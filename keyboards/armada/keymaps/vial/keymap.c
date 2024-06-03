#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_armada(
        KC_F11, KC_F12, KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, LT(1,KC_F5), KC_F6,   LT(1,KC_F5), KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,        KC_PSCR, KC_SCROLL_LOCK, KC_PAUS, RGB_TOG, RGB_VAI, RGB_VAD, _______,
        KC_F1, KC_F2, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,    KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,           KC_INS,  KC_HOME, KC_PGUP, KC_NUM_LOCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_F3, KC_F4, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,           KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN, KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_F5, KC_F6, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H,          KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENTER,                                    KC_P4, KC_P5, KC_P6,
        KC_F7, KC_F8, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N,          KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,                       KC_UP,            KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_F9, KC_F10, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,                    KC_SPC, KC_RALT, KC_RGUI, KC_APP, KC_RCTL,                        KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,       KC_PDOT
    ),

    [1] = LAYOUT_armada(
        _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,            _______, QK_BOOT, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______, _______,                                       _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,                              _______,          _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______,                                       _______, _______, _______, _______,          _______
    )
};

const rgblight_segment_t PROGMEM caps_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  //  {34, 1, HSV_CYAN},        // Light caps lock
  //  {39, 1, HSV_CYAN}        // Light lshift
   // below lights all alphas as well as caps lock
   {22, 13, HSV_CYAN},       // Light 13 leds, Q through caps lock on left hand
   {40, 6, HSV_CYAN},        // Light 6 leds, Z through N on left hand
   {71, 11, HSV_CYAN},       // right hand alphas
   {89, 3, HSV_CYAN}         // right hand alphas
);

const rgblight_segment_t PROGMEM num_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {107, 1, HSV_CYAN}, //numlock key
    {112, 3, HSV_CYAN},
    {118, 3, HSV_CYAN},
    {122, 3, HSV_CYAN},
    {129, 2, HSV_CYAN}
);

const rgblight_segment_t PROGMEM scroll_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {102, 1, HSV_CYAN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    caps_lock_layer,
    num_lock_layer,
    scroll_lock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
	rgblight_set_layer_state(0, led_state.caps_lock);
	rgblight_set_layer_state(1, led_state.num_lock);
	rgblight_set_layer_state(2, led_state.scroll_lock);
	rgblight_set();
	return true;
}

uint16_t g_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_F5):
            return 2000;
        default:
            return TAPPING_TERM;
    }
}
