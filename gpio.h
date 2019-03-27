/* While following the tutorial, I am always comparing the 
 * declarations and typedef, all the abstraction that lead to the
 * ease of programming of the EFM32 family HAL to this tutorial.
 * For me, the HAL of the EFM32 is way easier to understand while
 * both the naming and data stucture definations of the 
 * rPi3b+/BCM2837 seems to be much less structured in a way that
 * leverage the annoyance of the need of looking up reference 
 * manual, which is so badly documented comparing the EFM32 reference 
 * manual by the way. 
 * 
 * As an attempt to solve this problem(actually not really that 
 * big of problem, but anyway), I am trying to name registers
 * as clear as possible. And I am trying replicate the nice 
 * coherency of the EFM32 HAL as much as possible, and to make
 * the my 'own' HAL for the BCM2837 as consistant as the
 * EFM32 HAL as possible.
 *
 * What a great job Silicon Labs has done! Their documentations
 * and HAL are just amazing!
 */


/* ------------------ Back to Business ------------------- */

/* Define read/writ-ability flags */
#define _RW          volatile
#define _R           volatile
#define _W           volatile

/* Define MMIO physical address. Note that addresses seen on the
 * reference manual are bus addresses. A bus address looks something
 * like 0x7Enn nnnn maps to the physical address of 0x3Fnn nnnn.
 */
#define MMIO_BASE    0x3F000000


/* Reference: BCM2837-ARM-Peripherals Section 6 - GPIO */

/* Define the BASE address of the mem-mapped GPIO registers(i.e. the
 * first one of the 41 registers) 
 */
#define GPIO_BASE    ((volatile unsigned int*)(MMIO_BASE+0x00200000))

/* 32-bit registers! */

/* GPIO alt Function SELect registers */
#define GPFSEL0      ((_RW unsigned int*)(GPIO_BASE+0x00000000))
#define GPFSEL1      ((_RW unsigned int*)(GPIO_BASE+0x00000004))
#define GPFSEL2      ((_RW unsigned int*)(GPIO_BASE+0x00000008))
#define GPFSEL3      ((_RW unsigned int*)(GPIO_BASE+0x0000000C))
#define GPFSEL4      ((_RW unsigned int*)(GPIO_BASE+0x00000010))
#define GPFSEL5      ((_RW unsigned int*)(GPIO_BASE+0x00000014))

/* GPIO pin output SET registers */
#define GPSET0       ((_W unsigned int*)(GPIO_BASE+0x0000001C))
#define GPSET1       ((_W unsigned int*)(GPIO_BASE+0x00000020))

/* GPIO pin output CLeaR registers */
#define GPCLR0       ((_W unsigned int*)(GPIO_BASE+0x00000028))
#define GPCLR1       ((_W unsigned int*)(GPIO_BASE+0x0000002C))

/* GPIO pin LEVel registers */
#define GPLEV0       ((_R unsigned int*)(GPIO_BASE+0x00000034))
#define GPLEV1       ((_R unsigned int*)(GPIO_BASE+0x00000038))

/* GPIO pin Event Detect Status registers */
#define GPEDS0       ((_RW unsigned int*)(GPIO_BASE+0x00000040))
#define GPEDS1       ((_RW unsigned int*)(GPIO_BASE+0x00000044))

/* GPIO pin Rising edge detext ENable registers */
#define GPREN0       ((_RW unsigned int*)(GPIO_BASE+0x0000004C))
#define GPREN1       ((_RW unsigned int*)(GPIO_BASE+0x00000050))

/* GPIO pin Falling edge detect ENable registers */
#define GPFEN0       ((_RW unsigned int*)(GPIO_BASE+0x00000058))
#define GPFEN1       ((_RW unsigned int*)(GPIO_BASE+0x0000005C))

/* GPIO pin High detect ENable registers */
#define GPHEN0       ((_RW unsigned int*)(GPIO_BASE+0x00000064))
#define GPHEN1       ((_RW unsigned int*)(GPIO_BASE+0x00000068))

/* GPIO pin Low detext ENable registers */
#define GPLEN0       ((_RW unsigned int*)(GPIO_BASE+0x00000070))
#define GPLEN1       ((_RW unsigned int*)(GPIO_BASE+0x00000074))

/* GPIO pin Async Rising edge detect ENable registers */
#define GPAREN0      ((_RW unsigned int*)(GPIO_BASE+0x0000007C))
#define GPAREN1      ((_RW unsigned int*)(GPIO_BASE+0x00000080))

/* GPIO pin Async Falling edge detect ENable registers */
#define GPAFEN0      ((_RW unsigned int*)(GPIO_BASE+0x00000088))
#define GPAFEN1      ((_RW unsigned int*)(GPIO_BASE+0x0000008C))

/* GPIO pin Pull-up/Down enable register */
#define GPPUD        ((_RW unsigned int*)(GPIO_BASE+0x00000094))

