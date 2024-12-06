#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* fileslurp(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;  // Return NULL on error
    }

    // Seek to the end to find the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the entire file content + null terminator
    char *buffer = (char *)malloc(size + 1);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;  // Return NULL if memory allocation fails
    }

    // Read the file into the buffer
    size_t bytesRead = fread(buffer, 1, size, file);
    if (bytesRead != size) {
        perror("Error reading file");
        free(buffer);  // Free the allocated memory before returning
        fclose(file);
        return NULL;
    }

    // Null-terminate the string
    buffer[bytesRead] = '\0';

    fclose(file);
    return buffer;
}
