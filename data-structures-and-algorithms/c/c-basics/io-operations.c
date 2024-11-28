#include <stdio.h>

int main() {
    /*
    r   Read (file must exist)
    w   Write (creates/overwrites)
    a   Append (creates if missing)
    r+  Read/Write
    w+  Write/Read (truncates file)
    a+  Append/Read
    */

    // Text File Operations
    char content[100];
    FILE *file = fopen("./loops.c", "r+");
    
    if (file == NULL) {
        printf("Error opening ./loops.c\n");
    } else {
        // Read and print content
        printf("Reading content from loops.c:\n");
        while (fscanf(file, "%s", content) != EOF) {
            printf("%s ", content); // Add space for better readability
        }

        // Write into the file
        fprintf(file, "\nsksdksksks\n");

        fclose(file); // Close the file
    }

    // Binary File Operations
    int nums[5] = {1, 2, 3, 4, 5};
    FILE *bin = fopen("data.bin", "wb"); // Binary write mode
    if (bin == NULL) {
        printf("Error opening data.bin\n");
    } else {
        printf("\n=====Writing binary data...====\n");
        fwrite(nums, sizeof(int), 5, bin); // Write 5 integers
        fclose(bin); // Close the file after writing
    }

    // Reading binary file
    bin = fopen("data.bin", "rb"); // Binary read mode
    if (bin == NULL) {
        printf("Error opening data.bin for reading\n");
    } else {
        printf("=======Reading binary data...======\n");
        fread(nums, sizeof(int), 5, bin); // Read 5 integers
        fclose(bin); // Close the file

        // Print the integers read from the file
        printf("=======Binary file contents:=======\n");
        for (int i = 0; i < 5; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
//Character by character
printf("=======================Single chars===============\n");
FILE *f = fopen("loops.c", "r");
if (f != NULL) {
    char c;
    while ((c = fgetc(f)) != EOF) {
        putchar(c); // Print character to console
    }
    fclose(f);
}
    return 0;
}
