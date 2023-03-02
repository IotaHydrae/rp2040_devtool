/**
 * @file anim_slideout.c
 * @author IotaHydrae (writeforever@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-02
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

#include "lvgl/lvgl.h"
#include "ui/src/ui.h"
#include "ui/src/ui_comp.h"

#include "anim.h"
lv_obj_t ***tmp_restore;

static void obj_slide_out_ready_cb(lv_anim_t *a)
{
    lv_obj_t *scr = lv_anim_get_user_data(a);
    if (scr)
        lv_scr_load(scr);
}

static void obj_slide_out_cb(lv_event_t *event)
{
    int i,len = 0;
    int *origin_x;

    lv_obj_t ***objs = lv_event_get_user_data(event);
    lv_obj_t ***tmp = objs;
    lv_obj_t ***tmp_len = objs;
    tmp_restore = objs;

    while(**tmp_len) {
        tmp_len++;
        len++;
    }

    printf("length : %d\n", len);
    origin_x = (int *)malloc(len);

    i = 0;
    while (**tmp) {
        printf("%p\n", **tmp);
        // lv_obj_set_size(**objs, 50, 50);
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, **tmp);

        /* Determine should be left or right to the right */
        int obj_center_x = lv_obj_get_x(**tmp) + lv_obj_get_width(**tmp) / 2;
        int offset;

        printf("x : %d, y  : %d\n", lv_obj_get_x(**tmp), lv_obj_get_y(**tmp));
        printf("w : %d, h  : %d\n", lv_obj_get_width(**tmp), lv_obj_get_height(**tmp));
        printf("cx : %d\n", obj_center_x);

        if (obj_center_x < 400) {
            offset = -lv_obj_get_width(**tmp) - lv_obj_get_x(**tmp);
            // offset = -400;
            lv_anim_set_values(&a, lv_obj_get_x(**tmp), offset);
        } else {
            offset = 800 + lv_obj_get_width(**tmp);
            // offset = 400;
            /* move to the right side */
            lv_anim_set_values(&a, lv_obj_get_x(**tmp), offset);
        }
        lv_anim_set_time(&a, 250);
        origin_x[i] = lv_obj_get_x(**tmp);
        printf("origin x : %d\n", origin_x[i]);
        lv_obj_set_user_data(**tmp, origin_x);

        lv_anim_set_exec_cb(&a, anim_x_cb);
        lv_anim_set_path_cb(&a, lv_anim_path_overshoot);

        /* if this is the last obj, give a ready callback */
        if (!(**(tmp+1))) {
            lv_obj_t *trigger = lv_event_get_target(event);
            lv_anim_set_user_data(&a, trigger->user_data);
        }

        lv_anim_set_ready_cb(&a, obj_slide_out_ready_cb);

        lv_anim_start(&a);
        /* move to the next object */
        tmp++;
        i++;
    }

    // i = 0;
    // while (**tmp_restore) {
    //     int *p_offset = lv_obj_get_user_data(**tmp_restore);
    //     printf("x : %d\n", lv_obj_get_x(**tmp_restore));
    //     lv_obj_set_x(**tmp_restore, lv_obj_get_x(**tmp_restore));
        
    //     tmp_restore++;
    //     i++;
    // }

}

/**
 * @brief 
 * 
 * This function is used to set an exit animation for a certain OBJ. Before calling, please set the screen that jumps after exiting the Trigger after calling
 * 
 * @param trigger Obj as a trigger
 * @param objs objs gonna be slide out
 * @return int 0 if success
 */
int anim_set_obj_slide_out_trigger(lv_obj_t *trigger, lv_obj_t **objs[])
{
    // printf("%p\n", *objs);
    // printf("%p\n", *objs[0]);
    // printf("%p\n", *objs[1]);
    // lv_obj_t **tmp = objs;
    // printf("%p\n", **objs);
    // printf("%p\n", *tmp);
    // printf("%p\n", *(tmp + 1));
    lv_obj_add_event_cb(trigger, obj_slide_out_cb, LV_EVENT_PRESSED, objs);
    return 0;
}

int anim_set_obj_slide_in_trigger(lv_obj_t *trigger, lv_obj_t **objs[])
{
    // printf("%p\n", *objs);
    // printf("%p\n", *objs[0]);
    // printf("%p\n", *objs[1]);
    // lv_obj_t **tmp = objs;
    // printf("%p\n", **objs);
    // printf("%p\n", *tmp);
    // printf("%p\n", *(tmp + 1));
    lv_obj_add_event_cb(trigger, obj_slide_out_cb, LV_EVENT_PRESSED, objs);
    return 0;
}