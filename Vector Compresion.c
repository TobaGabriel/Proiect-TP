#include <stdio.h>
#include <stdlib.h>

int SetFlag(int n, int k)
{
    int mask = 1 << k;
    return n | mask;
}

int UnsetFlag(int n, int k)
{
    int mask = ~(1 << k);
    return n & mask;
}

int GetFlag(int n, int k)
{
    int mask = 1 << k;
    return ((n & mask) == mask);
}

int ChangeFlag(int n, int k)
{
    int mask = (1 << k);
    return n ^ mask;
}


int main()
{
    int v[32] = { 0 };//declar un vector cu toate elementele 0
    int j;//pozitia bitului
    int k;//verificare maska bit
    int i;//indexul vectorului
    int n = 1;//numarul care o sa fie introdus in vector

    for (i = 0; i < 1000; i++)//citirea
    {
        printf("v[%d]= ", i);//minciuni
        scanf("%d", &n);

        if (n >= 0 && n <= 1000)
        {
            j = n - (32 * (n / 32));//transformarea numarului in pozitie
            v[n / 32] = SetFlag(v[n / 32], j);
        }
        else
        {
            break;
        }
    }

    for (i = 0; i < 32; i++)//afisarea
    {
        for (j = 0; j <= 32; j++)
        {
            if (v[i] != 0)
            {
                k = GetFlag(v[i], j);

                if (k == 1)
                {
                    printf("%d ", (i * 32) + j);//transformarea pozitiei in numar
                }
            }
        }
    }

    return 0;
}