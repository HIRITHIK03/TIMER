#include <stdint.h>
#include "GPIO_F_Init.h"
#include "Timer1_Init.h"

// GPIO Port F Register
#define GPIO_PORTF_DATA       (*((volatile uint32_t *)0x4005D3FC))

// Timer 1 Registers

#define TIMER1_ICR            (*((volatile uint32_t *)0x40031024))
#define TIMER1_MIS            (*((volatile unsigned long *)0x40031020))


// Timer 1 Interrupt Handler
void Timer1A_Handler(void) {
    if (TIMER1_MIS & 0x01) {

        GPIO_PORTF_DATA ^= 0x01;   // Toggle LED
    }
    TIMER1_ICR = 0x01; // Clear timer interrupt
}

int main(void) {

    GPIO_F_Init();  //GPIO Port F Initialization

    Timer1_Init();  //Timer 1 Initialization

    while (1)  //Infinite Loop
    {

    }
}
