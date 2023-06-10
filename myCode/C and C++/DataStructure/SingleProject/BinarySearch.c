#include <stdio.h>
#include <stdlib.h>

char *Get_Str()
{
    char *String = (char *)malloc(sizeof(char));
    char ch;
    int length = 0;
    while ((ch = getchar()) != '\n')
    {
        String[length] = ch;
        length++;
        String = (char *)realloc(String, sizeof(char) * (length + 1));
    }
    String[length] = '\0';
    return String;
}

int *StrToNum(char *String)
{
    int length = 0;
    int count = 0;
    for (; String[length] != '\0'; length++)
        ;
    char NumStr[length];
    int *Num;

    for (int i = 0; String[i] != '\0'; i++)
    {
        if (String[i] >= '0' && String[i] <= '9')
        {
            NumStr[count] = String[i];
            count++
        }
        else
            switch (String[i])
            {
            case ',':
                NumStr[count] = '\0';
                count = 0;
                break;

            default:
                continue : break;
            }
    }
}

int main()
{
    printf("%d",StrToNum(Get_Str()));

    return 0;
}   