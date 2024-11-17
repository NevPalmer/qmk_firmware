/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _NUMNAV,
    _SYMBOL,
    _FUNCTION,
};

// Aliases for readability
#define SYMBOL   TT(_SYMBOL)
#define NUMNAV   TG(_NUMNAV)
#define FKEYS    MO(_FUNCTION)

#define SFT_ESC MT(MOD_LSFT, KC_ESC)

// For Thumb Cluster
#define NUM_DEL LT(_NUMNAV, KC_DEL)
#define NUM_BSP LT(_NUMNAV, KC_BSPC)
#define SYM_SPC LT(_SYMBOL, KC_SPC)

// For QWERTY layer
#define CTL_A    MT(MOD_LCTL, KC_A)
#define GUI_S    MT(MOD_LGUI, KC_S)
#define SFT_D    MT(MOD_LSFT, KC_D)
#define ALT_F    MT(MOD_LALT, KC_F)
#define ALT_H    MT(MOD_LALT, KC_H)
#define SFT_J    MT(MOD_RSFT, KC_J)
#define GUI_K    MT(MOD_RGUI, KC_K)
#define CTL_L    MT(MOD_RCTL, KC_L)
#define SFT_SC   MT(MOD_RSFT, KC_SCLN)

// For NUMNAV layer
#define CTL_SLS  MT(MOD_LCTL, KC_PSLS)
#define GUI_P4   MT(MOD_LGUI, KC_P4)
#define SFT_P5   MT(MOD_LSFT, KC_P5)
#define ALT_P6   MT(MOD_LALT, KC_P6)
#define ALT_LFT  MT(MOD_LALT, KC_LEFT)
#define SFT_DWN  MT(MOD_RSFT, KC_DOWN)
#define GUI_UP   MT(MOD_RGUI, KC_UP)
#define CTL_RGT  MT(MOD_RCTL, KC_RGHT)
#define SFT_VLD  MT(MOD_RSFT, KC_VOLD)

// For SYMBOL layer
#define CTL_TLD  MT(MOD_LCTL, KC_TILD)
#define GUI_HSH  MT(MOD_LGUI, KC_HASH)
#define SFT_PRC  MT(MOD_LSFT, KC_PERC)
#define ALT_CRC  MT(MOD_LALT, KC_CIRC)
#define ALT_LBR  MT(MOD_LALT, KC_LBRC)
#define SFT_RBR  MT(MOD_LSFT, KC_RBRC)
#define GUI_LPN  MT(MOD_RGUI, KC_LPRN)
#define CTL_RPN  MT(MOD_RCTL, KC_RPRN)

// For FUNCTION layer
#define GUI_LFT  MT(MOD_LGUI, KC_LEFT)
#define ALT_RGT  MT(MOD_LALT, KC_RGHT)
#define ALT_F5   MT(MOD_LALT, KC_F5)
#define SFT_F6   MT(MOD_LSFT, KC_F6)
#define GUI_F7   MT(MOD_RGUI, KC_F7)
#define CTL_F8   MT(MOD_RCTL, KC_F8)
#define SFT_INS  MT(MOD_RSFT, KC_INS)

// Note:
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// Intercepts non-basic keycodes for use with mod-tap.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_TLD:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_TILD); // Send KC_TILD on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case GUI_HSH:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_HASH); // Send KC_HASH on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case SFT_PRC:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PERC); // Send KC_PERC on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case ALT_CRC:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_CIRC); // Send KC_CIRC on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case GUI_LPN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN); // Send KC_LPRN on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case CTL_RPN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN); // Send KC_RPRN on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |      |   Y  |   U  |   I  |   O  |    P  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+-------|
 * |Shft/Esc| GUI/A| Alt/S|Ctrl/D|Shft/F|   G  |                              |      | Alt/H|Shft/J| GUI/K|Ctrl/L|Shft/;:|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-------|
 * |  CTRL  |   Z  |   X  |   C  |   V  |   B  |NumNav| NumLk|  |CapsLk|NumNav|      |   N  |   M  | ,  < | . >  |  /  ? |
 * |        |      |      |      |      |      | Lock |      |  |      | Lock |      |      |      |      |      |       |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+---------------------'
 *                        | Menu |F-Keys|NUMNAV| SYM/ | Enter|  | Enter| SYM/ |NUMNAV|F-Keys| Menu |
 *                        |      |      |/BkSpc| Space|      |  |      | Space| /Del |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                   XXXXXXX,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,
     SFT_ESC,  CTL_A,  GUI_S,  SFT_D,  ALT_F,   KC_G,                                   XXXXXXX,  ALT_H,  SFT_J,  GUI_K,  CTL_L, SFT_SC,
     KC_LCTL,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, NUMNAV, KC_NUM,    KC_CAPS,NUMNAV,XXXXXXX,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,
                              KC_APP,  FKEYS,NUM_BSP,SYM_SPC, KC_ENT,    KC_ENT,SYM_SPC,NUM_DEL,  FKEYS, KC_APP
    ),

