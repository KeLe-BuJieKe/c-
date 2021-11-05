#include<iostream>
#include<vector>
using namespace std;


/*1-区分两种情况，小于等于4，大于4
2-小于等于4比较好弄，输出所有列表，然后加减光标
3-大于4比较麻烦，区分好特殊情况，做一个移动的框框（upboundary，downboundary），刚开始的时候，upboundary等于1，downboundary=4
4-通过判断第一个移动动作，上或者下，然后调整框框的upboundary和downboundary，当upboundary或者downboundary向上突破1，或者向下突破最大的输入数，立即根据规则切换，
5-另外光标在upboundary和downboundary中移动时，upboundary和downboundary不变
6-或者光标在移动过程中，突破了upboundary和downboundary，也要根据规则改变upboundary和downboundary
7-以上就是所有情况，注意顺序不能变，这是关键*/
int main()
{
    int n;
    string str;
    while (cin >> n >> str)
    {
        vector<int>arr;
        int index = 0;
        for (int i = 0; i < n; ++i)
        {
            arr.push_back(i + 1);
        }
        int upboundary = 0;
        int downboundary = 3;
        if (n <= 4)
        {
            downboundary = n - 1;
            for (auto& ch : str)
            {
                if (ch == 'U')
                {
                    --index;
                    if (index < 0)
                    {
                        index = n - 1;
                    }
                }
                else
                {
                    ++index;
                    if (index >= n)
                    {
                        index = 0;
                    }
                }
            }
        }
        else
        {
            for (auto& ch : str)
            {
                if (ch == 'U')
                {
                    if (upboundary == index)
                    {
                        --upboundary;
                        if (upboundary < 0)
                        {
                            upboundary = n - 4;
                            index = n - 1;
                            downboundary = upboundary + 3;
                        }
                        else
                        {
                            --downboundary;
                            --index;
                        }
                    }
                    else
                    {
                        --index;
                    }
                }
                else
                {
                    if (downboundary == index)
                    {
                        ++downboundary;
                        if (downboundary >= n)
                        {
                            downboundary = 3;
                            index = 0;
                            upboundary = downboundary - 3;
                        }
                        else
                        {
                            ++index;
                            upboundary++;
                        }
                    }
                    else
                    {
                        ++index;
                    }
                }
            }
        }
       

        for (int i = upboundary; i <= downboundary; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl << arr[index] << endl;
    }


    return 0;
}
