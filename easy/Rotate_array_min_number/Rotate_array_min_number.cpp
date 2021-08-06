#include<iostream>
#include<vector>
using namespace std;
/*把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
 * */
class Solution 
{
public:
/*找题眼，看到递增排序的数组，第一反应就是用二分查找
 * 1.numbers[mid]<numbers[right];如果中间的mid位置的值比right的值小，则说明mid位置到right这段区间内是属于第二个递增区间内的，
 此时我们把区间缩小到[left,mid]，为什么是mid而不是mid-1呢？
 这是因为如果mid这个位置是第二个区间最小的元素也就是我们要找的最小的元素时就会出错
 *2.numbers[mid]>numbers[right]如果中间的mid位置的值比right的值大，
 这说明最小的值在mid到right的区间内，所以我们缩小范围到[mid+1,right]
 *3.numbers[mid]==numbers[right],此时有可能该位置是我们的最小值但不能这么笃定，此时我们就小心一点，将区间缩小一格[left,right-1]
 那么为什么不使用left+=1呢？例如[1,3,3]这种情况时，我们的mid=1，此时相等如果把left+=1的话我们最小的值就会被跳过
 s */
    int minArray(vector<int>& numbers) 
    {
        int left=0;
        int right=numbers.size()-1;
        while(left<right)
        {
            int mid = left +((right - left) >> 1);
            if(numbers[mid]<numbers[right])
            {
                right=mid;
            }
            else if(numbers[mid]>numbers[right])
            {
                left=mid+1;
            }
            else
            {
                right-=1;
            }

        }
        return numbers[right];
    }
};

//测试代码
int main()
{
    vector<int>v{3,4,5,1,2};
    Solution s;
    cout<< s.minArray(v)<<endl;
    return 0;
}
