#!/bin/bash

set -euo pipefail

bitbake mutex && bitbake mutex:do_clean
bitbake qsetandsemaphore && bitbake qsetandsemaphore:do_clean
bitbake queueisr && bitbake queueisr:do_clean
bitbake streambuffer && bitbake streambuffer:do_clean
bitbake taskcreate && bitbake taskcreate:do_clean
bitbake tasknotify && bitbake tasknotify:do_clean
bitbake timer && bitbake timer:do_clean

exit 0
