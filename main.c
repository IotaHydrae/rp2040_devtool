/**
 * @file main.c
 * @author IotaHydrae (writeforever@foxmail.com)
 * @brief
 * @version 0.1
 * @date 2023-02-27
 *
 * MIT License
 *
 * Copyright 2022 IotaHydrae(writeforever@foxmail.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libusb-1.0/libusb.h>

#include "picoboot_connection.h"

int endpoint_out;
int endpoint_in;
int interface_n;

// struct picoboot_cmd {
//     int dMagic;         /* 0x00 */
//     int dToken;         /* 0x04 */
//     int bCmdId;         /* 0x08 */
//     uint8_t bCmdSize;   /* 0x09 */
//     uint8_t reserved;   /* 0x0a */
//     uint16_t dTransferLength;    /* 0x0c */
//     int args[4];   /* 0x10 */
// };

int main()
{
    int i, rc;
    int num_devices;
    libusb_device *dev, **devs;
    libusb_device_handle *dev_handle;

    rc = libusb_init(NULL);
    if (rc < 0) {
        printf("failed to initialize libusb");
        exit(1);
    }

    /* get device list */
    if ((num_devices = libusb_get_device_list(NULL, &devs)) < 0) {
        printf("libusb get device list failed ! %s \n", libusb_error_name(num_devices));
        libusb_exit(NULL);
        exit(1);
    }

    /* is this device rp2040 ? */
    for (i = 0; i < num_devices; i++) {
        dev = devs[i];

        rc = picoboot_open_device(dev, &dev_handle);
        if (rc == dr_vidpid_bootrom_ok)
            break;
    }

    if (i == num_devices) {
        printf("device not founded! exiting ...\n");
        goto err_exit;
    }

    /* making a test reboot */
    picoboot_cmd_warpper(dev_handle, picoboot_reboot(dev_handle, 0, 0, 200));

err_exit:
    libusb_close(dev_handle);
    libusb_exit(NULL);

    return 0;
}
