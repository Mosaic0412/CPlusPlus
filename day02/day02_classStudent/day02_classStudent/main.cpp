//
//  main.cpp
//  day02_classStudent
//
//  Created by 陈庆华 on 2020/3/15.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 • 类是对对象的抽象
 • 对象是对类的实例

 设计一个学生类，属性有姓名和学号，
 可以给姓名和学号赋值，可以显示学生的姓名和学号
 */
#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    string sName;
    string sId;
    
    void setName(string name){
        sName = name;
    }
    void setId(string id){
        sId = id;
    }
    
    void showStudentInformation(){
        cout<<"学生姓名："<<sName<<"，学号"<<sId<<endl;
    }
};

void test01(){
    cout<<"------test 01------"<<endl;
    //创建一个学生，实例化————通过类来创建对象的过程
    Student student1;
    student1.setName("Mosaic");
    student1.setId("2015150217");
    student1.showStudentInformation();
}

int main(int argc, const char * argv[]) {
    
    test01();
    
    cout << "Hello, World!\n";
    return 0;
}
