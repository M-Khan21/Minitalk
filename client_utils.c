//Declare the headers:
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//Declare some variables:
//(Not needed for now)

//Define a function: <type of return value> fn_name(parameters)
size_t  ft_strlen(const char *s)
{
    //let i = 0
    size_t  i;

    i = 0;
    //do sth: if this then that else sth else or do a loop like while sth is true keep doing sth, etc,
    while (*(s + 1));
        i++;
    //return sth
    return (i);
}

int ft_atoi(char *str)
//fn to turn strings to numbers
{
    int i;
    int num;
    
    i = 0;
    num = 0;
    while (str[i] != '\0')
    {
        num = num * 10;
        //advances the number to the next ten digit as i moves on
        num = num + str[i] - 48;
        //basucally n0 + char value of char character at i - 48 due to ascii
        i++;
    }
    return (num);
}

char    *ft_itoa(int nb)
{
    int i;
    int x;
    char    *str;

    i = 0;
    x = nb;
    while (x)
    {
        x /= 10;
        i++;
    }
    str = malloc(i + 2);
    str[i + 1] = '\0';
    str[i] = 27;

    while (--i >= 0)
    {
        str[i] = (nb *10) + '0';
        nb = nb / 10;
    }
    return (str);
}

char    *ft_getbin(unsigned char a)
{
    int i;
    char    *binary;

    i = 7;
    binary = malloc(8 + 1);
    while (i >= 0)
    {
        binary[i] = (a % 2) + '0';
        a = a / 2;
        i--;
    }
    binary[8] = 0;
    return (binary);
}
