/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "whitefox.h"

// enum keyboard_macros {
//   MACRO_BREATH_TOGGLE = 0,
//   MACRO_BREATH_SPEED_INC,
//   MACRO_BREATH_SPEED_DEC,
//   MACRO_BREATH_DEFAULT,
// };

enum whitefox_layers {
  _MAC,
  _WIN,
  _FL,
  _SL,
};

enum whitefox_keycodes {
  MAC = SAFE_RANGE,
  WIN,
  FL,
  SL,
};

//Tap Dance Declarations
enum {
  TD_GRV_ESC = 0
};

// #define M_BRTOG             M(MACRO_BREATH_TOGGLE)
// #define M_BSPDU             M(MACRO_BREATH_SPEED_INC)
// #define M_BSPDD             M(MACRO_BREATH_SPEED_DEC)
// #define M_BDFLT M(MACRO_BREATH_DEFAULT)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Mac Layer
     * ,---------------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|   |Fn1|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  Bkc|Del|
     * |---------------------------------------------------------------|
     * |MacFn |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |Hom|
     * |---------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |End|
     * |---------------------------------------------------------------|
     * |Ctrl|Alt |Gui |         Space    |Alt |Fn0 |    |  |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [_MAC] = KEYMAP_TRUEFOX( \
        TD(TD_GRV_ESC),KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,  KC_EQL,  KC_BSLS,KC_APFN, MO(_SL),\
        KC_TAB, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,   KC_LBRC,   KC_RBRC,      KC_BSPC,  KC_DEL,\
        LT(_FL, KC_BSPC),KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,  KC_QUOT,       KC_ENT, KC_HOME,\
        KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT,    KC_UP,    KC_END,\
        KC_LCTL,KC_LALT,KC_LGUI,               KC_SPC,           KC_RALT,MO(_FL),                         KC_LEFT,KC_DOWN,KC_RGHT\
    ),
        /* Layer 1: Windows Layer
     * ,---------------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|   |Fn1|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  Bkc|Del|
     * |---------------------------------------------------------------|
     * |CapLck|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |Hom|
     * |---------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |End|
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Space    |Alt |Fn0 |    |  |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [_WIN] = KEYMAP_TRUEFOX( \
        TD(TD_GRV_ESC),KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,  KC_EQL,  KC_BSLS,XXXXXXX, MO(_SL),\
        KC_TAB, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,   KC_LBRC,   KC_RBRC,      KC_BSPC,  KC_DEL,\
        LT(_FL, KC_CAPS),KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,  KC_QUOT,       KC_ENT, KC_HOME,\
        KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT,    KC_UP,    KC_END,\
        KC_LCTL,KC_LGUI,KC_LALT,               KC_SPC,           KC_RALT,MO(_FL),                         KC_LEFT,KC_DOWN,KC_RGHT\
    ),
        /* Layer 2: Function Layer
     * ,---------------------------------------------------------------.
     * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|   |   |Ins|
     * |---------------------------------------------------------------|
     * |     |   |Up |   |   |   |   |   |   |   |Psc|   |   |     |   |
     * |---------------------------------------------------------------|
     * |      |<- |Dn | ->|   |   |   |   |   |   |   |   |        |   |
     * |---------------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |Bl-|BL+|BL |  VU-|| >||VU+|
     * |---------------------------------------------------------------|
     * |    |    |    |                       |    |    |  |<< |MUT| >>|
     * `---------------------------------------------------------------'
     */
    [_FL] = KEYMAP_TRUEFOX( \
        _______, KC_F1,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, _______,\
        _______,_______,  KC_UP,_______,_______,_______,_______,_______,_______,_______,KC_PSCR,_______,_______,_______,  KC_INS,\
        _______ ,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,_______,_______,_______,_______,_______,_______,        _______,_______,\
        _______  ,_______,_______,_______,_______,_______,_______,_______, BL_DEC , BL_INC , BL_TOGG, KC_VOLD, KC_MPLY,  KC_VOLU,\
        _______,_______,_______,               _______,          _______,_______,                        KC_MRWD,KC_MUTE, KC_MFFD\
    ),
        /* Layer 3: Super Layer
     * ,---------------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |---------------------------------------------------------------|
     * |     |   |Win|   |   |   |   |   |   |   |   |   |   |     |   |
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |   |
     * |---------------------------------------------------------------|
     * |        |   |   |   |   |   |   |Mac|   |   |   |      |   |   |
     * |---------------------------------------------------------------|
     * |    |    |    |                       |    |    |  |   |   |   |
     * `---------------------------------------------------------------'
     */
    [_SL] = KEYMAP_TRUEFOX( \
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
        XXXXXXX ,XXXXXXX,    WIN,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,\
        XXXXXXX  ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,              XXXXXXX,XXXXXXX,\
        XXXXXXX   ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   MAC,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,       XXXXXXX,\
        XXXXXXX,XXXXXXX,XXXXXXX,               XXXXXXX,          XXXXXXX,XXXXXXX,                                XXXXXXX,XXXXXXX,XXXXXXX\
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MAC);
      }
      return false;
    case WIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WIN);
      }
      return false;
  }
return true;
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_GRV_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC)
// Other declarations would go here, separated by commas, if you have them
};

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
//     switch (id) {
//     case MACRO_BREATH_TOGGLE:
//       if (record->event.pressed)
//       {
//         #ifdef BACKLIGHT_BREATHING
//           breathing_toggle();
//         #endif
//       }
//       break;

//     case MACRO_BREATH_SPEED_INC:
//       if (record->event.pressed)
//       {
//         #ifdef BACKLIGHT_BREATHING
//           breathing_period_inc();
//         #endif
//       }
//       break;

//     case MACRO_BREATH_SPEED_DEC:
//       if (record->event.pressed)
//       {
//         #ifdef BACKLIGHT_BREATHING
//           breathing_period_dec();
//         #endif
//       }
//       break;

//     case MACRO_BREATH_DEFAULT:
//       if (record->event.pressed)
//       {
//         #ifdef BACKLIGHT_BREATHING
//           breathing_period_default();
//         #endif
//       }
//       break;

//     }
//     return MACRO_NONE;
// };
