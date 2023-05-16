#include<stdio.h>
#include<math.h>
int B[20],k=3,  n=5;
void Print(int k){
	int i;
	for( i=1;i<=k;i++){
		printf("%d\t",B[i]);
	}
	printf("\n%");
}

void XauNP(int k){
	for(int i=1;i<=k;i++){
		B[i]=1;
		//Print(k);
		
	}
	Print(k);
	for(int c=1;c<pow(n,k);c++){
		int i=k;
		while(B[i]==n)i-=1;
		B[i]+=1;
		for(int j=i+1;j<=k;j++)B[j]=1;
		Print(k);
	}
}


int main(){
	XauNP(k);
}
