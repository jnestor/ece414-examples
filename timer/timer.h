

#ifndef TIMER_H
#define TIMER_H

#include "stdint.h"

uint32_t timer_read();

uint32_t timer_elapsed_us(uint32_t t1, uint32_t t2);

uint32_t timer_elapsed_ms(uint32_t t1, uint32_t t2);

#endif