/* GPIO pin Pull-up/Down enable CLocK registers */
/* PIN 0 - 31 */
#define GPPUDCLK0    ((_RW unsigned int*)(GPIO_BASE+0x00000098))
/* PIN 32 - 53 */
#define GPPUDCLK1    ((_RW unsigned int*)(GPIO_BASE+0x0000009C))


/* Bit masks for GPFSEL0 registers */

/* INPUT : 000 */
#define _GPIO_FSEL_INPUT_0     0b0
#define _GPIO_FSEL_INPUT_1     0b0
#define _GPIO_FSEL_INPUT_2     0b0
/* OUTPUT : 001 */
#define _GPIO_FSEL_OUTPUT_0     0b1
#define _GPIO_FSEL_OUTPUT_1     0b0
#define _GPIO_FSEL_OUTPUT_2     0b0
/* ALT0 : 100 */
#define _GPIO_FSEL_ALT0_0     0b0
#define _GPIO_FSEL_ALT0_1     0b0
#define _GPIO_FSEL_ALT0_2     0b1
/* ALT1 : 101 */
#define _GPIO_FSEL_ALT1_0     0b1
#define _GPIO_FSEL_ALT1_1     0b0
#define _GPIO_FSEL_ALT1_2     0b1
/* ALT2 : 110 */
#define _GPIO_FSEL_ALT2_0     0b0
#define _GPIO_FSEL_ALT2_1     0b1
#define _GPIO_FSEL_ALT2_2     0b1
/* ALT3 : 111 */
#define _GPIO_FSEL_ALT3_0     0b1
#define _GPIO_FSEL_ALT3_1     0b1
#define _GPIO_FSEL_ALT3_2     0b1
/* ALT4 : 011 */
#define _GPIO_FSEL_ALT4_0     0b1
#define _GPIO_FSEL_ALT4_1     0b1
#define _GPIO_FSEL_ALT4_2     0b0
/* ALT5 : 010 */
#define _GPIO_FSEL_ALT5_0     0b0
#define _GPIO_FSEL_ALT5_1     0b1
#define _GPIO_FSEL_ALT5_2     0b0

/* SHIFT for PINn : FSELn */

/* GPFSEL0 : pin 0 - 9 */
#define _GPIO_FSEL0_SHIFT       0
#define _GPIO_FSEL1_SHIFT       3
#define _GPIO_FSEL2_SHIFT       6
#define _GPIO_FSEL3_SHIFT       9
#define _GPIO_FSEL4_SHIFT       12
#define _GPIO_FSEL5_SHIFT       15
#define _GPIO_FSEL6_SHIFT       18
#define _GPIO_FSEL7_SHIFT       21
#define _GPIO_FSEL8_SHIFT       24
#define _GPIO_FSEL9_SHIFT       27

/* GPFSEL1 : pin 10 - 19 */
#define _GPIO_FSEL10_SHIFT       0
#define _GPIO_FSEL11_SHIFT       3
#define _GPIO_FSEL12_SHIFT       6
#define _GPIO_FSEL13_SHIFT       9
#define _GPIO_FSEL14_SHIFT       12
#define _GPIO_FSEL15_SHIFT       15
#define _GPIO_FSEL16_SHIFT       18
#define _GPIO_FSEL17_SHIFT       21
#define _GPIO_FSEL18_SHIFT       24
#define _GPIO_FSEL19_SHIFT       27

/* GPFSEL2 : pin 20 - 29 */
#define _GPIO_FSEL20_SHIFT       0
#define _GPIO_FSEL21_SHIFT       3
#define _GPIO_FSEL22_SHIFT       6
#define _GPIO_FSEL23_SHIFT       9
#define _GPIO_FSEL24_SHIFT       12
#define _GPIO_FSEL25_SHIFT       15
#define _GPIO_FSEL26_SHIFT       18
#define _GPIO_FSEL27_SHIFT       21
#define _GPIO_FSEL28_SHIFT       24
#define _GPIO_FSEL29_SHIFT       27

/* GPFSEL3 : pin 30 - 39 */
#define _GPIO_FSEL30_SHIFT       0
#define _GPIO_FSEL31_SHIFT       3
#define _GPIO_FSEL32_SHIFT       6
#define _GPIO_FSEL33_SHIFT       9
#define _GPIO_FSEL34_SHIFT       12
#define _GPIO_FSEL35_SHIFT       15
#define _GPIO_FSEL36_SHIFT       18
#define _GPIO_FSEL37_SHIFT       21
#define _GPIO_FSEL38_SHIFT       24
#define _GPIO_FSEL39_SHIFT       27

/* GPFSEL4 : pin 40 - 49 */
#define _GPIO_FSEL40_SHIFT       0
#define _GPIO_FSEL41_SHIFT       3
#define _GPIO_FSEL42_SHIFT       6
#define _GPIO_FSEL43_SHIFT       9
#define _GPIO_FSEL44_SHIFT       12
#define _GPIO_FSEL45_SHIFT       15
#define _GPIO_FSEL46_SHIFT       18
#define _GPIO_FSEL47_SHIFT       21
#define _GPIO_FSEL48_SHIFT       24
#define _GPIO_FSEL49_SHIFT       27

