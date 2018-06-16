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

              char lm35[20]=""; char fc28[16]="";
                                          char rc;



void main() 
{
             unsigned long rslm35,rsfc28;
             unsigned int temp,temp1;
             float x,m,m1; //FC28 Variables
             
             Lcd_Init();
              Lcd_Cmd(_Lcd_Clear);
              Lcd_Cmd(_Lcd_Cursor_OFF);
              Lcd_Cmd(_Lcd_Clear);            //LCD inititalization
              Adc_init();
                UART1_Init(9600);     // Initialize UART module at 9600 bps
               Delay_ms(100);     
                  // Wait for UART module to stabilize
                //   PWM1_Init(5000);
               TRISD.RD2=0;                      ///    led buzzer
                                            ///TRISB.RB4=1; // button

               Lcd_out(1,1, "Welcome NACC");
               Lcd_out(2,7, "to");
               Lcd_out(3,0, "KKWIEER,");
               Lcd_out(4,0,"Nashik");
               delay_ms(3000);
              Lcd_cmd(_Lcd_Clear);
                Lcd_out(1,1,"*-*-Farmosys-*-*-");
                PORTD.RD2=1;
                delay_ms(400);
                PORTD.RD2=0;
                  PORTD.RD2=1;
                delay_ms(200);
                PORTD.RD2=0;
                  PORTD.RD2=1;
                delay_ms(100);
                PORTD.RD2=0;

              while(1){  
               rslm35=adc_read(0);
              Lcd_out(2,1,"Temp:");
             // temp1=rslm35*500;
             temp=rslm35*0.4887585533;

               //lcd_out(1,1,"Temp:");
               InttoStr(temp,lm35);
               lcd_out(2,8,lm35);

               lcd_chr(2,15,223); //print at pos(row=1,col=13) "°" =223 =0xdf
               lcd_out(2,16,"C"); //celcius
               //UART1 DATA send
  
               UART1_write_text(lm35);
                      if(UART1_Data_Ready()==1){
               rc=UART1_Read();
               //lcd_chr(3,0,receive);
               if(rc=='1'){
               PORTD.RD2=1;
               }
               if(rc=='0')
               {
               PORTD.RD2=0;
                }
                 }

  
                  /*
              SOIL MOISTURE:
              */

              Lcd_out(3,0,"SOIL MOIST:");
              rsfc28=adc_read(1);
             //LongtoStr(result,display);
              //lcd_out(2,1,display);
               x=rsfc28-90;
                m=(933-x)/933;
                m1=100*m;          //SOil Moisture Calibration
                 FloattoStr(m1,fc28);
                 lcd_out(4,-2,fc28);
                     lcd_out_cp("%");
                /* if(PORTB.RB4==0)
                 { UART1_write_text(fc28);
                 
                 if(UART1_Data_Ready()==1){
               rc=UART1_Read();
               //lcd_chr(3,0,receive);
               if(rc=='1'){
               PWM1_Start();
               PWM1_Set_Duty(70);
                    // LATE.F0=1;
                     LATC.F2=1;
               }
               if(rc=='0')
               {
               LATC.F2=0;
                }
                 } */
                  

  
};
           }