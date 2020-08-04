//
//  main.cpp
//  day01_parameter
//
//  Created by 陈庆华 on 2020/3/10.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 参数的传递方式
 */

#include <iostream>
using namespace std;

//值传递
void mySwap(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}
void test01(){
    cout<<"------test01------"<<endl;
    int a = 10;
    int b = 20;
    mySwap(a,b); //值传递
    cout<<"a:"<<a<<",b:"<<b<<endl;
}

//地址传递
void mySwap2(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void test02(){
    cout<<"------test02------"<<endl;
    int a = 10;
    int b = 20;
    mySwap2(&a,&b); //地址传递
    cout<<"a:"<<a<<",b:"<<b<<endl;
}

//引用传递，类似传地址
void mySwap3(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
void test03(){
    cout<<"------test03------"<<endl;
    int a = 10;
    int b = 20;
    mySwap3(a,b); //引用传递
    cout<<"a:"<<a<<",b:"<<b<<endl;
}

//引用的注意事项
//1、引用必须引一块合法的内存空间
//2、不要返回局部变量的引用
int& doWork(){
    int a = 10; //局部变量
    return a;
}
int& doWork2(){
    static int a = 10; //静态变量
    return a;
}
void test04(){
    cout<<"------test04------"<<endl;
//    int &a = 10; //error：要有合法内存空间
    
    int &ret = doWork();
    cout<<"ret:"<<ret<<endl;
    
    int &ret2 = doWork2();
    cout<<"ret2:"<<ret2<<endl;
    
    //如果函数的返回值是引用，那么这么函数可以作为左值
    doWork2() = 1000; //doWork2()作为左值，相当于1000
}

//引用的本质：!!!在c++内部实现是一个指针常量!!!
//发现接收的是引用，内部转化为 int* const ref = &a;
void doWork3(int &ref){
    ref=100; //ref 是引用，转换为 *ref = 100
}
void test05(){
    cout<<"------test05------"<<endl;
    int a = 10;
    int &aRef = a;//自动转换为 int* const aRef = &a; 这说明引用为什么初始化
    aRef = 20; //内部发现 aRef 是引用，自动帮我们转换为：*aRef = 20;
    cout<<"a:"<<a<<endl;
    cout<<"aRef:"<<aRef<<endl;
    
    doWork3(a);
    cout<<"doWork(a):"<<a<<endl;
}

int main(int argc, const char * argv[]) {
    
//    test01();
//    test02();
//    test03();
//    test04();
    test05();
    return 0;
}
