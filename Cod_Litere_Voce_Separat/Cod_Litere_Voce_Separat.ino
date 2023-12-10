#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup()
{
  tmrpcm.speakerPin = 9;

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }
  tmrpcm.setVolume(7);

  Serial.println("OK");
}

int numarLitera = 1;

void loop() {
  if (numarLitera < 8)
  {
    if (!tmrpcm.isPlaying())
    {
      tmrpcm.play("type.wav");
      delay(3000);
      switch (numarLitera)
      {
        case 1:
          tmrpcm.play("A.wav");
          break;
        case 2:
          tmrpcm.play("B.wav");
          break;
        case 3:
          tmrpcm.play("C.wav");
          break;
        case 4:
          tmrpcm.play("D.wav");
          break;
        case 5:
          tmrpcm.play("E.wav");
          break;
        case 6:
          tmrpcm.play("F.wav");
          break;
        case 7:
          tmrpcm.play("G.wav");
          break;
        default:
          break;
      }
      delay(1000);
      numarLitera++;
    }


  }
}
