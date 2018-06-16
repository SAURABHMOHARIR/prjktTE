void delay()
{
Delay_ms(1000);
}

void main() {

         /* TRISA=0;
          TRISB=0;
          TRISC=0;
          TRISD=0;
            while(1){
           LATA=0xFF;
           LATB=0xFF;
           LATC=0xFF;
           LATD=0xFF;
           delay(1000);
           LATA=0x00;
           LATB=0x00;
           LATC=0x00;
           LATD=0x00;*/
           TRISC5_bit=0
           TRISD2_bit=0;
           while(1){
           LATD.F2=1;
           LATC.F5=1;
           delay(1000);
           LATD.F2=0;
           LATC.F5=0;
           }



           }

        }