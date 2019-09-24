/***********************************************************************************************************************
 * ATMega32MemMapReg.h
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 ***********************************************************************************************************************/
#ifndef ATMEGA32MEMMAPREG_H_
#define ATMEGA32MEMMAPREG_H_
/***********************************************************************************************************************
 * include(s)
 ***********************************************************************************************************************/
#include "CommonHeaders.h"
/***********************************************************************************************************************
 * definition(s)
 ***********************************************************************************************************************/
#define SREG_REG        (*(volatile uint8_t *) 0x5Fu)
#define C_BIT           (0u)
#define Z_BIT           (1u)
#define N_BIT           (2u)
#define V_BIT           (3u)
#define S_BIT           (4u)
#define H_BIT           (5u)
#define T_BIT           (6u)
#define I_BIT           (7u)

#define SPH_REG         (*(volatile uint8_t *) 0x5Eu)
#define SP8_BIT         (0u)
#define SP9_BIT         (1u)
#define SP10_BIT        (2u)
#define SP11_BIT        (3u)
/* Bit 4 is reserved */
/* Bit 5 is reserved */
/* Bit 6 is reserved */
/* Bit 7 is reserved */

#define SPL_REG         (*(volatile uint8_t *) 0x5Du)
#define SP0_BIT         (0u)
#define SP1_BIT         (1u)
#define SP2_BIT         (2u)
#define SP3_BIT         (3u)
#define SP4_BIT         (4u)
#define SP5_BIT         (5u)
#define SP6_BIT         (6u)
#define SP7_BIT         (7u)

#define OCR0_REG        (*(volatile uint8_t *) 0x5Cu)

#define GICR_REG        (*(volatile uint8_t *) 0x5Bu)
#define IVCE_BIT        (0u)
#define IVSEL_BIT       (1u)
/* Bit 2 is reserved */
/* Bit 3 is reserved */
/* Bit 4 is reserved */
#define INT2_BIT        (5u)
#define INT0_BIT        (6u)
#define INT1_BIT        (7u)

#define GIFR_REG        (*(volatile uint8_t *) 0x5Au)
/* Bit 0 is reserved */
/* Bit 1 is reserved */
/* Bit 2 is reserved */
/* Bit 3 is reserved */
/* Bit 4 is reserved */
#define INTF2_BIT       (5u)
#define INTF0_BIT       (6u)
#define INTF1_BIT       (7u)

#define TIMSK_REG       (*(volatile uint8_t *) 0x59u)
#define TOIE0_BIT       (0u)
#define OCIE0_BIT       (1u)
#define TOIE1_BIT       (2u)
#define OCIE1B_BIT      (3u)
#define OCIE1A_BIT      (4u)
#define TICIE1_BIT      (5u)
#define TOIE2_BIT       (6u)
#define OCIE2_BIT       (7u)

#define TIFR_REG        (*(volatile uint8_t *) 0x58u)
#define TOV0_BIT        (0u)
#define OCF0_BIT        (1u)
#define TOV1_BIT        (2u)
#define OCF1B_BIT       (3u)
#define OCF1A_BIT       (4u)
#define ICF1_BIT        (5u)
#define TOV2_BIT        (6u)
#define OCF2_BIT        (7u)

#define SPMCR_REG       (*(volatile uint8_t *) 0x57u)
#define SPMEN_BIT       (0u)
#define PGERS_BIT       (1u)
#define PGWRT_BIT       (2u)
#define BLBSET_BIT      (3u)
#define RWWSRE_BIT      (4u)
/* Bit 5 is reserved */
#define RWWSB_BIT       (6u)
#define SPMIE_BIT       (7u)

#define TWCR_REG        (*(volatile uint8_t *) 0x56u)
#define TWIE_BIT        (0u)
/* Bit 1 is reserved */
#define TWEN_BIT        (2u)
#define TWWC_BIT        (3u)
#define TWSTO_BIT       (4u)
#define TWSTA_BIT       (5u)
#define TWEA_BIT        (6u)
#define TWINT_BIT       (7u)

