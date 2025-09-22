#include <MQ2_NAJIKHUL_UMAM.h>   // memanggil library MQ2

MQ2 mq(A0);  // membuat object sensor MQ2, terhubung ke pin analog A0

void setup() {
  Serial.begin(9600);   // memulai komunikasi serial dengan baudrate 9600
  mq.begin();           // menjalankan fungsi kalibrasi sensor (menentukan Ro)
}

void loop() {
  float ratio = mq.getRatio();  // membaca perbandingan Rs/Ro dari sensor

  // hitung konsentrasi gas berdasarkan grafik MQ2 (dengan slope & intercept yang sudah didefinisikan)
  float lpg   = mq.getGasPPM(ratio, GAS_LPG);      // konsentrasi gas LPG (ppm)
  float co    = mq.getGasPPM(ratio, GAS_CO);       // konsentrasi gas CO (ppm)
  float smoke = mq.getGasPPM(ratio, GAS_SMOKE);    // konsentrasi asap (ppm)

  // tampilkan hasil ke Serial Monitor
  Serial.print("LPG: "); 
  Serial.print(lpg); 
  Serial.println(" ppm");

  Serial.print("CO: "); 
  Serial.print(co); 
  Serial.println(" ppm");

  Serial.print("Smoke: "); 
  Serial.print(smoke); 
  Serial.println(" ppm");

  Serial.println("----");  // pemisah biar lebih mudah dibaca

  delay(1000);  // tunggu 1 detik sebelum pembacaan berikutnya

  //HAPPY LEARNING HEHEHE
}
