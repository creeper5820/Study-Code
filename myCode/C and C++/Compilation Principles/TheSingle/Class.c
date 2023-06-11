#include <stdio.h>
#include <string.h>

char prog[180], token[20]; // prog 输入的字符长度，token单个词长度
char ch;
int syn, p, m, n, sum;
char *rwtab[23] = {"program", "var", "integer", "bool", "real", "char", "const", "begin", "if", "then",
                   "else", "while", "do", "for", "to", "end", "read", "write", "true", "false", "not", "and", "or"}; // 关键字
main()
{
    p = 0;
    printf("\nplease intput string:");
    do
    {
        ch = getchar();
        prog[p++] = ch;
    } while (ch != '#');
    p = 0;
    do
    {
        scaner();
        switch (syn)
        {
        case 11:
            printf("(%d,%d)", syn, sum);
            break;
        case -1:
            printf("input error\n");
            break;
        default:
            printf("(%d,%s)", syn, token);
        }
    } while (syn != 0);
    getch();
}

/*词法扫描程序：*/
scaner()
{
    for (n = 0; n < 20; n++)
        token[n] = NULL;
    m = 0;
    ch = prog[p++];
    while (ch == ' ')
        ch = prog[p++];
    if ((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A'))
    {
        while ((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A') || (ch <= '9' && ch >= '0'))
        {
            token[m++] = ch;
            ch = prog[p++];
        }
        token[m++] = '\0';
        ch = prog[--p];
        syn = 24;
        for (n = 0; n < 23; n++)
            if (strcmp(token, rwtab[n]) == 0)
            {
                syn = n + 1;
                break;
            }
    }
    else if ((ch <= '9' && ch >= '0'))
    {
        sum = 0;
        while ((ch <= '9' && ch >= '0'))
        {
            sum = sum * 10 + ch - '0';
            ch = prog[p++];
        }
        ch = prog[--p];
        syn = 25;
    }
    else
        switch (ch)
        {
        case '<':
            m = 0;
            token[m++] = ch;
            ch = prog[p++];
            if (ch == '>')
            {
                syn = 37;
                token[m++] = ch;
            }
            else if (ch == '=')
            {
                syn = 34;
                token[m++] = ch;
            }
            else
            {
                syn = 32;
                ch = prog[--p];
            }
            break;
        case '>':
            token[m++] = ch;
            ch = prog[p++];
            if (ch == '=')
            {
                syn = 35;
                token[m++] = ch;
            }
            else
            {
                syn = 33;
                ch = prog[--p];
            }
            break;
        case ':':
            token[m++] = ch;
            ch = prog[p++];
            if (ch == '=')
            {
                syn = 31;
                token[m++] = ch;
            }
            else
            {
                syn = 30;
                ch = prog[--p];
            }
            break;

        case '+':
            token[m++] = ch;
            ch = prog[p++];
            if (ch == '+')
            {
                syn = 54;
            }
            else
            {
                syn = 26;
                ch = prog[--p];
            }
            break;
        case '-':
            token[m++] = ch;
            ch = prog[p++];
            if (ch == '-')
            {
                syn = 55;
            }
            else
            {
                syn = 27;
                ch = prog[--p];
            }
            break;

        case '/':
            token[m++] = ch;
            ch = prog[p++];
            if (ch == '*')
            {
                syn = 44;
            }
            else
            {
                syn = 29;
                ch = prog[--p];
            }
            break;
        case '*':
            token[m++] = ch;
            ch = prog[p++];
            if (ch == '/')
            {
                syn = 28;
            }
            else
            {
                syn = 45;
                ch = prog[--p];
            }
            break;
        case ';':
            syn = 39;
            token[0] = ch;
            break;
        case '(':
            syn = 42;
            token[0] = ch;
            break;
        case ')':
            syn = 43;
            token[0] = ch;
            break;
        case '&':
            token[m++] = ch;
            ch = prog[p++];
            if (ch == '=')
            {
                syn = 57;
            }
            else
            {
                syn = 46;
                ch = prog[--p];
            }

            break;
        case '=':
            token[m++] = ch;
            ch = prog[p++];
            if (ch == '=')
            {
                syn = 36;
            }
            else
            {
                syn = 38;
                ch = prog[--p];
            }
            break;
        case ',':
            syn = 40;
            token[0] = ch;
            break;
        case '`':
            syn = 41;
            token[0] = ch;
            break;
        case '%':
            syn = 47;
            token[0] = ch;
            break;
        case '，':
            syn = 48;
            token[0] = ch;
            break;
        case '!':
            token[m++] = ch;
            ch = prog[p++];
            if (ch == '=')
            {
                syn = 56;
            }
            else
            {
                syn = 49;
                ch = prog[--p];
            }
            break;

        case '[':
            syn = 52;
            token[0] = ch;
            break;
        case ']':
            syn = 53;
            token[0] = ch;
            break;
        case '{':
            syn = 50;
            token[0] = ch;
            break;
        case '}':
            syn = 51;
            token[0] = ch;
            break;
        case '#':
            syn = 0;
            token[0] = ch;
            break;
        default:
            syn = -1;
        }
}