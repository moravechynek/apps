#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

long g_int_ip_address[5] = {0x4D4B4FDE, 0x8EFB2464, 0x9EC40050, 0x9DF01E12, 0x11FD8E04};
char g_str_ip_address[5][16] = {0};

char g_str_mac_address[5][18] = {"CC:96:E5:00:92:52", 
    "74:86:E2:31:05:13", 
    "74:86:E2:31:6E:78", 
    "2C:4F:52:05:3D:02", 
    "CC:96:E5:00:92:3D"};

int g_temperatures[20] = {-2, 0, 1, 3, 5, 7, 6, 4, 2, 0, -1, -3, -5, -6, -4, -2, 0, 2, 4, 6};
int g_count_null = 0; 

int main(){
    
    extern void convert_int_to_ip();
    convert_int_to_ip();
    for (int i = 0; i < 5; i++) {
        printf("%d IP adresa: %s \n", i, g_str_ip_address[i]);
    }

    extern void change_format_mac();
    change_format_mac();
    for (int i = 0; i < 5; i++) {
        printf("%d MAC adresa: %s \n", i, g_str_mac_address[i]);
    }

    extern void get_count_null();
    get_count_null();
    printf("Venku byla nula: %d krát\n", g_count_null);

    return 0;
}