#!/bin/bash

#this cannot be used inside docker
openocd -f ./thirdparty/STM32L452RET/st_nucleo_l4.cfg

# then in another terminal (or even in docker), run below
# gdb-multiarch $1/build/$1.elf
# then type
# target extended-remote localhost:3333
# 3333 can be found netstat -tunlpa | grep openocd
# additional note: LD_LIBRARY_PATH=/usr/local/lib st-info --probe
# st-flash write <file_to_flash>.bin 0x08000000

exit 0
