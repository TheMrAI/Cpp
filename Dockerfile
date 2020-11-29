FROM ubuntu:latest AS builder
# For properly installing the packages
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/London

RUN apt-get update && apt-get install -y build-essential && apt-get install -y cmake && apt-get install -y git && apt-get install -y python3
COPY . ./project_tree/cpp

# get googletest
RUN cd project_tree/ && git clone https://github.com/google/googletest.git