FROM ubuntu:latest

ENV TZ="America/Los_Angeles"

RUN echo 'APT::Install-Suggests "0";' >> /etc/apt/apt.conf.d/00-docker
RUN echo 'APT::Install-Recommends "0";' >> /etc/apt/apt.conf.d/00-docker

RUN apt-get -y update && apt-get -y upgrade

RUN apt-get -y install build-essential g++ clang-15 clang-tidy-15 valgrind gdb

RUN groupadd -g 1000 andrew && useradd -l -u 1000 -g andrew andrew
USER andrew