#define MCUCR_REG       (*(volatile uint8_t *) 0x55u)
#define ISC00_BIT       (0u)
#define ISC01_BIT       (1u)
#define ISC10_BIT       (2u)
#define ISC11_BIT       (3u)
#define SM0_BIT         (4u)
#define SM1_BIT         (5u)
#define SM2_BIT         (6u)
#define SE_BIT          (7u)

#define MCUCSR_REG      (*(volatile uint8_t *) 0x54u)
#define PORF_BIT        (0u)
#define EXTRF_BIT       (1u)
#define BORF_BIT        (2u)
#define WDRF_BIT        (3u)
#define JTRF_BIT        (4u)
/* Bit 5 is reserved */
#define ISC2_BIT        (6u)
#define JTD_BIT         (7u)

#define TCCR0_REG       (*(volatile uint8_t *) 0x53u)
#define CS00_BIT        (0u)
#define CS01_BIT        (1u)
#define CS02_BIT        (2u)
#define WGM01_BIT       (3u)
#define COM00_BIT       (4u)
#define COM01_BIT       (5u)
#define WGM00_BIT       (6u)
#define FOC0_BIT        (7u)

#define TCNT0_REG       (*(volatile uint8_t *) 0x52u)

#define OSCCAL_REG      (*(volatile uint8_t *) 0x51u)

#define OCDR_REG        (*(volatile uint8_t *) 0x51u)

#define SFIOR_REG       (*(volatile uint8_t *) 0x50u)
#define PSR10_BIT       (0u)
#define PSR2_BIT        (1u)
#define PUD_BIT         (2u)
#define ACME_BIT        (3u)
/* Bit 4 is reserved */
#define ADTS0_BIT       (5u)
#define ADTS1_BIT       (6u)
#define ADTS2_BIT       (7u)

#define TCCR1A_REG      (*(volatile uint8_t *) 0x4Fu)
#define WGM10_BIT       (0u)
#define WGM11_BIT       (1u)
#define FOC1B_BIT       (2u)
#define FOC1A_BIT       (3u)
#define COM1B0_BIT      (4u)
#define COM1B1_BIT      (5u)
#define COM1A0_BIT      (6u)
#define COM1A1_BIT      (7u)

#define TCCR1B_REG      (*(volatile uint8_t *) 0x4Eu)
#define CS10_BIT        (0u)
#define CS11_BIT        (1u)
#define CS12_BIT        (2u)
#define WGM12_BIT       (3u)
#define WGM13_BIT       (4u)
/* Bit 5 is reserved */
#define ICES1_BIT       (6u)
#define ICNC1_BIT       (7u)

#define TCNT1H_REG      (*(volatile uint8_t *) 0x4Du)

#define TCNT1L_REG      (*(volatile uint8_t *) 0x4Cu)

#define OCR1AH_REG      (*(volatile uint8_t *) 0x4Bu)

#define OCR1AL_REG      (*(volatile uint8_t *) 0x4Au)

#define OCR1BH_REG      (*(volatile uint8_t *) 0x49u)

#define OCR1BL_REG      (*(volatile uint8_t *) 0x48u)

#define ICR1H_REG       (*(volatile uint8_t *) 0x47u)

#define ICR1L_REG       (*(volatile uint8_t *) 0x46u)

#define TCCR2_REG       (*(volatile uint8_t *) 0x45u)
#define CS20_BIT        (0u)
#define CS21_BIT        (1u)
#define CS22_BIT        (2u)
#define WGM21_BIT       (3u)
#define COM20_BIT       (4u)
#define COM21_BIT       (5u)
#define WGM20_BIT       (6u)
#define FOC2_BIT        (7u)

#define TCNT2_REG       (*(volatile uint8_t *) 0x44u)

