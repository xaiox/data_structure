#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 105

typedef struct stu
{
    char num[10];
    char name[10];
    int score;
}stu;

int cmp(stu stud[MAX],int i,int j,int mode,int index[MAX])
{
    int ans;
    if(mode == 1) return strcmp(stud[i].num,stud[j].num);
    else if(mode == 2){
        ans = strcmp(stud[i].name,stud[j].name);
        if(ans!=0) return ans;
        return strcmp(stud[i].num,stud[j].num);
    }
    else{
        if(stud[i].score > stud[j].score)
            return 1;
        else if(stud[i].score < stud[j].score)
            return -1;
        return strcmp(stud[i].num,stud[j].num);
    }
}

void QuickSort(stu stud[MAX], int low, int high,int mode,int index[MAX])
{
    int temp, i, j;
    i = low; j = high;
    while(i<j){
        //printf("%d",cmp(stud,index[low],index[high],mode,index));
        while(i<j && cmp(stud,index[i],index[j],mode,index)<0) --j;
        temp=index[i];index[i]=index[j];index[j]=temp;
        while(i<j && cmp(stud,index[i],index[j],mode,index)<0) ++i;
        temp=index[i];index[i]=index[j];index[j]=temp;
    }
    if(low <= i-2) QuickSort(stud,low,i-1,mode,index);
    if(high >= i+2) QuickSort(stud,i+1,high,mode,index);
}

int main()
{
    stu stud[MAX];
    int n, C, i;
    int index[MAX];
    for(i=0;i<MAX;i++) index[i]=i;
    scanf("%d%d",&n, &C);
    for(i=0;i<n;i++)
        scanf("%s %s %d", stud[i].num, stud[i].name, &stud[i].score);
    QuickSort(stud,0,n-1,C,index);
    printf("sort:\n");
    for(i=0;i<n;i++){
        printf("%s %s %d\n", stud[index[i]].num, stud[index[i]].name, stud[index[i]].score);
    }
    return 0;
}
