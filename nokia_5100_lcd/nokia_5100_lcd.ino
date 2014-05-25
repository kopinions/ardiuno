#include "font.h"

int reset = 0;
int sce = 1;
int dc = 2;
int din = 3;
int clk = 4;
int nc = 5;

void lcd_write_cmd(byte cmd)
{
  digitalWrite(dc, LOW);
  digitalWrite(sce, LOW);
  shiftOut(din, clk, MSBFIRST, cmd);
  digitalWrite(sce, HIGH);
}

void lcd_write_data(byte data)
{
  digitalWrite(dc, HIGH);
  digitalWrite(sce, LOW);
  shiftOut(din, clk, MSBFIRST, data);
  digitalWrite(sce, HIGH);
}

void lcd_write_string(char * string) {
  while(*string) {
    lcd_write_char(*string++);
  }
  lcd_write_data(0x00);
}

void lcd_write_char(char c){
  for(int i=0; i< 5; i++) {
    lcd_write_data(ASCII[c-0x20][i]);
  }
  lcd_write_data(0x00);
}

void lcd_set_xy(int x, int y) {
  lcd_write_cmd(0x40 | y);
  lcd_write_cmd(0x80 | x);
}


void setup(){
  pinMode(reset, OUTPUT);
  pinMode(sce, OUTPUT);
  pinMode(dc, OUTPUT);
  pinMode(din, OUTPUT);
  pinMode(clk, OUTPUT);
  digitalWrite(reset, LOW);
  digitalWrite(reset, HIGH);
  
  lcd_write_cmd(0x21);
  lcd_write_cmd(0xb8);
  lcd_write_cmd(0x04);
  lcd_write_cmd(0x14);
  lcd_write_cmd(0x20);
  lcd_write_cmd(0x0c);
  for(int i=0; i<504; i++)
  {
    lcd_write_data(0x00);
  }
  lcd_set_xy(2,2);
  lcd_write_string("Hello World");
}

void loop(){
}