/*
 * NUMNAV Layer: Left Numpad - Right Navigation
 *
 * ,-------------------------------------------.                              ,------------------------------------------.
 * |        |   *  |   7  |   8  |   9  |   +  |                              |      | Break|M Prev|M Play|M Next| VolUp |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+-------|
 * |        |Ctrl//| GUI/4|Shft/5| Alt/6|   -  |                              |      | Alt/←|Shft/↓| GUI/↑|Ctrl/→|  Shft/|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |  VolDn|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-------|
 * |        |   0  |   1  |   2  |   3  |   .  |      |      |  |      |      |      | Home | PgDn | PgUp |  End | VolMut|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+---------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMNAV] = LAYOUT(
     _______,KC_PAST,  KC_P7,  KC_P8,  KC_P9,KC_PPLS,                                   _______,KC_BRK ,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLU,
     _______,CTL_SLS, GUI_P4, SFT_P5, ALT_P6,KC_PMNS,                                   _______,ALT_LFT,SFT_DWN, GUI_UP,CTL_RGT,SFT_VLD,
     _______,  KC_P0,  KC_P1,  KC_P2,  KC_P3,KC_PDOT,_______,_______,   _______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP, KC_END,KC_MUTE,
                             _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
    ),

/*
 * SYMBOL Layer: Symbols
 *
 * ,-------------------------------------------.                              ,------------------------------------------.
 * |    `   |   `  |   &  |   *  |      |   +  |                              |      |      |   "  |   '  |      |       |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+-------|
 * |        |Ctrl/~| GUI/#|Shft/%| Alt/^|   -  |                              |      | Alt/[|Shft/]| GUI/(|Ctrl/)|Shft/' |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-------|
 * |        |   _  |   !  |   @  |   $  |   =  |      |      |  |      |      |      |      |  |   |  {   |  }   |   \   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+---------------------'
 *                        |      |      |NUMNAV|      |      |  |      |      |NUMNAV|      |      |
 *                        |      |      | /Del |      |      |  |      |      |/BkSpc|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOL] = LAYOUT(
     _______, KC_GRV,KC_AMPR,KC_ASTR,XXXXXXX,KC_PLUS,                                   _______,XXXXXXX,KC_DQUO,KC_QUOT,XXXXXXX,XXXXXXX,
     _______,CTL_TLD,GUI_HSH,SFT_PRC,ALT_CRC,KC_MINS,                                   _______,ALT_LBR,SFT_RBR,GUI_LPN,CTL_RPN,KC_RSFT,
     _______,KC_UNDS,KC_EXLM, KC_AT , KC_DLR, KC_EQL,_______,_______,   _______,_______,_______,XXXXXXX,KC_PIPE,KC_LCBR,KC_RCBR,KC_BSLS,
                             _______,_______,NUM_DEL,_______,_______,   _______,_______,NUM_BSP,_______,_______
   ),

/*
 * Function Layer: Function keys
 *
 * ,------------------------------------------.                              ,------------------------------------------.
 * |       |      | Home |   ↑  |  End |      |                              |      |  F1  |  F2  |  F3  |  F4  | PrtScr|
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+-------|
 * |       | Ctrl | GUI/←|Shft/↓| Alt/→|      |                              |      |Alt/F5|Sft/F6|GUI/F7|Ctl/F8|Sft/Ins|
 * |-------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-------|
 * |       |      | PgDn |      | PgUp |      |      |      |  |      |      |      |  F9  |  F10 |  F11 |  F12 | ScrLk |
 * `---------------------+------+------+------+------+------|  |------+------+------+------+------+---------------------'
 *                       |      |      |      |      |      |  |      |      |      |      |      |
 *                       `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
     _______,XXXXXXX,KC_HOME,  KC_UP, KC_END,XXXXXXX,                                   _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,KC_PSCR,
     _______,KC_LCTL,GUI_LFT,SFT_DWN,ALT_RGT,XXXXXXX,                                   _______, ALT_F5, SFT_F6, GUI_F7, CTL_F8,SFT_INS,
     _______,XXXXXXX,KC_PGDN,XXXXXXX,KC_PGUP,XXXXXXX,_______,_______,   _______,_______,_______,  KC_F9, KC_F10, KC_F11, KC_F12,KC_SCRL,
                             _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
//     ),
};

/* LED LOCK and LAYER indicators.
 * Repurpose SCL(D0) and SDA(D1) pins for LED indicators.
 * Left (master) board for Layer indicators.
 * Right(slave) board for Num and Caps Lock indicators.
 * (Was unable to get Layers to indicate on the slave side. Even with 
 * SPLIT_LAYER_STATE_ENABLE defined in config.h.)
 */
void keyboard_pre_init_user(void) {
    gpio_set_pin_output(D0);  // initialize D0 for LED (master & slave sides)
    gpio_set_pin_output(D1);  // initialize D1 for LED (master & slave sides)
};

layer_state_t layer_state_set_user(layer_state_t layer_state) {
    if (is_keyboard_master()) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                gpio_write_pin_low(D0);
                gpio_write_pin_low(D1);
                break;
            case _NUMNAV:
                gpio_write_pin_high(D0);
                gpio_write_pin_low(D1);
                break;
            case _SYMBOL:
                gpio_write_pin_low(D0);
                gpio_write_pin_low(D1);
                break;
            case _FUNCTION:
                gpio_write_pin_low(D0);
                gpio_write_pin_high(D1);
                break;
            default:
                gpio_write_pin_low(D0);
                gpio_write_pin_low(D1);
                break;
        }
    }
    return layer_state;
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (!is_keyboard_master()) {
        if(res) {
            // gpio_write_pin sets the pin high for 1 and low for 0.
            gpio_write_pin(D1, led_state.num_lock);
            gpio_write_pin(D0, led_state.caps_lock);
        }
    }
    return res;
}

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NUMNAV:
                oled_write_P(PSTR("Num-Nav\n"), false);
                break;
            case _SYMBOL:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
