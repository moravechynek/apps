bits 64

section .data

extern g_int_ip_address
extern g_str_ip_address
extern g_str_mac_address
extern g_temperatures
extern g_count_null

section .text

global convert_int_to_ip
global change_format_mac
global get_count_null

convert_int_to_ip:
    mov rcx, 0
    mov rax, 0

.first_loop:
    mov rbx, 0
    .second_loop:
        .preved:
            mov rax, [ g_int_ip_address + rcx * 8 ]
            cmp rax, 0
            ;jg .positive
            ;jl .negative
            jmp .ret

        inc rbx
        cmp rbx, 16
        jl .second_loop
    inc rcx
    cmp rcx, 5
    jl .first_loop

    .ret:
    ret

change_format_mac:
    mov rcx, 0

.first_loop:
    cmp byte [ change_format_mac + 1 * rcx ], 64;cmp char
    jl .continue;number or ':' continue
    ;add byte [ change_format_mac + 1 * rcx  ], 32; else add 32
    .continue:
    inc rcx
    cmp rcx, 16*4
    jl .first_loop

    ret

get_count_null:
    mov eax, 0
    mov rcx, 0
    jmp .back
.is_zero:
    inc eax
    jmp .continue
.back:
    cmp [ g_temperatures + rcx * 4], dword 0
    je .is_zero
    .continue:
    inc rcx
    cmp rcx, 20
    jl .back

    mov [g_count_null], eax

    ret
