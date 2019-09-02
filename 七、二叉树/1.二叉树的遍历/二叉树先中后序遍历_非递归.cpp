/*
���⣺���������ȡ��С�����ǵݹ����

��������ǵݹ飺
	1������ջ���Ƚ�����ջ
	2������ջ������ӡ��Ȼ�����Һ���**��ջ�����еĻ��� 
	3��Ȼ������**��ջ �����еĻ���
	4��Ȼ��ص�2
��������ǵݹ飺 
	1������ջ��������������߽�**һ����ջ(root=root->left) 
	2����rootΪ�գ��򵯳�ջ��node����ӡ����root=node.right��Ȼ���ظ�1
	3��ֱ��ջΪ�ջ�rootΪ�գ�����
�����������������ջ��***��
	1��ջs1����ʼֵΪ��
	2������s1ջ����root������ջs2������root���Һ�������*��ջs1������еĻ���
	3��ֱ��s1Ϊ��
	4�����ε���s2��Ԫ�ؼ�Ϊ���������� 

�������������һ��ջ��***��
	1��ջs1,����root�������һ�ε�������ӡ�Ľ׶Σ�����c����ջ���ڵ�
	2����ʼrootΪ����c=NULL
	3����c�����Ӳ�ΪNULL����h������c������Ҳ������c���Һ��ӣ���cѹ��ջ��
		����Ϊroot�������һ�ε�������ӡ�Ľڵ㣬���rootΪc������Һ��ӣ�˵��c����������ӡ��ϣ�
		  �Ͳ���Ҫ��c������Ҫ��ջ���ˣ�����˵��������û�д������������ѹ��ջ�У� 
	4����3�����㣬����c���Һ��Ӳ�ΪNULL����root������c���Һ��ӣ���c���Һ���ѹ��ջ
		����Ϊ���rootΪc���Һ��ӣ�����������������ϣ�����Ҫ���Һ���ѹ��ջ�������ѹ���Һ��ӣ� 
	5�����3��4�������㣬��ջ�е���c����ӡ��Ȼ����root=c 
		��˵������������������ϣ�����ջ������ӡ�� 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

typedef struct Node{//���Ľṹ�嶨�� 
	int value;
	Node *left;
	Node *right;
}BiNode,*BiTree; //*BiTree��ʾָ��ṹ���ָ�룬BiNode��ʾ����ṹ�� 

//�������
void preOrderNotRecursion(BiTree root)
{
	if(root){//���������Ϊ�� 
		stack<BiTree> st;//����һ��ջ���������ΪBiTree���� 
		st.push(root);//��ʼֵΪ���ڵ� 
		
		while(!st.empty()){//����ջ 
			root=st.top();//��ȡջ�� 
			st.pop();//����һ��Ԫ�� 
			printf("%d ",root->value);//��ӡ������Ԫ�� 
			if(root->right)//�����Һ��ӣ���ջ 
				st.push(root->right);
			if(root->left)//Ȼ���ٷ����� 
				st.push(root->left);
		}
	}
} 

//������� 
void inOrderNotRecursion(BiTree root)
{
	if(root){//������Ϊ�� 
		stack<BiTree> st;//����ջ 
		while(!st.empty() || root){//���ջ��Ϊ�ջ��ߵ�ǰ����Ľڵ㲻Ϊ�գ���Ϊ�տ�ʼջ���ǿյģ� 
			if(root){//��ǰ�ڵ㲻Ϊ�� 
				st.push(root);//��ջ 
				root=root->left;//���� 
			}
			else{//���Ϊ���� 
				root=st.top();//��ջ����ӡ 
				st.pop();
				printf("%d ",root->value);
				root=root->right;//ָ���ұߣ��������ֻص����� 
			}
				
		}	
	}
	
}
//�����������������ջ��*** 
void posOrderNotRecursion1(BiTree root)
{
	if(root){
		stack<BiTree> s1;
		stack<BiTree> s2;
		s1.push(root);//��ʼֵs1Ϊ�� 
		while(!s1.empty()){//ֱ��s1Ϊ�� 
			root=s1.top();//����s1������root��¼
			s1.pop();
			s2.push(root);//�������ķŵ�s2 
			if(root->left)//��ߺ�����ջs1 
				s1.push(root->left);
			if(root->right)//�ұߺ�����ջs2 
				s1.push(root->right);
		}
		while(!s2.empty()){//���ε���ջs2 
			printf("%d ",s2.top()->value);
			s2.pop();
		}
	} 
}
//�������������һ��ջ�� 
void posOrderNotRecursion2(BiTree root)
{
	if(root){
		stack<BiTree> st;
		st.push(root);
		BiTree c=NULL;
		while(!st.empty()){
			c=st.top();
			if(c->left && root!=c->left && root!=c->right)
				st.push(c->left);
			else if(c->right!=NULL && root!=c->right)
				st.push(c->right);
			else{
				printf("%d ",st.top()->value);
				st.pop();
				root=c;
			}
		}
	} 
} 


/*
	      1
	  .	  .
	2	    3
     .    .	   
   4        5	     
     .    . 
      6  7 	
*/
int i=-1;
//����ݹ齨������������������ͼ  
void createTree(BiTree *root)//*ȡ�� 
{
	int a[]={1,2,4,0,6,0,0,5,7,0,0,0,3,0,0};
	++i;
	if(a[i]==0)//Ϊ����ǰ�ڵ�Ϊ�� 
		(*root)=NULL;
	else{
		*root=(BiNode*)malloc(sizeof(BiNode));
		if(!(*root))//û���뵽�ͷ��� 
			return;
		(*root)->value=a[i];//����ֵ 
		createTree(&(*root)->left);
		createTree(&(*root)->right);
	}
} 

int main()
{
	BiTree root;
	createTree(&root);//&ȡ��ַ 
	
	printf("������������");
	preOrderNotRecursion(root);
	printf("\n������������");
	inOrderNotRecursion(root); 
	printf("\n����������(��������ջ)��");
	posOrderNotRecursion1(root); 
	printf("\n����������(����һ��ջ)��");
	posOrderNotRecursion2(root); 
	
	return 0; 
} 
