#include QMK_KEYBOARD_H
#include "version.h"
#include "debug.h"
#include "action_layer.h"
#include "action_code.h"

enum layers {
    BASE, // default layer
    MOUSE,
    KEY_NAV,
    KEY_SEL,
    NUMBER,
    SYMBOL, // symbols
    GAME,
    RSMITH,
    BRACKETS,  // media keys
    SHORTCUTS,
    SHELL_NAV
};

enum macros {
  MC_COPY_LINE,
  MC_CUT_LINE,
  MC_PASTE_LINE,
  MC_NEW_SEARCH_TAB,
  SCREEN_TAB_LEFT,
  SCREEN_TAB_RIGHT,
  SCREEN_NEW_TAB,
  SWITCH_NDS,
  SCREEN_COPY_MODE,
  SCREEN_PASTE,
  OPEN_CLOSE_PAREN,
  OPEN_CLOSE_BRACKET,
  OPEN_CLOSE_CURLY,
  OPEN_CLOSE_SINGLE_QUOTE,
  OPEN_CLOSE_DOUBLE_QUOTE,
  SHELL_RECALL_LAST_ARG_REMOVE_FIRST_COMMAND,
  SEMICOLON_NEWLINE,
  END_NEWLINE,
  GMAIL,
  VS_EMAIL,
  RS_AS,
  GAME_AS

};
enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // // left hand
        // MT(MOD_LSFT, KC_ESC),                    KC_F1,          KC_F2,       KC_F3,        KC_F4,       KC_F5,       MEH_T(KC_F6),
        // KC_TAB,                    KC_QUOT,        KC_COMM,     KC_DOT,       KC_P,        KC_Y,        MO(KEY_SEL),
        // MO(BRACKETS),              KC_A,           KC_O,        KC_E,         KC_U,        KC_I,
        // LM(MOUSE, MOD_LALT),             KC_SCLN,        KC_Q,        KC_J,         KC_K,        KC_X,        MO(KEY_NAV),
        //            MO(MOUSE),OSM(MOD_LCTL), OSM(MOD_LALT),MO(SYMBOL),MO(NUMBER),
        //                                // thumb cluster
        //                                        SFT_T(KC_PAUSE), LCTL(KC_S),
        //                                                   RCTL(KC_DEL),
        //                                        KC_BSPC,RCTL(KC_BSPC),KC_DEL,
        //Original ^^

         // left hand
        MT(MOD_LSFT, KC_ESC),                    KC_F1,          KC_F2,       KC_F3,        KC_F4,       KC_F5,       MEH_T(KC_F6),
        KC_TAB,                    KC_QUOT,        KC_COMM,     KC_DOT,       KC_P,        KC_Y,        MO(KEY_SEL),
        OSM(MOD_LCTL),              KC_A,           KC_O,        KC_E,         KC_U,        KC_I,
        KC_LWIN,             KC_SCLN,        KC_Q,        KC_J,         KC_K,        KC_X,        MO(KEY_NAV),
                   MO(MOUSE),LM(MOUSE, MOD_LALT), OSM(MOD_LALT),MO(SYMBOL),MO(NUMBER),
                                       // thumb cluster
                                               SFT_T(KC_PAUSE), LCTL(KC_S),
                                                          RCTL(KC_DEL),
                                               KC_BSPC,RCTL(KC_BSPC),KC_DEL,



        // right hand
             KC_F7,       KC_F8,       KC_F9,       KC_F10,        KC_F11,       KC_F12,       KC_BSLS,
             KC_PGUP,     KC_F,        KC_G,        KC_C,          KC_R,         KC_L,         KC_SLSH,
                          KC_D,        KC_H,        KC_T,          KC_N,         KC_S,         KC_MINS,
             KC_PGDN,     KC_B,        KC_M,        KC_W,          KC_V,         KC_Z,         MO(BRACKETS),
                                  // lower keys - browser tab control
                                  RSFT(RCTL(KC_TAB)), RCTL(KC_TAB), RCTL(KC_T), LALT(KC_LEFT), RCTL(KC_W),
             // thumb cluster
             KC_LEFT,KC_RIGHT,
             KC_UP,
             KC_DOWN,KC_ENT, KC_SPC
    ),

