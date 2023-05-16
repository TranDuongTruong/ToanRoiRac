#include<iostream>
#include<stdio.h>
#define Max 50

int A[Max],n,B[Max],m,C[Max],k;
int Init(int M[], int &k, char*path){
	FILE *fptr;
	if(!(fptr=fopen(path,"r"))){
		system("Error");
		return 0;
	}
	k=0;
	while(!feof(fptr)){
		fscanf(fptr,"%d", &M[k]);
		k++;
		
	}
	fclose(fptr);
	return 1;
}

void Delete(int M[], int&n){
	int i,j,k;
	for( i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(M[i]==M[j]){
				for(k=j;k<n-1;k++)M[k]=M[k+1];
				n=n-1;
				j=j-1;
			}
		}
	}
}
void Print(int M[],int n){
	for(int i=0;i<n;i++)
		printf("%3d",M[i]);
	printf("\n");
}

void intersection(int A[],int n, int B[], int m, int C[], int &k){
	int i,j;
	k=0;i=0;
	while(i<n){
		for(j=0;j<m;j++){
			if(B[j]==A[j]){
				C[k]=A[i];
				k++;
			}
		}
		i++;
	}	
}
int main(int argc,char ** argv){
	if(Init(A,n,(char*)"Set_A.INP")==0&&Init(B,m,(char*)"Set_B.INP")==0 ){
		printf("A:\t");Print(A,n);
		printf("B:\t");Print(B,m);
		Delete(A,n);Delete(B,m);
		intersection(A,n,B,m,C,k);
		printf("C:\t");Print(C,k);
	}
}