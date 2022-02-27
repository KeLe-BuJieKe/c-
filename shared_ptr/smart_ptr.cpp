#include<iostream>
#include<mutex>
#include<thread>


template<class T>
class auto_ptr //不要去使用，管理权转移
{
    private:
        T* ptr_;
    public:
        auto_ptr(T* ptr):ptr_(ptr)
        {}

        ~auto_ptr()
        {
            if(ptr_ != nullptr)
            {
                std::cout << "delete: " << ptr_ << std::endl;
                delete ptr_;
                ptr_ = nullptr;
            }
        }

        auto_ptr(auto_ptr<T>& ap)
        {
            ptr_ = ap.ptr_;
            ap.ptr_ = nullptr;
        }

        auto_ptr<T>& operator= (auto_ptr<T>& ap)
        {
            if(this != &ap)
            {
                delete ptr_;
                ptr_ = ap.ptr_;
                ap.ptr_ = nullptr;
            }
            return *this;
        }

        T& operator* ()
        {
            return *ptr_;
        }

        T* operator->()
        {
            return ptr_;
        }
};


template<class T>
class unique_ptr  // 与之前的auto_ptr不同的是直接防止拷贝
{
    private:
        T* ptr_;
    public:
        unique_ptr(T* ptr):ptr_(ptr)
        {}
        
        ~unique_ptr()
        {
            if(ptr_ != nullptr)
            {
                std::cout << "delete: " << ptr_ << std::endl;
                delete ptr_;
                ptr_ = nullptr;
            }
        }

        T& operator*()
        {
            return *ptr_;
        }

        T* operator->()
        {
            return ptr_;
        }

        unique_ptr(const unique_ptr<T>&) = delete;
        unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
};


//引用计数
template<class T>
class shared_ptr
{
    private:
        T* ptr_;
        int* count_;
        std::mutex* p_mutex_;
    public:
        shared_ptr(T* ptr = nullptr)
          :ptr_(ptr),
          count_(new int(1)),
          p_mutex_(new std::mutex)
        {}
        
        shared_ptr(const shared_ptr<T>& sp)
          :ptr_(sp.ptr_)
           ,count_(sp.count_)
           ,p_mutex_(sp.p_mutex_)
          {
              AddRef();
          }
        
        void AddRef()
        {
            (*p_mutex_).lock();
            (*count_)++;
            (*p_mutex_).unlock();
        }

        void Release()
        {
            (*p_mutex_).lock();
            bool flag = false;
            if(--(*count_) == 0)
            {
                std::cout << "delete: " << ptr_ << std::endl;
                delete ptr_;
                delete count_;
                flag = true;
            }

            (*p_mutex_).unlock();
            if(flag == true)
            {
                delete p_mutex_;
            }
        }

        shared_ptr<T>& operator=(const shared_ptr<T>& sp)
        {
            
            if(ptr_ != sp.ptr_)
            {
                Release();
                ptr_ = sp.ptr_;
                count_ = sp.count_;
                p_mutex_ = sp.p_mutex_;
                AddRef();
            }
            return *this;
        }
        
        T& operator*()
        {
            return *ptr_;
        }
        
        T* operator->()
        {
            return ptr_;
        }
        
        int use_count() const 
        {
            return *count_;
        }
      
        T* GetPtr() const 
        {
            return ptr_;
        }

        ~shared_ptr()
        {
            Release();
        }
};

template<class T>
class weak_ptr 
{
    private:
        T* ptr_;
    public:
        weak_ptr()
          :ptr_(nullptr)
        {}

        weak_ptr(const shared_ptr<T>& sp)
        {
            ptr_ = sp.GetPtr();
        }

        weak_ptr<T>& operator=(const shared_ptr<T>& sp)
        {
            ptr_ = sp.GetPtr();
            return *this;
        }

        T& operator*()
        {
            return *ptr_;
        }

        T* operator->()
        {
            return ptr_;
        }
};

struct ListNode
	{
		//ListNode* _next;
		//ListNode* _prev;
		//std::shared_ptr<ListNode> _next;
		//std::shared_ptr<ListNode> _prev;

		weak_ptr<ListNode> _next;
		weak_ptr<ListNode> _prev;

		int _val;

		~ListNode()
		{
			  std::cout << "~ListNode()"<< std::endl;
		}
	};


//假设我们想用智能指针来进行管理节点
void test_shared_ptr_cycle_ref()
{
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);

  std::cout << node1.use_count() << std::endl;
  std::cout << node2.use_count() << std::endl;

	// 循环引用
	node1->_next = node2;
	node2->_prev = node1;
	// ...

  std::cout << node1.use_count() << std::endl;
  std::cout << node2.use_count() << std::endl;

	//delete node1;
	//delete node2;
}
