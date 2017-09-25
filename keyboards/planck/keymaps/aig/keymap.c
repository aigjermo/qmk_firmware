#include QMK_KEYBOARD_H
#include "../../../../quantum/keymap_extras/keymap_norwegian.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _SYMBOLS,
  _ALTSYMB,
  _MOVEMENT
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLGT
};

/* Filler keys */
#define XXXXXXX KC_NO

/* Normal keys */
#define NO_QUO1 KC_BSLS

/* Shifted keys */

/* Modifier keys */
#define RSFTENT MT(MOD_RSFT, KC_ENT)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)

/* Layer keys */
#define MOVEESC LT(_MOVEMENT, KC_ESC)
#define L_SYMB  OSL(_SYMBOLS)
#define L_ASYMB MO(_ALTSYMB)
#define L_MOVE  OSL(_MOVEMENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/** Qwerty
 ** ,-----------------------------------------------------------------------------------------------.
 ** |  Tab  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   Å   |
 ** |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 ** |MoveEsc|   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   Ø   |   Æ   |
 ** |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 ** | Shift |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   -   |RShEntr|
 ** |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 ** | Ctrl  |  GUI  | Leader|  Alt  |NumbSmb|  <-   |   ->  |Movemnt|  RALT | Leader|  Del  |  Ins  |
 ** '-----------------------------------------------------------------------------------------------'
 **/
[_QWERTY] = {
  { KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , NO_AA   },
  { MOVEESC, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , NO_OSLH, NO_AE   },
  { KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, RSFTENT },
  { OS_LCTL, KC_LGUI, KC_LEAD, OS_LALT, L_SYMB , KC_BSPC, KC_SPC , L_MOVE , OS_RALT, KC_LEAD, KC_DEL , KC_INS  }
},

/** Numbers
 ** ,-----------------------------------------------------------------------------------------------.
 ** |   |   |   !   |   ?   |   (   |   )   |   '   |   #   |   7   |   8   |   9   |   /   |   *   |
 ** |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 ** |AltSymb|   @   |   =   |   {   |   }   |   "   |   $   |   4   |   5   |   6   |   +   |   -   |
 ** |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 ** | Shift |   ^   |   ~   |   [   |   ]   |   `   |   &   |   1   |   2   |   3   |   %   |RShEntr|
 ** |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 ** | Ctrl  |  GUI  |       |  Alt  |NumbSmb|  <-   |   ->  |   0   |   ,   |   .   |  Del  |  Ins  |
 ** '-----------------------------------------------------------------------------------------------'
 **/
[_SYMBOLS] = {
  { NO_PIPE, KC_EXLM, NO_QUES, NO_LPRN, NO_RPRN, NO_QUO1, KC_HASH, KC_7   , KC_8   , KC_9   , NO_SLSH, NO_ASTR },
  { L_ASYMB, NO_AT  , NO_EQL , NO_LCBR, NO_RCBR, NO_QUO2, NO_DLR , KC_4   , KC_5   , KC_6   , KC_PMNS, KC_PPLS },
  { _______, NO_CIRC, NO_TILD, NO_LBRC, NO_RBRC, NO_GRV , NO_AMPR, KC_1   , KC_2   , KC_3   , KC_PERC, _______ },
  { _______, _______, XXXXXXX, _______, L_SYMB , _______, _______, KC_0   , KC_COMM, KC_DOT , _______, _______ }
},

/** Alternate symbols
 ** ,-----------------------------------------------------------------------------------------------.
 ** |   \   |   !   |   ?   |   (   |   )   |   '   |   #   |  F7   |  F8   |  F9   |   \   |   *   |
 ** |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 ** |AltSymb|   @   |   =   |   <   |   >   |   "   |   $   |  F4   |  F5   |  F6   |   +   |   -   |
 ** |-------+-------+-------+-------+-------j-------+-------+-------+-------+-------+-------+-------|
 ** | Shift |   ^   |   ~   |   [   |   ]   |   `   |   &   |  F1   |  F2   |  F3   |   %   |RShEntr|
 ** |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 ** | Ctrl  |  GUI  |       |  Alt  |NumbSmb|  <-   |   ->  |  F10  |  F11  |  F12  |  Del  |  Del  |
 ** '-----------------------------------------------------------------------------------------------'
 **/
[_ALTSYMB] = {
  { NO_BSLS, _______, _______, _______, _______, _______, _______, KC_F7  , KC_F8  , KC_F9  , NO_BSLS, _______ },
  { L_ASYMB, _______, _______, NO_LESS, NO_GRTR, _______, _______, KC_F4  , KC_F5  , KC_F6  , _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, KC_F1  , KC_F2  , KC_F3  , _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, KC_F10 , KC_F11 , KC_F12 , _______, _______ }
},

/** Movement
 ** ,-----------------------------------------------------------------------------------------------.
 ** |  Tab  |       |       | VolDn | VolUp |  Mute |  Home |  PgUp |  PgDn |  End  |       | Pause |
 ** |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 ** |MoveEsc|       |  Stop |  Prev |  Next |  P/P  |  Left |  Down |   Up  | Right |       |       |
 ** |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 ** | Shift |       |       |       |       |       |       |       |       |       |       |       |
 ** |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 ** | Ctrl  |  GUI  |       |  Alt  |       |       |       |Movemnt|       |       |       |       |
 ** '-----------------------------------------------------------------------------------------------'
 **/
[_MOVEMENT] = {
  { KC_TAB , XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX, KC_PAUS },
  { _______, XXXXXXX, KC_MSTP, KC_MPRV, KC_MNXT, KC_MPLY, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX },
  { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  { _______, _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, L_MOVE , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }
}

};

/* Leader macros */
LEADER_EXTERNS();

#define SW_DESK(DN) \
    register_code(KC_RCTRL);\
    unregister_code(KC_RCTRL);\
    register_code(KC_LCTRL);\
    register_code(DN);\
    unregister_code(DN);\
    unregister_code(KC_LCTRL);

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Keeb Reset
    SEQ_TWO_KEYS(KC_K, KC_R) {
      reset_keyboard();
    }

    // Keeb Light
    SEQ_TWO_KEYS(KC_K, KC_L) {
      backlight_step();
    }

    // Switch desktops
    SEQ_ONE_KEY(KC_Q) {
      SW_DESK(KC_F1)
    }
    SEQ_ONE_KEY(KC_W) {
      SW_DESK(KC_F2)
    }
    SEQ_ONE_KEY(KC_E) {
      SW_DESK(KC_F3)
    }
    SEQ_ONE_KEY(KC_R) {
      SW_DESK(KC_F4)
    }
  }
}



/* Handle custom keycodes */
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BACKLGT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}
*/
