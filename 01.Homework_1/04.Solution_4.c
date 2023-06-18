#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

// The function below converts the passed argument 
// (which mimics octal number system format)
// into an int that contains only ones and zeros.
// The purpose of this is to mimic a binary format!
int convert(short oct) {

    unsigned short dec = 0;
    int i = 0;
    int bin = 0;

    // Converting octal to decimal
    while (oct != 0) 
    {
        dec += (oct % 10) * pow(8, i);
        ++i;
        oct /= 10;
    }
    i = 1;

   // Converting decimal to binary
    while (dec != 0) 
    {
        bin += (dec % 2) * i;
        dec /= 2;
        i *= 10;
    }

    return bin;
}

// The following function prints to the standard output
// the file permissions in Linux!
// It receives as an argument the int from the previous
// function (which mimics a binary number system).
void printPermissions(int binary_code){

    char users_permissions[9] = "";
    char charToAdd            = 'R';
    int  check_if_true        = 0;
    int  sequent_digit        = binary_code;
    int  ten_power            = 10;
    int  code_length          = 0;
    
    if (binary_code > 0)
    {
        // Find the length of the pseudo binary code
        code_length = floor(log10(abs(binary_code))) + 1;
    }

    // For loop for the three types of users:
    // u (user owner), g (group owner) and o (others).
    for (short user = 0; user < 3; user++)
    {
        // For loop for the three types of permissions:
        // r (read), w (write), and x (execute).
        for (short permissions = 0; permissions < 3; permissions++)
        {          

            if (9 - code_length > 0)
            {
                check_if_true = 0; 
            }
            if (9 - code_length <= 0)
            {
                // Take the digits of the decimal number 
                // (which represents the binary code) 
                // one by one and from left to righ
                while (sequent_digit >= ten_power)
                {
                    sequent_digit = sequent_digit / 10;
                }
                check_if_true = sequent_digit % 10;
                ten_power *= 10;
            }

            code_length++;
            sequent_digit = binary_code;


            switch (permissions) 
            {
                case 0:
                    (check_if_true == 1) ? (charToAdd = 'R') : (charToAdd = '-');
                    strncat(users_permissions, &charToAdd, 1);               
                    break;
                case 1:
                    (check_if_true == 1) ? (charToAdd = 'W') : (charToAdd = '-');
                    strncat(users_permissions, &charToAdd, 1);  
                  break;
                case 2:
                    (check_if_true == 1) ? (charToAdd = 'X') : (charToAdd = '-');
                    strncat(users_permissions, &charToAdd, 1);
                  break;
            }
        }
    }

    printf("\nUser:\n");
    printf ("%.*s\n", 3, users_permissions);
    printf("Group:\n");
    printf ("%.*s\n", 3, users_permissions + 3);
    printf("Other:\n");
    printf ("%.*s\n", 3, users_permissions + 6);
    printf("\n");
}


int main() {

    short oct;
    printf("Please, enter 3 digit octal number: ");
    scanf("%hd", &oct);

    printPermissions(convert(oct));

    return 0;
}
