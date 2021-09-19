#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int>temp1;
        for (auto& e : nums1)
        {
            temp1[e] = e;
        }
        unordered_map<int, int>temp2;
        for (auto& e : nums2)
        {
            temp2[e] = e;
        }
        vector<int>ret;
        for (auto &e:temp1)
        {
            if (temp2.find(e.first) != temp2.end())
            {
                ret.push_back(e.second);
            }
        }
        return ret;
    }
};

int main()
{
  return 0;
}
