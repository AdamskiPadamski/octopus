print_string:
  mov ah, 0x0e  
  mov di, 0

  jmp get_next_character

get_next_character:
  mov al, [bx + di]
  jmp print_or_return

print_or_return:
  cmp al, 0
  je return
  int 0x10
  add di, 1
  jmp get_next_character

return:
  ret
