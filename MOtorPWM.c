void main() {
         TRISC.F3==0;
         TRISE.F0=0;
         PWM1_Init(5000);
         while(1){
               PWM1_Start();
               PWM1_Set_Duty(70);
                     LATE.F0=1;
         }
}