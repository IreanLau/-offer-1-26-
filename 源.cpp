
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


/***************       数组               *******/
bool myFind(int *ar, int rows, int cols, int key)
{
	bool found = false;
	if (ar != NULL && rows > 0 && cols > 0)
	{
		int row = 0;
		int col = cols - 1;
		while (row < rows && col >= 0)
		{
			if (ar[row*cols + col] == key)
			{
				found = true;
				break;
			}
			else if (ar[row*cols + col] > key)
				--col;
			else
				++row;
		}
	}
	return found;
}

void test()
{
	int arry[] = {
		1, 2, 8,  9,
		2, 4, 9,  12,
		4, 7, 10, 13,
		6, 8, 11, 15,
	};


	myFind(NULL, 4, 4, 7) ? cout << "true " << endl : cout << "false " << endl;
}


void test1()
{
	char s1[] = "hello";
	char s2[] = "hello";
	char *s3 = "hello";
	char *s4 = "hello";

	if (s1 == s2)
		cout << "s1 eq s2" << endl;
	else
		cout << "s1 not eq s2" << endl;

	if(s3==s4)
		cout << "s3 eq s4" << endl;
	else
		cout << "s3 not eq s4" << endl;
}
/*
hello world -> hello%20world
		
*/
#include <assert.h>
void blankreplace(char String[], int length)
{
	if (String == NULL || length <= 0)
		return;

	int orglen = 0;
	int blanknum = 0;

	int i = 0;
	while (String[i] != '\0')
	{
		++orglen;

		if (String[i] == ' ')
			++blanknum;

		++i;
	}
	int newlen = orglen + 2 * blanknum;
	if (newlen > length)
		return;

	while (orglen >= 0 && newlen > orglen)
	{
		if (String[orglen] == ' ')
		{
			String[newlen--] = '0';
			String[newlen--] = '2';
			String[newlen--] = '%';
		}
		else
		{
			String[newlen--] = String[orglen];
		}
		--orglen;
	}
}
void test2()
{
	char ar[20] = "hello world";
	cout << ar << endl;

	blankreplace(ar, 20);
	cout << ar << endl;
}

void Merge(int ara[],int arb[],int alen,int blen,int size)
{
	if (ara == NULL || arb == NULL || size < alen+blen)
		return;

	int orglen = alen-1;
	int _blen = blen-1;
	int newlen = blen+alen-1;

	while (orglen >= 0)
	{
		int key = arb[_blen];

		if (arb[_blen] < ara[orglen]) 
		{
			int j = orglen;

			while (ara[j] > key)
			{
				ara[newlen--] = ara[j--];
				--orglen;
			}
		}
		ara[newlen--] = key;
		--_blen;
		
	}
}

void test3()
{
	int a1[20] = {1,2,6,7,9};
	int a2[] = {3,4,5,8,10};

	Merge(a1, a2, 5, 5, 20);

	for (int i = 0; i < 10; ++i)
		cout << a1[i] << " ";
	cout << endl;
}

/***************       栈和队列          *******/

/***************     旋转数组         ************/
//1 2 3 4 5 ：》   3 4 5 1 2 ; 1 2 3 4 5
//0 1 1 1 1  :>>   1 1 0 1 1    , 1 0 1 1 1

namespace Array
{
	int MininOder(int *numbers, int index1, int index2)
	{
		int min = index1;
		for (int i = index1; i <= index2; ++i)
		{
			if (numbers[i] < numbers[min])
				min = i;
		}
		return numbers[min];
	}

	int min(int* numbers, int length)
	{
		if (numbers == NULL || length < 0)
			throw new std::exception("Invalid parmetes");

		int index1 = 0;
		int index2 = length - 1;
		int midindex = 0;

		if (numbers[index1] < numbers[index2])
			return numbers[index1];

		while (numbers[index1] >= numbers[index2])
		{
			if (index1 + 1 == index2)
			{
				midindex = index2;
				break;
			}

			//1 0 1 1 1 
			if (numbers[index1] == numbers[index2]
				&& numbers[index1] == numbers[midindex])
				return MininOder(numbers,index1,index2);

			midindex = index1 + (index2 - index1) / 2;
			if (numbers[midindex] >= numbers[index1])
				index1 = midindex;

			else 
				index2 = midindex;

		}
		return numbers[midindex];
	}




