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
extern lv_obj_t * ui_ButtonMemory;
extern lv_obj_t * ui_ImageMemory;
extern lv_obj_t * ui_LabelMemory;
extern lv_obj_t * ui_ButtonLog;
extern lv_obj_t * ui_ImageLog;
extern lv_obj_t * ui_LabelLog;
extern lv_obj_t * ui_ButtonSetting;
extern lv_obj_t * ui_ImageSetting;
extern lv_obj_t * ui_LabelSetting;
extern lv_obj_t * ui_ScreenMemory;
extern lv_obj_t * ui_ImageBG2;
extern lv_obj_t * ui_RollerTools;
extern lv_obj_t * ui_PanelToolDetail;
extern lv_obj_t * ui_ButtonBack;
extern lv_obj_t * ui_ButtonReboot;
extern lv_obj_t * ui_LabelReboot;


LV_IMG_DECLARE(ui_img_background_png);    // assets/background.png
LV_IMG_DECLARE(ui_img_flash_png);    // assets/flash.png
LV_IMG_DECLARE(ui_img_log_png);    // assets/log.png
LV_IMG_DECLARE(ui_img_setting_png);    // assets/setting.png
LV_IMG_DECLARE(ui_img_back_png);    // assets/back.png


LV_FONT_DECLARE(ui_font_FiraCodeSemiBold20);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
