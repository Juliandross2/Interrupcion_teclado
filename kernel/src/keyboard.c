/**
 * @file 
 * @brief Implementacion del modulo de manejo del teclado
 * @author Julian Munoz Perez <julianalejom@unicauca.edu.co>
 */
#include <asm.h>
#include <console.h>
#include <keyboard.h>
#include <pm.h>
/**
 * @brief rutina manejadora de la irq del teclado
 * @param state estado del procesador al ser interrumpido por el teclado
 */
void keyboard_handler(interrupt_state * state);

void setup_keyboard(){
    console_printf("Setupiando up el keyboard...\n");
    install_irq_handler(KEY_BOARD_IRQ,keyboard_handler);
}

void keyboard_handler(){
    //SACAR EL DATO
    unsigned char status;
    unsigned char data;
    //Obtiene la info del puerto de estado 
    //es decir recupera el byte de registro de estado del controlador
    //del teclado
    status = inb(KEY_BOARD_STATUS_PORT);
    //Solo si tiene datos debería pasar del if ya que
    //debería retornar si el 8042 no tiene datos en su registro de salida(0x60)
    if(!(status & KEY_BOARD_HAS_DATA)){
        return;
    }
    //POSTCONDICION : El 8042 tiene datos por leer 
    data = inb(KEY_BOARD_DATA_PORT);
    console_printf("Data: %d 0x%x\n", data, data );
}
