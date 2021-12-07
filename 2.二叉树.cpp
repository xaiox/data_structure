#include <stdio.h>
#include <string.h>
#include <malloc.h>

int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

int length(int n,char* first, char* mid)
{
    int i, index, len1, len2;
    if(n==1) return 1;
    else if(n==0) return 0;
    for(i=0;i<n;i++)
        if(mid[i]==first[0]){
            index = i;
            break;
        }
    len1 = length(index,first+sizeof(char),mid);
    len2 = length(n-index-1,first+(index+1)*sizeof(char),mid+(index+1)*sizeof(char));
    return max(len1,len2)+1;
}

int main()
{
    int i,n;
    char *first, *mid;
    scanf("%d",&n);
    first = (char*)malloc(sizeof(char)*(n+1));
    mid = (char*)malloc(sizeof(char)*(n+1));
    scanf("%s",first);
    scanf("%s",mid);

    printf("high:%d\n",length(n,first,mid));
    free(first);
    free(mid);
    return 0;
}
