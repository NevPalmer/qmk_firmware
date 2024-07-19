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
    _DVORAK,
    _COLEMAK_DH,
    _NUMSYM,
    _NAVSYM,
    _FUNCTION,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)

#define NAVSYM   TT(_NAVSYM)
#define NUMSYM   TT(_NUMSYM)
#define FKEYS    MO(_FUNCTION)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_SLSH MT(MOD_RCTL, KC_SLSH)

// For QWERTY layer
#define GUI_A    MT(MOD_LGUI, KC_A)
#define ALT_S    MT(MOD_LALT, KC_S)
#define CTL_D    MT(MOD_LCTL, KC_D)
#define SFT_F    MT(MOD_LSFT, KC_F)
#define SFT_J    MT(MOD_RSFT, KC_J)
#define CTL_K    MT(MOD_RCTL, KC_K)
#define ALT_L    MT(MOD_LALT, KC_L)
#define GUI_SC   MT(MOD_RGUI, KC_SCLN)

// For Dvorak layer
#define ALT_O    MT(MOD_LALT, KC_O)
#define LCTL_E   MT(MOD_LCTL, KC_E)
#define SFT_U    MT(MOD_LSFT, KC_U)
#define SFT_H    MT(MOD_RSFT, KC_H)
#define CNTL_T   MT(MOD_RCTL, KC_T)
#define ALT_N    MT(MOD_LALT, KC_N)
#define GUI_S    MT(MOD_RGUI, KC_S)

// For Colemak layer
#define ALT_R    MT(MOD_LALT, KC_R)
#define CTL_S    MT(MOD_LCTL, KC_S)
#define SHFT_T   MT(MOD_LSFT, KC_T)
#define SFT_N    MT(MOD_RSFT, KC_N)
#define RCTL_E   MT(MOD_RCTL, KC_E)
#define ALT_I    MT(MOD_LALT, KC_I)
#define GUI_O    MT(MOD_RGUI, KC_O)

// For NUMSYM layer
#define GUI_EXL  MT(MOD_LGUI, KC_EXLM)
#define ALT_AT   MT(MOD_LALT, KC_AT)
#define CTL_HAS  MT(MOD_LCTL, KC_HASH)
#define SFT_DLR  MT(MOD_LSFT, KC_DLR)
#define SFT_P4   MT(MOD_LSFT, KC_P4)
#define CTL_P5   MT(MOD_LCTL, KC_P5)
#define ALT_P6   MT(MOD_LALT, KC_P6)
#define GUI_PPLS  MT(MOD_LGUI, KC_PPLS)

// For NAVSYM layer
#define GUI_PDN  MT(MOD_LGUI, KC_PGDN)
#define ALT_LFT  MT(MOD_LALT, KC_LEFT)
#define CTL_DWN  MT(MOD_LCTL, KC_DOWN)
#define SFT_RGT  MT(MOD_LSFT, KC_RGHT)
#define SFT_AMP  MT(MOD_RSFT, KC_AMPR)
#define CTL_AST  MT(MOD_RCTL, KC_ASTR)
#define ALT_LPR  MT(MOD_LALT, KC_LPRN)
#define GUI_RPR  MT(MOD_RGUI, KC_RPRN)

// Note:
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// Intercepts non-basic keycodes for use with mod-tap.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_EXL:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EXLM); // Send KC_EXLM on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case ALT_AT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_AT); // Send KC_AT on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case CTL_HAS:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_HASH); // Send KC_HASH on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case SFT_DLR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DLR); // Send KC_DLR on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case SFT_AMP:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_AMPR); // Send KC_AMPR on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case CTL_AST:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_ASTR); // Send KC_ASTR on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case ALT_LPR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN); // Send KC_LPRN on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case GUI_RPR:
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
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc| GUI/A| Alt/S|Ctrl/D|Shft/F|   G  |                              |   H  |Shft/J|Ctrl/K| Alt/L|GUI/;:|Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |CapsLk|      |  |      |F-keys|   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LGUI | LAlt | NAV  | Space| Enter|  | Enter| Space|  NUM | AltGr| RGUI/|
 *                        |      |      | SYM  |      |      |  |      |      |  SYM |      | Menu |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_TAB  ,  KC_Q ,  KC_W  ,  KC_E  ,   KC_R ,   KC_T ,                                         KC_Y ,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     CTL_ESC , GUI_A , ALT_S  , CTL_D  ,  SFT_F ,   KC_G ,                                         KC_H ,  SFT_J , CTL_K ,  ALT_L ,GUI_SC ,CTL_QUOT,
     KC_LSFT ,  KC_Z ,  KC_X  ,  KC_C  ,   KC_V ,   KC_B , KC_CAPS,XXXXXXX,     XXXXXXX, FKEYS  ,  KC_N ,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                KC_LGUI, KC_LALT,  NAVSYM, KC_SPC , KC_ENT,     KC_ENT , KC_SPC , NUMSYM, KC_RALT,KC_APP
    ),

