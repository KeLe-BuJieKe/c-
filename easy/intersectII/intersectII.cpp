/*350. 两个数组的交集 II
给定两个数组，编写一个函数来计算它们的交集。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
示例 2:

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]

链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
*/


#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    //利用map容器来分别来得到各个容器中的元素的出现的次数
    //在利用双指针法，如果key值相同那么那么根据该数在两个数组中出现的最小次数，push_back到结果数组中
    //那个小，那么指针就往后走
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int,int>m1;
        size_t sizeNum1=nums1.size();
        for(size_t i=0;i<sizeNum1;++i)
        {
            m1[ nums1[i] ]++;
        }

        size_t sizeNum2=nums2.size();
        map<int,int>m2;
        for(size_t i=0;i<sizeNum2;++i)
        {
            m2[ nums2[i] ]++;
        }

        map<int,int>::iterator it1=m1.begin();
        map<int,int>::iterator it2=m2.begin();
        vector<int>retV;
        while( it1 != m1.end() && it2 != m2.end() )
        {
            if ( it1->first > it2->first)
            {
                ++it2;
            }
            else if (it1->first < it2->first)
            {
                ++it1;
            }
            else
            {
                size_t size=min(it1->second,it2->second);
                while(size--)
                {
                    retV.push_back(it1->first);
                }
                ++it1;
                ++it2;
            }
        }
        return retV;
    }
};
