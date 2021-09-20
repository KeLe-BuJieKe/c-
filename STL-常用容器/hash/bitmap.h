#pragma once
#include<iostream>
#include<vector>
//位图---利用直接定值法，用每一位大小的空间存储每一位的值
namespace ZJ
{
	class BitMap		//位图，解决不了字符串的情况
	{
	public:
		BitMap(size_t bit=-1):m_size(0)
		{
			m_bitmap.resize(bit / 32 + 1);	//开辟足够存放数据的空间
		}

		void set(const size_t& val)
		{
			size_t index = val / 32;	//得到它在第几个整形的比特位中中
			size_t pos = val % 32;		//得到它在要存储的比特位的位置
			m_bitmap[index] |= (1 << pos);
			++m_size;
		}

		void unset(const size_t& val)
		{
			size_t index = val / 32;	//得到它在第几个整形的比特位中中
			size_t pos = val % 32;		//得到它在要存储的比特位的位置
			m_bitmap[index] &= ~(1 << pos);
			--m_size;
		}

		bool queryexist(const size_t& val)const
		{
			size_t index = val / 32;	//得到它在第几个整形的比特位中中
			size_t pos = val % 32;		//得到它在要存储的比特位的位置

			return m_bitmap[index] & (1 << pos);
		}


	public:
		std::vector<int>m_bitmap;	//按位存储的哈希表
		int m_size;	//当前哈希表中存储了多少个数据
	};
}
