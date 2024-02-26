#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_digit(int c)
{
    return(c >= '0' && c <= '9');
}

int ft_atoi(char *str)
{
    int res = 0;
    int sign = 1;

    
    if(*str == '-')
    {
        sign = sign * -1;
        str++;
    }

    while(*str && *str != ' ')
    {
        res = res * 10 + *str - 48;
        str++;
    }
    return (res * sign);
    
}
int numbers_unique(int * arr, int len)
{
    int i = 0;
    int j = 0;

    while(i < len)
    {
        int j = 0;
        while(j < len)
        {
            if(arr[i] == arr[j] && i != j)
            {
                return (0);
            }
            j++;
        }
        i++;
    }
    return(1);

}


int input_valid(char * str)
{
    int i = 0;
    int j = 0;
    if(str[0] == ' ')
        return(0);
    while(str[i])
    {
        if(is_digit(str[i]))
        {
            i++;
        }
        else
        {
            if (str[i] == '-' && is_digit(str[i + 1]) && (i == 0 || str[i - 1] == ' '))
            {
                i++;
            }
            else if(str[i] == ' ' && (is_digit(str[i + 1]) || str[i + 1] == '-') && is_digit(str[i - 1]))
            {
                i++;
            }
            else
                return(0);
        }
    }
    return(i);
}

int word_count(char *str)
{
    int word_cnt = 1;
    while(*str)
    {
        if(*str == ' ')
            word_cnt++;
        str++;
    }
    return(word_cnt);
}

int * str_to_numbers(char *str)
{
    //int flg = 0;
    int i = 0;
    int j = 0;

    if(!input_valid(str))
        return(0);
    int word_cnt = word_count(str); //4

    int * res = (int*)malloc(sizeof(int) * (word_cnt));
    if (res == 0)
        return(0);

    res[0] = ft_atoi(str + 0); // 12
    j++;//1
    while(j < word_cnt) // 1 < 4
    {
        while(str[i] && str[i] != ' ') // 1
        {
            i++;
        }
        i++;
        res[j] = ft_atoi(str + i);
        j++; // 2
    }
    if(!numbers_unique(res, word_cnt))
    {
        return(0);
    }
    return(res);
}
int united_str_size(int argc, char ** argv)
{
    int i = 1;
    int j = 0;
    int count = 0;

    while(i < argc)
    {
        j = 0;
        while(argv[i][j])
        {
            j++;
        }
        count = count + j;
        i++;
    }
    count = count + argc - 2;
    return(count);
}

char *words_to_str(int argc, char ** argv)
{
    int i;
    int j;
    int res_size;
    char *res;
    int k;

    i = 1;
    j = 0;
    k = 0;
    res_size = united_str_size(argc, argv);
    res = (char *)malloc(sizeof(char) * (res_size));
    while(i < argc)
    {
        k = 0;
        while(argv[i][k])
        {
            res[j++] = argv[i][k++];
        }
        res[j] = ' ';
        j++;
        i++;
    }
    res[j] = '\0';
    return(res);
    
}


int main(int argc, char ** argv)
{

    if(argc == 2)
    {
        if(!str_to_numbers(argv[1]))
        {
            printf("Error");
        }
        else
            
    }
    else if(argc > 2)
    {
        printf("%s", words_to_str(argc, argv));
    }    
}