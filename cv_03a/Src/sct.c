/*
 * sct.c
 *
 *  Created on: 7. 10. 2021
 *      Author: student
 *
 *  Driver 7seg displeje
 */

#include <stdint.h>
#include "stm32f0xx.h"
#include "sct.h"

void sct_init(void){

	RCC->AHBENR |= RCC_AHBENR_GPIOBEN; // timer enable
	GPIOB->MODER |= GPIO_MODER_MODER3_0; // CLK
	GPIOB->MODER |= GPIO_MODER_MODER4_0; // SDI
	GPIOB->MODER |= GPIO_MODER_MODER5_0; // NLA
	GPIOB->MODER |= GPIO_MODER_MODER10_0; // NOE

	sct_led(0);
	sct_noe(0);

}

void sct_led(uint32_t value) {
	for (uint32_t i=0;i<32;i++){
		sct_sdi((value >> i) & 1);
		sct_clk(1);
		sct_clk(0);
	}
	sct_nla(1);
	sct_nla(0);
}
