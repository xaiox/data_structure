#include <stdio.h>
#include <malloc.h>

typedef struct LNode
{
    int zhishu;
    int xishu;
    struct LNode *next;
}LNode, *LinkList;

void CreatList(LinkList &L)
{
    int n, x;
    LinkList H;
    H = L;
    while(scanf("%d %d",&x,&n)!=EOF)
    {
        LinkList p;
        p = (LinkList)malloc(sizeof(LNode));
        p->xishu = x;
        p->zhishu = n;
        p->next = H->next;
        H->next = p;
        H = p;
        if(getchar()=='\n') break;
    }

}

void D(LinkList &L)
{
    LinkList p;
    p = L->next;
    while(p!=NULL)
    {
        p->xishu = (p->xishu) * (p->zhishu);
        p->zhishu -= 1;
        p = p->next;
    }
}

void Output(LinkList L)
{
    LinkList p;
    p = L->next;
    while(p!=NULL && p->zhishu>=0)
    {
        printf("%d %d ",p->xishu,p->zhishu);
        p = p->next;
    }
    if(p == L->next) printf("0 0");
}

void ListDelete(LinkList &L)
{
    while(L->next!=NULL)
    {
        LinkList p;
        p = L->next;
        L->next = L->next->next;
        free(p);
    }
    free(L);
}

int main()
{
    LinkList L;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    printf("input:");
    CreatList(L);
    D(L);
    Output(L);

    ListDelete(L);
    return 0;
}
