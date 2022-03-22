
/*
第一题：函数calc计算围棋中位置(x,y)处连成一片的棋子个数。所谓连成一片，即沿着棋盘横竖线往任意方向遍历，遍历过程允许转弯，不允许走斜线，中间未出现对方棋子或空子。

enum color {
    NONE, WHITE, BLACK,         // 棋子颜色，NONE表示未落子
};
struct weiqi {
    enum color board[19][19];   // 棋盘上每个位置的落子
};
int calc(struct weiqi *wq, int x, int y)
{
}
*/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
enum color {
    NONE, WHITE, BLACK,         //棋子颜色，NONE表示未落子
};
struct weiqi {
    enum color board[19][19];   //棋盘上每个位置的落子
};

//深度优先遍历，从起始位置开始的一连串相同颜色的联通位置
int Dfs(struct weiqi* wq, int x, int y, const int& color)
{
    if(x < 0 || y < 0 || x > 19 || y > 19 || wq->board[x][y] != color)
    {
        return 0;
    }
    
    int count = 1;
    wq->board[x][y] = NONE;
    count += Dfs(wq, x + 1, y, color);
    count += Dfs(wq, x - 1, y, color);
    count += Dfs(wq, x, y + 1, color);
    count += Dfs(wq, x, y - 1, color);
    return count;
}

int calc(struct weiqi *wq, int x, int y)
{
    if(wq->board[y][x] == NONE)
    {
        return 0;
    }
    return Dfs(wq, y, x, wq->board[y][x]);
}
int input(struct weiqi *wq, int *x, int *y)
{
    int row, col;
    int ret;
    char buf[80];
    
    for (row = 0; row < 19; ++row) {
        if (fgets(buf, sizeof(buf), stdin) == NULL)
            return -1;
        if (strlen(buf) < 19)
            return -1;
        for (col = 0; col < 19; ++col) {
            switch (buf[col]) {
            case '0':
                wq->board[row][col] = NONE;
                break;
            case '1':
                wq->board[row][col] = WHITE;
                break;
            case '2':
                wq->board[row][col] = BLACK;
                break;
            default:
                return -1;
            }
        }
    }
    ret = fscanf(stdin, "%d,%d\n", x, y);
    if (ret != 2)
        return -1;
    for (row = 0 ; row < 19; ++row) {
        for (col = 0; col < 19; ++col) {
            fprintf(stderr, "%d ", wq->board[row][col]);
        }
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "x = %d, y = %d\n", *x, *y);
    return 0;
}

int main()
{
    struct weiqi wq;
    int x = 0, y = 0;
    int cnt;

    memset(&wq, 0, sizeof(wq));
    if (input(&wq, &x, &y) < 0) {
        fprintf(stderr, "error!\n");
        return 1;
    }
    cnt = calc(&wq, x, y);

    printf("%d\n", cnt);
    return 0;
}


/*
第二题：请实现list_sort，使用冒泡法将head指向的链表按val值大小排成升序
struct node {
    int val;
    struct node *next;
};
void list_sort(struct node *head)
{
}
*/

#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <algorithm>
struct node {
    int val;
    struct node *next;
};

static void list_sort(struct node *head);

struct node *list_create(int arr[], int size)
{
    struct node *head = NULL;
    int i;
    for (i = size - 1; i >= 0; --i) {
        struct node *p = (struct node *)malloc(sizeof(struct node));

        p->val = arr[i];
        p->next = head;
        head = p;
    }
    return head;
}
static void list_print(struct node *head)
{
    for (; head; head = head->next) {
        printf("%d", head->val);
        if (head->next)
            printf(" ");
    }
    printf("\n");
}
static void list_free(struct node *head)
{
    struct node *next;
    while (head) {
        next = head->next;
        free(head);
        head = next;
    }
}
static int input(int **arr, int *size)
{
    int i;
    int ret;

    ret = fscanf(stdin, "%d\n", size);
    if (ret != 1)
        return -1;
    *arr = (int *)malloc(sizeof(int) * (*size));
    for (i = 0; i < *size; ++i) {
        fscanf(stdin, "%d ", &(*arr)[i]);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    struct node *head;
    int *arr = NULL;
    int size = 0;

    if (input(&arr, &size) < 0) {
        fprintf(stderr, "input error\n");
        return 0;
    }
    head = list_create(arr, size);
    list_sort(head);
    list_print(head);
    list_free(head);
    free(arr);
    return 0;
}

//链式冒泡排序
static void list_sort(struct node *head)
{
    for (struct node* cur = head; cur != nullptr; cur = cur->next)
    {
        for (struct node* next = cur->next; next != nullptr; next = next->next)
        {
            if(cur->val > next->val)
            {
                std::swap(cur->val, next->val);
            }
        }
    }
    
}


/*
第三题：已知某一个字母序列，把序列中的字母按出现顺序压入一个栈，在入栈的任意过程中，允许栈中的字母出栈，求所有可能的出栈顺序
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

//全排列
void Dfs(std::vector<std::string>& arr, std::string& path, std::vector<bool>& flag, const std::string& str)
{
    size_t size = str.size();
    if (path.size() == size)
    {
        arr.push_back(path);
        return;
    }
    
    for(size_t i = 0; i < size; ++i)
    {
        if(flag[i] == false)
        {
            path.push_back(str[i]);
            flag[i] = true;
            Dfs(arr, path, flag, str);
            flag[i] = false;
            path.pop_back();
        }
    }
}

//判断是否是出战序列
bool IsPopOrder(std::string& in, std::string& out)
{
    std::stack<char> st;
    int pushindex = 0;
    int popindex = 0;
    int pushsize = static_cast<int>(in.size());
    while (pushindex < pushsize)
    {
        st.push(in[pushindex]);
        while (!st.empty() && st.top() == out[popindex])
        {
            st.pop();
            ++popindex;
        }
        ++pushindex;
    }
    return st.empty();
}

//打印序列
void print(std::vector<std::string>& arr, std::string& str)
{
    size_t size = arr.size();
    for (size_t i = 0; i < size; ++i)
    {
        if(IsPopOrder(str, arr[i]))
        {
            std::cout << arr[i] << std::endl;
        }
    }
}

int main()
{
    std::string str;
    std::cin >> str;
    std::vector<std::string> arr;
    std::string path;
    std::vector<bool> flag(str.size());
    Dfs(arr, path, flag, str);
    print(arr, str);
    
    return 0;
}

