#include "led.h"
#if (LED_PIN > -1)
#include "Marlin.h"
#include "temperature.h"

static unsigned long previous_millis_led=0;
static unsigned long previous_millis_toggle=0;

void led_init()
{
    SET_OUTPUT(LED_PIN);
}

void led_status()
{
   if (((millis() - previous_millis_led) < LED_UPDATE_INTERVAL))
     return;
   previous_millis_led=millis();
/* // Not sure what this did - AB
   if (degTargetHotend(active_extruder) > HEATER_0_MINTEMP)
   {
     if (((millis() - previous_millis_toggle) < LED_HOTEND_ACTIVE_FLASH))
   }
   else
   {
     WRITE(LED_PIN, READ(HEATER_0_PIN)); // Just tell us if the extruder heater is on
   }*/
  if(READ(HEATER_0_PIN))
     WRITE(LED_PIN, 1);  // Heater on
  else
     TOGGLE(LED_PIN);  // Heater off
}


#endif //LED_PIN > -1


