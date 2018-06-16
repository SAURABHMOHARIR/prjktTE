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

              char lm35[20]="";
              char fc28[16]="";


             /*unsigned char seconds,minute,hour,weekday, days, month, years;
void settime (void);
void Read_Time(void)
{
  I2C1_Start();
  I2C1_Wr(0xD0);
  I2C1_Wr(0);
  I2C1_Repeated_Start();
  I2C1_Wr(0xD1);
  seconds =I2C1_Rd(1);       //seconds   //convert bcd to ascii for lcd
  minute =I2C1_Rd(1);     //minute       //convert bcd to ascii for lcd
  hour=I2C1_Rd(1);        //hour        //convert bcd to ascii for lcd
  weekday =I2C1_Rd(1);  //weekday ex-monday=2   //convert bcd to ascii for lcd
  days =I2C1_Rd(1);       //day         //convert bcd to ascii for lcd
  month =I2C1_Rd(1);        //month       //convert bcd to ascii for lcd
  years =I2C1_Rd(0);      //year         //convert bcd to ascii for lcd
  I2C1_Stop();

  LCD_Out(2,1,"Date:");
   LCD_Chr(2,7,((days&0xf0)>>4)+0x30);//convert bcd to ascii for lcd
   LCD_Chr_cp((days&0x0f)+0x30);  //convert bcd to ascii for lcd
   LCD_Chr_cp(':');
   LCD_Chr_cp(((month&0xf0)>>4)+0x30); //convert bcd to ascii for lcd
   LCD_Chr_cp((month&0x0f)+0x30);   //convert bcd to ascii for lcd
    LCD_Chr_cp(':');
  LCD_Chr_cp(((years&0xf0)>>4)+0x30);  //convert bcd to ascii for lcdii
   LCD_Chr_cp((years&0x0f)+0x30);      //convert bcd to ascii for lcd


 LCD_Out(3,-3,"Time:");
   LCD_Chr(3,2,((hour&0xf0)>>4)+0x30);
   LCD_Chr_cp((hour&0x0f)+0x30);
   LCD_Chr_cp(':');
   LCD_Chr_cp(((minute&0xf0)>>4)+0x30);
   LCD_Chr_cp((minute&0x0f)+0x30);
    LCD_Chr_cp(':');
   LCD_Chr_cp(((seconds&0xf0)>>4)+0x30);
   LCD_Chr_cp((seconds&0x0f)+0x30);
}
      */

void main() 
{ 

 unsigned long rslm35,rsfc28;
 unsigned int temp;      //Lm35 Variables
              char x1;
            float x,m,m1;
TRISC.F5=0;
                   //Switch input
            //FC28 Variables
                /**        Initialization                          **/
              //  TRISB.F5=1;
                Lcd_Init();
              Adc_init();
                 UART1_Init(9600);     // Initialize UART module at 9600 bps
               Delay_ms(100);        // Wait for UART module to stabilize

                // I2C1_Init(32000);
                // settime ();

              Lcd_Cmd(_Lcd_Cursor_OFF);
              Lcd_Cmd(_Lcd_Clear);            //LCD inititalization



              while(1){      //if(PORTB.RB5==0){

                         // Lcd_Cmd(_Lcd_Clear);
                          Lcd_out(1,1,"----Farmosys---");
               rslm35=adc_read(0);
              Lcd_out(2,1,"Temp:");
             // temp1=rslm35*500;
             temp=rslm35*0.4887585533;
              InttoStr(temp,lm35);
              lcd_out(2,5,lm35);
               /*IntTostr(temp,display);
                 lcd_out_cp(display);
              */
              lcd_chr(2,15,223); //print at pos(row=1,col=13) "°" =223 =0xdf
              lcd_out(2,16,"C"); //celcius
              // UART1_Write_Text("Temperature:");
           UART1_write_text(lm35);
                                                  /*
              SOIL MOISTURE:
            */
            Lcd_out(3,-2,"SOIL MOIST:");
              rsfc28=adc_read(1);
                               //LongtoStr(result,display);
              //lcd_out(2,1,display);
                x=rsfc28-90;
                m=(933-x)/933;
                m1=100*m;
                 FloattoStr(m1,fc28);
                 lcd_out(4,1,fc28);
                 lcd_out_cp("%");
                 if(UART1_data_Ready()==1)
                 {
                             x1 = UART1_Read();
                             UART1_write(x1);
                              // lcd_chr(4,15,x1);
                         if(x1=='1')
                            {LATC.F5=1;;}
                            else   {
                            LATC.F5=0;;}  }
             //   if(m1<50){
                 //    PWM1_Start();  // start PWM1
  //PWM2_Start();  // start PWM2

 // PWM1_Set_Duty(70); // Set current duty for PWM1


            // UART1_Write_Text("Soil Mositure:");
             //UART1_write(fc28);
          //   Delay_ms(500);        // 500ms delay
                   // UART1_write_text(fc28);

             
             
                }
                }
                          /*
              else    if(PORTB.RB5==1){
                         Lcd_cmd(_Lcd_clear);
                         Lcd_out(1,1,"----Farmosys----");
             while(1){                     // perform initialization
            Read_Time();      // read time from RTC(DS1307)
             Delay_ms(999); 
             if(PORTB.RB5==0) break;}

}               }}

  /*
void settime (void)
{
   I2C1_Init(100000);     // initialize full master mode
   I2C1_Start();          // issue start signal
   I2C1_Wr(0xD0);         // address DS1307
   I2C1_Wr(0);            // start from word at address (REG0)
   I2C1_Wr(0x80);         // write $80 to REG0. (pause counter + 0 sec)
   I2C1_Wr(0x45); //Mins           // write 0 to minutes word to (REG1)
   I2C1_Wr(0x14);     //hrs    // write 17 to hours word (24-hours mode)(REG2)
   I2C1_Wr(0x07);     //day    // write 2 - Monday (REG3)
   I2C1_Wr(0x22);    //date     // write 4 to date word (REG4)
   I2C1_Wr(0x04);     //month    // write 5 (May) to month word (REG5)
   I2C1_Wr(0x17);    //year     // write 01 to year word (REG6)
   I2C1_Stop();           // issue stop signal

   I2C1_Start();          // issue start signal
   I2C1_Wr(0xD0);         // address DS1307
   I2C1_Wr(0);            // start from word at address 0
   I2C1_Wr(0);            // write 0 to REG0 (enable counting + 0 sec)
   I2C1_Stop();           // issue stop signal
     delay_ms(500);       */