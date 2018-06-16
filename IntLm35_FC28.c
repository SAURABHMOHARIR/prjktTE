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




void main() {  unsigned long rslm35,rsfc28;
unsigned int temp,temp1;      //Lm35 Variables

//TRISC.F5=0;
float x,m,m1; //FC28 Variables
                Lcd_Init();
              Lcd_Cmd(_Lcd_Clear);
              Lcd_Cmd(_Lcd_Cursor_OFF);
              Lcd_Cmd(_Lcd_Clear);            //LCD inititalization
              Adc_init();
              Lcd_out(1,1,"----Farmosys---");
              UART1_Init(9600);     // Initialize UART module at 9600 bps
               Delay_ms(100);        // Wait for UART module to stabilize

              while(1){
               rslm35=adc_read(0);
              Lcd_out(2,1,"Temp:");
             // temp1=rslm35*500;
             temp=rslm35*0.4887585533;
         //comp(display);
//lcd_out(1,1,"Temp:");
InttoStr(temp,lm35);
lcd_out(2,8,lm35);
/*IntTostr(temp,display);
lcd_out_cp(display);
  */
lcd_chr(2,15,223); //print at pos(row=1,col=13) "°" =223 =0xdf
lcd_out(2,16,"C"); //celcius
   // UART1_Write_Text("Temperature:");
             UART1_write_text(lm35);         /*
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
            // UART1_Write_Text("Soil Mositure:");
             //UART1_write(fc28);
    Delay_ms(500);        // 500ms delay
                   // UART1_write_text(fc28);

}               }