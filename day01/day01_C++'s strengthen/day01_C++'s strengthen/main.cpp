//
//  main.cpp
//  day01_C++'s strengthen
//
//  Created by 陈庆华 on 2020/3/7.
//  Copyright © 2020 陈庆华. All rights reserved.
//

#include <iostream>
using namespace std;

//1、全局变量的检测增强
void test01(){
    //int a;
    int a=10; //重复定义 a 了
    cout<<a<<endl;
}

//2、函数检测增强，参数类型增强,返回值检测增强
//int getRect(w,h){}
int getRects(int w,int h){
    return w*h;
}
//函数调用参数检测增强
//void test02(){getRects(10,10,10);}
void test02(){
    getRects(10,10);
}

//3、类型转换检测增强
//void test03(){char *p = malloc(sizeof(64));} //malloc 返回值是 void*
void test03(){
    char *p = (char*)malloc(sizeof(64));
    cout<<p<<endl;
}

//4、struct 增强
struct Person{
    int m_Age;
    void plusAge(){m_Age++;}; //C语言中struct不可以加函数
};
void test04(){
    struct Person p1;//C语言必须加入struct
    Person p2;
    p1.m_Age=10;
    p1.plusAge();
    cout<<"p1.m_Age:"<<p1.m_Age<<endl;
    p2.m_Age=20;
    p2.plusAge();
    cout<<"p2.m_Age:"<<p2.m_Age<<endl;
}

//5、bool类型增强,C语言中没有bool类型
bool flag; //true or false
void test05(){
    cout<<sizeof(bool)<<endl;
}

//6、三目运算符增强
void test06(){
    int a = 10;
    int b = 20;
    cout<<"max:"<< (a>b?a:b) <<endl;
    
    (a < b ? a : b) = 100; //C语言返回的值，C++中返回的变量
    cout<< "a:"<<a<<",b:"<<b<<endl;
    
//    *(a < b ? &a : &b) = 100; //C语言可以取地址返回变量
}

//7、const增强
//C语言中，const修饰的常量是伪常量编译器会分配内存
//C++中，const不分配内存，真正的常量
const  int t7_A =20; //不能修改，全局只读区域，不可以改
void test07(){
    cout<<"------Test07:"<<endl;;
    const int t7_B = 20;
    //t7_B = 100; //错误
    int *p = (int *) & t7_B;
    /*
     编译器会临时开辟一块内存空间
     int tmp = t7_B; //tmp有内存
     int *p = (int *)&tmp; //tmp指向的是临时那块空间
     临时空间看不到，真正意义上的const修饰，用指针改了地址，值不改变
     */
    *p = 200;
    cout<<"t7_B:"<<t7_B<<", *p:"<< * p<<endl;
    cout<<"t7_A:"<<t7_A<<endl;
    
    //int arr[t7_B]; //C语言不可以初始化数组
}

void test08(){
    cout<<"------Test08:"<<endl;
    int t7_A = 20;
    const int t7_B = t7_A;
    int *p = (int *) & t7_B;
    *p = 200;
    cout<<"t7_B:"<<t7_B<<", *p:"<< * p<<endl;
    cout<<"t7_A:"<<t7_A<<endl;
}


class Teacher{
public:
    int t_Age;
};

// 对于自定数据类型，比如类对象，那么也会分配内存。
void test09(){
    Teacher teacher;
    teacher.t_Age = 10;
    
    const Teacher teacher2 = teacher;
    Teacher * teacher3 = (Teacher * ) & teacher2;
    
    cout << "teacher->age:" << teacher.t_Age << endl;
    cout << "teacher2->age:" << teacher2.t_Age << endl;
    cout << "teacher3->age:" << teacher3 -> t_Age << endl << endl;
    
    teacher3->t_Age = 21;
    
    cout << "teacher->age:" << teacher.t_Age << endl;
    cout << "teacher2->age:" << teacher2.t_Age << endl;
    cout << "teacher3->age:" << teacher3 -> t_Age << endl;

}

int main(int argc, const char * argv[]) {
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
    test07();
    test08();
//    test09();
    
    return 0;
}
