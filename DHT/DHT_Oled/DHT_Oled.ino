#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <dht_nonblocking.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

static const int DHT_SENSOR_PIN = 2;

DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


static bool measure_environment( float *temperature, float *humidity ){
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul ){
    if( dht_sensor.measure( temperature, humidity ) == true ){ 
      measurement_timestamp = millis( ); return( true );
    }
  }
  return( false );
}


void Screen (float temperature, float humidity){

  if 
  display.setTextSize(1);             
  display.print("Current Temp and Hum");
  display.setTextSize(2);             
  display.setCursor(0,20);
  display.print( temperature, 1 );
  display.println( " C" );
  display.print( humidity, 1 );
  display.println( " %" );
  display.display();
  display.clearDisplay(); 
  display.setCursor(0,0);

}

class Unit
{
  int updateRate; // How many times it gets updated 
  int lastUpdate; // Last time it was updated
};


void Initialize_screen(){
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
      Serial.println(F("SSD1306 allocation failed"));
      for(;;);
    }

  display.clearDisplay();
  display.setTextColor(WHITE);   
       
}

// ###################################################################################################

void setup( )
{
  Serial.begin(9600);

  Initialize_screen();

}


void loop( )
{
  float temperature;
  float humidity;

  if( measure_environment( &temperature, &humidity ) == true )
  {
    Screen(temperature, humidity);
  }
}

