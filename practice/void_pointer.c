#include <stdio.h>

// C Program to demonstrate that a void pointer
// can hold the address of any type-castable type
/*int main()
{
    int a = 10;
    char b = 'x';
 
    // void pointer holds address of int 'a'
    void* p = &a;
    // void pointer holds address of char 'b'
    p = &b;
}*/



// C Program to demonstrate that a void pointer
// cannot be dereferenced
 
/*int main()
{
    int a = 10;
    void* ptr = &a;
    printf("%d", *ptr);
 
    return 0;
}*/

// C program to dereference the void
// pointer to access the value
 
 
/*int main()
{
    int a = 10;
    void* ptr = &a;
    // The void pointer 'ptr' is cast to an integer pointer
    // using '(int*)ptr' Then, the value is dereferenced
    // with `*(int*)ptr` to get the value at that memory
    // location
    printf("%d", *(int*)ptr);
    return 0;
}*/


// C program to demonstrate the usage
// of a void pointer to perform pointer
// arithmetic and access a specific memory location

 
int main()
{
    // Declare and initialize an integer array 'a' with two
    // elements
    int a[3] = { 1, 2, 3 };
    // Declare a void pointer and assign the address of
    // array 'a' to it
    void* ptr = &a;
 
    // Increment the pointer by the size of an integer
    ptr = ptr + sizeof(int) * 2;
 
    // The void pointer 'ptr' is cast to an integer
    // pointer using '(int*)ptr' Then, the value is
    // dereferenced with `*(int*)ptr` to get the value at
    // that memory location
    printf("%d", *(int*)ptr);

    return 0;
}

 