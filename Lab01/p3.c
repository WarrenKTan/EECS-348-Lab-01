#include <stdio.h>

// helper method to tell if 'n' is prime
int isPrime(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return 0;
        }
    }

    return 1;
}

int main() {
    // define variables
    int input;

    // initial user inputs
    printf("Enter a number: ");
    scanf(" %d", &input);

    // read through every input 0-'input'
    for(int i = 0; i < input; i++){
        // print 'i' if it is prime
        if(isPrime(i)){
            printf("%d ", i);
        }
    }

    return 0;
}