/*
 * Base Layer: Dvorak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   | ' "  | , <  | . >  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc| GUI/A| Alt/O|Ctrl/E|Shft/U|   I  |                              |   D  |Shft/H|Ctrl/T| Alt/N| GUI/S|Ctrl//? |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift | ; :  |   Q  |   J  |   K  |   X  |CapsLk|      |  |      |F-keys|   B  |   M  |   W  |   V  |   Z  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LGUI | LAlt | NAV  | Space| Enter|  | Enter| Space|  NUM | AltGr| RGUI/|
 *                        |      |      | SYM  |      |      |  |      |      |  SYM |      | Menu |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_DVORAK] = LAYOUT(
     KC_TAB  ,KC_QUOTE,KC_COMM,  KC_DOT,   KC_P ,   KC_Y ,                                         KC_F ,   KC_G ,  KC_C ,   KC_R ,  KC_L , KC_BSPC,
     CTL_ESC , GUI_A , ALT_O  , LCTL_E ,  SFT_U ,   KC_I ,                                         KC_D ,  SFT_H ,CNTL_T ,  ALT_N , GUI_S ,CTL_SLSH,
     KC_LSFT ,KC_SCLN, KC_Q   ,  KC_J  ,   KC_K ,   KC_X , KC_CAPS,XXXXXXX,     XXXXXXX, FKEYS  ,  KC_B ,   KC_M ,  KC_W ,   KC_V ,  KC_Z , KC_RSFT,
                                KC_LGUI, KC_LALT,  NAVSYM, KC_SPC , KC_ENT,     KC_ENT , KC_SPC , NUMSYM, KC_RALT,KC_APP
    ),

/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc| GUI/A| Alt/R|Ctrl/S|Shft/T|   G  |                              |   M  |Shft/N|Ctrl/E| Alt/I| GUI/O|Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |CapsLk|      |  |      |F-keys|   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LGUI | LAlt | NAV  | Space| Enter|  | Enter| Space|  NUM | AltGr| RGUI/|
 *                        |      |      | SYM  |      |      |  |      |      |  SYM |      | Menu |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                         KC_J ,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSPC,
     CTL_ESC , GUI_A , ALT_R  , CTL_S  , SHFT_T ,   KC_G ,                                         KC_M ,  SFT_N ,RCTL_E ,  ALT_I , GUI_O ,CTL_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_CAPS,XXXXXXX,     XXXXXXX, FKEYS  ,  KC_K ,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                KC_LGUI, KC_LALT,  NAVSYM, KC_SPC , KC_ENT,     KC_ENT , KC_SPC , NUMSYM, KC_RALT,KC_APP
    ),

/*
 * NumSym Layer: Left Numbers and symbols - Right Numpad
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |   1  |   2  |   3  |   4  |   5  |                              |   /  |   7  |   8  |   9  |   -  | Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   | GUI/!| Alt/@|Ctrl/#|Shft/$|   %  |                              |   *  |Shft/4|Ctrl/5| Alt/6| GUI/+| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | Break|   _  |   =  |   -  |   +  |NumLck|      |  |      |ScrLck|   0  |   1  |   2  |   3  |   .  | PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMSYM] = LAYOUT(
      KC_GRV ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                                     KC_PSLS,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PMNS,  KC_DEL,
      KC_TILD, GUI_EXL, ALT_AT , CTL_HAS, SFT_DLR, KC_PERC,                                     KC_PAST, SFT_P4 , CTL_P5 , ALT_P6 ,GUI_PPLS,  KC_INS,
      _______, KC_BRK , KC_UNDS, KC_EQL , KC_MINS, KC_PLUS, KC_NUM , _______, _______, KC_SCRL,  KC_P0 ,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PDOT, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * NavSym Layer: Left Media, Navigation - Right Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | PgUp | Home |   ↑  | End  | VolUp|                              |   6  |  7   |  8   |  9   |  0   | Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |GUI/PD| Alt/←|Ctrl/↓|Shft/→| VolDn|                              |   ^  |Shft/&|Ctrl *| Alt/(|GUI/) |   |    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |M Prev|M Play|M Next|VolMut|NumLck|      |  |      |ScrLck|   \  |  {   |  }   |  [   |  ]   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAVSYM] = LAYOUT(
      _______, KC_PGUP, KC_HOME,  KC_UP , KC_END , KC_VOLU,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_DEL ,
      _______, GUI_PDN, ALT_LFT, CTL_DWN, SFT_RGT, KC_VOLD,                                     KC_CIRC, SFT_AMP, CTL_AST, ALT_LPR, GUI_RPR, KC_PIPE,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_NUM , _______, _______, KC_SCRL, KC_BSLS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |QWERTY|  F7  |  F8  |  F9  | F12  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Shift| Ctrl |  Alt |  GUI |      |                              |Dvorak|  F4  |  F5  |  F6  |  F11 |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |Colmak|  F1  |  F2  |  F3  |  F10 |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     QWERTY ,  KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_F12, _______,
      _______, _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,                                     DVORAK ,  KC_F4 ,  KC_F5 ,  KC_F6 ,  KC_F11, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, COLEMAK,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F10, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

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
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NUMSYM:
                oled_write_P(PSTR("Num-Sym\n"), false);
                break;
            case _NAVSYM:
                oled_write_P(PSTR("Nav-Sym\n"), false);
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
