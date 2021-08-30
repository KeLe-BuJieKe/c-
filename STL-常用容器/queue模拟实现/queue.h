#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>
namespace ZJ
{
	template<class T,class Container=deque<T>>
	class queue
	{
	public:
		void pop()
		{
			m_queue.pop_front();
		}

		void push(const T& val)
		{
			m_queue.push_back(val);
		}

		size_t size()	const
		{
			return static_cast<size_t>(m_queue.size());
		}

		T& back()
		{
			return m_queue.back();
		}

		const T& back() const
		{
			return m_queue.back();
		}

		T& front()
		{
			return m_queue.front();
		}

		const T& front() const
		{
			return m_queue.front();
		}

		bool empty()	const
		{
			return m_queue.empty();
		}
	private:
		Container m_queue;
	};
}