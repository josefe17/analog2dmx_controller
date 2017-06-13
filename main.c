/*****************************************************************************
*                           main.c
*
* Demo for DMX Controller
*
*
* Hardware:
*  Lighting Communications Motherboard DM160214
*  Lighting Communications DMX512 Adapter board AC160214-2
*
*
* CODE OWNERSHIP AND DISCLAIMER OF LIABILITY
*
* Microchip Technology Incorporated ("Microchip") retains all ownership and
* intellectual property rights in the code accompanying this message and in
* all derivatives hereto.  You may use this code, and any derivatives created
* by any person or entity by or on your behalf, exclusively with Microchips
* proprietary products.  Your acceptance and/or use of this code constitutes
* agreement to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT
* LIMITED TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND
* FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH
* MICROCHIPS PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY
* APPLICATION.
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE,
* WHETHER IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF
* STATUTORY DUTY), STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE,
* FOR ANY INDIRECT, SPECIAL, PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL
* LOSS, DAMAGE, FOR COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
* CODE, HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
* POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE
* BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS
* CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY
* TO HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and
* determining its suitability.  Microchip has no obligation to modify, test,
* certify, or support the code.
*
* Author            Date            Ver     Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Michael Pearce    23 October 2012 0.00    Write demo code
*
* Michael Pearce   5 November 2012  0.01    Add Color mixing option.
*                                           Clear first 4 channels when modes
*                                           are changes. 
******************************************************************************/


#include "dmx.h"
#include "config.h"
#include "analogconfig.h"
#include <xc.h>

#define _XTAL_FREQ 48000000          // System clock


volatile int address=0;                 // Starting address
volatile unsigned char adc_output_buffer[ANALOG_CHANNELS_SIZE]; // ADC output buffer
const unsigned char sampling_curve[] = { 0, 0, 27, 31, 34, 37, 39, 42, 44, 45, 47, 49, 50, 52, 53, 54, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 73, 74, 75, 76, 76, 77, 78, 79, 79, 80, 81, 82, 82, 83, 84, 84, 85, 86, 86, 87, 88, 88, 89, 90, 90, 91, 91, 92, 93, 93, 94, 94, 95, 96, 96, 97, 97, 98, 98, 99, 100, 100, 101, 101, 102, 102, 103, 103, 104, 105, 105, 106, 106, 107, 107, 108, 108, 109, 109, 110, 110, 111, 111, 112, 112, 113, 114, 114, 115, 115, 116, 116, 117, 117, 118, 118, 119, 119, 120, 120, 121, 121, 122, 122, 123, 123, 124, 124, 125, 125, 126, 126, 127, 127, 128, 128, 129, 129, 130, 130, 131, 131, 132, 132, 133, 133, 134, 134, 135, 135, 136, 136, 137, 137, 138, 138, 139, 139, 140, 140, 141, 141, 142, 142, 143, 143, 144, 144, 145, 145, 146, 147, 147, 148, 148, 149, 149, 150, 150, 151, 151, 152, 152, 153, 154, 154, 155, 155, 156, 156, 157, 157, 158, 159, 159, 160, 160, 161, 162, 162, 163, 163, 164, 165, 165, 166, 167, 167, 168, 168, 169, 170, 170, 171, 172, 173, 173, 174, 175, 175, 176, 177, 178, 178, 179, 180, 181, 181, 182, 183, 184, 185, 186, 187, 187, 188, 189, 190, 191, 192, 193, 194, 195, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 211, 213, 215, 217, 220, 223, 227, 255, 255 };

void adc_init(void);                                                    // configures ADC
void start_conversion(unsigned char*, unsigned char, unsigned char);    // sampling routine
void load_tx_buffer(int, int*);                                               // loads sampled values on tx buffer starting from selected address (as param)
void port_init(void);                                                   // configures I/O ports
int  read_address(void);                                                // reads starting address from DIP switch
unsigned char check_sampling_curve(void);                               // checks if linear shaping or not
void interrupts_init(void);                                             // configures global MCU's interrupts
void tx_buffer_init(volatile uint8_t* );
void tx_buffer_rotate(volatile uint8_t* );

void main(void)
{

#ifdef INT_OSC
OSCCONbits.IRCF=0b111; //  8MHz, Config bits source
OSCCONbits.SCS=0b11;   //   Int OSC
#endif

#ifdef PRIM_OSC
OSCCONbits.SCS=0b00;   //   Primary OSC
#endif

dmx_init();     // Initialise DMX512
port_init();    // Initialise I/O Ports
//tx_buffer_init(DMX_TxData); //already done by dmx stack
adc_init();     // Initialise ADC
interrupts_init();  // Initialise interrupts and enable priority

while(1)
{
    start_conversion(&adc_output_buffer, 0 , ANALOG_CHANNELS_SIZE);
    load_tx_buffer(read_address(), &address);
 //   tx_buffer_rotate((unsigned char*)get_TX_buffer());
 //    *((unsigned char*) get_TX_buffer()+64)=128;
}
}
void interrupt isr(void)
{
dmx_interrupt(); // Process the DMX512 interrupts
}

