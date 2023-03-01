// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0 Beta1
// LVGL VERSION: 8.2
// PROJECT: rp2040_devtool

#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_ScreenHome;
lv_obj_t * ui_ImageBG;
lv_obj_t * ui_ButtonMemory;
lv_obj_t * ui_ImageMemory;
lv_obj_t * ui_LabelMemory;
lv_obj_t * ui_ButtonLog;
lv_obj_t * ui_ImageLog;
lv_obj_t * ui_LabelLog;
lv_obj_t * ui_ButtonSetting;
lv_obj_t * ui_ImageSetting;
lv_obj_t * ui_LabelSetting;
lv_obj_t * ui_ScreenMemory;
lv_obj_t * ui_ImageBG2;
lv_obj_t * ui_Roller2;
lv_obj_t * ui_PanelToolDetail;
lv_obj_t * ui_Button6;
lv_obj_t * ui_Image7;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_ScreenHome_screen_init(void)
{
    ui_ScreenHome = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenHome, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImageBG = lv_img_create(ui_ScreenHome);
    lv_img_set_src(ui_ImageBG, &ui_img_background_png);
    lv_obj_set_width(ui_ImageBG, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImageBG, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ImageBG, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageBG, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBG, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonMemory = lv_btn_create(ui_ScreenHome);
    lv_obj_set_width(ui_ButtonMemory, 150);
    lv_obj_set_height(ui_ButtonMemory, 150);
    lv_obj_set_align(ui_ButtonMemory, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonMemory, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonMemory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonMemory, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonMemory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageMemory = lv_img_create(ui_ButtonMemory);
    lv_img_set_src(ui_ImageMemory, &ui_img_flash_png);
    lv_obj_set_width(ui_ImageMemory, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImageMemory, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ImageMemory, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_ImageMemory, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageMemory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelMemory = lv_label_create(ui_ButtonMemory);
    lv_obj_set_width(ui_LabelMemory, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelMemory, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelMemory, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_LabelMemory, "Memory");
    lv_obj_set_style_text_color(ui_LabelMemory, lv_color_hex(0xC82754), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelMemory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelMemory, &ui_font_FiraCodeSemiBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonLog = lv_btn_create(ui_ScreenHome);
    lv_obj_set_width(ui_ButtonLog, 150);
    lv_obj_set_height(ui_ButtonLog, 150);
    lv_obj_set_x(ui_ButtonLog, 220);
    lv_obj_set_y(ui_ButtonLog, 0);
    lv_obj_set_align(ui_ButtonLog, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonLog, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonLog, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonLog, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonLog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageLog = lv_img_create(ui_ButtonLog);
    lv_img_set_src(ui_ImageLog, &ui_img_log_png);
    lv_obj_set_width(ui_ImageLog, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImageLog, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ImageLog, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_ImageLog, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageLog, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelLog = lv_label_create(ui_ButtonLog);
    lv_obj_set_width(ui_LabelLog, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelLog, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelLog, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_LabelLog, "Setting");
    lv_obj_set_style_text_color(ui_LabelLog, lv_color_hex(0xC82754), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelLog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelLog, &ui_font_FiraCodeSemiBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonSetting = lv_btn_create(ui_ScreenHome);
    lv_obj_set_width(ui_ButtonSetting, 150);
    lv_obj_set_height(ui_ButtonSetting, 150);
    lv_obj_set_x(ui_ButtonSetting, -220);
    lv_obj_set_y(ui_ButtonSetting, 0);
    lv_obj_set_align(ui_ButtonSetting, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonSetting, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSetting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonSetting, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSetting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageSetting = lv_img_create(ui_ButtonSetting);
    lv_img_set_src(ui_ImageSetting, &ui_img_setting_png);
    lv_obj_set_width(ui_ImageSetting, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImageSetting, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ImageSetting, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_ImageSetting, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageSetting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelSetting = lv_label_create(ui_ButtonSetting);
    lv_obj_set_width(ui_LabelSetting, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSetting, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelSetting, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_LabelSetting, "Setting");
    lv_obj_set_style_text_color(ui_LabelSetting, lv_color_hex(0xC82754), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSetting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSetting, &ui_font_FiraCodeSemiBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_ScreenMemory_screen_init(void)
{
    ui_ScreenMemory = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenMemory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImageBG2 = lv_img_create(ui_ScreenMemory);
    lv_img_set_src(ui_ImageBG2, &ui_img_background_png);
    lv_obj_set_width(ui_ImageBG2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImageBG2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ImageBG2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageBG2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBG2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Roller2 = lv_roller_create(ui_ScreenMemory);
    lv_roller_set_options(ui_Roller2, "Info\nLoad\nSave\nVerify", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_Roller2, 150);
    lv_obj_set_height(ui_Roller2, 460);
    lv_obj_set_x(ui_Roller2, 19);
    lv_obj_set_y(ui_Roller2, 2);
    lv_obj_set_align(ui_Roller2, LV_ALIGN_LEFT_MID);
    lv_obj_set_style_text_font(ui_Roller2, &ui_font_FiraCodeSemiBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Roller2, lv_color_hex(0xC31C4A), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller2, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_PanelToolDetail = lv_obj_create(ui_ScreenMemory);
    lv_obj_set_width(ui_PanelToolDetail, 592);
    lv_obj_set_height(ui_PanelToolDetail, 460);
    lv_obj_set_x(ui_PanelToolDetail, -21);
    lv_obj_set_y(ui_PanelToolDetail, 0);
    lv_obj_set_align(ui_PanelToolDetail, LV_ALIGN_RIGHT_MID);
    lv_obj_clear_flag(ui_PanelToolDetail, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button6 = lv_btn_create(ui_ScreenMemory);
    lv_obj_set_width(ui_Button6, 50);
    lv_obj_set_height(ui_Button6, 50);
    lv_obj_set_x(ui_Button6, 20);
    lv_obj_set_y(ui_Button6, 20);
    lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button6, lv_color_hex(0xC31C4A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image7 = lv_img_create(ui_Button6);
    lv_img_set_src(ui_Image7, &ui_img_back_png);
    lv_obj_set_width(ui_Image7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Image7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image7, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_Image7, 128);

}

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScreenHome_screen_init();
    ui_ScreenMemory_screen_init();
    lv_disp_load_scr(ui_ScreenHome);
}
