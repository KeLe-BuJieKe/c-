#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
void test()
{
    //1.����ͷ�ļ�
    //#include<fstream>

    //2.����������
    ifstream ifs;

    //3.���ļ��������ж��Ƿ�򿪳ɹ�
    ifs.open("test.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    //4.������
    //��һ�ַ���
   /* char buf[1024] = { 0 };
    while (ifs >> buf)
    {
        cout << buf << endl;
    }*/

    //�ڶ��ַ���
    //char buf[1024] = { 0 };
    //while (ifs.getline(buf,sizeof(buf)))   //getline()����ǳ�Ա������ʾ���ǻ�ȡһ��     
                                   //��һ��������ʾ�����ݷŵ��Ǹ��ط����������ǵ�������ָ��ľ��ǵ�һ��Ԫ�ص��׵�ַ   
    //                                     //�ڶ���������ʾ�����������Ҫ�����ٸ��ֽ���
    //{
    //    cout << buf << endl;
    //}

    //�����ַ���
    string buf;
    while (getline(ifs, buf))                            //�����getline��ȫ�ֺ���
                                                         //��һ��������ʾ��������������
                                                         //�ڶ���������ʾ���ǰѶ�ȡ�������ݷŵ�buf��
    {
        cout << buf << endl;
    }

    //�����ַ���  ���Ƽ����֣�����Ч��������Ϊ��һ��һ����
    //char c;
    //while ((c = ifs.get()) != EOF)
    //{
    //    cout << c;
    //}

    //5.�ر��ļ�
    ifs.close();
}
int main()
{
    test();
    system("pause");
    return 0;
}