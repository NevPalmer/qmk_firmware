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
    _QWERTY_NEV = 0,
    _NUMNAV_NEV,
    _SYMBOL_NEV,
    _FUNCTION_NEV,
    _QWERTY,
    _NUMNAV,
    _SYMBOL,
    _FUNCTION,
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define QWTNEV   DF(_QWERTY_NEV)

#define SYMBOL   TT(_SYMBOL)
#define NUMNAV   TG(_NUMNAV)
#define FKEYS    MO(_FUNCTION)
#define SYMNEV   TT(_SYMBOL_NEV)
#define NUMNEV   TG(_NUMNAV_NEV)
#define FKYNEV   MO(_FUNCTION_NEV)

#define ALT_ESC MT(MOD_LALT, KC_ESC)

// For Thumb Cluster
#define LCTL_ENT MT(MOD_LCTL, KC_ENT)
#define RCTL_ENT MT(MOD_RCTL, KC_ENT)
#define  GUI_MNU MT(MOD_LGUI, KC_APP)
#define  NUM_DEL LT(_NUMNAV, KC_DEL)
#define  NUM_BSP LT(_NUMNAV, KC_BSPC)
#define  SYM_SPC LT(_SYMBOL, KC_SPC)
#define  NUM_D_N LT(_NUMNAV_NEV, KC_DEL)
#define  NUM_B_N LT(_NUMNAV_NEV, KC_BSPC)
#define  SYM_S_N LT(_SYMBOL_NEV, KC_SPC)

// For QWERTY layer

// For QWERTY_NEV layer
#define ALT_SC   MT(MOD_RALT, KC_SCLN)
#define SFT_SL   MT(MOD_RSFT, KC_SLSH)

// For NUMNAV layer

// For NUMNAV_NEV layer
#define ALT_VLD  MT(MOD_RALT, KC_VOLD)
#define SFT_MUT  MT(MOD_RSFT, KC_MUTE)

// For SYMBOL layer

// For SYMBOL_NEV layer
#define SFT_BSL  MT(MOD_RSFT, KC_BSLS)

// For FUNCTION layer
#define ALT_INS  MT(MOD_RALT, KC_INS)
#define SFT_SCL  MT(MOD_RSFT, KC_SCRL)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 */
    [_QWERTY] = LAYOUT(
// ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
// │   Tab    │    Q     │    W     │    E     │    R     │    T     │                                              │    Y     │    U     │    I     │    O     │    P     │          │
    KC_TAB    ,KC_Q      ,KC_W      ,KC_E      ,KC_R      ,KC_T      ,                                               KC_Y      ,KC_U      ,KC_I      ,KC_O      ,KC_P      ,XXXXXXX   ,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
// │ Alt/Esc  │    A     │    S     │    D     │    F     │    G     │                                              │    H     │    J     │    K     │    L     │    ;:    │   Alt    │
    ALT_ESC   ,KC_A      ,KC_S      ,KC_D      ,KC_F      ,KC_G      ,                                               KC_H      ,KC_J      ,KC_K      ,KC_L      ,KC_SCLN   ,KC_RALT   ,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐  ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
// │  Shift   │    Z     │    X     │    C     │    V     │    B     │NumNav Lk │ NumLock  │  │ NumLock  │NumNav Lk │    N     │    M     │    ,<    │    .>    │    /?    │   Shft   │
    KC_LSFT   ,KC_Z      ,KC_X      ,KC_C      ,KC_V      ,KC_B      ,NUMNEV    ,KC_NUM    ,   KC_CAPS   ,NUMNEV    ,KC_N      ,KC_M      ,KC_COMM   ,KC_DOT    ,KC_SLSH   ,KC_RSFT   ,
// └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
//                                  │ GUI/     │ Function │ NumNav/  │ Symbols/ │  Ctrl/   │  │  Ctrl/   │ Symbols/ │ NumNav/  │ Function │ GUI/     │
//                                  │ App Menu │ Keys     │ Backspace│ Space    │  Enter   │  │  Enter   │ Space    │ Delete   │ Keys     │ App Menu │
                                     GUI_MNU   ,FKYNEV    ,NUM_BSP   ,SYM_SPC   ,LCTL_ENT  ,   RCTL_ENT  ,SYM_SPC   ,NUM_DEL   ,FKYNEV    ,GUI_MNU
//                                  └──────────┴──────────┴──────────┴──────────┴──────────┘  └──────────┴──────────┴──────────┴──────────┴──────────┘
    ),

