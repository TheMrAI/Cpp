FROM ubuntu:latest

LABEL description="Build and test."

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/London

RUN apt-get update
RUN apt-get install -y build-essential 
RUN apt-get install -y cmake
RUN apt-get install -y git