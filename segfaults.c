#include <stdio.h>

int 
main(void)
{
    printf("Welcome!");
    char *string = "meow";
    printf("Our string is: %s\n", *string);
    *string = 'W';
    printf("Animals make: %s\n", string);

}
