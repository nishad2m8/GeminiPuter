// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: gemini-sls

#include "../ui.h"

void ui_Screen_AiChat_screen_init(void)
{
ui_Screen_AiChat = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen_AiChat, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen_AiChat, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen_AiChat, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_img_chat_bg = lv_img_create(ui_Screen_AiChat);
lv_img_set_src(ui_img_chat_bg, &ui_img_images_chat_bg_png);
lv_obj_set_width( ui_img_chat_bg, LV_SIZE_CONTENT);  /// 240
lv_obj_set_height( ui_img_chat_bg, LV_SIZE_CONTENT);   /// 135
lv_obj_set_align( ui_img_chat_bg, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_img_chat_bg, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_img_chat_bg, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_TextArea_AI_response = lv_textarea_create(ui_Screen_AiChat);
lv_obj_set_width( ui_TextArea_AI_response, 227);
lv_obj_set_height( ui_TextArea_AI_response, 83);
lv_obj_set_x( ui_TextArea_AI_response, 0 );
lv_obj_set_y( ui_TextArea_AI_response, -20 );
lv_obj_set_align( ui_TextArea_AI_response, LV_ALIGN_CENTER );
lv_textarea_set_placeholder_text(ui_TextArea_AI_response,"...");
lv_obj_set_scrollbar_mode(ui_TextArea_AI_response, LV_SCROLLBAR_MODE_ON);
lv_obj_set_scroll_dir(ui_TextArea_AI_response, LV_DIR_VER);
lv_obj_set_style_text_font(ui_TextArea_AI_response, &ui_font_RR17, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_TextArea_AI_response, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TextArea_AI_response, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TextArea_AI_response, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_TextArea_AI_response, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_TextArea_AI_response, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_TextArea_AI_response, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_TextArea_AI_response, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_TextArea_AI_response, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_TextArea_AI_response, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_TextArea_AI_response, 0, LV_PART_MAIN| LV_STATE_FOCUSED);



ui_TextArea_chat_input = lv_textarea_create(ui_Screen_AiChat);
lv_obj_set_width( ui_TextArea_chat_input, 236);
lv_obj_set_height( ui_TextArea_chat_input, 40);
lv_obj_set_x( ui_TextArea_chat_input, 0 );
lv_obj_set_y( ui_TextArea_chat_input, 47 );
lv_obj_set_align( ui_TextArea_chat_input, LV_ALIGN_CENTER );
lv_textarea_set_placeholder_text(ui_TextArea_chat_input,"Ask Gemini");
lv_obj_add_state( ui_TextArea_chat_input, LV_STATE_FOCUSED );     /// States
lv_obj_set_style_text_color(ui_TextArea_chat_input, lv_color_hex(0x4EBD92), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TextArea_chat_input, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_TextArea_chat_input, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_TextArea_chat_input, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TextArea_chat_input, &ui_font_RR17, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_TextArea_chat_input, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TextArea_chat_input, lv_color_hex(0x111411), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TextArea_chat_input, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_TextArea_chat_input, lv_color_hex(0xA0A0A0), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_TextArea_chat_input, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_TextArea_chat_input, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_TextArea_chat_input, 0, LV_PART_MAIN| LV_STATE_FOCUSED);
lv_obj_set_style_border_color(ui_TextArea_chat_input, lv_color_hex(0x4EBD92), LV_PART_MAIN | LV_STATE_FOCUSED );
lv_obj_set_style_border_opa(ui_TextArea_chat_input, 255, LV_PART_MAIN| LV_STATE_FOCUSED);
lv_obj_set_style_border_width(ui_TextArea_chat_input, 2, LV_PART_MAIN| LV_STATE_FOCUSED);

lv_obj_set_style_text_color(ui_TextArea_chat_input, lv_color_hex(0x4EBD92), LV_PART_CURSOR | LV_STATE_FOCUSED );
lv_obj_set_style_text_opa(ui_TextArea_chat_input, 255, LV_PART_CURSOR| LV_STATE_FOCUSED);


}
