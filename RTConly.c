sbit LCD_RS at LATC0_bit;
sbit LCD_EN at LATC1_bit;
sbit LCD_D4 at LATD4_bit;
sbit LCD_D5 at LATD5_bit;
sbit LCD_D6 at LATD6_bit;
sbit LCD_D7 at LATD7_bit;

sbit LCD_RS_Direction at TRISC0_bit;
sbit LCD_EN_Direction at TRISC1_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;


unsigned short read_ds1307(unsigned short address)
{
  unsigned short read_data;
  I2C1_Start();
  I2C1_Wr(0xD0); //address 0x68 followed by direction bit (0 for write, 1 for read) 0x68 followed by 0 --> 0xD0
  I2C1_Wr(address);
  I2C1_Repeated_Start();
  I2C1_Wr(0xD1); //0x68 followed by 1 --> 0xD1
  read_data=I2C1_Rd(0);
  I2C1_Stop();
  return(read_data);
}

unsigned char MSB(unsigned char x)           //Display Most Significant Bit of BCD number
{
  return ((x >> 4) + '0');
}

unsigned char  LSB(unsigned char x)          //Display Least Significant Bit of BCD number
{
  return ((x & 0x0F) + '0');
}

//Global Variables:
int second;
int minute;
int hour;
int hr;
int day;
int dday;
int month;
int year;
int ap;

char time[] = "00:00:00 PM";
char date[] = "00-00-00";


void main()
{
   ////OSCCON = 0x66;      // Configure to use 8MHz internal oscillator
   I2C1_Init(32000); //DS1307 I2C is running at 100KHz
   Lcd_Init();        // Initialize LCD

   Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off

   Lcd_out(1,1,"Time:");
   Lcd_out(2,1,"Date:");

   while(1)
{
      second = read_ds1307(0);
      minute = read_ds1307(1);
      hour = read_ds1307(2);
      hr = hour & 0b00011111;
      ap = hour & 0b00100000;
      dday = read_ds1307(3);
      day = read_ds1307(4);
      month = read_ds1307(5);
      year = read_ds1307(6);

      time[0] = MSB(hr);
      time[1] = LSB(hr);
      time[3] = MSB(minute);
      time[4] = LSB(minute);
      time[6] = MSB(second);
      time[7] = LSB(second);
      date[0] = MSB(day);
      date[1] = LSB(day);
      date[3] = MSB(month);
      date[4] = LSB(month);
      date[6] = MSB(year);
      date[7] = LSB(year);
      if(ap)
      {
         time[9] = 'P';
         time[10] = 'M';
      }
      else
      {
         time[9] = 'A';
         time[10] = 'M';
      }

      Lcd_out(1, 6, time);
      Lcd_out(2, 6, date);
      Delay_ms(100);

}
}