	void test()
	{

		//int ar[5] = {3,4,5,1,2};

		int ar[5] = { 1,0,1,1,1 };

		cout << min(ar,5)<<endl;
	}
}


/**************      Count of '1'     ****************/
namespace Count
{
	int myCount(int binaryNum)
	{
		int ct = 0;
		while (binaryNum)
		{
			binaryNum &= (binaryNum-1);
			++ct;
		}
		return ct;
	}


	void test()
	{
		//测试用例 边界值　１，0x80000000，0x7FFFFFFF ,0xFFFFFFFF
		int num = 0x80000000;
		//int num = 0x7FFFFFFF;
		//int num = 0xFFFFFFFF;
		cout << "the '1' count of " << num << " is :> " << myCount(num) << endl;

	}


	/******************************************/
	//判断是不是2的整数次方
	// 16 :1 0000 ,15 1111   16&15==0
	bool func(int binaryNum)
	{
		return !(binaryNum&(binaryNum-1));
	}

	void test1()
	{
		int binaryNum = 31;
		cout << func(binaryNum) << endl;
	}
}
/**************************   Chapter3   ********************/

namespace Chapter3
{
	/*pow*/

	//a^n =a^(n/2)*a^(n/2)  (偶数)
	//a^n =a^((n-1)/2)*a^((n-1)/2)*a (奇数) 

	double PowerWithUnsignedExp(double base, unsigned int exp)
	{
		if (exp == 0)
			return 1;
		if (exp == 1)
			return base;

		double result = PowerWithUnsignedExp(base,exp>>1);
		result *= result;

		if ((exp & 0x1) == 1)  //奇数
			result *= base;


		return result;
	}


	void test()
	{
		double dNum = 2.0;
		cout << PowerWithUnsignedExp(dNum, -2) << endl;//负数  inf（infinite）
	}


	/**********************  n位的最大值 ****************/

	void PrintNum(char* num)
	{
		bool flag = true;
		int length = strlen(num);

		for (int i = 0; i < length; ++i)
		{
			if (flag && num[i] !='0')
				flag = false;
			if (!flag)
				printf("%c",num[i]);

		}

		cout << " ";
	}



	void PrintRes(char* num ,int length,int index)
	{
		if (index == length - 1)
		{
			PrintNum(num);
			return;
		}
		for (int i = 0; i < 10; ++i)
		{
			num[index + 1] = i + '0';
			PrintRes(num, length, index + 1);
		}
	}


	void PrintToMaxDigit(int n)
	{
		if (n <= 0)
			return;

		char* num = new char[n + 1];
		num[n] = '\0';

		for (int i = 0; i < 10; ++i)
		{
			num[0] = i + '0';
			PrintRes(num, n, 0);
			cout << endl;
		}
		delete[]num;
	}

	void test1()
	{
		int num = 2;
		PrintToMaxDigit(num);
	}
	/*********************  O(1)删除节点 **************/
	struct Node
	{
		int _val;
		Node* _next;
	};
	void DeleteNode(Node** pHead, Node*pToBeDel)
	{
		if (pHead == NULL || pToBeDel == NULL)
			return;

		if (pToBeDel->_next != NULL)		//not tail
		{
			Node* tmp = pToBeDel->_next;
			pToBeDel->_val = tmp->_val;
			pToBeDel->_next = tmp->_next;

			delete tmp;
			pToBeDel = NULL;
		}

		else if (*pHead == pToBeDel)  //eq head
		{
			delete pToBeDel;
			pToBeDel = NULL;

			pHead = NULL;
		}

		else						//is tail
		{
			Node* pPrev = *pHead;
			while (pPrev->_next != pToBeDel)
				pPrev = pPrev->_next;

			pPrev->_next = pToBeDel->_next;
			delete pToBeDel;
			pToBeDel = NULL;
		}
	}


	/*************    数组改变： 奇数在前  偶数在后   **********************/
	void Reoder(int * ar, int length)
	{
		if (ar == NULL || length <= 0)
			return;

		int *pBegin = ar;
		int *pEnd = ar + length - 1;

		while (pBegin < pEnd)
		{
			while (pBegin < pEnd && (*pBegin & 0x1) == 1)
				pBegin++;
			while (pBegin < pEnd && (*pEnd & 0x1) == 0)
				pEnd--;

			if (pBegin < pEnd)
				*pBegin ^= *pEnd ^= *pBegin ^= *pEnd;
		}
	}

