#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<assert.h>
#include<iostream>
using namespace std;
namespace  ZJ
{
	
	class string
	{
		friend ostream& operator<< (ostream& os, const string& str);
		friend istream& operator>> (istream& is, string& str);
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		const static  size_t npos;
	public:
		string(const char* str="")
		{
			// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
			if (str == nullptr)
			{
				assert(false);
			}
			this->m_size = strlen(str);
			if (this->m_size <=15)
			{
				this->m_capacity = 15;
				
			}
			else
			{
				this->m_capacity = strlen(str);
			}
			this->m_str = new char[this->m_capacity + 1];
			strcpy(this->m_str, str);
		}

		string(const string& str) : m_str(new char[str.m_capacity + 1]), m_capacity(str.m_capacity), m_size(str.m_size)
		{
			strcpy(this->m_str, str.m_str);
		}

		void swap(string& str)
		{
			std::swap<size_t>(this->m_capacity, str.m_capacity);
			std::swap<size_t>(this->m_size, str.m_size);
			std::swap<char*>(this->m_str, str.m_str);
		}
		string& operator =(string& str)
		{
			if (this != &str)
			{
				string temp(str);
				swap(temp);
			}
			return *this;
		}

		~string()
		{
			if (this->m_str != nullptr)
			{
				delete[]this->m_str;
				this->m_str = nullptr;
			}
		}

		const_iterator c_str() const
		{
			return this->m_str;
		}

		size_t size() const
		{
			return this->m_size;
		}

		size_t capacity() const
		{
			return this->m_capacity;
		}

		bool empty() const
		{
			return this->m_size==0;
		}

		char& operator[](size_t index)
		{
			assert(index < this->m_size);
			return this->m_str[index];
		}

		const char& operator[](size_t index) const 
		{
			assert(index < this->m_size);
			return this->m_str[index];
		}

		char& at(size_t pos)
		{
			assert(pos < this->m_size);
			return this->m_str[pos];
		}

		const char& at(size_t pos) const
		{
			assert(pos < this->m_size);
			return this->m_str[pos];
		}

		//删除从pos开始的n个字符
		string& erase(size_t pos = 0, size_t len =string::npos)
		{
			assert(pos <this->size());
			if (pos + len >= this->m_size)
			{
				this->m_size = pos;
				this->m_str[pos] = '\0';
			}
			else
			{
				for (size_t i = pos,j= pos + len; i<size()&&j<size(); ++i,++j)
				{
					this->m_str[i] = this->m_str[j];
				}
				this->m_size -= len;
				this->m_str[this->m_size] = '\0';
			}
			return *this;
		}

		// 在pos位置上插入字符c/字符串str
		string& insert(size_t pos, size_t n,const char c)
		{
			assert(pos <= this->size());
			int len = this->m_size;
			this->m_size += n;
			if (this->m_size > this->m_capacity)
			{
				reserve(this->m_size*2);
			}

			memmove(begin() + pos + n, begin() + pos, len-pos);
			for (size_t i = pos; i < pos + n; ++i)
			{
				this->m_str[i] = c;
			}
			return *this;
		}

		string& insert(size_t pos, const string& str)
		{
			assert(pos <= this->size());
			string temp = *this;
			int len = temp.m_size;
			temp.m_size += str.m_size;
			if (temp.m_size > this->m_capacity)
			{
				temp.reserve(this->m_size * 2);
			}
			memmove(temp.begin() + pos + str.m_size, temp.begin() + pos, len - pos);
			memmove(temp.begin() + pos, str.m_str, str.m_size);
			swap(temp);
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= this->size());
			string temp = *this;
			int len = this->m_size;
			temp.m_size += strlen(str);
			if (temp.m_size > this->m_capacity)
			{
				temp.reserve(temp.m_size * 2);
			}
			memmove(temp.begin() + pos + strlen(str), temp.begin() + pos, len - pos);
			memmove(temp.begin() + pos, str, strlen(str));
			swap(temp);
			return *this;
		}

		void reserve(size_t n = 0)
		{
			if (n > this->m_capacity)
			{
				char* str = new char[n + 1];
				strncpy(str,this->m_str,this->m_size+1);
				delete[] this->m_str;
				this->m_str = str;
				this->m_capacity=n;
			}
		}

		void resize(size_t n, char c='\0')
		{
			if (n > this->m_size)
			{
				if (n>this->m_capacity)
				{
					reserve(n);
				}
				while (n - this->m_size)
				{
					push_back(c);
				}
			}
			else
			{
				this->m_size = n;
				this->m_str[this->m_size] = '\0';
			}
		}
		string& append(const char ch)
		{
			this->push_back(ch);
			return *this;
		}

