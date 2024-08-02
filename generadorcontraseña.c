#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
#include <string.h>  

#define LENGTH 12 // Puedes cambiar la longitud de la contraseña aquí  

char *generate_password(int length) {  
    const char charset[] = "abcdefghijklmnopqrstuvwxyz"  
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"  
                           "0123456789"  
                           "!@#$%^&*()_+[]{}|;:,.<>?";  
    char *password = malloc(length + 1); // +1 para el carácter nulo  

    if (password) {  
        for (int n = 0; n < length; n++) {  
            int key = rand() % (int)(sizeof(charset) - 1);  
            password[n] = charset[key];  
        }  
        password[length] = '\0'; // Añadir el carácter nulo al final de la cadena  
    }  
    return password;  
}  

int main() {  
    srand(time(NULL)); // Inicializar la semilla para generadores de números aleatorios  

    char *password = generate_password(LENGTH);  
    if (password) {  
        printf("Contraseña generada: %s\n", password);  
        free(password); // Liberar la memoria asignada  
    } else {  
        printf("Error al generar la contraseña.\n");  
    }  

    return 0;  
}