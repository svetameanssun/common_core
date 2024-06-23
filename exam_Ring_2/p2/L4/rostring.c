#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int is_printable(int c)
{
    return(c >= 33 && c <= 126);
}

int ft_strlen(char *str)
{
    int count = 0;
    while(str[count])
    {
        count++;
    }
    return(count);
}
int ft_word_len(char *str)
{
    int count = 0;
    int i = 0;
    while(str[i] != '\0' && str[i] != ' ')
    {
        i++;
        count++;
    }
    return(count);
}

int word_count(char *str)
{
    int i = 0;
    int j = 1;
    int count = 0;

    while(str[i])
    {
        if(is_printable(str[i]) && (str[j] == ' ' || str[j] == '\0'))
        {
            count++;
        }
        i++;
        j++;
    }
    return(count);
}

void rostring(char *str)
{
    int i = 0;

    while(*str == ' ')
        str++;

    //printf("-%s-\n", str);

    int wrd = word_count(str);
    //printf("words in str: %d\n", wrd);
    int first_wrd_len = ft_word_len(str);
   //printf("first word length: %d\n", first_wrd_len);
    int len = ft_strlen(str);
    //printf("Full str length: %d\n", len);
    int *first_word;
    first_word = malloc(sizeof(char) * (first_wrd_len + 1));
    
    while(i < first_wrd_len)
    {
        first_word[i] = str[i];
        //printf("-%c\n", first_word[i]);
        i++;
    }

    str = str + first_wrd_len;
    //printf("-%s-\n", str);
    i  = 0;
    int j = 0;
    
    while(wrd > 0)
    {
        while(str[i]== ' ')
            i++;
        if(wrd == 1)
        {
            while(is_printable(first_word[j]) && first_word[j] != '\0')
            {
                write(1, &first_word[j], 1);
                j++;
            }
        }
        else
        {
            while(is_printable(str[i]) && str[i] != '\0')
            {
                write(1, &str[i], 1);
                i++;
            }
            write(1," ", 1);
        }
        wrd--;
    }
    write(1, "\n", 1);
    

}

int main(int argc, char ** argv)
{
    if (argc >= 2)
        rostring(argv[1]);
    else
    {
        write(1, "\n", 1);
    }

}