	void test4()
	{
		int a[5] = { 1,2,3,4,5 };
		Reoder(a, 5);
		int q = 0;
	}
}


namespace Tree
{
	typedef struct Node
	{
		int data;
		Node* left;
		Node* right;
	}Node;

	void Mirror(Node* pNode)
	{
		if (pNode == NULL || (pNode->left == NULL && pNode->right))
			return;

		Node* tmp = pNode->left;
		pNode->left = pNode->right;
		pNode->right = tmp;

		if (pNode->left)
			Mirror(pNode->left);
		if (pNode->right)
			Mirror(pNode->right);
	}


	/*判断一个数组是不是一颗树的后序遍历序列*/
	bool JudgeLast(int ar[], int length)
	{
		if (ar == NULL || length < 0)
			return false;

		int root = ar[length - 1];

		int i = 0;
		for (; i < length - 1; ++i)
		{
			if(ar[i]>root)
				break;
		}
		for (int j = i; j < length - 1; ++j)
		{
			if (ar[j] < root)
				return false;
		}

		bool left = true;
		if (i > 0)
		{
			left = JudgeLast(ar, i);
		}

		bool right = true;
		if (i < length - 1)
		{
			right = JudgeLast(ar+i,length-i-1);
		}

		return (left&&right);
	}

	/*
		某一路径求和
	*/
	void FindPath(Node* pRoot,int sum)
	{
		if (pRoot == NULL)
			return;


	}
	//搜索树转有序双链表
	Node* First(Node* pRoot)
	{
		if (pRoot == NULL)
			return NULL;

		Node* pF = pRoot;
		while (pF->left)
		{
			pF = pF->left;
		}
		return pF;
	}
	Node* Last(Node* pRoot)
	{
		if (pRoot == NULL)
			return NULL;

		Node* pL = pRoot;
		while (pL->right)
		{
			pL = pL->right;
		}
		return pL;
	}

	Node* Convert(Node*& pRoot)
	{
		if (pRoot == NULL)
		{
			cout << "NULL" << endl;
			exit(1);
		}
		Node*cur = pRoot->left;
		Node*NewHead = First(pRoot);
		while (cur)
		{
			if (pRoot->left)
				pRoot->left = Last(pRoot);
			if (pRoot->right)
				pRoot->right = First(pRoot);

			cur = cur->left;
		}
		return NewHead;
	}

	void test()
	{
		Node* root = new Node;
		root->data = 8;

		root->left = new Node;
		root->left->data = 6;
		root->right = new Node;
		root->right->data = 10;

		root->left->left = new Node;
		root->left->left->data = 5;
		root->left->right = new Node;
		root->left->right->data = 7;
		root->left->left->left = root->left->left->right = NULL;
		root->left->right->left = root->left->right->right = NULL;

		root->right->left = new Node;
		root->right->left->data = 9;
		root->right->right = new Node;
		root->right->right->data = 11;
		root->right->left->left = root->right->left->right = NULL;
		root->right->right->left = root->right->right->right = NULL;

		//Mirror(root);
		Node* Nh = Convert(root);
		getchar();
	}
	
}

namespace RingPrintArry
{

#define ROWSIZE 4
	void RingPrint(int number[][ROWSIZE], int col, int row, int start);

	void func(int number[][ROWSIZE], int col, int row)
	{
		if (number == NULL || col <= 0 || row <= 0)
			return;

		int start = 0;
		while (col > start * 2 && row > start * 2)
		{
			/*
				把矩阵看成多个圈，每个圈从 (start,start)开始，依次打印
			*/
			RingPrint(number, col, row, start);
			++start;
		}
		cout << endl;
	}

