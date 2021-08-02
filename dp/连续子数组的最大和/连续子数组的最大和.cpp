#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using  namespace std;


class Solution
{
public:
    /*
    dp��̬�滮
    ��f[i]��ʾ�Ե�i�����ֽ�β������������͡�
                  {    nums[i]                          i=0����ret[i-1]+nums[i]<=nums[i]
    ״̬���̣�f[i]={
                  {   ret[i]=nums[i]+ret[i-1]           ret[i-1]+nums[i]>nums[i]
    ���״̬���̵����壺
    �񡢵��Ե�i-1�����ֽ�β�����������������ֵĺ�С��nums[i]ʱ�����������������i�����ۼӣ�
    ��õ��Ľ���ȵ�i�����ֱ���ҪС����������������Ե�i�����ֽ�β����������ǵ�i�����ֱ���
    ������Ե�i-1�����ֽ�β�����������������ֵĺʹ���nums[i]ʱ�����ڵ�i�������ۼӾ͵õ���
    ��i�����ֽ�β�����������������ֵĺ͡�
    */
    int maxSubArray(vector<int>& nums)
    {
        vector<int>ret(nums.size(), 0);
        int summax = INT_MIN;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (i == 0 || ret[i - 1] + nums[i] <= nums[i])
            {
                ret[i] = nums[i];
            }
            else    //(ret[i-1]+nums[i]>nums[i])
            {
                ret[i] = nums[i] + ret[i - 1];
            }
            summax = max(ret[i], summax);
        }
        return  summax;
    }
};

int main()
{
	system("pause");
	return 0;
}