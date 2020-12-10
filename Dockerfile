FROM ubuntu:latest AS builder
# For properly installing the packages
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/London
# Install all dependencies
RUN apt-get update && apt-get install -y build-essential && apt-get install -y cmake && apt-get install -y git && apt-get install -y python3
# Get googletest
RUN mkdir project_tree && cd project_tree/ && git clone https://github.com/google/googletest.git