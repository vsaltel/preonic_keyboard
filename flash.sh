#!/bin/bash

## COLORS       ##
if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
    NC=$(tput sgr0) # No Color
    BOLD=$(tput bold)
    RED=$(tput setaf 1)
    GREEN=$(tput setaf 2)
    YELLOW=$(tput setaf 3)
    PURPLE=$(tput setaf 5)
else
    NC='\033[0m' # No Color
    BOLD=''
    RED='\033[0;31m'
    GREEN='\033[0;32m'
    YELLOW='\033[1;33m'
    PURPLE='\033[1;35m'
fi

## FUNCTIONS    ##
command_exists() {
    command -v "$@" >/dev/null 2>&1
}

## VARS         ##
DIRPATH=$(dirname ${0})
LOGFILE="${DIRPATH}/logs.txt"
PACKAGES="build-essential curl python3 python3-pip gcc-arm-none-eabi"

## START        ##
# Check sudo
if [ "${EUID}" -ne 0 ] ; then
    echo -e "${BOLD}${RED}Please run as root${NC}"
    exit
fi

if [ ! -e "qmk_firmware" ] ; then
    # Update
    echo -e "${BOLD}${YELLOW}APT UPDATE${NC}" | tee -a ${LOGFILE}
    apt-get -y update >> ${LOGFILE}
    if [ ${?} -ne 0 ]; then
        echo -e "${BOLD}${RED}UPDATE FAILED${NC}" | tee -a ${LOGFILE}
        exit
    fi
    
    # Install Packages
    echo -e "${BOLD}${YELLOW}APT INSTALL PACKAGES:${NC}" | tee -a ${LOGFILE}
    for PACK in ${PACKAGES}; do
        echo -e "${BOLD}${PURPLE}INSTALL ${PACK}${NC}" | tee -a ${LOGFILE}
        apt-get -y install $PACK >> ${LOGFILE}
        if [ ${?} -ne 0 ]; then
            echo -e "${BOLD}${RED}${PACK} INSTALLATION FAILED${NC}" | tee -a ${LOGFILE}
            exit
        fi
    done
    
    # QMK CLI clone
    echo -e "${BOLD}${YELLOW}QMK CLI INSTALL${NC}" | tee -a ${LOGFILE}
    python3 -m pip install qmk >> ${LOGFILE}
    if [ ${?} -ne 0 ] ; then
        echo -e "${BOLD}${RED}QMK CLI INSTALL FAILED${NC}" | tee -a ${LOGFILE}
        exit
    fi

    # QMK firmware clone
    echo -e "${BOLD}${YELLOW}QMK FIRMWARE INSTALL${NC}" | tee -a ${LOGFILE}
    qmk setup -H "${DIRPATH}/qmk_firmware" | tee -a ${LOGFILE}
    if [ ! -e "${DIRPATH}/qmk_firmware" ] ; then
        echo -e "${BOLD}${RED}QMK FIRMWARE INSTALL FAILED${NC}" | tee -a ${LOGFILE}
        exit
    fi

    # Install requirements
    cd ${DIRPATH}/qmk_firmware
    echo -e "${BOLD}${YELLOW}QMK FIRMWARE REQUIREMENTS INSTALL${NC}" | tee -a ${LOGFILE}
    pip3 install -r requirements.txt >> ${LOGFILE}
    if [ ${?} -ne 0 ] ; then
        echo -e "${BOLD}${RED}QMK FIRMWARE REQUIREMENTS INSTALL FAILED${NC}" | tee -a ${LOGFILE}
        exit
    fi
    cd ..
fi

# Copy keyboard config files
echo -e "${BOLD}${YELLOW}COPY KEYBOARD CONFIG FILES${NC}" | tee -a ${LOGFILE}
mkdir -p ${DIRPATH}/qmk_firmware/keyboards/preonic/rev3/keymaps/vsaltel
cp ${DIRPATH}/keymap.c ${DIRPATH}/qmk_firmware/keyboards/preonic/rev3/keymaps/vsaltel
cp ${DIRPATH}/config.h ${DIRPATH}/qmk_firmware/keyboards/preonic/rev3/keymaps/vsaltel
cp ${DIRPATH}/rules.mk ${DIRPATH}/qmk_firmware/keyboards/preonic/rev3/keymaps/vsaltel

# Flash Firmware
echo -e "${BOLD}${YELLOW}FLASH FIRMWARE${NC}" | tee -a ${LOGFILE}
cd ${DIRPATH}/qmk_firmware
make preonic/rev3:vsaltel:flash
if [ ${?} -ne 0 ] ; then
    echo -e "${BOLD}${RED}FLASH FAILED${NC}" | tee -a ${LOGFILE}
else
    echo -e "${BOLD}${GREEN}FLASH SUCCESSFUL${NC}" | tee -a ${LOGFILE}
fi
