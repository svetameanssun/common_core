
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
}*/
//Trying malloc
int main(void)
{
    char * str_mal;
    str_mal = malloc(sizeof(char)*5);

    char * str_cal;
    str_cal = calloc(sizeof(char),5);

    //printf("%p\n", str);
    //printf("%p", str1);

    /*Malloc elements*/
    printf("%c\n", str_mal[0]);
    printf("%c\n", str_mal[1]);
    printf("%c\n", str_mal[2]);
    printf("%c\n", str_mal[3]);
    printf("%c\n", str_mal[4]);

    /*Directions of malloc element*/
    printf("%p\n",&str_mal[0]);
    printf("%p\n",&str_mal[1]);
    printf("%p\n",&str_mal[2]);
    printf("%p\n",&str_mal[3]);
    printf("%p\n",&str_mal[4]);


    /*Calloc elements*/
    printf("%c\n", str_cal[0]);
    printf("%c\n", str_cal[1]);
    printf("%c\n", str_cal[2]);
    printf("%c\n", str_cal[3]);
    printf("%c\n", str_cal[4]);

    /*Directions of calloc element*/
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
    
    return(0);
}