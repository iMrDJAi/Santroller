#include <pico/unique_id.h>
#include <stdint.h>
#include <Usb.h>
#define SERIAL_LEN ((PICO_UNIQUE_BOARD_ID_SIZE_BYTES + 3) * 2)


typedef struct
{
    uint8_t bLength;          // Length of this descriptor.
    uint8_t bDescriptorType;  // CONFIGURATION descriptor type (USB_DESCRIPTOR_CONFIGURATION).
    uint16_t UnicodeString[SERIAL_LEN]; /**< String data, as unicode characters (alternatively,
                               *   string language IDs). If normal ASCII characters are
                               *   to be used, they must be added as an array of characters
                               *   rather than a normal C string so that they are widened to
                               *   Unicode size.
                               *
                               *   Under GCC, strings prefixed with the "L" character (before
                               *   the opening string quotation mark) are considered to be
                               *   Unicode strings, and may be used instead of an explicit
                               *   array of ASCII characters on little endian devices with
                               *   UTF-16-LE \c wchar_t encoding.
                               */
} __attribute__((packed)) __attribute__((aligned (16))) STRING_DESCRIPTOR_PICO;


static inline void generateSerialString(STRING_DESCRIPTOR_PICO* const UnicodeString, uint8_t consoleType) {
    char id[PICO_UNIQUE_BOARD_ID_SIZE_BYTES * 2];
    pico_get_unique_board_id_string(id, sizeof(id));
    for (int i = 0; i < sizeof(id); i++) {
        UnicodeString->UnicodeString[i] = id[i];
    }

    UnicodeString->UnicodeString[PICO_UNIQUE_BOARD_ID_SIZE_BYTES] = '0' + consoleType;
    UnicodeString->UnicodeString[PICO_UNIQUE_BOARD_ID_SIZE_BYTES+1] = '0' + DEVICE_TYPE;
    UnicodeString->UnicodeString[PICO_UNIQUE_BOARD_ID_SIZE_BYTES+2] = '0' + WINDOWS_USES_XINPUT;
}