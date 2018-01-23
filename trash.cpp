#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;
const int trigPin = 9; 
const int echoPin = 10;
const int pin =  13;

const long minRange = 5; // in centimeters
long distance;
long time;

void setUp()
{
	char *setEchoPinWithDirectionInput[] = "gpioctl" + " dirin " + echoPin;
	system(setEchoPinWithDirectionInput);
	
	char *setTrigPinWithDirectionOutput[] = "gpioctl" + " dirout " + trigPin;
	system(setTrigPinWithDirectionOutput);
}

void delay()
{
	for(int i = 0; i<100; i++)
	{
		// wasing time LOL
	}
}

void loop()
{
	char *setTrigPinLow[] = "gpioctl dirout-low " +  trigPin;
	system(setTrigPinLow);
	delay();
	char *setTrigPinHigh[] = "gpioctl dirout-high " +  trigPin;
	system(setTrigPinHigh);
	delay();
	system(setTrigPinLow);
	
	// char *getEchoPin[] = "gpioctl get " + echoPin;
	// 
	
	char *getEchoPin[] = "fast-gpio read " + echoPin;
	
	time  = system(getEchoPin);
	
	distance = 0.034*time/2;
	
	if(distance<minRange)
	{
		
	void setup()
	{
		pinMode(ledPin, OUTPUT);      // sets the digital pin as output
	}

	void loop()
	{
		digitalWrite(ledPin, HIGH);   // sets the LED on
		//delay(1000);                  // waits for a second
		//digitalWrite(ledPin, LOW);    // sets the LED off
		//delay(1000);                  // waits for a second
	}	
	
	bool writeFile(){
	time_t timer = time(NULL);
	tm t = *localtime(&timer);
	std::ofstream fout("full.txt");
	if(!fout.is_open())
		return false;
	fout << "I'm full! Date: " << t .tm_mday << "/" << t.tm_mon << "/" << 1900+t.tm_year <<" Time: " << t.tm_hour << ":" << t.tm_min <<"\n";
	return true;
}

}

int main()
{
	setUp();
	loop();
	return 0;
}