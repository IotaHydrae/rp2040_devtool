// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0 Beta1
// LVGL VERSION: 8.2
// PROJECT: rp2040_devtool

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_ScreenHome;
lv_obj_t * ui_ImageBG;
lv_obj_t * ui_ButtonSettings;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Button3;
lv_obj_t * ui_Image3;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Button4;
lv_obj_t * ui_Image4;
lv_obj_t * ui_Label3;

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

    ui_ButtonSettings = lv_btn_create(ui_ScreenHome);
    lv_obj_set_width(ui_ButtonSettings, 150);
    lv_obj_set_height(ui_ButtonSettings, 150);
    lv_obj_set_align(ui_ButtonSettings, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonSettings, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonSettings, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSettings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image2 = lv_img_create(ui_ButtonSettings);
    lv_img_set_src(ui_Image2, &ui_img_setting_png);
    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Image2, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label1 = lv_label_create(ui_ButtonSettings);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label1, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_Label1, "Setting");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xC82754), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label1, &ui_font_FiraCodeSemiBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button3 = lv_btn_create(ui_ScreenHome);
    lv_obj_set_width(ui_Button3, 150);
    lv_obj_set_height(ui_Button3, 150);
    lv_obj_set_x(ui_Button3, 220);
    lv_obj_set_y(ui_Button3, 0);
    lv_obj_set_align(ui_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image3 = lv_img_create(ui_Button3);
    lv_img_set_src(ui_Image3, &ui_img_setting_png);
    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Image3, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label2 = lv_label_create(ui_Button3);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label2, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_Label2, "Setting");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xC82754), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label2, &ui_font_FiraCodeSemiBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button4 = lv_btn_create(ui_ScreenHome);
    lv_obj_set_width(ui_Button4, 150);
    lv_obj_set_height(ui_Button4, 150);
    lv_obj_set_x(ui_Button4, -220);
    lv_obj_set_y(ui_Button4, 0);
    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image4 = lv_img_create(ui_Button4);
    lv_img_set_src(ui_Image4, &ui_img_setting_png);
    lv_obj_set_width(ui_Image4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Image4, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_Image4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label3 = lv_label_create(ui_Button4);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label3, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_Label3, "Setting");
    lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0xC82754), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label3, &ui_font_FiraCodeSemiBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScreenHome_screen_init();
    lv_disp_load_scr(ui_ScreenHome);
}
