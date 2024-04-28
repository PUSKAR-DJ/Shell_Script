#include <stdio.h>

int main() {
    FILE *file_pointer;
    char filename[100];

    // Prompt user to enter filename
    printf("Enter the filename to create: ");
    scanf("%s", filename);

    // Attempt to open the file in write mode
    file_pointer = fopen(filename, "w");

    // Check if file creation was successful
    if (file_pointer == NULL) {
        printf("Unable to create file.\n");
        return 1; // Exit with error
    }

    printf("File created successfully: %s\n", filename);

    // Close the file
    fclose(file_pointer);

    return 0; // Exit with success
}
/*
Compile

gcc create_file.c -o create_file
Run
./create_file
*/
