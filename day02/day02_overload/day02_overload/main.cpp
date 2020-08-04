//
//  main.cpp
//  day02_overload
//
//  Created by 陈庆华 on 2020/3/15.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 函数重载（Overload）
 */

//C++中，函数名可以重复
//必须在同一个作用域中
//参数不同
//参数顺序不同
#include <iostream>
using namespace std;

void func(){
    cout<<"无参数func()"<<endl;
}
void func(int a){
    cout<<"有参数func(int a)"<<endl;
}
void func(double a){
    cout<<"有参数func(double a)"<<endl;
}
void func(double a, int b){
    cout<<"有参数func(double a, int b)"<<endl;
}
void func(int a, double b){
    cout<<"有参数func(int a, double b)"<<endl;
}
class Person{
    void func();
};

void test01(){
    cout<<"------test 01------"<<endl;
    func();
    func(1);
    func(1.1);
    func(1.1,2);
    func(1,1.1);
}

//返回值可以作为函数重载的条件吗？？？ 不可以！！！
//int func(int a, double b){return 1;}
//二义性，不确定调用的哪一个

//当函数重载遇到了默认参数时候，要注意避免二义性问题
void func2(int a ,int b = 10){}
void func2(int a){}

void test02(){
    cout<<"------test 02------"<<endl;
//    func2(10); // error: Call to 'func2' is ambiguous
}

//引用的重载
void func3(int & a){ //引用必须要有合法的内存空间
    cout<<"func3(int & a)"<<endl;
}
void func3(const int & a){ //const 也可以作为重载的条件
    cout<<"func3(const int & a)"<<endl;
    //int tmp = 10; const int & a = tmp;
    //开辟一个临时的空间
}
void test03(){
    cout<<"------test 03------"<<endl;
    int a = 10;
    func3(a); //调用第一个func3
    func3(10); //调用第二个func3
}
int main(int argc, const char * argv[]) {
    
//    test01();
//    test02();
    test03();
    
    cout << "Hello, World!\n";
    return 0;
}
