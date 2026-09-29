#include <stdio.h>

int main()
 {
    int data[7];
    int r1, r2, r4;

    printf("Enter 4 data bits (D3 D2 D1 D0): ");
    scanf("%d %d %d %d", &data[2], &data[4], &data[5], &data[6]);

    r1 = data[2] ^ data[4] ^ data[6];
    r2 = data[2] ^ data[5] ^ data[6];
    r4 = data[4] ^ data[5] ^ data[6];

    data[0] = r1;
    data[1] = r2;
    data[3] = r4;

    printf("\nHamming Code (7,4): ");

    for (int i = 0; i < 7; i++)
	{
        printf("%d", data[i]);
    }

    printf("\n");

    printf("Positions:           ");
    for (int i = 1; i <= 7; i++) 
	{
        printf("%d", i);
    }

    printf("\n");

    return 0;
}
