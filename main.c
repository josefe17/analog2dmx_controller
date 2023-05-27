/*
 * File:   main.c
 * Author: josefe
 *
 * Created on June 13, 2017, 1:55 PM
 */

#include "dmx.h"
#include "config.h"
#include "analogconfig.h"
#include <xc.h>

#define _XTAL_FREQ 48000000          // System 

#define deadZoneThreshold 25
#define deadZoneValue     0

#define ADDRESS_FOR_SCHOOOL_MODE 1

//Dip switch bits
//Bit 0 SW 1: RC0
//Bit 1 SW 2: RC1
//Bit 2 SW 3: RC2
//Bit 3 SW 4: RD0
//Bit 4 SW 5: RD1
//Bit 5 SW 6: RD2
//Bit 6 SW 7: RD3
//Bit 7 SW 8: RC4
//Bit 8 SW 9: RC5
//Bit 9 SW 10: RD5
//Bit 10 SW 11: RD6
//Bit 11 SW 12: RD7


uint16_t address = 0;                 // Starting address
uint8_t adc_output_buffer[ANALOG_CHANNELS_SIZE]; // ADC output buffer
const uint8_t sampling_curve[] = { 0, 0, 27, 31, 34, 37, 39, 42, 44, 45, 47, 49, 50, 52, 53, 54, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 73, 74, 75, 76, 76, 77, 78, 79, 79, 80, 81, 82, 82, 83, 84, 84, 85, 86, 86, 87, 88, 88, 89, 90, 90, 91, 91, 92, 93, 93, 94, 94, 95, 96, 96, 97, 97, 98, 98, 99, 100, 100, 101, 101, 102, 102, 103, 103, 104, 105, 105, 106, 106, 107, 107, 108, 108, 109, 109, 110, 110, 111, 111, 112, 112, 113, 114, 114, 115, 115, 116, 116, 117, 117, 118, 118, 119, 119, 120, 120, 121, 121, 122, 122, 123, 123, 124, 124, 125, 125, 126, 126, 127, 127, 128, 128, 129, 129, 130, 130, 131, 131, 132, 132, 133, 133, 134, 134, 135, 135, 136, 136, 137, 137, 138, 138, 139, 139, 140, 140, 141, 141, 142, 142, 143, 143, 144, 144, 145, 145, 146, 147, 147, 148, 148, 149, 149, 150, 150, 151, 151, 152, 152, 153, 154, 154, 155, 155, 156, 156, 157, 157, 158, 159, 159, 160, 160, 161, 162, 162, 163, 163, 164, 165, 165, 166, 167, 167, 168, 168, 169, 170, 170, 171, 172, 173, 173, 174, 175, 175, 176, 177, 178, 178, 179, 180, 181, 181, 182, 183, 184, 185, 186, 187, 187, 188, 189, 190, 191, 192, 193, 194, 195, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 211, 213, 215, 217, 220, 223, 227, 255, 255 };

void adc_init(void);                                                                           // configures ADC
void start_conversion(uint8_t* output_buffer, uint8_t first_channel, uint8_t last_channel);    // sampling routine
void load_tx_buffer (uint16_t start_address, uint16_t* address);                               // loads sampled values on tx buffer starting from selected address (as param)
void port_init(void);                                                                          // configures I/O ports
uint16_t  read_address(void);                                                                  // reads starting address from DIP switch
uint8_t check_sampling_curve(void);                                                            // checks if linear shaping or not
uint8_t check_special_mode(void);                                                              // checks if special mapping modes are required
void set_deadZone(uint8_t* values, uint16_t valuesCount);
void interrupts_init(void);                                                                    // configures global MCU's interrupts

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
    adc_init();     // Initialise ADC
    interrupts_init();  // Initialise interrupts and enable priority

    while(1)
    {
        start_conversion(adc_output_buffer, 0 , ANALOG_CHANNELS_SIZE);
        set_deadZone(adc_output_buffer, ANALOG_CHANNELS_SIZE);
        load_tx_buffer(read_address(), &address);              
        __delay_ms(5);
    }
}
void __interrupt(high_priority) isr_high(void)
{
    dmx_interrupt(); // Process the DMX512 interrupts
}

