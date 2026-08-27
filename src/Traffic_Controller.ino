// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>


#define WR 15
#define WG 2
#define ER 0
#define EG 4
#define SR 16
#define SG 17
#define NR 5
#define NG 18
#define Nir1 19
#define Nir2 23
#define Nir3 13
#define Eir1 12
#define Eir2 14
#define Eir3 17
#define Sir1 26
#define Sir2 25
#define Sir3 34
#define Wir1 33
#define Wir2 32
#define Wir3 35

// LiquidCrystal_I2C lcd(0x27, 16, 2);








void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Nir1, INPUT);
  pinMode(Nir2, INPUT);
  pinMode(Nir3, INPUT);
  pinMode(Sir1, INPUT);
  pinMode(Sir2, INPUT);
  pinMode(Sir3, INPUT);
  pinMode(Eir1, INPUT);
  pinMode(Eir2, INPUT);
  pinMode(Eir3, INPUT);
  pinMode(Wir1, INPUT);
  pinMode(Wir2, INPUT);
  pinMode(Wir3, INPUT);

  pinMode(WR, OUTPUT);
  pinMode(WG, OUTPUT);
  pinMode(ER, OUTPUT);
  pinMode(EG, OUTPUT);
  pinMode(NR, OUTPUT);
  pinMode(NG, OUTPUT);
  pinMode(SR, OUTPUT);
  pinMode(SG, OUTPUT);
  
  // lcd.init();
  // lcd.backlight();

  // lcd.setCursor(0, 0);      // column, row
  // lcd.print("Dynamic Traffic");

  // lcd.setCursor(0, 1);
  // lcd.print("Light Control");
}
int countN=0,countS=0,countE=0,countW=0;
int turn = 1;// N = 1, E = 2, S = 3, W = 4 
int temp = countN;
void loop() {

     int Er1 = digitalRead(Eir1);
     
     if(Er1==0){
      delay(70);
      int Er2 = digitalRead(Eir2);
      if(Er2==0){
        countE=countE+1;
      }
     }

     int Wr1 = digitalRead(Wir1);
     if(Wr1==0){
      delay(70);
      int Wr2 = digitalRead(Wir2);
      if(Wr2==0){
        countW=countW+1;
      }
     }

     int Nr1 = digitalRead(Nir1);
     if(Nr1==0){
      delay(70);
      int Nr2 = digitalRead(Nir2);
      if(Nr2==0){
        countN=countN+1;
      }
     }

    int Sr1 = digitalRead(Sir1);
     if(Sr1==0){
      delay(70);
      int Sr2 = digitalRead(Sir2);
      if(Sr2==0){
        countS=countS+1;
      }
     }

    if(temp==0){
      // maximum of rest
      int maxi = 0;
      int newturn=turn;
      if(turn==1){
        digitalWrite(NG,0);
        digitalWrite(NR,1);
        maxi = max(countE,maxi);
        if(maxi==countE){
          newturn = 2;
        }
        maxi = max(countS,maxi);
        if(maxi==countS){
          newturn = 3;
        }
        maxi = max(countW,maxi);
        if(maxi==countW){
          newturn = 4;
        }
      }
      else if(turn==2){
        digitalWrite(EG,0);
        digitalWrite(ER,1);
        maxi = max(countN,maxi);
        if(maxi==countN){
          newturn = 1;
        }
        maxi = max(countS,maxi);
        if(maxi==countS){
          newturn = 3;
        }
        maxi = max(countW,maxi);
        if(maxi==countW){
          newturn = 4;
        }
      } else if(turn==3){
        digitalWrite(SG,0);
        digitalWrite(SR,1);
        maxi = max(countE,maxi);
        if(maxi==countE){
          newturn = 2;
        }
        maxi = max(countN,maxi);
        if(maxi==countN){
          newturn = 1;
        }
        maxi = max(countW,maxi);
        if(maxi==countW){
          newturn = 4;
        }
      } else if(turn==4){
        digitalWrite(WG,0);
        digitalWrite(WR,1);
        maxi = max(countE,maxi);
        if(maxi==countE){
          newturn = 2;
        }
        maxi = max(countS,maxi);
        if(maxi==countS){
          newturn = 3;
        }
        maxi = max(countN,maxi);
        if(maxi==countN){
          newturn = 1;
        }
      }

      turn = newturn;
      temp = maxi;
      if(turn==1){
        digitalWrite(NG,1);
        digitalWrite(NR,0);
      }
      else if(turn==2){
        digitalWrite(EG,1);
        digitalWrite(ER,0);
      } else if(turn==3){
        digitalWrite(SG,1);
        digitalWrite(SR,0);
      } else if(turn==4){
        digitalWrite(WG,1);
        digitalWrite(WR,0);
      }
      //maximum turn
      // temp maximum store
      // turn temp-- and agar kahi par gadi aa rahi hai usko bhi count karenga
    }

    if(turn==1){
      //read green third sensor
      int Nr3 = digitalRead(Nir3);
      if(Nr3==0){
        temp = temp-1;
        countN = countN - 1;
      }
      // temp--

    }
    else if(turn==2){
      int Er3 = digitalRead(Eir3);
      if(Er3==0){
        temp = temp-1;
        countE = countE - 1;
      }
    }
    else if(turn==3){
      int Sr3 = digitalRead(Sir3);
      if(Sr3==0){
        temp = temp-1;
        countS = countS - 1;
      }
    }
    else if(turn==4){
        int Wr3 = digitalRead(Wir3);
      if(Wr3==0){
        temp = temp-1;
        countW = countW - 1;
      }
    }



    //lcd
  // lcd.setCursor(0, 0);      // column, row
  // lcd.print("L1=");
  // lcd.setCursor(3, 0);      // column, row
  // lcd.print(countN);// triple bit
  char c1 = (turn == 1 ? 'G' : 'R');
  // lcd.setCursor(6, 0);      // column, row
  // lcd.print(c1);// triple bit

  // lcd.setCursor(8, 0);      // column, row
  // lcd.print("L2=");
  // lcd.setCursor(11, 0);      // column, row
  // lcd.print(countE);// triple bit
  char c2 = (turn == 2 ? 'G' : 'R');
  // lcd.setCursor(14, 0);      // column, row
  // lcd.print(c2);// triple bit



// 2

  // lcd.setCursor(0, 1);      // column, row
  // lcd.print("L3=");
  // lcd.setCursor(3, 1);      // column, row
  // lcd.print(countS);// triple bit
  char c3 = (turn == 3 ? 'G' : 'R');
  // lcd.setCursor(6, 1);      // column, row
  // lcd.print(c3);// triple bit

  // lcd.setCursor(8, 1);      // column, row
  // lcd.print("L4=");
  // lcd.setCursor(11, 1);      // column, row
  // lcd.print(countW);// triple bit
  char c4 = (turn == 4 ? 'G' : 'R');
  // lcd.setCursor(14, 1);      // column, row
  // lcd.print(c4);// triple bit
  // // put your main code here, to run repeatedly:
  Serial.print("L1=");
  Serial.print(countN);
  Serial.println(c1);

  Serial.print("L2=");
  Serial.print(countE);
  Serial.println(c2);

  Serial.print("L3=");
  Serial.print(countS);
  Serial.println(c3);

  Serial.print("L4=");
  Serial.print(countW);
  Serial.println(c4);
  delay(200);
  
}
