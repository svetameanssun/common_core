#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;
    char * res;
    while(s1[i])
    {
        j = 0;
        while(s2[j])
        {
            if(s1[i] == s2[j])
            {
                res = (char*)s1 + i;
                return(res);
            }
            j++;
        }
        i++;
    }
    return(0);

}

int main(int argc, char**argv)
{
    char * str = ft_strpbrk(argv[1], argv[2]);
    char * str1 = strpbrk(argv[1], argv[2]);
    if(str == NULL)
        printf("str == NULL\n");
    if(str1 == NULL)
        printf("str1 == NULL\n");
    int i = 0;
    while(str[i])
    {
        printf("%c", str[i]);
        i++;
    }
    i = 0;
    printf("\n");
    while(str1[i])
    {
        printf("%c", str1[i]);
        i++;
    }
}