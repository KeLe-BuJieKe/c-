#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<assert.h>
#include<deque>


namespace ZJ
{
	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:
		void pop()
		{
			m_stack.pop_back();
		}

		void push(const T&val)
		{
			m_stack.push_back(val);
		}

		int size()	const
		{
			return static_cast<int>(m_stack.size());
		}

		T& top()	
		{
			return m_stack.back();
		}

		const T& top() const
		{
			return m_stack.back();
		}

		bool empty()	const
		{
			return m_stack.empty();
		}
	private:
		Container m_stack;
	};
}

