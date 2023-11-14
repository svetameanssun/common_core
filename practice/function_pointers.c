#include <stdio.h>
#include <stdbool.h> 

// how sizeof works 
/*int main ()
{
    int arr[] = {10,5 ,15, 12, 90, 80};
    int n = sizeof(arr);
    printf("%d", n);//Output: 24, because each element's size is 4 bytes
    return (0);
}*/
// Here we are sorting an array of integers using function pointer (compare)
/*int compare (const void *a , const void *b)
{
    return (*(int*)a - *(int*)b);
}
int main ()
{
    int arr[] = {10,5 ,15, 12, 90, 80};
    int n = sizeof(arr)/sizeof(int);
    int i;
    qsort(arr, n, sizeof(int), compare);
    for (i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    return (0);
}*/


// and array of function pointers:
/*int add(int a, int b)
{
    return(a+b);
}

int mult(int a, int b)
{
    return(a*b);
}

int subt(int a, int b)
{
    return(a-b);
}
int main()
{
    int (*func_ptr_arr[])(int,int) = {add, mult, subt};
    unsigned int ch;
    unsigned int a = 15;
    unsigned int b = 10;
    printf("Enter choice: 0 - add, 1 - mult, 2 - subt");
    scanf("%d", &ch);
    if (ch > 2)
        return 0;
    
    int res = (*func_ptr_arr[ch])(a,b);
    printf("%d", res);
    return (0);
}*/

/*void funct1(void)
{
    printf("Function 1\n");
}
void funct2(void)
{
    printf("Function 2\n");
}
int funct3(int a)
{
    return (a);
}

void wrapper1(void (*any_void_funct)())
{
    any_void_funct();
}

int wrapper2(int(*any_int_funt)(int), int a)
{   
    int res;
    res = funct3(a);
    return (res);
}

int main()
{
    wrapper1(funct1);
    wrapper1(funct2);
    int res = wrapper2(funct3, 12);
    printf("%d", res);
    return (0);
}*/
/*Similar to qsort(), we can write our own functions that can be used for any data type
and can do different tasks without code redundancy. Below is an example search function
that can be used for any data type.
In fact we can use this search function to find close elements (below a threshold) by writing a customized compare function.*/
  
// A compare function that is used for searching
// an integer in an array 

/*bool compare (const void * a, const void * b)
{
    return ( *(int*)a == *(int*)b );
}
// General purpose search() function that can be used 
// for searching an element *x in an array arr[] of 
// arr_size. Note that void pointers are used so that 
// the function can be called by passing a pointer of 
// any type.  ele_size is size of an array element 
*/
/*int search(void *arr, int arr_size, int ele_size, void *x,
            bool compare (const void *, const void *))
{ 
    // Since char takes one byte, we can use char pointer 
    // for any type/ To get pointer arithmetic correct, 
    // we need to multiply index with size of an array 
    // element ele_size 
    char *ptr = (char *)arr;

    int i;
    for (i = 0; i<arr_size; i++)
        if( compare(ptr + i * ele_size, x))
            return i;
    // If element not found 
    return -1;
}*/
/*int main() 
{ 
    int arr[] = {2, 5, 7, 90, 70}; 
    int num_el = sizeof(arr)/sizeof(arr[0]); 
    int x = 90; 
    printf ("Returned index is %d ", search(arr, num_el, sizeof(int), &x, compare)); 
    return 0; 
}*/
//Output: Returned index is 3

//Derefencing NULL pointer:
int main() 
{ 
    int *ptr = NULL;
    printf ("%d", *ptr);
    return 0; 
}
// zsh: segmentation fault  ./a.out




    