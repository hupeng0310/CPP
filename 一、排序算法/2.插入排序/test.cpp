#include <iostream>
using namespace std;

void BubbleSort(int *a,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		} 
	}	
} 

int main()
{
	int n=0,a[100],i,data;
	//���� 
	cout<<"���������������:(��-1��β)"<<endl;
	while(cin>>data&&data!=-1){
		a[n++]=data; 
	}
	//���� 
	BubbleSort(a,n);
	//��� 
	cout<<"��������"<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0; 
} 
