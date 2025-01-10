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
#include QMK_KEYBOARD_H

#define RS_SCRL MT(MOD_RSFT, KC_SCRL)

#ifdef TAP_DANCE_ENABLE
//Tap Dance Declarations
enum {
    TD_B_TG_1 = 0,
    TD_N_TG_2,
    TD_M_APP
};

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_B_TG_1] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_B, 1),
    [TD_N_TG_2] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_N, 2),
    [TD_M_APP]  = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_APP)
};
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_planck_mit(    // Letters
        QK_GESC,  KC_Q,    KC_W,    KC_E,       KC_R,       KC_T,         KC_Y,       KC_U,           KC_I,           KC_O,       KC_P,       KC_BSPC,
        KC_TAB,   KC_A,    KC_S,    KC_D,       KC_F,       KC_G,         KC_H,       KC_J,           KC_K,           KC_L,       KC_SCLN,    KC_ENT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,       KC_V,       KC_B,         KC_N,       KC_M,           KC_COMM,        KC_DOT,     KC_UP,      MT(MOD_RSFT,KC_SLSH),
        KC_LCTL,  KC_LGUI, KC_LALT, TG(2),      MO(1),      LT(2,KC_SPC),             LM(1,MOD_LSFT), LT(3, KC_APP),  KC_LEFT,    KC_DOWN,    KC_RGHT
    ),

    [1] = LAYOUT_planck_mit(    // Function keys, numbers and symbols
        KC_GRV,   KC_1,    KC_2,    KC_3,       KC_4,       KC_5,         KC_6,       KC_7,           KC_8,           KC_9,       KC_0,       KC_DEL,
        KC_TAB,   KC_MINS, KC_EQL,  KC_LBRC,    KC_RBRC,    KC_BSLS,      KC_SCLN,    KC_QUOT,        KC_COMM,        KC_DOT,     KC_SLSH,    KC_ENT,
        KC_LSFT,  _______, _______, _______,    _______,    XXXXXXX,      XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    KC_PGUP,    XXXXXXX,
        KC_LCTL,  KC_LGUI, KC_LALT, XXXXXXX,    _______,    KC_SPC,                   _______,        XXXXXXX,        KC_HOME,    KC_PGDN,    KC_END
    ),

    [2] = LAYOUT_planck_mit(    // Function keys and  NumPad
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,      KC_F4,      KC_INS,      KC_DEL,      KC_P7,          KC_P8,          KC_P9,      KC_PSLS,    KC_BSPC,
        KC_TAB,   KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_ESC,      KC_BSPC,     KC_P4,          KC_P5,          KC_P6,      KC_PAST,    KC_ENT,
        KC_RSFT,  KC_F9,   KC_F10,  KC_F11,     KC_F12,     KC_TAB,      KC_ENT,      KC_P1,          KC_P2,          KC_P3,      KC_PMNS,    XXXXXXX,
        KC_RCTL,  KC_RGUI, KC_RALT, _______,    XXXXXXX,    _______,                  KC_P0,          KC_PDOT,        KC_PENT,    KC_PPLS,    XXXXXXX
    ),

    [3] = LAYOUT_planck_mit(    // RGB control, PrintScreen, Media keys
        RGB_HUI,  RGB_SAI, XXXXXXX, QK_BOOT,    XXXXXXX,    G(KC_PAUSE),   XXXXXXX,   LAG(KC_PSCR),   A(KC_PSCR),     KC_NUM,     KC_CAPS,    KC_SCRL,
        RGB_HUD,  RGB_SAD, RGB_TOG, XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,   XXXXXXX,        XXXXXXX,        KC_MUTE,    XXXXXXX,    KC_MPLY,
        XXXXXXX,  RGB_VAI, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,   XXXXXXX,        XXXXXXX,        XXXXXXX,    KC_VOLU,    XXXXXXX,
        RGB_SPD,  RGB_VAD, RGB_SPI, XXXXXXX,    XXXXXXX,    XXXXXXX,                  XXXXXXX,        _______,        KC_MPRV,    KC_VOLD,    KC_MNXT
    )

};
// clang-format on

/*
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // layer state
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 128);
            break;
        case 1:
            RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, 0, 128);
            break;
        case 2:
            RGB_MATRIX_INDICATOR_SET_COLOR(2, 0, 0, 128);
            break;
        case 3:
            RGB_MATRIX_INDICATOR_SET_COLOR(3, 0, 0, 128);
            break;
    }
    return true;
}
*/
