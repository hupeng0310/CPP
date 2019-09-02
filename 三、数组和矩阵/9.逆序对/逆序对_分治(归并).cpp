/*
���⣺������������Ը����������ǰ��������ں���������򹹳�һ�������
		Poj problem1804 Accept(http://poj.org/problem?id=1804)
	
˼·�����ù鲢�����˼�룬
	��1����Ϊ�ϲ������ǽ������ֺϲ���һ���֣��ںϲ��Ĺ����У����ǰ�沿��ĳ�������ں���Ĳ��ֵ�
		�����򹹳������ 
	��2���ϲ���ʱ��������������ģ����Ե�ǰλ��i������ں���jλ�õ�������i��mid֮��������Ǵ��ں���jλ�õ�����
		count+=mid-i+1; 
*/
#include <stdio.h>

long long count; 
//�ϲ� 
void merge(int *a,int left,int mid,int right)
{
	int b[100000];
	int i=left,j=mid+1,k=left;//iָ����߿�ʼ��ߣ�jָ���ұ߿�ʼ���꣬k��¼�洢�û��ϲ���b����λ�� 
	while(i<=mid&&j<=right){//i��jͬʱ��ʼɨ�� 
		if(a[i]>a[j]){//������߲��ִ����ұ߲��֣�j����ƣ�����������С��Ԫ�طŵ�b�����У� 
			b[k++]=a[j++];
			count+= mid - i + 1;//��������ԣ�count+=mid-i+1,��Ϊ��������ģ�iλ�ô�>a[j]����i--mid����>a[j] 
		}
		else//����i����� 
			b[k++]=a[i++];
	}
	while(i<=mid)//�п���һ���ȱ����꣬Ȼ����һ��ʣ��ļ�������b���� 
		b[k++]=a[i++];
	while(j<=right)//ͬ�� 
		b[k++]=a[j++];
	for(i=left;i<=right;i++)//���ｫ�ϲ���b���鸴�Ƶ�a������
		a[i]=b[i];
}
//�鲢����-�ݹ� 
void mergeSort(int *a,int left,int right)
{
	int mid;
	if(left<right){
		mid=(left+right)/2;//�����е� 
		mergeSort(a,left,mid);//�ݹ黮������ 
		mergeSort(a,mid+1,right);//�ݹ黮���Ұ�� 
		merge(a,left,mid,right);//�ϲ������� 
	} 
}

int main()
{
    int n,time,tt=1,a[100000];  
    scanf("%d",&time);  
    while(time--)
    {  
        scanf("%d",&n);  
        for(int i=0;i<n;i++)  
            scanf("%d",&a[i]);  
        count = 0;  
        mergeSort(a,0,n-1);  
        printf("Scenario #%d:\n%d\n\n",tt++,count);  
    }  
    return 0;  
} 
