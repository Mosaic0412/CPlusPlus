//
//  main.cpp
//  day01_reference
//
//  Created by 陈庆华 on 2020/3/10.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 ------引用------
 int &b = a;
    &写到左侧，叫引用
 int *p = &a;
    &写到右侧，去地址
 */

#include <iostream>
using namespace std;

//1、引用基本语法 Type &别名 = 原名
void test01(){
    cout<<"------test01------"<<endl;
    int a = 10;
    int &b = a;
    b = 20;
    
    cout<<"a:"<<a<<",b:"<<b<<endl;
}

//2、引用必须初始化
void test02(){
    cout<<"------test02------"<<endl;
//    int &a; //error：Declaration of reference variable 'a' requires an initializer
    int a = 10;
    int &b = a; //引用初始化之后就不可以修改了
    int c = 20;
    
    b = c; //赋值!!!
}

//3、对数组建立引用
void test03(){
    cout<<"------test03------"<<endl;
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    //第一种方式 给数组起别名
    int (&brr)[10] = arr;
    for (int i = 0; i < 10; i++) {
        cout<<brr[i]<<" ";
    }
    cout<<endl;
    
    //第二种方式 给数组起别名
    typedef int (ArrayRet)[10]; //定义一个具有10个元素的int类型的数组
    ArrayRet & crr = arr;
    for (int i = 0; i < 10; i++) {
        cout<<crr[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    
//    test01();
//    test03();
    cout << "Hello, World!\n";
    return 0;
}
