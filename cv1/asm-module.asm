bits 64

section .data

    extern g_ip
    extern g_netmask_int
    extern g_netmask_bytes
    extern g_ip_address

    extern g_mac_address
    extern g_mac_oui
    extern g_mac_nic
     

section .text

    global change_endian
    global get_broadcast_address
    global join_mac_address
    global convert_mask_int_to_bytes

convert_mask_int_to_bytes:
    mov eax, [ g_netmask_int ]
    mov ebx, eax

    mov [ g_netmask_bytes + 3 ], al
    mov [ g_netmask_bytes + 2 ], ah

    ret

change_endian:
    mov al, [ g_ip + 0 * 1 ]
    mov bl, [ g_ip + 3 * 1 ]
    mov [ g_ip + 0 * 1 ], bl
    mov [ g_ip + 3 * 1 ], al

    mov al, [ g_ip + 1 * 1 ]
    mov bl, [ g_ip + 2 * 1 ]
    mov [ g_ip + 1 * 1 ], bl
    mov [ g_ip + 2 * 1 ], al
    
    ret

get_broadcast_address:
    mov eax, [ g_ip_address ]
    mov ax, 0xFFFF
    mov [ g_ip_address ], eax
    ret

join_mac_address:
    ;mov rax, g_mac_address
    ;movzx g_max_oui
    ret