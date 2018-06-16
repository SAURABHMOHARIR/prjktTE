char uart_rd;
void main() {
    ////TRISB=0x00;
   // OSCCON=0x76;       //Configure OSCON Register to use
                       //internal oscillator. Please check datasheet

    UART1_Init(9600);     // Initialize UART module at 9600 bps
    Delay_ms(100);        // Wait for UART module to stabilize

    UART1_Write_Text("Hello World");
    Delay_ms(500);        // 500ms delay
    //UART1_Write_Text("h");


    while (1) {                     // Endless loop
    if (UART1_Data_Ready()) {     // If data is received,
             uart_rd = UART1_Read();     // read the received data
             switch(uart_rd){
             case '1':LATB0_bit = 1;
                      LATB1_bit = 0;
                      LATB2_bit = 0;

             break;

             case '2':LATB0_bit = 0;
                      LATB1_bit = 1;
                      LATB2_bit = 0;

             break;
             case '3':LATB0_bit = 0;
                      LATB1_bit = 0;
                      LATB2_bit = 1;

             break;
              default:LATB0_bit = 0;
                      LATB1_bit = 0;
                      LATB2_bit = 0;
             break;

                 }
           }
         }

}