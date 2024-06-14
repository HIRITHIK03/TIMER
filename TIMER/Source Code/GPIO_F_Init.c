#include <stdint.h>

// System Control Registers
#define SYSCTL_RCGCGPIO       (*((volatile uint32_t *)0x400FE608))

// GPIO Port F Registers
#define GPIO_PORTF_DIR        (*((volatile uint32_t *)0x4005D400))
#define GPIO_PORTF_DEN        (*((volatile uint32_t *)0x4005D51C))

//GPIO Port F Initialization
void GPIO_F_Init()
{
    // Enable Port F clock
    SYSCTL_RCGCGPIO |= 0x20;
    GPIO_PORTF_DIR |= 0xFF; // Set all pins as outputs
    GPIO_PORTF_DEN |= 0xFF; // Enable digital functionality for all pins
}

