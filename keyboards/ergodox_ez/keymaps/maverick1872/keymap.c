#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"

// Windows/Linux custom keys
#define WIN_CUT  C(KC_X)
#define WIN_COPY C(KC_C)
#define WIN_PSTE C(KC_V)
#define WIN_UNDO C(KC_Z)
#define WIN_REDO C(S(KC_Z))

// MAC custom keys
#define MAC_CUT  LGUI(KC_X)
#define MAC_COPY LGUI(KC_C)
#define MAC_PSTE LGUI(KC_V)
#define MAC_UNDO LGUI(KC_Z)
#define MAC_REDO LGUI(S(KC_Z))

// Layer definitions
enum {
  WIN_BASE = 0,
  WIN_NAV,
  MAC_BASE,
  MAC_NAV,
  NUMPAD
};

// Tap dance keycodes
enum {
  TD_ENT = 0,
  TD_SCLN,
  TD_SLSH,
  TD_QUOT
};

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};


// Empty layer layout doc
/*
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |        |      |      |      |      |                                       |      |      |      |      |        |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |      |      |       |      |       |
 *                                 ,------|------|------|       |------+-------+-------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
*/


// Program layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [WIN_BASE] = LAYOUT_ergodox(
    // LEFT HAND
    KC_GESC,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_F4,
    KC_TAB,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_F6,
    KC_CAPS,          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
    KC_LSPO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_F8,
    KC_LCTL,          KC_GRV,         KC_LALT,        MO(NUMPAD),     MO(WIN_NAV),
    // LEFT THUMB
    TO(MAC_BASE),     XXXXXXX,
    XXXXXXX,
    KC_SPC,       KC_DEL,         KC_LGUI,

    // RIGHT HAND
    KC_EQL,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           XXXXXXX,
    KC_MINS,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
                      KC_H,           KC_J,           KC_K,           KC_L,           TD(TD_SCLN),    TD(TD_QUOT),
    KC_AMPR,          KC_N,           KC_M,           KC_COMM,        KC_DOT,         TD(TD_SLSH),    KC_RSPC,
                                      MO(WIN_NAV),    MO(NUMPAD),     KC_RALT,        XXXXXXX,        KC_RCTL,
    // RIGHT THUMB
    RGB_VAD,          RGB_VAI,
    XXXXXXX,
    KC_RGUI,          KC_BSPC,        TD(TD_ENT)
  ),
  [WIN_NAV]  = LAYOUT_ergodox(
    // LEFT HAND
    XXXXXXX,          KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            WIN_CUT,
    XXXXXXX,          XXXXXXX,          KC_PGDN,          KC_VOLU,          KC_PGUP,          XXXXXXX,          WIN_COPY,
    XXXXXXX,          XXXXXXX,          KC_MPRV,          KC_MPLY,          KC_MNXT,          XXXXXXX,
    KC_TRNS,          XXXXXXX,          XXXXXXX,          KC_VOLD,          XXXXXXX,          XXXXXXX,          WIN_PSTE,
    KC_TRNS,          XXXXXXX,          KC_TRNS,          XXXXXXX,          MO(WIN_NAV),
    // LEFT THUMB
    XXXXXXX,          XXXXXXX,
    XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,

    // RIGHT HAND
    XXXXXXX,          KC_F6,            KC_F7,            KC_F8,            KC_F9,            KC_F10,           KC_F11,
    WIN_REDO,         XXXXXXX,          KC_LBRC,          KC_UP,            KC_RBRC,          XXXXXXX,          KC_F12,
                      KC_HOME,          KC_LEFT,          KC_DOWN,          KC_RGHT,          KC_END,           XXXXXXX,
    WIN_UNDO,         XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          KC_TRNS,
                                        MO(WIN_NAV),      XXXXXXX,          KC_TRNS,          XXXXXXX,          KC_TRNS,
    // RIGHT THUMB
    XXXXXXX,          XXXXXXX,
    XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX
  ),
  [MAC_BASE] = LAYOUT_ergodox(
    // LEFT HAND
    KC_GESC,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_F4,
    KC_TAB,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_F6,
    KC_CAPS,          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
    KC_LSPO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_F8,
    KC_LCTL,          KC_GRV,         KC_LALT,        MO(NUMPAD),     MO(MAC_NAV),
    // LEFT THUMB
    TO(WIN_BASE),     XXXXXXX,
    XXXXXXX,
    KC_SPC,       KC_DEL,         KC_LGUI,

    // RIGHT HAND
    KC_EQL,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           XXXXXXX,
    KC_MINS,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
                      KC_H,           KC_J,           KC_K,           KC_L,           TD(TD_SCLN),    TD(TD_QUOT),
    KC_AMPR,          KC_N,           KC_M,           KC_COMM,        KC_DOT,         TD(TD_SLSH),    KC_RSPC,
                                      MO(MAC_NAV),    MO(NUMPAD),     KC_RALT,        XXXXXXX,        KC_RCTL,
    // RIGHT THUMB
    RGB_VAD,          RGB_VAI,
    XXXXXXX,
    KC_RGUI,          KC_BSPC,        TD(TD_ENT)
  ),
  [MAC_NAV]  = LAYOUT_ergodox(
    // LEFT HAND
    XXXXXXX,          KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            MAC_CUT,
    XXXXXXX,          XXXXXXX,          KC_PGDN,          KC_VOLU,          KC_PGUP,          XXXXXXX,          MAC_COPY,
    XXXXXXX,          XXXXXXX,          KC_MRWD,          KC_MPLY,          KC_MFFD,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,          KC_VOLD,          XXXXXXX,          XXXXXXX,          MAC_PSTE,
    KC_TRNS,          XXXXXXX,          KC_TRNS,          XXXXXXX,          MO(MAC_NAV),
    // LEFT THUMB
    XXXXXXX,          XXXXXXX,
    XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,

    // RIGHT HAND
    XXXXXXX,          KC_F6,            KC_F7,            KC_F8,            KC_F9,            KC_F10,           KC_F11,
    MAC_REDO,         XXXXXXX,          KC_LBRC,          KC_UP,            KC_RBRC,          XXXXXXX,          KC_F12,
                      KC_HOME,          KC_LEFT,          KC_DOWN,          KC_RGHT,          KC_END,           XXXXXXX,
    MAC_UNDO,         XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
                                        MO(MAC_NAV),      XXXXXXX,          KC_TRNS,          XXXXXXX,          KC_TRNS,
    // RIGHT THUMB
    XXXXXXX,          XXXXXXX,
    XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX
  ),
  [NUMPAD]   = LAYOUT_ergodox(
    // LEFT HAND
    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,          MO(NUMPAD),       XXXXXXX,
    // LEFT THUMB
    XXXXXXX,          XXXXXXX,
    XXXXXXX,
    XXXXXXX,          XXXXXXX,          XXXXXXX,

    // RIGHT HAND
    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          KC_7,             KC_8,             KC_9,             XXXXXXX,          XXXXXXX,
                      XXXXXXX,          KC_4,             KC_5,             KC_6,             XXXXXXX,          XXXXXXX,
    XXXXXXX,          XXXXXXX,          KC_1,             KC_2,             KC_3,             XXXXXXX,          XXXXXXX,
                                        KC_0,             MO(NUMPAD),       XXXXXXX,          XXXXXXX,          XXXXXXX,
    // RIGHT THUMB
    KC_SLEP,          XXXXXXX,
    XXXXXXX,
    XXXXXXX,          KC_BSPC,          KC_DOT
  )
};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// RGB LED map per layer
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255} },

    [1] = { {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255}, {147,119,255} },

    [2] = { {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255} },

    [3] = { {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255}, {246,142,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

// Runs on key event
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case KC_CAPS:
      if (record->event.pressed) {
        if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
          ergodox_right_led_3_off();
        } else {
          ergodox_right_led_3_on();
        }
      }
  }
  return true;
}

// Runs on layer change
uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  // right led 3 is caps lock indicator - layer change should not affect it.
  // ergodox_right_led_3_off();
  switch (layer) {
    case WIN_BASE:
      break;
    case WIN_NAV:
      ergodox_right_led_1_on();
      break;
    case MAC_BASE:
      break;
    case MAC_NAV:
      ergodox_right_led_1_on();
      break;
    case NUMPAD:
      ergodox_right_led_2_on();
      break;
    default:
      break;
  }
  return state;
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap for ent, double tap for dot
  [TD_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_DOT),
  [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
  [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_QUES),
  [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO)
};
