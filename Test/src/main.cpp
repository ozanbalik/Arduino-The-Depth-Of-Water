#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

LiquidCrystal_I2C lcd(0x27,16,2);
#define POWER_PIN  7
#define SIGNAL_PIN A0

int value = 0; // variable to store the sensor value

void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  lcd.begin();
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds$
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  if (value<=250){ 
		Serial.println("Water level: 0mm - Empty!");                      
     lcd.setCursor(0,0); 
     lcd.print("Water level:");
     lcd.setCursor(0,1);
     lcd.print("0mm - Empty!");
     

	}
	else if (value>250 && value<=325){ 
		Serial.println("Water level: 0mm to 5mm");
    lcd.setCursor(0,0); 
    lcd.print("Water level:");
    lcd.setCursor(0,1);
    lcd.print("0mm to 5mm");
    
	}
	else if (value>325 && value<=375){ 
		Serial.println("Water level: 5mm to 10mm");
    lcd.setCursor(0,0); 
    lcd.print("Water level:");
    lcd.setCursor(0,1);
    lcd.print("5mm to 10mm");
     
	}
	else if (value>375 && value<=425){ 
		Serial.println("Water level: 10mm to 15mm");
    lcd.setCursor(0,0); 
    lcd.print("Water level:");
    lcd.setCursor(0,1);
    lcd.print("10mm to 15mm");
      
	}	
	else if (value>425 && value<=460){ 
		Serial.println("Water level: 15mm to 20mm");
    lcd.setCursor(0,0); 
    lcd.print("Water level:");
    lcd.setCursor(0,1);
    lcd.print("15mm to 20mm");
      
	}
	else if (value>460 && value<=485){ 
		Serial.println("Water level: 20mm to 25mm");
    lcd.setCursor(0,0); 
    lcd.print("Water level:");
    lcd.setCursor(0,1);
    lcd.print("20mm to 25mm");
     
	}
	else if (value>485 && value<=500){ 
		Serial.println("Water level: 25mm to 30mm");
    lcd.setCursor(0,0); 
    lcd.print("Water level:");
    lcd.setCursor(0,1);
    lcd.print("25mm to 30mm");
     
	}
	else if (value>500 && value<=525){ 
		Serial.println("Water level: 30mm to 35mm");
    lcd.setCursor(0,0); 
    lcd.print("Water level:");
    lcd.setCursor(0,1);
    lcd.print("30mm to 35mm");
    
	}
	else if (value>525){ 
		Serial.println("Water level: 35mm to 40mm");
    lcd.setCursor(0,0); 
    lcd.print("Water level:");
    lcd.setCursor(0,1);
    lcd.print("35mm to 40mm");
     
	}

  delay(1000);
  lcd.clear();
}

//The sensor value can be change if you are using a different sensor