/*
 * Base Layer: QWERTY_NEV
*/
    [_QWERTY_NEV] = LAYOUT(
// ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
// │   Tab    │    Q     │    W     │    E     │    R     │    T     │                                              │          │    Y     │    U     │    I     │    O     │    P     │
    KC_TAB    ,KC_Q      ,KC_W      ,KC_E      ,KC_R      ,KC_T      ,                                               XXXXXXX   ,KC_Y      ,KC_U      ,KC_I      ,KC_O      ,KC_P      ,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
// │ Alt/Esc  │    A     │    S     │    D     │    F     │    G     │                                              │          │    H     │    J     │    K     │    L     │  Alt ;:  │
    ALT_ESC   ,KC_A      ,KC_S      ,KC_D      ,KC_F      ,KC_G      ,                                               XXXXXXX   ,KC_H      ,KC_J      ,KC_K      ,KC_L      ,ALT_SC    ,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐  ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
// │  Shift   │    Z     │    X     │    C     │    V     │    B     │NumNav Lk │ NumLock  │  │ NumLock  │NumNav Lk │          │    N     │    M     │    ,<    │    .>    │  Sft /?  │
    KC_LSFT   ,KC_Z      ,KC_X      ,KC_C      ,KC_V      ,KC_B      ,NUMNAV    ,KC_NUM    ,   KC_CAPS   ,NUMNAV    ,XXXXXXX   ,KC_N      ,KC_M      ,KC_COMM   ,KC_DOT    ,SFT_SL    ,
// └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
//                                  │ GUI/     │ Function │ NumNav/  │ Symbols/ │  Ctrl/   │  │  Ctrl/   │ Symbols/ │ NumNav/  │ Function │ GUI/     │
//                                  │ App Menu │ Keys     │ Backspace│ Space    │  Enter   │  │  Enter   │ Space    │ Delete   │ Keys     │ App Menu │*/
                                     GUI_MNU   ,FKEYS     ,NUM_B_N   ,SYM_S_N   ,LCTL_ENT  ,   RCTL_ENT  ,SYM_S_N   ,NUM_D_N   ,FKEYS     ,GUI_MNU
//                                  └──────────┴──────────┴──────────┴──────────┴──────────┘  └──────────┴──────────┴──────────┴──────────┴──────────┘*/
    ),

/*
 * NUMNAV Layer: Left Numpad - Right Navigation
 *
 */
    [_NUMNAV] = LAYOUT(
/* ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
 * │          │    *     │    7     │    8     │    9     │    +     │                                              │  Break   │   Prev   │Play-Pause│   Next   │  VolUp   │          │*/
    _______   ,KC_PAST   ,KC_P7     ,KC_P8     ,KC_P9     ,KC_PPLS   ,                                               KC_BRK    ,KC_MPRV   ,KC_MPLY   ,KC_MNXT   ,KC_VOLU   ,_______   ,
/* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
 * │          │    /     │    4     │    5     │    6     │    -     │                                              │    ←     │    ↓     │    ↑     │    →     │  VolDn   │          │*/
    _______   ,KC_PSLS   ,KC_P4     ,KC_P5     ,KC_P6     ,KC_PMNS   ,                                               KC_LEFT   ,KC_DOWN   ,KC_UP     ,KC_RGHT   ,KC_VOLD   ,_______   ,
/* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐  ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
 * │          │    0     │    1     │    2     │    3     │    .     │          │          │  │          │          │   Home   │ Page Up  │ Page Dn  │   End    │   Mute   │          │*/
    _______   ,KC_P0     ,KC_P1     ,KC_P2     ,KC_P3     ,KC_PDOT   ,_______   ,_______   ,   _______   ,_______   ,KC_HOME   ,KC_PGDN   ,KC_PGUP   , KC_END   ,KC_MUTE   ,_______   ,
/* └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
 *                                  │          │          │          │          │          │  │          │          │          │          │          │*/
                                     _______   ,_______   ,_______   ,_______   ,_______   ,   _______   ,_______   ,_______   ,_______   ,_______
/*                                  └──────────┴──────────┴──────────┴──────────┴──────────┘  └──────────┴──────────┴──────────┴──────────┴──────────┘*/
    ),