	void RingPrint(int number[][ROWSIZE], int col, int row, int start)
	{
		int endX = col - 1 - start;
		int endY = row - 1 - start;

		//左到右
		for (int i = start ; i <= endX; ++i)
		{
			int num = number[start][i];
			cout << num << " ";
		}
		//上到下
		if (start < endY)
		{
			for (int i = start + 1; i <= endY; ++i)
			{
				int num = number[i][endX];
				cout << num << " ";
			}
		}
		
		//右到左
		if (start < endX && start < endY)
		{
			for (int i = endX-1; i >= start; --i)
			{
				int num = number[endY][i];
				cout << num << " ";
			}
		}

		//下到上
		if (start < endX && start < endY - 1)
		{
			for (int i = endY-1; i >= start+1; --i)
			{
				int num = number[i][start];
				cout << num << " ";
			}
		}
	}


	void test()
	{
		int ar[4][4] = 
		{	1,2,3,4,
			5,6,7,8,
			9,10,11,12,
			13,14,15,16
		};


		func(ar, 4, 4);
	}
}


namespace JudgeStackSeq
{
	typedef int Stack[100];
	bool Judge(const int* push,const int* pop,int length)	
	{
		Stack myStack;
		memset(myStack, 0, 100);
		int top = 0;
		if (push != NULL && pop != NULL && length > 0)
		{
			int indexPush = 0;
			int indexPop = 0;
			while (top < length && indexPop<length)
			{
				if (indexPush < length)
				{
					myStack[top++] = push[indexPush++];
				}
				
				if (myStack[top-1] == pop[indexPop])
				{
					--top;
					++indexPop;
				}
			}
			return top == 0;
		}
		return false;
	}

	void test()
	{
		int push[5] = { 1,2,3,4,5 };
		int pop[5] = {4,5,3,2,1};
		cout << Judge(push, pop, 5) << endl;
	}
}

namespace ComplexListCopy
{
	struct ComlexListNode
	{
		int m_val;
		ComlexListNode* pNext;
		ComlexListNode* pSib;
		ComlexListNode(int key, ComlexListNode* next = NULL, ComlexListNode*sib = NULL)
			:m_val(key), pNext(next), pSib(sib)
		{}
	};
	void show(ComlexListNode* pBeign)
	{
		ComlexListNode* cur = pBeign;
		while (cur)
		{
			cout << cur->m_val << " ";
			cur = cur->pNext;
		}
	}
	//在每个节点后克隆节点
	void CloneNode(ComlexListNode* pHead)
	{
		ComlexListNode *pNode = pHead;
		while (pNode)
		{
			ComlexListNode* pClone = new ComlexListNode(pNode->m_val, pNode->pNext);
			pNode->pNext = pClone;
			pNode = pClone->pNext;
		}
	}
	//将克隆后节点的sib指向相应位置
	void Connect(ComlexListNode* pHead)
	{
		ComlexListNode *pNode = pHead;
		while (pNode)
		{
			ComlexListNode* pClone = pNode->pNext;
			if (pNode->pSib != NULL)
			{
				pClone->pSib = pNode->pSib->pNext;
			}
			pNode = pClone->pNext;
		}
	}
	//断开连接，返回克隆链表的头节点
	ComlexListNode* Depart(ComlexListNode* pHead)
	{
		ComlexListNode *pNode = pHead;
		ComlexListNode *pCloneHead = NULL;
		ComlexListNode *pClonepNode = NULL;

		if (pNode != NULL)
		{
			pCloneHead = pClonepNode = pNode->pNext;
			//pNode->pNext = pClonepNode->pNext;
			//pNode = pNode->pNext;
		}

		while (pClonepNode->pNext)
		{
			pNode->pNext = pClonepNode->pNext;
			pNode = pNode->pNext;
			pClonepNode->pNext = pNode->pNext;
			pClonepNode = pClonepNode->pNext;
		}

		return pCloneHead;
	}

	ComlexListNode*  Clone(ComlexListNode* pHead)
	{
		CloneNode(pHead);
		Connect(pHead);
		return Depart(pHead);
	}

	void test()
	{

		ComlexListNode *e = new ComlexListNode(5);
		ComlexListNode *d = new ComlexListNode(4, e);
		ComlexListNode *c = new ComlexListNode(3, d);
		ComlexListNode *b = new ComlexListNode(2, c, e);
		ComlexListNode *a = new ComlexListNode(1, b, c);
		d->pSib = b;

		show(a);
		cout << endl;
		show(Clone(a));
	}
}




void main()
{
	Tree::test();
	
	
}
