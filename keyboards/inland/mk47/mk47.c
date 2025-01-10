/* Copyright (C) 2023 jonylee@hfd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"
#ifdef RGB_MATRIX_ENABLE
const snled27351_led_t PROGMEM g_snled27351_leds[SNLED27351_LED_COUNT] = {
/* Refer to SNLED27351 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, CB4_CA1,   CB5_CA1,   CB6_CA1},
    {0, CB4_CA2,   CB5_CA2,   CB6_CA2},
    {0, CB4_CA3,   CB5_CA3,   CB6_CA3},
    {0, CB4_CA4,   CB5_CA4,   CB6_CA4},
    {0, CB4_CA5,   CB5_CA5,   CB6_CA5},
    {0, CB4_CA6,   CB5_CA6,   CB6_CA6},
    {0, CB4_CA7,   CB5_CA7,   CB6_CA7},
    {0, CB4_CA8,   CB5_CA8,   CB6_CA8},
    {0, CB4_CA9,   CB5_CA9,   CB6_CA9},
    {0, CB4_CA10,  CB5_CA10,  CB6_CA10},
    {0, CB4_CA11,  CB5_CA11,  CB6_CA11},
    {0, CB4_CA12,  CB5_CA12,  CB6_CA12},

    {0, CB7_CA1,   CB8_CA1,   CB9_CA1},
    {0, CB7_CA2,   CB8_CA2,   CB9_CA2},
    {0, CB7_CA3,   CB8_CA3,   CB9_CA3},
    {0, CB7_CA4,   CB8_CA4,   CB9_CA4},
    {0, CB7_CA5,   CB8_CA5,   CB9_CA5},
    {0, CB7_CA6,   CB8_CA6,   CB9_CA6},
    {0, CB7_CA7,   CB8_CA7,   CB9_CA7},
    {0, CB7_CA8,   CB8_CA8,   CB9_CA8},
    {0, CB7_CA9,   CB8_CA9,   CB9_CA9},
    {0, CB7_CA10,  CB8_CA10,  CB9_CA10},
    {0, CB7_CA11,  CB8_CA11,  CB9_CA11},
    {0, CB7_CA12,  CB8_CA12,  CB9_CA12},

    {0, CB10_CA1,   CB11_CA1,   CB12_CA1},
    {0, CB10_CA2,   CB11_CA2,   CB12_CA2},
    {0, CB10_CA3,   CB11_CA3,   CB12_CA3},
    {0, CB10_CA4,   CB11_CA4,   CB12_CA4},
    {0, CB10_CA5,   CB11_CA5,   CB12_CA5},
    {0, CB10_CA6,   CB11_CA6,   CB12_CA6},
    {0, CB10_CA7,   CB11_CA7,   CB12_CA7},
    {0, CB10_CA8,   CB11_CA8,   CB12_CA8},
    {0, CB10_CA9,   CB11_CA9,   CB12_CA9},
    {0, CB10_CA10,  CB11_CA10,  CB12_CA10},
    {0, CB10_CA11,  CB11_CA11,  CB12_CA11},
    {0, CB10_CA12,  CB11_CA12,  CB12_CA12},

    {0, CB10_CA13,  CB11_CA13,  CB12_CA13},
    {0, CB10_CA14,  CB11_CA14,  CB12_CA14},
    {0, CB10_CA15,  CB11_CA15,  CB12_CA15},
    {0, CB10_CA16,  CB11_CA16,  CB12_CA16},
    {0, CB4_CA13,  CB5_CA13,  CB6_CA13},
    {0, CB4_CA14,  CB5_CA14,  CB6_CA14},
    {0, CB4_CA15,  CB5_CA15,  CB6_CA15},
    {0, CB7_CA13,  CB8_CA13,  CB9_CA13},
    {0, CB7_CA14,  CB8_CA14,  CB9_CA14},
    {0, CB7_CA15,  CB8_CA15,  CB9_CA15},
    {0, CB7_CA16,  CB8_CA16,  CB9_CA16},
};

#define SHIFT_COLOR_CHANGE 40

#define INDICATOR_COLOR(suffix, hue, sat)   hsv.h = (hue); hsv.s = (sat); RGB suffix ## _rgb = hsv_to_rgb(hsv);
#define MAKE_COLOR(suffix, hue, sat)        hsv.h = (rgb_matrix_config.hsv.h+(hue))&0xff; hsv.s = (sat); RGB suffix ## _rgb = hsv_to_rgb(hsv);
#define MAKE_COLOR_CS(suffix, hue, sat)     hsv.h = (rgb_matrix_config.hsv.h+(hue))&0xff; hsv.s = (get_mods() & MOD_MASK_SHIFT) ? (sat-SHIFT_COLOR_CHANGE) : (sat); RGB suffix ## _rgb = hsv_to_rgb(hsv);

#define SET_COLOR(i,clr)  rgb_matrix_set_color(i, clr ## _rgb.r, clr ## _rgb.g, clr ## _rgb.b);

#define SET_COLOR_STATE(i,clr,cond) if (cond) rgb_matrix_set_color(i, clr ## _on_rgb.r, clr ## _on_rgb.g, clr ## _on_rgb.b); else rgb_matrix_set_color(i, clr ## _off_rgb.r, clr ## _off_rgb.g, clr ## _off_rgb.b);

#define MAKE_ALPHA_COLOR_CS(suffix)  hsv = rgb_matrix_config.hsv; if (is_upper) {hsv.s -= SHIFT_COLOR_CHANGE;} RGB suffix ## _rgb = hsv_to_rgb(hsv);

#define SHOW_LAYER_INDICATORS

//#define HIGLIGHT_MOD_TAP

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (rgb_matrix_indicators_advanced_user(led_min, led_max) != true) {
        return false;
    }

    uint8_t is_upper = ((get_mods() & MOD_MASK_SHIFT)) || host_keyboard_led_state().caps_lock;

    /* Make Colors */
    HSV      hsv;   // temporary variable
    // use separate brightness level for indicators - repurpose effect speed setting
    hsv.v = rgb_matrix_config.speed;
