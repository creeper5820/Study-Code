#include "list.h"

int main()
{
    bool InWord(char ch);
    void bubbleSort(List start);

    List list;
    ListInitiallize(&list);

    FILE *fp;
    fp = fopen("ncetextansi.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR!");
        exit(1);
    }

    /*
                char ch;
                while((ch=fgetc(fp))!= EOF )
              {
                      if(ch>='A'&&ch<='Z')
                      ch+=32;
                  AddNode_Specified(&list, &ch);
              }
    */

    char buf[50];
    while (fscanf(fp, "%s", buf) != EOF)
    {
        int i;
        for (i = 0; InWord(buf[i]); i++)
            ;
        buf[i] = '\0';
        for (int i = 0; buf[i] != '\0'; i++)
        {
            if (buf[i] >= 'A' && buf[i] <= 'Z')
                buf[i] += 32;
        }
        AddNode_Specified(&list, buf);
    }

    bubbleSort(list);
    Node *pnode = list;
    for (int i = 0; pnode != NULL && i < 200; i++, pnode = pnode->next)
    {
        PrintNode(pnode);
    }
    fclose(fp);
    return 0;
}

bool InWord(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == 45 || ch == 39);
}

void bubbleSort(List start)
{
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->item.number < ptr1->next->item.number)
            {
                ExchangeNode(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}