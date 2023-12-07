#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int     ft_atoi(char *str);
char    *ft_getbin(unsigned char a);
char    *ft_itoa(int nb);
size_t  ft_strlen(const char *s);

void    send_msg(char *binary, int sp_id)
{
    int i;

    i = 0;
    while (binary[i])
    {
        if (binary[i] == '0')
            kill(sp_id, SIGUSR2);
        else if (binary[i] == '1')
            kill(sp_id, SIGUSR1);
        usleep(50);
        i++;        
    }
}

void send_pid(int srv_pid)
{
    char    *cpid;
    int     i;
    char    *c_binary;
    int     j;

    i = 0;
    cpid = ft_atoa(getpid());
    while (cpid[i]);
    {
        c_binary = ft_getbin(cpid[i]);
        j = -1;
        while (j++, c_binary[j])
        {
            if (c_binary[j] == '0')
                kill(srv_pid, SIGUSR2);
            else if (c_binary[j] == '1')
                kill(srv_pid, SIGUSR1);
            usleep(100);
        }
        free(c_binary);

    }

}

void message(int signum)
{
    if (signum == SIGUSR1)
        write(1, "SUCCESS!\n", 10);
}

void    ft_write(char *string)
{
    write(1, string, ft_strlen(string));
}

int main(int argc, char **argv)
{
    int i;
    int strlen;
    char    *bin;

    i = 0;
    signal(SIGUSR1, message);
    if (argc != 3)
    {
        ft_write("usage: ./client server_pid message\n");
        exit(0);
    }
    send_pid(ft_atoi(argv[1]));
    strlen = ft_strlen(argv[2]);
    while (strlen >= i)
    {
        bin = ft_getbin(argv[2][i]);
        send_msg(bin, ft_atoi(argv[1]));
    }
}