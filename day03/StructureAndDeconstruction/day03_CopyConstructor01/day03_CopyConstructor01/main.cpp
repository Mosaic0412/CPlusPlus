//
//  main.cpp
//  day03_CopyConstructor01
//
//  Created by 陈庆华 on 2020/3/18.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 拷贝构造函数的调用时机
    对象以值传递的方式传给函数参数
    函数局部对象以值传递的方式从函数返回(vs debug模式下调用一次拷贝构造，qt不调用任何构造)
    用一个对象初始化另一个对象
 */

#include <iostream>
using namespace std;

class Person {
public:
    Person() { cout << "默认构造函数" << endl; };
    Person(int a) { cout << "有参构造函数" << endl; };
    Person(const Person & person) { cout << "拷贝构造函数" << endl; }; // 不加&，值传递，开辟，再传递，死循环
    ~Person() { cout << "析构函数" << endl; }
    int p_Age;
};

//拷贝构造调用的时机
//1、用已经创造好的对象初始化新的对象
void test01(){
    cout<<"------test 01------"<<endl;
    Person person1;
    person1.p_Age = 10;
    Person person2(person1);
}

//2、以值传递的方式给函数的参数传值
//值传递都会开销一份内存，引用构造 Person & person1就不会
void doWork(Person person1){} //Person person1 = Person(person)
void test02(){
    cout<<"------test 02------"<<endl;
    Person person;
    person.p_Age = 20;
    doWork(person);
}

//3、以值的方式传递返回局部对象，
Person doWork2(){
    Person person1;
    return person1;
}
/*
 Release 下优化成什么样? debug 模式下并没有进行这种优化
 Person person; //不调用默认构造
 doWork2(person);
 void doWork2(Person & person) {
    Person person; // 调用默认构造
 }
 */
void test03(){
    cout<<"------test 03------"<<endl;
    Person person = doWork2();
}
int main(int argc, const char * argv[]) {
//    test01();
//    test02();
    test03();
    return 0;
}
