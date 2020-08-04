//
//  main.cpp
//  day03_New
//
//  Created by 陈庆华 on 2020/3/19.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 1)    程序员必须确定对象的长度。
 2)    malloc返回一个void*指针，c++不允许将void*赋值给其他任何指针，必须强转。
 3)    malloc可能申请内存失败，所以必须判断返回值来确保内存分配成功。
 4)    用户在使用对象之前必须记住对他初始化，构造函数不能显示调用初始化(构造函数是由编译器调用)，用户有可能忘记调用初始化函数。

 */

#include <iostream>
using namespace std;

class Person {
public:
    Person() { cout << "默认构造函数" << endl; }
    ~Person(){ cout << "析构函数" << endl; }
    Person(int a){ cout << "有参构造函数" << endl; }
};

void test01(){
    //栈区开辟
    Person person1;
    //堆区开辟，不会释放
    Person * person2 = new Person;
    /*  所有 new 出来的对象，都会返回该类型的指针  */
    //malloc 返回 void* 还要强转
    //malloc 会调用构造吗？不会！ new 会调用构造
    //new 运算符，malloc 函数
    //释放堆区域的空间
    delete person2;
}

void test02(){
    void * person = new Person;
    //当用 void * 接收 new 出来的指针，会出现释放问题
//    delete person; //warning: Cannot delete expression with pointer-to-'void' type 'void *'
    //无法释放person，所以要避免这种写法
}

/*
 当创建一个对象数组的时候，必须对数组中的每一个对象调用构造函数，
 除了在栈上可以聚合初始化，必须提供一个默认的构造函数。
 */
void test03(){
    //堆区开辟空间注意事项，创建堆上对象数组必须提供构造函数
    Person * pArray = new Person[10]; //调用了10个构造
    //通过 new 开辟数组，一定会调用默认构造函数，所以一定要提供默认构造函数
    
    //栈上开辟空间注意事项，栈聚合初始化
    Person pArray2[3] = {Person(11),Person(21),Person(31)};
    //栈上开辟数组，可以指定有参构造
    
    //释放数组，delete []
    delete[] pArray;
    //如果在new表达式中使用[]，必须在相应的delete表达式中也使用[]
    //如果在new表达式中不使用[], 一定不要在相应的delete表达式中使用[]
}

int main(int argc, const char * argv[]) {
//    test01();
    test02();
//    test03();
    return 0;
}