#define OCR2_REG        (*(volatile uint8_t *) 0x43u)

#define ASSR_REG        (*(volatile uint8_t *) 0x42u)
#define TCR2UB_BIT      (0u)
#define OCR2UB_BIT      (1u)
#define TCN2UB_BIT      (2u)
#define AS2_BIT         (3u)
/* Bit 4 is reserved */
/* Bit 5 is reserved */
/* Bit 6 is reserved */
/* Bit 7 is reserved */

#define WDTCR_REG       (*(volatile uint8_t *) 0x41u)
#define WDP0_BIT        (0u)
#define WDP1_BIT        (1u)
#define WDP2_BIT        (2u)
#define WDE_BIT         (3u)
#define WDTOE_BIT       (4u)
/* Bit 5 is reserved */
/* Bit 6 is reserved */
/* Bit 7 is reserved */

#define UBRRH_REG       (*(volatile uint8_t *) 0x40u)
/* Bit 0 is reserved */
/* Bit 1 is reserved */
/* Bit 2 is reserved */
/* Bit 3 is reserved */
/* Bit 4 is reserved */
/* Bit 5 is reserved */
/* Bit 6 is reserved */
#define URSEL_BIT       (7u)

#define UCSRC_REG       (*(volatile uint8_t *) 0x40u)
#define UCPOL_BIT       (0u)
#define UCSZ0_BIT       (1u)
#define UCSZ1_BIT       (2u)
#define USBS_BIT        (3u)
#define UPM0_BIT        (4u)
#define UPM1_BIT        (5u)
#define UMSEL_BIT       (6u)
#define URSEL_BIT       (7u)

#define EEARH_REG       (*(volatile uint8_t *) 0x3Fu)
#define EEAR8_BIT       (0u)
#define EEAR9_BIT       (1u)
/* Bit 2 is reserved */
/* Bit 3 is reserved */
/* Bit 4 is reserved */
/* Bit 5 is reserved */
/* Bit 6 is reserved */
/* Bit 7 is reserved */

#define EEARL_REG       (*(volatile uint8_t *) 0x3Eu)

#define EEDR_REG        (*(volatile uint8_t *) 0x3Du)

#define EECR_REG        (*(volatile uint8_t *) 0x3Cu)
#define EERE_BIT        (0u)
#define EEWE_BIT        (1u)
#define EEMWE_BIT       (2u)
#define EERIE_BIT       (3u)
/* Bit 4 is reserved */
/* Bit 5 is reserved */
/* Bit 6 is reserved */
/* Bit 7 is reserved */

#define PORTA_REG       (*(volatile uint8_t *) 0x3Bu)
#define PORTA0_BIT      (0u)
#define PORTA1_BIT      (1u)
#define PORTA2_BIT      (2u)
#define PORTA3_BIT      (3u)
#define PORTA4_BIT      (4u)
#define PORTA5_BIT      (5u)
#define PORTA6_BIT      (6u)
#define PORTA7_BIT      (7u)

#define DDRA_REG        (*(volatile uint8_t *) 0x3Au)
#define DDA0_BIT        (0u)
#define DDA1_BIT        (1u)
#define DDA2_BIT        (2u)
#define DDA3_BIT        (3u)
#define DDA4_BIT        (4u)
#define DDA5_BIT        (5u)
#define DDA6_BIT        (6u)
#define DDA7_BIT        (7u)

#define PINA_REG        (*(volatile uint8_t *) 0x39u)
#define PINA0_BIT       (0u)
#define PINA1_BIT       (1u)
#define PINA2_BIT       (2u)
#define PINA3_BIT       (3u)
#define PINA4_BIT       (4u)
#define PINA5_BIT       (5u)
#define PINA6_BIT       (6u)
#define PINA7_BIT       (7u)

