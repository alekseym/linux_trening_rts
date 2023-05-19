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
	&& apt-get -y install g++ \
	&& apt-get -y install make \
	&& apt-get -y install cmake \
	&& apt-get -y install git \
	&& apt-get -y install libglew-dev libglfw3-dev libghc-glut-dev \
	&& apt-get -y install libssl-dev \
        && apt-get autoremove --yes && apt-get clean --yes

#USER docker  
CMD ["/bin/bash"]

