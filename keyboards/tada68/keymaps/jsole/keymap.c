#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum keyboard_macros {
  MACRO_BREATH_TOGGLE = 0,
  MACRO_BREATH_SPEED_INC,
  MACRO_BREATH_SPEED_DEC,
  MACRO_BREATH_DEFAULT,
  // MACRO_NUMBER,
};

#define _BL 0
#define _FL 1
#define _NL 2

#define M_BRTOG             M(MACRO_BREATH_TOGGLE)
#define M_BSPDU             M(MACRO_BREATH_SPEED_INC)
#define M_BSPDD             M(MACRO_BREATH_SPEED_DEC)
#define M_BDFLT             M(MACRO_BREATH_DEFAULT)
// #define M_NUML              M(MACRO_NUMBER)

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Esc |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |FN2Bspc|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |Win |        Space          |Alt|FN1|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_GRV,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_ESC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  LT(_NL, KC_BSPC) , KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGUP,  \
  KC_LSPO,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSPC,KC_UP,KC_PGDN, \
  MT(MOD_LCTL, KC_LBRC), KC_LALT,KC_LGUI,                KC_SPC,                        KC_RALT,MO(_FL),MT(MOD_RCTL, KC_RBRC), KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |Psc|   |   |     |Hme |
   * |----------------------------------------------------------------|
   * |CAPS  |<- |Dn | ->|   |   |BrT|   |   |   |   |   |        |End |
   * |----------------------------------------------------------------|
   * |        |Bl-|BL |BL+|Br-|BrD|Br+|VU-|VU+|MUT|   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS ,  \
  _______,_______, KC_UP,_______,_______, _______,_______,_______,_______,_______, KC_PSCR,_______,_______, _______,KC_HOME, \
  KC_CAPS,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,M_BRTOG,_______,_______,_______,_______,_______,        _______,KC_END, \
  _______,BL_DEC ,BL_TOGG,BL_INC , M_BSPDD,M_BDFLT, M_BSPDU,KC_VOLD,KC_VOLU,KC_MUTE,_______,KC_BTN1, KC_MS_U, KC_BTN2, \
  _______,_______,_______,                 _______,               _______,_______,_______,KC_MS_L,KC_MS_D, KC_MS_R),

  /* Keymap _CL: Function Layer
   * ,----------------------------------------------------------------.
   * |   |   |   |   |   |   |   | 7 | 8 | 9 |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   | 4 | 5 | 6 |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |      |<- |Dn | ->|   |   |   | 1 | 2 | 3 |   |   |        |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   | 0 |   |   |   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_NL] = KEYMAP_ANSI(
  _______, _______,_______,_______,_______,_______,_______,KC_P7  ,KC_P8  ,KC_P9  ,_______,_______,_______,_______,_______,  \
  _______,_______,  KC_UP,_______,_______, _______,_______,KC_P4  ,KC_P5  ,KC_P6  ,_______,_______,_______, _______,_______, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,_______,KC_P1  ,KC_P2  ,KC_P3  ,_______,_______,        _______,_______, \
  _______,_______,_______,_______,_______,_______, _______,KC_P0  ,_______,_______,_______,KC_BTN1, KC_MS_U, KC_BTN2, \
  _______,_______,_______,                 _______,               _______,_______,_______,KC_MS_L,KC_MS_D, KC_MS_R),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
    case MACRO_BREATH_TOGGLE:
      if (record->event.pressed) {
        breathing_toggle();
      }
      break;

    case MACRO_BREATH_SPEED_INC:
      if (record->event.pressed) {
        breathing_speed_inc(1);
      }
      break;

    case MACRO_BREATH_SPEED_DEC:
      if (record->event.pressed) {
        breathing_speed_dec(1);
      }
      break;

    case MACRO_BREATH_DEFAULT:
      if (record->event.pressed) {
        breathing_defaults();
      }
      break;

    // case MACRO_NUMBER:
    //   if (record->event.pressed) {
    //     breathing_speed_set(3);
    //     breathing_enable();
    //     layer_on(_NL);
    //   }
    //   else {
    //     breathing_speed_set(1);
    //     breathing_self_disable();
    //     layer_off(_NL);
    //   }
    //   break;
  }
    return MACRO_NONE;
};