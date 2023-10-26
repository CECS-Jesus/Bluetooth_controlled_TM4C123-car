#include "Bluetooth.h"

void UART0_Init(void);
void UART1_Init(void);

void Bluetooth_Init(void) {
	UART0_Init();
	UART1_Init();
}

void UART0_Init(void) {

}

void UART0_OutChar(unsigned char data) {

}

void UART0_OutString(unsigned char *pt) {

}

void UART1_Init(void) {
	// Activate Clocks
	SYSCTL_RCGC1_R |= SYSCTL_RCGC1_UART1;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB;

	UART1_CTL_R &= ~UART_CTL_UARTEN;		// disable UART
	// Data Communication Mode, Buad Rate = 57600
	UART1_IBRD_R = 54;						// IBRN = int(50,000,000 / (16 * 57600)) = int(54.25347)
	UART1_FBRD_R = 16;						// FBRD = round(.25347 * 64) = 16
											// 8 bit word length (no parity bits, one stop bit, FIFOs)
	UART1_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);
	UART1_CTL_R |= 0x301;					// enable UART for both Rx and Tx
	GPIO_PORTB_AFSEL_R |= 0x03;				// enable alt funct on PB1,PB0
	GPIO_PORTB_DEN_R |= 0x03;				// enable digital I/O on PB1,PB0
											// configure PB1,PB0 as UART1
	GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xFFFFFF00)+0x00000011;
	GPIO_PORTB_AMSEL_R &= ~0x03;			// disable analog functionality on PB1,PB0
}

//------------UART1_InChar------------
// Wait for new serial port input
// Input: none
// Output: ASCII code for key typed
unsigned char UART1_InChar(void){
	while((UART1_FR_R&UART_FR_RXFE) != 0);
	return((unsigned char)(UART1_DR_R&0xFF));
}

void BLT_InString(unsigned char *bufPt) {

}
