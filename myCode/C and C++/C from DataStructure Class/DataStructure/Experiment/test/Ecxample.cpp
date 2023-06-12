#include <stdio.h>
#include <string.h>

void get_next(char s[],int next[]);

int KMP(char s1[],char s2[],int next[]);

int main() {
	int i= 0;
	int next[1000];
	char s2[] = "abcac";
	char s1[] = "ababcabcacbab";
	get_next(s2,next);
    
	i=KMP(s1,s2,next);
    printf("%d\n",i);
    return 0;
}

void get_next(char s[],int next[])
{	
	int len=0;
    int i=0;
    int j=-1;
    next[0]=-1;
    len=strlen(s);
    while(i<len-1)
    {
        if(j==-1||s[i]==s[j])
        {
            i++;
            j++;
			next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}

int KMP(char s1[],char s2[],int next[])
{
    int i=0;
    int j=0;
    int len1=strlen(s1);
    int len2=strlen(s2);
    while(i<len1&&j<len2)
    {
        if(j==-1||s1[i]==s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j>=len2)
        return i-len2+1;
    else
        return -1;
}