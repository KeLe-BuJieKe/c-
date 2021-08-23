#include<iostream>
using namespace std;
#include<vector>
/*输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]
链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof
*/


class Solution 
{
public:
    //建一个数量为K的大根堆，然后将剩余的小于堆顶数字的数字更换堆顶，并重新建堆
    void AdjustBigHeap(vector<int>&arr,const int &size,int parent) //调整为大根堆
    {
        int child=parent*2+1;
        while(child<size)
        {
            if(child+1<size&&arr[child]<arr[child+1])   //判断左右孩子那个大
            {
                ++child;
            }

            if(arr[child]>arr[parent])  //判断左右孩子中最大的，是否大于父节点，如果大于则需要进去交换
            {
                swap(arr[child],arr[parent]);
                parent=child;
                child=parent*2+1;
            }
            else    //如果不大于则退出
            {
                break;
            }

        }
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        int size=(int)arr.size();
        if(k==0||size==0)
        {
            return {};
        }
        vector<int>ret(arr.begin(),arr.begin()+k);
        
        for(int i=(k/2)-1;i>=0;--i)
        {
            AdjustBigHeap(ret,k,i);
        }

        for(int i=k;i<size;++i)
        {
            if(arr[i]<ret[0])
            {
                ret[0]=arr[i];
                AdjustBigHeap(ret,k,0);
            }
        }
        return ret;
    }   
};


int main()
{
  return 0;
}
