#include <iostream>
#include <fstream>

#include "ddi.hpp"
#include "ritms_dps.hpp"

// header with up2date com functionality
#include "up2date.h"



using namespace ritms::dps;
using namespace ddi;



class CancelActionFeedbackDeliveryListener : public ResponseDeliveryListener {
public:
    void onSuccessfulDelivery() override {
        std::cout << ">> Successful delivered cancelAction response" << std::endl;
    }

    void onError() override {
        std::cout << ">> Error delivery cancelAction response" << std::endl;
    }
};

class DeploymentBaseFeedbackDeliveryListener : public ResponseDeliveryListener {
public:
    void onSuccessfulDelivery() override {
        std::cout << ">> Successful delivered deliveryAction response" << std::endl;
    }

    void onError() override {
        std::cout << ">> Error delivery deliveryAction response" << std::endl;
    }
};

class Handler : public EventHandler {
public:
    std::unique_ptr<ConfigResponse> onConfigRequest() override {
        std::cout << ">> Sending Config Data" << std::endl;

        return ConfigResponseBuilder::newInstance()
        
// TODO: add information about your PC
                ->addData("TODO", "TODO")
                ->addData("TODO", "TODO")
                // Do not wait polling time before the request
                ->setIgnoreSleep()
                ->build();
    }

    std::unique_ptr<Response> onDeploymentAction(std::unique_ptr<DeploymentBase> dp) override {
        std::cout << ">> Get Deployment base request" << std::endl;
        std::cout << " id: " << dp->getId() << " update: " << dp->getUpdateType() << std::endl;
        std::cout << " download: " << dp->getDownloadType() << " inWindow: " << (bool) dp->isInMaintenanceWindow()
                  << std::endl;

        auto builder = ResponseBuilder::newInstance();
        builder->addDetail("Printed deployment base info");
        std::cout << " + CHUNKS:" << std::endl;

        for (const auto &chunk: dp->getChunks()) {
            std::cout << "  part: " << chunk->getPart() << std::endl;
            std::cout << "  name: " << chunk->getName() << " version: " << chunk->getVersion() << std::endl;
            std::cout << "  + ARTIFACTS:" << std::endl;
            for (const auto &artifact: chunk->getArtifacts()) {
                std::cout << "   filename: " << artifact->getFilename() << " size: " << artifact->size() << std::endl;
                std::cout << "   md5: " << artifact->getFileHashes().md5 << std::endl;
                std::cout << "   sha1: " << artifact->getFileHashes().sha1 << std::endl;
                std::cout << "   sha256: " << artifact->getFileHashes().sha256 << std::endl;
                builder->addDetail(artifact->getFilename() + " described. Starting download ...");
                std::cout << "  .. downloading " + artifact->getFilename() + "...";
                
                artifact->downloadTo(artifact->getFilename());
                
// TODO: implement install logic here
                
                builder->addDetail("Downloaded " + artifact->getFilename());
                std::cout << "[OK]" << std::endl;
            }
            std::cout << " + ---------------------------" << std::endl;
        }

        return builder->addDetail("Work done. Sending response")
                ->setExecution(Response::CLOSED)
                // IF OK
                ->setFinished(Response::SUCCESS)
                // IF BAD
                // -> setFinished(Response::FAILURE)
                ->setResponseDeliveryListener(
                        std::shared_ptr<ResponseDeliveryListener>(new DeploymentBaseFeedbackDeliveryListener()))
                ->build();

    }

    std::unique_ptr<Response> onCancelAction(std::unique_ptr<CancelAction> action) override {
        std::cout << ">> CancelAction: id " << action->getId() << ", stopId " << action->getStopId() << std::endl;

        return ResponseBuilder::newInstance()
                ->setExecution(ddi::Response::CLOSED)
                ->setFinished(ddi::Response::SUCCESS)
                ->addDetail("")
                ->setResponseDeliveryListener(
                        std::shared_ptr<ResponseDeliveryListener>(new CancelActionFeedbackDeliveryListener()))
                ->build();
    }

    void onNoActions() override {
        std::cout << "No actions from hawkBit" << std::endl;
    }

    ~Handler() override = default;

    Handler() = default;
};


int main() {
    std::cout << "up2date update client started..." << std::endl;

    auto clientCertificatePath = getEnvOrExit("CERT_PATH");

    std::ifstream t((std::string(clientCertificatePath)));
    if (!t.is_open()) {
        std::cout << "File " << clientCertificatePath << " not exists" << std::endl;
        throw std::runtime_error(std::string("fail: cannot open file :").append(clientCertificatePath));
    }
    std::string certificate((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    auto dpsBuilder = CloudProvisioningClientBuilder::newInstance();
    auto dpsClient = dpsBuilder->setEndpoint(provisioningEndpoint)
            ->setAuthCrt(certificate)
            ->addHeader("X-Apig-AppCode", std::string(xApigToken))
            ->build();

    auto authErrorHandler = std::shared_ptr<AuthErrorHandler>(new DPSInfoReloadHandler(std::move(dpsClient)));


    auto builder = DDIClientBuilder::newInstance();
    builder->setAuthErrorHandler(authErrorHandler)
        ->setEventHandler(std::shared_ptr<EventHandler>(new Handler()))
        ->build()
        ->run();
}



