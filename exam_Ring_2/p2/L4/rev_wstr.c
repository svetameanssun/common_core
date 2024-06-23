# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int is_printable(int c)
{
    return(c >= 33 && c <= 126);
}

int ft_strlen(char * str)
{
    int count = 0;
    while(str[count])
        count++;
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

void rev_wstr(char * str)
{
    int wrd_cnt = word_count(str);
    int str_len = ft_strlen(str);


    int i = str_len - 1;
    int save = 0;

    while(wrd_cnt > 0)
    {
        if(wrd_cnt == 1)
        {
            i = 0;
            while(is_printable(str[i]) && str[i] != '\0')
            {
       
                write(1, &str[i], 1);
                i++;
            }
            wrd_cnt--;
            break;
        }
        while(str[i] == ' ')
            i--;
        while(is_printable(str[i]))
        {
            i--;
        }
        save = i;
        i++;
        while(is_printable(str[i]) && str[i] != '\0')
        {
            write(1, &str[i], 1);
            i++;
        }
        i = save;
        write(1, " ", 1);
        i--;
        wrd_cnt--;
    }
}


int main(int argc, char ** argv)
{
    if (argc == 2)
        rev_wstr(argv[1]);
    write(1, "\n",1);
    return(0);
}
