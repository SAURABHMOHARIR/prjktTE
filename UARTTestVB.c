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


void main()
{
           //   char x1;
              TRISD.F0=0;
              TRISE.F0=0;
              Lcd_Init();
            //  UART1_Init(9600);     // Initialize UART module at 9600 bps
            //   Delay_ms(100);        // Wait for UART module to stabilize

             Lcd_Cmd(_Lcd_Cursor_OFF);
              Lcd_Cmd(_Lcd_Clear);            //LCD inititalization



              while(1){      //if(PORTB.RB5==0){

                         // Lcd_Cmd(_Lcd_Clear);
                          Lcd_out(1,1,"----Farmosys---");

             // UART1_Write_Text("35");

              //   if(UART1_data_Ready()==1)
                // {
                            // x1 = UART1_Read();
                             //UART1_write(x1);
                              // lcd_chr(4,15,x1);
                         //if(x1=='1')
                            //{
                            LATD.F0=1;
                            LATE.F0=1;
                            //Lcd_Out(2,1,x1);
                           // Lcd_out(3,1,"1= One");
                         //   }
                            //else   {
                          //  LATC.F5=0;
                            //LATE.F0=0;
                          //  }  }


                }
                }