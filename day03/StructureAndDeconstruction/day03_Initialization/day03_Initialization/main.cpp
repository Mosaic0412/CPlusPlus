//
//  main.cpp
//  day03_Initialization
//
//  Created by 陈庆华 on 2020/3/18.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 * 初始化 *
 构造函数和析构函数，这两个函数将会被编译器自动调用，完成对象初始化和对象清理工作。
 对象的初始化和清理工作是编译器强制我们要做的事情，即使你不提供初始化操作和清理操作，编译器也会给你增加默认的操作。
 只是这个默认初始化操作不会做任何事，所以编写类就应该顺便提供初始化函数。
 */

#include <iostream>
using namespace std;

class Person{
public:
    //构造函数的写法
    //与类名相同，没有返回值，不写void，可以重载(可以有参数)
    //自动调用，只调用一次
    Person(){
        cout << "无参数构造函数" << endl;
    }
    
    //析构函数写法
    //与类名相同，类名前加一个符号“～”，没有返回值，不写void，不可以有参数，不可以重载
    //自动调用，只调用一次
    ~Person(){
        cout << "析构函数" << endl;
    }
};

void test01(){
    cout << "------test 01 start------" << endl;
    //默认调用了构造和析构，是系统提供的两个空实现的函数
    Person person1;
    cout << "------test 01 end------" << endl;
}

int main(int argc, const char * argv[]) {
    cout << "------main start------" << endl;
    test01();
    Person person2;
    cout << "------main end------" << endl;
    return 0;
}
