# cypress
Personalized programming-oriented keymap for the Levinson split keyboard. Intended for use with the [QMK Firmware](https://github.com/qmk/qmk_firmware) and a CLI.

### Installation
Copy the 'keyboards' folder into your qmk_firmware folder. You may now compile and flash the keymap with `make levinson/rev2:cypress:avrdude` or an equivalent command of your choice.

Note that I have enabled EE_HANDS with this keymap, meaning that you **must flash eeprom-lefthand.eep and eeprom-righthand.eep to each respective half of the board to ensure the keymap does not get mirrored.** Both files are the default Let's Split EEPROM files copied from [here](https://github.com/qmk/qmk_firmware/tree/master/keyboards/lets_split). 

### Other notes
I've designed the right half of the keyboard to contain the most relevant symbols for the programming languages that I primarily use (which are, at the time of writing this, predominantly C/C++ and Java), where the symbols I thought were utilized the most are placed close to the strongest fingers (index and middle). The left half of the board is dedicated to numbers, symbols, and the function keys, depending on if the lower, raise, or adjust layers are activated respectively.
