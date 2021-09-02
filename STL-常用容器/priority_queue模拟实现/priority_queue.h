#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<assert.h>
namespace ZJ
{
	template<class T>
	class less
	{
	public:
		bool operator() (const T& x, const T& y) const
		{
			return x < y;
		}
	};

	template<class T>
	class greater
	{
	public:
		bool operator() (const T& x, const T& y) const
		{
			return x > y;
		}
	};
	template<class T,class Container=std::vector<T>, class Compare = ZJ::less<T>>
	class priority_queue
	{
	public:
		// 创造空的优先级队列
		priority_queue():m_priority_queue()
		{

		}

		template<class Iterator>
		priority_queue(Iterator first, Iterator last)
			: m_priority_queue(first, last)
		{
			// 将c中的元素调整成堆的结构
			int count = m_priority_queue.size();
			int root = ((count - 2) >> 1);
			for (; root >= 0; root--)
			AdjustDown(root);
		}
	public:

		//向上调整
		void AdjustUp(int child)
		{
			int parent = (child-1)>>1;
			
			while (child > 0)
			{
				if (c(m_priority_queue[parent], m_priority_queue[child]))
				{
					std::swap(m_priority_queue[parent], m_priority_queue[child]);
					child = parent;
					parent = (child - 1) >> 1;
				}
				else
				{
					break;
				}
			}

		}
		void push(const T& val)
		{
			m_priority_queue.push_back(val);
			AdjustUp(m_priority_queue.size()-1);
		}

		void AdjustDown(int parent)
		{
			int child = (parent << 1) + 1;
			int size = static_cast<int>(m_priority_queue.size());

			while (child< size)
			{
				if (child + 1 < size && c(m_priority_queue[child],m_priority_queue[child + 1]) )
				{
					++child;
				}

				if (c(m_priority_queue[parent], m_priority_queue[child]))
				{
					std::swap(m_priority_queue[parent], m_priority_queue[child]);
					parent = child;
					child = (parent << 1) + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			assert(!m_priority_queue.empty());

			std::swap(m_priority_queue[0], m_priority_queue[m_priority_queue.size()- 1]);
			m_priority_queue.pop_back();
			AdjustDown(0);
		}

		size_t size()	const
		{
			return m_priority_queue.size();
		}

		T& top()
		{
			return m_priority_queue.front();
		}

		const T& top()	const
		{
			return m_priority_queue.front();
		}

		bool empty()	const
		{
			return m_priority_queue.empty();
		}

	private:
		Container m_priority_queue;
		Compare c;
	};
}
