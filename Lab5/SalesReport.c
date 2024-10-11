#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int min(float arr[], int n);
int max(float arr[], int n);
float avg(float arr[], int lowerBound, int upperBound);
void swap(float* xp, float* yp);
void bubbleSort(float arr[], char arr2[][12], int n);

int main() {
    FILE *myFile;
    char fileName[64];
    char line[256];
    char month[32][12] = {"January", 
                           "February", 
                           "March", 
                           "April", 
                           "May", 
                           "June", 
                           "July", 
                           "August", 
                           "September", 
                           "October", 
                           "November", 
                           "December"};
    float sales[12];

    // get file from user
    printf("Enter the file name: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = '\0';
    myFile = fopen(fileName, "r");

    printf("\n\n");

    // error opening file
    if (myFile == NULL) {
        printf("file could not be opened\n");
        return EXIT_FAILURE;
    }

    // get file line by line
    int i = 0;
    char* endFloat;

    printf("Monthly Sales Report for 2024\n\nMonth\t\tSales\n");
    while (fgets(line, sizeof(line), myFile) && i < 12) {
        sales[i] = strtof(line, &endFloat);
        printf("%-10s %12.2f\n", month[i], sales[i]);
        i++;
    }

    //min, max, and average
    printf("\n\nSales summary report:\n\n");
    int minIndex = min(sales, 12);
    int maxIndex = max(sales, 12);
    float avgSales = avg(sales, 0, 12);
    printf("Minimum sales: %.2f (%s)\n", sales[minIndex], month[minIndex]);
    printf("Maximum sales: %.2f (%s)\n", sales[maxIndex], month[maxIndex]);
    printf("Average sales: %.2f\n", avgSales);

    // 6-Month averages
    printf("\n\nSix-Month moving average report:\n\n");
    for (int j = 0; j < 7; j++) {
        printf("%s-%s%20.2f\n", month[j], month[j + 5],  avg(sales, j, j + 6));
    }

    // sort by sales
    printf("\n\nSales report (highest to lowest):\n\nMonth\t\tSales\n");
    bubbleSort(sales, month, 12);
    for (int i = 0; i < 12; i++) {
        printf("%-15s$%.2f\n", month[i], sales[i]);
    }

    // close file
    fclose(myFile);
    return 0;
}

// sorts arr (high -> low)
void bubbleSort(float arr[], char arr2[][12], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                char temp[32];
                strcpy(temp, arr2[j]);
                strcpy(arr2[j], arr2[j + 1]);
                strcpy(arr2[j + 1], temp);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

// finds min of arr and returns the index
int min(float arr[], int n){
    int i;
    int j = 0;
    for (i = 0; i < n; i++) {
        if (arr[j] > arr[i]){
            j = i;
        }
    }

    return j;
}

// finds max of arr and returns the index
int max(float arr[], int n){
    int i;
    int j = 0;
    for (i = 0; i < n; i++) {
        if (arr[j] < arr[i]){
            j = i;
        }
    }

    return j;
}

// takes average of range in arr
float avg(float arr[], int lowerBound, int upperBound){
    int i;
    int j = lowerBound;
    float sum = 0;
    int averageCount = upperBound - lowerBound;
    for (i = lowerBound; i < upperBound; i++) {
        sum += arr[i];
    }

    return sum/averageCount;
}

// swap pointers
void swap(float* xp, float* yp){
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}