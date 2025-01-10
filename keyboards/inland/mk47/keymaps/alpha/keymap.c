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

#define MT_LS MT(MOD_LSFT, KC_BACKSLASH)
#define MT_RS MT(MOD_RSFT, KC_QUOT)

#define MT_LC MT(MOD_LCTL, KC_SLASH)
#define MT_RC MT(MOD_RCTL, KC_DOT)

#define MT_LG MT(MOD_LGUI, KC_Z)
#define MT_RG MT(MOD_RGUI, KC_COMMA)

#define MT_LA MT(MOD_LALT, KC_X)
#define MT_RA MT(MOD_RALT, KC_M)

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
        QK_GESC, KC_1,      KC_2,    KC_3,       KC_4,     KC_5,     KC_6,       KC_7,          KC_8,       KC_9,       KC_0,       KC_BSPC,
        KC_TAB,  KC_Q,      KC_W,    KC_E,       KC_R,     KC_T,     KC_Y,       KC_U,          KC_I,       KC_O,       KC_P,       KC_ENT,
        MT_LS,   KC_A,      KC_S,    KC_D,       KC_F,     KC_G,     KC_H,       KC_J,          KC_K,       KC_L,       KC_SCLN,    MT_RS,
        MT_LC,   MT_LG,     MT_LA,   KC_C,       KC_V,     LT(1,KC_SPC),         LT(3,KC_B),    KC_N,       MT_RA,      MT_RG,      MT_RC
    ),

    [1] = LAYOUT_planck_mit(    // Function keys, arrows and other symbols
        KC_MINS,  KC_F1,   KC_F2,   KC_F3,      KC_F4,          KC_F5,      KC_F6,      KC_F7,          KC_F8,      KC_F9,      KC_F10,     KC_EQL,
        KC_LBRC,  KC_F11,  KC_F12,  XXXXXXX,    LAG(KC_PSCR),   XXXXXXX,    KC_INS,     KC_HOME,        KC_UP,      KC_END,     KC_PGUP,    KC_RBRC,
        KC_LSFT,  KC_PAUSE, XXXXXXX, XXXXXXX,   A(KC_PSCR),     TO(2),      KC_DEL,     KC_LEFT,        KC_DOWN,    KC_RIGHT,   KC_PGDN,    KC_RSFT,
//        KC_LBRC,  KC_F11,  KC_F12,  XXXXXXX,    KC_MUTE,  KC_VOLU,  KC_INS,     KC_PGUP,        KC_HOME,    KC_UP,      KC_END,     KC_RBRC,
//        KC_LSFT,  XXXXXXX, XXXXXXX, XXXXXXX,    KC_MPLY,  KC_VOLD,  KC_DEL,     KC_PGDN,        KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_RSFT,
        _______,  _______, _______, _______,    _______,        _______,                KC_APP,         XXXXXXX,    KC_RALT,    KC_RGUI,    KC_RCTL
//        KC_LCTL,  C(KC_Z), C(KC_X), C(KC_C),        C(KC_V),        KC_TRNS,                KC_APP,         XXXXXXX,    KC_RALT,    KC_RGUI,    KC_RCTL
    ),

    [2] = LAYOUT_planck_mit(   // XXX: Duplicate previous layer to emulate layer lock
        KC_MINS,  KC_F1,   KC_F2,   KC_F3,      KC_F4,          KC_F5,      KC_F6,      KC_F7,          KC_F8,      KC_F9,      KC_F10,     KC_EQL,
        KC_LBRC,  KC_F11,  KC_F12,  XXXXXXX,    LAG(KC_PSCR),   XXXXXXX,    KC_INS,     KC_HOME,        KC_UP,      KC_END,     KC_PGUP,    KC_RBRC,
        KC_LSFT,  KC_PAUSE, XXXXXXX, XXXXXXX,   A(KC_PSCR),     TO(0),      KC_DEL,     KC_LEFT,        KC_DOWN,    KC_RIGHT,   KC_PGDN,    KC_RSFT,
        _______,  _______, _______, _______,    _______,        _______,                KC_APP,         XXXXXXX,    KC_RALT,    KC_RGUI,    KC_RCTL
    ),

    [3] = LAYOUT_planck_mit(    // NumPad, and RGB control
        KC_ESC,   KC_P7,   KC_P8,   KC_P9,      KC_PAST,  KC_BSPC,  KC_NUM,     KC_MUTE,        XXXXXXX,    RGB_HUD,    RGB_SAD,    RGB_MOD,
        KC_TAB,   KC_P4,   KC_P5,   KC_P6,      KC_PMNS,  XXXXXXX,  KC_CAPS,    KC_VOLU,        XXXXXXX,    RGB_HUI,    RGB_SAI,    RGB_RMOD ,
        KC_RSFT,  KC_P1,   KC_P2,   KC_P3,      KC_PPLS,  XXXXXXX,  KC_SCRL,    KC_VOLD,        XXXXXXX,    RGB_TOG,    RGB_VAI,    XXXXXXX,
        KC_RCTL,  KC_P0,   KC_PDOT, KC_PSLS,    KC_PENT,  KC_SPC,               KC_TRNS,        XXXXXXX,    RGB_SPD,    RGB_VAD,    RGB_SPI
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