void set_deadZone(uint8_t* values, uint16_t valuesCount)
{
    uint16_t index;
    if (PORTDbits.RD6)
    {
        for(index = 0; index < valuesCount; ++index)
        {
            if (values[index] < deadZoneThreshold)
            {
                values[index] = deadZoneValue;
            }
        }
    }
}

void adc_init()
{
    ADCON0bits.GO_DONE = 0;       // Converter is idle
    ADCON1 = 0b00000011;          // No reference inputs, all channels analog inputs
    ADCON2 = 0b00000110;          // Left justified, 0 Tad adquisition, Fosc/64
    TRISA |= 0b00101111;          // Set TRIS for ADC pins
    TRISB |= 0b00011111;
    TRISE |= 0b00000111;    
    ADCON0bits.ADON = 1;          // ADC on
}

void start_conversion(uint8_t* output_buffer, uint8_t first_channel, uint8_t last_channel)
{
    uint8_t adc_index = first_channel;
    ADCON0bits.CHS = adc_index;       // Select channel
    while (adc_index < last_channel)
    {
        __delay_us(100);                 // Wait for adquisition time
        ADCON0bits.GO_DONE = 1;          // Start conversion
        __delay_us(10);                  // Wait 1 us before changing mux to allow C to be disconnected
        ADCON0bits.CHS = ++adc_index;    // Increment channel index
        while (ADCON0bits.GO_DONE){}     // Wait for conversion
        output_buffer[adc_index - 1] = ADRESH; // Save converted value       
        ADRESH = 0;
        ADRESL = 0;
    }
}

