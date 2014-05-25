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

void setup(){
  pinMode(reset, OUTPUT);
  pinMode(sce, OUTPUT);
  pinMode(dc, OUTPUT);
  pinMode(din, OUTPUT);
  pinMode(clk, OUTPUT);
  delay(1000);
  digitalWrite(reset, LOW);
  digitalWrite(reset, HIGH);
  
  lcd_write_cmd(0x21);
  lcd_write_cmd(0xb8);
  lcd_write_cmd(0x04);
  lcd_write_cmd(0x14);
  lcd_write_cmd(0x20);
  lcd_write_cmd(0x09);
}

void loop(){
}
