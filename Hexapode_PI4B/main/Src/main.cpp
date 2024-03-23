#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#define RX_BUFFER_SIZE 256 // Taille du tampon de réception

int main() {
    int fd;

    // Initialisation de WiringPi et ouverture du port série
    if ((fd = serialOpen("/dev/ttyS0", 115200)) < 0) {
        fprintf(stderr, "Impossible d'ouvrir le port série.\n");
        return 1;
    }

    char rx_buffer[RX_BUFFER_SIZE];
    int rx_index = 0;

    while(1) {
        // Envoi de données
        printf("Envoi de données via UART...\n");
        serialPuts(fd, "Hello STM32!\n");

        // Réception de données
        while (serialDataAvail(fd)) {
            char c = serialGetchar(fd);
            rx_buffer[rx_index++] = c;
            // Vérifier si la trame est complète
            if (c == '\n' || rx_index >= RX_BUFFER_SIZE) {
                rx_buffer[rx_index] = '\0'; // Terminer la chaîne avec un caractère nul
                printf("Trame reçue : %s\n", rx_buffer);
                rx_index = 0; // Réinitialiser l'index du tampon de réception
            }
        }
        delay(1000); // Attendre 1 seconde
    }

    // Fermeture du port série
    serialClose(fd);

    return 0;
}