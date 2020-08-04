//
//  main.cpp
//  day02_encapsulationPrivate
//
//  Created by 陈庆华 on 2020/3/15.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 建议将成员变量设置为private
 */
#include <iostream>
#include <string>
using namespace std;

class Person{
private:
    string pName; //可读可写
    int pAge = 23; //只读
    string pLover; //只写
public:
//    void setpAge(int age){
//        pAge = age;
//    }
    int getpAge(){
        return pAge;
    }
    
    string getpName(){
        return pName;
    }
    
    void setpName(string name){
        pName = name;
    }
    
    void setpLover(string lover){
        pLover = lover;
    }
    void showLover(){
        cout<<"Lover："<<pLover<<endl;
    }
};
void test01(){
    cout<<"------test 01------"<<endl;
    Person person1;
//    person1.pAge = 10; //error: 'pAge' is a private member of 'Person'
    person1.setpName("Mosaic");
    person1.setpLover("wintersweet");
    cout<<"姓名："<<person1.getpName()<<endl<<"年龄："<<person1.getpAge()<<endl;
    person1.showLover();
}

int main(int argc, const char * argv[]) {
    test01();
    
    return 0;
}
