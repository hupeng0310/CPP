/*
��ѡ������ÿ��ѭ��ֻ��ȷ��һ��Ԫ�������Ķ�λ��
���ǿ��Կ��ǸĽ�Ϊÿ��ѭ��ȷ������Ԫ��,ѡ����С��Ԫ�ط���ǰ�棬����Ԫ�ط��ں��� 
*/
#include <iostream>
using namespace std;

//�������� 
void swapNum(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp; 
} 

void selectSort(int *a,int len)
{
	int i,j,min,max;
	for(i=0;i<len/2;i++){//�ܹ��������� 
		min=i;//��¼��СԪ������ 
		max=i;//��¼���Ԫ������ 
		for(j=i+1;j<len-i;j++){//j=i+1��j<len-i��ͷͬʱ��С����Ϊÿ��ѡ������Ԫ�� 
			if(a[j]>a[max]){//��������Ԫ�ش���max�����Ӧ��Ԫ�أ�����max���� 
				max=j;
				continue;//���a[j]�Ѿ�����a[max]�ˣ�����a[j]������С��Ԫ���ˣ���������ıȽ��ˣ�continue��������ѭ���������´�ѭ�� 
			}
			if(a[j]<a[min]){//��������Ԫ��С��min��Ӧ��Ԫ�أ�����min���� 
				min=j;
			}
		}
		if(min!=i)//���min�仯�ˣ��ͽ���С��Ԫ�ؽ�����ǰ�� 
			swapNum(&a[i],&a[min]);
		if(max==i)//***������Ҫע���£����max==i����maxָ����ǰ�棬��ǰ��϶��Ὣ��С��Ԫ�ؽ�������ǰ�棬���Դ�ʱ����Ԫ��Ϊa[min] 
			swapNum(&a[len-i-1],&a[min]);
		else//������������� 
			swapNum(&a[len-i-1],&a[max]);
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
	selectSort(a,n);
	//���
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	
	return 0;
}
