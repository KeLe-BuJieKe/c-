#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
void test()
{
    //1.包含头文件
    //#include<fstream>

    //2.创建流对象
    ifstream ifs;

    //3.打开文件，并且判断是否打开成功
    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    //4.读数据
    //第一种方法
   /* char buf[1024] = { 0 };
    while (ifs >> buf)
    {
        cout << buf << endl;
    }*/

    //第二种方法
    //char buf[1024] = { 0 };
    //while (ifs.getline(buf,sizeof(buf)))   //getline()这个是成员函数表示的是获取一行     
                                   //第一个参数表示把数据放到那个地方，正好我们的数组名指向的就是第一个元素的首地址   
    //                                     //第二个参数表示的是我们最多要读多少个字节数
    //{
    //    cout << buf << endl;
    //}

    //第三种方法
    string buf;
    while (getline(ifs, buf))                            //这里的getline是全局函数
                                                         //第一个参数表示的是输入流对象
                                                         //第二个参数表示的是把读取到的数据放刀buf中
    {
        cout << buf << endl;
    }

    //第四种方法  不推荐这种，运行效率慢，因为是一个一个读
    //char c;
    //while ((c = ifs.get()) != EOF)
    //{
    //    cout << c;
    //}

    //5.关闭文件
    ifs.close();
}
int main()
{
    test();
    system("pause");
    return 0;
}