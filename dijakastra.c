#include<stdio.h>
#define INF 9999
///works perfectly @shoaib
/**ALGORITHM
     MAKE AN ARRY AND SOME VARIBALES WHICH WILL BE USED
     1. TAKE INPUT FOR GRAPH AND THEN TAKE INPUT FOR STARTNODE
     2. FUN() COPY DATA INTO SOME ANOTHER ARRY AND REPLACE 0 WITH INF AND REST WOULD BE SAME
     3. IJINITIALIZE VISTIED ARRAY WITH ZERO (0) AND PAR[I] WITH STARTNODE AND DIST[I]WITH  ARR[STNODE][I]
     4. PUSH INTO DIST[STARTNNODE]=0 COZ, SELF DISTANCE IS ZERO
     5. PUSH INTO VISITED[STARTNODE]=1  COZ FIRST NODE AND INITIALIZE COUNT=1
     6. LOOP  COUNT<N-1 REPEAT 8 9 10 11
     7  INITIALIZE MINDISTNACE=INF
     8. LOOP I<N
     9. IF DISTANCE [I] < MINDISTANCE AND !VISITED[I]
              MINDISTANC=DISTANCE[I]
              NEXTNODE=I
     10. VISITED OF[NEXTNODE]=1;
     11. LOOP I<N
              IF(!VISITED[I])
                 MINDISTANCE+GRAPH[NEXTNODE][I]<DIST[I]
                 DIST[I]=MINDISTANCE+GRAPH[NEXTNODE][I]
                 PAR[I]=NEXTNODE
     COUN++;
                 */
int main()
{
    int graph[10][10],n,startnode,i;
    printf("Enter the number of node\n");
    scanf("%d",&n);
    printf("Enter the data into matrix form \n");
    for(i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        scanf("%d",&graph[i][j]);
    }
    printf("Enter the starting node\n");
    scanf("%d",&startnode);
    dijkstras(graph,startnode,n);

    return 0;
}
void dijkstras(int graph[][10],int startnode,int n)
{
    int cost[10][10],i,visited[10],dist[10],nextnode,minDist,parent[10],count,j;
    for(i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
       if(graph[i][j]==0)
           cost[i][j]=INF;
       else
        cost[i][j]=graph[i][j];
    }
    for(i=0;i<n;i++)
    {
        dist[i]=cost[startnode][i];
        visited[i]=0;
        parent[i]=startnode;
    }
    dist[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1)
    {
        minDist=INF;
        for(i=0;i<n;i++)
        {
            if(!visited[i]&&dist[i]<minDist)
            {
                 minDist=dist[i];
                 nextnode=i;
            }


        }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(cost[nextnode][i]+minDist<dist[i])
                {
                    dist[i]=cost[nextnode][i]+minDist;
                    parent[i]=nextnode;
                }
            }
        }
        count++;
    }
   for(i=0;i<n;i++)
   {

       	if(i!=startnode)
		{
			printf("\nDistance of node%d=%d",i,dist[i]);
			printf("\nPath=%d",i);

			j=i;
			do
			{
				j=parent[j];
				printf("<-%d",j);
			}while(j!=startnode);
	}
   }

}
