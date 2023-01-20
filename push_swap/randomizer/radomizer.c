#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    // Check if the user provided a value for n
    if (argc < 2) {
        printf("Please provide a value for n as a command line argument.\n");
        return 1;
    }

    int n = atoi(argv[1]);
    char s1 = '"';
    char s2 = ',';
    char s3 = ' ';
    

    // Initialize the random number generator
    srand(time(NULL));

    // Create an array to store the random numbers
    int* random_numbers = (int*) malloc(n * sizeof(int));

    // Generate n unique random numbers
    int i, rand_num;
    for (i = 0; i < n; i++) {
        rand_num = rand() % n + 1;
        int j;
        for (j = 0; j < i; j++) {
            if (random_numbers[j] == rand_num) {
                i--;
                break;
            }
        }
        if (j == i) {
            random_numbers[i] = rand_num;
        }
    }

    // Open the output file
    FILE* file = fopen("generator.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the numbers to the file
    for (i = 0; i < n; i++) {
    	if (i + 1 != n)
        	fprintf(file, "%c%d%c%c%c ", s1, random_numbers[i], s1, s2, s3);
        else
        	fprintf(file, "%c%d%c ", s1, random_numbers[i], s1);
    }

    // Close the file and free the memory
    fclose(file);
    free(random_numbers);

    return 0;
}


