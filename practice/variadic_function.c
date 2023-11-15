#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
//#include "/c/Desktop/common_core/libft/ft_strjoin.c"
//#include "/c/Desktop/common_core/libft/ft_strlen.c"



//Variadic function to add numbers:
/*int add_numbers(int n, ...)
{
    int sum = 0;
    
    //Declaring pointer to the argument list
    va_list ptr;

    //Initializing argument to the list pointer
    va_start(ptr, n);
    for (int i = 0; i < n; i++)
    {
        //Accessing current variable and pointing to next one
        sum  = sum + va_arg(ptr, int);
    }
    va_end(ptr);
    return sum;
}*/

//Driver code for add_numbers:
/*int main()
{
    printf("\n\n Variadic functions; \n");

    //Variable number of arguments
    printf("\n 1 + 2 = %d",
        add_numbers(2, 1, 2));
    
    printf("\n 3 + 4 + 5 = %d",
        add_numbers(3, 3, 4, 5));
    
    printf("\n 6 + 7 + 8 + 9 = %d",
        add_numbers(4, 6, 7, 8, 9));
    
    printf("\n");
    return 0;
}*/


//Extra functions used for print_words
/*size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}*/
/*char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t len_s1 = ft_strlen(s1);
	size_t len_s2 = ft_strlen(s2);
    if(!s1)
        len_s1 = 0;

	new = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < (len_s1 + len_s2))
	{
		new[i] = s2[i - len_s1];
		i++;
	}
	new[i] = '\0';
	return (new);
}*/

//Variadic function to print words:
/*void print_words(int n, ...)
{
    char word[6] = "word ";
    char *result;
    //странно, но если сделать char *result = NULL,
    //то получается Segmentation fault.
    //Может, проблема в a.exe

    //Declaring pointer to the argument list
    va_list ptr;

    //Initializing argument to the list pointer
    va_start(ptr, n);
    for(int i=0; i< n; i++)
    {
        //Accessing current variable and pointing to next one
        va_arg(ptr, int);
        result = ft_strjoin(result, word);
    }

    va_end(ptr);
    printf("\n\n Print Words Function\n", result);
    printf("%s", result);
    printf("\n");

}*/

//Driver code for print_words:
/*int main()
{
    printf("\n\n Variadic functions; \n");

    //Variable number of arguments;
    
    print_words(3, 0,0,0);
    return 0;
}*/


//Variadic Function to find the largest number:
/*int largest_number(int n, ...)
{
    int i = 0;
    va_list ptr;
    va_start(ptr,n);

    int max = va_arg(ptr, int);
    if(n == 1)
        return(max);
    if(n == 2)
    {
        int temp  = va_arg(ptr,int);
        if(temp > max)
        {
            return(temp);
        }
        return (max);
    }

    while(i<n)
    {
        int temp  = va_arg(ptr,int);
        
        if (temp > max)
        {
            max = temp;
        }
        i++;
    }
    return (max);
}*/

//Driver code for largest_number:
/*int main()
{
    printf("\n\n Variadic function largest_number: \n");

    //Variable number of arguments
    printf("\n [1, 2] largest is - %d",
        largest_number(2, 1, 2));
    
    printf("\n [1, 222, 13] largest is - %d",
        largest_number(3, 1, 222, 13));
    
    printf("\n [1, 222, 13, 22, 100, 900] largest is - %d",
        largest_number(6, 1, 222, 13, 22, 100, 900));
    
    printf("\n");
    return 0;
}*/

//Variadic Function to find the smallest number:
int smallest_number(int n, ...)
{
    int i = 0;
    va_list ptr;

    va_start(ptr,n);
    int min = va_arg(ptr,int);
    printf("min = %i\n", min);
    printf("\nSTART WHILE\n");
    while(i < n-1)    {
        printf("\nwhile number%i \n",i);
        printf("i = %i\n", i);
        int temp = va_arg(ptr,int);
        printf("temp = %i\n", temp);
        if(min > temp)
        {
            min = temp;
        }
        printf("min = %i\n", min);
        printf("\n");
        printf("\n");
        i++;
    }
    printf("END WHILE");
    va_end(ptr);
    return (min);
}

//Driver code for smallest_number:
int main()
{
    printf("\n\n Variadic function smallest_number: \n");

    //Variable number of arguments
    printf("\n [1, 2] smallest is - %d",
        smallest_number(2, 1000, 2));
    
    printf("\n [1, 222, 13] smallest is - %d",
        smallest_number(3, 1000, -222, 13));
    
    printf("\n [1, 222, 13, 22, 100, 900] smallest is - %d",
        smallest_number(6, 1000, -222, 13, 22, 100, 900));
    
    printf("\n");
    return 0;
}