//
//  main.cpp
//  day03_DeepAndShallowCopy
//
//  Created by 陈庆华 on 2020/3/19.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 深拷贝：
    当类中有指针，并且此指针有动态分配空间，析构函数做了释放处理，往往需要自定义拷贝构造函数，自行给指针动态分配空间，深拷贝。
 浅拷贝：
    同一类型的对象之间可以赋值，使得两个对象的成员变量的值相同，两个对象仍然是独立的两个对象，这种情况被称为浅拷贝。
    一般情况下，浅拷贝没有任何副作用，但是当类中有指针，并且指针指向动态分配的内存空间，析构函数做了动态内存释放的处理，会导致内存问题。

 */

#include <iostream>
using namespace std;

class Person{
public:
    char * p_Name; //需要开辟空间
    int p_Age;
    //构造函数用来初始化属性
    Person(){}
    Person(char * name,int age) {
        p_Name = (char *)malloc(strlen(name) + 1); //开辟空间
        strcpy(p_Name, name);
        p_Age = age;
        cout << "有参构造：p_Name = " << p_Name << ", p_Age = " <<p_Age << endl;
    }
    
    //拷贝构造 系统会默认提供，只是简单的值拷贝
    //自己提供拷贝构造，原因简单的浅拷贝会释放堆区空间两次，导致挂掉
    //解决上述问题，需要z我们自己提供s拷贝构造函数m，进行深拷贝：
    Person(const Person & person){
        p_Age = person.p_Age;
        p_Name = (char *)malloc(strlen(person.p_Name) + 1); //加1，因为有一个'\0'
        strcpy(p_Name, person.p_Name);
        cout << "拷贝构造：p_Name = " << p_Name << ", p_Age = " <<p_Age << endl;;
    }
    ~Person(){
        cout << "析构函数" << endl;
        if (p_Name != nullptr) {
            free(p_Name);
            p_Name = nullptr;
        }
    }
};
void test01(){
    cout<<"------test 01------"<<endl;
    Person person1("Mosaic",23);
    Person person2(person1);
}
 
int main(int argc, const char * argv[]) {
    test01();
    
    return 0;
}
