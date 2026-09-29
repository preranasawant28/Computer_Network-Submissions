#include <stdio.h>

int main()
{
    int data[7];
    int p1, p2, p4;
    int error;

    printf("Enter 7-bit Hamming code: ");

    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &data[i]);
    }

    p1 = data[0] ^ data[2] ^ data[4] ^ data[6];
    p2 = data[1] ^ data[2] ^ data[5] ^ data[6];
    p4 = data[3] ^ data[4] ^ data[5] ^ data[6];

    error = p4 * 4 + p2 * 2 + p1;

    if (error == 0)
    {
        printf("\nNo error detected.");
    }
    else
    {
        printf("\nError detected at position: %d", error);
        
        data[error - 1] = data[error - 1] ^ 1;

        printf("\nCorrected Hamming Code: ");

        for (int i = 0; i < 7; i++)
        {
            printf("%d", data[i]);
        }
    }

    printf("\nOriginal Data: %d%d%d%d\n",
           data[2], data[4], data[5], data[6]);

    return 0;
}
