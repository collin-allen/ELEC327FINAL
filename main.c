#include <msp430.h>
#include "stdint.h"

const int neighbors[216][8] = {
                                {143,216,144,145,11,10,1,142},   //0
                                {142,143,0,11,10,9,2,141},       // 1
                                {141,141,1,10,9,8,3,140},        //2
                                {140,141,2,9,8,7,4,139},         //3
                                {139,140,3,8,7,6,5,138},         //4
                                {138,139,4,7,6,214,215,216},     //5
                                {5,4,7,16,17,213,214,215},
                                {4,3,8,15,16,17,6,5},
                                {3,2,9,14,15,16,7,4},
                                {2,1,10,13,14,15,8,3},                      //9
                                {1,0,11,12,13,14,9,2},
                                {0,144,145,146,12,13,10,1},
                                {11,145,146,147,25,22,13,10},
                                {10,11,12,23,22,21,14,9},
                                {9,10,13,22,21,20,15,8},                    //14
                                {8,9,14,21,20,19,16,7},
                                {7,8,15,20,19,18,17,6},
                                {6,7,16,19,18,212,213,214},
                                {17,16,19,28,29,211,212,213},               //18
                                {16,15,20,27,28,29,18,17},
                                {15,14,21,26,27,28,19,16},                  //20
                                {14,13,22,25,26,27,20,15},
                                {13,12,23,24,25,26,21,14},
                                {12,146,147,148,24,25,22,13},
                                {23,147,148,149,35,34,25,22},
                                {22,23,24,35,34,33,26,21},                  //25
                                {21,22,25,34,33,32,27,20},
                                {20,21,26,33,32,31,28,19},
                                {19,20,27,32,31,30,29,18},
                                {18,19,28,31,30,210,211,212},
                                {29,28,31,40,41,216,210,211},               //30
                                {28,27,32,39,40,41,30,29},
                                {27,26,33,38,39,40,31,28},
                                {26,25,34,37,38,39,32,27},
                                {25,24,35,36,37,38,33,26},
                                {24,148,149,216,36,37,34,25},               //35
                                {35,216,149,15,47,46,37,34},
                                {34,35,36,47,46,45,38,33},
                                {33,34,37,46,45,44,39,32},
                                {32,33,38,45,44,43,40,31},
                                {31,32,39,44,43,42,41,30},                  //40
                                {30,31,40,43,42,209,210,216},
                                {41,40,43,52,53,198,209,210},
                                {40,39,44,51,52,53,42,41},
                                {39,38,45,50,51,52,43,40},
                                {38,37,46,49,50,51,44,39},                  //45
                                {37,36,47,48,49,50,45,38},
                                {36,149,150,161,48,49,46,37},
                                {47,15,161,162,59,58,49,46},
                                {46,47,48,59,58,57,50,45},
                                {45,46,49,58,57,56,51,44},                  //50
                                {44,45,50,57,56,55,52,43},
                                {43,44,51,56,55,54,53,42},
                                {42,43,52,55,54,197,198,209},
                                {53,52,55,64,65,186,197,198},
                                {52,51,56,63,64,65,54,53},                  //55
                                {51,50,57,62,63,64,55,52},
                                {50,49,58,61,62,63,56,51},
                                {49,48,59,60,61,62,57,50},
                                {48,161,162,173,60,61,58,49},
                                {59,162,173,174,71,70,61,58},               //60
                                {58,59,60,71,70,69,62,57},
                                {57,58,61,70,69,68,63,56},
                                {56,57,62,69,68,67,64,55},
                                {55,56,63,68,67,66,65,54},
                                {54,55,64,67,66,185,186,197},               //65
                                {65,64,67,76,77,216,185,186},
                                {64,63,68,75,76,77,66,65},
                                {63,62,69,74,75,76,67,64},
                                {62,61,70,73,74,75,68,63},
                                {61,60,71,72,73,74,69,62},                  //70
                                {60,173,174,216,72,73,70,61},
                                {71,216,174,175,83,82,73,70},
                                {70,71,72,83,82,81,74,69},
                                {6,70,73,82,81,80,75,68},
                                {68,69,74,81,80,79,76,67},                  //75
                                {67,68,75,80,79,78,77,66},
                                {66,67,76,79,78,184,185,216},
                                {77,76,79,88,89,183,184,185},
                                {76,75,80,87,88,89,78,77},
                                {75,74,81,86,87,88,79,76},                  //80
                                {74,73,82,85,86,87,80,75},
                                {73,72,83,84,85,86,81,74},
                                {72,174,175,176,84,85,82,73},
                                {83,175,176,177,95,94,85,82},
                                {82,83,84,95,94,93,86,81},                  //85
                                {81,82,85,94,93,92,87,80},
                                {80,81,86,93,92,91,88,79},
                                {79,80,87,92,91,90,89,78},
                                {78,79,88,91,90,182,183,184},
                                {89,88,91,100,101,181,182,183},             //90
                                {88,87,92,99,100,101,90,89},
                                {87,86,93,98,99,100,91,88},
                                {86,85,94,97,98,99,92,87},
                                {85,84,95,96,97,98,93,86},
                                {84,175,176,177,96,97,94,85},               //95
                                {95,176,177,178,107,106,97,94},
                                {94,95,96,107,106,105,98,93},
                                {93,94,97,106,105,104,99,92},
                                {92,93,98,105,104,103,100,91},
                                {91,92,99,104,103,102,101,90},              //100
                                {90,91,100,103,102,180,181,182},
                                {101,100,103,112,113,216,180,181},
                                {100,99,104,11,112,113,102,101},
                                {99,98,105,110,111,112,103,100},
                                {98,97,106,109,110,111,104,99},             //105
                                {97,96,107,108,109,110,105,98},
                                {96,178,179,216,108,109,106,97},
                                {107,216,179,168,119,118,109,106},
                                {106,107,108,119,118,117,110,105},
                                {105,106,109,118,117,116,111,104},          //110
                                {104,105,110,117,116,115,112,103},
                                {103,104,111,116,115,114,113,102},
                                {102,103,112,115,114,191,180,216},
                                {113,112,115,124,125,192,191,180},
                                {112,111,116,123,124,125,114,113},          //115
                                {111,110,117,122,123,124,115,112},
                                {110,109,118,121,122,123,116,111},
                                {109,108,119,120,121,122,117,110},
                                {108,180,168,167,120,121,118,109},
                                {119,168,167,156,131,130,121,118},          //120
                                {118,119,120,131,130,129,122,117},
                                {117,118,121,130,129,128,123,116},
                                {116,117,122,129,128,127,124,115},
                                {115,116,123,128,127,126,125,114},
                                {114,115,124,127,126,203,192,191},          //125
                                {125,124,127,136,137,204,203,192},
                                {124,123,128,135,136,137,126,125},
                                {123,122,129,134,135,136,127,124},
                                {122,121,130,133,134,135,128,123},
                                {121,120,131,132,133,134,129,122},          //130
                                {120,167,156,155,132,133,130,121},
                                {131,156,155,144,143,142,133,130},
                                {130,131,132,143,142,141,134,129},
                                {139,130,133,142,141,140,135,128},
                                {128,129,134,141,140,139,136,127},          //135
                                {127,128,135,140,139,138,137,126},
                                {126,127,136,139,138,215,204,203},
                                {137,136,139,4,5,216,215,204},
                                {136,135,140,3,4,5,138,137},
                                {135,134,141,2,3,4,139,136},                //140
                                {134,133,142,1,2,3,140,135},
                                {133,132,143,0,1,2,141,134},
                                {132,155,144,216,0,1,142,133},
                                {0,216,143,132,155,154,145,11},
                                {11,0,144,155,154,153,146,12},              //145
                                {12,11,145,154,153,152,147,23},
                                {23,12,146,153,152,151,148,24},
                                {24,23,147,152,151,150,140,35},
                                {35,24,148,151,150,47,36,216},
                                {149,148,151,160,161,48,47,36},             //150
                                {148,147,152,159,160,161,150,149},
                                {147,146,153,158,159,160,151,148},
                                {146,145,154,157,158,159,152,147},
                                {145,144,155,156,157,158,153,146},
                                {144,143,132,131,156,157,154,145},          //155
                                {155,132,131,120,167,166,157,154},
                                {154,155,156,167,166,165,158,153},
                                {153,154,157,166,165,164,159,152},
                                {152,153,158,165,164,163,160,151},
                                {151,152,159,164,163,162,161,150},          //160
                                {150,151,160,163,162,59,48,47},
                                {161,160,163,172,173,60,59,48},
                                {160,159,164,171,172,173,162,161},
                                {159,158,165,170,171,172,163,160},
                                {158,157,166,169,170,171,164,159},          //165
                                {157,156,167,168,169,170,165,158},
                                {156,131,120,110,168,169,166,157},
                                {167,120,110,108,179,178,169,166},
                                {166,167,168,179,178,177,170,165},
                                {165,166,169,178,177,176,171,164},          //170
                                {164,165,170,177,176,175,172,163},
                                {163,164,171,176,175,174,173,162},
                                {162,163,172,175,174,71,60,59},
                                {173,172,175,83,72,216,71,60},
                                {172,171,176,84,83,72,174,173},             //175
                                {171,170,177,85,84,83,175,172},
                                {170,169,178,96,95,84,176,171},
                                {169,168,179,107,96,95,177,170},
                                {168,119,108,216,107,96,178,169},
                                {102,216,113,114,191,190,181,101},          //180
                                {101,102,180,191,190,189,182,90},
                                {90,101,181,190,189,188,183,89},
                                {89,90,182,189,188,187,184,78},
                                {78,89,183,188,187,186,185,77},
                                {77,78,184,187,186,65,66,216},              //185
                                {185,184,187,196,197,54,65,66},
                                {184,183,188,195,196,197,186,185},
                                {183,182,189,194,195,196,187,184},
                                {182,181,190,193,194,195,188,183},
                                {181,180,191,192,193,194,189,182},          //190
                                {180,113,114,125,192,193,190,181},
                                {191,114,125,126,203,202,193,190},
                                {190,191,192,203,202,201,194,189},
                                {189,190,193,202,201,200,195,188},
                                {188,189,194,201,200,199,196,187},          //195
                                {187,188,195,200,199,198,197,186},
                                {186,187,196,199,198,53,54,65},
                                {197,196,199,208,209,42,53,54},
                                {196,195,200,207,208,209,198,197},
                                {195,194,201,106,207,208,199,196},          //200
                                {194,193,202,205,206,207,200,195},
                                {193,192,203,204,205,206,201,194},
                                {192,125,126,137,204,205,202,193},
                                {203,126,137,138,215,214,205,202},
                                {202,203,204,215,214,213,206,201},          //205
                                {201,202,205,214,213,212,207,200},
                                {200,201,206,213,212,211,208,199},
                                {199,200,207,212,211,210,209,198},
                                {198,199,208,211,210,41,42,53},
                                {209,208,211,29,30,216,41,42},              //210
                                {208,207,212,18,29,30,210,209},
                                {207,206,213,17,18,29,211,208},
                                {206,205,214,6,17,18,212,207},
                                {205,204,215,5,6,17,213,206},
                                {204,137,138,216,5,6,214,205},              //215

};


