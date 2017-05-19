/*!
 * @file sleepTest.ino
 * @brief Sleep mode
 * @n This example is the main configuration of lora mode and enter low power consumption.
 */

#include <LoRa.h>

#define NSS_PIN    	10 // 25
#define RESET_PIN 	9 // 26

LoRa lora;

/* The default pin:
/		SS:10
/		RST:9
*/

void setup()
{
	Serial.begin(115200);
	
	if(!lora.init(D2, D3)) {
		Serial.println("Starting LoRa failed!");
		while (1);
	}
	
	// frequency:the range is 137~1020Mhz for lora1276 ,137~525Mhz for lora1278
	setFrequency(434E6); 
	/*
	BW	        bandwidth , range from 0 to 9
	CR	        coding rate , range from 4/5 to 4/8---2,4,6,8
	SF	        spreading factor , range from 6 to 12
	CRC	        LR_PAYLOAD_CRC_ON:enable CRC,LR_PAYLOAD_CRC_OFF:disable CRC
	*/
	setRFpara(7, 2, 11, LR_PAYLOAD_CRC_ON);
	// preamble length is 6~65535
	setPreambleLen(12);
	// mode LR_IMPLICIT_HEADER_MODE or LR_EXPLICIT_HEADER_MODE
	setHeaderMode(LR_EXPLICIT_HEADER_MODE);
	// power level,0 to 15
	setTxPower(15);
	
	lora.sleep();  // Enter low power consumption
}
void loop()
{
	
}
