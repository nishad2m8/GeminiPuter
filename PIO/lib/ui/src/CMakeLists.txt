SET(SOURCES screens/ui_Screen_loading.c
    screens/ui_Screen_status.c
    screens/ui_Screen_AiChat.c
    screens/ui_Screen_Menu.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_images_loading_bg_png.c
    images/ui_img_images_status_bg_png.c
    images/ui_img_images_chat_bg_png.c
    images/ui_img_images_menu_bg_png.c
    images/ui_img_images_battery_main_png.c
    images/ui_img_images_battery_indicator_png.c
    images/ui_img_images_mask_png.c
    fonts/ui_font_RR17.c
    fonts/ui_font_RR13.c)

add_library(ui ${SOURCES})
