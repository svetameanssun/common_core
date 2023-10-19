
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//PRACTICE

//delfina's variant that does not work
/*char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1[start] || !set[start])
		return (0);
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]))
	{
		printf("%zu", end);
		end--;
	}
	ptr = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_substr(s1, start, ((end - start)));
	return (ptr);
}*/
/*#include <stdlib.h>

int main(void)
{
char *s1;
char *s2;
char *s3;
int i;
s1 = "franco";
s2 = "curulla";
s3 = "galan";
i = 0;
while (*s1 != 'c')
	s1++;
while (*s2+i != 'l')
{
    i++;
    printf("%d---", i);
}
while (s3[i] != 'l')
{ 
	i++;
    printf("%d+++", i);
}
printf("\n%s\n", s1);
printf("%s\n", s2);
printf("%s\n", s3);
    return 0;
}
//Trying malloc
int main(void)
{
    char * str_mal;
    str_mal = malloc(sizeof(char)*5);

    char * str_cal;
    str_cal = calloc(sizeof(char),5);

    //printf("%p\n", str);
    //printf("%p", str1);

    //Malloc elements
    printf("%c\n", str_mal[0]);
    printf("%c\n", str_mal[1]);
    printf("%c\n", str_mal[2]);
    printf("%c\n", str_mal[3]);
    printf("%c\n", str_mal[4]);

    //Directions of malloc element
    printf("%p\n",&str_mal[0]);
    printf("%p\n",&str_mal[1]);
    printf("%p\n",&str_mal[2]);
    printf("%p\n",&str_mal[3]);
    printf("%p\n",&str_mal[4]);


    //Calloc elements
    printf("%c\n", str_cal[0]);
    printf("%c\n", str_cal[1]);
    printf("%c\n", str_cal[2]);
    printf("%c\n", str_cal[3]);
    printf("%c\n", str_cal[4]);

    //Directions of calloc element
    printf("%p\n",&str_cal[0]);
    printf("%p\n",&str_cal[1]);
    printf("%p\n",&str_cal[2]);
    printf("%p\n",&str_cal[3]);
    printf("%p\n",&str_cal[4]);

    int i = 0;
    int j = 0;
    while(str_mal[i])
    {
        printf("%d\n", str_mal[i]);
        i++;
    }
    while(str_cal[j])
    {
        printf("%d\n", str_cal[j]);
        j++;
    }
}*/
/*int main(void)
{  
    //Two-Dimensional Arrays
    /*int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };

    int i = 0;
    int j = 0;
    while ( i < 2)
    {
        while(j < 3)
        {
            printf("%d\n", matrix[i][j]);
            j++;
        }
        j = 0;
        i++;
    }*/
    
    /*int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
    int i = 0;
    int j = 0;
    for (i; i < 2; i++) {
        for (j; j < 3; j++) {
            printf("%d\n", matrix[i][j]);
        }
        j = 0;
    }*/

    /*int x[3][4];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            x[i][j] = i + j;
            printf("%d\n", x[i][j]);
        }
        printf("\n");
    }
    
    return(0);
}*/
int main(void)
{
    int i = -1;
    while(++i < 10)
        printf("%d", i);
    
// an array with 3 rows and 2 columns.
    /*int x[3][2] = { { 0, 1 }, { 2, 3 }, { 4, 5 } };
 
    // output each array element's value
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Element at x[%i][%i]: ", i, j);
            printf("%d\n", x[i][j]);
        }
    }
*/
    return (0);
}