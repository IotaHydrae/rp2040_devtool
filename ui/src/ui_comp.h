// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0 Beta1
// LVGL VERSION: 8.2
// PROJECT: rp2040_devtool

#ifndef _RP2040_DEVTOOL_UI_COMP_H
#define _RP2040_DEVTOOL_UI_COMP_H

#include "ui.h"

lv_obj_t * ui_comp_get_child(lv_obj_t * comp, uint32_t child_idx);
extern uint32_t LV_EVENT_GET_COMP_CHILD;

// COMPONENT ButtonBack
#define UI_COMP_BUTTONBACK_BUTTONBACK 0
#define UI_COMP_BUTTONBACK_IMAGEBACK 1
#define _UI_COMP_BUTTONBACK_NUM 2
lv_obj_t * ui_ButtonBack_create(lv_obj_t * comp_parent);

// COMPONENT ImageBG
#define UI_COMP_IMAGEBG_IMAGEBG 0
#define _UI_COMP_IMAGEBG_NUM 1
lv_obj_t * ui_ImageBG_create(lv_obj_t * comp_parent);

#endif
