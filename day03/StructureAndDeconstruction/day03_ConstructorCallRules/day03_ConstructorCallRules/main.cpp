//
//  main.cpp
//  day03_ConstructorCallRules
//
//  Created by 陈庆华 on 2020/3/18.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 * 构造函数调用规则 *
 默认情况下，c++编译器至少为我们写的类增加3个函数
    1．默认构造函数(无参，函数体为空)
    2．默认析构函数(无参，函数体为空)
    3．默认拷贝构造函数，对类中非静态成员属性简单值拷贝
 如果用户定义了普通构造(非拷贝)，c++不在提供默认无参构造，但是会提供默认拷贝构造
 如果用户定义拷贝构造函数，c++不会再提供任何默认构造函数
 */

#include <iostream>
using namespace std;

class Person{
public:
    //Person() { cout << "默认构造函数" << endl; };
    Person(int a) { cout << "有参构造函数" << endl; };
    Person(const Person & person) { cout << "拷贝构造函数" << endl; }; // 不加&，值传递，开辟，再传递，死循环
    ~Person() { cout << "析构函数" << endl; }
    int p_Age;
};


void test01(){
//    Person person1; //error：No matching constructor for initialization of 'Person'
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
