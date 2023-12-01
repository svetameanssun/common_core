

// C program that demonstrates wild pointers
int main()
{
    /* wild pointer */
    int* p;
    /* Some unknown memory location is being corrupted.
    This should never be done. */
    *p = 12;
}

/*If a pointer points to a known variable
then it’s not a wild pointer.*/


//In the below program, p is a wild pointer till this points to a.
int main()
{
    int* p; /* wild pointer */
    int a = 10;
    /* p is not a wild pointer now*/
    p = &a;
    /* This is fine. Value of a is changed */
    *p = 12;
}

/*If we want a pointer to a value (or set of values)
without having a variable for the value,
we should explicitly allocate memory and
put the value in the allocated memory.*/



int main()
{
    int* p = (int*)malloc(sizeof(int));
    // This is fine (assuming malloc doesn't return
    // NULL)
    *p = 12;
}

