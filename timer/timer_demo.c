/**
 * Simple timer demo - flash two LEDs at different rates
*/

#include "pico/stdlib.h"
#include "timer.h"

int main() {
    uint32_t t1a, t2a, t1b, t2b;
    const uint32_t PD_MS_A = 100;
    const uint32_t PD_MS_B = 250;
    bool a, b;
    gpio_init(2);
    gpio_set_dir(2,true);
    gpio_init(3);
    gpio_set_dir(3,true);
    t1a = t1b = timer_read();
    a = b = true;
    gpio_put(2,a);
    gpio_put(3,b);
    while (true) {
        t2a = t2b = timer_read();
        if (timer_elapsed_ms(t1a, t2a) >= PD_MS_A) {
            t1a = t2a;
            a = !a;
            gpio_put(2,a);
        }
        if (timer_elapsed_ms(t1b, t2b) >= PD_MS_B) {
            t1b = t2b;
            b = !b;
            gpio_put(3,b);
        }       
    }
}