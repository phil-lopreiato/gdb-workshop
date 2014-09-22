#include <stdio.h>

int 
main(void)
{
 /* Things that cause segfaults:
    // Phil does these
    Dereferencing NULL pointers – this is special-cased by memory management hardware
    Attempting to access a nonexistent memory address (outside process's address space)
    Attempting to access memory the program does not have rights to (such as kernel structures in process context)
    Attempting to write read-only memory (such as code segment)
    These in turn are often caused by programming errors that result in invalid memory access:
    
    // Neel does these
    Dereferencing or assigning to an uninitialized pointer (wild pointer, which points to a random memory address)
    Dereferencing or assigning to a freed pointer (dangling pointer, which points to memory that has been freed/deallocated/deleted)
    A buffer overflow
    A stack overflow
  */

    

    // write to read only memory
    char *string;
    printf("Our string is: %s\n", *string);
    *string = 'W';
    printf("Animals make: %s\n", string);

}
