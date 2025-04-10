#include <stdio.h>

void main(){
    float num1 = 0, num2 = 0, ans = 0;
    char opt;
    char loop = 0;
    int not_valid = 0, div_by_zero_error = 0;

    printf("Welcome to the Calculator APP!\n");

    do {
        printf("Enter 1st number: ");
        scanf("%f", &num1);

        printf("Enter 2nd number: ");
        scanf("%f", &num2);

        div_by_zero_error = 0;

        do {
            printf("Select an operation: +, -, *, /: ");
            scanf(" %c", &opt);
            not_valid = 0;

            switch (opt) {
                case '+':
                    ans = num1 + num2;
                    printf("Addition result: %f\n", ans);
                    break;
                case '-':
                    ans = num1 - num2;
                    printf("Subtraction result: %f\n", ans);
                    break;
                case '*':
                    ans = num1 * num2;
                    printf("Multiplication result: %f\n", ans);
                    break;
                case '/':
                    if (num2 == 0) {
                        printf("Division not possible as the second number is 0\n");
                        div_by_zero_error = 1;
                    } else {
                        ans = num1 / num2;
                        printf("Division result: %f\n", ans);
                    }
                    break;
                default:
                    printf("Invalid operation\n");
                    not_valid = 1;
            }
        } while (not_valid == 1 && div_by_zero_error == 0);

        // This part will now always execute, regardless of errors
        printf("Would you like to calculate again? (y/n): ");
        scanf(" %c", &loop);

    } while (loop == 'y');

    printf("Thank you for using the calculator program. Goodbye!\n");
}
