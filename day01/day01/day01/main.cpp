//
//  main.cpp
//  day01
//
//  Created by 陈庆华 on 2020/3/6.
//  Copyright © 2020 陈庆华. All rights reserved.
//

#include <iostream>
using namespace std;
#include "game1.h"
#include "game2.h"

void test01(){
    //::作用域运算符
    G1::goAtk();
    goAtk();
}

//1、命名空间下可以放函数、变量、结构体、类
namespace A {
    void func();
    int m_A = 10;
    struct Person{
        
    };
    class Anima{};

    namespace B{
    int m_A = 20;
    }
}
//2、命名空间必须定义在全局作用下
//3、命名空间可以嵌套命名
void test02(){
    cout<<"作用域A下m_A："<<A::m_A<<endl;
    cout<<"作用域B下m_A："<<A::B::m_A<<endl;
}
//4、命名空间是开放的，可以临时往原先的命名空间中添加内容
namespace A { //此A命名空间与上方命名空间A进行合并
    int m_B=30;
}
void test03(){
    cout<<"作用域A下的m_B："<<A::m_B<<endl;
}
//5、匿名命名空间
//当写了无名命名空间，相当于写了 static int m_C,static int m_D
//只能在当前文件内使用
namespace {
int m_C=0;
int m_D=0;
}
//6、命名空间可以起别名
namespace veryLongName {
int m_A=40;
}
void test04(){
    //起别名
    namespace veryShortName = veryLongName;
    cout<<"veryLongName m_A："<<veryLongName::m_A<<endl;
    cout<<"veryShortName m_A："<<veryShortName::m_A<<endl;
}


int main(int argc, const char * argv[]) {
//    test01();
//    test02();
//    test03();
//    test04();
    return 0;
}
