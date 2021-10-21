
/*标题：进制转换 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【进制转换】给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
输入描述：
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
输出描述：
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
示例1：
输入
7 2
111 
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int num;
    int radix;
    cin >> num >> radix;
    string ret;
    bool flag = (num < 0); //判断是否是负数
    if (num != 0)
    {
        if (flag) //如果是负数先将该负数转换成补码形式
        {
            num = (~num) + 1;
        }
        while (num)
        {
            //得到每一次模要转换的进制数的余数
            //最后将得到的一整个数组的数逆置才是我们要的答案
            int cur = num % radix;
            if (cur != 0)
            {
                if (cur < 10)
                {
                    ret += cur + '0';
                }
                else
                {
                    int temp = cur % 10;
                    ret += 'A' + temp;
                }
            }
            else
            {
                ret += '0';
            }
            num /= radix;
        }
        reverse(ret.begin(), ret.end());
        //如果是负数我们需要添加符号位
        if (flag)
        {
            ret.insert(ret.begin(), '-');
        }
        cout << ret;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
