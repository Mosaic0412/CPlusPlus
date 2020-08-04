//
//  main.cpp
//  day02_inlineFunction
//
//  Created by 陈庆华 on 2020/3/15.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 内联函数(inline function)
 
 但是在c++出现之后，使用预处理宏会出现两个问题：
    第一个在c中也会出现，宏看起来像一个函数调用，但是会有隐藏一些难以发现的错误
    第二个问题是c++特有的，预处理器不允许访问类的成员，也就是说预处理器宏不能用作为类的成员函数
 为了保持预处理宏的效率又增加安全性，而且还能像一般成员函数那样可以在类里访问自如，c++引入了内联函数。
    内联函数为了继承宏函数的效率，没有函数调用时开销，然后又可以像普通函数那样，可以进行参数，返回值类型的安全检查，
 又可以作为成员函数。
 */
#include <iostream>
using namespace std;

#define MyAdd(x,y) x+y //定义一个加法

void test01(){
    cout<<"------test 01------"<<endl;
    int ret = MyAdd(10, 20);
    int ret2 = MyAdd(10, 20) * 20; //宏要加括号(x+y)
    cout<<"ret = "<<ret<<",ret2 = "<<ret2<<endl;
}

#define MyCompare(a,b) ((a < b) ? (a) : (b)) //定义一个比较

inline void mycompare(int a,int b){
    cout<<"------mycompare------"<<endl;
    int ret = a < b ? a : b;
    cout<<"ret = "<< ret <<endl;
}

void test02(){
    cout<<"------test 02------"<<endl;
    int a = 30;
    int b = 40;
    int ret  = MyCompare(a, b);
    cout << "ret = " << ret << endl;
    int ret2 = MyCompare(++a, b); //预期结果31，实际结果32
    cout << "ret2 = " << ret2 << endl; //((++a < b) ? (++a) : (b))
}

void test03(){
    cout<<"------test 03------"<<endl;
    int c = 50;
    int d = 60;
    mycompare(++c, d);
}

//1、内联函数注意事项
inline void func(); //内联函数的申明
inline void func(){}; //如果函数实现时候，没有 inline 关键字，那么函数依然不算内联函数
//2、类内部的成员函数默认会加 inline 关键字
int main(int argc, const char * argv[]) {
    test01();
    test02();
    test03();
    return 0;
}
