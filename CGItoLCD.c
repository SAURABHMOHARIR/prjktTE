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

                char m3[20]="";
                char n3[20]="";
void main() {
           
            float temp,t1,cnt;
             Lcd_Init();
            Adc_init();


            Lcd_Cmd(_Lcd_Clear);
              Lcd_Cmd(_Lcd_Cursor_OFF);
              
               Lcd_out(1,1,"Curnt to Volt:");
                 delay_ms(300);
                    lcd_cmd(_Lcd_clear);
                    
                      while(1){
                                   Lcd_out(1,1,"Volt:");
                                     temp=adc_read(0);
                                      t1= temp*0.0048758553;
                                      floattoStr(t1,m3);
                                      lcd_out(1,7,m3);
                                      Lcd_out(2,1,"Curnt:");
                                      cnt=t1/25000;
                                      floattoStr(cnt,n3);
                                      Lcd_out(2,7,n3);



            }
}