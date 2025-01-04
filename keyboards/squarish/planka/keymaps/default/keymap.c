// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define SH_ENT      MT(MOD_RSFT, KC_ENT)
#define SH_BSLS     MT(MOD_LSFT, KC_BSLS)
#define SH_QUOT     MT(MOD_RSFT, KC_QUOT)

#define SQ_RAISE    LM(1,MOD_LSFT)
#define SQ_LOWER    MO(1)


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
        QK_GESC,  KC_Q,    KC_W,    KC_E,       KC_R,           KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,       KC_P,       KC_BSPC,
        KC_BSLS,  KC_A,    KC_S,    KC_D,       KC_F,           LT(3,KC_G),   LT(3,KC_H),   KC_J,         KC_K,         KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,       KC_V,           LT(2,KC_B),   LT(2,KC_N),   KC_M,         KC_COMM,      KC_DOT,     KC_SLSH,    KC_ENT,
        KC_LCTL,  KC_LGUI, KC_LALT, TG(2),      SQ_LOWER,       KC_TAB,       KC_SPC,       SQ_RAISE,     KC_LEFT,      KC_DOWN,    KC_UP,      KC_RGHT
    ),
    [1] = LAYOUT_ortho_4x12(    // Numbers and symbols
        KC_GRV,   KC_1,    KC_2,    KC_3,       KC_4,           KC_5,         KC_6,         KC_7,         KC_8,         KC_9,       KC_0,       _______,
        KC_TAB,   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,        KC_ESC,       KC_INS,       KC_MINS,      KC_EQL,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        _______,  _______, _______, _______,    _______,        XXXXXXX,      KC_DEL,       XXXXXXX,      KC_HOME,      KC_PGUP,    KC_PGDN,    KC_END,
        _______,  _______, _______, KC_APP,     _______,        _______,      _______,      _______,      KC_LEFT,      KC_DOWN,    KC_UP,      KC_RGHT
    ),
    [2] = LAYOUT_ortho_4x12(    // Function keys and NumPad
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,      KC_F4,          KC_CAPS,      KC_NUM,       KC_P7,        KC_P8,        KC_P9,      KC_PSLS,    KC_BSPC,
        KC_TAB,   KC_F5,   KC_F6,   KC_F7,      KC_F8,          KC_SCRL,      KC_INS,       KC_P4,        KC_P5,        KC_P6,      KC_PAST,    S(KC_9),
        KC_RSFT,  KC_F9,   KC_F10,  KC_F11,     KC_F12,         XXXXXXX,      KC_DEL,       KC_P1,        KC_P2,        KC_P3,      KC_PMNS,    S(KC_0),
        KC_RCTL,  KC_RGUI, KC_RALT, _______,    _______,        _______,      _______,      KC_P0,        KC_PDOT,      KC_PENT,    KC_PPLS,    KC_EQL
    ),
    [3] = LAYOUT_ortho_4x12(    // RGB control, PrintScreen, Media keys
        UG_PREV,  UG_SPDU, UG_TOGG, XXXXXXX,    XXXXXXX,        QK_BOOT,      LAG(KC_PSCR), A(KC_PSCR),   XXXXXXX,      XXXXXXX,    XXXXXXX,    G(KC_PAUSE),
        UG_NEXT,  UG_SPDD, UG_TOGG, XXXXXXX,    XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,
        UG_HUEU,  UG_VALU, UG_SATU, XXXXXXX,    XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_MUTE,      XXXXXXX,    XXXXXXX,    KC_MPLY,
        UG_HUED,  UG_VALD, UG_SATD, XXXXXXX,    TO(0),          _______,      _______,      XXXXXXX,      KC_MPRV,      KC_VOLD,    KC_VOLU,    KC_MNXT
    )
};

/*
LED order
Left              Right
13,12,11,10,9,8,7,0,1,2,3,4,5,6
*/

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 1, HSV_WHITE}
);

const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_WHITE}
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 4, HSV_CYAN},
    {3, 4, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 4, HSV_PURPLE},
    {1, 4, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 3, HSV_ORANGE},
    { 7, 1, HSV_RED},
    { 1, 2, HSV_GREEN},
    { 3, 4, HSV_BLUE}
);

#define FIRST_LAYER 1

// Define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_numlock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    rgblight_set_layer_state(1, led_state.num_lock);
    return true;
}

/*
layer_state_t default_layer_state_set_user(layer_state_t state) {
    return state;
}*/

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t i;
    for (i=1;i<=3; ++i){
        rgblight_set_layer_state(i+FIRST_LAYER, layer_state_cmp(state, i));
    }
    return state;
}
