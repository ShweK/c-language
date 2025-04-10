#include <stdio.h>

void main() {
    float input1 = 0, input2 = 0, answer = 0;
    char opt = 2;
    char more_calculations = 'y';
    int not_valid = 0;
    int div_by_zero_error = 0;

    printf("Welcome to the Calculator Program!\n");
   
    do {
        printf("Enter first number: ");
        scanf("\n%f", &input1);
    
        printf("Enter second number: ");
        scanf("\n%f", &input2);

        div_by_zero_error = 0;

        do {
            printf("Enter Operation (+,-,*,/): ");
            scanf("\n%c", &opt);

            not_valid = 0;
            switch (opt) {
                case '+': 
                    answer = input1 + input2; 
                    break;
                case '-': 
                    answer = input1 - input2;
                    break;
                case '*':
                    answer = input1 * input2; 
                    break;
                case '/': 
                    if (input2 == 0) {
                        printf("Second Number should not be a 0\n");
                        div_by_zero_error = 1;
                    }
                    answer = input1 / input2;
                    break;
                default: 
                    printf("Invalid input.\n");
                    not_valid = 1;
            }

            if (div_by_zero_error == 1) {
                break;
            }
        } while (not_valid == 1);

        if (div_by_zero_error == 1) {
            continue;
        }
        
        printf("Result: %f %c %f = %f\n", input1, opt, input2, answer);
        printf("Would you like to calculate agian? (y/n): ");
        scanf("\n%c", &more_calculations);
    } while (more_calculations == 'y');
    
    printf("Thank you for using the Calculator program. Goodbye!\n");
}