#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
例如，
[2,3,4] 的中位数是 3
[2,3] 的中位数是 (2 + 3) / 2 = 2.5
设计一个支持以下两种操作的数据结构：
void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

示例 1：
输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
链接：https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof
*/

class MedianFinder 
{
public:
    MedianFinder() 
    {
    }
   //思路，我们用m_smallHeap来建小堆，存储较大的部分
   //用m_bigHeap来建大堆，存储较小的部分
   //利用vector来建堆
   //始终保持m_bigHeap与m_smallHeap元素个数最多差1
   //1、当m_bigHeap与m_smallHeap元素个数相等时，我们往m_bigHeap中插入元素，并重新建成大堆
   //最后将我们堆顶最大的元素插入到m_small中，并将m_bigHeap堆顶删除，最后在分别重新建堆，m_bigHeap建大根堆，m_smallHeap建小根堆
   //2、当元素个数不相等时，即m_bigHeap.size()<m_smallHeap.size()时
   //我们往m_smallHeap中插入元素，并重新建成小根堆
   //建成新的小根堆之后，我们将新建好的小根堆的堆顶元素，即最小的那个，删除并插入到m_bigHeap中
   //最后在分别重新建堆，m_bigHeap建大根堆，m_smallHeap建小根堆
    void addNum(int num) 
    {
        if(m_bigHeap.size()!=m_smallHeap.size())
        {
            m_smallHeap.push_back(num);
            make_heap(m_smallHeap.begin(),m_smallHeap.end(), greater<int>());
            m_bigHeap.push_back(m_smallHeap.front());
            m_smallHeap.erase(m_smallHeap.begin());
            make_heap(m_smallHeap.begin(),m_smallHeap.end(), greater<int>());
            make_heap(m_bigHeap.begin(),m_bigHeap.end());
        }
        else
        {
            m_bigHeap.push_back(num);
            make_heap(m_bigHeap.begin(),m_bigHeap.end());
            m_smallHeap.push_back(m_bigHeap.front());
            m_bigHeap.erase(m_bigHeap.begin());
            make_heap(m_bigHeap.begin(),m_bigHeap.end());   //建大根堆
            make_heap(m_smallHeap.begin(),m_smallHeap.end(), greater<int>());//建小根堆
        }
    }
    
    //如果是总的元素个数为奇数，那么由于我们始终保持着m_bigHeap<m_smallHeap元素个数最多差1
    //所以当为元素个数为奇数是，m_smallHeap的小根堆堆顶，既是中间元素
    //当为偶数时，则为两个堆的堆顶相加在除2，但这里的返回值是double，所以我们这里除以2.0
    double findMedian() 
    {
        return m_bigHeap.size()!=m_smallHeap.size()?m_smallHeap.front():(m_bigHeap.front()+m_smallHeap.front())/2.0;
    }

private:
    vector<int>m_bigHeap; //大根堆，用来存储较小的部分
    vector<int>m_smallHeap;//小根堆，用来存储较大的部分

};

int main()
{
  return 0;
}
