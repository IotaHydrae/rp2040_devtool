#!/bin/bash

# source the enviroments
WORKDIR=$(pwd)
echo "working dir is ${WORKDIR}"

BUILDDIR=${WORKDIR}/dir_build

BIN="rp2040_devtool"

function do_banner() {
cat << "EOF" >> /dev/tty

EOF

}

function do_usage() {
cat << "EOF" >> /dev/tty

./build.sh [-h|-c|-p]

    If no parameter is provided, will do a normal build process

    -h      print this usage

    -c      do a make clean job

    -p      do a chip flash program job

EOF
}

function do_configure() {
    # cd .. && source tools/envsetup.sh && cd ${WORKDIR}

    echo "do configuring ..."
    # if [ ! -f .config ]; then
    #     echo "making a default config"
    #     ARCH=${ARCH} make xeniaclock_defconfig
    # else
    #     echo "user config exists"
    # fi
}

function do_git_submodule() {
    git submodule update --init
    if [ $? -ne 0 ]; then
        echo "git submodule update failed! exiting..."
        exit -1
    fi
}

function do_post_build() {
    if [ ! -d "${WORKDIR}/tools/picotool" ]; then
        echo "can't find picotool, doing `git submodule update --init` "
        do_git_submodule
    else
        echo "building picotool ..."
    fi

    if [ ! -d "${WORKDIR}/tools/pico-sdk" ]; then
        echo "can't find pico-sdk, doing `git submodule update --init` "
        do_git_submodule
    else
        echo "pico-sdk founded!"
    fi


    if [ -x "${WORKDIR}/tools/picotool/build/picotool" ]; then
        echo "picotool has been built, do nothing ..."
        return 1
    fi

    # real build process
    cd ${WORKDIR}/tools/picotool

    mkdir -p build && cd build
    export PICO_SDK_PATH=${WORKDIR}/tools/pico-sdk

    cmake ..
    make -j4
    ls -lh ./picotool

    cd ${WORKDIR}
}

function do_compile() {
    echo "do compiling ..."
    # if [ ! -d "${WORKDIR}/build" ]; then
    #     mkdir build
    # fi
    mkdir -p ${BUILDDIR} && cd ${BUILDDIR}
    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Release -GNinja ..
    time ninja

    # symol link compile_commands.json on WORKDIR

    ln -sf ${BUILDDIR}/compile_commands.json ${WORKDIR}

    cd -
}

function do_install() {
    echo "do installing ..."
    ln -sf ${BUILDDIR}/${BIN} ${WORKDIR}
    echo -e "                     =--- size info ---=\n"
    size -d ${BIN}
}

function do_clean() {
    echo "do cleaning ..."
    mkdir -p ${BUILDDIR} && cd ${BUILDDIR}
    ninja clean
    cd -
}

function do_run() {
    echo "running target ..."
    ./${BIN}
}

case $1 in

    "-h")
        echo "Printing Usage ..."
        do_banner
        do_usage
        exit 0
        ;;

    "-c")
        echo "do a clean job"
        do_banner
        do_clean
        exit 0
        ;;

    "-r")
        echo "do a build process, then run"
        do_banner
        do_configure
        do_post_build
        do_compile
        do_install
        do_run
        exit 0
        ;;

esac

do_banner
do_configure
do_post_build
do_compile
do_install

exit 0
