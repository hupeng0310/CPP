/*
��һ�ˣ���n����¼���ҳ��ؼ�����С�ļ�¼���һ����¼������
�ڶ��ˣ��ӵڶ�����¼��ʼ��n-1 ����¼����ѡ���ؼ�����С�ļ�¼��ڶ�����¼������
�Դ�����.....
��i �ˣ���ӵ�i ����¼��ʼ��n-i+1 ����¼��ѡ���ؼ�����С�ļ�¼���i ����¼������
ֱ���������а��ؼ�������
*/ 
#include <iostream>
using namespace std;

void simpleSelectSort(int *a,int len)
{
	int i,j,k,temp;
	for(i=0;i<len;i++){
		k=i;//�ݴ��i��Ԫ�����꣬����Ϊ��С��Ԫ������ 
		for(j=i+1;j<len;j++){//��i+1֮���Ԫ��������С��Ԫ�أ���k��¼ 
			if(a[k]>a[j])
				k=j;
		}
		if(k!=i){//kֵ�仯˵��֮ǰ����Ĳ�����С��Ԫ�أ�����a[k]��a[i] 
			temp=a[k];
			a[k]=a[i];
			a[i]=temp;
		}
	}
}

int main()
{
	int n=0,a[100],i,data;
	//����
	cout<<"��������������֣���-1��β��"<<endl;
	while(cin>>data&&data!=-1){
		a[n++]=data;
	} 
	//����
	simpleSelectSort(a,n);
	//���
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	return 0;
}
