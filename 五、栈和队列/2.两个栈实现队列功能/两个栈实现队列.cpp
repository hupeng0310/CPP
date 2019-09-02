/*
���⣺ʹ������ջʵ�ֶ��е�add����ӣ�,poll�����ӣ�,peek����ȡ��ͷԪ�أ����� 
 
1�������ݷ���һ��ջstackPush���ٽ�ջ��Ԫ�����ε�������һ��ջ��stackPop 
	5	1
	4	2
	3	3
	2	4
	1	5
2����Ҫע������
	��1��stackPushһ��Ҫȫ������ 
	��2����stackPop��Ϊ�գ�stackPush���ܵ��� 
*/ 
#include <iostream>
#include <stack>
using namespace std;

class TwoStackQueue//�Զ���һ���࣬ʵ�����Ϲ��� 
{
	private:
		stack<int> stackPush;//ѹ��ջ 
		stack<int> stackPop;//����ջ 
	public:
		void add(int number);
		int poll();
		int peek();
}; 
//��� 
void TwoStackQueue::add(int number)
{
	stackPush.push(number);//ѹ��ջֱ����ջ 
}
//���� 
int TwoStackQueue::poll()
{
	if(stackPush.empty() && stackPop.empty()){//������ջ��Ϊ�գ������Ϊ�� 
		return -1;
	}
	else if(stackPop.empty()){//���ǵ���ջΪ�� 
		while(!stackPush.empty()){//��ѹ��ջȫ��ѹ�� 
			stackPop.push(stackPush.top());
			stackPush.pop();//pop����ֻ�ǵ�������������Ԫ�أ����Էֿ�д����java�в�ͬ 
		}	
	}
	
	int value=stackPop.top();//��ȡջ������Ϊ��ͷ�� 
	stackPop.pop();//��ջ 
	return value;
}
//��ȡ��ͷԪ�� 
int TwoStackQueue::peek()
{
	if(stackPush.empty() && stackPop.empty()){//������ջ��Ϊ�գ������Ϊ��
		return -1;
	}
	else if(stackPop.empty()){//ͬ�� 
		while(!stackPush.empty()){
			stackPop.push(stackPush.top());
			stackPush.pop();
		}	
	}
	
	return stackPop.top();//��ȡ����ջջ������Ϊ��ͷԪ�أ� 
}

int main()
{
	//���� 
	TwoStackQueue queue;
	int data,n=0;
	cout<<"���������Ԫ�أ���-1��β����"<<endl;
	while(cin>>data && data!=-1){
		queue.add(data);
		++n; 
	} 
	
	//���
	cout<<"��������"<<endl;
	for(int i=0;i<n;++i){
		cout<<"����"<<(i+1)<<"��,������ͷԪ��Ϊ��"<<queue.poll();
		if(queue.peek()!=-1)
			cout<<"����ʱ��ͷԪ��Ϊ��"<<queue.peek()<<endl; 
		else
			cout<<"����ʱ��Ϊ��"<<endl;
	} 
	
	return 0;
}
