/*!
 * @file sendTest.ino
 * @brief Send data
 * @n This example is send.
 */

#include <LoRa.h>

LoRa lora;

uint8_t counter = 0;
uint8_t sendBuf[] = "HelloWorld!";

/* The default pin:
/		SS:10
/		RST:9
*/

void setup()
{
	Serial.begin(115200);
	
	if(!lora.init()) {
		Serial.println("Starting LoRa failed!");
		while (1);
	}
}
void loop()
{
	Serial.print("Sending packet: ");
	Serial.println(counter);

	// send packet
	lora.sendPackage(sendBuf, sizeof(sendBuf)); // sending data
	lora.idle();    // turn to standby mode

	counter++;
#if 0
	if(counter%10 == 0) {
		lora.sleep();
		delay (5000);// sleep 5 seconds
	}
#endif

	delay(500);
}
