//
//  main.cpp
//  day03_SortAndCall
//
//  Created by 陈庆华 on 2020/3/18.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 构造函数的分类及调用
 */

//按参数类型：分为无参构造函数和有参构造函数
//按类型分类：普通构造函数和拷贝构造函数(复制构造函数)

#include <iostream>
using namespace std;

class Person{
public:
    int p_Age;
    //构造和析构必须写在public下才可以调用
    Person(){
        cout << "默认构造函数" << endl;
    }
    Person(int a){
        cout<<"a = "<<a<<endl;
        cout << "有参构造函数" << endl;
    }
    //拷贝构造函数 !!!!! const !!!!!
    Person(const Person & person){
        p_Age = person.p_Age;
        cout << "拷贝构造函数" << endl;
    }
};

void test01(){
    cout<<"------test 01 start------"<<endl;
    //构造函数调用
    //1、括号法
    cout<<"------括号法调用"<<endl;
    Person person1(10);
    person1.p_Age = 20;
    Person person2(person1);
    cout<<"person1的年纪："<<person1.p_Age<<endl;
    cout<<"person2的年纪："<<person2.p_Age<<endl;
    cout<<"------test 01 end------"<<endl;
    Person person3; //默认构造函数，不加括号；编译器会认为是函数的声明
    //2、显示法调用
    cout<<"------显示法调用"<<endl;
    Person person4 = Person(30);
    Person person5 = Person(person4);
    
    //如果编译器发现对象是匿名的，那在这行代码结束后就释放这个对象
    Person(40); //匿名对象
    //不能用拷贝构造函数 初始化匿名对象
//    Person(person5); //error: Redefinition of 'person5',编译器认为你写成了Person person5；可以写成右值
    
    Person person6 = 100; //相当于调用了Person person6 = Person(100)，隐式z类型转换
}
int main(int argc, const char * argv[]) {
    cout<<"------main start------"<<endl;
    
    test01();
    
    cout<<"------main end------"<<endl;
    return 0;
}
