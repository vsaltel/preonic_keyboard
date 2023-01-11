/* Copyright 2015-2017 Jack Humbert
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

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | 1  ! | 2  @ | 3  # | 4  $ | 5  % | 6  ^ | 7  & | 8  * | 9  ( | 0  ) | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | - _  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Lower |    Space    | RCtrl-Space |Raise | Left |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_6,        KC_7,          KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_Y,        KC_U,          KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_H,        KC_J,          KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_N,        KC_M,          KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,RCTL(KC_SPC),RCTL(KC_SPC),  RAISE,   KC_LEFT, KC_UP,   KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |  [ { |  ] } | del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CapsWo|      |      |      |      |      |      |      |      |      |   \  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   x  |             |             |  x   |      | Down |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  KC_TILD,    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,     KC_LBRC,    KC_RBRC,     KC_DEL,  \
  CS(KC_TAB), CS(KC_Q), CS(KC_W), CS(KC_E), CS(KC_R), CS(KC_T), CS(KC_Y), CS(KC_U), CS(KC_I),    CS(KC_O),   CS(KC_P),    KC_PIPE, \
  CS(KC_GRV), CS(KC_A), CS(KC_S), CS(KC_D), CS(KC_F), CS(KC_G), CS(KC_H), CS(KC_J), CS(KC_K),    CS(KC_L),   CS(KC_SCLN), KC_PLUS, \
  CW_TOGG,    CS(KC_Z), CS(KC_X), CS(KC_C), CS(KC_V), CS(KC_B), CS(KC_N), CS(KC_M), CS(KC_COMM), CS(KC_DOT), KC_BSLS,     KC_EQL,  \
  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,    KC_DOWN,     _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RAlt |  Mb1 | Mup  | Mb2  | Mwup |      |      |      |Insert| Copy |Paste |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Lead |Mleft |Mdown |Mright| Mwdo |      | Lum+ | Vol+ |      | Home | End  |AS ON |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift|      |      |      | Prev | Next | Lum- | Vol- |      |PageDo|PageUp|AS OFF|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Rctrl | RAlt | RGUI |  x   |     Play    |    Mute     |  x   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  KC_RALT, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, _______, _______, KC_INS,  KC_COPY, KC_PSTE, _______, \
  KC_LEAD, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, KC_BRIU, KC_VOLU, _______, KC_HOME, KC_END,  AS_ON,   \
  KC_RSFT, _______, _______, _______, KC_MPRV, KC_MNXT, KC_BRID, KC_VOLD, _______, KC_PGDN, KC_PGUP, AS_OFF,  \
  KC_RCTL, KC_RALT, KC_RGUI, _______, KC_MPLY, KC_MPLY, KC_MUTE, KC_MUTE, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Sleep | Wake |      |Reset |      |      |      |      |      |PrintS|  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Powoff|      |Aud on|AudOff|AGnorm|AGswap|Qwerty|      |KeyLok|      | AS + |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lock |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      | AS - |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |AS RPT|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F12,  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  _______, KC_SLEP, KC_WAKE, _______, RESET,   _______, _______, _______, _______, _______, KC_PSCR, KC_DEL,  \
  _______, KC_PWR,  _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, QK_LOCK, _______, AS_UP,   \
  KC_CAPS, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, AS_DOWN, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, AS_RPT   \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
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
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            PORTE &= ~(1<<6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            PORTE |= (1<<6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
#ifdef LEADER_ENABLE
	LEADER_DICTIONARY()
	{
		leading = false;
		leader_end();
		SEQ_ONE_KEY(KC_I)
		{
			SEND_STRING("#include \"");
		}
		SEQ_ONE_KEY(KC_M)
		{
			SEND_STRING("int main(int argc, char **argv)");
		}
		SEQ_ONE_KEY(KC_P)
		{
			SEND_STRING("printf(\"%s\n\",);");
		}
		SEQ_ONE_KEY(KC_R)
		{
			SEND_STRING("return (0);");
		}
	}
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
