#pragma once
#include<iostream>
#include"bitmap.h"
namespace ZJ
{
	template<class K>
	struct _HashBKDR
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};
	template<>struct _HashBKDR<std::string>
	{
		size_t operator()(const std::string& str)
		{
			size_t size = str.size();
			size_t val = 0;
			for (size_t i = 0; i < size; ++i)
			{
				val *= 131;
				val += str[i];
			}
			return val;
		}
	};

	template<class K>
	struct _HashSDBM
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};
	template<>struct _HashSDBM<std::string>
	{
		size_t operator()(const std::string& str)
		{
			size_t size = str.size();
			size_t val = 0;
			for (size_t i = 0; i < size; ++i)
			{
				val *= 65599;
				val += str[i];
			}
			return val;

		}
	};

	template<class K>
	struct _RSHash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};
	template<>struct _RSHash<std::string>
	{
		size_t operator()(const std::string& str)
		{
			size_t size = str.size();
			size_t val = 0;
			size_t magic = 63689;
			for (size_t i = 0; i < size; ++i)
			{
				val *= magic;
				val += str[i];	
				magic *= 378551;
			}
			return val;
		}
	};

	template<class K,class HashBKDR=_HashBKDR<K>,class HashSDBM=_HashSDBM<K>,class RSHash=_RSHash<K>>
	class BloomFilter //布隆过滤器
	{
	public:
		BloomFilter(size_t num):m_bm(5*num),m_size(5*num)
		{

		}
		void set(const K&val)
		{
			size_t indexBKDR = HashBKDR()(val) % m_size;
			size_t indexAP = HashSDBM()(val) % m_size;
			size_t indexRS = RSHash()(val) % m_size;
			
			m_bm.set(indexBKDR);
			m_bm.set(indexAP);
			m_bm.set(indexRS);
		}

		bool queryexist(const K& val) const
		{
			size_t indexBKDR = HashBKDR()(val) % m_size;
			size_t indexAP = HashSDBM()(val) % m_size;
			size_t indexRS = RSHash()(val) % m_size;
			
			if (! m_bm.queryexist(indexBKDR))
			{
				return false;
			}
			if (! m_bm.queryexist(indexAP))
			{
				return false;
			}
			if (! m_bm.queryexist(indexRS))
			{
				return false;
			}
			return true;

		}
	private:
		ZJ::BitMap m_bm;	//λͼ
		size_t m_size;
	};
}