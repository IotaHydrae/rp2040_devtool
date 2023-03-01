// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0 Beta1
// LVGL VERSION: 8.2
// PROJECT: rp2040_devtool

#ifndef _RP2040_DEVTOOL_UI_H
#define _RP2040_DEVTOOL_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

extern lv_obj_t * ui_ScreenHome;
extern lv_obj_t * ui_ImageBG;
extern lv_obj_t * ui_ButtonSettings;
extern lv_obj_t * ui_Image2;
extern lv_obj_t * ui_Label1;
extern lv_obj_t * ui_Button3;
extern lv_obj_t * ui_Image3;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Button4;
extern lv_obj_t * ui_Image4;
extern lv_obj_t * ui_Label3;


LV_IMG_DECLARE(ui_img_background_png);    // assets/background.png
LV_IMG_DECLARE(ui_img_setting_png);    // assets/setting.png


LV_FONT_DECLARE(ui_font_FiraCodeSemiBold20);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
