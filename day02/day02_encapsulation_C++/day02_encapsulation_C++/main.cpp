//
//  main.cpp
//  day02_encapsulation_C++
//
//  Created by 陈庆华 on 2020/3/15.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 C++语言下的封装
 */

#include <iostream>
using namespace std;

struct Person{
    char pName[64];
    int pAge;
    
    void PersonEat(){
        cout << pName << "吃晚饭" << endl;
    }
};

struct Dog{
    char dName[64];
    int dAge;
    void DogEat(){
        cout << dName << "在吃狗粮" << endl;
    }
};

//C++封装，严格d类型转换检测，让属性和行为绑定在一起
//属性和行为作为一个整体来表示生活中的事物
//控制权限 public 公有权限、protected 保护权限、private 私有权限
void test01(){
    cout<<"------test 01------"<<endl;
    Person person1;
    strcpy(person1.pName, "老王");
    person1.PersonEat();
//    person1.DogEat(); //error: No member named 'DogEat' in 'Person'
}


//struct 和 class 是一个意思，唯一不同的是，struct 是 public，class 默认是 private
class Animal{
    //如果不声明权限，默认的权限是 private
    void AnimalEat(){
        cout<<"调用私有权限的eat()"<<endl;
    };
public:
    int aAge;
protected:
    string aHeight;
};
//私有权限，在类的外部访问不到，子类也访问不到
//保护权限，在类的外部访问不到，在类的内部、当前类的子类可以访问
//公有权限，在类的外部、类的内部都可以访问到
void test02(){
    Animal animal1;
//    animal1.AnimalEat(); //error: 'eat' is a private member of 'Animal'
    animal1.aAge = 5;
//    animal1.aHeight = "60cm"; //error: aHeight' is a protected member of 'Animal'
}

int main(int argc, const char * argv[]) {
    
    test01();
    
    return 0;
}
