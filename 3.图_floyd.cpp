# include <stdio.h>
# include <stdlib.h>


int main()
{
    int n, m, i, j, k;
    scanf("%d%d",&n, &m);
    int g[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i==j) g[i][j] = 0;
            else g[i][j] = 100;  //100表示无穷大
    for(k=0;k<m;k++){
        scanf("%d%d", &i, &j);
        g[i-1][j-1] = 1;
        g[j-1][i-1] = 1;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++){
                if(j==i || k==i)
                    continue;
                else{
                    if(g[j][i]+g[i][k]<g[j][k])
                        g[j][k] = g[j][i]+g[i][k];
                }
            }
    float people_count;
    for(i=0;i<n;i++){
        people_count = 0;
        for(j=0;j<n;j++)
            if(g[i][j]<=6)
                people_count++;
        printf("%d:%.2f%%\n",i+1, (people_count/n)*100);
    }
    return 0;
}
