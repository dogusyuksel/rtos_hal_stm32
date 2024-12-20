FROM ubuntu:22.04
ARG DEBIAN_FRONTEND=noninteractive

USER root

RUN apt-get update && \
    apt-get -y upgrade && \
    apt-get -y --no-install-recommends install \
        build-essential \
        git \
        git-core \
        git-lfs \
        python3-dbg \
        python3-dev \
        python3-pip \
        python3-pexpect \
        python3-git \
        python3-jinja2 \
        python3-subunit \
        vim \
        cmake \
        gcc-multilib \
        g++-multilib \
        software-properties-common \
        language-pack-en-base \
        wget \
        diffstat \
        chrpath \
        cpio \
        gawk \
        file \
        zstd \
        liblz4-tool \
        openocd \
        stlink-tools \
        gdb-multiarch \
        valgrind \
        gdb \
        ruby \
        clang-format \
        unzip && \
    apt-get -y clean

RUN git config --global --add safe.directory /workspace

RUN cd / && \
    git clone git://git.openembedded.org/bitbake
ENV PATH="${PATH}:/bitbake/bin"
ENV PYTHONPATH="${PYTHONPATH}:/bitbake/lib"
RUN pip install -r bitbake/toaster-requirements.txt

RUN wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2 && \
    tar -xf gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2
ENV PATH="/gcc-arm-none-eabi-10.3-2021.10/bin:${PATH}"

RUN cd / && mkdir thirdparty && \
    git clone https://github.com/modm-io/cmsis-header-stm32.git /thirdparty/cmsis-header-stm32 && \
    git clone https://github.com/ARM-software/CMSIS_5.git /thirdparty/CMSIS_5 && \
    git clone https://github.com/FreeRTOS/FreeRTOS-Kernel.git /thirdparty/FreeRTOS-Kernel && \
    git clone https://github.com/STMicroelectronics/stm32f1xx_hal_driver.git /thirdparty/STM32F103X_HAL && \
    git clone https://github.com/dogusyuksel/embedded_linting.git /thirdparty/linting && \
    git clone https://github.com/mpaland/printf.git /thirdparty/custom_printf && \
    git clone https://github.com/STMicroelectronics/OpenOCD.git /thirdparty/openocd && \
    git clone https://github.com/STMicroelectronics/stm32l4xx_hal_driver.git /thirdparty/STM32L4XX_HAL

CMD ["/bin/bash"]

WORKDIR /workspace/
