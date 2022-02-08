/*******************************************************************************
 * Size: 18 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef LV_FONT_COMMON_18
#define LV_FONT_COMMON_18 1
#endif

#if LV_FONT_COMMON_18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0xcc, 0xdd, 0xdd, 0xdd, 0xdc, 0xbb, 0x99, 0x87,
    0x66, 0x22, 0x88, 0xcc,

    /* U+0022 "\"" */
    0x5d, 0x5c, 0x3b, 0x4b, 0x2a, 0x39, 0x5, 0x15,

    /* U+0023 "#" */
    0x0, 0xb, 0x50, 0x3c, 0x0, 0x0, 0xd2, 0x6,
    0x90, 0x0, 0xf, 0x0, 0x96, 0x0, 0xdf, 0xff,
    0xff, 0xf6, 0x2, 0x8a, 0x22, 0xf3, 0x0, 0x9,
    0x70, 0x2e, 0x0, 0x0, 0xc3, 0x5, 0xb0, 0x0,
    0xf, 0x0, 0x88, 0x0, 0x5f, 0xff, 0xff, 0xfe,
    0x0, 0x7b, 0x22, 0xe3, 0x20, 0x8, 0x80, 0x1f,
    0x0, 0x0, 0xb5, 0x4, 0xc0, 0x0,

    /* U+0024 "$" */
    0x0, 0x0, 0xb2, 0x0, 0x0, 0x3, 0x9e, 0xb5,
    0x0, 0x4, 0xfe, 0xed, 0xf7, 0x0, 0xdc, 0xb,
    0x29, 0xf2, 0xe, 0xa0, 0xb2, 0x18, 0x30, 0x9f,
    0x4b, 0x20, 0x0, 0x0, 0xaf, 0xf3, 0x0, 0x0,
    0x0, 0x4e, 0xfa, 0x10, 0x0, 0x0, 0xb6, 0xdf,
    0x30, 0x0, 0xb, 0x20, 0xdd, 0x4f, 0x70, 0xb2,
    0xc, 0xd0, 0xbf, 0x5c, 0x59, 0xf6, 0x0, 0x7d,
    0xff, 0xc5, 0x0, 0x0, 0xb, 0x20, 0x0, 0x0,
    0x0, 0xb2, 0x0, 0x0,

    /* U+0025 "%" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0xde,
    0x60, 0x0, 0x2c, 0x0, 0xe, 0x42, 0xd2, 0x0,
    0xc7, 0x0, 0x3c, 0x0, 0x87, 0x6, 0xc0, 0x0,
    0x3c, 0x0, 0x87, 0x1e, 0x20, 0x0, 0xe, 0x20,
    0xd3, 0xb8, 0x0, 0x0, 0x5, 0xef, 0x85, 0xd0,
    0x0, 0x0, 0x0, 0x0, 0x1e, 0x38, 0xdc, 0x20,
    0x0, 0x0, 0xa9, 0x5d, 0x36, 0xc0, 0x0, 0x4,
    0xe0, 0x96, 0x0, 0xe1, 0x0, 0xe, 0x40, 0x96,
    0x0, 0xe1, 0x0, 0x9a, 0x0, 0x5c, 0x25, 0xd0,
    0x0, 0xc1, 0x0, 0x9, 0xed, 0x30, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,

    /* U+0026 "&" */
    0x0, 0x0, 0x7e, 0xe9, 0x0, 0x0, 0x0, 0x7,
    0xf6, 0x5f, 0x60, 0x0, 0x0, 0xc, 0x90, 0xb,
    0xb0, 0x0, 0x0, 0xd, 0x80, 0xd, 0x90, 0x0,
    0x0, 0x9, 0xc4, 0xdd, 0x10, 0x0, 0x0, 0xa,
    0xfe, 0x70, 0x0, 0x0, 0x3, 0xec, 0xbc, 0x0,
    0x8, 0x90, 0x1e, 0xa0, 0x1f, 0x80, 0xe, 0x90,
    0x6f, 0x20, 0x5, 0xf5, 0x4f, 0x30, 0x5f, 0x40,
    0x0, 0x8f, 0xea, 0x0, 0xd, 0xe6, 0x34, 0x8f,
    0xfb, 0x62, 0x1, 0x8d, 0xfe, 0xb4, 0x4b, 0xf5,

    /* U+0027 "'" */
    0x5d, 0x3b, 0x2a, 0x5,

    /* U+0028 "(" */
    0x0, 0x0, 0x80, 0x0, 0x9, 0xe2, 0x0, 0x6f,
    0x30, 0x1, 0xf7, 0x0, 0x8, 0xc0, 0x0, 0xe,
    0x50, 0x0, 0x3f, 0x0, 0x0, 0x6c, 0x0, 0x0,
    0x7b, 0x0, 0x0, 0x7b, 0x0, 0x0, 0x5d, 0x0,
    0x0, 0x2f, 0x10, 0x0, 0xd, 0x70, 0x0, 0x6,
    0xe1, 0x0, 0x0, 0xda, 0x0, 0x0, 0x3f, 0x70,
    0x0, 0x5, 0xf3, 0x0, 0x0, 0x30,

    /* U+0029 ")" */
    0x8, 0x0, 0x0, 0x2e, 0x90, 0x0, 0x3, 0xf5,
    0x0, 0x0, 0x7e, 0x10, 0x0, 0xc, 0x80, 0x0,
    0x5, 0xe0, 0x0, 0x0, 0xf3, 0x0, 0x0, 0xd5,
    0x0, 0x0, 0xb7, 0x0, 0x0, 0xc6, 0x0, 0x0,
    0xe5, 0x0, 0x1, 0xf2, 0x0, 0x7, 0xd0, 0x0,
    0x1e, 0x60, 0x0, 0xad, 0x0, 0x7, 0xf2, 0x0,
    0x3f, 0x50, 0x0, 0x3, 0x0, 0x0,

    /* U+002A "*" */
    0x0, 0x89, 0x0, 0x2, 0x7, 0x80, 0x20, 0xdb,
    0x45, 0xae, 0x0, 0x58, 0x95, 0x0, 0x39, 0x98,
    0x94, 0xc, 0x66, 0x66, 0xd0, 0x0, 0x89, 0x0,
    0x0, 0x0, 0x0, 0x0,

    /* U+002B "+" */
    0x0, 0x5, 0xa0, 0x0, 0x0, 0x5, 0xa0, 0x0,
    0x0, 0x5, 0xa0, 0x0, 0x0, 0x5, 0xa0, 0x0,
    0x0, 0x5, 0xa0, 0x0, 0x6f, 0xff, 0xff, 0xfb,
    0x2, 0x26, 0xa2, 0x21, 0x0, 0x5, 0xa0, 0x0,
    0x0, 0x5, 0xa0, 0x0,

    /* U+002C "," */
    0x2c, 0x63, 0xf9, 0x4, 0x70, 0xb0, 0x12, 0x0,

    /* U+002D "-" */
    0x4f, 0xff, 0xf3, 0x2, 0x22, 0x20,

    /* U+002E "." */
    0x3d, 0x64, 0xf8,

    /* U+002F "/" */
    0x0, 0x1, 0x0, 0x0, 0x88, 0x0, 0xb, 0x50,
    0x0, 0xe1, 0x0, 0x2e, 0x0, 0x5, 0xb0, 0x0,
    0x87, 0x0, 0xb, 0x40, 0x0, 0xf1, 0x0, 0x2d,
    0x0, 0x5, 0xa0, 0x0, 0x97, 0x0, 0xc, 0x30,
    0x0, 0xf0, 0x0, 0x3d, 0x0, 0x6, 0x90, 0x0,
    0x65, 0x0, 0x0,

    /* U+0030 "0" */
    0x0, 0x6d, 0xfd, 0x70, 0x0, 0x6f, 0x62, 0x5f,
    0x70, 0xe, 0x70, 0x0, 0x6f, 0x4, 0xf1, 0x0,
    0x0, 0xf4, 0x6e, 0x0, 0x0, 0xd, 0x77, 0xd0,
    0x0, 0x0, 0xb9, 0x7d, 0x0, 0x0, 0xb, 0x96,
    0xe0, 0x0, 0x0, 0xd7, 0x3f, 0x10, 0x0, 0xf,
    0x50, 0xe7, 0x0, 0x6, 0xf0, 0x6, 0xf6, 0x25,
    0xf7, 0x0, 0x5, 0xdf, 0xd6, 0x0,

    /* U+0031 "1" */
    0x16, 0xeb, 0xed, 0xcb, 0x30, 0x8b, 0x0, 0x8b,
    0x0, 0x8b, 0x0, 0x8b, 0x0, 0x8b, 0x0, 0x8b,
    0x0, 0x8b, 0x0, 0x8b, 0x0, 0x8b, 0x0, 0x8b,

    /* U+0032 "2" */
    0x0, 0x5c, 0xfd, 0x70, 0x0, 0x5f, 0x50, 0x3e,
    0x70, 0xd, 0x70, 0x0, 0x7e, 0x0, 0xa2, 0x0,
    0x5, 0xf0, 0x0, 0x0, 0x0, 0xca, 0x0, 0x0,
    0x0, 0x9e, 0x20, 0x0, 0x0, 0xae, 0x30, 0x0,
    0x0, 0xbe, 0x20, 0x0, 0x0, 0x9e, 0x20, 0x0,
    0x0, 0x3f, 0x40, 0x0, 0x0, 0x9, 0xd3, 0x33,
    0x33, 0x0, 0xdf, 0xff, 0xff, 0xf3,

    /* U+0033 "3" */
    0x0, 0x5d, 0xfd, 0x60, 0x0, 0x4f, 0x40, 0x4f,
    0x60, 0x8, 0x80, 0x0, 0x8c, 0x0, 0x0, 0x0,
    0x9, 0xc0, 0x0, 0x0, 0x5, 0xf4, 0x0, 0x1,
    0xff, 0xf9, 0x0, 0x0, 0x0, 0x3, 0xd8, 0x0,
    0x0, 0x0, 0x4, 0xf1, 0x5, 0x20, 0x0, 0x1f,
    0x30, 0xd9, 0x0, 0x4, 0xf1, 0x5, 0xf7, 0x36,
    0xe8, 0x0, 0x5, 0xdf, 0xd6, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x3, 0xf0, 0x0, 0x0, 0x0, 0xef,
    0x0, 0x0, 0x0, 0xaa, 0xf0, 0x0, 0x0, 0x5d,
    0x1f, 0x0, 0x0, 0x1e, 0x30, 0xf0, 0x0, 0xb,
    0x80, 0xf, 0x0, 0x6, 0xd0, 0x0, 0xf0, 0x2,
    0xe2, 0x0, 0xf, 0x0, 0x7f, 0xff, 0xff, 0xff,
    0x70, 0x22, 0x22, 0x2f, 0x21, 0x0, 0x0, 0x0,
    0xf0, 0x0, 0x0, 0x0, 0xf, 0x0,

    /* U+0035 "5" */
    0x4, 0xff, 0xff, 0xfa, 0x0, 0x6d, 0x44, 0x44,
    0x20, 0x8, 0xa0, 0x0, 0x0, 0x0, 0x98, 0x0,
    0x0, 0x0, 0xb, 0xab, 0xee, 0x80, 0x0, 0xce,
    0x40, 0x4e, 0x80, 0x0, 0x10, 0x0, 0x5f, 0x10,
    0x0, 0x0, 0x0, 0xf4, 0x2, 0x0, 0x0, 0xf,
    0x50, 0xf6, 0x0, 0x5, 0xf1, 0x7, 0xf5, 0x14,
    0xe8, 0x0, 0x6, 0xdf, 0xd6, 0x0,

    /* U+0036 "6" */
    0x0, 0x2b, 0xfe, 0x90, 0x0, 0x1e, 0x91, 0x3e,
    0xa0, 0x8, 0xc0, 0x0, 0x36, 0x0, 0xd7, 0x0,
    0x0, 0x0, 0xf, 0x48, 0xde, 0x90, 0x1, 0xfe,
    0x83, 0x5e, 0x90, 0x1f, 0x60, 0x0, 0x5f, 0x10,
    0xf4, 0x0, 0x1, 0xf3, 0xe, 0x60, 0x0, 0x2f,
    0x20, 0x9b, 0x0, 0x7, 0xe0, 0x2, 0xf7, 0x14,
    0xe6, 0x0, 0x3, 0xcf, 0xe7, 0x0,

    /* U+0037 "7" */
    0xf, 0xff, 0xff, 0xff, 0x20, 0x44, 0x44, 0x4a,
    0xf1, 0x0, 0x0, 0x2, 0xf5, 0x0, 0x0, 0x0,
    0xcb, 0x0, 0x0, 0x0, 0x5f, 0x20, 0x0, 0x0,
    0xd, 0x90, 0x0, 0x0, 0x3, 0xf3, 0x0, 0x0,
    0x0, 0x7f, 0x0, 0x0, 0x0, 0xb, 0xb0, 0x0,
    0x0, 0x0, 0xd8, 0x0, 0x0, 0x0, 0xe, 0x70,
    0x0, 0x0, 0x0, 0xf6, 0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x8d, 0xfd, 0x60, 0x0, 0xbd, 0x30, 0x4f,
    0x60, 0xf, 0x50, 0x0, 0x9c, 0x0, 0xf6, 0x0,
    0x9, 0xc0, 0x8, 0xe4, 0x7, 0xf5, 0x0, 0x7,
    0xff, 0xf5, 0x0, 0x5, 0xfa, 0x4b, 0xf6, 0x2,
    0xf7, 0x0, 0x7, 0xf3, 0x6f, 0x0, 0x0, 0xd,
    0x86, 0xf0, 0x0, 0x0, 0xe8, 0x1e, 0xa2, 0x2,
    0xaf, 0x20, 0x19, 0xdf, 0xe9, 0x20,

    /* U+0039 "9" */
    0x0, 0x6d, 0xfd, 0x50, 0x0, 0x5e, 0x51, 0x5f,
    0x40, 0xd, 0x70, 0x0, 0x9b, 0x0, 0xf4, 0x0,
    0x5, 0xf0, 0xf, 0x50, 0x0, 0x4f, 0x10, 0xac,
    0x20, 0x4d, 0xf2, 0x1, 0xaf, 0xfc, 0x5f, 0x20,
    0x0, 0x1, 0x5, 0xf0, 0x0, 0x0, 0x0, 0x8d,
    0x0, 0xa7, 0x0, 0xd, 0x80, 0x6, 0xf4, 0x8,
    0xf1, 0x0, 0x7, 0xef, 0xc3, 0x0,

    /* U+003A ":" */
    0x4f, 0x83, 0xd6, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xd6, 0x4f, 0x80,

    /* U+003B ";" */
    0x4f, 0x83, 0xd6, 0x0, 0x0, 0x0, 0x0, 0x2,
    0xc6, 0x3f, 0x90, 0x46, 0xb, 0x1, 0x20,

    /* U+003C "<" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x79, 0x0, 0x1b,
    0xc2, 0x4, 0xe8, 0x0, 0x4f, 0x70, 0x0, 0x5,
    0xe7, 0x0, 0x0, 0x2c, 0xb1, 0x0, 0x0, 0x8a,
    0x0, 0x0, 0x0,

    /* U+003D "=" */
    0x6f, 0xff, 0xff, 0xfb, 0x2, 0x22, 0x22, 0x21,
    0x0, 0x0, 0x0, 0x0, 0x6f, 0xff, 0xff, 0xfb,
    0x2, 0x22, 0x22, 0x21,

    /* U+003E ">" */
    0x0, 0x0, 0x0, 0x5a, 0x10, 0x0, 0x9, 0xe3,
    0x0, 0x0, 0x5e, 0x70, 0x0, 0x3, 0xf8, 0x0,
    0x4e, 0x80, 0x8, 0xe4, 0x0, 0x5b, 0x10, 0x0,
    0x0, 0x0, 0x0,

    /* U+003F "?" */
    0x2, 0xae, 0xfc, 0x50, 0xd, 0xc3, 0x29, 0xf4,
    0x3f, 0x30, 0x0, 0xe9, 0x3a, 0x0, 0x0, 0xe9,
    0x0, 0x0, 0x7, 0xf2, 0x0, 0x0, 0x6f, 0x40,
    0x0, 0x2, 0xf4, 0x0, 0x0, 0x5, 0xd0, 0x0,
    0x0, 0x5, 0xb0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x6, 0xa0, 0x0, 0x0, 0x9, 0xf0, 0x0,

    /* U+0040 "@" */
    0x0, 0x1, 0x8d, 0xff, 0xb4, 0x0, 0x0, 0x2,
    0xec, 0x52, 0x26, 0xe7, 0x0, 0x1, 0xea, 0x6,
    0xdc, 0x67, 0xe4, 0x0, 0x8e, 0x5, 0xe2, 0x2f,
    0x75, 0xc0, 0xe, 0x70, 0xd6, 0x0, 0xf3, 0xf,
    0x1, 0xf4, 0x2f, 0x10, 0x3f, 0x0, 0xf1, 0x2f,
    0x34, 0xe0, 0x9, 0xc0, 0x4e, 0x1, 0xf4, 0x4f,
    0x14, 0xfa, 0x2d, 0x60, 0xc, 0xa0, 0xbf, 0xd5,
    0xff, 0x83, 0x0, 0x4f, 0x70, 0x10, 0x1, 0x1a,
    0xb0, 0x0, 0x6f, 0xb4, 0x12, 0x6d, 0xa0, 0x0,
    0x0, 0x29, 0xdf, 0xeb, 0x40, 0x0,

    /* U+0041 "A" */
    0x0, 0x0, 0xf, 0xd0, 0x0, 0x0, 0x0, 0x0,
    0x6d, 0xf3, 0x0, 0x0, 0x0, 0x0, 0xc7, 0x9a,
    0x0, 0x0, 0x0, 0x2, 0xf1, 0x3f, 0x10, 0x0,
    0x0, 0x8, 0xb0, 0xd, 0x70, 0x0, 0x0, 0xe,
    0x50, 0x7, 0xd0, 0x0, 0x0, 0x4e, 0x0, 0x1,
    0xf4, 0x0, 0x0, 0xbf, 0xff, 0xff, 0xfa, 0x0,
    0x1, 0xf5, 0x33, 0x33, 0x6f, 0x10, 0x7, 0xd0,
    0x0, 0x0, 0xf, 0x70, 0xd, 0x80, 0x0, 0x0,
    0xa, 0xe0, 0x3f, 0x30, 0x0, 0x0, 0x4, 0xf4,

    /* U+0042 "B" */
    0x6f, 0xff, 0xfe, 0xa2, 0x0, 0x6e, 0x22, 0x35,
    0xcf, 0x10, 0x6d, 0x0, 0x0, 0x1f, 0x50, 0x6d,
    0x0, 0x0, 0xf, 0x50, 0x6d, 0x0, 0x1, 0xad,
    0x0, 0x6f, 0xee, 0xff, 0xd1, 0x0, 0x6d, 0x11,
    0x13, 0xbe, 0x30, 0x6d, 0x0, 0x0, 0xb, 0xc0,
    0x6d, 0x0, 0x0, 0x7, 0xf0, 0x6d, 0x0, 0x0,
    0x9, 0xe0, 0x6e, 0x22, 0x23, 0x9f, 0x70, 0x6f,
    0xff, 0xff, 0xc5, 0x0,

    /* U+0043 "C" */
    0x0, 0x6, 0xcf, 0xfc, 0x50, 0x0, 0xb, 0xf7,
    0x33, 0x9f, 0x70, 0x7, 0xf2, 0x0, 0x0, 0x6f,
    0x30, 0xe8, 0x0, 0x0, 0x0, 0x21, 0x3f, 0x30,
    0x0, 0x0, 0x0, 0x5, 0xf1, 0x0, 0x0, 0x0,
    0x0, 0x5f, 0x0, 0x0, 0x0, 0x0, 0x3, 0xf2,
    0x0, 0x0, 0x0, 0x0, 0xe, 0x90, 0x0, 0x0,
    0x6, 0x40, 0x7f, 0x40, 0x0, 0x6, 0xf2, 0x0,
    0xaf, 0x94, 0x38, 0xf6, 0x0, 0x0, 0x5c, 0xff,
    0xc4, 0x0,

    /* U+0044 "D" */
    0x4f, 0xff, 0xfe, 0xb4, 0x0, 0x4, 0xf2, 0x23,
    0x49, 0xf9, 0x0, 0x4f, 0x0, 0x0, 0x3, 0xf7,
    0x4, 0xf0, 0x0, 0x0, 0x7, 0xf0, 0x4f, 0x0,
    0x0, 0x0, 0x1f, 0x44, 0xf0, 0x0, 0x0, 0x0,
    0xf6, 0x4f, 0x0, 0x0, 0x0, 0xf, 0x64, 0xf0,
    0x0, 0x0, 0x2, 0xf4, 0x4f, 0x0, 0x0, 0x0,
    0x8e, 0x4, 0xf0, 0x0, 0x0, 0x4f, 0x60, 0x4f,
    0x22, 0x24, 0x9f, 0x80, 0x4, 0xff, 0xff, 0xd9,
    0x30, 0x0,

    /* U+0045 "E" */
    0x7f, 0xff, 0xff, 0xff, 0xa7, 0xc2, 0x22, 0x22,
    0x21, 0x7c, 0x0, 0x0, 0x0, 0x7, 0xc0, 0x0,
    0x0, 0x0, 0x7c, 0x0, 0x0, 0x0, 0x7, 0xff,
    0xff, 0xff, 0x0, 0x7c, 0x22, 0x22, 0x20, 0x7,
    0xc0, 0x0, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x0,
    0x7, 0xc0, 0x0, 0x0, 0x0, 0x7c, 0x22, 0x22,
    0x22, 0x27, 0xff, 0xff, 0xff, 0xfe,

    /* U+0046 "F" */
    0x7f, 0xff, 0xff, 0xff, 0xd7, 0xc2, 0x22, 0x22,
    0x22, 0x7c, 0x0, 0x0, 0x0, 0x7, 0xc0, 0x0,
    0x0, 0x0, 0x7c, 0x0, 0x0, 0x0, 0x7, 0xff,
    0xff, 0xff, 0x30, 0x7c, 0x22, 0x22, 0x20, 0x7,
    0xc0, 0x0, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x0,
    0x7, 0xc0, 0x0, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x0, 0x7, 0xc0, 0x0, 0x0, 0x0,

    /* U+0047 "G" */
    0x0, 0x6, 0xcf, 0xfd, 0x70, 0x0, 0x9, 0xf7,
    0x33, 0x7f, 0xb0, 0x5, 0xf4, 0x0, 0x0, 0x3f,
    0x50, 0xcb, 0x0, 0x0, 0x0, 0x0, 0x1f, 0x50,
    0x0, 0x0, 0x0, 0x3, 0xf3, 0x0, 0x0, 0x0,
    0x0, 0x4f, 0x10, 0x0, 0x8, 0xff, 0xa2, 0xf3,
    0x0, 0x0, 0x12, 0x9a, 0xe, 0x90, 0x0, 0x0,
    0xa, 0xa0, 0x8f, 0x40, 0x0, 0x6, 0xfa, 0x0,
    0xbf, 0x83, 0x39, 0xec, 0xa0, 0x0, 0x7c, 0xff,
    0xa2, 0x8a,

    /* U+0048 "H" */
    0x7c, 0x0, 0x0, 0x0, 0x7c, 0x7c, 0x0, 0x0,
    0x0, 0x7c, 0x7c, 0x0, 0x0, 0x0, 0x7c, 0x7c,
    0x0, 0x0, 0x0, 0x7c, 0x7c, 0x0, 0x0, 0x0,
    0x7c, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x7c, 0x22,
    0x22, 0x22, 0x9c, 0x7c, 0x0, 0x0, 0x0, 0x7c,
    0x7c, 0x0, 0x0, 0x0, 0x7c, 0x7c, 0x0, 0x0,
    0x0, 0x7c, 0x7c, 0x0, 0x0, 0x0, 0x7c, 0x7c,
    0x0, 0x0, 0x0, 0x7c,

    /* U+0049 "I" */
    0x1f, 0x21, 0xf2, 0x1f, 0x21, 0xf2, 0x1f, 0x21,
    0xf2, 0x1f, 0x21, 0xf2, 0x1f, 0x21, 0xf2, 0x1f,
    0x21, 0xf2,

    /* U+004A "J" */
    0x0, 0x0, 0xb, 0x80, 0x0, 0x0, 0xb8, 0x0,
    0x0, 0xb, 0x80, 0x0, 0x0, 0xb8, 0x0, 0x0,
    0xb, 0x80, 0x0, 0x0, 0xb8, 0x0, 0x0, 0xb,
    0x80, 0x0, 0x0, 0xb8, 0x0, 0x0, 0xb, 0x84,
    0xd2, 0x0, 0xd6, 0xe, 0xc4, 0x9f, 0x10, 0x2b,
    0xfe, 0x50,

    /* U+004B "K" */
    0x9a, 0x0, 0x0, 0x8, 0xf3, 0x9, 0xa0, 0x0,
    0x9, 0xe3, 0x0, 0x9a, 0x0, 0xa, 0xe2, 0x0,
    0x9, 0xa0, 0xb, 0xd1, 0x0, 0x0, 0x9a, 0xc,
    0xf2, 0x0, 0x0, 0x9, 0xbc, 0xbc, 0x90, 0x0,
    0x0, 0x9f, 0xa0, 0x2f, 0x40, 0x0, 0x9, 0xc0,
    0x0, 0x8e, 0x0, 0x0, 0x9a, 0x0, 0x0, 0xda,
    0x0, 0x9, 0xa0, 0x0, 0x3, 0xf5, 0x0, 0x9a,
    0x0, 0x0, 0x9, 0xe1, 0x9, 0xa0, 0x0, 0x0,
    0xe, 0xa0,

    /* U+004C "L" */
    0xf4, 0x0, 0x0, 0x0, 0xf, 0x40, 0x0, 0x0,
    0x0, 0xf4, 0x0, 0x0, 0x0, 0xf, 0x40, 0x0,
    0x0, 0x0, 0xf4, 0x0, 0x0, 0x0, 0xf, 0x40,
    0x0, 0x0, 0x0, 0xf4, 0x0, 0x0, 0x0, 0xf,
    0x40, 0x0, 0x0, 0x0, 0xf4, 0x0, 0x0, 0x0,
    0xf, 0x40, 0x0, 0x0, 0x0, 0xf6, 0x22, 0x22,
    0x22, 0xf, 0xff, 0xff, 0xff, 0xf3,

    /* U+004D "M" */
    0x7f, 0x40, 0x0, 0x0, 0x9, 0xf2, 0x7f, 0xa0,
    0x0, 0x0, 0xf, 0xf2, 0x7d, 0xf0, 0x0, 0x0,
    0x5d, 0xf2, 0x7a, 0xd6, 0x0, 0x0, 0xb8, 0xf2,
    0x7a, 0x7c, 0x0, 0x1, 0xf2, 0xf2, 0x7a, 0x1f,
    0x20, 0x7, 0xa2, 0xf2, 0x7a, 0xb, 0x70, 0xd,
    0x52, 0xf2, 0x7a, 0x5, 0xd0, 0x3e, 0x2, 0xf2,
    0x7a, 0x0, 0xe3, 0x99, 0x2, 0xf2, 0x7a, 0x0,
    0x99, 0xe4, 0x2, 0xf2, 0x7a, 0x0, 0x3f, 0xe0,
    0x2, 0xf2, 0x7a, 0x0, 0xd, 0x80, 0x2, 0xf2,

    /* U+004E "N" */
    0x7f, 0x70, 0x0, 0x0, 0x9b, 0x7f, 0xf1, 0x0,
    0x0, 0x9b, 0x7c, 0xbb, 0x0, 0x0, 0x9b, 0x7c,
    0x2f, 0x50, 0x0, 0x9b, 0x7c, 0x7, 0xe1, 0x0,
    0x9b, 0x7c, 0x0, 0xd9, 0x0, 0x9b, 0x7c, 0x0,
    0x3f, 0x40, 0x9b, 0x7c, 0x0, 0x9, 0xd0, 0x9b,
    0x7c, 0x0, 0x1, 0xe8, 0x9b, 0x7c, 0x0, 0x0,
    0x5f, 0xbb, 0x7c, 0x0, 0x0, 0xb, 0xfb, 0x7c,
    0x0, 0x0, 0x2, 0xfb,

    /* U+004F "O" */
    0x0, 0x5, 0xcf, 0xfc, 0x50, 0x0, 0x0, 0xad,
    0x51, 0x15, 0xe9, 0x0, 0x7, 0xe1, 0x0, 0x0,
    0x1e, 0x60, 0xf, 0x70, 0x0, 0x0, 0x7, 0xe0,
    0x4f, 0x10, 0x0, 0x0, 0x2, 0xf4, 0x6f, 0x0,
    0x0, 0x0, 0x0, 0xf6, 0x6f, 0x0, 0x0, 0x0,
    0x0, 0xf6, 0x4f, 0x10, 0x0, 0x0, 0x1, 0xf4,
    0xf, 0x60, 0x0, 0x0, 0x7, 0xf0, 0x8, 0xe1,
    0x0, 0x0, 0x1e, 0x70, 0x0, 0xbd, 0x51, 0x15,
    0xea, 0x0, 0x0, 0x6, 0xcf, 0xfc, 0x60, 0x0,

    /* U+0050 "P" */
    0x8f, 0xff, 0xfd, 0x81, 0x8, 0xc2, 0x22, 0x4b,
    0xd1, 0x8b, 0x0, 0x0, 0xf, 0x78, 0xb0, 0x0,
    0x0, 0xc9, 0x8b, 0x0, 0x0, 0xe, 0x88, 0xb0,
    0x0, 0x29, 0xf2, 0x8f, 0xff, 0xff, 0xd3, 0x8,
    0xc3, 0x33, 0x10, 0x0, 0x8b, 0x0, 0x0, 0x0,
    0x8, 0xb0, 0x0, 0x0, 0x0, 0x8b, 0x0, 0x0,
    0x0, 0x8, 0xb0, 0x0, 0x0, 0x0,

    /* U+0051 "Q" */
    0x0, 0x5, 0xcf, 0xfc, 0x50, 0x0, 0x0, 0xae,
    0x61, 0x16, 0xe9, 0x0, 0x7, 0xe1, 0x0, 0x0,
    0x2f, 0x60, 0xe, 0x70, 0x0, 0x0, 0x8, 0xe0,
    0x4f, 0x10, 0x0, 0x0, 0x2, 0xf4, 0x6f, 0x0,
    0x0, 0x0, 0x0, 0xf6, 0x6e, 0x0, 0x0, 0x0,
    0x0, 0xf6, 0x4f, 0x10, 0x0, 0x0, 0x1, 0xf4,
    0xf, 0x62, 0xce, 0x80, 0x7, 0xf0, 0x8, 0xed,
    0x40, 0x9b, 0x2f, 0x60, 0x0, 0xbf, 0x62, 0x1c,
    0xf9, 0x0, 0x0, 0x6, 0xcf, 0xfc, 0xd6, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0x71, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xc6,

    /* U+0052 "R" */
    0x9f, 0xff, 0xfd, 0x70, 0x9, 0xb2, 0x22, 0x5d,
    0xc0, 0x9a, 0x0, 0x0, 0x2f, 0x49, 0xa0, 0x0,
    0x0, 0xf6, 0x9a, 0x0, 0x0, 0x1f, 0x49, 0xa0,
    0x0, 0x2b, 0xd0, 0x9f, 0xff, 0xff, 0xb1, 0x9,
    0xb3, 0x38, 0xd0, 0x0, 0x9a, 0x0, 0xd, 0x80,
    0x9, 0xa0, 0x0, 0x4f, 0x30, 0x9a, 0x0, 0x0,
    0xac, 0x9, 0xa0, 0x0, 0x1, 0xf7,

    /* U+0053 "S" */
    0x0, 0x6c, 0xfe, 0x90, 0x0, 0x8f, 0x83, 0x5d,
    0xb0, 0xe, 0xa0, 0x0, 0x2f, 0x50, 0xcb, 0x0,
    0x0, 0x0, 0x3, 0xfa, 0x10, 0x0, 0x0, 0x2,
    0xbf, 0x81, 0x0, 0x0, 0x0, 0x3b, 0xf7, 0x0,
    0x0, 0x0, 0x5, 0xf8, 0x26, 0x10, 0x0, 0x8,
    0xf1, 0xf8, 0x0, 0x0, 0xbe, 0x6, 0xf8, 0x44,
    0xaf, 0x60, 0x4, 0xce, 0xeb, 0x40,

    /* U+0054 "T" */
    0x8f, 0xff, 0xff, 0xff, 0xff, 0x71, 0x22, 0x24,
    0xf4, 0x22, 0x21, 0x0, 0x0, 0x1f, 0x20, 0x0,
    0x0, 0x0, 0x1, 0xf2, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0x20, 0x0, 0x0, 0x0, 0x1, 0xf2, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0x20, 0x0, 0x0, 0x0,
    0x1, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x1f, 0x20,
    0x0, 0x0, 0x0, 0x1, 0xf2, 0x0, 0x0, 0x0,
    0x0, 0x1f, 0x20, 0x0, 0x0, 0x0, 0x1, 0xf2,
    0x0, 0x0,

    /* U+0055 "U" */
    0x7c, 0x0, 0x0, 0x0, 0x2f, 0x17, 0xc0, 0x0,
    0x0, 0x2, 0xf1, 0x7c, 0x0, 0x0, 0x0, 0x2f,
    0x17, 0xc0, 0x0, 0x0, 0x2, 0xf1, 0x7c, 0x0,
    0x0, 0x0, 0x2f, 0x17, 0xc0, 0x0, 0x0, 0x2,
    0xf1, 0x7c, 0x0, 0x0, 0x0, 0x2f, 0x6, 0xd0,
    0x0, 0x0, 0x3, 0xf0, 0x4f, 0x0, 0x0, 0x0,
    0x6e, 0x0, 0xf6, 0x0, 0x0, 0xd, 0x90, 0x6,
    0xf7, 0x21, 0x3b, 0xe1, 0x0, 0x4, 0xbf, 0xfe,
    0x91, 0x0,

    /* U+0056 "V" */
    0x4f, 0x10, 0x0, 0x0, 0xe, 0x70, 0xe7, 0x0,
    0x0, 0x4, 0xf1, 0x8, 0xc0, 0x0, 0x0, 0x9c,
    0x0, 0x2f, 0x20, 0x0, 0xf, 0x60, 0x0, 0xc8,
    0x0, 0x5, 0xf1, 0x0, 0x6, 0xd0, 0x0, 0xaa,
    0x0, 0x0, 0x1f, 0x30, 0xf, 0x50, 0x0, 0x0,
    0xb8, 0x5, 0xe0, 0x0, 0x0, 0x5, 0xe0, 0xb9,
    0x0, 0x0, 0x0, 0xe, 0x5f, 0x30, 0x0, 0x0,
    0x0, 0x9e, 0xe0, 0x0, 0x0, 0x0, 0x3, 0xf8,
    0x0, 0x0,

    /* U+0057 "W" */
    0x6e, 0x0, 0x0, 0xad, 0x0, 0x0, 0xb8, 0x2f,
    0x10, 0x0, 0xef, 0x10, 0x0, 0xf4, 0xe, 0x50,
    0x2, 0xfd, 0x50, 0x3, 0xf0, 0xa, 0x90, 0x6,
    0xc9, 0x80, 0x7, 0xc0, 0x7, 0xc0, 0xb, 0x85,
    0xc0, 0xb, 0x80, 0x3, 0xf0, 0xf, 0x31, 0xf0,
    0xe, 0x40, 0x0, 0xf3, 0x3f, 0x0, 0xd4, 0x2f,
    0x10, 0x0, 0xb7, 0x7b, 0x0, 0xa8, 0x6c, 0x0,
    0x0, 0x8a, 0xb7, 0x0, 0x6c, 0xa9, 0x0, 0x0,
    0x4e, 0xf3, 0x0, 0x2f, 0xe5, 0x0, 0x0, 0xf,
    0xf0, 0x0, 0xe, 0xf1, 0x0, 0x0, 0xc, 0xb0,
    0x0, 0xa, 0xd0, 0x0,

    /* U+0058 "X" */
    0x6, 0xf3, 0x0, 0x0, 0xbd, 0x0, 0xb, 0xd0,
    0x0, 0x6f, 0x30, 0x0, 0x1f, 0x80, 0x2f, 0x80,
    0x0, 0x0, 0x6f, 0x3b, 0xd0, 0x0, 0x0, 0x0,
    0xcf, 0xf3, 0x0, 0x0, 0x0, 0x4, 0xfa, 0x0,
    0x0, 0x0, 0x0, 0xbf, 0xf2, 0x0, 0x0, 0x0,
    0x6f, 0x3c, 0xc0, 0x0, 0x0, 0x1f, 0x80, 0x2f,
    0x70, 0x0, 0xb, 0xd0, 0x0, 0x8f, 0x20, 0x5,
    0xf3, 0x0, 0x0, 0xdc, 0x1, 0xe9, 0x0, 0x0,
    0x3, 0xf6,

    /* U+0059 "Y" */
    0x1f, 0x60, 0x0, 0x0, 0xd, 0x90, 0x6f, 0x10,
    0x0, 0x8, 0xe0, 0x0, 0xca, 0x0, 0x2, 0xf4,
    0x0, 0x2, 0xf4, 0x0, 0xc9, 0x0, 0x0, 0x7,
    0xd0, 0x6e, 0x10, 0x0, 0x0, 0xc, 0x9f, 0x50,
    0x0, 0x0, 0x0, 0x3f, 0xa0, 0x0, 0x0, 0x0,
    0x0, 0xe5, 0x0, 0x0, 0x0, 0x0, 0xe, 0x50,
    0x0, 0x0, 0x0, 0x0, 0xe5, 0x0, 0x0, 0x0,
    0x0, 0xe, 0x50, 0x0, 0x0, 0x0, 0x0, 0xe5,
    0x0, 0x0,

    /* U+005A "Z" */
    0x2f, 0xff, 0xff, 0xff, 0xa0, 0x2, 0x22, 0x22,
    0x5f, 0x50, 0x0, 0x0, 0x0, 0xca, 0x0, 0x0,
    0x0, 0x7, 0xe1, 0x0, 0x0, 0x0, 0x3f, 0x40,
    0x0, 0x0, 0x0, 0xda, 0x0, 0x0, 0x0, 0x8,
    0xe1, 0x0, 0x0, 0x0, 0x3f, 0x40, 0x0, 0x0,
    0x0, 0xd9, 0x0, 0x0, 0x0, 0x9, 0xe0, 0x0,
    0x0, 0x0, 0x4f, 0x72, 0x22, 0x22, 0x20, 0x8f,
    0xff, 0xff, 0xff, 0xf1,

    /* U+005B "[" */
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xf3, 0x3f, 0x33,
    0x30, 0x3f, 0x0, 0x0, 0x3f, 0x0, 0x0, 0x3f,
    0x0, 0x0, 0x3f, 0x0, 0x0, 0x3f, 0x0, 0x0,
    0x3f, 0x0, 0x0, 0x3f, 0x0, 0x0, 0x3f, 0x0,
    0x0, 0x3f, 0x0, 0x0, 0x3f, 0x0, 0x0, 0x3f,
    0x0, 0x0, 0x3f, 0x0, 0x0, 0x3f, 0x0, 0x0,
    0x3f, 0x0, 0x0, 0x3f, 0xff, 0xf3, 0x3, 0x33,
    0x30,

    /* U+005C "\\" */
    0x1, 0x0, 0x8, 0x70, 0x0, 0x5b, 0x0, 0x1,
    0xe0, 0x0, 0xe, 0x10, 0x0, 0xb5, 0x0, 0x7,
    0x80, 0x0, 0x4b, 0x0, 0x1, 0xf0, 0x0, 0xd,
    0x20, 0x0, 0xa5, 0x0, 0x7, 0x90, 0x0, 0x3c,
    0x0, 0x0, 0xf0, 0x0, 0xd, 0x30, 0x0, 0xa6,
    0x0, 0x5, 0x60,

    /* U+005D "]" */
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xf3, 0x3, 0x33,
    0xf3, 0x0, 0x0, 0xf3, 0x0, 0x0, 0xf3, 0x0,
    0x0, 0xf3, 0x0, 0x0, 0xf3, 0x0, 0x0, 0xf3,
    0x0, 0x0, 0xf3, 0x0, 0x0, 0xf3, 0x0, 0x0,
    0xf3, 0x0, 0x0, 0xf3, 0x0, 0x0, 0xf3, 0x0,
    0x0, 0xf3, 0x0, 0x0, 0xf3, 0x0, 0x0, 0xf3,
    0x0, 0x0, 0xf3, 0x3f, 0xff, 0xf3, 0x3, 0x33,
    0x30,

    /* U+005E "^" */
    0x0, 0xae, 0x80, 0x0, 0x2e, 0x2e, 0x10, 0xa,
    0x60, 0x88, 0x2, 0xc0, 0x0, 0xd1,

    /* U+005F "_" */
    0xff, 0xff, 0xff, 0xff, 0xf2, 0x22, 0x22, 0x22,
    0x22,

    /* U+0060 "`" */
    0x3, 0x0, 0x3f, 0x20, 0x8, 0xb0, 0x0, 0xa4,
    0x0, 0x0,

    /* U+0061 "a" */
    0x4, 0xce, 0xea, 0x0, 0x1, 0xf7, 0x0, 0xb9,
    0x0, 0x26, 0x0, 0x3, 0xd0, 0x0, 0x0, 0x37,
    0xaf, 0x0, 0x6, 0xe9, 0x53, 0xf0, 0x5, 0xf3,
    0x0, 0xf, 0x10, 0xaa, 0x0, 0x7, 0xf1, 0x8,
    0xe3, 0x3b, 0xbf, 0x82, 0xa, 0xfd, 0x60, 0x9f,
    0x90,

    /* U+0062 "b" */
    0xb7, 0x0, 0x0, 0x0, 0xb, 0x70, 0x0, 0x0,
    0x0, 0xb7, 0x0, 0x0, 0x0, 0xb, 0x75, 0xcf,
    0xd6, 0x0, 0xbd, 0x81, 0x4, 0xf5, 0xb, 0x90,
    0x0, 0x7, 0xe0, 0xb7, 0x0, 0x0, 0x2f, 0x1b,
    0x70, 0x0, 0x1, 0xf2, 0xb7, 0x0, 0x0, 0x3f,
    0xb, 0xc0, 0x0, 0x9, 0xb0, 0xbb, 0xb3, 0x17,
    0xf3, 0xb, 0x72, 0xcf, 0xd4, 0x0,

    /* U+0063 "c" */
    0x0, 0x7d, 0xfd, 0x50, 0x9, 0xc2, 0x4, 0xf4,
    0x2f, 0x20, 0x0, 0x33, 0x6e, 0x0, 0x0, 0x0,
    0x6e, 0x0, 0x0, 0x0, 0x4f, 0x0, 0x0, 0x0,
    0x1f, 0x40, 0x0, 0x66, 0x8, 0xe3, 0x5, 0xf4,
    0x0, 0x7d, 0xfd, 0x50,

    /* U+0064 "d" */
    0x0, 0x0, 0x0, 0xe, 0x30, 0x0, 0x0, 0x0,
    0xe3, 0x0, 0x0, 0x0, 0xe, 0x30, 0x1a, 0xef,
    0xb2, 0xe3, 0xd, 0xc3, 0x15, 0xcf, 0x36, 0xf0,
    0x0, 0x1, 0xf3, 0xab, 0x0, 0x0, 0xe, 0x3a,
    0xa0, 0x0, 0x0, 0xe3, 0x8c, 0x0, 0x0, 0xe,
    0x34, 0xf1, 0x0, 0x6, 0xf3, 0xc, 0xc3, 0x28,
    0xae, 0x30, 0x1a, 0xfe, 0x70, 0xe3,

    /* U+0065 "e" */
    0x0, 0x8e, 0xfd, 0x50, 0x0, 0xab, 0x20, 0x2d,
    0x50, 0x2f, 0x10, 0x0, 0x5d, 0x5, 0xfd, 0xdd,
    0xdd, 0xe0, 0x6e, 0x0, 0x0, 0x0, 0x5, 0xf0,
    0x0, 0x0, 0x0, 0x1f, 0x60, 0x0, 0x57, 0x0,
    0x8f, 0x40, 0x5f, 0x40, 0x0, 0x7d, 0xfd, 0x40,
    0x0,

    /* U+0066 "f" */
    0x0, 0x2c, 0xfc, 0x0, 0xbc, 0x42, 0x0, 0xd5,
    0x0, 0xcf, 0xff, 0xfc, 0x0, 0xd5, 0x0, 0x0,
    0xd5, 0x0, 0x0, 0xd5, 0x0, 0x0, 0xd5, 0x0,
    0x0, 0xd5, 0x0, 0x0, 0xd5, 0x0, 0x0, 0xd5,
    0x0, 0x0, 0xd5, 0x0,

    /* U+0067 "g" */
    0x0, 0x6c, 0xdd, 0x83, 0x91, 0x6, 0xd2, 0x0,
    0x9f, 0x60, 0xc, 0x70, 0x0, 0xf, 0x20, 0xc,
    0x70, 0x0, 0xf, 0x30, 0x6, 0xf5, 0x0, 0xac,
    0x0, 0x4, 0xea, 0xdc, 0x70, 0x0, 0xe, 0x92,
    0x0, 0x0, 0x0, 0xb, 0xcc, 0xee, 0xb7, 0x10,
    0x5c, 0x0, 0x0, 0x29, 0xe0, 0x4f, 0x60, 0x0,
    0x18, 0xe0, 0x4, 0xad, 0xde, 0xd9, 0x20,

    /* U+0068 "h" */
    0xb8, 0x0, 0x0, 0x0, 0xb8, 0x0, 0x0, 0x0,
    0xb8, 0x0, 0x0, 0x0, 0xb8, 0x2b, 0xfd, 0x50,
    0xbb, 0xd5, 0x14, 0xf2, 0xbd, 0x10, 0x0, 0xc6,
    0xb8, 0x0, 0x0, 0xa8, 0xb8, 0x0, 0x0, 0xa8,
    0xb8, 0x0, 0x0, 0xa8, 0xb8, 0x0, 0x0, 0xa8,
    0xb8, 0x0, 0x0, 0xa8, 0xb8, 0x0, 0x0, 0xa8,

    /* U+0069 "i" */
    0x5f, 0x33, 0xc2, 0x0, 0x2, 0xf0, 0x2f, 0x2,
    0xf0, 0x2f, 0x2, 0xf0, 0x2f, 0x2, 0xf0, 0x2f,
    0x2, 0xf0,

    /* U+006A "j" */
    0x0, 0x8f, 0x0, 0x6b, 0x0, 0x0, 0x0, 0x5c,
    0x0, 0x5c, 0x0, 0x5c, 0x0, 0x5c, 0x0, 0x5c,
    0x0, 0x5c, 0x0, 0x5c, 0x0, 0x5c, 0x0, 0x7a,
    0x27, 0xe6, 0xad, 0x70,

    /* U+006B "k" */
    0xa8, 0x0, 0x0, 0x0, 0xa8, 0x0, 0x0, 0x0,
    0xa8, 0x0, 0x0, 0x0, 0xa8, 0x0, 0xa, 0xe2,
    0xa8, 0x0, 0xad, 0x10, 0xa8, 0xb, 0xc1, 0x0,
    0xa9, 0xcf, 0x30, 0x0, 0xaf, 0xba, 0xc0, 0x0,
    0xac, 0x1, 0xe7, 0x0, 0xa8, 0x0, 0x5f, 0x20,
    0xa8, 0x0, 0xb, 0xc0, 0xa8, 0x0, 0x1, 0xf6,

    /* U+006C "l" */
    0x4e, 0x4e, 0x4e, 0x4e, 0x4e, 0x4e, 0x4e, 0x4e,
    0x4e, 0x4e, 0x4e, 0x4e,

    /* U+006D "m" */
    0x8a, 0x1b, 0xfc, 0x1, 0xaf, 0xd5, 0x8, 0xcc,
    0x41, 0xc9, 0xd6, 0x16, 0xf1, 0x8f, 0x20, 0x6,
    0xf5, 0x0, 0xd, 0x58, 0xa0, 0x0, 0x4d, 0x0,
    0x0, 0xc6, 0x8a, 0x0, 0x4, 0xd0, 0x0, 0xc,
    0x68, 0xa0, 0x0, 0x4d, 0x0, 0x0, 0xc6, 0x8a,
    0x0, 0x4, 0xd0, 0x0, 0xc, 0x68, 0xa0, 0x0,
    0x4d, 0x0, 0x0, 0xc6, 0x8a, 0x0, 0x4, 0xd0,
    0x0, 0xc, 0x60,

    /* U+006E "n" */
    0x8a, 0x18, 0xde, 0x80, 0x8c, 0xd6, 0x1, 0xe5,
    0x8f, 0x30, 0x0, 0x99, 0x8a, 0x0, 0x0, 0x7a,
    0x8a, 0x0, 0x0, 0x7b, 0x8a, 0x0, 0x0, 0x7b,
    0x8a, 0x0, 0x0, 0x7b, 0x8a, 0x0, 0x0, 0x7b,
    0x8a, 0x0, 0x0, 0x7b,

    /* U+006F "o" */
    0x0, 0x9e, 0xea, 0x10, 0xb, 0xa0, 0x8, 0xd0,
    0x4f, 0x0, 0x0, 0xe6, 0x8c, 0x0, 0x0, 0x9a,
    0x9b, 0x0, 0x0, 0x8c, 0x8c, 0x0, 0x0, 0x9a,
    0x3f, 0x10, 0x0, 0xe6, 0xb, 0xa0, 0x8, 0xd0,
    0x0, 0x9e, 0xeb, 0x10,

    /* U+0070 "p" */
    0xa8, 0x6d, 0xfc, 0x30, 0xae, 0x92, 0x2a, 0xe1,
    0xaa, 0x0, 0x0, 0xe7, 0xa8, 0x0, 0x0, 0x9b,
    0xa8, 0x0, 0x0, 0x8c, 0xa8, 0x0, 0x0, 0xaa,
    0xaa, 0x0, 0x0, 0xf5, 0xae, 0x81, 0x1a, 0xd0,
    0xa8, 0x6d, 0xfb, 0x20, 0xa8, 0x0, 0x0, 0x0,
    0xa8, 0x0, 0x0, 0x0,

    /* U+0071 "q" */
    0x2, 0xcf, 0xd6, 0x5d, 0xe, 0xb3, 0x28, 0xed,
    0x6e, 0x0, 0x0, 0x8d, 0x9b, 0x0, 0x0, 0x5d,
    0xaa, 0x0, 0x0, 0x5d, 0x8c, 0x0, 0x0, 0x5d,
    0x4f, 0x10, 0x0, 0x9d, 0xc, 0xb1, 0x7, 0xdd,
    0x1, 0xaf, 0xe6, 0x5d, 0x0, 0x0, 0x0, 0x5d,
    0x0, 0x0, 0x0, 0x5d,

    /* U+0072 "r" */
    0xa9, 0x7, 0xd9, 0xa9, 0xbb, 0x63, 0xaf, 0x70,
    0x0, 0xab, 0x0, 0x0, 0xa9, 0x0, 0x0, 0xa9,
    0x0, 0x0, 0xa9, 0x0, 0x0, 0xa9, 0x0, 0x0,
    0xa9, 0x0, 0x0,

    /* U+0073 "s" */
    0x3, 0xcf, 0xd5, 0x0, 0xe7, 0x5, 0xf3, 0x1f,
    0x30, 0x1, 0x0, 0x9e, 0x60, 0x0, 0x0, 0x5d,
    0xd4, 0x0, 0x0, 0x7, 0xf6, 0x39, 0x0, 0x8,
    0xb1, 0xe9, 0x12, 0xd8, 0x3, 0xbf, 0xe9, 0x0,

    /* U+0074 "t" */
    0x0, 0x71, 0x0, 0x0, 0xf, 0x30, 0x0, 0x0,
    0xf3, 0x0, 0x8, 0xff, 0xff, 0xf0, 0x0, 0xf4,
    0x0, 0x0, 0xf, 0x30, 0x0, 0x0, 0xf3, 0x0,
    0x0, 0xf, 0x30, 0x0, 0x0, 0xf3, 0x0, 0x0,
    0xe, 0x40, 0x0, 0x0, 0xcb, 0x42, 0x0, 0x4,
    0xdf, 0xa0,

    /* U+0075 "u" */
    0x8a, 0x0, 0x0, 0x7b, 0x8a, 0x0, 0x0, 0x7b,
    0x8a, 0x0, 0x0, 0x7b, 0x8a, 0x0, 0x0, 0x7b,
    0x8a, 0x0, 0x0, 0x7b, 0x8a, 0x0, 0x0, 0x7b,
    0x6c, 0x0, 0x0, 0xdb, 0x1f, 0x50, 0x2c, 0xcb,
    0x4, 0xdf, 0xc3, 0x7b,

    /* U+0076 "v" */
    0x5e, 0x0, 0x0, 0xc, 0x80, 0xf5, 0x0, 0x2,
    0xf2, 0x9, 0xa0, 0x0, 0x8c, 0x0, 0x3f, 0x10,
    0xe, 0x50, 0x0, 0xd6, 0x4, 0xf0, 0x0, 0x6,
    0xc0, 0x99, 0x0, 0x0, 0x1f, 0x3f, 0x30, 0x0,
    0x0, 0xad, 0xd0, 0x0, 0x0, 0x4, 0xf7, 0x0,
    0x0,

    /* U+0077 "w" */
    0x6d, 0x0, 0x1, 0xf2, 0x0, 0xb, 0x91, 0xf2,
    0x0, 0x6f, 0x70, 0x0, 0xf3, 0xc, 0x60, 0xb,
    0x8b, 0x0, 0x5e, 0x0, 0x8a, 0x0, 0xf1, 0xe0,
    0xa, 0x90, 0x3, 0xe0, 0x5b, 0xa, 0x40, 0xf3,
    0x0, 0xe, 0x3a, 0x60, 0x59, 0x4e, 0x0, 0x0,
    0x98, 0xf1, 0x1, 0xd9, 0x90, 0x0, 0x5, 0xfb,
    0x0, 0xc, 0xf3, 0x0, 0x0, 0xf, 0x60, 0x0,
    0x8e, 0x0, 0x0,

    /* U+0078 "x" */
    0xc, 0xa0, 0x0, 0x3f, 0x40, 0x1e, 0x60, 0xd,
    0x70, 0x0, 0x4f, 0x2a, 0xb0, 0x0, 0x0, 0x8e,
    0xe1, 0x0, 0x0, 0x3, 0xfa, 0x0, 0x0, 0x0,
    0xda, 0xf5, 0x0, 0x0, 0x9d, 0x6, 0xe1, 0x0,
    0x5f, 0x20, 0xa, 0xc0, 0x1e, 0x60, 0x0, 0xd,
    0x80,

    /* U+0079 "y" */
    0x4f, 0x10, 0x0, 0x2f, 0x40, 0xd8, 0x0, 0x8,
    0xd0, 0x6, 0xe0, 0x0, 0xe7, 0x0, 0xf, 0x50,
    0x4f, 0x10, 0x0, 0x9b, 0xa, 0xb0, 0x0, 0x2,
    0xf3, 0xf5, 0x0, 0x0, 0xb, 0xde, 0x0, 0x0,
    0x0, 0x4f, 0x80, 0x0, 0x0, 0x6, 0xf1, 0x0,
    0x1, 0x37, 0xf7, 0x0, 0x0, 0x8f, 0xd6, 0x0,
    0x0, 0x0,

    /* U+007A "z" */
    0x8f, 0xff, 0xff, 0xf1, 0x0, 0x0, 0x1d, 0xc0,
    0x0, 0x0, 0x9f, 0x20, 0x0, 0x5, 0xf5, 0x0,
    0x0, 0x1e, 0x90, 0x0, 0x0, 0xcd, 0x0, 0x0,
    0x8, 0xf2, 0x0, 0x0, 0x3f, 0x60, 0x0, 0x0,
    0x8f, 0xff, 0xff, 0xf1,

    /* U+007B "{" */
    0x0, 0x0, 0x0, 0x3, 0xdd, 0x0, 0xdb, 0x30,
    0xf, 0x20, 0x0, 0xf2, 0x0, 0xf, 0x20, 0x0,
    0xf2, 0x0, 0xf, 0x10, 0x6, 0xd0, 0xa, 0xf5,
    0x0, 0x29, 0xc0, 0x0, 0x1f, 0x0, 0x0, 0xf2,
    0x0, 0xf, 0x20, 0x0, 0xf2, 0x0, 0xf, 0x20,
    0x0, 0xe8, 0x10, 0x5, 0xfd, 0x0, 0x0, 0x20,

    /* U+007C "|" */
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f,

    /* U+007D "}" */
    0x0, 0x0, 0xa, 0xe6, 0x0, 0x29, 0xf1, 0x0,
    0xf, 0x30, 0x0, 0xf3, 0x0, 0xf, 0x30, 0x0,
    0xf3, 0x0, 0xe, 0x40, 0x0, 0xa9, 0x10, 0x2,
    0xfd, 0x0, 0x9b, 0x30, 0xd, 0x40, 0x0, 0xf3,
    0x0, 0xf, 0x30, 0x0, 0xf3, 0x0, 0xf, 0x30,
    0x6, 0xf1, 0xa, 0xf8, 0x0, 0x11, 0x0, 0x0,

    /* U+007E "~" */
    0x0, 0x0, 0x0, 0x3e, 0xc4, 0x57, 0x85, 0x4e,
    0xf4, 0x0, 0x0, 0x10,

    /* U+2103 "℃" */
    0x1a, 0xa6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x82, 0xa, 0x0, 0x7, 0xcf, 0xfd, 0x81, 0x0,
    0x82, 0xa, 0x1, 0xce, 0x62, 0x25, 0xcd, 0x10,
    0x1a, 0xa6, 0xb, 0xd1, 0x0, 0x0, 0xd, 0xb0,
    0x0, 0x0, 0x4f, 0x30, 0x0, 0x0, 0x2, 0x50,
    0x0, 0x0, 0x9d, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xc9, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xd9, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xca, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x9d, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0x40, 0x0, 0x0, 0x5, 0xb0,
    0x0, 0x0, 0xa, 0xe2, 0x0, 0x0, 0x1d, 0xa0,
    0x0, 0x0, 0x0, 0xbe, 0x73, 0x25, 0xdd, 0x10,
    0x0, 0x0, 0x0, 0x5, 0xce, 0xfd, 0x81, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 96, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 96, .box_w = 2, .box_h = 12, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 12, .adv_w = 71, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 20, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 74, .adv_w = 151, .box_w = 9, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 142, .adv_w = 190, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 226, .adv_w = 191, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 298, .adv_w = 40, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 302, .adv_w = 95, .box_w = 6, .box_h = 18, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 356, .adv_w = 96, .box_w = 6, .box_h = 18, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 410, .adv_w = 129, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 438, .adv_w = 132, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 474, .adv_w = 52, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 482, .adv_w = 96, .box_w = 6, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 488, .adv_w = 52, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 491, .adv_w = 80, .box_w = 5, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 534, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 588, .adv_w = 146, .box_w = 4, .box_h = 12, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 612, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 666, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 720, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 774, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 828, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 882, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 936, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 990, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1044, .adv_w = 52, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1055, .adv_w = 52, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1070, .adv_w = 132, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1097, .adv_w = 132, .box_w = 8, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1117, .adv_w = 132, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1144, .adv_w = 131, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1192, .adv_w = 207, .box_w = 13, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1270, .adv_w = 193, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1342, .adv_w = 154, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1402, .adv_w = 181, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1468, .adv_w = 179, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1534, .adv_w = 151, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1588, .adv_w = 150, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1642, .adv_w = 182, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1708, .adv_w = 165, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1768, .adv_w = 81, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1786, .adv_w = 113, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1828, .adv_w = 167, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1894, .adv_w = 164, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1948, .adv_w = 187, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2020, .adv_w = 164, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2080, .adv_w = 192, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2152, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2206, .adv_w = 192, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2290, .adv_w = 147, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2344, .adv_w = 154, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2398, .adv_w = 175, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2464, .adv_w = 170, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2530, .adv_w = 179, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2596, .adv_w = 227, .box_w = 14, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2680, .adv_w = 182, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2746, .adv_w = 185, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2812, .adv_w = 153, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2872, .adv_w = 96, .box_w = 6, .box_h = 19, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 2929, .adv_w = 80, .box_w = 5, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2972, .adv_w = 96, .box_w = 6, .box_h = 19, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 3029, .adv_w = 110, .box_w = 7, .box_h = 4, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 3043, .adv_w = 144, .box_w = 9, .box_h = 2, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 3052, .adv_w = 96, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 3062, .adv_w = 142, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3103, .adv_w = 137, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3157, .adv_w = 134, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3193, .adv_w = 137, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3247, .adv_w = 139, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3288, .adv_w = 96, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3324, .adv_w = 154, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 3379, .adv_w = 125, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3427, .adv_w = 78, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 3445, .adv_w = 69, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 3473, .adv_w = 130, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3521, .adv_w = 74, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 3533, .adv_w = 206, .box_w = 13, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3592, .adv_w = 130, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3628, .adv_w = 130, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3664, .adv_w = 131, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 3708, .adv_w = 130, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 3752, .adv_w = 96, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3779, .adv_w = 117, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3811, .adv_w = 103, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3853, .adv_w = 130, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3889, .adv_w = 146, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3930, .adv_w = 211, .box_w = 13, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3989, .adv_w = 151, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 4030, .adv_w = 143, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 4080, .adv_w = 121, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 4116, .adv_w = 83, .box_w = 5, .box_h = 19, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 4164, .adv_w = 46, .box_w = 2, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 4176, .adv_w = 83, .box_w = 5, .box_h = 19, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 4224, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 8},
    {.bitmap_index = 4236, .adv_w = 288, .box_w = 16, .box_h = 14, .ofs_x = 1, .ofs_y = -1}
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
    },
    {
        .range_start = 8451, .range_length = 1, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t lv_font_Common_18 = {
#else
lv_font_t lv_font_Common_18 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 20,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if LV_FONT_COMMON_18*/
