#include <stdio.h>
#include "pico/stdlib.h"

// Define LED pins (you can change according to your wiring)
// For Arduino Nano RP2040, built-in RGB LED pins:
#define LED_R 6   // Red LED pin
#define LED_G 7   // Green LED pin
#define LED_B 8   // Blue LED pin

// Delay times (in milliseconds)
#define OFF_TIME 5000
#define SEQ_DELAY 1000
#define ALL_ON_TIME 2000

int main() {
    // Initialize the standard input/output
    stdio_init_all();

    // Initialize LED pins as outputs
    gpio_init(LED_R);
    gpio_init(LED_G);
    gpio_init(LED_B);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);

    while (true) {
        // --- Step 1: All LEDs OFF for 5 seconds ---
        gpio_put(LED_R, 0);
        gpio_put(LED_G, 0);
        gpio_put(LED_B, 0);
        sleep_ms(OFF_TIME);

        // --- Step 2: Turn ON Red for 1s ---
        gpio_put(LED_R, 1);
        sleep_ms(SEQ_DELAY);
        gpio_put(LED_R, 0);

        // --- Step 3: Turn ON Green for 1s ---
        gpio_put(LED_G, 1);
        sleep_ms(SEQ_DELAY);
        gpio_put(LED_G, 0);

        // --- Step 4: Turn ON Blue for 1s ---
        gpio_put(LED_B, 1);
        sleep_ms(SEQ_DELAY);
        gpio_put(LED_B, 0);

        // --- Step 5: All ON for 2s ---
        gpio_put(LED_R, 1);
        gpio_put(LED_G, 1);
        gpio_put(LED_B, 1);
        sleep_ms(ALL_ON_TIME);

        // --- Step 6: Turn all OFF before repeating ---
        gpio_put(LED_R, 0);
        gpio_put(LED_G, 0);
        gpio_put(LED_B, 0);
    }

    return 0;
}