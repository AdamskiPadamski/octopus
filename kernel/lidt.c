#include "./lidt.h"

void lidt(idtr_register idtr_register) {
  __asm__("lidt %0" : : "m" (idtr_register));
}
