#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t g_netmask_int = 0xFFFFC000;
uint8_t g_netmask_bytes[4];

uint8_t g_ip[4] = {158, 196, 109, 32};

uint32_t g_ip_address = 0x9EC46D20;

int64_t g_mac_address;
int32_t g_mac_oui = 0x00005056;
int32_t g_mac_nic = 0x00ADA948;

int main(){
    // 1
    extern void convert_mask_int_to_bytes();
    convert_mask_int_to_bytes();

    printf("Síťová maska: %d.%d.%d.%d\n\n", g_netmask_bytes[0], g_netmask_bytes[1], g_netmask_bytes[2], g_netmask_bytes[3]);


    // 2
    printf("Původní IP adresa: %d.%d.%d.%d\n", g_ip[0], g_ip[1], g_ip[2], g_ip[3]);

    extern void change_endian();
    change_endian();

    printf("Po změne endianity IP adresa: %d.%d.%d.%d\n\n", g_ip[3], g_ip[2], g_ip[1], g_ip[0]);

    // 3
    printf("Původní IP v hexa formátu: 0x%X\n", g_ip_address);

    extern void get_broadcast_address();
    get_broadcast_address();

    printf("Broadcast v hexa formátu: 0x%X\n\n", g_ip_address);

    // 4
    extern void join_mac_address();
    join_mac_address();

    printf("Výsledná MAC adresa: 0x%lX\n", g_mac_address);

    return 0;
}