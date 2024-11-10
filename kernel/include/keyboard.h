/**
 * @file 
 * @brief Implementacion del modulo de manejo del teclado
 * @author Julian Munoz Perez <julianalejom@unicauca.edu.co>
 */
#ifndef KEYBOARD_H
#define KEYBOARD_H

#define KEY_BOARD_HAS_DATA 0x01

#define KEY_BOARD_IRQ 1

#define KEY_BOARD_STATUS_PORT 0x64

#define KEY_BOARD_DATA_PORT 0x60
/**
 * @brief Inicializa el modulo de manejo de teclado 
 */
void setup_keyboard();



#endif