/* GPFSEL5 : pin 50 - 53 */
#define _GPIO_FSEL50_SHIFT       0
#define _GPIO_FSEL51_SHIFT       3
#define _GPIO_FSEL52_SHIFT       6
#define _GPIO_FSEL53_SHIFT       9

/* GPSETn register bitmasks */




/* GPCLRn register bitmasks */




/* GPLEVn register bitmasks */





/* GPEDSn register bitmasks */




/* GPRENn register bitmasks */




/* GPRENn register bitmasks */





/* GPHENn register bitmasks */






/* GPLENn register bitmasks */






/* GPARENn register bitmasks */






/* GPAFENn register bitmasks */





/* GPPUD register bitmask */

/* OFF : 00 */
#define _GPIO_PUD_OFF_0     0b0
#define _GPIO_PUD_OFF_1     0b0
/* PULL DOWN : 01 */
#define _GPIO_PUD_PD_0      0b1
#define _GPIO_PUD_PD_1      0b0
/* PULL UP : 10 */
#define _GPIO_PUD_PU_0      0b0
#define _GPIO_PUD_PU_1      0b1
/* RESERVED : 11 */



/* GPPUDCLKn register bitmasks */
#define _GPIO_PUDCLK_ASSERT  0b1

/* To assert PINn : GPPUDCLK{0/1} |=   _GPIO_PUDCLK_ASSERT \
 *                                     << _GPIO_PUDCLKn_SHIFT 
 * 
 * Use GPPUDCLK0 for pin 0  - 31
 * Use GPPUDCLK1 for pin 32 - 53
 */


/* SHIFT for pins */

/* GPPUDCLK0 : pin 0 - 31 */
#define _GPIO_PUDCLK0_SHIFT  0
#define _GPIO_PUDCLK1_SHIFT  1
#define _GPIO_PUDCLK2_SHIFT  2
#define _GPIO_PUDCLK3_SHIFT  3
#define _GPIO_PUDCLK4_SHIFT  4
#define _GPIO_PUDCLK5_SHIFT  5
#define _GPIO_PUDCLK6_SHIFT  6
#define _GPIO_PUDCLK7_SHIFT  7
#define _GPIO_PUDCLK8_SHIFT  8
#define _GPIO_PUDCLK9_SHIFT  9
#define _GPIO_PUDCLK10_SHIFT  10
#define _GPIO_PUDCLK11_SHIFT  11
#define _GPIO_PUDCLK12_SHIFT  12
#define _GPIO_PUDCLK13_SHIFT  13
#define _GPIO_PUDCLK14_SHIFT  14
#define _GPIO_PUDCLK15_SHIFT  15
#define _GPIO_PUDCLK16_SHIFT  16
#define _GPIO_PUDCLK17_SHIFT  17
#define _GPIO_PUDCLK18_SHIFT  18
#define _GPIO_PUDCLK19_SHIFT  19
#define _GPIO_PUDCLK20_SHIFT  20
#define _GPIO_PUDCLK21_SHIFT  21
#define _GPIO_PUDCLK22_SHIFT  22
#define _GPIO_PUDCLK23_SHIFT  23
#define _GPIO_PUDCLK24_SHIFT  24
#define _GPIO_PUDCLK25_SHIFT  25
#define _GPIO_PUDCLK26_SHIFT  26
#define _GPIO_PUDCLK27_SHIFT  27
#define _GPIO_PUDCLK28_SHIFT  28
#define _GPIO_PUDCLK29_SHIFT  29
#define _GPIO_PUDCLK30_SHIFT  30
#define _GPIO_PUDCLK31_SHIFT  31

/* GPPUDCLK1 : pin 32 - 53 */
#define _GPIO_PUDCLK32_SHIFT  0
#define _GPIO_PUDCLK33_SHIFT  1
#define _GPIO_PUDCLK34_SHIFT  2
#define _GPIO_PUDCLK35_SHIFT  3
#define _GPIO_PUDCLK36_SHIFT  4
#define _GPIO_PUDCLK37_SHIFT  5
#define _GPIO_PUDCLK38_SHIFT  6
#define _GPIO_PUDCLK39_SHIFT  7
#define _GPIO_PUDCLK40_SHIFT  8
#define _GPIO_PUDCLK41_SHIFT  9
#define _GPIO_PUDCLK42_SHIFT  10
#define _GPIO_PUDCLK43_SHIFT  11
#define _GPIO_PUDCLK44_SHIFT  12
#define _GPIO_PUDCLK45_SHIFT  13
#define _GPIO_PUDCLK46_SHIFT  14
#define _GPIO_PUDCLK47_SHIFT  15
#define _GPIO_PUDCLK48_SHIFT  16
#define _GPIO_PUDCLK49_SHIFT  17
#define _GPIO_PUDCLK50_SHIFT  18
#define _GPIO_PUDCLK51_SHIFT  19
#define _GPIO_PUDCLK52_SHIFT  20
#define _GPIO_PUDCLK53_SHIFT  21

























