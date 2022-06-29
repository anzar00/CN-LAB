//  Write a program to implement Go-Back N and Selective repeat sliding window protocol.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, r;
struct frame
{
    char ack;
    int data;
} frm[10];
int sender(void);
void recvfrm(void);
void resend_sr(void);
void resend_gb(void);
void goback(void);
void selective(void);
int main()
{
    int c;
    do
    {
        printf("\n\n1.Selective repeat ARQ\n2.Goback ARQ\n3.exit");
        printf("\nEnter choice:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            selective();
            break;
        case 2:
            goback();
            break;
        case 3:
            exit(0);
            break;
        }
    } while (c < 3);
}
void goback()
{
    sender();
    recvfrm();
    resend_gb();
    printf("\n All packets sent successfully\n");
}
void selective()
{
    sender();
    recvfrm();
    resend_sr();
    printf("\nAll packets sent successfully");
}
int sender()
{
    int i;
    printf("\nEnter the no. of packets to be sent:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\nEnter data for packets[%d]", i);
        scanf("%d", &frm[i].data);
        frm[i].ack = 'y';
    }
    return 0;
}
void recvfrm()
{
    int i;
    rand();
    r = rand() % n;
    frm[r].ack = 'n';
    for (i = 1; i <= n; i++)
    {
        if (frm[i].ack == 'n')
            printf("\nThe packet number %d is not received\n", r);
    }
}
void resend_sr()
{
    printf("\nResending packet %d", r);
    sleep(2);
    frm[r].ack = 'y';
    printf("\nThe received packet is %d", frm[r].data);
}
void resend_gb()
{
    int i;
    printf("\n Resending from packet %d", r);
    for (i = r; i <= n; i++)
    {
        sleep(2);
        frm[i].ack = 'y';
        printf("\nReceived data of packet %d is %d", i, frm[i].data);
    }
}
