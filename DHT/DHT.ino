// Libraries
#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11


// Variables
int humi_sensor = 3;
int led = A2;
DHT_nonblocking dht_sensor( humi_sensor, DHT_SENSOR_TYPE );

static bool measure_environment( float *temperature, float *humidity )
  {
    static unsigned long measurement_timestamp = millis( );

    /* Measure once every four seconds. */
    if( millis( ) - measurement_timestamp > 3000ul )
    {
      if( dht_sensor.measure( temperature, humidity ) == true )
      {
        measurement_timestamp = millis( );
        return( true );
      }
    }

    return( false );
  }

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature;
  float humidity;

  /* Measure temperature and humidity.  If the functions returns
     true, then a measurement is available. */
  if( measure_environment( &temperature, &humidity ) == true )
  { 
    if (humidity >= 55)
    {
      analogWrite(led, 255);
    }else{
      analogWrite(led, 255);
      delay(100);
      analogWrite(led, 0);
    }
    // Serial.print( "T = " );
    // Serial.print( temperature, 1 );
    // Serial.print( " deg. C, H = " );
    Serial.print( "H = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
}
}