void load_tx_buffer(uint16_t start_address, uint16_t* address) 
{
    uint16_t i; // Tx buffer_index
    uint8_t adc_buffer_index;
    if (check_special_mode())
    {
        if (start_address == ADDRESS_FOR_SCHOOOL_MODE)
        {
            if (check_sampling_curve())
            {
                for (i = 0; i<DMX_TX_BUFFER_SIZE; i++)
                {
                    switch(i) 
                    {
                        // Front reds: 1st analog channel
                        case 21:
                        case 31:
                        case 41:
                        case 51:
                        case 61:
                        case 71:
                        case 81:
                            dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[0]]);
                            break;
                         // Front greens: 2nd analog channel   
                        case 22:
                        case 32:
                        case 42:
                        case 52:
                        case 62:
                        case 72:
                        case 82:
                            dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[1]]);
                            break;
                        // Front blues: 3rd analog channel   
                        case 23:
                        case 33:
                        case 43:
                        case 53:
                        case 63:
                        case 73:
                        case 83:
                            dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[2]]);
                            break;
                        // Stage reds: 4th analog channel
                        case 1:
                        case 11:
                            dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[3]]);
                            break;
                         // Stage greens: 5th analog channel   
                        case 2:
                        case 12:
                            dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[4]]);
                            break;
                        // Stage blues: 6th analog channel   
                        case 3:
                        case 13:
                            dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[5]]);
                            break; 
                        // Strip control: 7th analog channel
                        case 90:
                            dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[6]]);
                            break;
                        // Strip red: 8th analog channel
                        case 91:
                            dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[7]]);
                            break;
                         // Strip green: 9th analog channel   
                        case 92:
                            dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[8]]);
                            break;
                        // Strip blue: 10th analog channel   
                        case 93:
                            dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[9]]);
                            break;
                        // Left dimmer: 11th analog channel
                        case 94:
                            dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[10]]);
                            break;
                        // Right dimmer: 12th analog channel
                        case 95:
                            dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[11]]);
                            break;
                        default:
                            dmx_write_byte(i + 1, 0);
                            break;
                    }
                } 
            }
            else
            {
               for (i = 0; i<DMX_TX_BUFFER_SIZE; i++)           // Writes 0 after analog channels
                {
                    switch(i) 
                    {
                        // Front reds: 1st analog channel
                        case 21:
                        case 31:
                        case 41:
                        case 51:
                        case 61:
                        case 71:
                        case 81:
                            dmx_write_byte(i + 1, adc_output_buffer[0]);
                            break;
                         // Front greens: 2nd analog channel   
                        case 22:
                        case 32:
                        case 42:
                        case 52:
                        case 62:
                        case 72:
                        case 82:
                            dmx_write_byte(i + 1, adc_output_buffer[1]);
                            break;
                        // Front blues: 3rd analog channel   
                        case 23:
                        case 33:
                        case 43:
                        case 53:
                        case 63:
                        case 73:
                        case 83:
                            dmx_write_byte(i + 1, adc_output_buffer[2]);
                            break;
                        // Stage reds: 4th analog channel
                        case 1:
                        case 11:
                            dmx_write_byte(i + 1, adc_output_buffer[3]);
                            break;
                         // Stage greens: 5th analog channel   
                        case 2:
                        case 12:
                            dmx_write_byte(i + 1, adc_output_buffer[4]);
                            break;
                        // Stage blues: 6th analog channel   
                        case 3:
                        case 13:
                            dmx_write_byte(i + 1, adc_output_buffer[5]);
                            break; 
                        // Strip control: 7th analog channel
                        case 90:
                            dmx_write_byte(i + 1, adc_output_buffer[6]);
                            break;
                        // Strip red: 8th analog channel
                        case 91:
                            dmx_write_byte(i + 1, adc_output_buffer[7]);
                            break;
                         // Strip green: 9th analog channel   
                        case 92:
                            dmx_write_byte(i + 1, adc_output_buffer[8]);
                            break;
                        // Strip blue: 10th analog channel   
                        case 93:
                            dmx_write_byte(i + 1, adc_output_buffer[9]);
                            break;
                        // Left dimmer: 11th analog channel
                        case 94:
                            dmx_write_byte(i + 1, adc_output_buffer[10]);
                            break;
                        // Right dimmer: 12th analog channel
                        case 95:
                            dmx_write_byte(i + 1, adc_output_buffer[11]);
                            break;
                        default:
                            dmx_write_byte(i + 1, 0);
                            break;
                    }
                }  
            }            
        }
        else 
        {
            for (i = 0; i<DMX_TX_BUFFER_SIZE; i++)           // Writes 0 for all channels
            {
                dmx_write_byte(i + 1, 0);
            }
        }
    }
    else
    {
        if ((*address) != start_address)                     // If address has changed
        {        
            for (i = 0; i < start_address; i++)             // Writes 0 before starting analog channels
            {
                dmx_write_byte(i + 1, 0);
            }

            if(check_sampling_curve())                 // If non-linear response enabled
            {
                for (adc_buffer_index = 0;
                        adc_buffer_index < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE;
                        i++, adc_buffer_index++)
                {                                       // Writes pattern-shaped values
                    dmx_write_byte(i + 1, sampling_curve[adc_output_buffer[adc_buffer_index]]);
                }
            }
            else                                        // Else writes linear analog values
            {
                for (adc_buffer_index = 0;
                        adc_buffer_index < ANALOG_CHANNELS_SIZE && i < DMX_TX_BUFFER_SIZE;
                        i++, adc_buffer_index++)
                {
                    dmx_write_byte(i + 1, adc_output_buffer[adc_buffer_index]);
                }
            }
            for (; i<DMX_TX_BUFFER_SIZE; i++)           // Writes 0 after analog channels
            {
                dmx_write_byte(i + 1, 0);
            }
            *address = start_address;                     // Store new address
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
}

void port_init(void)
{      
    TRISD|=0b11101111;          // PortD 0-3, 5-7 as address input
    TRISC0=1;                   
    TRISC1=1;                   
    TRISC2=1;       
    UCONbits.USBEN=0;
    UCFGbits.UTRDIS=1;    
}

uint16_t read_address(void)
{      
   return ((uint16_t) PORTC & 0x0007) | (((uint16_t) PORTD & 0x000F) << 3) | (((uint16_t) PORTC & 0x0030) << 3);   
}

uint8_t check_sampling_curve(void)
{
    return (uint8_t) PORTDbits.RD5;    
}

uint8_t check_special_mode(void)
{
    return (uint8_t) PORTDbits.RD7;
}

void interrupts_init()
{
    //PEIE=1;
    GIE=1;     // Enable interrupts
}