#ifdef SHOW_LAYER_INDICATORS
    INDICATOR_COLOR(layer, 170, 255) // blue        - 66%
#endif
    INDICATOR_COLOR(state_on,    0,   0) // white       - 0%
    hsv.v >>= 1;
    INDICATOR_COLOR(state_off,   0,   0) // white       - 0%

    // normal keys use configured brightness
    hsv.v = rgb_matrix_config.hsv.v;
    MAKE_COLOR_CS(number,      85, 255) // green       - 33%
    MAKE_COLOR(num_pad,     85, 180) // green       - 33%
    MAKE_COLOR(num_number,     85, 255) // green       - 33%
    MAKE_COLOR_CS(function,   211, 255) // purple      - 83%
    MAKE_COLOR_CS(arrows,      41, 255) // yellow      - 16%
    MAKE_COLOR_CS(end_arrows,  21, 255) // orange      - 8%
    MAKE_COLOR(multimedia, 128, 255) // turquoise   - 50%
    MAKE_COLOR(layer_mod,  170, 100) // blue        - 66%
    MAKE_COLOR(modifier,   128, 200) // turquoise   - 50%
    MAKE_COLOR_CS(entry,      100, 255) // sea
    MAKE_COLOR_CS(symbol,     240, 255) // purplish
#ifdef HIGLIGHT_MOD_TAP
    MAKE_COLOR_CS(mod_tap,      0, 200) // red         - 0%