/*
 * NUMNAV_NEV Layer: Left Numpad - Right Navigation
 */
    [_NUMNAV_NEV] = LAYOUT(
/* ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
 * │          │    *     │    7     │    8     │    9     │    +     │                                              │          │  Break   │   Prev   │Play-Pause│   Next   │  VolUp   │*/
    _______   ,KC_PAST   ,KC_P7     ,KC_P8     ,KC_P9     ,KC_PPLS   ,                                               _______   ,KC_BRK    ,KC_MPRV   ,KC_MPLY   ,KC_MNXT   ,KC_VOLU   ,
/* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
 * │          │    /     │    4     │    5     │    6     │    -     │                                              │          │    ←     │    ↓     │    ↑     │    →     │ Alt VolDn│*/
    _______   ,KC_PSLS   ,KC_P4     ,KC_P5     ,KC_P6     ,KC_PMNS   ,                                               _______   ,KC_LEFT   ,KC_DOWN   ,KC_UP     ,KC_RGHT   ,ALT_VLD   ,
/* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐  ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
 * │          │    0     │    1     │    2     │    3     │    .     │          │          │  │          │          │          │   Home   │ Page Up  │ Page Dn  │   End    │ Shft Mute│*/
    _______   ,KC_P0     ,KC_P1     ,KC_P2     ,KC_P3     ,KC_PDOT   ,_______   ,_______   ,   _______   ,_______   ,_______   ,KC_HOME   ,KC_PGDN   ,KC_PGUP   , KC_END   ,SFT_MUT   ,
/* └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
 *                                  │          │          │          │          │          │  │          │          │          │          │          │*/
                                     _______   ,_______   ,_______   ,_______   ,_______   ,   _______   ,_______   ,_______   ,_______   ,_______
/*                                  └──────────┴──────────┴──────────┴──────────┴──────────┘  └──────────┴──────────┴──────────┴──────────┴──────────┘*/
    ),

/*
 * SYMBOL Layer: Symbols
 */
    [_SYMBOL] = LAYOUT(
/* ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
 * │          │    `     │    &     │    *     │          │    +     │                                              │          │    "     │    '     │          │          │          │*/
    _______   ,KC_GRV    ,KC_AMPR   ,KC_ASTR   ,XXXXXXX   ,KC_PLUS,                                                  XXXXXXX   ,KC_DQUO   ,KC_QUOT   ,XXXXXXX   ,XXXXXXX   ,_______   ,
/* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                              ┼──────────┼──────────┼──────────┼──────────┼──────────├──────────┤
 * │          │    ~     │    $     │    %     │    ^     │    -     │                                              │    [     │    ]     │    (     │    )     │          │          │*/
    _______   ,KC_TILD   ,KC_DLR    ,KC_PERC   ,KC_CIRC   ,KC_MINS,                                                  KC_LBRC   ,KC_RBRC   ,KC_LPRN   ,KC_RPRN   ,XXXXXXX   ,_______   ,
/* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐  ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
 * │          │    _     │    !     │    @     │    #     │    =     │          │          │  │          │          │          │    |     │    {     │    }     │    \     │          │*/
    _______   ,KC_UNDS   ,KC_EXLM   ,KC_AT     ,KC_HASH   ,KC_EQL    ,_______   ,_______   ,   _______   ,_______   ,XXXXXXX   ,KC_PIPE   ,KC_LCBR   ,KC_RCBR   ,KC_BSLS   ,_______   ,
/* └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
 *                                  │          │          │ NumNav/  │          │          │  │          │          │ NumNav/  │          │          │
 *                                  │          │          │ Delete   │          │          │  │          │          │ Backspace│          │          │*/
                                     _______   ,_______   ,NUM_DEL   ,_______   ,_______   ,   _______   ,_______   ,NUM_BSP   ,_______   ,_______
/*                                  └──────────┴──────────┴──────────┴──────────┴──────────┘  └──────────┴──────────┴──────────┴──────────┴──────────┘*/
    ),