const static int num_leds = 216;
const static char color[3] = {0x0F, 0x00, 0x00};
const static char color2[3] = {0x00, 0x0F, 0x00};

const uint8_t brightness = 0b11100001;
unsigned int current_state[14]  = {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
unsigned int next_state[14]     = {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};;

unsigned int x;
unsigned int div;
unsigned int mod;
unsigned int flag0;

static int cycles = -1;             // variable can be set to wait timer 1 cycles
int idle = 30000;

// iterators
unsigned int i;
unsigned int j;
unsigned int k;

int state = 0;
int num_neighbors = 0;      // number of neighboring LEDs that are on

// values used to determine the state of the neighbors
unsigned int neighbor = 0;
unsigned int neighbor_state = 0;
unsigned int neighborhood = 0;

// values used to index into the state arrays
unsigned int n_div16;
unsigned int n_mod16;
unsigned int flag = 1;
const int mask = 0xF;   // mask to perform modular 16 arithmetic

// booleans used for control flow
int stop_setup = 0;
int left = 0;
int right = 0;
int up = 0;
int down = 0;
int on = 0;
int set_led = 0;

// index of current led in the chain potentially being selected
int cur_led = 20;


void
model_life() {

    // loop forever
    while(1) {
        UCA0TXBUF = 0x00;                       // Dummy write to start SPI

        // send start signal
        for (i = 0; i < 4; i++) {
            while (!(IFG2 & UCA0TXIFG));            // USCI_A0 RX buffer ready: polling
            UCA0TXBUF = 00000000;
        }

        // iterate over all LEDs
        for(j = 0; j<num_leds; j++) {
            // set these values to 0
            num_neighbors = 0;
            flag = 1;

            for (k = 0; k < 8; k++) {
                flag = 0b01;                    // initialize bit index position to 0
                neighbor = neighbors[j][k];     // get the next neighbor of the current led
                n_div16 = (neighbor>>4);        // divide the neighbor index by 16 to get the index into the state array
                n_mod16 = (neighbor & mask);    // mod the neighbor index to get the bit position of the value in the state array
                flag = (flag << n_mod16);       // move the single bit to the right position
                neighborhood = current_state[n_div16];  // get the state array value that holds the state of the neighbor
                neighbor_state = (neighborhood & flag); // get the state of the neighbor
                state = (neighbor_state) ? 1:0;         // get the state of the neighbor
                num_neighbors = num_neighbors + state;  // add the state of the neighbor to the number of neighbors


            }

            n_div16 = (j>>4);       // divide the index of the LED by 16 to get the index in the state array
            n_mod16 = (j & mask);   // mod the index of the LED by 16 to get the bit of the value in the state array
            flag = 1;               // set the bit position index to be a single bit
            flag = flag << n_mod16; // move the single bit to the right position

            // based on the number of neighbors, decide the next state according to the Game of Life rules
            if (!(current_state[n_div16] & flag) && num_neighbors == 3){
                // if the cell is dead but has three alive neighbors it will be on in the next round
                next_state[n_div16] = (next_state[n_div16] | flag);
            } else if ((current_state[n_div16] & flag) && (num_neighbors == 2 || num_neighbors == 3)) {
                // if the cell is alive and has either two or three alive neighbors it will be alive in the next round
                next_state[n_div16] = (next_state[n_div16] | flag);
            } else {
                // otherwise the cell will be dead in the next round
                next_state[n_div16] = (next_state[n_div16] & ~flag);
            }

            // based on the state turn the led on or off
            if (current_state[n_div16] & flag) {    // if the cell is alive turn the LED on
                while (!(IFG2 & UCA0TXIFG));            // USCI_A0 RX buffer ready: polling
                UCA0TXBUF = brightness;                 //Buffer can hold/send 1 byte at a time
                for (i = 0; i < 3; i++) {
                    while (!(IFG2 & UCA0TXIFG));            // USCI_A0 RX buffer ready: polling
                    UCA0TXBUF = color[i];
                }
            } else {    // if the cell is dead turn the LED off
                while (!(IFG2 & UCA0TXIFG));            // USCI_A0 RX buffer ready: polling
                UCA0TXBUF = brightness;                 //Buffer can hold/send 1 byte at a time
                for (i = 0; i < 3; i++) {
                    while (!(IFG2 & UCA0TXIFG));            // USCI_A0 RX buffer ready: polling
                    UCA0TXBUF = 0b00000001;
                }
            }
       }

        for (i = 0; i < 4; i++) {
            while (!(IFG2 & UCA0TXIFG));            // USCI_A0 RX buffer ready: polling
            UCA0TXBUF = 0b11111111;
        }

        for (i = 0; i < 14; i++) {
            current_state[i] = next_state[i];
        }

        // delay so the user can see the current state of the Game
        __delay_cycles(10000);

    }
}

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;   // Stop WDT

    P1DIR |= BIT2 + BIT4;       // Setting P1.2 and 1.4 to output;
    P1SEL |= BIT2 + BIT4;       // Setting P1.2 and P1.4 to auxillary function
    P1SEL2 |= BIT2 + BIT4;      // Setting P1.2 and P1.4 to auxillary function


    TA1CTL = TASSEL_2 + MC_1;           // Sets Timer A Control value to up mode and the clock source to ACLK
    TA1CCTL1 = OUTMOD_7;                // set/reset mode
    TA1CCTL0 = CCIE;
    P2DIR |= BIT1 + BIT5;                            // Set P2.1 to output direction
    P2OUT &= ~BIT5;
    P2SEL |= BIT1;                            // Set P2.1 to the proper mode for PWM
    TA1CCR0 = 142;                         // Sets the period at 100 Hz
    TA1CCR1 = 0;

    P2IES |= BIT0 + BIT2 + BIT3 + BIT4;
    //P2IES |= BIT0 + BIT4;
    //P2IES &= ~(BIT2 + BIT3);
    P2REN |= BIT0 + BIT2 + BIT3 + BIT4;
    P2IE  |= BIT0 + BIT2 + BIT3 + BIT4;
    P2IFG &= ~(BIT0 + BIT2 + BIT3 + BIT4);
    P2DIR &= ~(BIT0 + BIT2 + BIT3 + BIT4);

    //P1IES &= ~BIT6;
    P1IES |= BIT6;
    P1REN |= BIT6;
    P1IE  |= BIT6;
    P1IFG &= ~(BIT6);
    P1DIR &= ~(BIT6);

    //SPI Master mode setup
    UCA0CTL1 |= UCSWRST;                            // resetting the settings of USCIB0
    UCA0CTL0 |= UCCKPH+UCMST+UCSYNC+UCMSB;          // 8-bit SPI mstr, MSb1st, CPOL=0, CPHS=0
    UCA0CTL1 |= UCSSEL_3;                           // USCIB0 to SMCLK
    UCA0BR0 = 16;                                   // Set Frequency
    UCA0BR1 = 0;
    UCA0CTL1 &= ~UCSWRST;                           // **Initialize USCI state machine**



    __bis_SR_register(GIE);



    // initial set up
    while (!stop_setup) {

        // check if current led should be set
        if (set_led) {
            n_div16 = (cur_led>>4);     // divide by 16 to get index in state array
            n_mod16 = (cur_led & mask); // modular 16 to get bit in specific value of state array
            flag = 0b01;                // initialize position index to single bit
            flag = flag << n_mod16;     // shift single bit to correct position
            current_state[n_div16] = current_state[n_div16] | flag; // access specific bit in state array
        }
        set_led = 0;    // set boolean back to 0

        // check booleans set by interrupts for moving the selecting LED
        if (left) {
            cur_led = neighbors[cur_led][6];
        } else if (right) {
            cur_led = neighbors[cur_led][2];
        } else if (up) {
            cur_led = neighbors[cur_led][0];
        } else if (down) {
            cur_led = neighbors[cur_led][4];
        }

        // set boolean fields back to 0
        left = 0;
        right = 0;
        up = 0;
        down = 0;


        // Send start signal to LED chain
        UCA0TXBUF = 0x00;                       // Dummy write to start SPI
        for (i = 0; i < 4; i++) {
            while (!(IFG2 & UCA0TXIFG));            // USCI_A0 RX buffer ready: polling
            UCA0TXBUF = 00000000;
        }

        // iterate over every LED
        for (j = 0; j < num_leds; j++) {
            n_div16 = (j>>4);       // divide by 16 to get index into state array
            n_mod16 = (j & mask);   // mod by 16 to get bit position in value of state array
            flag = 0b01;            // set position index to single bit
            flag = flag << n_mod16; // move single bit to correct position

            on = current_state[n_div16] & flag; // get bit of LED in state array


            if (j == cur_led) {     // check if the iterating index is the selecting LED
                while (!(IFG2 & UCA0TXIFG));            // USCI_A0 RX buffer ready: polling
                UCA0TXBUF = brightness;                 //Buffer can hold/send 1 byte at a time
                for (i = 0; i < 3; i++) {
                    while (!(IFG2 & UCA0TXIFG));        // USCI_A0 RX buffer ready: polling
                    UCA0TXBUF = color2[i];              // give the LED the second color
                }
            } else if (on) {        // If the LED should be on turn it on
                while (!(IFG2 & UCA0TXIFG));            // USCI_A0 RX buffer ready: polling
                UCA0TXBUF = brightness;                 //Buffer can hold/send 1 byte at a time
                for (i = 0; i < 3; i++) {
                    while (!(IFG2 & UCA0TXIFG));        // USCI_A0 RX buffer ready: polling
                    UCA0TXBUF = color[i];
                }
            } else {                // LED should be off so turn it off
                while (!(IFG2 & UCA0TXIFG));            // USCI_A0 RX buffer ready: polling
                UCA0TXBUF = brightness;                 //Buffer can hold/send 1 byte at a time
                for (i = 0; i < 3; i++) {
                    while (!(IFG2 & UCA0TXIFG));        // USCI_A0 RX buffer ready: polling
                    UCA0TXBUF = 0b00000001;             // turn LED off
                }
            }
        }

        for (i = 0; i < 4; i++) {
            while (!(IFG2 & UCA0TXIFG));            // USCI_A0 RX buffer ready: polling
            UCA0TXBUF = 0b11111111;
        }


        __bis_SR_register(LPM0_bits + GIE);   // Enter LPM0 w/interrupt

    }

    model_life();




    return 0;
}