// shell navigation layer
[SHELL_NAV] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               LALT(KC_D),
                               KC_TRNS,RCTL(KC_W),KC_TRNS,
       // right hand
       KC_TRNS,    KC_TRNS,        KC_TRNS,             KC_TRNS,         KC_TRNS,         KC_TRNS,        KC_TRNS,
       RCTL(KC_L), RCTL(KC_W),     KC_HOME,             KC_UP,           KC_END,          LALT(KC_D),     RCTL(KC_R),
                   LALT(KC_B),     KC_LEFT,             KC_DOWN,         KC_RIGHT,        LALT(KC_F),     LALT(KC_DOT),
       RCTL(KC_C), RCTL(KC_U),     M(SCREEN_COPY_MODE), M(SCREEN_PASTE), MEH(KC_V),      RCTL(KC_K),     M(SHELL_RECALL_LAST_ARG_REMOVE_FIRST_COMMAND),
                // bottom row
                 M(SCREEN_TAB_LEFT), M(SCREEN_TAB_RIGHT), M(SCREEN_NEW_TAB),  KC_TRNS,    KC_TRNS,
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


// key navigation layer
[KEY_NAV] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_V),LCTL(KC_C),KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       RCTL(KC_1), RCTL(KC_2),        RCTL(KC_3),    RCTL(RSFT(KC_PGUP)),    RCTL(RSFT(KC_PGDN)),    KC_TRNS,        KC_TRNS,
       KC_TRNS, KC_PGDN,        KC_HOME,    KC_UP,      KC_END,     KC_PGUP,        M(MC_COPY_LINE),
                RCTL(KC_LEFT),  KC_LEFT,    KC_DOWN,    KC_RIGHT,   RCTL(KC_RIGHT), M(MC_CUT_LINE),
       KC_TRNS, KC_TRNS,        RCTL(KC_C), RCTL(KC_X), RCTL(KC_V), RCTL(KC_Z),        M(MC_PASTE_LINE),
                // bottom row
                KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

// key selection layer
[KEY_SEL] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_V),LCTL(KC_C),KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,       KC_TRNS,             KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,              KC_TRNS,
       RSFT(RCTL(KC_HOME)), RSFT(KC_PGDN),       RSFT(KC_HOME), RSFT(KC_UP),   RSFT(KC_END),   RSFT(KC_PGUP),        M(MC_COPY_LINE),
                      RSFT(RCTL(KC_LEFT)), RSFT(KC_LEFT), RSFT(KC_DOWN), RSFT(KC_RIGHT), RSFT(RCTL(KC_RIGHT)), M(MC_CUT_LINE),
       RSFT(RCTL(KC_END)), RCTL(KC_A),             RCTL(KC_C),    RCTL(KC_X),    RCTL(KC_V),     RCTL(KC_Z),              M(MC_PASTE_LINE),
                // bottom row
                KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

// number layer
[NUMBER] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_V),LCTL(KC_C),KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_PLUS,  KC_7,    KC_8,    KC_9,     KC_ASTR, KC_TRNS,
                KC_MINS,  KC_4,    KC_5,    KC_6,     KC_SLSH, KC_TRNS,
       KC_TRNS, KC_EQUAL, KC_1,    KC_2,    KC_3,     KC_COLN, KC_TRNS,
                               // bottom row
                                KC_0, KC_DOT, KC_COMMA, KC_TRNS,  KC_TRNS,
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_ENT, KC_SPC
),


[SYMBOL] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_PLUS, KC_AMPR, KC_ASTR, KC_GRAVE,KC_TILD, KC_TRNS,
                KC_MINS, KC_DLR,  KC_PERC, KC_CIRC, KC_PIPE, KC_TRNS,
       KC_TRNS, KC_EQUAL,KC_EXLM, KC_AT,   KC_HASH, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       M(SEMICOLON_NEWLINE), M(END_NEWLINE),
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

[BRACKETS] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,             KC_TRNS,            KC_TRNS,               KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,M(OPEN_CLOSE_CURLY), M(OPEN_CLOSE_PAREN),M(OPEN_CLOSE_BRACKET), KC_TRNS,KC_TRNS,
       KC_TRNS,KC_LPRN, KC_RPRN,            KC_LBRC,            KC_RBRC,               KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,             KC_LCBR,            KC_RCBR,               KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,             KC_TRNS,            KC_TRNS,
                                        KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS, KC_TRNS, M(OPEN_CLOSE_BRACKET),M(OPEN_CLOSE_PAREN),M(OPEN_CLOSE_CURLY),KC_TRNS,KC_TRNS,
                KC_TRNS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

