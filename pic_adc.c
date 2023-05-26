#include "pic_adc.h"

void adc_init()
{
    ADCON0bits.GO_DONE=0;       // Converter is idle
    ADCON1=0b00000011;          // No reference inputs, all channels analogic inputs
    ADCON2=0b00000001;          // Left justified, 0 Tad adquisition, Fosc/8
    TRISA = TRISA | 0b00101111; // Set TRIS for ADC pins
    TRISB = TRISB | 0b00011111;
    TRISE = TRISE | 0b00000111;
    ADON=1;                     // ADC on

}

void start_conversion()
{
    adc_index=0;
    ADCON0bits.CHS=adc_index;       // Select channel
    while (adc_index<ANALOG_CHANNELS_SIZE)
    {
        __delay_us(10);                 // Wait for adquisition time
        ADCON0bits.GO_DONE = 1;         // Start conversion
        ADCON0bits.CHS=++adc_index;     // Incremen channel index
        while (ADCON0bits.GO_DONE){}    // Wait for conversion
        adc_output_buffer[adc_index-1] = ADRESH; // Save converted value
        ADRESH = 0;                     // Clear adc buffer
    }
}