#endif

    MAKE_ALPHA_COLOR_CS(alpha)

    uint8_t layer = get_highest_layer(layer_state|default_layer_state);
    uint8_t default_layer = get_highest_layer(default_layer_state);
    uint16_t k;
    uint8_t i, row, col;

    for (row = 0; row < MATRIX_ROWS; ++row) {
        for (col = 0; col < MATRIX_COLS; ++col) {
            i = g_led_config.matrix_co[row][col];
            if (i < led_min || i >= led_max || i == NO_LED) continue;

            k = keymap_key_to_keycode(layer, (keypos_t){col,row});
            if(k==KC_TRANSPARENT) {
                k = keymap_key_to_keycode(default_layer, (keypos_t){col,row});
            }

            if (k == KC_NO) {
                rgb_matrix_set_color(i, RGB_OFF);
                continue;
            }
            if (IS_QK_MOD_TAP(k)) {
#ifdef HIGLIGHT_MOD_TAP
                SET_COLOR(i, mod_tap)
                continue;
#else
                k&=0xff;    // only look at the basic keycode
#endif
            }

            if (k>=KC_A && k<=KC_Z) {
                SET_COLOR(i, alpha)
                continue;
            }
            if (k>=KC_MINUS && k<=KC_SLASH) {
                SET_COLOR(i, symbol)
                continue;
            }
            if (k>=KC_1 && k<=KC_0) {
                SET_COLOR(i, number)
                continue;
            }
            if (k>=KC_KP_1 && k<=KC_KP_DOT) {
                SET_COLOR(i, num_number)
                continue;
            }
            if (k>=KC_KP_SLASH && k<=KC_KP_ENTER) {
                SET_COLOR(i, num_pad)
                continue;
            }
            if (k>=KC_F1 && k<=KC_F12) {
                SET_COLOR(i, function)
                continue;
            }
            if (k==KC_HOME || k==KC_END || k==KC_PAGE_DOWN || k==KC_PAGE_UP) {
                SET_COLOR(i, end_arrows)
                continue;
            }
            if (k>=KC_RIGHT && k<=KC_UP) {
                SET_COLOR(i, arrows)
                continue;
            }
            if ((k>=KC_AUDIO_MUTE && k<=KC_MEDIA_EJECT) || (k>=KC_MEDIA_FAST_FORWARD && k<=KC_MEDIA_REWIND)) {
                SET_COLOR(i, multimedia)
                continue;
            }
            if ( k>= QK_LAYER_TAP && k<= QK_LAYER_TAP_TOGGLE_MAX /*IS_QK_LAYER_MOD(k) || IS_QK_LAYER_TAP(k) ||IS_QK_TO(k)*/ ) {
                SET_COLOR(i, layer_mod)
                continue;
            }
            if ((k >= KC_ENTER && k <= KC_TAB) || k == KC_INSERT || k == KC_DELETE || k == QK_GESC || k==KC_APPLICATION) {
                SET_COLOR(i, entry)
                continue;
            }
            if (IS_MODIFIER_KEYCODE(k)) {
                SET_COLOR(i, modifier)
                continue;
            }
#ifdef HIGLIGHT_MOD_TAP
            if (IS_QK_MOD_TAP(k)) {
                SET_COLOR(i, mod_tap)
                continue;
            }
#endif
            if (IS_RGB_MATRIX_KEYCODE(k) || IS_UNDERGLOW_KEYCODE(k)) {
                SET_COLOR(i, end_arrows)   // temporarily
                continue;
            }
            switch(k) {
                case KC_NUM_LOCK:
                    SET_COLOR_STATE(i, state, host_keyboard_led_state().num_lock)
                    break;
                case KC_SCROLL_LOCK:
                    SET_COLOR_STATE(i, state, host_keyboard_led_state().scroll_lock)
                    break;
                case KC_CAPS_LOCK:
                    SET_COLOR_STATE(i, state, host_keyboard_led_state().caps_lock)
                    break;
            }
        }
    }

#ifdef SHOW_LAYER_INDICATORS
    /* layer state indicators */
    static const uint8_t layer_indicator_keys[] =
//    {39,40,42,43};  // old
//    {41,40,39,43};  // new
    {41,42,39,40};  // arrows
    //{40,41,29,42}; // alpha
    SET_COLOR(layer_indicator_keys[layer], layer)
#endif
    return true;
}
#endif
