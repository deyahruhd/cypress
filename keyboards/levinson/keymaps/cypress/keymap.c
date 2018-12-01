#include QMK_KEYBOARD_H

#define DEBUG

#ifdef DEBUG
#include <print.h>
#endif

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _PLAY_MACROS 13
#define _START_MACRO_REC 14
#define _STOP_MACRO_REC 15

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  DYNAMIC_MACRO_RANGE,
};
#include "dynamic_macro.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

bool is_recording = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty
                                               ())))))))))))))))))
                                              /                   \
,----------------------------------------------------.     ,-----------------------------------------.
|  Tab  |     Q     |     W     |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  | Bksp |
|-------+-----------+-----------+------+------+------|     |------+------+------+------+------+------|
|  Esc  |     A     |     S     |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |Enter |
|-------+-----------+-----------+------+------+------|     |------+------+------+------+------+------|
| Shift |     Z     |     X     |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |  '   |
|-------+-----------+-----------+------+------+------|     |------+------+------+------+------+------|
| Ctrl  |Play Macro1|Play Macro2| Alt  |Lower |Space |     | Space|Raise | Left | Down |  Up  |Right |
`----------------------------------------------------'     `-----------------------------------------'
 */

[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   /**/                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   /**/                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT , \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   /**/                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
  KC_LCTL, XXXXXXX, XXXXXXX, KC_LALT, LOWER,   KC_SPC,                 /**/                KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Lower
                                               ())))))))))))))))))
                                              /                   \
,----------------------------------------------------.     ,-----------------------------------------.
|   `   |     1     |     2     |   3  |   4  |   5  |     |   !  |   @  |   &  |   (  |   )  | Bksp |
|-------+-----------+-----------+------+------+------|     |------+------+------+------+------+------|
|  Del  |     6     |     7     |   8  |   9  |   0  |     |   +  |   =  |   _  |   [  |   ]  |Enter |
|-------+-----------+-----------+------+------+------|     |------+------+------+------+------+------|
| Shift |     Z     |     X     |   C  |Insert|   B  |     |   #  |   *  |   ,  |   .  |   /  |  '   |
|-------+-----------+-----------+------+------+------|     |------+------+------+------+------+------|
| Ctrl  |Rec  Macro1|Rec  Macro2| Alt  |Lower |Space |     | Space|Raise | Left | Down |  Up  |Right |
`----------------------------------------------------'     `-----------------------------------------'
 */ 
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   /**/                KC_EXLM, KC_AT,   KC_AMPR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                   /**/                KC_PLUS, KC_EQL,  KC_UNDS, KC_LBRC, KC_RBRC, KC_ENT,  \
  _______, _______, _______, _______, KC_INS,  _______,                /**/                KC_HASH, KC_ASTR, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                /**/                _______, _______, _______, _______, _______, _______  \
),

/* Raise
                                               ())))))))))))))))))
                                              /                   \
,----------------------------------------------------.     ,-----------------------------------------.
|   `   |     !     |     @     |   #  |   $  |   %  |     |   !  |   @  |   &  |   (  |   )  | Bksp |
|-------+-----------+-----------+------+------+------|     |------+------+------+------+------+------|
|  Del  |     ^     |     &     |   *  |   \  |   |  |     |   +  |   =  |   -  |   {  |   }  |Enter |
|-------+-----------+-----------+------+------+------|     |------+------+------+------+------+------|
| Shift |     Z     |     X     |   C  |Insert|   B  |     |   #  |   *  |   ,  |   .  |   /  |  '   |
|-------+-----------+-----------+------+------+------|     |------+------+------+------+------+------|
| Ctrl  |Rec  Macro1|Rec  Macro2| Alt  |Lower |Space |     | Space|Raise | Left | Down |  Up  |Right |
`----------------------------------------------------'     `-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_TILDE,KC_EXLM, KC_AT,   KC_HASH, KC_DLR,    KC_PERC,              /**/                KC_EXLM, KC_AT,   KC_AMPR,  KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLASH, KC_PIPE,              /**/                KC_PLUS, KC_EQL,  KC_MINUS, KC_LCBR, KC_RCBR, KC_ENT,  \
  _______, _______, _______, _______, KC_INS,    _______,              /**/                KC_HASH, KC_ASTR, _______,  _______, _______, _______, \
  _______, _______, _______, _______, _______,   _______,              /**/                _______, _______, _______,  _______, _______, _______  \
),