void tx_buffer_init(volatile uint8_t* tx_buffer){
    unsigned int i=0;
    for (;i<DMX_TX_BUFFER_SIZE;i++){
        tx_buffer[i]=i;
    }
}

void tx_buffer_rotate(volatile uint8_t*  tx_buffer){
    int i = 0;
    for (; i < DMX_TX_BUFFER_SIZE; i++) {
        tx_buffer[i]++;
    }
}

void adc_init()
{
    ADCON0bits.GO_DONE=0;       // Converter is idle
    ADCON1=0b00000011;          // No reference inputs, all channels analog inputs
    ADCON2=0b00000001;          // Left justified, 0 Tad adquisition, Fosc/8
    TRISA |= 0b00101111;        // Set TRIS for ADC pins
    TRISB |= 0b00011111;
    TRISE |= 0b00000111;    
    ADON=1;                       // ADC on

}

void start_conversion(unsigned char* output_buffer, unsigned char first_channel, unsigned char last_channel)
{
    unsigned char adc_index=first_channel;
    ADCON0bits.CHS=adc_index;       // Select channel
    while (adc_index<last_channel)
    {
        __delay_us(10);                 // Wait for adquisition time
        ADCON0bits.GO_DONE = 1;         // Start conversion
        __delay_us(1);                  // Wait 1 us before changing mux to allow C to be disconnected
        ADCON0bits.CHS=++adc_index;     // Increment channel index
        while (ADCON0bits.GO_DONE){}    // Wait for conversion
        output_buffer[adc_index-1] = ADRESH; // Save converted value
        ADRESH = 0;
    }
}


void load_tx_buffer (int start_address, int* address) {

    int i; // Tx buffer_index
    unsigned char adc_buffer_index;
    if ((*address)!=start_address)                     // If address has changed
    {        
        for (i=0; i<start_address; i++)             // Writes 0 before starting analog channels
        {
            dmx_write_byte(i+1,0);
        }

        if(check_sampling_curve())                 // If non-linear response enabled
        {
            for (adc_buffer_index=0;
                    adc_buffer_index<ANALOG_CHANNELS_SIZE && i<DMX_TX_BUFFER_SIZE;
                    i++, adc_buffer_index++)
            {                                       // Writes pattern-shaped values
                dmx_write_byte(i+1, sampling_curve[adc_output_buffer[adc_buffer_index]]);
            }
        }
        else                                        // Else writes linear analog values
        {
            for (adc_buffer_index = 0;
                    adc_buffer_index < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE;
                    i++, adc_buffer_index++) {
                dmx_write_byte(i + 1, adc_output_buffer[adc_buffer_index]);
            }
        }
        for (; i<DMX_TX_BUFFER_SIZE; i++)           // Writes 0 after analog channels
        {
            dmx_write_byte(i+1,0);
        }
        (*address)=start_address;                     // Store new address
    }
    else                                            // If starting address hasn't changed
    {                                               // only rewrites data channels
        if (check_sampling_curve())              // Linear response check and shaping
        {
            for (adc_buffer_index = 0, i=start_address; // Writes analog data
                    adc_buffer_index < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE;
                    i++, adc_buffer_index++)
            {
                dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[adc_buffer_index]]);
            }
        }
        else
        {
            for (adc_buffer_index = 0, i = start_address; // Writes analog data
                    adc_buffer_index < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE;
                    i++, adc_buffer_index++)
            {
                dmx_write_byte(i + 1, adc_output_buffer[adc_buffer_index]);
            }
        }
    }
}




void port_init(void){
    TRISD|=0b11101111;          // PortD 0-3, 5-7 as address input
    TRISC0=1;                   // 5th address bit
    TRISC1=1;                   // 9th address bit
    TRISC2=1;                   // Non-linear response control bit
}


int read_address(void){
    //return 0;    
    int data = PORTD & 0b11101111;
    if (PORTCbits.RC0)
    {
         data+=16;
    }
    if (PORTCbits.RC1)
    {
        data+=256;
    } 
   return data;
   
}

unsigned char check_sampling_curve(void)
{
    return PORTCbits.RC2;
    //return 0;
}

void interrupts_init()
{
    //PEIE=1;
    GIE=1;     // Enable interrupts
}

