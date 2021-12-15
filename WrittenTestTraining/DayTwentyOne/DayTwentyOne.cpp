/*
1.设一个有序的单链表中有n个结点，现要求插入一个新结点后使得单链表仍然保持有序，则该操作的时间复杂度（ D ）
A O(log2n)
B O(1)
C O(n2)
D O(n)
答:这个谈到的插入操作是指不知道插入位置的时候，此时首先得找到插入到单链表的的位置，时间复杂度为O（n）
因为我们已经找到了插入点，此时插入到一个元素到单链表中所需要的时间复杂度，那么就为O(1)



2.一个栈的初始状态为空。首先将元素5，4，3，2，1 依次入栈，然后退栈一次，再将元素A,B,C,D依次入栈，
之后将所有元素全部退栈，则所有元素退栈（包括中间退栈的元素）的顺序为？( B  )
A 1DCAB2345
B 1DCBA2345
C 54321ABCD
D DCBA12345


3.设栈S和队列Q的初始状态为空，元素e1，e2，e3，e4，e5，e6依次压入栈S,一个元素出栈后即进入队列Q，
若出队列的顺序为e2,e4,e3,e6,e5,e1则栈S的容量要求最小值为( B )
A 2
B 3
C 4
D 5


4.给定下列程序，那么执行printf("%d\n", foo(20, 13));的输出结果是___D_____。
int foo(int x, int y){
  if (x <= 0 || y <= 0)
    return 1;
  return 3 * foo( x-6, y/2 );
}
A 3
B 9
C 27
D 81
答：foo(20, 13) = 3 * foo(14, 6) = 3 * 3 * foo(8, 3) = 3 * 3 * 3 * foo(2, 1) = 3 * 3 * 3 * 3 * foo(-4, 0) =3 * 3 * 3 * 3 * 1 = 81


5.在具有 2n 个结点的完全二叉树中，叶子结点个数为（ A）
A n
B n+1
C n-1
D n/2
答：完全二叉树是指除最后一层外，每一层上的结点数均达到最大值，在最后一层上只缺少右边的若干结点。
根据完全二叉树性质，如果共 2n 个结点，从根结点开始按层序用自然数 1 ， 2 ，…， 2n 给结点编号，
则编号为 n 的结点左子结点编号为 2n ，因此叶子结点编号为 n+1,n+2, … ,2n 。故叶子结点个数为 n ，
本题答案为 A 选项。


6.有权值分别为11，8，6，2，5的叶子结点生成一棵哈夫曼树，它的带权路径长度为___B____。
A 24
B 71
C 48
D 53


7.下述二叉树中,哪一种满足性质:从任一结点出发到根的路径上所经过的结点序列按其关键字有序( D )
A 二叉排序树
B 哈夫曼树
C AVL树
D 堆


8.为提高散列（Hash）表的查找效率，可以采取的正确措施是（ D ）。
Ⅰ．增大装填（载）因子
Ⅱ．设计冲突（碰撞）少的散列函数
Ⅲ．处理冲突（碰撞）时避免产生聚集（堆积）现象
A 仅Ⅰ
B 仅Ⅱ
C 仅Ⅰ、 Ⅱ
D 仅Ⅱ、 Ⅲ


9.将整数数组（7-6-3-5-4-1-2）按照堆排序的方式原地进行升序排列，请问在第一轮排序结束之后，数组的顺序是__C___。
A 2-6-3-5-4-1-7
B 6-2-3-5-4-1-7
C 6-5-3-2-4-1-7
D 1-5-3-2-4-6-7
E 5-4-3-2-1-6-7
F 5-1-3-2-4-6-7


10.要连通具有 n 个顶点的有向图，最少需要（ D ）条边。
A n+l
B n-l
C 2n
D n



11.标题：洗牌 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【洗牌】洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。 现在需要洗2n张牌，从上到下依次是第1张，第2张，第3张一直到第2n张。首先，我们把
这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），右手拿着第n+1张到第2n张（下半堆）。接着就开始洗牌的过程，先放下右手的最后一张牌，再放下左手
的最后一张牌，接着放下右手的倒数第二张牌，再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。接着把牌合并起来就可以了。 例如有6张牌，最开始牌
的序列是1,2,3,4,5,6。首先分成两组，左手拿着1,2,3；右手拿着4,5,6。在洗牌过程中按顺序放下了6,3,5,2,4,1。把这六张牌再次合成一组牌之后，我们按照从上往下
的顺序看这组牌，就变成了序列1,4,2,5,3,6。 现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。
输入描述：
第一行一个数T(T ≤ 100)，表示数据组数。对于每组数据，第一行两个数n,k(1 ≤ n,k ≤ 100)，接下来一行有2n个数a1,a2,...,a2n(1 ≤ ai ≤ 1000000000)。表示原
始牌组从上到下的序列。
输出描述：
对于每组数据，输出一行，最终的序列。数字之间用空格隔开，不要在行末输出多余的空格。
示例1：
输入
3 3 1 1 2 3 4 5 6 3 2 1 2 3 4 5 6 2 2 1 1 1 1
输出
1 4 2 5 3 6 1 5 4 3 2 6 1 1 1 1
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void shufflecards(vector<int>& arr, const int& n)
{
    stack<int>one;
    stack<int>two;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (i < n)
        {
            one.push(arr[i]);
        }
        else
        {
            two.push(arr[i]);
        }
    }
    int num = n;
    int j = 0;
    while (num--)
    {
        arr[j++] = two.top();
        two.pop();
        arr[j++] = one.top();
        one.pop();
    }
}
int main()
{
    int T;//组数
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int>arr(2 * n);
        for (int i = 0; i < 2 * n; ++i)
        {
            cin >> arr[i];
        }
        while (k--)
        {
            shufflecards(arr, n);
            reverse(arr.begin(), arr.end());
        }
        for (auto& e : arr)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}



12.标题：MP3光标位置 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【MP3光标位置】
MP3 Player因为屏幕较小，显示歌曲列表的时候每屏只能显示几首歌曲，用户要通过上下键才能浏览所有的歌曲。为了简化处理，假设每屏只能显示4首歌曲，光标
初始的位置为第1首歌。
现在要实现通过上下键控制光标移动来浏览歌曲列表，控制逻辑如下：
歌曲总数<=4的时候，不需要翻页，只是挪动光标位置。
光标在第一首歌曲上时，按Up键光标挪到最后一首歌曲；光标在最后一首歌曲时，按Down键光标挪到第一首歌曲。
其他情况下用户按Up键，光标挪到上一首歌曲；用户按Down键，光标挪到下一首歌曲。
2. 歌曲总数大于4的时候（以一共有10首歌为例）：
特殊翻页：屏幕显示的是第一页（即显示第1 – 4首）时，光标在第一首歌曲上，用户按Up键后，屏幕要显示最后一页（即显示第7-10首歌），同时光标放到最后一
首歌上。同样的，屏幕显示最后一页时，光标在最后一首歌曲上，用户按Down键，屏幕要显示第一页，光标挪到第一首歌上。
一般翻页：屏幕显示的不是第一页时，光标在当前屏幕显示的第一首歌曲时，用户按Up键后，屏幕从当前歌曲的上一首开始显示，光标也挪到上一首歌曲。光标当
前屏幕的最后一首歌时的Down键处理也类似。
其他情况，不用翻页，只是挪动光标就行。
数据范围：本题含有多组输入数据，数据组数1<=t<=5  ，命令长度 1<=s<=100 ,歌曲数量: 1<=n<=150
进阶：时间复杂度：O(n)  空间复杂度O(n)
输入描述：
输入说明：
1 输入歌曲数量
2 输入命令 U或者D
本题含有多组输入数据！

输出描述：
输出说明
1 输出当前列表
2 输出当前选中歌曲
示例1：
输入
10
UUUU
输出
7 8 9 10
7

#include<iostream>
#include<vector>
using namespace std;
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
*/