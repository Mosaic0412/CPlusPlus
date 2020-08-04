//
//  main.cpp
//  day01_constRef
//
//  Created by 陈庆华 on 2020/3/10.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 常量引用
 */

#include <iostream>
using namespace std;

void test01(){
    cout<<"<------test01------>"<<endl;
    /*
     false: int &ref = 10; //引用了不合法的内存
     true: int a = 10; int &ref = a;
     */
    
    /*
     加入 const 后，编译器内部处理为：
     int tmp = 10;
     const int &ref = tmp;
     */
    const int &ref = 10;
    cout<<"ref:"<<ref<<endl;
    //ref = 10; //error
    //只要有!!合法内存!!的，都可以通过!!指针!!绕过检查，修改数值（除非扔到符号表里，改不掉）
    int *p = (int *)&ref;
    *p=1000;
    
    cout<<"ref_changed:"<<ref<<endl;
}

//常量引用场景，用来修饰形参
void showValue(const int &val){
//    val += 1000; //如果只想显示内容，而不修改内容，那么就用const修饰这个形参
    cout<<"val:"<<val<<endl;
}
void test02(){
    cout<<"<------test02------>"<<endl;
    int a = 10;
    showValue(a);
}

int main(int argc, const char * argv[]) {
    
//    test01();
    test02();
    
    cout << "Hello, World!\n";
    return 0;
}
