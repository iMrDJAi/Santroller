#include <pico/unique_id.h>
#include <stdint.h>
#include <Usb.h>
#define SERIAL_LEN (PICO_UNIQUE_BOARD_ID_SIZE_BYTES * 2)


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
} __attribute__((packed)) STRING_DESCRIPTOR_PICO;


static inline uint16_t generateSerialString(STRING_DESCRIPTOR_PICO* const UnicodeString) {
    char id[SERIAL_LEN];
    pico_get_unique_board_id_string(id, SERIAL_LEN);
    for (int i = 0; i < SERIAL_LEN; i++) {
        UnicodeString->UnicodeString[i] = id[i];
    }
    return sizeof(id);
}