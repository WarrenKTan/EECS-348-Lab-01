#include <stdio.h>

// used for pow() function
#include <math.h>

#define LIGHT 10000
#define MEDIUM 26000

int main() {
    // define variables
    int input;
    char weight;

    // initial user inputs
    printf("Enter vehicle weight: ");
    scanf(" %d", &input);

    //assignment logic
    if(input < LIGHT){
        weight = 'l';
    }else if(input < MEDIUM){
        weight = 'm';
    }else{
        weight = 'h';
    }

    printf("%c", weight);
    
    return 0;
}