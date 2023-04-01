disk_load:
  push dx

  mov ah, 0x02
  mov al, dh
  mov ch, 0x00
  mov dh, 0x00
  mov cl, 0x02

  int 0x13
 
  jc disk_error ; Jump to error if carry flag was set

  pop dx
  cmp dh, al
  jne de
  ret

de:
  mov bx, DE
  call print_string
  jmp $

disk_error:
  mov bx, DISK_ERROR_MSG
  call print_string
  jmp $

DISK_ERROR_MSG: db "Disk read error!", 0

DE: db "DE!", 0
