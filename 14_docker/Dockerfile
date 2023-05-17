FROM debian:buster

ENV LC_ALL C.UTF-8
ENV LANG C.UTF-8
ENV LANGUAGE C.UTF-8

# add user 'docker'
RUN useradd -r -u 1000 -U -m docker-DEV


RUN mkdir /workspace && chown -R docker-DEV /workspace
WORKDIR /workspace

ENV LC_ALL C.UTF-8
ENV LANG C.UTF-8
ENV LANGUAGE C.UTF-8

RUN apt-get update && apt-get -y install mc \
       && apt-get autoremove --yes && apt-get clean --yes

#USER docker  
CMD ["/bin/bash"]