#define PORTB_REG       (*(volatile uint8_t *) 0x38u)
#define PORTB0_BIT      (0u)
#define PORTB1_BIT      (1u)
#define PORTB2_BIT      (2u)
#define PORTB3_BIT      (3u)
#define PORTB4_BIT      (4u)
#define PORTB5_BIT      (5u)
#define PORTB6_BIT      (6u)
#define PORTB7_BIT      (7u)

#define DDRB_REG        (*(volatile uint8_t *) 0x37u)
#define DDB0_BIT        (0u)
#define DDB1_BIT        (1u)
#define DDB2_BIT        (2u)
#define DDB3_BIT        (3u)
#define DDB4_BIT        (4u)
#define DDB5_BIT        (5u)
#define DDB6_BIT        (6u)
#define DDB7_BIT        (7u)

#define PINB_REG        (*(volatile uint8_t *) 0x36u)
#define PINB0_BIT       (0u)
#define PINB1_BIT       (1u)
#define PINB2_BIT       (2u)
#define PINB3_BIT       (3u)
#define PINB4_BIT       (4u)
#define PINB5_BIT       (5u)
#define PINB6_BIT       (6u)
#define PINB7_BIT       (7u)

#define PORTC_REG       (*(volatile uint8_t *) 0x35u)
#define PORTC0_BIT      (0u)
#define PORTC1_BIT      (1u)
#define PORTC2_BIT      (2u)
#define PORTC3_BIT      (3u)
#define PORTC4_BIT      (4u)
#define PORTC5_BIT      (5u)
#define PORTC6_BIT      (6u)
#define PORTC7_BIT      (7u)

#define DDRC_REG        (*(volatile uint8_t *) 0x34u)
#define DDC0_BIT        (0u)
#define DDC1_BIT        (1u)
#define DDC2_BIT        (2u)
#define DDC3_BIT        (3u)
#define DDC4_BIT        (4u)
#define DDC5_BIT        (5u)
#define DDC6_BIT        (6u)
#define DDC7_BIT        (7u)

#define PINC_REG        (*(volatile uint8_t *) 0x33u)
#define PINC0_BIT       (0u)
#define PINC1_BIT       (1u)
#define PINC2_BIT       (2u)
#define PINC3_BIT       (3u)
#define PINC4_BIT       (4u)
#define PINC5_BIT       (5u)
#define PINC6_BIT       (6u)
#define PINC7_BIT       (7u)

#define PORTD_REG       (*(volatile uint8_t *) 0x32u)
#define PORTD0_BIT      (0u)
#define PORTD1_BIT      (1u)
#define PORTD2_BIT      (2u)
#define PORTD3_BIT      (3u)
#define PORTD4_BIT      (4u)
#define PORTD5_BIT      (5u)
#define PORTD6_BIT      (6u)
#define PORTD7_BIT      (7u)

#define DDRD_REG        (*(volatile uint8_t *) 0x31u)
#define DDD0_BIT        (0u)
#define DDD1_BIT        (1u)
#define DDD2_BIT        (2u)
#define DDD3_BIT        (3u)
#define DDD4_BIT        (4u)
#define DDD5_BIT        (5u)
#define DDD6_BIT        (6u)
#define DDD7_BIT        (7u)

#define PIND_REG        (*(volatile uint8_t *) 0x30u)
#define PIND0_BIT       (0u)
#define PIND1_BIT       (1u)
#define PIND2_BIT       (2u)
#define PIND3_BIT       (3u)
#define PIND4_BIT       (4u)
#define PIND5_BIT       (5u)
#define PIND6_BIT       (6u)
#define PIND7_BIT       (7u)

#define SPDR_REG        (*(volatile uint8_t *) 0x2Fu)

#define SPSR_REG        (*(volatile uint8_t *) 0x2Eu)
#define SPI2X_BIT       (0u)
/* Bit 1 is reserved */
/* Bit 2 is reserved */
/* Bit 3 is reserved */
/* Bit 4 is reserved */
/* Bit 5 is reserved */
#define WCOL_BIT        (6u)
#define SPIF_BIT        (7u)

