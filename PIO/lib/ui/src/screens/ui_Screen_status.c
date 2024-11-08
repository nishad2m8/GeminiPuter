// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: gemini-sls

#include "../ui.h"

void ui_Screen_status_screen_init(void)
{
ui_Screen_status = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen_status, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen_status, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen_status, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_img_status_bg = lv_img_create(ui_Screen_status);
lv_img_set_src(ui_img_status_bg, &ui_img_images_status_bg_png);
lv_obj_set_width( ui_img_status_bg, LV_SIZE_CONTENT);  /// 240
lv_obj_set_height( ui_img_status_bg, LV_SIZE_CONTENT);   /// 135
lv_obj_set_align( ui_img_status_bg, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_img_status_bg, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_img_status_bg, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_TextArea_debug_status = lv_textarea_create(ui_Screen_status);
lv_obj_set_width( ui_TextArea_debug_status, 221);
lv_obj_set_height( ui_TextArea_debug_status, 84);
lv_obj_set_x( ui_TextArea_debug_status, 0 );
lv_obj_set_y( ui_TextArea_debug_status, -21 );
lv_obj_set_align( ui_TextArea_debug_status, LV_ALIGN_CENTER );
lv_textarea_set_placeholder_text(ui_TextArea_debug_status,"...");
lv_obj_set_style_text_font(ui_TextArea_debug_status, &ui_font_RR17, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_TextArea_debug_status, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TextArea_debug_status, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TextArea_debug_status, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_TextArea_debug_status, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_TextArea_debug_status, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_TextArea_debug_status, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_TextArea_debug_status, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_TextArea_debug_status, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_TextArea_debug_status, 0, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_Label3 = lv_label_create(ui_Screen_status);
lv_obj_set_width( ui_Label3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label3, -81 );
lv_obj_set_y( ui_Label3, 57 );
lv_obj_set_align( ui_Label3, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label3,"Menu");
lv_obj_set_style_text_font(ui_Label3, &ui_font_RR13, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4 = lv_label_create(ui_Screen_status);
lv_obj_set_width( ui_Label4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4, -41 );
lv_obj_set_y( ui_Label4, 57 );
lv_obj_set_align( ui_Label4, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label4,"Focus");
lv_obj_set_style_text_font(ui_Label4, &ui_font_RR13, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label5 = lv_label_create(ui_Screen_status);
lv_obj_set_width( ui_Label5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label5, 53 );
lv_obj_set_y( ui_Label5, 57 );
lv_obj_set_align( ui_Label5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label5,"UP");
lv_obj_set_style_text_font(ui_Label5, &ui_font_RR13, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label6 = lv_label_create(ui_Screen_status);
lv_obj_set_width( ui_Label6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label6, 89 );
lv_obj_set_y( ui_Label6, 57 );
lv_obj_set_align( ui_Label6, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label6,"DOWN");
lv_obj_set_style_text_font(ui_Label6, &ui_font_RR13, LV_PART_MAIN| LV_STATE_DEFAULT);

}
