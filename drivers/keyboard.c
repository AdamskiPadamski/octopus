#include "../kernel/port.h"
#include "../kernel/idt.h"
#include "./keyboard.h"
#include "./screen.h"

#define DATA_PORT 0x60

static void print_letter(short scancode) {
  switch (scancode) {
    case 0x1e:
      print_char('A', -1, -1, 0);
      return;
  }
}

void keyboard_interrupt_handler() {
  short scancode = port_byte_in(DATA_PORT);

  print_letter(scancode);
}