[SHORTCUTS] = LAYOUT_ergodox(
       // left hand
       KC_NO,  MEH(KC_F1), MEH(KC_F2), MEH(KC_F3),  MEH(KC_F4), MEH(KC_F5), MEH(KC_F6),
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                         MEH(KC_0),MEH(KC_1),
                                                   MEH(KC_2),
                               MEH(KC_3),MEH(KC_4),MEH(KC_5),
       // right hand
       MEH(KC_F7), MEH(KC_F8), MEH(KC_F9), MEH(KC_F10),  MEH(KC_F11), MEH(KC_F12),  M(SWITCH_NDS),
       KC_TRNS, MEH(KC_A), MEH(KC_B),    MEH(KC_C),    MEH(KC_D),    MEH(KC_E), MEH(KC_F),
                MEH(KC_G), MEH(KC_H),    MEH(KC_I),    MEH(KC_J),    MEH(KC_K), MEH(KC_L),
       KC_TRNS, MEH(KC_M), MEH(KC_N),    MEH(KC_O),    MEH(KC_P),    MEH(KC_Q), KC_CAPSLOCK,
                           MEH(KC_S),    MEH(KC_T),    MEH(KC_U),    MEH(KC_V), MEH(KC_X),
       MEH(KC_6), MEH(KC_7),
       MEH(KC_8),
       MEH(KC_9), MEH(KC_Y), MEH(KC_Z)
),


