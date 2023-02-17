#include "./../minitalk.h"
#include "./../serverfolder/server_utils.c"
int main(void)
{
    sigset_t a = 2224594928;
    sigset_t rev_a = 0;
    printf("a = %u\n",a);
    rev_a = reverse_nbr_bytes(a,4);
    printf("rev_a = %u\n\n",rev_a);
    write(1, &rev_a, 4);
    printf("\n\n");
    write(1, &a, 4);
    return (0);
}