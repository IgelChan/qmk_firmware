// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define SH_ENT      MT(MOD_RSFT, KC_ENT)
#define SH_BSLS     MT(MOD_LSFT, KC_BSLS)
#define SH_QUOT     MT(MOD_RSFT, KC_QUOT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌──────┬─────┬─────┬────┬───────┬─────┬─────┬──────┬──────┬──────┬────┬───────┐
     * │  `   │  Q  │  W  │ E  │   R   │  T  │  Y  │  U   │  I   │  O   │ P  │ BS    │
     * ├──────┼─────┼─────┼────┼───────┼─────┼─────┼──────┼──────┼──────┼────┼───────┤
     * │  \   │  A  │  S  │ D  │   F   │  G  │  H  │  J   │  K   │  L   │ ;  │   '   │
     * ├──────┼─────┼─────┼────┼───────┼─────┼─────┼──────┼──────┼──────┼────┼───────┤
     * │ LSH  │  Z  │  X  │ C  │   V   │  B  │  N  │  M   │  ,   │  .   │ /  │ ENTER │
     * ├──────┼─────┼─────┼────┼───────┼─────┼─────┼──────┼──────┼──────┼────┼───────┤
     * │ CTRL │ GUI │ ALT │ FN │ LOWER │ TAB │ SPC │ RISE │ LEFT │ DOWN │ UP │ RIGHT │
     * └──────┴─────┴─────┴────┴───────┴─────┴─────┴──────┴──────┴──────┴────┴───────┘
     */
    [0] = LAYOUT_ortho_4x12(    // Letters
        QK_GESC,  KC_Q,    KC_W,    KC_E,       KC_R,           KC_T,         KC_Y,       KC_U,         KC_I,         KC_O,       KC_P,       KC_BSPC,
        KC_BSLS,  KC_A,    KC_S,    KC_D,       KC_F,           KC_G,         KC_H,       KC_J,         KC_K,         KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,       KC_V,           KC_B,         KC_N,       KC_M,         KC_COMM,      KC_DOT,     KC_SLSH,    SH_ENT,
        KC_LCTL,  KC_LGUI, KC_LALT, TG(2),      LM(1,MOD_LSFT), KC_TAB,       KC_SPC,     MO(1),        KC_LEFT,      KC_DOWN,    KC_UP,      KC_RGHT
    ),
    [1] = LAYOUT_ortho_4x12(    // Numbers and symbols
        KC_GRV,   KC_1,    KC_2,    KC_3,       KC_4,           KC_5,          KC_6,      KC_7,         KC_8,         KC_9,       KC_0,       _______,
        KC_COMM,  KC_DOT, KC_SLSH,  KC_SCLN,    KC_QUOT,        KC_ESC,        KC_BSPC,   KC_MINS,      KC_EQL,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        _______,  _______, _______, _______,    _______,        KC_TAB,        KC_ENT,    XXXXXXX,      KC_HOME,      KC_PGUP,    KC_PGDN,    KC_END,
        KC_LCTL,  KC_LGUI, KC_LALT, XXXXXXX,    _______,        _______,       _______,    _______,     KC_LEFT,      KC_DOWN,    KC_UP,      KC_RGHT
    ),
    [2] = LAYOUT_ortho_4x12(    // Function keys and  NumPad
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,      KC_F4,          KC_INS,        KC_DEL,    KC_NUM,           KC_P7,        KC_P8,      KC_P9,      KC_PSLS,
        KC_TAB,   KC_F5,   KC_F6,   KC_F7,      KC_F8,          KC_ESC,        KC_BSPC,   KC_CAPS,          KC_P4,        KC_P5,      KC_P6,      KC_PAST,
        KC_RSFT,  KC_F9,   KC_F10,  KC_F11,     KC_F12,         KC_TAB,        KC_ENT,    KC_SCRL,          KC_P1,        KC_P2,      KC_P3,      KC_PMNS,
        KC_RCTL,  KC_RGUI, KC_RALT, _______,    XXXXXXX,        _______,       _______,   KC_APP,           KC_P0,        KC_PDOT,    KC_PENT,    KC_PPLS
    )
};
