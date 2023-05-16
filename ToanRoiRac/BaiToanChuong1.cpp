#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int n=10;
char A='A', B='B',C='C';

void chuyen(int n, char A, char B, char C){
	if(n>1){
		chuyen(n-1,A,C,B);
		chuyen(1,A,B,C);
		chuyen(n-1,B,A,C);
	}
	else{
		cout<<A<<"->"<<C<<endl;
	}
}
int main(int argc, char** argv){
	chuyen(30,A,B,C);
	return 0;
}