#define SPCR_REG        (*(volatile uint8_t *) 0x2Du)
#define SPR0_BIT        (0u)
#define SPR1_BIT        (1u)
#define CPHA_BIT        (2u)
#define CPOL_BIT        (3u)
#define MSTR_BIT        (4u)
#define DORD_BIT        (5u)
#define SPE_BIT         (6u)
#define SPIE_BIT        (7u)

#define UDR_REG         (*(volatile uint8_t *) 0x2Cu)

#define UCSRA_REG       (*(volatile uint8_t *) 0x2Bu)
#define MPCM_BIT        (0u)
#define U2X_BIT         (1u)
#define PE_BIT          (2u)
#define DOR_BIT         (3u)
#define FE_BIT          (4u)
#define UDRE_BIT        (5u)
#define TXC_BIT         (6u)
#define RXC_BIT         (7u)

#define UCSRB_REG       (*(volatile uint8_t *) 0x2Au)
#define TXB8_BIT        (0u)
#define RXB8_BIT        (1u)
#define UCSZ2_BIT       (2u)
#define TXEN_BIT        (3u)
#define RXEN_BIT        (4u)
#define UDRIE_BIT       (5u)
#define TXCIE_BIT       (6u)
#define RXCIE_BIT       (7u)

#define UBRRL_REG       (*(volatile uint8_t *) 0x29u)

#define ACSR_REG        (*(volatile uint8_t *) 0x28u)
#define ACIS0_BIT       (0u)
#define ACIS1_BIT       (1u)
#define ACIC_BIT        (2u)
#define ACIE_BIT        (3u)
#define ACI_BIT         (4u)
#define ACO_BIT         (5u)
#define ACBG_BIT        (6u)
#define ACD_BIT         (7u)

#define ADMUX_REG       (*(volatile uint8_t *) 0x27u)
#define MUX0_BIT        (0u)
#define MUX1_BIT        (1u)
#define MUX2_BIT        (2u)
#define MUX3_BIT        (3u)
#define MUX4_BIT        (4u)
#define ADLAR_BIT       (5u)
#define REFS0_BIT       (6u)
#define REFS1_BIT       (7u)

#define ADCSRA_REG      (*(volatile uint8_t *) 0x26u)
#define ADPS0_BIT       (0u)
#define ADPS1_BIT       (1u)
#define ADPS2_BIT       (2u)
#define ADIE_BIT        (3u)
#define ADIF_BIT        (4u)
#define ADATE_BIT       (5u)
#define ADSC_BIT        (6u)
#define ADEN_BIT        (7u)

#define ADCH_REG        (*(volatile uint8_t *) 0x25u)

#define ADCL_REG        (*(volatile uint8_t *) 0x24u)

#define TWDR_REG        (*(volatile uint8_t *) 0x23u)

#define TWAR_REG        (*(volatile uint8_t *) 0x22u)
#define TWGCE_BIT       (0u)
#define TWA0_BIT        (1u)
#define TWA1_BIT        (2u)
#define TWA2_BIT        (3u)
#define TWA3_BIT        (4u)
#define TWA4_BIT        (5u)
#define TWA5_BIT        (6u)
#define TWA6_BIT        (7u)

#define TWSR_REG        (*(volatile uint8_t *) 0x21u)
#define TWPS0_BIT       (0u)
#define TWPS1_BIT       (1u)
/* Bit 2 is reserved */
#define TWS3_BIT        (3u)
#define TWS4_BIT        (4u)
#define TWS5_BIT        (5u)
#define TWS6_BIT        (6u)
#define TWS7_BIT        (7u)

#define TWBR_REG        (*(volatile uint8_t *) 0x20u)
/***********************************************************************************************************************
 * type definition(s)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * external variable(s)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * external function prototype(s)
 ***********************************************************************************************************************/
#endif /* ATMEGA32MEMMAPREG_H_ */
