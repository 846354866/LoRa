/*!
 * @file receiverTest.ino
 * @brief Received data
 * @n This example is receive.
 */

#include <LoRa.h>

LoRa lora;

uint8_t len;
uint8_t rxBuf[32];

void setup()
{
	Serial.begin(115200);

	pinMode(LED_BUILTIN, OUTPUT);
	Serial.println("Receiver Test");

	if(!lora.init()) {
		Serial.println("Starting LoRa failed!");
		while (1);
	}

	lora.rxInit();    
}
void loop()
{
	if(lora.waitIrq()) {   // wait for RXDONE interrupt
		lora.clearIRQFlags();
		len = lora.receivePackage(rxBuf);  // receive data
		Serial.write(rxBuf, len);    
		Serial.println();
		lora.rxInit();    // wait for packet from master
		
		// print RSSI of packet
    	Serial.print("with RSSI ");
    	Serial.println(lora.readRSSI());

		static uint8_t i;
		i = ~i;
		digitalWrite(LED_BUILTIN, i);
	}
}