		string& append(const char* str)
		{
			int len = this->m_size + strlen(str);
			if (len > this->m_capacity)
			{
				reserve(len * 2);
			}
			strcpy(this->m_str + this->m_size, str);
			this->m_size = len;
			return *this;
		}

		string& append(const string& str)
		{
			int len= this->m_size + str.size();
			
			if (len > this->m_capacity)
			{
				reserve(len * 2);
			}
			strcpy(this->m_str + this->m_size, str.m_str);
			this->m_size=len;
			return *this;
		}

		string& operator+=(const char ch)
		{
			this->push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			this->append(str);
			return *this;
		}

		string& operator+=(const string& str)
		{
			this->append(str);
			return *this;
		}

		iterator begin()	//起始迭代器
		{
			return this->m_str;
		}

		iterator end()		//结束迭代器
		{
			return this->m_str + this->m_size;
		}


		char& back()		//获得最后一个元素
		{
			return this->m_str[this->m_size - 1];
		}

		char& front()	//获得第一个元素
		{
			return this->m_str[0];
		}

		void push_back(char c)	//尾插
		{
			if (this->m_size == this->m_capacity)		//此时已满
			{
				reserve(this->m_capacity * 2);
			}
			this->m_str[this->m_size++] = c;
			this->m_str[this->m_size] = '\0';
		}

		void pop_back()		//尾删
		{
			this->m_str[--this->m_size] = '\0';
		}

		void clear()		//清空
		{
			this->m_size = 0;
			this->m_str[this->m_size] = '/0';
		}

		bool operator< (const string &str) const
		{
			if (strcmp(this->m_str, str.m_str) < 0)
			{
				return true;
			}
			return false;
		}
		
		bool operator==(const string& str) const
		{
			if (strcmp(this->m_str, str.m_str) ==0)
			{
				return true;
			}
			return false;
		}

		bool operator>(const string& str) const
		{
			if (strcmp(this->m_str, str.m_str)>0)
			{
				return true;
			}
			return false;
		}


		bool operator<=(const string& str) const
		{
			if (!(*this > str))
			{
				return true;
			}
			return false;
		}


		bool operator>=(const string& str) const
		{
			if (!(*this < str))
			{
				return true;
			}
			return false;
		}

		bool operator!=(const string& str) const
		{
			if (!(*this == str))
			{
				return true;
			}
			return false;
		}

		// 返回c在string中第一次出现的位置
		size_t find(const char c, size_t pos = 0) const
		{
			for (size_t i = pos; i < this->size(); ++i)
			{
				if (this->m_str[i] == c)
				{
					return i;
				}
			}
			return npos;
		}

		// 返回子串s在string中第一次出现的位置
		size_t find(const char* str, size_t pos = 0) const
		{
			assert(pos < this->m_size);
			int index = 0;
			size_t i = pos, j = 0;
			while( i < size() && j<strlen(str))
			{
				if (this->m_str[i] == str[j])
				{
					++i, ++j;
				}
				else
				{
					i = ++index;
					j = 0;
				}
			}
			
			return j==strlen(str)?index:string::npos;
		}
	private:
		char* m_str;			
		size_t m_size;		//个数
		size_t m_capacity;	//容量
	};
	const size_t string::npos = -1;

	ostream& operator<< (ostream& os, const string& str)
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			os << str.m_str[i];
		}
		return os;
	}

	istream& operator>> (istream& is, string& str)
	{
		str.clear();

		char ch;
		ch = is.get();
		while (ch==' '|| ch  == '\n')
		{
			ch = is.get();
		}
		while (ch != ' ' && ch != '\n')
		{
			str.push_back(ch);
			ch = is.get();
		}

		return is;
	}

	istream& getline(istream& is, string& str)
	{
		str.clear();
		char ch;
		ch = is.get();
		while (ch == '\n')
		{
			ch = is.get();
		}
		while (ch != '\n')
		{
			str.push_back(ch);
			ch = is.get();

		}
		return is;
	}
}

int main()
{
	ZJ::string const s="123";
	ZJ::string s1 = "123";
	ZJ::string s2 = "123";
	//cout<<s1.find("231")<<endl;
	//s1.resize(20);
	//ZJ::getline(cin, s1);
	s1 += '1';
	s2 += '4';
	cout <<s1<< endl;
	cout <<s2 << endl;
	system("pause");
	return 0;
}