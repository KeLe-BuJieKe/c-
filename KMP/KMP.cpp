#include<iostream>
using namespace std;
#include<string>
#include<vector>

void GetNext(vector<int>& next,const string&sub)
{
    next[0]=-1;
    next[1]=0;
    int k=0;
    int i=1;
    int sublen=sub.size();
    while(i<sublen-1)
    {
      if(k==-1||sub[i]==sub[k])
      {
        next[i+1]=k+1;    //如果sub[i]=sub[k],那么我们的next[i+1]=k+1
        ++i;  
        ++k;
        if(sub[next[i]]==sub[i])  //优化next数组
        {
          next[i]=next[next[i]];
        }
      }
      else  //如果sub[i]!=sub[k],那么k我们就一直回溯
      {
        k=next[k];
      }
    }
}
int KMP(string str,string sub,size_t position)
{
  int strlen=(int)str.size();
  int sublen=(int)sub.size();
  if(strlen==0||sublen==0)
  {
    return -1;
  }
  if(position<0||position>=str.size())
  {
    return -1;
  }

  int i=(int)position;
  int j=0;

  vector<int>next(sublen);
  //得到next数组，并将next数组优化
  GetNext(next,sub);
  
  while(i<strlen&&j<sublen)
  {
    if(j==-1||str[i]==sub[j])
    {
      ++i;  //如果匹配，一起++
      ++j;
    }
    else //如果不匹配，则回溯倒next[j]的位置
    {
      j=next[j];
    }
  }
  //i-j得位置就是我们开始匹配的第一个字符的位置，j就等于我们的sublen
  if(j>=sublen)
  {
    return i-j;
  }
  //没有匹配返回-1
  else
  {
    return -1;
  }
}


void test()
{
  cout<<KMP("aaaaaaaaaaaab","aaaaaaaab",0)<<endl;;
  cout<<KMP("dasgfsasd","fs",0)<<endl;;
  cout<<KMP("dasgfdsadweadsasasd","dsg",0)<<endl;;
  cout<<KMP("daadsagfdsadwdeadsasasd","dsg",0)<<endl;;
  cout<<KMP("daadsagfdsadagfdhgfdkljiqweuqesdasd","dsg",0)<<endl;;
}

int main()
{
  test();
  return 0;
}
