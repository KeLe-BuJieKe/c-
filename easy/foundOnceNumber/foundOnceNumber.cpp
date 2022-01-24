/*NC156 数组中只出现一次的数（其它数出现k次）
描述
给定一个长度为 n 的整型数组 arr 和一个整数 k(k>1) 。
已知 arr 中只有 1 个数出现一次，其他的数都出现 k 次。
请返回只出现了 1 次的数。 
进阶：时间复杂度 O(32n)，空间复杂度 O(1)

示例1
输入：
[5,4,1,1,5,1,5],3 
返回值：
4 
示例2
输入：
[2,2,1],2
复制
返回值：
1
*/

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param arr intvector 
     * @param k int 
     * @return int
     */
    int foundOnceNumber(vector<int>& arr, int k) 
    {
        int ret = 0;
        int temp = 0;
        
        for(int i = 31; i >= 0; --i)
        {
            temp = 0;
            for(size_t j = 0; j < arr.size(); ++j)
            {
                temp += ((arr[j] >> i)&1);
            }
            ret = (ret << 1) + temp % k;
        }
        return ret;
    }
};
