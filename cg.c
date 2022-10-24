#include <stdio.h>

void read_words(FILE *f, int arr[100][100]) {
    int n;
    for (int i = 0; i < 100; i++) {
        fscanf(f, "%d", &n);
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &arr[i][j]);
        }
    }
}

void cleanArray(int arr[100][100]) {

    for (int i = 0; i < 100; i++) {
        int digits[9] = {0};
        // find most amount of numbers with same value within each row
        for (int j = 0; j < 100; j++) {
            for (int k = 1; k <= 9; k++) {
                if (arr[i][j] == k) {
                    digits[k-1]++;
                }
            }
        }

        // replace all numbers with 0 except the most common number
        int max = 0;
        for (int k = 0; k < 9; k++) {
            if (digits[k] > max) {
                max = k+1;
            }
        }
        for (int j = 0; j < 100; j++) {
            if (arr[i][j] != max) {
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    FILE *f = fopen("Uloha1 Input 2022.txt", "r");

    int arr[100][100];
    read_words(f, arr);
    
    // print array
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < i+1; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    cleanArray(arr);

    // print array
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < i+1; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    fclose(f);

    return 0;
}