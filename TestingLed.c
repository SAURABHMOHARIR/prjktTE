void main() {
       TRISC=0xF0;
       while(1){
       LATC.F5=1;
       Delay_ms(1000);
       LATC.F5=0;
       }
}