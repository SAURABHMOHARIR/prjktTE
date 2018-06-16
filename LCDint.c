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
void main() {
            TRISC.F2=0;   //Motor
            TRISE.F0=0;   //Fan
            TRISD.F2=0;   //LED
            
           Lcd_Init();

         //  PWM2_Init(5000);
           
              Lcd_Cmd(_Lcd_Clear);
              Lcd_Cmd(_Lcd_Cursor_OFF);
                Lcd_out(1,1,"-----Farmosys----");
              Lcd_out(2,1,"SaMo Systems");
               delay_ms(3000);
                    lcd_cmd(_Lcd_clear);
                    PWM1_Init(5000);
           while(1){
                  //LATD.F2=1;  // LED On
                      LATE.F0=1;
                    //  PWM2_Start();
                  PWM1_Set_Duty(70);
                 //PWM2_Set_Duty(100);
                PWM1_Start();
                LATC.F2=1;
            }
}