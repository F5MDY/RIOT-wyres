/*
 * Copyright (C) 2023 Université Grenoble Alpes
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     boards_wyres-base
 * @{
 *
 * @file
 * @brief       Board specific definitions for the Wyres Base board.
 *
 * @author      Tristan Lailler <tristan.lailler@etu.univ-grenoble-alpes.fr
 * @author      Didier Donsez <didier.donsez@univ-grenoble-alpes.fr
 */

#ifndef BOARD_H
#define BOARD_H


#include "cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Xtimer configuration
 * @{
 */
#define XTIMER_WIDTH                (16)
/** @} */

/**
 * @name Macros for controlling the on-board LEDs.
 * @{
 */
//#define LED0_PIN            	GPIO_PIN(PORT_A,15)
#define LED_RED_PIN            	GPIO_PIN(PORT_A,15)
#define LED_RED_PORT           	GPIOA
#define LED_RED_MASK           	(1 << 15)

#define LED_RED_ON             	(LED_RED_PORT->BSRR |= LED_RED_MASK)
#define LED_RED_OFF            	(LED_RED_PORT->BSRR |= LED_RED_MASK<<16)
#define LED_RED_TOGGLE         	(LED_RED_PORT->ODR  ^= LED_RED_MASK)

//#define LED1_PIN            	GPIO_PIN(PORT_A,0)
#define LED_GREEN_PIN           GPIO_PIN(PORT_A,0)
#define LED_GREEN_PORT          GPIOA
#define LED_GREEN_MASK          (1)

#define LED_GREEN_ON            (LED_GREEN_PORT->BSRR |= LED_GREEN_MASK)
#define LED_GREEN_OFF           (LED_GREEN_PORT->BSRR |= LED_GREEN_MASK<<16)
#define LED_GREEN_TOGGLE        (LED_GREEN_PORT->ODR  ^= LED_GREEN_MASK)
/** @} */

/**
 * @name Light sensor supply
 * @{
 */
#define LIGHT_SENSOR_SUPPLY_PIN            GPIO_PIN(PORT_B,6)
#define LIGHT_SENSOR_SUPPLY_PORT           GPIOB
#define LIGHT_SENSOR_SUPPLY_MASK           (1 << 6)

#define LIGHT_SENSOR_SUPPLY_ON             (LIGHT_SENSOR_SUPPLY_PORT->BSRR |= LIGHT_SENSOR_SUPPLY_MASK)
#define LIGHT_SENSOR_SUPPLY_OFF            (LIGHT_SENSOR_SUPPLY_PORT->BSRR |= LIGHT_SENSOR_SUPPLY_MASK<<16)
#define LIGHT_SENSOR_SUPPLY_TOGGLE         (LIGHT_SENSOR_SUPPLY_PORT->ODR  ^= LIGHT_SENSOR_SUPPLY_MASK)

/** @} */


/**
 * @name External GPIO on pad TP3
 * @{
 */
#define EXTERNAL_GPIO_PIN            			GPIO_PIN(PORT_A,8)
#define EXTERNAL_GPI0_PORT           			GPIOA
#define EXTERNAL_GPI0_MASK           			(1 << 8)

/** @} */


/**
 * @name Speaker PWM on pads TP14/1P15
 * @{
 */
#define SPEAKER_PWM_PIN            				GPIO_PIN(PORT_A,1)
#define SPEAKER_PWM_PORT           				GPIOA
#define SPEAKER_PWM_MASK           				(1 << 1)

/** @} */


/**
 * @name Button 1 on pads TP7/TP10
 * @{
 */
#define BTN1_PIN            				GPIO_PIN(PORT_B,3)
#define BTN1_PORT           				GPIOB
#define BTN1_MASK           				(1 << 3)

/** @} */


/**
 * @name    sx1272 configuration
 * @{
 */

#define SX127X_PARAM_SPI                    (SPI_DEV(0))

#define SX127X_PARAM_SPI_NSS                GPIO_PIN(1,0)       /* SPI1_CS */

#define SX127X_PARAM_RESET                  GPIO_PIN(0,2)       /* PA2 */

#define SX127X_PARAM_DIO0                   GPIO_PIN(0,10)      /* PA10 */

#define SX127X_PARAM_DIO1                   GPIO_PIN(1,10)      /* PB10 */

#define SX127X_PARAM_DIO2                   GPIO_PIN(1,11)      /* PB11 */

#define SX127X_PARAM_DIO3                   GPIO_PIN(1,7)       /* PB7 */

/**< RFO HF or RFO LF */
#define SX127X_PARAM_PASELECT               (SX127X_PA_RFO)

#define SX127X_PARAM_TX_SWITCH              GPIO_PIN(0,4)		/* PA4 */

#define SX127X_PARAM_RX_SWITCH              GPIO_PIN(2,13)		/* PC13 */

// DIO4 --> PB5
// DIO5 --> PB4


/** @} */




/**
 * @brief Initialize board specific hardware, including clock, LEDs and std-IO
 */
void board_init(void);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/** @} */
