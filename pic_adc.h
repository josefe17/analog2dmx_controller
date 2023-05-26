/* 
 * File:  pic_adc.h
 * Author: josefe
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PIC_ADC_H
#define	PIC_ADC_H

#include <xc.h> 

void adc_init();
void start_conversion();

#endif	/* PIC_ADC_H */

