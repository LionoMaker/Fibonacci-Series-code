



#include<Arduino.h>

int return_Fib_number(int n)
{
  if (n < 2) // checking if number less than 2 return as it is: Example: 0, 1
  {
    return n;
  } 

  return return_Fib_number(n-1) + return_Fib_number(n-2); // using recursive call or itself call

}
void Print_Fib_Series(int size){

  for (int i = 0; i < size; i++) 
  {
    // Serial.print("Fibonacci_series");
    Serial.print("\t");
    Serial.print(return_Fib_number(i));
  }
  
}

void setup(){

  Serial.begin(115200);

}

void loop(){
  int size_of_Fib;

  while (!Serial.available());

  while (Serial.available())
  {
    size_of_Fib=Serial.readStringUntil('\n').toInt();
    Serial.print("size_of_Fib: ");
    Serial.println(size_of_Fib);
  }
  Print_Fib_Series(size_of_Fib);

  while (1); // print one time
}