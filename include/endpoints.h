#pragma once
enum endpoint_dir_t {
    ENDPOINT_OUT = 0x00,
    ENDPOINT_IN = 0x80
};

// By using these endpoints, we can double buffer!
enum endpoints_t {
    CDC_NOTIFICATION = ENDPOINT_IN | 1,
    DEVICE_EPADDR_IN = ENDPOINT_IN | 3,
    DEVICE_EPADDR_OUT = ENDPOINT_OUT | 4,
    XINPUT_EXTRA_1 = ENDPOINT_IN | 5,
    XINPUT_EXTRA_2 = ENDPOINT_OUT | 6,
    XINPUT_EXTRA_3 = ENDPOINT_IN | 7,
    XINPUT_EXTRA_4 = ENDPOINT_OUT | 8,
    XINPUT_EXTRA_5 = ENDPOINT_IN | 9,
};

#define SERIAL_TX_SIZE 32
#define SERIAL_RX_SIZE 32
#define SERIAL_NOTIFICATION_SIZE 8
#define ENDPOINT_SIZE 64
#define VENDOR_EPSIZE 64

#define ARDWIINO_VID 0x1209
#define ARDWIINO_PID 0x2882
#define HORI_VID 0x0f0d
#define HORI_POKKEN_TOURNAMENT_DX_PRO_PAD_PID 0x0092
#define NINTENDO_VID 0x057E
#define SWITCH_PID 0x2009
#define SONY_VID 0x12ba
#define PS3_GH_GUITAR_PID 0x0100
#define PS3_GH_DRUM_PID 0x0120
#define PS3_RB_GUITAR_PID 0x0200
#define PS3_RB_DRUM_PID 0x0210
#define PS3_DJ_TURNTABLE_PID 0x0140
#define PS3WIIU_GHLIVE_DONGLE_PID 0x074b
#define WII_RB_VID 0x1bad
#define WII_RB_GUITAR_PID 0x0004
#define WII_RB_DRUM_PID 0x074b
#define NINDENDO_VID 0x057E
#define PRO_CONTROLLER_PID 0x2009

#define SIMULTANEOUS_KEYS 6

#define Buttons 4
#define MinAxisVal -127
#define MaxAxisVal 127
#define MinPhysicalVal -127
#define MaxPhysicalVal 128
#define AbsoluteCoords false

enum descriptors_t {
    DESC_EXTENDED_COMPATIBLE_ID_DESCRIPTOR = 0x0004,
    DESC_EXTENDED_PROPERTIES_DESCRIPTOR = 0x0005,
};

enum requests_t {
    REQ_GET_OS_FEATURE_DESCRIPTOR = 0x20
};

enum hid_reports_t {
    REPORT_ID_MOUSE = 1,
    REPORT_ID_KBD,
};

enum interfaces_t {
    INTERFACE_ID_Device = 0, /**< XInput interface descriptor ID */
    INTERFACE_ID_Config = 1, /**< Config interface descriptor ID */
    INTERFACE_ID_Padding = 2,
    INTERFACE_ID_XBOX_Security = 3,
    INTERFACE_ID_ControlStream =
        0, /**< MIDI Control Stream interface descriptor ID */
    INTERFACE_ID_AudioStream =
        2, /**< MIDI Audio Stream interface descriptor ID */
};

void reset_usb(void);
#ifdef __cplusplus
extern "C" {
#endif
void reboot(void);
void bootloader(void);
#ifdef __cplusplus
}
#endif