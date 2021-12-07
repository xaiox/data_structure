#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 105

typedef struct node{
    char num[10];
    char name[20];
    int score;
    struct node *next;
}node, *stud;

int compare(stud a, stud b, int C){
    if(C==1){
        if(strcmp(a->num, b->num) < 0) return 1;
        else return 0;
    }
    else if(C==2){
        if(strcmp(a->name, b->name) < 0) return 1;
        else if(strcmp(a->name, b->name) == 0){
            if(strcmp(a->num, b->num) < 0) return 1;
            else return 0;
        }
        else return 0;
    }
    else if(C==3){
        if(a->score - b->score >0) return 1;
        else if(a->score - b->score == 0){
            if(strcmp(a->num, b->num) < 0) return 1;
            else return 0;
        }
        else return 0;
    }
}

void Merge(stud SR[], stud TR[], int i, int m, int n, int C){
    int j, k, l;
    for(j=m+1, k=i; i<=m && j<=n; k++){
        if(compare(SR[i], SR[j], C)) TR[k] = SR[i++];
        else TR[k] = SR[j++];
    }
    if(i<=m)
        for(l=0; l<=n-k; l++) TR[k+l] = SR[i+l];
    if(j<=n)
        for(l=0; l<=n-k; l++) TR[k+l] = SR[j+l];
}

void Msort(stud SR[], stud TR1[], int s, int t, int C){
    if(s==t) TR1[s]=SR[s];
    else{
        int m = (s+t)/2;
        stud TR2[Max];
        Msort(SR, TR2, s, m, C);
        Msort(SR, TR2, m+1, t, C);
        Merge(TR2, TR1, s, m, t, C);
    }

}

int main(){
    int N, C;
    stud students[Max];
    stud sorted[Max];
    scanf("%d%d", &N, &C);
    int i;
    for(i=1; i<=N; i++){
        students[i]= (node *)malloc(sizeof(node));
        scanf("%s %s %d", students[i]->num, students[i]->name, &students[i]->score);
    }
    Msort(students, students, 1, N, C);
    printf("sort:\n");
    for(i=1; i<=N; i++){
        printf("%s %s %d\n", students[i]->num, students[i]->name, students[i]->score);
    }

}