/*
 * SYMBOL_NEV Layer: Symbols
 */
    [_SYMBOL_NEV] = LAYOUT(
/* ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
 * │          │    `     │    &     │    *     │          │    +     │                                              │          │          │    "     │    '     │          │          │*/
    _______   ,KC_GRV    ,KC_AMPR   ,KC_ASTR   ,XXXXXXX   ,KC_PLUS,                                                  _______   ,XXXXXXX   ,KC_DQUO   ,KC_QUOT   ,XXXXXXX   ,XXXXXXX   ,
/* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
 * │          │    ~     │    $     │    %     │    ^     │    -     │                                              │          │    [     │    ]     │    (     │    )     │          │*/
    _______   ,KC_TILD   ,KC_DLR    ,KC_PERC   ,KC_CIRC   ,KC_MINS,                                                  _______   ,KC_LBRC   ,KC_RBRC   ,KC_LPRN   ,KC_RPRN   ,KC_RALT   ,
/* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐  ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
 * │          │    _     │    !     │    @     │    #     │    =     │          │          │  │          │          │          │          │    |     │    {     │    }     │  Shft \  │*/
    _______   ,KC_UNDS   ,KC_EXLM   ,KC_AT     ,KC_HASH   ,KC_EQL    ,_______   ,_______   ,   _______   ,_______   ,_______   ,XXXXXXX   ,KC_PIPE   ,KC_LCBR   ,KC_RCBR   ,SFT_BSL   ,
/* └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
 *                                  │          │          │ NumNav/  │          │          │  │          │          │ NumNav/  │          │          │
 *                                  │          │          │ Delete   │          │          │  │          │          │ Backspace│          │          │*/
                                     _______   ,_______   ,NUM_D_N   ,_______   ,_______   ,   _______   ,_______   ,NUM_B_N   ,_______   ,_______
/*                                  └──────────┴──────────┴──────────┴──────────┴──────────┘  └──────────┴──────────┴──────────┴──────────┴──────────┘*/
    ),

