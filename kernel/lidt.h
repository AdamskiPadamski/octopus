#ifndef OCTOPUS_LIDT_H
#define OCTOPUS_LIDT_H

#include <stdint.h>

typedef struct idtr_register {
  uint16_t  limit;
  uintptr_t base;
} __attribute__((packed)) idtr_register;

void lidt(idtr_register idtr_register);

#endif
