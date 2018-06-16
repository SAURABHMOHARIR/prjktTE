// LCD module connections
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
// End LCD module connections

        void main() {
        unsigned short result;
        unsigned int temp,temp1;
        TRISC.F5=0;
                      Lcd_Init();
                      Lcd_Cmd(_Lcd_Clear);
                      Lcd_Cmd(_Lcd_Cursor_OFF);
                     /* Lcd_out(1,1,"-----Farmosys----");
                      Lcd_out(2,1,"Saurabh Moharir");
                      Lcd_out(3,-2,"TE Electronics");
                      Lcd_out(4,1,"T120133836");   */
                  //    Delay_ms(5000);
                      Lcd_Cmd(_Lcd_Clear);
                            //Adc_Init();
                      adcon1=0x08;

            while(1)
        {       // Lcd_out(1,1,"Temp:");

        result=adc_read(0);
              comp(result);        // lcd_out(2,1,result);
        //temp1=result*500;
          temp=result*0.4887585533;
                 //comp(display);
        lcd_out(1,1,"Temp:");
        IntTostr(temp,display);
        lcd_out_cp(display);

        //lcd_chr(1,14,223); //print at pos(row=1,col=13) "°" =223 =0xdf
        lcd_out_cp("%"); //celcius
        //delay_ms(1000);
        }
        }