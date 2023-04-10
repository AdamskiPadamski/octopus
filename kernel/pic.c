#include "./port.h"

#define PIC1_COMMAND 0x20
#define PIC1_DATA    0x21
#define PIC2_COMMAND 0xa0
#define PIC2_DATA    0xa1

#define ICW1      0x11
#define PIC1_ICW2 0x02  
#define PIC2_ICW2 0x28  
#define PIC1_ICW3 0x01
#define PIC2_ICW3 0x02
#define ICW4      0x01

#define OCW2 0x20

void initialise_pic() {
  port_byte_out(PIC1_COMMAND, ICW1);
  port_byte_out(PIC1_DATA, PIC1_ICW2);
  port_byte_out(PIC1_DATA, PIC1_ICW3);
  port_byte_out(PIC1_DATA, ICW4);

  port_byte_out(PIC2_COMMAND, ICW1);
  port_byte_out(PIC2_DATA, PIC2_ICW2);
  port_byte_out(PIC2_DATA, PIC2_ICW3);
  port_byte_out(PIC2_DATA, ICW4);
}

void send_eoi() {
  port_byte_out(PIC1_COMMAND, OCW2);
  port_byte_out(PIC2_COMMAND, OCW2);
}
