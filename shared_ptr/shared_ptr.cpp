#include<iostream>
#include<mutex>
#include<thread>
//智能指针---引用计数
template<class T>
class Shared_Ptr
{
public:
  Shared_Ptr(T* ptr = nullptr):
    m_Ptr(ptr),
    m_pCount(new int(1)),
    m_pMut(new std::mutex)
  {}

  //
  Shared_Ptr(const Shared_Ptr<T>& obj):
    m_Ptr(obj.m_Ptr),
    m_pCount(obj.m_pCount),
    m_pMut(obj.m_pMut)
  {
    AddRefCount();
  }

  Shared_Ptr<T>& operator= (const Shared_Ptr<T>& obj)
  {
    if(this != &obj)
    {
      if(m_pCount != nullptr)
      {
        Release();
      }
     //if(--(*m_pCount) == 0)  //如果原来只有自己一个人来管理这块空间，那么就得先将原来的空间先释放掉
     //{
     //  delete m_Ptr;
     //  delete m_pCount;
     //}

      m_Ptr = obj.m_Ptr;
      m_pCount = obj.m_pCount;
      m_pMut = obj.m_pMut;
      AddRefCount();
    }
    return *this;
  }
  void AddRefCount()
  {
    m_pMut->lock();
    ++(*m_pCount);
    m_pMut->unlock();
  }

  void Release()
  {
    bool flag = false;
    m_pMut->lock(); 
    if(--(*m_pCount) == 0 && m_Ptr != NULL)
    {
      flag = (*m_pCount) == 0 ? true : false;
      std::cout << m_Ptr << std::endl;
      delete m_Ptr;
      m_Ptr = NULL;
      delete m_pCount;
      m_pCount = NULL;
    } 
    m_pMut->unlock();
    
    if(flag == true)
    {
      delete m_pMut;
      m_pMut = NULL;
    }
  }
  ~Shared_Ptr()
  {
    Release();
  }

  T& operator*()
  {
    return *m_Ptr;
  }

  T* operator->()
  {
    return m_Ptr;
  }
  
  int UseCount()
  {
    return *m_pCount;
  }

 	T* GetPtr () const
	{
		return m_Ptr;
	} 
private:
  T* m_Ptr;
  int* m_pCount; //通过指针来引用计数有多少个对象共同管理这一块空间
  std::mutex* m_pMut;
};

void test1()
{
	Shared_Ptr<int> sp(new int);
	int n = 1000;

  
	std::thread t1([&]()
	{
		for (int i = 0; i < n; ++i)
		{
			Shared_Ptr<int> sp1(sp);
		}
	}
	);

	std::thread t2([&]()
	{
		for (int i = 0; i < n; ++i)
		{
			Shared_Ptr<int> sp2(sp);
		}
	}
	);

	t1.join();
	t2.join();
}


template<class T>
class Weak_Ptr
{
public:
	Weak_Ptr() = default;

	Weak_Ptr(const Shared_Ptr<T>& obj):
		m_Ptr( obj.GetPtr() )
	{
	}
	Weak_Ptr<T>& operator= (const Shared_Ptr<T>& obj)
	{
		this->m_Ptr = obj.GetPtr();
		return *this;
	}

	T& operator*()
	{
		return *m_Ptr;
	}

	T* operator->()
	{
		return m_Ptr;
	}
private:
	T* m_Ptr;
};

struct ListNode
{
	//Shared_Ptr<ListNode> next;
	//Shared_Ptr<ListNode> prev;
	Weak_Ptr<ListNode> next;
	Weak_Ptr<ListNode> prev;
	~ListNode()
	{
    std::cout << " ~ListNode() " << std::endl;
	}
};



void test2()
{
  //循环引用造成错误
	Shared_Ptr<ListNode>spn1(new ListNode);
	Shared_Ptr<ListNode>spn2(new ListNode);
	//循环引用
  //Shared_Ptr缺点
  spn1->next = spn2; //通过Weak_Ptr来解决这个问题，这样引用计数就不会增加
	spn2->prev = spn1;

}

int main()
{
  test1();
  test2();
  return 0;
}
