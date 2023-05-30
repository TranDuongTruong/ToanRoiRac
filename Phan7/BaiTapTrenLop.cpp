#include<iostream>
#include<stdio.h>
#include<conio.h>
int G[20][20],n,C[20];
FILE *fptr;


int Init_Graph(char *path){
	int i,j;
	fptr=fopen(path,"r");
	if(fptr==NULL){
		system("Error");
		return 1;
	}
	fscanf(fptr,"%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			G[i][j]=0;
	while(!feof(fptr)){
		fscanf(fptr,"%d",&i);fscanf(fptr,"%d",&j);
		fscanf(fptr,"%d",&G[i][j]);
	}
	fclose(fptr);
	return 0;
}
void BFS(int u){
	int Q[20], first=1,last=1;
	Q[last]=u, C[u]=1;
	while(first<=last){
		int u=Q[first],
		first+=1;
		printf("%d\t",u);
		for(int v=1;v<=n;v++){
			if(G[u][v]!=0&&C[v]==0){
				last+=1;
				Q[last]=v;
				C[v]=1;
			}
		}
	}
}
int main(int argc,char *argv[]){

Init_Graph("Graph3.INP");
	
	i=1;
	BFS(i);
	getch();
	return 0;
}

