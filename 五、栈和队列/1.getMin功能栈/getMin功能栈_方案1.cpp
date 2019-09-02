/*
���⣺���һ��ÿ�ο��Եõ�ջ����СԪ�ص�ջ
	Ҫ��pop,push,getMin����ʱ�临�Ӷȶ���O(1),������������ջ�ṹ 

1����������ջ��һ��ջ���ڱ���ջ��Ԫ�أ���һ��ջ���ڱ���ÿһ����Сֵ 
2��eg:
	3	-->	 ��ѹ�� 
	1	-->	1
	5	-->	��ѹ�� 
	4	-->	��ѹ�� 
	3	-->	3

*/
#include <iostream>
#include <stack>
using namespace std;

class MyStack//�Զ���һ���࣬�����������Ĳ��� 
{
	private://����ջΪ˽�г�Ա���� 
		stack<int> dataStack;//�洢����ջ 
		stack<int> minStack;//�洢��ǰ��Сֵջ 
	public://������Ա���� 
		void push(int number);
		int pop();
		int getMin();
};
//ѹջ����
void MyStack::push(int number) 
{
	if(minStack.empty())//����СֵջΪ�գ�������ѹ�� 
		minStack.push(number);
	else if(number<=this->getMin())//����ǰֵС�ڵ�����Сֵջ�е���Сֵ����ѹ�� 
		minStack.push(number);
	
	dataStack.push(number);//������ѹ������ջ 
} 
//��ջ���� 
int MyStack::pop()
{
	if(dataStack.empty())//����ջΪ�գ����� 
		return -1;
	
	int value=dataStack.top();//��ȡ����ջջ��Ԫ�� 
	dataStack.pop();//����ջ��ջ��ֻ�ǽ�ջ��ɾ����û�з���ֵ����java�в�ͬ�� 
	if(value==this->getMin())//��������ջջ������Сֵջ�е���Сֵ��ջ������ͬ��Ҳ���� 
		minStack.pop();
		
	return value;
}
//�õ���ǰջ����Сֵ 
int MyStack::getMin()
{
	if(dataStack.empty())
		return -1;
		
	return minStack.top();//��ȡջ��Ԫ�� 
}

int main()
{
	MyStack myStack;
	//ѹջ 
	int data,n=0;
	cout<<"�������������У�������ѹ��ջ�У���-1��β��:"<<endl; 
	while(cin>>data && data!=-1){
		myStack.push(data);//ѹջ 
		n++;
	} 
	
	//ÿ�ε���һ��Ԫ�أ���ȡջ�е���Сֵ 
	cout<<"ÿ�λ�õ���Сֵ��"<<endl;
	for(int i=0;i<n;++i){
		cout<<myStack.getMin()<<" ";
		myStack.pop();
	} 	
	cout<<endl;
	
	return 0;
} 
