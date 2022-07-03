#include QMK_KEYBOARD_H
#include "led.h"
#include "version.h"
#include "action_layer.h"
#include "action_code.h"
#include "mousekey.h"

enum keyboard_layers {
    BASE = 0,
    //SHELL_NAV,
    KEY_NAV,
    KEY_SEL,
    NUMBER,
    SYMBOL,
    BRACKETS,
    SHORTCUTS,
    MOUSE,
    RSMITH,
    GAME,
};


// macros
enum keyboard_macros {
    // ! commented values not used
    // MC_NEW_SEARCH_TAB,
    // SCREEN_TAB_LEFT,
    // SCREEN_TAB_RIGHT,
    // SCREEN_NEW_TAB,
    // SWITCH_NDS,
    // SCREEN_COPY_MODE,
    // SCREEN_PASTE,
    OCPAREN = SAFE_RANGE,
    OCBRAC,
    OCCURL,
    OCSINGLE,
    OCDOUBLE,
    SHELL_RECALL_LAST_ARG_REMOVE_FIRST_COMMAND,
    SEMICOLON_NEWLINE,
    END_NEWLINE,
    GMAIL,
    VS_EMAIL,
    DELL,
    GAME_AS,
    MCPYLINE,
    MCUTLINE,
    MPASTELINE,
    SWITCH_NDS,
    RS_AS,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// base layer
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        MT(MOD_LSFT, KC_ESC),                    KC_F1,          KC_F2,       KC_F3,        KC_F4,       KC_F5,       MEH_T(KC_F6),
        KC_TAB,                    KC_QUOT,        KC_COMM,     KC_DOT,       KC_P,        KC_Y,        MO(KEY_SEL),
        OSM(MOD_LCTL),              KC_A,           KC_O,        KC_E,         KC_U,        KC_I,
        OSM(MOD_LSFT),             KC_SCLN,        KC_Q,        KC_J,         KC_K,        KC_X,        MO(KEY_NAV),
                   MO(MOUSE),KC_LWIN, OSM(MOD_LALT),MO(SYMBOL),MO(NUMBER),
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
/* [SHELL_NAV] = LAYOUT_ergodox(
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
 */

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
       KC_TRNS, KC_PGDN,        KC_HOME,    KC_UP,      KC_END,     KC_PGUP,        MCPYLINE,
                RCTL(KC_LEFT),  KC_LEFT,    KC_DOWN,    KC_RIGHT,   RCTL(KC_RIGHT), MCUTLINE,
       KC_TRNS, KC_TRNS,        RCTL(KC_C), RCTL(KC_X), RCTL(KC_V), RCTL(KC_Z),     MPASTELINE,
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
       RSFT(RCTL(KC_HOME)), RSFT(KC_PGDN),       RSFT(KC_HOME), RSFT(KC_UP),   RSFT(KC_END),   RSFT(KC_PGUP),  MCPYLINE,
                      RSFT(RCTL(KC_LEFT)), RSFT(KC_LEFT), RSFT(KC_DOWN), RSFT(KC_RIGHT), RSFT(RCTL(KC_RIGHT)), MCUTLINE,
       RSFT(RCTL(KC_END)), RCTL(KC_A),             RCTL(KC_C),    RCTL(KC_X),    RCTL(KC_V),     RCTL(KC_Z),   MPASTELINE,
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
       SEMICOLON_NEWLINE, END_NEWLINE,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

[BRACKETS] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,             KC_TRNS,            KC_TRNS,               KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,OCCURL,              OCPAREN,            OCBRAC,                 KC_TRNS,KC_TRNS,
       KC_TRNS,KC_LPRN, KC_RPRN,            KC_LBRC,            KC_RBRC,               KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,             KC_LCBR,            KC_RCBR,               KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,             KC_TRNS,            KC_TRNS,
                                        KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS, KC_TRNS, OCBRAC,OCPAREN,OCCURL,KC_TRNS,KC_TRNS,
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
       MEH(KC_F7), MEH(KC_F8), MEH(KC_F9), MEH(KC_F10),  MEH(KC_F11), MEH(KC_F12),  SWITCH_NDS,
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
       KC_TRNS, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS,
       KC_SLEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
       KC_TRNS,KC_ASDN, KC_ASUP, KC_ASRP,  KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  RS_AS,KC_TRNS, KC_TRNS,
    // right hand
       DELL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LWIN,
       GMAIL,  KC_TRNS, KC_MS_WH_UP, KC_MS_U, KC_TRNS, KC_TRNS, KC_MS_ACCEL0,
                 KC_MS_WH_LEFT, KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_WH_RIGHT, KC_MS_ACCEL1,
       VS_EMAIL,  KC_TRNS, KC_MS_WH_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_ACCEL2,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, GAME_AS,
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
                               RS_AS,KC_TRNS,KC_TRNS,
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
       KC_ESC,KC_1,KC_2,KC_3,KC_4,KC_5,LSFT(KC_1),
       KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_MS_WH_UP,
       KC_LCTRL,KC_A,KC_S,KC_D,KC_F,KC_G,
       KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_MS_WH_DOWN,
               // bottom row
               KC_LALT,LSFT(KC_2),LSFT(KC_3), LSFT(KC_4),LSFT(KC_5),
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
                KC_NO, KC_LSHIFT, KC_KP_MINUS,  KC_KP_PLUS,   GAME_AS,
       // thumb cluster
       KC_LEFT, KC_RIGHT,
       KC_UP,
       KC_DOWN, KC_ENTER, KC_SPC
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed){
        switch (keycode) {
            case OCPAREN:
            // D(LSFT), T(9), T(0), U(LSFT), T(LEFT), END);
                SEND_STRING(SS_LSFT("90")SS_TAP(X_LEFT));
                return false;
            case OCBRAC:
            // D(LSFT), T(9), T(0), U(LSFT), T(LEFT), END);
                SEND_STRING("[]"SS_TAP(X_LEFT));
                return false;
            case OCCURL:
            // D(LSFT), T(9), T(0), U(LSFT), T(LEFT), END);
                SEND_STRING(SS_LSFT("[]")SS_TAP(X_LEFT));
                return false;
            case OCSINGLE:
                SEND_STRING("''" SS_TAP(X_LEFT));
                return false;
            case OCDOUBLE:
                SEND_STRING(SS_DOWN(X_LSFT) "''"  SS_UP(X_LSFT) SS_TAP(X_LEFT));
                return false;
            case MCPYLINE:
            // T(HOME), D(LSFT), T(END), U(LSFT), D(LCTL), T(C), U(LCTL), END);
                SEND_STRING(SS_TAP(X_HOME) SS_DOWN(X_LSFT) SS_TAP(X_END) SS_UP(X_LSFT) SS_LCTL("c"));
                return false;
            case MCUTLINE:
            // T(HOME), D(LSFT), T(END), U(LSFT), D(LCTL), T(X), U(LCTL), END);
                SEND_STRING(SS_TAP(X_HOME) SS_DOWN(X_LSFT) SS_TAP(X_END) SS_UP(X_LSFT) SS_LCTL("x"));
                return false;
            case MPASTELINE:
            // T(HOME), D(LSFT), T(END), U(LSFT), D(LCTL), T(C), U(LCTL), END);
                SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER) SS_LCTL("v"));
                return false;
            case SEMICOLON_NEWLINE:
                SEND_STRING(SS_TAP(X_END) ";" SS_TAP(X_ENTER));
                return false;
            case END_NEWLINE:
                SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
                return false;
            case DELL:
                SEND_STRING("jim.dibb@dell.com");
                return false;
            case GMAIL:
                SEND_STRING("jimdibb@gmail.com");
                return false;
            case VS_EMAIL:
                SEND_STRING("jim.dibb@virtustream.com");
                return false;
            case RS_AS:
                autoshift_toggle();
                layer_invert(RSMITH);
                ergodox_right_led_1_off();
                return false;
            case GAME_AS:
                autoshift_toggle();
                layer_invert(GAME);
                ergodox_right_led_1_off();
                return false;
        }
    }
    return true;
}