[MOUSE] = LAYOUT_ergodox(
       RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_SLEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
       KC_TRNS,KC_ASDN, KC_ASUP, KC_ASRP,  KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  M(RS_AS),KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LWIN,
       M(GMAIL),  KC_TRNS, KC_MS_WH_UP, KC_MS_U, KC_TRNS, KC_TRNS, KC_MS_ACCEL0,
                 KC_MS_WH_LEFT, KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_WH_RIGHT, KC_MS_ACCEL1,
       M(VS_EMAIL),  KC_TRNS, KC_MS_WH_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_ACCEL2,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(GAME_AS),
       LALT(LSFT(KC_TAB)), LALT(KC_TAB),
       KC_TRNS,
	   KC_TRNS, KC_BTN1, KC_BTN2
),
[RSMITH] = LAYOUT_ergodox(
       // left hand
       RGB_TOG,RGB_MODE_PLAIN,RGB_MODE_BREATHE,RGB_MODE_RAINBOW,RGB_MODE_SWIRL,RGB_MODE_SNAKE,RGB_MODE_KNIGHT,
       RGB_MOD,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_VOLU,
       RGB_RMOD,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_VOLD,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               M(RS_AS),KC_TRNS,KC_TRNS,
       // right hand
       KC_NO, KC_NO,        KC_NO,    KC_NO,    KC_9,    KC_0,        KC_SPACE,
       KC_LBRC, KC_PGUP,        KC_HOME,    KC_UP,      KC_O,     KC_P,        KC_TAB,
                KC_PGDN,  KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_NO, KC_ESCAPE,
       KC_RBRC, KC_NO,        KC_END,    KC_NO,    KC_NO, KC_NO,        KC_ENTER,
                // bottom row
                KC_NO, KC_LSHIFT, KC_LCTRL,  KC_LALT,    KC_DEL,
       // thumb cluster
       RSFT(KC_EQUAL), KC_F8,
       KC_UP,
       KC_DOWN, KC_LEFT, KC_RIGHT
),
[GAME] = LAYOUT_ergodox(
       // left hand
       KC_ESC,KC_1,KC_2,KC_3,KC_4,KC_5,KC_NO,
       KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_MS_WH_UP,
       KC_LCTRL,KC_A,KC_S,KC_D,KC_F,KC_G,
       KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_MS_WH_DOWN,
               // bottom row
               LSFT(KC_1),LSFT(KC_2),LSFT(KC_3), LSFT(KC_4),LSFT(KC_5),
                                       // thumb cluster
                                       KC_P,KC_M,
                                               KC_L,
                               KC_E, KC_R,KC_SPC,
       // right hand
       KC_6, KC_7,        KC_8,    KC_9,    KC_0,    KC_DEL, KC_BSPACE,
       KC_LBRC, KC_Y,        KC_U,    KC_I,      KC_O,     KC_P,        KC_BSLASH,
                KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
       KC_RBRC, KC_N,        KC_M,    KC_COMM,    KC_DOT, KC_SLSH,        KC_RSHIFT,
                // bottom row
                KC_LALT, KC_LSHIFT, KC_KP_MINUS,  KC_KP_PLUS,   M(GAME_AS),
       // thumb cluster
       KC_LEFT, KC_RIGHT,
       KC_UP,
       KC_DOWN, KC_ENTER, KC_SPC
)

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
/* [BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_LEFT,              KC_RGHT,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_DEL,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    TG(SYMB),             TG(SYMB),     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_BSLS,
  KC_BSPC,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
  KC_LSFT,         CTL_T(KC_Z), KC_X,          KC_C,    KC_V,    KC_B,    ALL_T(KC_NO),                  MEH_T(KC_NO), KC_N,    KC_M,    KC_COMM, KC_DOT,           CTL_T(KC_SLSH), KC_RSFT,
  LT(SYMB,KC_GRV), KC_QUOT,     LALT(KC_LSFT), KC_LEFT, KC_RGHT,                                              KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, TT(SYMB),
                                                           ALT_T(KC_APP), KC_LGUI,                KC_LALT, CTL_T(KC_ESC),
                                                                          KC_HOME,                 KC_PGUP,
                                                         KC_SPC, KC_BSPC, KC_END,                  KC_PGDN, KC_TAB, KC_ENT
), */
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
/* [SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,               KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,     KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  EEP_RST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
                                               RGB_MOD, KC_TRNS,     RGB_TOG, RGB_SLD,
                                                        KC_TRNS,     KC_TRNS,
                                      RGB_VAD, RGB_VAI, KC_TRNS,     KC_TRNS, RGB_HUD, RGB_HUI
), */
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
/* [MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,                                         KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_WBAK
), */
};
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case MC_COPY_LINE:
            if (record->event.pressed) {
                return MACRO( T(HOME), D(LSFT), T(END), U(LSFT), D(LCTL), T(C), U(LCTL), END);
            }
            break;
        case MC_CUT_LINE:
            if (record->event.pressed) {
                return MACRO( T(HOME), D(LSFT), T(END), U(LSFT), D(LCTL), T(X), U(LCTL), END);
            }
            break;
        case MC_PASTE_LINE:
            if (record->event.pressed) {
                return MACRO( T(END), T(ENTER), D(LCTL), T(V), U(LCTL), END);
            }
            break;
        case MC_NEW_SEARCH_TAB:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(T), T(K), U(LCTL), END);
            }
            break;
        case SCREEN_TAB_LEFT:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(P), END);
            }
            break;
        case SCREEN_TAB_RIGHT:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(N), END);
            }
            break;
        case SCREEN_NEW_TAB:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(C), END);
            }
        break;
        case SCREEN_COPY_MODE:
            if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(ESC), END);
            }
        break;
        case SCREEN_PASTE:
            if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(RBRC), END);
            }
        break;
        case SWITCH_NDS:
             if (record->event.pressed) {
                return MACRO( D(LSFT), T(F11), U(LSFT), W(255), D(LALT), T(TAB), U(LALT), END);
            }
        break;
        case OPEN_CLOSE_PAREN:
            if (record->event.pressed) {
                return MACRO( D(LSFT), T(9), T(0), U(LSFT), T(LEFT), END);
            }
        break;
        case OPEN_CLOSE_BRACKET:
            if (record->event.pressed) {
                return MACRO( T(LBRC), T(RBRC), T(LEFT), END);
            }
        break;
        case OPEN_CLOSE_CURLY:
            if (record->event.pressed) {
                return MACRO( D(LSFT), T(LBRC), T(RBRC), U(LSFT), T(LEFT), END);
            }
        break;
        case OPEN_CLOSE_SINGLE_QUOTE:
            if (record->event.pressed) {
                return MACRO( T(QUOT), T(QUOT), T(LEFT), END);
            }
        break;
        case OPEN_CLOSE_DOUBLE_QUOTE:
            if (record->event.pressed) {
                return MACRO( D(LSFT), T(QUOT), T(QUOT), U(LSFT), T(LEFT), END);
            }
        break;
        case SHELL_RECALL_LAST_ARG_REMOVE_FIRST_COMMAND:
            if (record->event.pressed) {
                return MACRO( T(UP), T(HOME), D(LALT), T(D), U(LALT), END);
            }
        break;
		case SEMICOLON_NEWLINE:
            if (record->event.pressed) {
                return MACRO( T(END), T(SCLN), T(ENTER), END);
            }
		break;
		case END_NEWLINE:
            if (record->event.pressed) {
                return MACRO( T(END), T(ENTER), END);
            }
		break;
		case GMAIL:
            if (record->event.pressed) {
                SEND_STRING("jimdibb@gmail.com");
                return false;
            }
		break;
    case VS_EMAIL:
            if (record->event.pressed) {
                SEND_STRING("jim.dibb@virtustream.com");
                return false;
            }
		break;
    case RS_AS:
            if (record->event.pressed) {
                autoshift_toggle();
                layer_invert(RSMITH);
                ergodox_right_led_1_off();
                return false;
            }
		break;
    case GAME_AS:
            if (record->event.pressed) {
                autoshift_toggle();
                layer_invert(GAME);
                ergodox_right_led_1_off();
                return false;
            }
		break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
