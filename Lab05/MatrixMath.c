#include <stdio.h>
#include <math.h>
#include <errno.h>

#define SIZE 5

void printMatrix(int matrix[SIZE][SIZE]);
void addMatrix(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrix(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]);

int main() {
    int m1[SIZE][SIZE];
    int m2[SIZE][SIZE];
    int counter;

    // fill m1
    counter = 1;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            m1[i][j] = counter;
            counter++;
        }
    }

    // fill m2
    counter = pow(SIZE, 2);
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            m2[i][j] = counter;
            counter--;
        }
    }

    // print original matricies
    printf("\nprint original matricies");
    printMatrix(m1);
    printMatrix(m2);

    // add matricies
    printf("\nadd matricies");
    int addedMatrix[SIZE][SIZE];
    addMatrix(m1, m2, addedMatrix);
    printMatrix(addedMatrix);

    // multiply matricies
    printf("\nmultiply matricies");
    int multipliedMatrix[SIZE][SIZE];
    multiplyMatrix(m1, m2, multipliedMatrix);
    printMatrix(multipliedMatrix);

    // transpose matrix
    printf("\ntranspose matrix");
    int transposedMatrix[SIZE][SIZE];
    transposeMatrix(m1, transposedMatrix);
    printMatrix(transposedMatrix);

    return 0;
}

// print matrix to terminal
void printMatrix(int matrix[SIZE][SIZE]){
    printf("\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%-3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// add m1 and m2 to result
void addMatrix(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// multiply m1 and m2 to result
void multiplyMatrix(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]){
    // check requirements for multiplication
    // square matricies are... always going to be multiplicable?
    int m1Rows = SIZE;
    int m2Cols = SIZE;
    if (m1Rows != m2Cols){
        printf("The bounds of the matricies do not permit multiplication.");
    }else{
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                // location of multiplication
                result[i][j] = 0;

                for(int k = 0; k < SIZE; k++){
                    result[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
    }
}

// transpose matrix to result
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            result[j][i] = matrix[i][j];
        }
    }
}