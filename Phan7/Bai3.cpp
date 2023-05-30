#include<iostream>
#include<stdio.h>
#include<conio.h>
int G[20][20],n,V_in[20],V_out[20];
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

void Vetexs(int G[20][20],int V_in[20],int V_out[20],int n){
int i,j;
printf("\nNua bac ra:\n");
for(int i=1;i<=n;i++){
	V_out[i]=0;
	for(int j=1;j<=n;j++)
		V_out[i]=V_out[i]+G[i][j];
	V_out[i]=V_out[i]+G[i][j];
	printf("deg_out(%d)=%d\t",i,V_out[i]);
}
printf("\nNua bac vao:\n");

	for(j=1;j<=n;j++){
		V_in[j]=0;
		for(i=1;i<=n;i++){
			V_in[j]=V_in[j]+G[i][j];
			
		}
		V_in[j]+=G[j][j];
		printf("deg(%d)=%d\t",j,V_in[j]);
	}
}
int main(int argc,char *argv[]){
	int i;
	if(!Init_Graph("Graph3.INP")) View_Graph(G,n);
	printf("Bac dinh:\n");
	Vetexs(G,V_in,V_out,n);
	getch();
	return 0;
}


