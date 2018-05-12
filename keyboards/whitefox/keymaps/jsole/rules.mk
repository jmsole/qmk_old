# Build Options
#   comment out to disable the options.
#
APPLE_FN_ENABLE = yes
BOOTMAGIC_ENABLE = yes       # Virtual DIP switch configuration(+1000)
## (Note that for BOOTMAGIC on Teensy LC you have to use a custom .ld script.)
MOUSEKEY_ENABLE = no        # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
CUSTOM_MATRIX = yes         # Custom matrix file
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
SLEEP_LED_ENABLE = yes      # Breathing sleep LED during USB suspend
VISUALIZER_ENABLE = yes

ifndef QUANTUM_DIR
    include ../../../../Makefile
endif