# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# define MAX_VERTEX_NUM 104
# define MAXQSIZE 104

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode,*Node;

typedef struct VNode
{
    ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;

typedef struct
{
    int Q[MAXQSIZE];
    int front=0;
    int rear = 0;
}Queue;

//队列的方法
void append(Queue & q, int num)
{
    q.Q[q.rear] = num;
    q.rear++;
}

int pop(Queue & q)
{
    int item;
    item = q.Q[q.front];
    q.front++;

    return item;
}

//广度优先搜索
void bfs(int num, ALGraph G)
{
    Queue q;
    Node p;
    int juli[2][G.vexnum];
    for(int i=0;i<2;i++)
        for(int j=0;j<G.vexnum;j++)
            juli[i][j] = 0;
    int node;
    append(q, num);
    juli[0][num] = 1;
    juli[1][num] = 0;
    while(q.front != q.rear){
        node = pop(q);
        p = G.vertices[node].firstarc;
        while(p){
            if(juli[0][p->adjvex]!=1){
                append(q,p->adjvex);
                juli[0][p->adjvex] = 1;
                juli[1][p->adjvex] = juli[1][node]+1;
            }
            p = p->nextarc;
        }
    }
    float count=0;
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(juli[0][i]==1 && juli[1][i]<=6)
            count++;
    }
    printf("%d:%.2f%%\n",num+1,(count/G.vexnum)*100);
;
}

void destroy(ALGraph & G)
{
    Node p;
    int i;
    for(i=0;i<MAX_VERTEX_NUM;i++)
    {
        p = G.vertices[i].firstarc;
        while(p){
            G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
            free(p);
            p = G.vertices[i].firstarc;
        }
    }
}

int main()
{
    ALGraph G;
    int i, num1, num2;
    //对图进行初始化
    for(i=0;i<MAX_VERTEX_NUM;i++)
        G.vertices[i].firstarc = NULL;
    scanf("%d %d",&(G.vexnum),&(G.arcnum));
    Node p;
    //输入边
    for(i=0;i<G.arcnum;i++){
        p = (Node)malloc(sizeof(Node));
        p->nextarc = NULL;
        scanf("%d%d",&num1,&num2);
        p->adjvex = num2-1;
        p->nextarc = G.vertices[num1-1].firstarc;
        G.vertices[num1-1].firstarc = p;
        p = (Node)malloc(sizeof(Node));
        p->adjvex = num1-1;
        p->nextarc = G.vertices[num2-1].firstarc;
        G.vertices[num2-1].firstarc = p;
    }

    for(i=0;i<G.vexnum;i++)
    {
        //printf("bfs:%d\n\n",i);
        bfs(i,G);
    }
    destroy(G);
    return 0;
}
