<!--
 Copyright (c) 2023 IotaHydrae(writeforever@foxmail.com)
 
 This software is released under the MIT License.
 https://opensource.org/licenses/MIT
-->

rp2040_devtool
===================

Introduction
-------------------

rp2040_devtool was designed for embedded developers who using rp2040.

This project was inspired by [picotool](https://github.com/raspberrypi/picotool)

Requirements
-------------------

Use your favorite package tool to install dependencies. For example, on Ubuntu:
```shell
sudo apt install build-essential pkg-config libusb-1.0-0-dev cmake
```

On Linux you can add udev rules in order to run picotool without sudo:

```shell
sudo cp udev/99-picotool.rules /etc/udev/rules.d/
```

Building
--------------------

```shell
mkdir build && cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
make -j12
```

Development
--------------------

After a building work, type this in the root dir. make sure clangd was correctly configured in your computer.
```
code .
```

License
--------------------
`MIT`