/* Adjust (Lower + Raise)
                                                   ())))))))))))))))))
                                                  /                   \
,--------------------------------------------------------.     ,---------------------------------------------------.
|   Reset   |     Q     |     F1    |  F2  |  F3  |  F4  |     |   !  |   @  |   &  |   (  |   )  |      Bksp      |
|-----------+-----------+-----------+------+------+------|     |------+------+------+------+------+----------------|
|    Del    |     A     |     F5    |  F6  |  F7  |  F8  |     |   +  |   =  |   -  |   {  |   }  |     Enter      |
|-----------+-----------+-----------+------+------+------|     |------+------+------+------+------+----------------|
| Backlight |     Z     |     F9    | F10  | F11  | F12  |     |   #  |   *  |   ,  |   .  |   /  | Unswap Gui/Alt |
|-----------+-----------+-----------+------+------+------|     |------+------+------+------+------+----------------|
|   Ctrl    |Rec  Macro1|Rec  Macro2| Alt  |Lower |Space |     | Space|Raise | Left | Down |  Up  |     Right      |
`--------------------------------------------------------'     `---------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET,   KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,                  /**/                KC_EXLM, KC_AT,   KC_AMPR,  KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,                  /**/                KC_PLUS, KC_EQL,  KC_MINUS, KC_LCBR, KC_RCBR, KC_ENT,  \
  BL_STEP, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,                 /**/                KC_HASH, KC_ASTR, _______,  _______, _______, AG_NORM, \
  _______, _______, _______, KC_LGUI, _______, _______,                /**/                _______, _______, _______,  _______, _______, _______  \
),

[_PLAY_MACROS] =  LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______,                /**/                _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                /**/                _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                /**/                _______, _______, _______, _______, _______, _______, \
  _______, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, _______, _______, _______,/**/                _______, _______, _______, _______, _______, _______  \
),

[_START_MACRO_REC] =  LAYOUT_ortho_4x12( \
  _______,      _______,      _______, _______, _______, _______,      /**/                _______, _______, _______, _______, _______, _______, \
  _______,      _______,      _______, _______, _______, _______,      /**/                _______, _______, _______, _______, _______, _______, \
  _______,      _______,      _______, _______, _______, _______,      /**/                _______, _______, _______, _______, _______, _______, \
  _______, DYN_REC_START1, DYN_REC_START2, _______, _______, _______,  /**/                _______, _______, _______, _______, _______, _______  \
),

[_STOP_MACRO_REC] =  LAYOUT_ortho_4x12( \
  _______,      _______,      _______, _______, _______, _______,      /**/                _______, _______, _______, _______, _______, _______, \
  _______,      _______,      _______, _______, _______, _______,      /**/                _______, _______, _______, _______, _______, _______, \
  _______,      _______,      _______, _______, _______, _______,      /**/                _______, _______, _______, _______, _______, _______, \
  _______, DYN_REC_STOP, DYN_REC_STOP, _______, _______, _______,      /**/                _______, _______, _______, _______, _______, _______  \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Toggles between 3 recording layers which contain the various dynamic macro keycodes. 
// The recording boolean is used to select whether conditional_layer1 or conditional_layer2 is selected; conditional_layer2 is selected if
//   recording is false, otherwise conditional_layer1 is selected. 
// This allows the keyboard to switch the functionality of the two macro keys depending on whether it is recording a macro. For example,
//   if a macro is being recorded, both macro keys become DYN_REC_STOP, when normally they would be DYN_MACRO_PLAY or DYN_REC_START.
void update_tri_record_layer (uint16_t conditional_layer1, uint16_t conditional_layer2, uint16_t disable_layer, bool recording) {
  layer_on  (recording ? conditional_layer1 : conditional_layer2);
  layer_off (recording ? conditional_layer2 : conditional_layer1);
  layer_off (disable_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
      return false;
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        update_tri_record_layer(_STOP_MACRO_REC, _START_MACRO_REC, _PLAY_MACROS, is_recording);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        update_tri_record_layer(_STOP_MACRO_REC, _PLAY_MACROS, _START_MACRO_REC, is_recording);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        update_tri_record_layer(_STOP_MACRO_REC, _START_MACRO_REC, _PLAY_MACROS, is_recording);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        update_tri_record_layer(_STOP_MACRO_REC, _PLAY_MACROS, _START_MACRO_REC, is_recording);
      }
      return false;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
        update_tri_record_layer(_STOP_MACRO_REC, _START_MACRO_REC, _PLAY_MACROS, is_recording);
      } else {
        layer_off(_ADJUST);
        update_tri_record_layer(_STOP_MACRO_REC, _PLAY_MACROS, _START_MACRO_REC, is_recording);
      }
      return false;
    case DYN_REC_START1:
    case DYN_REC_START2:
      if (record->event.pressed) {
        is_recording = 1;

        update_tri_record_layer(_STOP_MACRO_REC, _START_MACRO_REC, _PLAY_MACROS, true);

        layer_on(_STOP_MACRO_REC);
        layer_off(_PLAY_MACROS);
        layer_off(_START_MACRO_REC);
      }
      return false;
    case DYN_REC_STOP:
      is_recording = 0;

      update_tri_record_layer(_PLAY_MACROS, _STOP_MACRO_REC, _START_MACRO_REC, true);
      return false;
  }
  return true;
}