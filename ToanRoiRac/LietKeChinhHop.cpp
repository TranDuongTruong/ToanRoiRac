#include<stdio.h>
#include<math.h>
int B[20],k=4;
void Print(int k){
	for(int i=1;i<=k;i++){
		printf("%d\t",B[i]);
	}
	printf("\n");
}
void XauNP(int k){
	for(int i=1;i<=k;i++){
		B[i]=0;
		//Print(k);
		
	}
	Print(k);
	for(int c=1;c<pow(2,k);c++){
		int i=k;
			while(B[i]==n)i-=1;
		B[i]+=1;
		for(int j=i+1;j<=k;j++)B[j]=0;
		Print(k);
	}
}


int main(){
	XauNP(k);
}
