/**
 * @file anim.c
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

static void load_scr_memory(lv_anim_t *a)
{
    lv_obj_t *scr = lv_anim_get_user_data(a);
    if (scr)
        lv_scr_load(scr);
}

void anim_y_cb(void *var, int32_t v)
{
    // if (v >= 0 && v <= 800)
        lv_obj_set_y(var, v);
}

void anim_x_cb(void *var, int32_t v)
{
    // printf(",\n");
    // if (v >= 0 && v <= 800)
    lv_obj_set_x(var, v);
}

static void obj_bump_cb(lv_event_t *event)
{
    lv_obj_t *obj = lv_event_get_user_data(event);

    int y = lv_obj_get_y(obj) - lv_obj_get_height(obj);
    /* anims here */
    lv_anim_t a, b;
    lv_anim_init(&a);
    lv_anim_init(&b);

    lv_anim_set_var(&a, obj);
    lv_anim_set_values(&a, y, y+30);
    lv_anim_set_time(&a, 250);
    lv_anim_set_exec_cb(&a, anim_y_cb);
    lv_anim_set_path_cb(&a, lv_anim_path_overshoot);
    // lv_anim_set_ready_cb(&a, load_scr_memory);
    lv_anim_start(&a);

    lv_anim_set_user_data(&b, obj->user_data);

    lv_anim_set_var(&b, obj);
    lv_anim_set_values(&b, y, 0);
    lv_anim_set_time(&b, 250);
    lv_anim_set_exec_cb(&b, anim_y_cb);
    lv_anim_set_path_cb(&b, lv_anim_path_overshoot);
    lv_anim_set_ready_cb(&b, load_scr_memory);
    lv_anim_start(&b);
}

int anim_set_obj_bump(lv_obj_t *obj)
{
    lv_obj_add_event_cb(obj, obj_bump_cb, LV_EVENT_PRESSED, obj);
    return 0;
}


lv_obj_t *null_ptr = NULL;
lv_obj_t **btn_back_slide_objs[] = {
    &ui_RollerTools,
    &ui_PanelToolDetail,

    /* end flag of this array */
    &null_ptr,
};

void anim_setup(void)
{
    lv_obj_set_user_data(ui_ButtonMemory, ui_ScreenMemory);
    anim_set_obj_bump(ui_ButtonMemory);
    anim_set_obj_bump(ui_ButtonSetting);
    anim_set_obj_bump(ui_ButtonLog);

    // printf("%p\n", back_slide_objs);
    lv_obj_set_user_data(ui_ButtonBack, ui_ScreenHome);
    anim_set_obj_slide_out_trigger(ui_ButtonBack, btn_back_slide_objs);
}
