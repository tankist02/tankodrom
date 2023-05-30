FROM ubuntu:latest

ARG USER_NAME=andrew
ARG USER_UID=1000
ARG USER_GID=$USER_UID

ENV TZ="America/Los_Angeles"

RUN echo 'APT::Install-Suggests "0";' >> /etc/apt/apt.conf.d/00-docker
RUN echo 'APT::Install-Recommends "0";' >> /etc/apt/apt.conf.d/00-docker

RUN apt-get -y update && apt-get -y upgrade

RUN apt-get -y install build-essential g++ clang-15 clang-tidy-15 valgrind gdb sudo git

RUN groupadd --gid $USER_GID $USER_NAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USER_NAME

RUN echo $USER_NAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USER_NAME \
    && chmod 0440 /etc/sudoers.d/$USER_NAME

USER $USER_NAME

