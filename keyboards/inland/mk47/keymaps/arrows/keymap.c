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

#define SH_ENT      MT(MOD_RSFT, KC_ENT)
#define SH_BSLS     MT(MOD_LSFT, KC_BSLS)
#define SH_QUOT     MT(MOD_RSFT, KC_QUOT)

#define SQ_RAISE    LM(1,MOD_LSFT)
#define SQ_LOWER    MO(1)

#define SQ_SPC_L    LT(2,KC_SPC)
#define SQ_SPC_R    LT(2,KC_SPC)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_planck_mit(    // Letters
        QK_GESC,  KC_Q,    KC_W,    KC_E,       KC_R,           KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,       KC_P,       KC_BSPC,
        KC_TAB,   KC_A,    KC_S,    KC_D,       KC_F,           KC_G,         KC_H,         KC_J,         KC_K,         KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,       KC_V,           KC_B,         KC_N,         KC_M,         KC_COMM,      KC_DOT,     KC_SLSH,    SH_ENT,
        KC_LCTL,  KC_LGUI, KC_LALT, TO(1),      SQ_LOWER,       SQ_SPC_L,                   SQ_RAISE,     KC_LEFT,      KC_DOWN,    KC_UP,      KC_RGHT
    ),

    [1] = LAYOUT_planck_mit(    // Numbers and symbols
        KC_GRV,   KC_1,    KC_2,    KC_3,       KC_4,           KC_5,         KC_6,         KC_7,         KC_8,         KC_9,       KC_0,       _______,
        KC_BSLS,  KC_MINS, KC_EQL,  KC_LBRC,    KC_RBRC,        KC_BSLS,      KC_INS,       KC_MINS,      KC_EQL,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        _______,  _______, _______, _______,    KC_DEL,         KC_DEL,       KC_DEL,       KC_DEL,       KC_HOME,      KC_PGUP,    KC_PGDN,    KC_END,
        _______,  _______, _______, TO(2),      _______,        KC_APP,                     _______,      KC_LEFT,      KC_DOWN,    KC_UP,      KC_RGHT
    ),

    [2] = LAYOUT_planck_mit(    // Function keys and NumPad
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,      KC_F4,          KC_CAPS,      KC_NUM,       KC_P7,        KC_P8,        KC_P9,      KC_PSLS,    _______,
        KC_TAB,   KC_F5,   KC_F6,   KC_F7,      KC_F8,          KC_SCRL,      KC_INS,       KC_P4,        KC_P5,        KC_P6,      KC_PAST,    S(KC_9),
        KC_RSFT,  KC_F9,   KC_F10,  KC_F11,     KC_F12,         KC_DEL,       KC_DEL,       KC_P1,        KC_P2,        KC_P3,      KC_PMNS,    S(KC_0),
        KC_RCTL,  KC_RGUI, KC_RALT, TO(3),      MO(3),          _______,                    KC_P0,        KC_PDOT,      KC_PENT,    KC_PPLS,    KC_EQL
    ),

    [3] = LAYOUT_planck_mit(    // RGB control, PrintScreen, Media keys
        UG_PREV,  UG_SPDU, UG_TOGG, XXXXXXX,    QK_BOOT,        XXXXXXX,      LAG(KC_PSCR), A(KC_PSCR),   XXXXXXX,      XXXXXXX,    KC_PAUSE,   G(KC_PAUSE),
        UG_NEXT,  UG_SPDD, UG_TOGG, XXXXXXX,    XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,
        UG_HUEU,  UG_VALU, UG_SATU, XXXXXXX,    XXXXXXX,        XXXXXXX,      XXXXXXX,      KC_MUTE,      KC_MRWD,      KC_MFFD,    KC_MSTP,    KC_MPLY,
        UG_HUED,  UG_VALD, UG_SATD, TO(0),      TO(0),          TO(0),                      XXXXXXX,      KC_MPRV,      KC_VOLD,    KC_VOLU,    KC_MNXT
    )

};
// clang-format on
