#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

class Solution 
{
public:
  /*
思路：把每一个数字转换成字符串，在将其排序
元素直接比较要有的3个条件证明
1、自反性：显然有aa=aa，所有a等于a
2、对称性：如果a小于b，则ab<ba，所有ba>ab，因此b大于a
3、传递性
字符串 xy < yx , yz < zy ，需证明 xz < zx 一定成立。
设十进制数 x, y, z 分别有 a, b, c 位，则有：（左边是字符串拼接，右边是十进制数计算，两者等价）
xy = x * 10^b + y 
yx = y * 10^a + x
则 xy < yx 可转化为：
x * 10^b + y < y * 10^a + x
x (10^b - 1) < y (10^a - 1)
x / (10^a - 1) < y / (10^b - 1)     ①

同理， 可将 yz < zy 转化为：
y / (10^b - 1) < z / (10^c - 1)     ②

将 ① ② 合并，整理得：
x / (10^a - 1) < y / (10^b - 1) < z / (10^c - 1)
x / (10^a - 1) < z / (10^c - 1)
x (10^c - 1) < z (10^a - 1)
x * 10^c + z < z * 10^a + x
∴  可推出 xz < zx ，传递性证毕
*/
    bool operator()(string x,string y)  //仿函数
    {
        return x+y<y+x; //降序
    }
    string minNumber(vector<int>& nums) 
    {
        vector<string>retarr;
        for(auto e:nums)
        {
            string temp=to_string(e);
            retarr.push_back(temp);
        }
        sort(retarr.begin(),retarr.end(),Solution());
        string ret;
        for(auto e:retarr)
        {
            ret+=e;
        }
        return ret;
    }
};

int main()
{
  return 0;
}
