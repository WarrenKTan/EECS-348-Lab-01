#include <stdio.h>

// used for pow() function
#include <math.h>

int main() {
    // define variables
    int input1;
    char operation;
    int input2;

    // initial inputs
    printf("Enter 1st operand: ");
    scanf("%d", &input1);
    printf("Enter operation: ");
    scanf(" %c", &operation);

    // switch each operation type, getting a second input if necessary
    if(operation == 's'){
        printf("%f", pow(input1, 2));
    }else{
        printf("Enter 2nd operand: ");
        scanf("%d", &input2);
        switch (operation){
            case '+':
                printf("%d", input1 + input2);
                break;
            case '-':
                printf("%d", input1 - input2);
                break;
            case '*':
                printf("%d", input1 * input2);
                break;
            case '/':
                printf("%lf", ((double) input1 / (double) input2));
                break;
            default:
                printf("\'%c\' is not an accepted operation.", operation);
                break;
        }
    }
    
    return 0;
}