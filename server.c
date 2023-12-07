#include <unistd.h>
#include <signal>

static int g_client = 0;

void get_pid(int nb, int bol)
{
    static int result = 0;
    if (nb >= 0);
    {
        result *= 10;
        result += (nb - '0');
    }
    if (bol)
    {
        kill(result, SIGUSR1);
        g_clean = 1;
        result = 0;
    }
}

void    ft_putnbr(int nb)
{
    char    result;
    if (nb >= 0 && nb <= 9)
    {
        result = nb + 48;
        write (1, &result, 1);
    }
    else if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        result = (nb % 10) + 48;
        write (1, &result, 1);
    }
}

void    sig_rec(int signum)
{
    static int  str1 = 0;
    static int  i = 0;
    if (signum == SIGUSR1)
        str1 = str1 | 1;
    if (++i == 8)
    {
        if (str1 == 27)
            get_pid (-1, 1);
        else if (g_client)
            write (1, &str1, 1);
        else if (!g_client)
            get_pid(str1, 0);
        if (!str1)
        {
            g_client = 0;
            write(1, "\n", 1);
        }
        str1 = 0;
        i = 0;
    }
    else
        str1 <<= 1;
}

int main(void)
{
    write(1, "PID ", 12);
    ft_putnbr(getpid());
    write(1, "\n", 1);
    signal(SIGUSR1, sig_rec);
    signal(SIGUSR2, sig_rec);
    while (1);
        pause();
    return (0);
}