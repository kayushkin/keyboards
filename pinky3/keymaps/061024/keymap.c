/* Copyright 2018 'Masayuki Sunahara'
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

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST
};

#define CTL_TAB CTL_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x7_4(

      KC_SCLN,
      KC_P,
      KC_O,
      KC_I,
      KC_U,
      KC_Y,
      KC_NO,
      KC_NO,
      KC_T,
      KC_R,
      KC_E,
      KC_W,
      KC_Q,
      KC_DEL,
      KC_QUOT,
      KC_ENT,
      KC_L,
      KC_K,
      KC_J,
      KC_H,
      KC_NO,
      KC_NO,
      KC_G,
      KC_F,
      KC_D,
      KC_S,
      KC_A,
      KC_ESC,
      KC_NO,
      KC_SLSH,
      KC_DOT,
      KC_COMM,
      KC_M,
      KC_N,
      KC_DEL,
      KC_TAB,
      KC_B,
      KC_V,
      KC_C,
      KC_X,
      KC_Z,
      KC_NO,
      KC_RGUI,
      KC_BSPC,
      KC_SPC,
      MO(1),
      MO(1),
      KC_LSFT,
      KC_LCTL,
      KC_LALT
    ),
    [_LOWER] = LAYOUT_split_3x7_4(
      KC_F11,
      KC_PGUP,
      KC_BSLS,
      KC_GRV,
      KC_RBRC,
      KC_LBRC,
      KC_TRNS,
      KC_TRNS,
      KC_0,
      KC_9,
      KC_8,
      KC_7,
      KC_6,
      KC_F7,
      KC_F12,
      KC_PGDN,
      KC_RGHT,
      KC_UP,
      KC_DOWN,
      KC_LEFT,
      KC_TRNS,
      KC_TRNS,
      KC_5,
      KC_4,
      KC_3,
      KC_2,
      KC_1,
      KC_F8,
      KC_TRNS,
      KC_F10,
      KC_F9,
      KC_EQL,
      KC_MINS,
      KC_PSCR,
      KC_CAPS,
      KC_F6,
      KC_F5,
      KC_F4,
      KC_F3,
      KC_F2,
      KC_F1,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS,
      KC_TRNS
    )};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // set_timelog();
    }

    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
    }
    return true;
}
