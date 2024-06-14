#include <stdint.h>

// System Control Registers
#define SYSCTL_RCGCTIMER      (*((volatile uint32_t *)0x400FE604))
#define NVIC_EN0              (*((volatile uint32_t *)0xE000E100))

// Timer 1 Registers
#define TIMER1_CFG            (*((volatile uint32_t *)0x40031000))
#define TIMER1_TAMR           (*((volatile uint32_t *)0x40031004))
#define TIMER1_CTL            (*((volatile uint32_t *)0x4003100C))
#define TIMER1_GPTMTAILR      (*((volatile uint32_t *)0x40031028))
#define TIMER1_ICR            (*((volatile uint32_t *)0x40031024))
#define TIMER_IMR             (*((volatile uint32_t *)0x40031018))
#define TIMER1_MIS            (*((volatile unsigned long *)0x40031020))

//Timer 1 Initialization
void Timer1_Init()
{

// Enable Timer 1
    SYSCTL_RCGCTIMER |= (1 << 1);


// Configure Timer 1
    TIMER1_CTL &= (~(1 << 0)); // Disable Timer 1
    TIMER1_CFG = 0x04; // 16-bit timer configuration
    TIMER1_TAMR = 0x2; // Periodic Timer mode
    TIMER1_GPTMTAILR = 16000; // Load value for 1 ms delay
    NVIC_EN0 = (1 << 21); // Enable Timer 1A interrupt
    TIMER1_CTL = (1 << 0); // Enable Timer 1
    TIMER_IMR = (1 << 0); // Enable Timer 1A timeout interrupt
}
