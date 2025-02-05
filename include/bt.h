#pragma once
#include <stdbool.h>
#include <stdint.h>
int btstack_main();
void send_report(uint8_t size, uint8_t* report);
bool check_bluetooth_ready(void);
bool bluetooth_can_send(void);

void hog_start_scan();
int hog_get_scan_results(uint8_t* buffer);
void hog_stop_scan(void);
int get_bt_address(uint8_t* buffer);

#define SIZE_OF_BD_ADDRESS 18
#define MAX_DEVICES_TO_SCAN 10