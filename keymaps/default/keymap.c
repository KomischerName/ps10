/* Copyright 2021 KomischerName
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
// #include "print.h"

// Defines names for use in layer keycodes and the keymap
enum layers {
    BASE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE LAYER
    /-----------------------------`
    |   Vol-  |   Mute  |  Vol+   |
    |         |---------|         |
    |---------|         |---------|
    |                   | RGB_TOG |
    |---------|---------|---------|
    |   F13   |   F14   |   F15   |
    |---------|---------|---------|
    |   F16   |   F17   |   F18   |
    |---------|---------|---------|
    |   F19   |   F20   |   F21   |
    \-----------------------------'
    */
    [BASE] = LAYOUT(
                        KC_AUDIO_MUTE,
                                        RGB_TOG,
        KC_F13,         KC_F14,         KC_F15,
        KC_F16,         KC_F17,         KC_F18,
        KC_F19,         KC_F20,         KC_F21
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_AUDIO_VOL_UP);
    } else {
        tap_code(KC_AUDIO_VOL_DOWN);
    }
    return true;
}

void keyboard_post_init_user(void) {
    rgblight_sethsv(0x08, 0xFF, 0xFF);
}