//
//  main.cpp
//  day02_parameter
//
//  Created by 陈庆华 on 2020/3/15.
//  Copyright © 2020 陈庆华. All rights reserved.
//

#include <iostream>
using namespace std;

//函数的默认参数，参数后面 = ...
void func(int a = 10, int b = 10){
    cout << "a+b = " << a+b << endl;
}
void func2(int a, int b = 10){
    cout << "a+b = " << a+b << endl;
}
//如果有一个位置有了默认参数，那么从这个位置开始，从左往右必须有默认参数
//void func3(int a, int b = 10, int c){
void func3(int a, int b = 10, int c=10){
    cout << "a+b+c = " << a + b + c << endl;
}
void test01(){
    cout<<"------test 01------"<<endl;
    func();
    func2(11);
    func3(11);
    //传入参数，如果有参数，就传入参数，没有参数就默认
    func3(11,11);
}
//如果函数声明里有了 默认参数，函数实现时候必须没有
void myFunc(int a = 10, int b = 10);
void myFunc(){};

//函数 占位参数
//如果有了占位参数，函数调用的时候必须要提供这个参数
//占位参数没有什么大用途，只有重载 ++符号才有一点点用
//占位参数，可以有默认参数
void func4(int a,int){
    
}
void test02(){
    func4(10,1);
}
int main(int argc, const char * argv[]) {
    test01();
    cout << "Hello, World!\n";
    return 0;
}
