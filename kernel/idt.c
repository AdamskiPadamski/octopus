#include "./idt.h"
#include "../drivers/screen.h"

#define KERNEL_SEGMENT_OFFSET 0x08;

typedef struct idt_descriptor {
  uint16_t low_offset;
  uint16_t segment_selector;
  uint8_t  zero;
  uint8_t  type_attributes;
  uint16_t high_offset;
} __attribute((packed)) idt_descriptor;

typedef struct idt_register {
  uint16_t  limit;
  uintptr_t base;
} __attribute__((packed)) idt_register;

idt_descriptor idt[256];

static void lidt(idt_register idt_register) {
  __asm__("lidt %0" : : "m" (idt_register));
}

static void add_interrupt_gate(int interrupt_number, uint32_t interrupt_handler_address) {
  idt[interrupt_number].low_offset       = interrupt_handler_address & 0xff;
  idt[interrupt_number].high_offset      = interrupt_handler_address >> 8;
  idt[interrupt_number].type_attributes  = 0x8e;
  idt[interrupt_number].segment_selector = KERNEL_SEGMENT_OFFSET;
}

static void create_idt() {
  add_interrupt_gate(0, (uint32_t) interrupt_handler_0);
  add_interrupt_gate(1, (uint32_t) interrupt_handler_1);
  add_interrupt_gate(2, (uint32_t) interrupt_handler_2);
  add_interrupt_gate(3, (uint32_t) interrupt_handler_3);
  add_interrupt_gate(4, (uint32_t) interrupt_handler_4);
  add_interrupt_gate(5, (uint32_t) interrupt_handler_5);
  add_interrupt_gate(6, (uint32_t) interrupt_handler_6);
  add_interrupt_gate(7, (uint32_t) interrupt_handler_7);
  add_interrupt_gate(8, (uint32_t) interrupt_handler_8);
  add_interrupt_gate(9, (uint32_t) interrupt_handler_9);
  add_interrupt_gate(10, (uint32_t) interrupt_handler_10);
  add_interrupt_gate(11, (uint32_t) interrupt_handler_11);
  add_interrupt_gate(12, (uint32_t) interrupt_handler_12);
  add_interrupt_gate(13, (uint32_t) interrupt_handler_13);
  add_interrupt_gate(14, (uint32_t) interrupt_handler_14);
  add_interrupt_gate(15, (uint32_t) interrupt_handler_15);
  add_interrupt_gate(16, (uint32_t) interrupt_handler_16);
  add_interrupt_gate(17, (uint32_t) interrupt_handler_17);
  add_interrupt_gate(18, (uint32_t) interrupt_handler_18);
  add_interrupt_gate(19, (uint32_t) interrupt_handler_19);
  add_interrupt_gate(20, (uint32_t) interrupt_handler_20);
  add_interrupt_gate(21, (uint32_t) interrupt_handler_21);
  add_interrupt_gate(22, (uint32_t) interrupt_handler_22);
  add_interrupt_gate(23, (uint32_t) interrupt_handler_23);
  add_interrupt_gate(24, (uint32_t) interrupt_handler_24);
  add_interrupt_gate(25, (uint32_t) interrupt_handler_25);
  add_interrupt_gate(26, (uint32_t) interrupt_handler_26);
  add_interrupt_gate(27, (uint32_t) interrupt_handler_27);
  add_interrupt_gate(28, (uint32_t) interrupt_handler_28);
  add_interrupt_gate(29, (uint32_t) interrupt_handler_29);
  add_interrupt_gate(30, (uint32_t) interrupt_handler_30);
  add_interrupt_gate(31, (uint32_t) interrupt_handler_31);
  add_interrupt_gate(32, (uint32_t) interrupt_handler_32);
  add_interrupt_gate(33, (uint32_t) interrupt_handler_33);
  add_interrupt_gate(34, (uint32_t) interrupt_handler_34);
  add_interrupt_gate(35, (uint32_t) interrupt_handler_35);
  add_interrupt_gate(36, (uint32_t) interrupt_handler_36);
  add_interrupt_gate(37, (uint32_t) interrupt_handler_37);
  add_interrupt_gate(38, (uint32_t) interrupt_handler_38);
  add_interrupt_gate(39, (uint32_t) interrupt_handler_39);
  add_interrupt_gate(40, (uint32_t) interrupt_handler_40);
  add_interrupt_gate(41, (uint32_t) interrupt_handler_41);
  add_interrupt_gate(42, (uint32_t) interrupt_handler_42);
  add_interrupt_gate(43, (uint32_t) interrupt_handler_43);
  add_interrupt_gate(44, (uint32_t) interrupt_handler_44);
  add_interrupt_gate(45, (uint32_t) interrupt_handler_45);
  add_interrupt_gate(46, (uint32_t) interrupt_handler_46);
  add_interrupt_gate(47, (uint32_t) interrupt_handler_47);
}

void initialise_idt() {
  idt_register idtr_reg = { sizeof(idt), (uintptr_t) &idt };

  lidt(idtr_reg);
}

void interrupt_handler() {
  print_char('h', 0, 0, 0);
}
