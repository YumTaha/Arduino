#include <Keypad.h>

const int onePins = 7; 
int all[onePins] = {5, 6, 7, 8, 9, 10, 11};
int zero[] = {5, 6, 7, 9, 10, 11};
int one[] = {5, 7};
int two[] = {5, 6, 8, 9, 11};
int three[] = {5, 6, 7, 8, 11};
int four[] = {5, 7, 8, 10};
int five[] = {6, 7, 8, 10, 11};
int six[] = {6, 7, 8, 9, 10, 11};
int seven[] = {5, 7, 11};
int eight[] = {5, 6, 7, 8, 9, 10, 11};
int nine[] = {5, 6, 7, 8, 10, 11};

int number[onePins];
int choice_number = 0;



void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}


void setup(){
  for (int i = 0; i < onePins; i++) {
    pinMode(all[i], OUTPUT);
  }
  Serial.begin(9600);
}


void loop(){
  if (choice_number > 9) choice_number = 0;
  switch (choice_number) {
    case 0:
      copyArray(zero, number, sizeof(zero) / sizeof(zero[0]));
      break;
    case 1:
      copyArray(one, number, sizeof(one) / sizeof(one[0]));
      break;
    case 2:
      copyArray(two, number, sizeof(two) / sizeof(two[0]));
      break;
    case 3:
      copyArray(three, number, sizeof(three) / sizeof(three[0]));
      break;
    case 4:
      copyArray(four, number, sizeof(four) / sizeof(four[0]));
      break;
    case 5:
      copyArray(five, number, sizeof(five) / sizeof(five[0]));
      break;
    case 6:
      copyArray(six, number, sizeof(six) / sizeof(six[0]));
      break;
    case 7:
      copyArray(seven, number, sizeof(seven) / sizeof(seven[0]));
      break;
    case 8:
      copyArray(eight, number, sizeof(eight) / sizeof(eight[0]));
      break;
    case 9:
      copyArray(nine, number, sizeof(nine) / sizeof(nine[0]));
      break;
    default:
      Serial.println("Invalid Number");
      break;
    }


  for (auto i: number) {
    digitalWrite(i, HIGH);
  }
  delay(1000);

  for (auto y: all) {
    digitalWrite(y, LOW);

  }
  choice_number++;
  Serial.println(choice_number);
}

