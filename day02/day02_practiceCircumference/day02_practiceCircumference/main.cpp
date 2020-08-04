//
//  main.cpp
//  day02_practiceCircumference
//
//  Created by 陈庆华 on 2020/3/14.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 设计一个类，求圆的周长
 */

#include <iostream>
using namespace std;

const double pi = 3.14;

class Circle{ //圆类
public:
    double r; //半径，成员属性
    double getCircumference(){ //求周长的成员函数
        return 2 * r * pi;
    }
    void setR(double c_r){ //设置半径的成员函数
        r = c_r;
    }
};

void test01(){
    cout<<"------test 01------"<<endl;
    //通过类，来创建一个圆
    Circle circle1; //圆 circle1（对象）
    circle1.r = 10.2;
    cout<<"圆 circle1 的周长："<<circle1.getCircumference()<<endl;
}

void test02(){
    cout<<"------test 02------"<<endl;
    //通过成员函数，间接设置半径
    Circle circle2;
    circle2.setR(12.4);
    cout<<"圆 circle2 的周长："<<circle2.getCircumference()<<endl;
}
int main(int argc, const char * argv[]) {
    
    test01();
    test02();
    
    cout << "Hello, World!\n";
    return 0;
}
