#include "ic32.h"

extern "C" void kernel_main(uint32_t memory_map_address) {
    print("Hello, world!", VGA_GREEN);
}
