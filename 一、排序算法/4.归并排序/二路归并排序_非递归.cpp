/* 
�ǵݹ�˼��: �������е�����Ԫ��������ԡ���merge��������������
����n/2�鳤��Ϊ2������õ�������Σ�Ȼ���ٽ���������ɳ���Ϊ4��������Σ�
��˼�����ȥ��ֱ�����������ź���
*/
#include <iostream>
using namespace std;

void mergeSort(int *a,int len)
{
	int i,lowMin,lowMax,highMin,highMax,next;
	int temp[100];
	for(i=1;i<len;i*=2){//������Ϊ1,2,4,8...... 
		for(lowMin=0;lowMin<len-i;lowMin=highMax){//ÿ�����������ֽ������� 
			highMin=lowMax=lowMin+i;//lowMin��highMin��ʼͬһλ�� 
			highMax=highMin+i;//highMax��¼��һ��������ʼ��λ�ã�������û�иı�highMax��ֵ��ֻ��forѭ����ָ����һ��lowMin��λ�� 
			if(highMax>len)//���highMaxԽ�磬ָ��Ϊ���ֵ 
				highMax=len;
			next=0;//ÿ�γ�ʼ��Ϊ0����Ҫ���ڲ����ݴ�����temp������ 
			while(lowMin<lowMax && highMin<highMax)//���������Σ���ΪhighMax���ܲ���������һ�Σ����Կ�����ǰ���� 
				temp[next++]=a[lowMin]>a[highMin] ? a[highMin++] : a[lowMin++];//temp�ݴ��С��Ԫ�أ�ͬʱ��С��Ԫ������++ 
			while(lowMin<lowMax)//���ǰһ��û�б����꣨��ΪhighMin<highMax������ǰ��������highMin��¼��һ��λ�ã���lowMax��highMin�ǿ��Ա����ǵģ���Ϊtemp��¼�ˣ������Խ�ǰһ������� 
				a[--highMin]=a[--lowMax];
			while(next>0)//���ݴ������е�ֵ������ 
				a[--highMin]=temp[--next]; 
		}
	}
}

int main()
{
		int n=0,a[100],data,i;
		//���� 
		cout<<"��������������֣���-1��β��"<<endl;
		while(cin>>data && data!=-1){
			a[n++]=data;
		} 
		//����
		mergeSort(a,n);
		//���
		cout<<"n="<<n<<endl;
		for(i=0;i<n;++i)
			cout<<a[i]<<" ";
		cout<<endl; 
		return 0;
} 
