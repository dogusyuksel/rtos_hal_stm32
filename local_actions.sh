#!/bin/bash

# important!! first call must have '-b' option
./docker_ctl.sh -b -c 'cd /workspace/build && ./build_all.sh'
