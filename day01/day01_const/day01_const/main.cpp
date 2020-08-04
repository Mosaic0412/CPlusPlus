//
//  main.cpp
//  day01_const
//
//  Created by 陈庆华 on 2020/3/7.
//  Copyright © 2020 陈庆华. All rights reserved.
//

#include <iostream>
using namespace std;
const int MAX = 1024; //尽量以 const 替换 #define

//1、const分配内存，取地址会分配内存
void test01(){
    cout<<"---test01:"<<endl;
    const int t1_A = 10;
    int *p = (int*)&t1_A;
    cout<<*p<<endl;
}
//2、extern编译器也会给const变量分配内存
//3、用变量初始化const的变量
void test03(){
    cout<<"---test03:"<<endl;
    int a = 10;
    
    const int b = a; //会分配内存，数值可以改变
    int *p = (int *)&b;
    *p = 1000;
    cout<<"b："<<b<<"，p："<<*p<<endl;
    
    const int c = 20; //不分配内存，不会改变数值
    int *q = (int *)&c;
    *q=2000;
    cout<<"c："<<c<<"，q："<<*q<<endl;
}
//4、自定义数据类型,加 const 也会分配内存
struct Person{
    string m_Name;
    string m_Age;
};
void test04(){
    cout<<"---test04:"<<endl;
    const Person p1;
    
//    //p1.m_Name="Mosaic"; //error：No viable overloaded '='
        Person * p = (Person*)&p1;
        p->m_Name = "Mosaic";
        (*p).m_Age = "18"; //两种表达方式
        cout<<"Name:"<<p1.m_Name<<",Age:"<<p1.m_Age<<endl;
}

int main(int argc, const char * argv[]) {
    
    //C语言中const默认是外部链接
    //C++中const默认是内部链接
    /*
     外部文件 test.c:
            const int a = 10;
     //告诉编译器a在外部
     extern const int a;
     printf("%d\n",a);
     */
    extern const int a;
    cout<<"a:"<<a<<endl;
    
//    test03();
    test04();
    
    cout << "Hello, World!\n";
    cout << MAX<<endl;
    return 0;
}
