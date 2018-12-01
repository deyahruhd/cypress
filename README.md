# cypress
Personalized programming-oriented keymap for the Levinson split keyboard. Intended for use with the [QMK Firmware](https://github.com/qmk/qmk_firmware) and a CLI.

## Installation
Copy the 'keyboards' folder into your qmk_firmware folder. You may now compile and flash the keymap with `make levinson/rev2:cypress:avrdude` or an equivalent command of your choice.

Note that I have enabled EE_HANDS with this keymap, meaning that you **must flash eeprom-lefthand.eep and eeprom-righthand.eep to each respective half of the board to ensure the keymap does not get mirrored.** Both files are the default Let's Split EEPROM files copied from [here](https://github.com/qmk/qmk_firmware/tree/master/keyboards/lets_split). 

## Keymap Layout

#### Default Layer - This is the layer selected when neither Lower nor Raise are being held.
```
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
```

#### Lower Layer - The "numbers" layer.
```
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
```

#### Raise Layer - The "symbols" layer.
```
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
```
Also note that shift can be held down if the numbers layer is active, so the symbols layer can be indirectly accessed through Shift + Lower. 

#### Adjust (Lower + Raise) Layer - The "function" layer.
```
                                                   ())))))))))))))))))
                                                  /                   \
,--------------------------------------------------------.     ,---------------------------------------------------.
|   Reset   |     Q     |     F1    |  F2  |  F3  |  F4  |     |   !  |   @  |   &  |   (  |   )  |      Bksp      |
|-----------+-----------+-----------+------+------+------|     |------+------+------+------+------+----------------|
|    Del    |     A     |     F5    |  F6  |  F7  |  F8  |     |   +  |   =  |   -  |   {  |   }  |     Enter      |
|-----------+-----------+-----------+------+------+------|     |------+------+------+------+------+----------------|
| Backlight |     Z     |     F9    | F10  | F11  | F12  |     |   #  |   *  |   ,  |   .  |   /  | Unswap Gui/Alt |
|-----------+-----------+-----------+------+------+------|     |------+------+------+------+------+----------------|
|   Ctrl    |Rec  Macro1|Rec  Macro2| GUI  |Lower |Space |     | Space|Raise | Left | Down |  Up  |     Right      |
`--------------------------------------------------------'     `---------------------------------------------------'
```

#### Layout regarding macro recording 
If a macro is being recorded by the user, the Play Macro/Rec Macro keys will stop the recording of the macro, regardless of whatever layer is active.

## Other notes
I've designed the right half of the keyboard to contain the most relevant symbols for the programming languages that I primarily use (which are, at the time of writing this, predominantly C/C++ and Java), where the symbols I thought were utilized the most are placed close to the strongest fingers (index and middle). The left half of the board is dedicated to numbers, symbols, and the function keys, depending on if the lower, raise, or adjust layers are activated respectively.
