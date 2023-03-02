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

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <libusb-1.0/libusb.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/sdl/sdl.h"
#include "ui/src/ui.h"

#include "event.h"
#include "anim.h"

#include "picoboot_connection.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);
static int tick_thread(void *data);

/**********************
 *  STATIC VARIABLES
 **********************/

int endpoint_out;
int endpoint_in;
int interface_n;
libusb_device_handle *dev_handle;

// struct picoboot_cmd {
//     int dMagic;         /* 0x00 */
//     int dToken;         /* 0x04 */
//     int bCmdId;         /* 0x08 */
//     uint8_t bCmdSize;   /* 0x09 */
//     uint8_t reserved;   /* 0x0a */
//     uint16_t dTransferLength;    /* 0x0c */
//     int args[4];   /* 0x10 */
// };
int picoboot_scan()
{
    int i, rc;
    int num_devices;
    libusb_device *dev, **devs;

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
        printf("device not founded!\n");
        // goto err_exit;
    }

    // err_exit:
    //     libusb_close(dev_handle);
    //     libusb_exit(NULL);

    return 0;
}

int picoboot_init()
{
    picoboot_scan();
    return 0;
}

int picoboot_loop()
{
    return 0;
}

static void rpt_btn_reboot_cb(lv_event_t *event)
{
    picoboot_cmd_warpper(dev_handle, picoboot_reboot(dev_handle, 0, 0, 200));
    // lv_scr_load(ui_ScreenHome);
}

int main(int argc, char **argv)
{
    /* making a test reboot */
    // picoboot_cmd_warpper(dev_handle, picoboot_reboot(dev_handle, 0, 0, 200))
    (void)argc; /*Unused*/
    (void)argv; /*Unused*/

    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init();

    picoboot_init();

    // lv_demo_stress();
    ui_init();
    anim_setup();
    event_setup();

    lv_obj_add_event_cb(ui_ButtonReboot, rpt_btn_reboot_cb, LV_EVENT_PRESSED, NULL);

    // lv_obj_add_event_cb(ui_ButtonMemory, rpt_btn_cb, LV_EVENT_PRESSED, NULL);
    while (1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_timer_handler();
        usleep(5 * 1000);
    }

    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static void hal_init(void)
{
    /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
    sdl_init();

    /*Create a display buffer*/
    static lv_disp_draw_buf_t disp_buf1;
    static lv_color_t buf1_1[SDL_HOR_RES * SDL_VER_RES];
    static lv_color_t buf1_2[SDL_HOR_RES * SDL_VER_RES];
    lv_disp_draw_buf_init(&disp_buf1, buf1_1, buf1_2, SDL_HOR_RES * SDL_VER_RES);

    /*Create a display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv); /*Basic initialization*/
    disp_drv.draw_buf = &disp_buf1;
    disp_drv.flush_cb = sdl_display_flush;
    disp_drv.hor_res = SDL_HOR_RES;
    disp_drv.ver_res = SDL_VER_RES;
    disp_drv.full_refresh = 1;

    lv_disp_t *disp = lv_disp_drv_register(&disp_drv);

    // lv_theme_t * th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
    // lv_disp_set_theme(disp, th);
    // lv_theme_t *th = lv_theme_mono_init(disp, 0, &lv_font_montserrat_14);
    // lv_disp_set_theme(disp, th);

    lv_group_t *g = lv_group_create();
    lv_group_set_default(g);

    /* Add the mouse as input device
     * Use the 'mouse' driver which reads the PC's mouse*/
    static lv_indev_drv_t indev_drv_1;
    lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
    indev_drv_1.type = LV_INDEV_TYPE_POINTER;

    /*This function will be called periodically (by the library) to get the mouse position and state*/
    indev_drv_1.read_cb = sdl_mouse_read;
    lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

    static lv_indev_drv_t indev_drv_2;
    lv_indev_drv_init(&indev_drv_2); /*Basic initialization*/
    indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
    indev_drv_2.read_cb = sdl_keyboard_read;
    lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
    lv_indev_set_group(kb_indev, g);

    static lv_indev_drv_t indev_drv_3;
    lv_indev_drv_init(&indev_drv_3); /*Basic initialization*/
    indev_drv_3.type = LV_INDEV_TYPE_ENCODER;
    indev_drv_3.read_cb = sdl_mousewheel_read;
    lv_indev_t *enc_indev = lv_indev_drv_register(&indev_drv_3);
    lv_indev_set_group(enc_indev, g);

    /*Set a cursor for the mouse*/
    // LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
    // lv_obj_t *cursor_obj = lv_img_create(
    //                                    lv_scr_act());  /*Create an image object for the cursor */
    // lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
    // lv_indev_set_cursor(mouse_indev,
    //                     cursor_obj);             /*Connect the image  object to the driver*/
}

/**
 * A task to measure the elapsed time for LVGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void *data)
{
    (void)data;

    while (1) {
        SDL_Delay(5);
        lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
    }

    return 0;
}
