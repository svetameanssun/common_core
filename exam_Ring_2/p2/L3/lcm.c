# include <stdio.h>
# include <unistd.h>


unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int res;
    if(a == 0 || b == 0)
        return(0);
    if(a > b)
        res = b;
    if(a < b)
        res = a;
    while(1)
    {
        if(res%a == 0 && res%b == 0)
            return(res);
        res++;
    }
    return(res);
    
    
}


int main()
{
    printf("%d\n",lcm(7, 7));
}