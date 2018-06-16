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

      char display[3]="";

   /*   void comp(unsigned char ch){

     if(ch>=102){
         PORTC.F5=1;
     }
     else
         if(ch<=102)
             PORTC.F5=0;

      } */
void main() 
{
             unsigned long result;float x,m,m1;
              Lcd_Init();
              Lcd_Cmd(_Lcd_Clear);
              Lcd_Cmd(_Lcd_Cursor_OFF);
              Lcd_Cmd(_Lcd_Clear);
              Adc_init();

              while(1){
              Lcd_out(1,1,"SOIL MOIST:");
              result=adc_read(1);
              //LongtoStr(result,display);
              //lcd_out(2,1,display);
                x=result-90;
                m=(933-x)/933;
                m1=100*m;
                 FloattoStr(m1,display);
                 lcd_out(2,1,display);
                         lcd_out_cp("%");
              
               }
              }
          //int b=8;
        //float fin,pcnt;
      // int a;    char c;
//TRISC.F5=0;

                    //Adc_Init();

            //  byteTostr(b,c);

                        // lcd_out_cp(b);
                 //  lcd_out(1,1,"SOIL MOIST:");


//{     

     // if(result>=483)
       // {
          //  fin=(Ch_result)*0.004105571;
         //   fin=(result-483)*0.004887585;
       // pcnt=(fin/1.83773216)*100;
        //humid=*Ch_result;
      //a=round(pcnt);
     //   sprintf(vstring,"%d",a);
       // stringlcd(vstring);


     // comp(result);        // lcd_out(2,1,result);
//temp1=result*500;
  //temp=result*0.4887585533;
         //comp(display);

//IntTostr(pcnt,display);
//lcd_out_cp(2,1,display);

//lcd_chr(1,14,223); //print at pos(row=1,col=13) "°" =223 =0xdf
 //PERCENTAGE soil mositure         (water content)
//delay_ms(1000);
//}     //  }
