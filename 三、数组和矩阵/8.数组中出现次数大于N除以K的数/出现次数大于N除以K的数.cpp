#include <stdio.h>
#include <map>
#include <list>
/*
���⣺��һ�������д������ִ���N/k����

˼·���������д�������N/2���������ƣ�ֻ����ҪѰ��k-1����ѡ
	1���������飬����a[i]���ѡ��Ԫ����ͬ�����Ӧ��map�е�value++
	2�����ǲ���ͬ���жϺ�ѡ�Ƿ����ˣ�k-1����������û�������µ�a[i]��Ϊ��ѡ
	3���������ˣ�˵����ǰ���ǵ�K��������ÿ����ѡ��key��Ӧ��value-1��ͬʱ����
		value-1֮��Ϊ0����Ҫɾ��map�ж�Ӧkey�Ŀռ�
	4�������Ϳ���ѡ�к�ѡԪ�أ�Ȼ�������ÿ����ѡ���ֵ���������ͳ�Ƶ�map���ж� 
	 
*/
#include <iostream>
using namespace std;

//map��ÿ��key��Ӧ��value��һ��ͬʱ����valueΪ0����ɾ�����key��Ӧ�Ŀռ� 
void allCandsMinusOne(map<int,int> &cands)//c++�е�&���ã��ı�ԭʼֵ 
{
	list<int> removeList;//��¼value-1Ϊ0�ļ��ϵ�key����Ҫ�ں�ѡmap��ɾ��key��ɾ��key����ɾ������ռ䣩 
	
	map<int,int>::iterator iter; 
 	for(iter = cands.begin(); iter != cands.end(); iter++){//���� 
 		int key=iter->first;//�õ�key 
 		int value=iter->second;//�õ�value 
 		if(value==1)//���value=1����������ɾ��list�� 
 			removeList.push_back(key);
 		cands[key]=value-1;//��Ӧvalue-1 
	}
	
	list<int>::iterator it;
	for(it=removeList.begin();it!=removeList.end();++it){//����ɾ������ 
		cands.erase(*it);
	}
}

//�õ���ѡԪ�غ�ͳ��ÿ����ѡ���ֵĴ��� 
map<int,int> getReals(int *a,map<int,int> cands,int len)
{
	map<int,int> reals;
	for(int i=0;i<len;++i){		//�������� 
		int curNum=a[i];
		
		map<int,int>::iterator iter1;
		iter1 = cands.find(curNum); 
		if(iter1 != cands.end()){//�ں�ѡ�������ң������ҵ���������real�������� 
			map<int,int>::iterator iter2;
			iter2=reals.find(curNum);
			if(iter2 != reals.end())//����ҵ�����Ӧλ��+1 
				reals[curNum]=reals[curNum]+1;
			else
				reals[curNum]=1;	//�������Ӧλ��Ϊ1 
		}
	}
	return reals;
}

//��ӡmap�е�key��value�����Բ鿴�� 
void print(map<int,int> cands)
{
	map<int,int>::iterator iter; 
 	for(iter = cands.begin(); iter != cands.end(); iter++){
		cout<<iter->first<<" "<<iter->second<<endl;
	}
}

 
void KMajority(int *a,int k,int len)
{
	if(k<2 || len<1)//������������� 
		return;
	
	map<int,int> cands;
	for(int i=0;i<len;++i){		//�������� 
		map<int,int>::iterator iter; 
		iter = cands.find(a[i]);//��ѡ�в���,�����ҵ������Ӧkeyλ����value+1 
		if(iter != cands.end()){
			cands[a[i]]=cands[a[i]]+1;
		}
		else{
			if(cands.size()==k-1){//�����ѡ��������������Ԫ�ض�Ӧ��value-1 
				//cout<<"ǰ��"<<endl;
				//print(cands);
				allCandsMinusOne(cands);
				//cout<<"��"<<endl;
				//print(cands);
			}	
			else	//�������µ�Ԫ��keyλ��valueΪ1 
				cands[a[i]]=1;
		}
	}
	//print(cands);	
	map<int,int> reals=getReals(a,cands,len);//�õ�ÿ����ѡԪ�س��ִ�����map 
	//print(reals);
	bool hasPrint=false;	//�����ж��Ƿ���N/k��Ԫ�ر�־ 
	
	map<int,int>::iterator iter; 
 	for(iter = reals.begin(); iter != reals.end(); iter++){//���� 
 		int key=iter->first;//firstΪkeyֵ 
 		if(reals[key]>len/k){//���key��Ӧ��value>len/K����Ϊ���󣬴�ӡ��� 
 			hasPrint=true;
 			printf("%d ",key);
 		}
	}
	
	if(!hasPrint)//û�д�ӡ�������ǲ����� 
		printf("û���ҵ�");
}

int main()
{
	int a[]={1,1,2,3,1,2,3,2,3,1};
	int len=sizeof(a)/sizeof(int);
	int k=3;
	
	KMajority(a,k,len); 
	
	return 0;
} 