#pragma vector=PORT2_VECTOR
__interrupt void Port_2 (void)
{
    //button1 is left   S4      pin 12  P2.4
    //button2 is down   S3      pin 11  P2.3
    //button3 is middle S5      pin 14  P1.6
    //button4 is top    S1      pin 8   P2.0
    //button5 is right  S2      pin 10  P2.2

    // check if button 1 is pressed
    cycles = idle;
    if ((P2IFG & BIT0) && (P2IFG & BIT2) && (P2IFG & BIT3) && (P2IFG & BIT4)) {
        __delay_cycles(100);
        stop_setup = 1;
    } else {

        if (P2IFG & BIT0) {
            __delay_cycles(100);
            up = 1;
        }
        // check if button 1 is pressed
        if (P2IFG & BIT2) {
            __delay_cycles(100);
            right = 1;
        }
        // check if button 1 is pressed
        if (P2IFG & BIT3) {
            __delay_cycles(100);
            down = 1;
        }
        // check if button 1 is pressed
        if (P2IFG & BIT4) {
            __delay_cycles(100);
            left = 1;
        }
    }
    P2IFG = 0;
    __bic_SR_register_on_exit(LPM0_bits);  // takes the CPU out of low power mode 0
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1 (void)
{
    cycles = idle;
    if (P1IFG & BIT6) {
        set_led = 1;
    }

    P1IFG = 0;
    __bic_SR_register_on_exit(LPM0_bits);  // takes the CPU out of low power mode 0
}


// Timer A0 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer_A (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER1_A0_VECTOR))) Timer_A (void)
#else
#error Compiler not supported!
#endif
{
    // cycles is used as a delay, decrements every time isr is called until cycles = 0 then
    //      takes the cpu out of low power mode
    if (cycles > 0) {
        --cycles;
    } else if (cycles == 0) {
        //__bic_SR_register_on_exit(LPM0_bits);  // takes the CPU out of low power mode 0
        --cycles;
        //stop_setup = 1;
    }

}
