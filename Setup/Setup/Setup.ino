void setup()
{
	//Pin Mode declaration (OUTPUT or INPUT) AND Initial state declaration (LOW / HIGH) 
  //Soil moisture
  pinMode(soilMoisterVcc,OUTPUT);
  digitalWrite(soilMoisterVcc,LOW);
  //DHT
  pinMode(DHTVCC,OUTPUT);
  digitalWrite(DHTVCC,LOW);
  pinMode(DHTPIN,INPUT);
  //LDR
  pinMode(ptrVcc,OUTPUT);
  digitalWrite(ptrVcc,LOW);
  //Relays
  pinMode(relay_pump, OUTPUT);
  pinMode(relay_leds, OUTPUT);
  
  //Relays should be working as HIGH = 0, but sometimes they're reversed
  //If the relay is ON whenever it should be OFF, Then put LOW in the state below and inverse the states in the analyses functions
  digitalWrite(relay_pump,HIGH); 
  digitalWrite(relay_leds,HIGH);
  // Be careful when you try to debug your code, you must put the baudrate to 115200
  Serial.begin(115200); // See the connection status in Serial Monitor
  delay(10);
   //BLYNK
  Blynk.begin(auth, ssid, pass); // Connexion to Blynk 
  dht.begin();
	//Blynk widgets
  led1.on();
  led2.on();
  // Setup a function to be called every intervals
  //The "getData" function will be called every 12000 ms = 12s this is easily changed and is meant to be much higher (each 15 or 30 mins)
  //I put 12s to check if everything is working fine, the sensor data as well as the blynk connexion 
  timer.setInterval(12000L,getData);

}