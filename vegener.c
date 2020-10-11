#include <stdio.h>
#include <stdlib.h>

// in c, in pos, out shifted
char plusCorrection (char c, int pos)
{
    if(c >= '0' && c <= '9') return '#';

    char shifted = (c + pos);
    
    if (shifted > 'Z')
    {
        shifted = 'A' + (shifted - 'Z' - 1);
    }

    return shifted;
}

char minusCorrection (char c, int pos)
{
    if(c >= '0' && c <= '9') return '#';

    char shifted = (c - pos);

    if (shifted < 'A')
    {
        shifted = 'Z' - ('A' - shifted - 1);
    }

    return shifted;
}

int shiftSize(char c)
{
    int size = (c - 'A') + 1;
    return size;
}

int main(int argc, char **argv)
{
    printf("%d %d \n", shiftSize(argv[2][0]), argv[2][0]);
    
    for(int i = 0; argv[1][i] != '\0'; i++)
    {
        int pos;
                
        if(i % 2)
        {
            pos = shiftSize(argv[2][1]);
            printf("Char represented: %c %d\n", minusCorrection(argv[1][i], pos),pos);
        }
        else
        {
            pos = shiftSize(argv[2][0]);
            printf("Char represented: %c %d \n", plusCorrection(argv[1][i], pos), pos);    
        }
    }

    return 0;
}
