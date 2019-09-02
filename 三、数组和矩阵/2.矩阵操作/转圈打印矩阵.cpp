/*
���⣺תȦ��ӡ����

1����topRow,topCol����¼���Ͻ�Ԫ��λ�ã���downRow,downCol����¼���½�Ԫ��λ��
2��ÿ�δ�ӡһȦ�� topRow++,topCol++�� downRow--,downCol--
3���������Ͻ���һ�����ܵ����½Ƕ�Ӧ�������棬���ӡ��� 
*/ 
#include <iostream>
using namespace std;

//��ӡ�Ӿ����һȦ 
void printCircle(int a[][4],int topRow,int topCol,int downRow,int downCol)
{
	if(topRow==downRow)//���ֻʣһ�У�ֱ�Ӵ�ӡ 
		for(int i=topCol;i<=downCol;++i)
			cout<<a[topRow][i]<<" ";
	else if(topCol==downCol)//���ֻʣһ�У�ֱ�Ӵ�ӡ
		for(int i=topRow;i<=downRow;++i)
			cout<<a[i][topCol]<<" ";
	else{//������� 
		int curCol=topCol,curRow=topRow;//�������������ֱ��ƶ���ӡ���൱������ָ��תȦ�ƶ��� 
		while(curCol!=downCol)//���ң����������½ǵ��к�,���curCol���ƶ�����ǰ����󣨲�����ӡ��ǰ�����һ��Ԫ�أ�curCol++��downCol���˳���while������������󲢲����ӡ��topRow,topCol�����Ԫ�أ� 
			cout<<a[topRow][curCol++]<<" ";
		while(curRow!=downRow)//���£����������½ǵ��кţ����curRow���ƶ����е���� 
			cout<<a[curRow++][downCol]<<" "; 
		while(curCol!=topCol)//���󣬱��������Ͻǵ��кţ����curCol���ƶ����е���ǰ 
			cout<<a[downRow][curCol--]<<" "; 
		while(curRow!=topRow)//���ϣ� 
			cout<<a[curRow--][topCol]<<" "; 
	}
}
//������ 
void spiralOrderPrint(int a[][4],int rowCount,int colCount)
{
	int topRow=0;
	int topCol=0;
	int downRow=rowCount-1;
	int downCol=colCount-1;//��ȡ���ϽǺ����½ǵ����� 
	while(topRow<=downRow && topCol<=downCol)//��һ���곬���������ӡ 
		printCircle(a,topRow++,topCol++,downRow--,downCol--);//��ӡһȦ������ 
}

int main()
{
	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	cout<<"����Ϊ��"<<endl;
	int rowCount=sizeof(a)/sizeof(a[0]);//������ 
	int colCount=sizeof(a[0])/sizeof(int);//������ 
	//��ʾ���� 
	for(int i=0;i<rowCount;++i){
		for(int j=0;j<colCount;++j)
			cout<<a[i][j]<<" ";
		cout<<endl;
	} 
	//������
	cout<<"���Ϊ��"<<endl;
	spiralOrderPrint(a,rowCount,colCount);
	 
	return 0;
}
