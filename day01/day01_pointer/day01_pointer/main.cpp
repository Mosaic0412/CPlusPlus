//
//  main.cpp
//  day01_pointer
//
//  Created by 陈庆华 on 2020/3/10.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 指针的引用
 */

#include <iostream>
using namespace std;

struct Person{
    int m_Age;
};
//**p 是具体的Person对象
// *p 是对象的指针
//  p 是指针的指针
void allocatMemory(Person ** p){ //指针间接修改
    *p = (Person *) malloc(sizeof(Person));
    (*p) -> m_Age = 100;
}
void test01(){
    cout<<"------test01------"<<endl;
    //创建 Person
    Person *p = nullptr;
    //指针间接赋值
    allocatMemory(&p);
    cout<<"p m_Age:"<<p->m_Age<<endl;
    free(p);
}

//利用指针引用开辟空间
void allocatMemoryByRef(Person* &p){ //引用修改
    p = (Person *) malloc(sizeof(Person));
    p -> m_Age = 200;
}
void test02(){
    cout<<"------test02------"<<endl;
    Person * p = nullptr;
    //引用赋值，将 Person 本身传到 allocatMemoryByRef 函数中
    allocatMemoryByRef(p);
    cout<<"p m_Age:"<<p->m_Age<<endl;
    free(p);
}

int main(int argc, const char * argv[]) {
    
    test01();
    test02();
    
    std::cout << "Hello, World!\n";
    return 0;
}
