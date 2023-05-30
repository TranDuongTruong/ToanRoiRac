#include<iostream>
#include<stdio.h>
#include<conio.h>
int G[20][20],n,V[20];
FILE *fptr;
void View_Graph(int G[20][20],int n ){
	int i,j;
	printf("So dinh: %d\n",n);
	printf("Ma tran ke: \n\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d\t",G[i][j]);
		}
		printf("\n\n");
		
	}
	
}
void Vetexs(int G[20][20],int V[20],int n){
	int i,j;
	for(int i=1;i<=n;i++){
		V[i]=0;
		for(j=1;j<=n;j++) V[i]=V[i]+G[i][j];
		V[i]=V[i]+G[i][i];
		printf("deg(%d)=%d\t",i,V[i]);
	}
}

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
int main(int argc,char *argv[]){
	int i;
	if(!Init_Graph("Graph.INP")) View_Graph(G,n);
	printf("Bac dinh:\n");
	Vetexs(G,V,n);
	getch();
	return 0;
}
