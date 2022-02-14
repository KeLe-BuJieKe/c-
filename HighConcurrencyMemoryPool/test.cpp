#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<thread>
using namespace std;
#include"ConcurrentAlloc.h"

#include<vector>
#include<ctime>
struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode()
		:_val(0)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

void TestObjectPool()
{
	// 申请释放的轮次
	const size_t Rounds = 5;

	// 每轮申请释放多少次
	const size_t N = 100000;

	std::vector<TreeNode*> v1;
	v1.reserve(N);

	size_t begin1 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v1.push_back(new TreeNode);
		}
		for (int i = 0; i < N; ++i)
		{
			delete v1[i];
		}
		v1.clear();
	}

	size_t end1 = clock();

	std::vector<TreeNode*> v2;
	v2.reserve(N);

	ObjectPool<TreeNode> TNPool;
	size_t begin2 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v2.push_back(TNPool.New());
		}
		for (int i = 0; i < N; ++i)
		{
			TNPool.Delete(v2[i]);
		}
		v2.clear();
	}
	size_t end2 = clock();

	std::cout << "new cost time:" << end1 - begin1 << std::endl;
	std::cout << "object pool cost time:" << end2 - begin2 << std::endl;
}


void testConcurrentAlloc()
{
	void* p1 = ConcurrentAlloc(6);
	void* p2 = ConcurrentAlloc(8);
	//void* p3 = ConcurrentAlloc(1);
	//void* p4 = ConcurrentAlloc(7);
	//void* p5 = ConcurrentAlloc(8);
	cout << p1 << endl;
	//cout << p2 << endl;
	//cout << p3 << endl;
	//cout << p4 << endl;
	//cout << p5 << endl;

	ConcurrentFree(p1);
	ConcurrentFree(p2);
	//ConcurrentFree(p3);
	//ConcurrentFree(p4);
	//ConcurrentFree(p5);
}
void testObjectPool()
{
	//TestObjectPool();

}



void test()
{
	for (size_t i = 0; i < 1024; ++i)
	{
		void* p1 = ConcurrentAlloc(8);
		cout << p1 << endl;
	}
	void* p2 = ConcurrentAlloc(8);
	cout << p2 << endl;
}

void MultiThreadAlloc1()
{
	std::vector<void*> v;
	for (size_t i = 0; i < 7; ++i)
	{
		void* ptr = ConcurrentAlloc(6);
		v.push_back(ptr);
	}

	for (auto e : v)
	{
		ConcurrentFree(e);
	}
}

void MultiThreadAlloc2()
{
	std::vector<void*> v;
	for (size_t i = 0; i < 7; ++i)
	{
		void* ptr = ConcurrentAlloc(16);
		v.push_back(ptr);
	}
	for (auto e : v)
	{
		ConcurrentFree(e);
	}
}

void TestMultiThread()
{
	std::thread t1(MultiThreadAlloc1);
	std::thread t2(MultiThreadAlloc2);

	t1.join();
	t2.join();
}

void BigAlloc()
{
	void* p1 = ConcurrentAlloc(257 * 1024);
	ConcurrentFree(p1);

	void* p2 = ConcurrentAlloc(129 * 8 * 1024);
	ConcurrentFree(p2);
}


int main()
{
	testConcurrentAlloc();
	//TestMultiThread();
	//BigAlloc();
	system("pause");

	return 0;
}


