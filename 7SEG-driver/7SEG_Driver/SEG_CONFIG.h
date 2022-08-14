/*
 * SEG_CONFIG.h
 *
 * Created: 2/6/2021 7:15:42 PM
 *  Author: Mohamed Ismail
 */ 


#ifndef SEG_CONFIG_H_
#define SEG_CONFIG_H_

/* Select port in which 7 segment connected to */
#define SEG_PORT	PORTD

/* it takes 1 to use decoder */
#define BCD_DECODER	1

/* 7 segment type 0 for common cathode , and 1 for common anode */ 
#define SEG_TYPE	0

/* if 7 segment common cathode then enable will be 0, if it common anode its enable will be 1*/
#define ENABLE	0
#define DISABLE	1

/* Segment enable control */
#define SEG_CONTROL_PORT	PORTC
#define SEG1_EN  PIN0
#define SEG2_EN  PIN1


#endif /* SEG_CONFIG_H_ */