// ! Any remaining macros below were not converted above as I just don't use them
// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
// {
//   // MACRODOWN only works in this function
//       switch(id) {
//
//         case MC_NEW_SEARCH_TAB:
//              if (record->event.pressed) {
//                 return MACRO( D(LCTL), T(T), T(K), U(LCTL), END);
//             }
//             break;
//         case SCREEN_TAB_LEFT:
//              if (record->event.pressed) {
//                 return MACRO( D(LCTL), T(A), U(LCTL), T(P), END);
//             }
//             break;
//         case SCREEN_TAB_RIGHT:
//              if (record->event.pressed) {
//                 return MACRO( D(LCTL), T(A), U(LCTL), T(N), END);
//             }
//             break;
//         case SCREEN_NEW_TAB:
//              if (record->event.pressed) {
//                 return MACRO( D(LCTL), T(A), U(LCTL), T(C), END);
//             }
//         break;
//         case SCREEN_COPY_MODE:
//             if (record->event.pressed) {
//                 return MACRO( D(LCTL), T(A), U(LCTL), T(ESC), END);
//             }
//         break;
//         case SCREEN_PASTE:
//             if (record->event.pressed) {
//                 return MACRO( D(LCTL), T(A), U(LCTL), T(RBRC), END);
//             }
//         break;
//         case SWITCH_NDS:
//              if (record->event.pressed) {
//                 return MACRO( D(LSFT), T(F11), U(LSFT), W(255), D(LALT), T(TAB), U(LALT), END);
//             }
//         break;
//         case SHELL_RECALL_LAST_ARG_REMOVE_FIRST_COMMAND:
//             if (record->event.pressed) {
//                 return MACRO( T(UP), T(HOME), D(LALT), T(D), U(LALT), END);
//             }
//         break;

//       }
//     return MACRO_NONE;
// };

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

    return;
};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }
}


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case NUMBER:
        case SYMBOL:
		case BRACKETS:
		//case SHELL_LAYER:
            ergodox_right_led_2_on();
            break;
        case KEY_NAV:
        case KEY_SEL:
            ergodox_right_led_3_on();
            break;
        case MOUSE:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case RSMITH:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
        case GAME:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
        default:
            // none
            break;
    }
    return;
};
