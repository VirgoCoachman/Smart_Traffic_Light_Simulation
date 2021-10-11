#ifndef BLINKLED_H_
#define BLINKLED_H_

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

// ----------------------------------------------------------------------------

void
blink_led_on(int index);

void
blink_led_off(void);

void blink_orange_led(int *);


// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

#endif // BLINKLED_H_
