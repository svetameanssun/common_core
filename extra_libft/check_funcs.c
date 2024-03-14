#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <memory.h>


void *ft_memmove(void *dst, const void *src, size_t n)
{
    size_t i;
    char *dest;
    char *source;
    
    dest = (char *)dst;
    source = (char *)src;

    
    //if (dst == 0 && src == 0)
    //   return(dst);
    if (n == 0)
        return (dst);

    if (src < dst)
    {
        i = n - 1;
        while (i >= 0)
        {
            *(dest + i) = *(source + i);
            i--;
        }
    }
    else if (src >= dst)
    {   i = 0;
        while (i < n)
        {
            *(dest + i) = *(source + i);
            i++;
        }
    } 
    return (dst);
}




int main( void )
{
    char str1[7] = "abcdef";
    char str2[7] = "abcdef";

    printf( "The string: %s\n", str1 );
    memmove( str1 + 2, str1, 4 );
    printf( "New string: %s\n", str1 );

    printf( "The string2: %s\n", str2 );
    ft_memmove( str2 + 2, str2, 4 );
    printf( "New string2: %s\n", str2 );
    printf( "length str2: %p\n", str2);
    printf( "length str2 + 2: %p\n", str2 + 2);
}

/*int	ft_strlen(const char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0' || s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t little_len;
    size_t big_len;

	little_len = ((size_t)ft_strlen((char*)little));
    big_len = ((size_t)ft_strlen((char*)big));
	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while (i + little_len <= len && i < big_len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

int main(void)
{
    const char * str = "teste";
    printf("%s\n",ft_strnstr(((void *)0), "fake", 2));
    //printf("%s\n",strnstr(((void *)0), "fake", 2));
}
*/



/*char	*ft_strrchr(const char *s, int c)
{
	unsigned int i;
	char * aux;
	
	i = 0;
	aux = NULL;

	while(s[i] != '\0')
	{
		if(s[i] == (char)c)
			aux = (char *)s + i;
		i++;
	}
    //printf("%d", i);
	if (c == '\0')
		aux = (char *)s + i;
        //printf("%s", aux);
	return (aux);
}

int main(void)
{
    const char * str = "teste";
    printf("%s\n",ft_strrchr(str, '\0'));
    printf("%s",strrchr(str, '\0'));
}*/


/*int	ft_strlen(const char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}*/



/*int	ft_strlen(char *str)
{
    int count;

    count = 0;
    while (str[count] != '\0')
        count++;
    return (count);
}
*/

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

/*int main(void)
{
    char arr1[10] = "mandibula";
    char arr2[6] = "verde";

    printf("%s\n", memmove(arr2, arr1, 1));
    // printf("%s\n", ft_memmove(arr1, arr2, 1));
    return 0;
}*/