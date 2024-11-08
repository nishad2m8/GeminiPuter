/*******************************************************************************
 * Size: 16 px
 * Bpp: 2
 * Opts: --bpp 2 --size 16 --font /Users/redhatdesign/Desktop/gemini/gemini-sls/assets/Fonts/JetBrainsMono-Regular.ttf -o /Users/redhatdesign/Desktop/gemini/gemini-sls/assets/Fonts/ui_font_JBR10.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_JBR10
#define UI_FONT_JBR10 1
#endif

#if UI_FONT_JBR10

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0x38, 0xe3, 0x8e, 0x38, 0xd3, 0x4d, 0x0, 0x3,
    0x8f,

    /* U+0022 "\"" */
    0xb1, 0xcb, 0x1c, 0xb1, 0xc7, 0xc, 0x60, 0xc0,

    /* U+0023 "#" */
    0x2, 0x43, 0x0, 0x34, 0x30, 0x3, 0x7, 0x3,
    0xff, 0xfc, 0x7, 0x9, 0x0, 0xa0, 0xd0, 0x9,
    0xc, 0x0, 0xd0, 0xc0, 0x7f, 0xff, 0x41, 0xc2,
    0x80, 0x1c, 0x24, 0x2, 0x83, 0x0,

    /* U+0024 "$" */
    0x1, 0x0, 0x2, 0x40, 0x2, 0x80, 0x1f, 0xf4,
    0x3a, 0x6c, 0xb2, 0x4c, 0x72, 0x40, 0x3a, 0x40,
    0x1f, 0xd0, 0x2, 0xf8, 0x2, 0x5d, 0x52, 0x4d,
    0xb2, 0x4d, 0x3f, 0xfc, 0xb, 0xe0, 0x2, 0x40,
    0x2, 0x40,

    /* U+0025 "%" */
    0x3f, 0x0, 0xca, 0x28, 0x34, 0xd1, 0x86, 0xa,
    0x28, 0xc0, 0x3f, 0x34, 0x0, 0x6, 0x0, 0x0,
    0xc0, 0x0, 0x35, 0xf8, 0x6, 0x34, 0xd0, 0xc3,
    0xd, 0x34, 0x34, 0xd6, 0x1, 0xf8,

    /* U+0026 "&" */
    0x7, 0xf4, 0x1, 0xe6, 0xc0, 0x1c, 0x9, 0x1,
    0xc0, 0x0, 0xe, 0x0, 0x1, 0xf4, 0x0, 0x39,
    0xc2, 0x83, 0x4b, 0x70, 0x34, 0x3e, 0x3, 0x42,
    0xd0, 0x3d, 0x7f, 0x0, 0xfd, 0x38,

    /* U+0027 "'" */
    0x34, 0xd3, 0x4d, 0x24,

    /* U+0028 "(" */
    0x0, 0x10, 0x1e, 0xb, 0x40, 0xd0, 0x2c, 0x3,
    0x80, 0x34, 0x3, 0x40, 0x34, 0x3, 0x40, 0x34,
    0x3, 0x80, 0x1c, 0x0, 0xf0, 0x3, 0xd0, 0x6,

    /* U+0029 ")" */
    0x10, 0x3, 0xc0, 0xb, 0x0, 0x3c, 0x0, 0xd0,
    0xe, 0x0, 0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0,
    0xe0, 0xd, 0x2, 0xc0, 0x78, 0x2e, 0x2, 0x40,

    /* U+002A "*" */
    0x0, 0xe0, 0x0, 0xd, 0x0, 0x20, 0xd1, 0x43,
    0xea, 0xfc, 0x5, 0xf4, 0x0, 0x2b, 0x40, 0xb,
    0x2c, 0x0, 0xd0, 0xe0, 0x0, 0x0, 0x0,

    /* U+002B "+" */
    0x3, 0x80, 0x3, 0x80, 0x3, 0x80, 0xff, 0xfe,
    0x3, 0x80, 0x3, 0x80, 0x3, 0x80, 0x2, 0x40,

    /* U+002C "," */
    0xf, 0x1d, 0x2c, 0x38, 0x30,

    /* U+002D "-" */
    0x0, 0xf, 0xfd, 0x0, 0x0,

    /* U+002E "." */
    0x24, 0x7c, 0x7c,

    /* U+002F "/" */
    0x0, 0x1c, 0x0, 0x2c, 0x0, 0x34, 0x0, 0x70,
    0x0, 0xe0, 0x0, 0xd0, 0x2, 0xc0, 0x3, 0x80,
    0x7, 0x0, 0xb, 0x0, 0xd, 0x0, 0x1c, 0x0,
    0x38, 0x0, 0x34, 0x0, 0xb0, 0x0,

    /* U+0030 "0" */
    0x1f, 0xe0, 0x39, 0x7c, 0xb0, 0x1c, 0xa0, 0xd,
    0xa0, 0xd, 0xa3, 0x8d, 0xa3, 0x8d, 0xa0, 0xd,
    0xa0, 0xd, 0xb0, 0x1c, 0x39, 0x7c, 0x1f, 0xe0,

    /* U+0031 "1" */
    0xb, 0xc0, 0x3e, 0xc0, 0xb1, 0xc0, 0x41, 0xc0,
    0x1, 0xc0, 0x1, 0xc0, 0x1, 0xc0, 0x1, 0xc0,
    0x1, 0xc0, 0x1, 0xc0, 0x16, 0xd4, 0xbf, 0xfe,

    /* U+0032 "2" */
    0x1f, 0xe0, 0x79, 0x78, 0xb0, 0x1c, 0x50, 0xc,
    0x0, 0x1c, 0x0, 0x38, 0x0, 0xf0, 0x2, 0xc0,
    0xb, 0x0, 0x2d, 0x0, 0x79, 0x54, 0xbf, 0xfd,

    /* U+0033 "3" */
    0x7f, 0xfc, 0x15, 0x78, 0x0, 0xe0, 0x3, 0x40,
    0xb, 0xe0, 0x0, 0x78, 0x0, 0x1c, 0x0, 0x1c,
    0x50, 0x1c, 0xb0, 0x2c, 0x79, 0x78, 0x1f, 0xe0,

    /* U+0034 "4" */
    0x0, 0x70, 0x3, 0x40, 0x2c, 0x1, 0xc0, 0xe,
    0x0, 0xb0, 0x77, 0x41, 0xec, 0x7, 0xbf, 0xfc,
    0x55, 0xb0, 0x1, 0xc0, 0x7,

    /* U+0035 "5" */
    0x7f, 0xfc, 0x75, 0x54, 0x70, 0x0, 0x70, 0x0,
    0x77, 0xf0, 0x79, 0x7c, 0x10, 0x1c, 0x0, 0xc,
    0x0, 0xc, 0x60, 0x1c, 0x39, 0x78, 0x1f, 0xe0,

    /* U+0036 "6" */
    0x1, 0xd0, 0x3, 0xc0, 0xb, 0x0, 0xe, 0x0,
    0x2c, 0x0, 0x7f, 0xf0, 0xb8, 0x7c, 0xe0, 0xd,
    0xe0, 0xe, 0xb0, 0xd, 0x39, 0x7c, 0x1f, 0xe0,

    /* U+0037 "7" */
    0xbf, 0xfe, 0xb5, 0x5d, 0xa0, 0x1c, 0x0, 0x2c,
    0x0, 0x34, 0x0, 0xb0, 0x0, 0xe0, 0x1, 0xc0,
    0x2, 0xc0, 0x3, 0x40, 0x7, 0x0, 0xe, 0x0,

    /* U+0038 "8" */
    0x1f, 0xe0, 0x39, 0x78, 0x70, 0x1c, 0x70, 0x1c,
    0x38, 0x38, 0xf, 0xe0, 0x1e, 0xf0, 0x70, 0x2c,
    0xa0, 0xd, 0xb0, 0xc, 0x79, 0x7c, 0x1f, 0xe0,

    /* U+0039 "9" */
    0x1f, 0xe0, 0x79, 0x7c, 0xb0, 0xd, 0xe0, 0xd,
    0xe0, 0xd, 0xb4, 0x2d, 0x2f, 0xfc, 0x0, 0x74,
    0x0, 0xe0, 0x2, 0xc0, 0x3, 0x80, 0xb, 0x0,

    /* U+003A ":" */
    0x7c, 0x7c, 0x10, 0x0, 0x0, 0x0, 0x10, 0x7c,
    0x7c,

    /* U+003B ";" */
    0x1f, 0x7, 0xc0, 0x40, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3c, 0x1d, 0xb, 0x3, 0x80, 0xc0,

    /* U+003C "<" */
    0x0, 0x0, 0x0, 0x2c, 0x2, 0xe0, 0x2e, 0x0,
    0xb0, 0x0, 0x7d, 0x0, 0xb, 0xd0, 0x0, 0xbc,
    0x0, 0x8,

    /* U+003D "=" */
    0x0, 0x0, 0xbf, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xbf, 0xfc, 0x0, 0x0,

    /* U+003E ">" */
    0x40, 0x0, 0xb4, 0x0, 0x1f, 0x40, 0x1, 0xf4,
    0x0, 0x1c, 0x0, 0x7c, 0xb, 0xd0, 0x7d, 0x0,
    0x90, 0x0,

    /* U+003F "?" */
    0xff, 0x45, 0x7c, 0x0, 0xe0, 0xb, 0x0, 0xb0,
    0x1d, 0x2f, 0x82, 0xc0, 0x18, 0x0, 0x0, 0x3c,
    0x3, 0xc0,

    /* U+0040 "@" */
    0x7, 0xfd, 0x7, 0x81, 0xd3, 0x80, 0x28, 0xc0,
    0x7, 0x70, 0x7d, 0xdc, 0x38, 0xb7, 0xc, 0x1d,
    0xc3, 0x7, 0x70, 0xc1, 0xdc, 0x34, 0xb7, 0x7,
    0xdc, 0xc0, 0x0, 0x38, 0x0, 0x7, 0x90, 0x0,
    0x2f, 0x40,

    /* U+0041 "A" */
    0x1, 0xf0, 0x0, 0xbc, 0x0, 0x3b, 0x40, 0xd,
    0xe0, 0x7, 0x2c, 0x2, 0xc7, 0x0, 0xe0, 0xd0,
    0x34, 0x38, 0x1f, 0xff, 0xb, 0x1, 0xc3, 0x80,
    0x34, 0xd0, 0xe,

    /* U+0042 "B" */
    0xbf, 0xe0, 0xb5, 0x7c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x3c, 0xbf, 0xf0, 0xb0, 0x7c, 0xb0, 0xd,
    0xb0, 0xd, 0xb0, 0xd, 0xb5, 0x7c, 0xbf, 0xe0,

    /* U+0043 "C" */
    0xf, 0xe0, 0x3d, 0x7c, 0x70, 0x1c, 0xb0, 0x4,
    0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0,
    0xb0, 0x4, 0x70, 0x1c, 0x3d, 0x7c, 0xf, 0xe0,

    /* U+0044 "D" */
    0xbf, 0xe0, 0xb5, 0x78, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xb0, 0x1c, 0xb5, 0x78, 0xbf, 0xe0,

    /* U+0045 "E" */
    0x7f, 0xfd, 0x75, 0x54, 0x70, 0x0, 0x70, 0x0,
    0x70, 0x0, 0x7f, 0xfc, 0x74, 0x0, 0x70, 0x0,
    0x70, 0x0, 0x70, 0x0, 0x75, 0x54, 0x7f, 0xfd,

    /* U+0046 "F" */
    0x7f, 0xfd, 0x75, 0x54, 0x70, 0x0, 0x70, 0x0,
    0x70, 0x0, 0x70, 0x0, 0x7f, 0xfc, 0x75, 0x50,
    0x70, 0x0, 0x70, 0x0, 0x70, 0x0, 0x70, 0x0,

    /* U+0047 "G" */
    0xf, 0xe0, 0x3d, 0x7c, 0x70, 0x1c, 0xb0, 0x4,
    0xb0, 0x0, 0xb0, 0x0, 0xb2, 0xfd, 0xb0, 0x5d,
    0xb0, 0xd, 0x70, 0x1c, 0x39, 0x7c, 0xf, 0xe0,

    /* U+0048 "H" */
    0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xbf, 0xfc, 0xb5, 0x5c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c,

    /* U+0049 "I" */
    0x7f, 0xfc, 0x5e, 0x50, 0x38, 0x0, 0xe0, 0x3,
    0x80, 0xe, 0x0, 0x38, 0x0, 0xe0, 0x3, 0x80,
    0xe, 0x1, 0x79, 0x5f, 0xff,

    /* U+004A "J" */
    0x1, 0xff, 0x0, 0x5b, 0x0, 0xb, 0x0, 0xb,
    0x0, 0xb, 0x0, 0xb, 0x0, 0xb, 0x0, 0xb,
    0x20, 0xb, 0x34, 0xb, 0x2d, 0x6d, 0xb, 0xf4,

    /* U+004B "K" */
    0xb0, 0xe, 0xb0, 0x2c, 0xb0, 0x34, 0xb0, 0xb0,
    0xb0, 0xd0, 0xbf, 0xc0, 0xb1, 0xd0, 0xb0, 0xf0,
    0xb0, 0x74, 0xb0, 0x3c, 0xb0, 0x1c, 0xb0, 0xe,

    /* U+004C "L" */
    0x34, 0x0, 0x34, 0x0, 0x34, 0x0, 0x34, 0x0,
    0x34, 0x0, 0x34, 0x0, 0x34, 0x0, 0x34, 0x0,
    0x34, 0x0, 0x34, 0x0, 0x39, 0x54, 0x3f, 0xfe,

    /* U+004D "M" */
    0xf4, 0x2d, 0xf8, 0x3d, 0xec, 0x79, 0xdc, 0xad,
    0xda, 0xdd, 0xe7, 0xcd, 0xe2, 0x8d, 0xe0, 0xd,
    0xe0, 0xd, 0xe0, 0xd, 0xe0, 0xd, 0xe0, 0xd,

    /* U+004E "N" */
    0xb8, 0xc, 0xbc, 0xc, 0xbc, 0xc, 0xba, 0xc,
    0xb7, 0xc, 0xb3, 0x4c, 0xb2, 0x8c, 0xb1, 0xdc,
    0xb0, 0xdc, 0xb0, 0xbc, 0xb0, 0x7c, 0xb0, 0x3c,

    /* U+004F "O" */
    0x1f, 0xe0, 0x39, 0x78, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xb0, 0x1c, 0x39, 0x78, 0x1f, 0xe0,

    /* U+0050 "P" */
    0xbf, 0xf4, 0xb5, 0x6c, 0xb0, 0xe, 0xb0, 0xb,
    0xb0, 0xe, 0xb0, 0x2d, 0xbf, 0xf8, 0xb0, 0x0,
    0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0,

    /* U+0051 "Q" */
    0x1f, 0xe0, 0x39, 0x7c, 0xb0, 0x1c, 0xa0, 0xd,
    0xa0, 0xd, 0xa0, 0xd, 0xa0, 0xd, 0xa0, 0xd,
    0xa0, 0xd, 0xb0, 0x1c, 0x39, 0x7c, 0x1f, 0xf0,
    0x0, 0xb0, 0x0, 0x38, 0x0, 0x2c,

    /* U+0052 "R" */
    0xbf, 0xe0, 0xb5, 0x7c, 0xb0, 0xd, 0xb0, 0xe,
    0xb0, 0xd, 0xb0, 0x2c, 0xbf, 0xf4, 0xb1, 0xd0,
    0xb0, 0xb0, 0xb0, 0x34, 0xb0, 0x2c, 0xb0, 0xd,

    /* U+0053 "S" */
    0xf, 0xe0, 0x39, 0x7c, 0x70, 0x1c, 0xb0, 0x0,
    0x38, 0x0, 0x2f, 0x90, 0x2, 0xf8, 0x0, 0x2c,
    0x0, 0xd, 0xe0, 0xd, 0x79, 0x7c, 0x1f, 0xe0,

    /* U+0054 "T" */
    0x3f, 0xff, 0x85, 0x79, 0x40, 0xe, 0x0, 0x3,
    0x80, 0x0, 0xe0, 0x0, 0x38, 0x0, 0xe, 0x0,
    0x3, 0x80, 0x0, 0xe0, 0x0, 0x38, 0x0, 0xe,
    0x0, 0x3, 0x80,

    /* U+0055 "U" */
    0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0x70, 0x1c, 0x39, 0x78, 0x1f, 0xe0,

    /* U+0056 "V" */
    0x34, 0x3, 0x8e, 0x0, 0xd2, 0xc0, 0x70, 0x70,
    0x2c, 0xd, 0xe, 0x3, 0x83, 0x40, 0xb0, 0xc0,
    0x1c, 0x70, 0x3, 0x68, 0x0, 0xed, 0x0, 0x2f,
    0x0, 0x7, 0xc0,

    /* U+0057 "W" */
    0xb0, 0xe0, 0xc7, 0xe, 0x1c, 0x70, 0xb1, 0xc3,
    0x1b, 0x1c, 0x31, 0x72, 0x83, 0x66, 0x28, 0x36,
    0x27, 0x43, 0xb1, 0x74, 0x2b, 0x1b, 0x2, 0xf1,
    0xb0, 0x1e, 0xf, 0x1, 0xe0, 0xf0,

    /* U+0058 "X" */
    0x38, 0x3, 0x87, 0x2, 0xc0, 0xf0, 0xd0, 0x1d,
    0xb0, 0x3, 0xf4, 0x0, 0x3c, 0x0, 0x1f, 0x0,
    0xe, 0xe0, 0x7, 0x2c, 0x3, 0x83, 0x82, 0xc0,
    0x70, 0xd0, 0xe,

    /* U+0059 "Y" */
    0x34, 0x2, 0xc2, 0xc0, 0x34, 0x1c, 0xb, 0x0,
    0xe0, 0xd0, 0x7, 0x2c, 0x0, 0x3b, 0x40, 0x1,
    0xf0, 0x0, 0xe, 0x0, 0x0, 0xe0, 0x0, 0xe,
    0x0, 0x0, 0xe0, 0x0, 0xe, 0x0,

    /* U+005A "Z" */
    0xbf, 0xfc, 0x15, 0x6c, 0x0, 0x34, 0x0, 0xb0,
    0x0, 0xd0, 0x3, 0xc0, 0x7, 0x0, 0xe, 0x0,
    0x1c, 0x0, 0x34, 0x0, 0xb5, 0x54, 0xbf, 0xfc,

    /* U+005B "[" */
    0x0, 0x2f, 0xcb, 0x2, 0x80, 0xa0, 0x28, 0xa,
    0x2, 0x80, 0xa0, 0x28, 0xa, 0x2, 0x80, 0xa0,
    0x28, 0xa, 0x2, 0xfc, 0x0, 0x0,

    /* U+005C "\\" */
    0xb0, 0x0, 0x34, 0x0, 0x38, 0x0, 0x1c, 0x0,
    0xd, 0x0, 0xb, 0x0, 0x7, 0x0, 0x3, 0x80,
    0x2, 0xc0, 0x0, 0xd0, 0x0, 0xe0, 0x0, 0x70,
    0x0, 0x34, 0x0, 0x2c, 0x0, 0x1c,

    /* U+005D "]" */
    0x0, 0x2f, 0xd0, 0x74, 0xd, 0x3, 0x40, 0xd0,
    0x34, 0xd, 0x3, 0x40, 0xd0, 0x34, 0xd, 0x3,
    0x40, 0xd0, 0x36, 0xfd, 0x0, 0x0,

    /* U+005E "^" */
    0x1, 0x40, 0x7, 0xc0, 0x9, 0xd0, 0xc, 0x70,
    0x28, 0x30, 0x30, 0x28, 0x70, 0xc,

    /* U+005F "_" */
    0x0, 0x0, 0xf, 0xff, 0xe0, 0x0, 0x0,

    /* U+0060 "`" */
    0x14, 0x7, 0x0, 0xb0,

    /* U+0061 "a" */
    0xf, 0xe0, 0x39, 0x7c, 0x60, 0x1c, 0x0, 0x1c,
    0x2f, 0xfc, 0xb0, 0x1c, 0xe0, 0x1c, 0xb4, 0x7c,
    0x2f, 0x9c,

    /* U+0062 "b" */
    0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0, 0xb7, 0xf0,
    0xb9, 0x7c, 0xb0, 0x1c, 0xb0, 0xc, 0xb0, 0xc,
    0xb0, 0xc, 0xb0, 0x1c, 0xb9, 0x7c, 0xb7, 0xf0,

    /* U+0063 "c" */
    0x1f, 0xe0, 0x39, 0x7c, 0xb0, 0x1c, 0xb0, 0x0,
    0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x1c, 0x39, 0x7c,
    0x1f, 0xe0,

    /* U+0064 "d" */
    0x0, 0x1c, 0x0, 0x1c, 0x0, 0x1c, 0x1f, 0xdc,
    0x79, 0x7c, 0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xb0, 0x1c, 0x39, 0x7c, 0x1f, 0x9c,

    /* U+0065 "e" */
    0x1f, 0xe0, 0x38, 0x78, 0xb0, 0x1c, 0xb0, 0xc,
    0xbf, 0xfc, 0xb0, 0x0, 0xb0, 0x4, 0x39, 0x7c,
    0x1f, 0xe0,

    /* U+0066 "f" */
    0x0, 0xbf, 0x80, 0x75, 0x40, 0x1c, 0x0, 0xb,
    0x0, 0x3f, 0xff, 0x85, 0xb5, 0x40, 0x1c, 0x0,
    0x7, 0x0, 0x1, 0xc0, 0x0, 0x70, 0x0, 0x1c,
    0x0, 0x7, 0x0,

    /* U+0067 "g" */
    0x1f, 0x9c, 0x39, 0x7c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xb0, 0x1c, 0x74, 0x3c, 0x2f, 0xec,
    0x0, 0x1c, 0x0, 0x1c, 0x5, 0x7c, 0x1f, 0xf0,

    /* U+0068 "h" */
    0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0, 0xb7, 0xe0,
    0xb9, 0x7c, 0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c,

    /* U+0069 "i" */
    0x3, 0xc0, 0x3, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xc0, 0x16, 0xc0, 0x2, 0xc0, 0x2, 0xc0,
    0x2, 0xc0, 0x2, 0xc0, 0x2, 0xc0, 0x16, 0xd5,
    0xbf, 0xff,

    /* U+006A "j" */
    0x0, 0xf0, 0x3, 0xc0, 0x0, 0x0, 0x0, 0x3f,
    0xf0, 0x56, 0xc0, 0x7, 0x0, 0x1c, 0x0, 0x70,
    0x1, 0xc0, 0x7, 0x0, 0x1c, 0x0, 0x70, 0x2,
    0xc1, 0x6d, 0x2f, 0xd0,

    /* U+006B "k" */
    0x70, 0x0, 0x70, 0x0, 0x70, 0x0, 0x70, 0xe,
    0x70, 0x2c, 0x70, 0x70, 0x70, 0xe0, 0x7f, 0xc0,
    0x71, 0xe0, 0x70, 0x70, 0x70, 0x3c, 0x70, 0xe,

    /* U+006C "l" */
    0xbf, 0xc0, 0x5, 0xb0, 0x0, 0x2c, 0x0, 0xb,
    0x0, 0x2, 0xc0, 0x0, 0xb0, 0x0, 0x2c, 0x0,
    0xb, 0x0, 0x2, 0xc0, 0x0, 0xb0, 0x0, 0x1d,
    0x54, 0x2, 0xff,

    /* U+006D "m" */
    0xef, 0x7c, 0xe3, 0x8d, 0xd3, 0x4e, 0xd3, 0x4e,
    0xd3, 0x4e, 0xd3, 0x4e, 0xd3, 0x4e, 0xd3, 0x4e,
    0xd3, 0x4e,

    /* U+006E "n" */
    0xb7, 0xe0, 0xb8, 0x3c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c,

    /* U+006F "o" */
    0x1f, 0xe0, 0x39, 0x7c, 0xb0, 0x1c, 0xb0, 0xc,
    0xb0, 0xc, 0xb0, 0xc, 0xb0, 0x1c, 0x39, 0x7c,
    0x1f, 0xe0,

    /* U+0070 "p" */
    0xb7, 0xf0, 0xb8, 0x3c, 0xb0, 0x1c, 0xb0, 0xc,
    0xb0, 0xc, 0xb0, 0xc, 0xb0, 0x1c, 0xb9, 0x7c,
    0xb7, 0xf0, 0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0,

    /* U+0071 "q" */
    0x1f, 0x9c, 0x39, 0x7c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c, 0x39, 0x7c,
    0x1f, 0xdc, 0x0, 0x1c, 0x0, 0x1c, 0x0, 0x1c,

    /* U+0072 "r" */
    0x37, 0xf4, 0x38, 0x2c, 0x34, 0xd, 0x30, 0x9,
    0x30, 0x0, 0x30, 0x0, 0x30, 0x0, 0x30, 0x0,
    0x30, 0x0,

    /* U+0073 "s" */
    0x1f, 0xf0, 0x39, 0x6c, 0x70, 0x0, 0x39, 0x0,
    0x1f, 0xf4, 0x0, 0x2c, 0x10, 0xd, 0x79, 0x6c,
    0x1f, 0xf4,

    /* U+0074 "t" */
    0x1, 0x40, 0x0, 0xb0, 0x0, 0x2c, 0x0, 0xff,
    0xfd, 0x17, 0xd5, 0x0, 0xb0, 0x0, 0x2c, 0x0,
    0xb, 0x0, 0x2, 0xc0, 0x0, 0xb0, 0x0, 0x1d,
    0x50, 0x2, 0xfc,

    /* U+0075 "u" */
    0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c, 0xb0, 0x1c,
    0xb0, 0x1c, 0xb0, 0x1c, 0x70, 0x1c, 0x39, 0x78,
    0xf, 0xe0,

    /* U+0076 "v" */
    0x38, 0x3, 0x8b, 0x0, 0xc1, 0xc0, 0xb0, 0x34,
    0x38, 0xb, 0xd, 0x1, 0xc7, 0x0, 0x37, 0x80,
    0xb, 0xd0, 0x1, 0xf0, 0x0,

    /* U+0077 "w" */
    0x70, 0xe0, 0xc3, 0xe, 0x1c, 0x31, 0xb2, 0x83,
    0x57, 0x24, 0x26, 0x63, 0x42, 0xa2, 0x70, 0x1b,
    0x1b, 0x1, 0xf0, 0xf0, 0xe, 0xe, 0x0,

    /* U+0078 "x" */
    0x2c, 0x7, 0x43, 0x83, 0x80, 0x76, 0xc0, 0xb,
    0xd0, 0x1, 0xf0, 0x0, 0xfd, 0x0, 0xb2, 0xc0,
    0x34, 0x3c, 0x3c, 0x3, 0x40,

    /* U+0079 "y" */
    0x38, 0x3, 0x8b, 0x1, 0xc0, 0xd0, 0xb0, 0x3c,
    0x34, 0x7, 0x1c, 0x0, 0xda, 0x0, 0x2f, 0x40,
    0x3, 0xc0, 0x0, 0xe0, 0x0, 0x34, 0x0, 0x2c,
    0x0, 0xe, 0x0,

    /* U+007A "z" */
    0x7f, 0xfc, 0x15, 0x7c, 0x0, 0xb0, 0x1, 0xd0,
    0x3, 0x80, 0xe, 0x0, 0x2c, 0x0, 0x75, 0x54,
    0xbf, 0xfc,

    /* U+007B "{" */
    0x0, 0x0, 0x0, 0x7c, 0x1, 0xe0, 0x1, 0xc0,
    0x1, 0xc0, 0x1, 0xc0, 0x1, 0xc0, 0x2, 0xc0,
    0xbf, 0x0, 0x6, 0xc0, 0x1, 0xc0, 0x1, 0xc0,
    0x1, 0xc0, 0x1, 0xc0, 0x1, 0xd0, 0x0, 0xbc,
    0x0, 0x0,

    /* U+007C "|" */
    0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xe0,

    /* U+007D "}" */
    0x0, 0x0, 0xbc, 0x0, 0x1f, 0x0, 0x7, 0x0,
    0x7, 0x0, 0xb, 0x0, 0xb, 0x0, 0x7, 0x0,
    0x2, 0xfc, 0x7, 0x40, 0xb, 0x0, 0xb, 0x0,
    0x7, 0x0, 0x7, 0x0, 0xb, 0x0, 0xbd, 0x0,
    0x0, 0x0,

    /* U+007E "~" */
    0x7e, 0xe, 0xe7, 0x8e, 0xd1, 0xfc, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 154, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 154, .box_w = 3, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 9, .adv_w = 154, .box_w = 6, .box_h = 5, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 17, .adv_w = 154, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 154, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 81, .adv_w = 154, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 154, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 154, .box_w = 3, .box_h = 5, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 145, .adv_w = 154, .box_w = 6, .box_h = 16, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 169, .adv_w = 154, .box_w = 6, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 193, .adv_w = 154, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 216, .adv_w = 154, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 232, .adv_w = 154, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 237, .adv_w = 154, .box_w = 6, .box_h = 3, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 242, .adv_w = 154, .box_w = 4, .box_h = 3, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 154, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 275, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 299, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 371, .adv_w = 154, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 392, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 416, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 440, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 464, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 488, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 512, .adv_w = 154, .box_w = 4, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 521, .adv_w = 154, .box_w = 5, .box_h = 12, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 536, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 554, .adv_w = 154, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 568, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 586, .adv_w = 154, .box_w = 6, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 154, .box_w = 9, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 638, .adv_w = 154, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 665, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 689, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 713, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 737, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 761, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 785, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 809, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 833, .adv_w = 154, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 854, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 878, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 902, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 926, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 950, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 974, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 998, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1022, .adv_w = 154, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1052, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1076, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1100, .adv_w = 154, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1127, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1151, .adv_w = 154, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1178, .adv_w = 154, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1208, .adv_w = 154, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1235, .adv_w = 154, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1265, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1289, .adv_w = 154, .box_w = 5, .box_h = 17, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 1311, .adv_w = 154, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1341, .adv_w = 154, .box_w = 5, .box_h = 17, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1363, .adv_w = 154, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 1377, .adv_w = 154, .box_w = 9, .box_h = 3, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1384, .adv_w = 154, .box_w = 5, .box_h = 3, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 1388, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1406, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1430, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1448, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1472, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1490, .adv_w = 154, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1517, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1541, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1565, .adv_w = 154, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1591, .adv_w = 154, .box_w = 7, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1619, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1643, .adv_w = 154, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1670, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1688, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1706, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1724, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1748, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1772, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1790, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1808, .adv_w = 154, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1835, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1853, .adv_w = 154, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1874, .adv_w = 154, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1897, .adv_w = 154, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1918, .adv_w = 154, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1945, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1963, .adv_w = 154, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1997, .adv_w = 154, .box_w = 2, .box_h = 15, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 2005, .adv_w = 154, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 2039, .adv_w = 154, .box_w = 8, .box_h = 4, .ofs_x = 1, .ofs_y = 3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_JBR10 = {
#else
lv_font_t ui_font_JBR10 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_JBR10*/

