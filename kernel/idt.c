#include "./idt.h"
#include "./lidt.h"
#include "../drivers/screen.h"

#define KERNEL_SEGMENT_OFFSET 0x08;

idt_entry idt[256];

void add_interrupt_gate(int interrupt_number, uint32_t interrupt_handler_address) {
  idt[interrupt_number].low_offset       = interrupt_handler_address & 0xff;
  idt[interrupt_number].high_offset      = interrupt_handler_address >> 8;
  idt[interrupt_number].type_attributes  = 0x8e;
  idt[interrupt_number].segment_selector = KERNEL_SEGMENT_OFFSET;
}

void load_idt() {
  idtr_register idtr_reg = { sizeof(idt), (uintptr_t) &idt };
  lidt(idtr_reg);
}

void interrupt_handler() {
  print_char('h', 0, 0, 0);
}
