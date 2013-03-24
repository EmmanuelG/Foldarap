#ifndef _SLAVE_COMMSH
#define _SLAVE_COMMSH
/*
   Functions to drive, and to return values from, a slave processor

   Adrian Bowyer 29 July 2012
*/

#ifdef REPRAPPRO_MULTIMATERIALS

extern float txyz[];
extern char slaveBuffer[];
extern long timeout;
#define TIMEOUT 4 // ms

float slaveDegHotend(uint8_t extruder);
void slaveSetTargetHotend(const float &celsius, uint8_t extruder);
float slaveDegTargetHotend(uint8_t extruder);
bool slaveIsHeatingHotend(uint8_t extruder);
bool slaveIsCoolingHotend(uint8_t extruder);
void slaveRemoteStep(int8_t extruder, int8_t v);
void slaveRemoteDir(int8_t extruder, bool forward);
void talkToSlave(char s[]);
char* listenToSlave();
void setup_slave();


FORCE_INLINE float slaveDegHotend(uint8_t extruder) { return txyz[extruder]; }
FORCE_INLINE void slaveSetTargetHotend(const float &celsius, uint8_t extruder) {txyz[extruder] = celsius; }
FORCE_INLINE float slaveDegTargetHotend(uint8_t extruder) { return txyz[extruder]; }
FORCE_INLINE bool slaveIsHeatingHotend(uint8_t extruder) { return false; }
FORCE_INLINE bool  slaveIsCoolingHotend(uint8_t extruder) { return false; }


FORCE_INLINE void slaveRemoteStep(int8_t extruder, int8_t v)
{

}

FORCE_INLINE void toggleSlaveClock()
{
	digitalWrite(SLAVE_CLOCK, !digitalRead(SLAVE_CLOCK));
}

FORCE_INLINE void slaveRemoteDir(int8_t extruder, bool forward)
{

}

FORCE_INLINE void talkToSlave(char s[]) { MYSERIAL1.println(s); }
FORCE_INLINE char* listenToSlave() 
{
	int c = 0;
	timeout = millis();
	int8_t i = 0;
	while(c != '\n' && (millis() - timeout < TIMEOUT))
	{
		while(!MYSERIAL1.available() && (millis() - timeout < TIMEOUT));
		c = MYSERIAL1.read();
		//timeout = millis();
		slaveBuffer[i] = (char)c;
		i++;
	}
	slaveBuffer[i] = 0;
	return slaveBuffer;
}

#endif

#endif

