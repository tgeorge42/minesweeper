FROM debian:bullseye

# Install necessary dependencies
RUN apt-get update \
    && apt-get install -y xorg libxext-dev zlib1g-dev libbsd-dev make gcc valgrind

# Create directory structure and copy files
WORKDIR /root/demineur

RUN mkdir -p srcs images includes mlx_linux

COPY images images/
COPY includes includes/
COPY mlx_linux mlx_linux/
COPY srcs srcs/
COPY Makefile ./

ENV DISPLAY=host.docker.internal:0

# Build the project
RUN make