/*
 * Function Layer: Function keys
 */
    [_FUNCTION] = LAYOUT(
/* ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
 * │          │          │   Home   │    ↑     │ Page Up  │          │                                              │QWERTY Lyr│    F1    │    F2    │    F3    │    F4    │ Prt Scrn │*/
     _______  ,XXXXXXX   ,KC_HOME   ,KC_UP     ,KC_PGUP   ,XXXXXXX   ,                                               QWERTY    ,KC_F1     ,KC_F2     ,KC_F3     ,KC_F4     ,KC_PSCR   ,
/* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
 * │          │  Shift   │    ←     │    ↓     │    →     │          │                                              │Nev Lyr   │    F5    │    F6    │    F7    │    F8    │ Alt/Ins  │*/
     _______  ,KC_LSFT   ,KC_LEFT   ,KC_DOWN   ,KC_RGHT   ,XXXXXXX   ,                                               QWTNEV    ,KC_F5     ,KC_F6     ,KC_F7     ,KC_F8     ,ALT_INS   ,
/* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐  ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
 * │          │          │   End    │          │ Page Dn  │          │          │          │  │          │          │          │    F9    │    F10   │    F11   │    F12   │Sft ScLck │*/
     _______  ,XXXXXXX   ,KC_END    ,XXXXXXX   ,KC_PGDN   ,XXXXXXX   ,_______   ,_______   ,   _______   ,_______   ,_______   ,KC_F9     ,KC_F10    ,KC_F11    ,KC_F12    ,SFT_SCL   ,
/* └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
 *                                  │          │          │          │          │          │  │          │          │          │          │          │*/
                                     _______   ,_______   ,_______   ,_______   ,_______   ,   _______   ,_______   ,_______   ,_______   ,_______
/*                                  └──────────┴──────────┴──────────┴──────────┴──────────┘  └──────────┴──────────┴──────────┴──────────┴──────────┘*/
    ),

    [_FUNCTION_NEV] = LAYOUT(
/* ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
 * │          │          │   Home   │    ↑     │ Page Up  │          │                                              │QWERTY Lyr│    F1    │    F2    │    F3    │    F4    │ Prt Scrn │*/
     _______  ,XXXXXXX   ,KC_HOME   ,KC_UP     ,KC_PGUP   ,XXXXXXX   ,                                               QWERTY    ,KC_F1     ,KC_F2     ,KC_F3     ,KC_F4     ,KC_PSCR   ,
/* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
 * │          │  Shift   │    ←     │    ↓     │    →     │          │                                              │Nev Lyr   │    F5    │    F6    │    F7    │    F8    │ Alt/Ins  │*/
     _______  ,KC_LSFT   ,KC_LEFT   ,KC_DOWN   ,KC_RGHT   ,XXXXXXX   ,                                               QWTNEV    ,KC_F5     ,KC_F6     ,KC_F7     ,KC_F8     ,ALT_INS   ,
/* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐  ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
 * │          │          │   End    │          │ Page Dn  │          │          │          │  │          │          │          │    F9    │    F10   │    F11   │    F12   │Sft ScLck │*/
     _______  ,XXXXXXX   ,KC_END    ,XXXXXXX   ,KC_PGDN   ,XXXXXXX   ,_______   ,_______   ,   _______   ,_______   ,_______   ,KC_F9     ,KC_F10    ,KC_F11    ,KC_F12    ,SFT_SCL   ,
/* └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
 *                                  │          │          │          │          │          │  │          │          │          │          │          │*/
                                     _______   ,_______   ,_______   ,_______   ,_______   ,   _______   ,_______   ,_______   ,_______   ,_______
/*                                  └──────────┴──────────┴──────────┴──────────┴──────────┘  └──────────┴──────────┴──────────┴──────────┴──────────┘*/
    ),

// /*
//  * Layer template
//  */
//     [_LAYERINDEX] = LAYOUT(
// /* ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
//  * │          │          │          │          │          │          │                                              │          │          │          │          │          │          │*/
//     _______   ,_______   ,_______   ,_______   ,_______   ,_______                                                  ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,
// /* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
//  * │          │          │          │          │          │          │                                              │          │          │          │          │          │          │*/
//     _______   ,_______   ,_______   ,_______   ,_______   ,_______                                                  ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,
// /* ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐  ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
//  * │          │          │          │          │          │          │          │          │  │          │          │          │          │          │          │          │          │*/
//     _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,   _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,
// /* └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
//  *                                  │          │          │          │          │          │  │          │          │          │          │          │*/
//                                      _______   ,_______   ,_______   ,_______   ,_______   ,   _______   ,_______   ,_______   ,_______   ,_______
// /*                                  └──────────┴──────────┴──────────┴──────────┴──────────┘  └──────────┴──────────┴──────────┴──────────┴──────────┘*/
//     ),
};

/* LED LOCK and LAYER indicators.
 * Repurpose SCL(D0) and SDA(D1) pins for LED indicators.
 * Left (master) board for Layer indicators.
 * Right(slave) board for Num and Caps Lock indicators.
 * (Unable to get Layers to indicate on the slave side. Even with 
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
            case _QWERTY_NEV:
                gpio_write_pin_low(D0);
                gpio_write_pin_low(D1);
                break;
            case _NUMNAV_NEV:
                gpio_write_pin_high(D0);
                gpio_write_pin_low(D1);
                break;
            case _SYMBOL_NEV:
                gpio_write_pin_low(D0);
                gpio_write_pin_low(D1);
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
