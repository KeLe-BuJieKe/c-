#pragma once
#include<iostream>
#include<vector>
//λͼ---����ֱ�Ӷ�ֵ������ÿһλ��С�Ŀռ�洢ÿһλ��ֵ
namespace ZJ
{
	class BitMap		//λͼ����������ַ��������
	{
	public:
		BitMap(size_t bit=-1):m_size(0)
		{
			m_bitmap.resize(bit / 32 + 1);	//�����㹻������ݵĿռ�
		}

		void set(const size_t& val)
		{
			size_t index = val / 32;	//�õ����ڵڼ������εı���λ����
			size_t pos = val % 32;		//�õ�����Ҫ�洢�ı���λ��λ��
			m_bitmap[index] |= (1 << pos);
			++m_size;
		}

		void unset(const size_t& val)
		{
			size_t index = val / 32;	//�õ����ڵڼ������εı���λ����
			size_t pos = val % 32;		//�õ�����Ҫ�洢�ı���λ��λ��
			m_bitmap[index] &= ~(1 << pos);
			--m_size;
		}

		bool queryexist(const size_t& val)const
		{
			size_t index = val / 32;	//�õ����ڵڼ������εı���λ����
			size_t pos = val % 32;		//�õ�����Ҫ�洢�ı���λ��λ��

			return m_bitmap[index] & (1 << pos);
		}


	public:
		std::vector<int>m_bitmap;	//��λ�洢�Ĺ�ϣ��
		int m_size;	//��ǰ��ϣ���д洢�˶��ٸ�����
	};
}
