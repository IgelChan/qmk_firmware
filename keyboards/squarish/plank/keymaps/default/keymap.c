// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define SH_ENT      MT(MOD_RSFT, KC_ENT)
#define SH_BSLS     MT(MOD_LSFT, KC_BSLS)
#define SH_QUOT     MT(MOD_RSFT, KC_QUOT)

#define SQ_RAISE    LM(1,MOD_LSFT)
#define SQ_LOWER    MO(1)

#define SQ_SPC_L    LT(2,KC_SPC)
#define SQ_SPC_R    LT(2,KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌──────┬─────┬─────┬─────┬───────┬─────┬─────┬──────┬───────┬──────┬──────┬───────┐
     * │  `   │  Q  │  W  │  E  │   R   │  T  │  Y  │  U   │   I   │  O   │  P   │  BS   │
     * ├──────┼─────┼─────┼─────┼───────┼─────┼─────┼──────┼───────┼──────┼──────┼───────┤
     * │ TAB  │  A  │  S  │  D  │   F   │  G  │  H  │  J   │   K   │  L   │  ;   │   '   │
     * ├──────┼─────┼─────┼─────┼───────┼─────┼─────┼──────┼───────┼──────┼──────┼───────┤
     * │ LSH  │  Z  │  X  │  C  │   V   │  B  │  N  │  M   │   ,   │  .   │  UP  │   /   │
     * ├──────┼─────┼─────┼─────┼───────┼─────┼─────┼──────┼───────┼──────┼──────┼───────┤
     * │ CTRL │ FN  │ GUI │ ALT │ LOWER │ SPC │ SPC │ RISE │ ENTER │ LEFT │ DOWN │ RIGHT │
     * └──────┴─────┴─────┴─────┴───────┴─────┴─────┴──────┴───────┴──────┴──────┴───────┘
     */
    [0] = LAYOUT_ortho_4x12(    // Letters
        QK_GESC,  KC_Q,    KC_W,    KC_E,       KC_R,           KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,       KC_P,       KC_BSPC,
        KC_TAB,   KC_A,    KC_S,    KC_D,       KC_F,           KC_G,         KC_H,         KC_J,         KC_K,         KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,       KC_V,           KC_B,         KC_N,         KC_M,         KC_COMM,      KC_DOT,     KC_UP,      KC_SLSH,
        KC_LCTL,  TO(1),   KC_LGUI, KC_LALT,    SQ_LOWER,       SQ_SPC_L,     SQ_SPC_R,     SQ_RAISE,     KC_ENT,       KC_LEFT,    KC_DOWN,    KC_RGHT
    ),
    [1] = LAYOUT_ortho_4x12(    // Numbers and symbols
        KC_GRV,   KC_1,    KC_2,    KC_3,       KC_4,           KC_5,         KC_6,         KC_7,         KC_8,         KC_9,       KC_0,       _______,
        _______,  KC_MINS, KC_EQL,  KC_LBRC,    KC_RBRC,        KC_BSLS,      KC_INS,       KC_MINS,      KC_EQL,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        _______,  _______, _______, _______,    _______,        KC_DEL,       KC_DEL,       XXXXXXX,      _______,      _______,    KC_PGUP,    _______,
        _______,  TO(2),   _______, _______,    _______,        KC_APP,       KC_APP,       _______,      _______,      KC_HOME,    KC_PGDN,    KC_END
    ),
    [2] = LAYOUT_ortho_4x12(    // Function keys and NumPad
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,      KC_F4,          KC_CAPS,      KC_NUM,       KC_P7,        KC_P8,        KC_P9,      KC_PSLS,    _______,
        KC_TAB,   KC_F5,   KC_F6,   KC_F7,      KC_F8,          KC_SCRL,      KC_INS,       KC_P4,        KC_P5,        KC_P6,      KC_PAST,    S(KC_9),
        KC_RSFT,  KC_F9,   KC_F10,  KC_F11,     KC_F12,         KC_DEL,       KC_DEL,       KC_P1,        KC_P2,        KC_P3,      KC_PMNS,    S(KC_0),
        KC_RCTL,  TO(3),   KC_RGUI, KC_RALT,    MO(3),          _______,      _______,      KC_P0,        KC_PDOT,      KC_PENT,    KC_PPLS,    KC_EQL
    ),
    [3] = LAYOUT_ortho_4x12(    // PrintScreen, Media keys, etc.
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,        QK_BOOT,      LAG(KC_PSCR), A(KC_PSCR),   XXXXXXX,      XXXXXXX,    KC_PAUSE,   G(KC_PAUSE),
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,        XXXXXXX,      XXXXXXX,      KC_MUTE,      KC_MRWD,      KC_MFFD,    KC_VOLU,    KC_MSTP,
        _______,  TO(0),   _______, _______,    TO(0),          TO(0),        XXXXXXX,      XXXXXXX,      KC_MPLY,      KC_MPRV,    KC_VOLD,    KC_MNXT
    )
};

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(GP27); // Layer 1
    gpio_set_pin_output(GP26); // Layer 2
    gpio_set_pin_output(GP22); // Layer 3

    gpio_set_pin_output(GP25); // Scroll lock

}

layer_state_t layer_state_set_user(layer_state_t state) {
    gpio_write_pin(GP27, layer_state_cmp(state, 1));
    gpio_write_pin(GP26, layer_state_cmp(state, 2));
    gpio_write_pin(GP22, layer_state_cmp(state, 3));
    return state;
}

bool led_update_user(led_t led_state) {
    gpio_write_pin(GP25, led_state.scroll_lock);
    return true;
}
