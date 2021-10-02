#define BLYNK_PRINT Serial // definisi serial pada blynk

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h> //file untuk modul wifi
#include <BlynkSimpleEsp8266.h> //file untuk blynk
#include <Servo.h> // ini library untuk servo

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "zMlosSJ-Kq5MgKkD5smdE6Z_OzgHBxBI"; // token yang dikirim dari blynk ke email masing masing
char ssid[] = "AndroidAP3F5F";
char pass[] = "safwan030804";
Servo gerak_servo;

BLYNK_WRITE(V1)
{
  gerak_servo.write(param.asInt()); // fungsi blynk untuk mengatur pin virtual V1 yang ada pada aplikasi blynk
}

void setup()
{
  // Debug console
  Serial.begin(9600); //memual serial monitor dengan baudrate 9600

  Blynk.begin(auth,ssid,pass); // Menjalankan blynk sesuai token, wifi, dan passwordnya

  gerak_servo.attach(2); // setting pin gpio 2 ke servo, D4 = 2 (https://lh3.googleusercontent.com/proxy/xI55intCGTb4Hsuy3cV6skphjhZNMHRMQRGcodfuAlhEspM-MmIfJmt54qA4VSgbdKrSfziM0AcZIj2AfFod5vrWxN4j7w)
}

void loop()
{
  Blynk.run(); // memulai blynk
}
