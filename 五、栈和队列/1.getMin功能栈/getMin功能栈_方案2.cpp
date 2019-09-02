/*
���⣺���һ��ÿ�ο��Եõ�ջ����СԪ�ص�ջ
	Ҫ��pop,push,getMin����ʱ�临�Ӷȶ���O(1),������������ջ�ṹ 

1����������ջ��һ��ջ���ڱ���ջ��Ԫ�أ���һ��ջ���ڱ���ÿһ����Сֵ 
2��eg:
	3	-->	1 
	1	-->	1
	5	-->	3 
	4	-->	3
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
	if(minStack.empty())//��minStackΪ�գ��򽫵�һ��Ԫ��ѹ�� 
		minStack.push(number);
	else if(number<=this->getMin())//���ǵ�ǰԪ��С�ڵ���minStack��Сֵ����ѹ�� 
		minStack.push(number);
	else//����ѹ��minStack�е���Сֵ 
		minStack.push(this->getMin());
		
	dataStack.push(number);//ѹ������ջ 
}
//��ջ����
int MyStack::pop()
{
	if(dataStack.empty())
		return -1;
	
	minStack.pop();//minStack��Ҫͬ������ 
	int value=dataStack.top();//�õ�����ջջ�� 
	dataStack.pop();//��������ջջ�� 
	return value;
}
//�õ���ǰջ����Сֵ 
int MyStack::getMin()
{
	if(minStack.empty())
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
