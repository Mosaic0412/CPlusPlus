//
//  main.cpp
//  day03_explicit
//
//  Created by 陈庆华 on 2020/3/19.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 * explicit *
    explicit用于修饰构造函数,防止!!!隐式转化!!!。
    是针对单参数的构造函数(或者除了第一个参数外其余参数都有默认值的多参构造)而言。
 */

#include <iostream>
using namespace std;

class MyString{
public:
    MyString(const char * str){}
    
    explicit MyString(int a){}
    
    char * mstr;
};

void test01(){
    MyString str = "Mosaic";
    MyString str2(20);
    
//    MyString str3 = 10; //error: No viable conversion from 'int' to 'MyString'
    //用途？ str2的字符串为“10” or 字符串长度为10 ？
    //隐式类型转换 MyString str3 = MyString(10);
    //如果不允许用户这么写，可以在构造函数前面加 explicit
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
