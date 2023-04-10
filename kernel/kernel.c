#include "../drivers/screen.h"
#include "./idt.h"
#include "./pic.h"

int main() {
  clear_screen();

  initialise_pic();

  // load_idt();

  return 0;
}
