/**
 * Simple GPIO test - output an 8-bit pattern
 * to GPIO2-GPIO10
 *
 * (Leave GPIO0, GPIO1 availabe for UART)
 */

#include "pico/stdlib.h"

int main() {
    const uint32_t MASK_2_10 = 0x000003fc;
    uint32_t outval = 0x1;
    bool dir_left = true;
    gpio_init_mask(MASK_2_10);
    gpio_set_dir_out_masked(MASK_2_10);
    while (true) {
        gpio_put_masked(MASK_2_10, outval << 2);
        sleep_ms(100);
        if (dir_left) {
            if (outval == 0x80) {
                dir_left = false;
                outval = outval >> 1;
            }
            else outval = outval << 1;
        }
        else {
            if (outval == 0x1) {
                dir_left = true;
                outval = outval << 1;
            }
            else outval = outval >> 1;
        }
    }
}
