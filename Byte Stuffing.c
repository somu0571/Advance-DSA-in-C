#include <stdio.h> 
#define FLAG 'F'
#define ESC 'E'

int main() {
    char data[100], stuffed[200];
    int i, j = 0;
    printf("Enter data: ");
    scanf("%s", data);
    stuffed[j++] = FLAG;
    for (i = 0; data[i] != '\0'; i++) {
        if (data[i] == FLAG || data[i] == ESC) {
            stuffed[j++] = ESC;   
        }
        stuffed[j++] = data[i];
    }
    stuffed[j++] = FLAG;
    stuffed[j] = '\0';
    printf("Stuffed Data: %s\n", stuffed);
    return 0;
}
