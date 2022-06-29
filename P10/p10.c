// Write a program to implement Diffie Hellman Key exchange.

#include <stdio.h>
#include <math.h>
long int power(long int a, long int b, long int P)
{
    if (b == 1)
        return a;
    else
    {
        double d = (((long int)pow(a, b)) % P);
        return d;
    }
}
int main()
{
    long int P, G, x, a, y, b, ka, kb;
    P = 23;
    printf("The value of P : %ld \n", P);
    G = 5;
    printf("The value of G : %ld \n\n", G);
    a = 4;
    printf("The private key a for Alice : %ld \n", a);
    x = power(G, a, P);
    b = 3;
    printf("The private key b for Bob : %ld \n\n", b);
    y = power(G, b, P);
    ka = power(y, a, P);
    kb = power(x, b, P);
    printf("Secret key for the Alice is : %ld \n", ka);
    printf("Secret Key for the Bob is : %ld \n", kb);
    return 0;
}