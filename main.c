#include <stdio.h>
#include "pico/stdlib.h"

// =====================
// Pin Definitions
// =====================
// Change these GPIO pins according to your actual wiring
#define LED_R 11   // GPIO for Red LED pin
#define LED_G 12   // GPIO for Green LED pin
#define LED_B 13   // GPIO for Blue LED pin

// =====================
// Timing Definitions
// =====================
#define OFF_TIME     5000   // All LEDs off for 5 seconds
#define SEQ_DELAY    1000   // Each LED on for 1 second
#define ALL_ON_TIME  2000   // All LEDs on for 2 seconds

int main() {
    // Initialize standard I/O (optional but good practice)
    stdio_init_all();

    // Initialize LED pins as outputs
    gpio_init(LED_R);
    gpio_init(LED_G);
    gpio_init(LED_B);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);

    while (true) {
        // --------------------------
        // 1. All LEDs OFF for 5 sec
        // --------------------------
        gpio_put(LED_R, 0);
        gpio_put(LED_G, 0);
        gpio_put(LED_B, 0);
        sleep_ms(OFF_TIME);

        // --------------------------
        // 2. Turn RED ON for 1 sec
        // --------------------------
        gpio_put(LED_R, 1);
        sleep_ms(SEQ_DELAY);
        gpio_put(LED_R, 0);

        // --------------------------
        // 3. Turn GREEN ON for 1 sec
        // --------------------------
        gpio_put(LED_G, 1);
        sleep_ms(SEQ_DELAY);
        gpio_put(LED_G, 0);

        // --------------------------
        // 4. Turn BLUE ON for 1 sec
        // --------------------------
        gpio_put(LED_B, 1);
        sleep_ms(SEQ_DELAY);
        gpio_put(LED_B, 0);

        // --------------------------
        // 5. Turn ALL ON for 2 sec
        // --------------------------
        gpio_put(LED_R, 1);
        gpio_put(LED_G, 1);
        gpio_put(LED_B, 1);
        sleep_ms(ALL_ON_TIME);

        // --------------------------
        // 6. Turn ALL OFF before repeating
        // --------------------------
        gpio_put(LED_R, 0);
        gpio_put(LED_G, 0);
        gpio_put(LED_B, 0);
    }

    return 0;
}