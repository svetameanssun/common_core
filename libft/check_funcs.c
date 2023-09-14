#include <string.h>
#include <stdio.h>
int	ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}


/*void *ft_memmove(void *dest, const void *src, int n)
{
    int i = 0;
    char *temp_dest;
    const char *temp_src;
    temp_dest = dest;
    temp_src = src;
    char * temp;

    int len_dest = ft_strlen(dest);
    if (!dest && !src)
        return (dest);
    if (n == 0)
    {
        return (dest);
    }
    while (i < n)
    {
        while (i < len_dest)
        {
            temp[i] = temp_src[i];
            i++;
        }
        temp[i] = temp_dest[i];
        i++;
    }
    temp[i] = '\0';
    return (temp);
}
*/

int main(void)
{
    char arr1[10] = "mandibula";
    char arr2[6] = "verde";

     
    printf("%s\n", memmove(arr2, arr1, 1));
    //printf("%s\n", ft_memmove(arr1, arr2, 1));
    return 0;

}