//
//  main.cpp
//  day03_InitializationList
//
//  Created by 陈庆华 on 2020/3/19.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 * 初始化列表 *
 构造函数和其他函数不同，除了有名字，参数列表，函数体之外还有初始化列表。
 注意：初始化成员列表(参数列表)只能在构造函数使用。
 */
#include <iostream>
using namespace std;

class Person{
public:
//    Person(){}
    //有参构造，初始化数据
//    Person(int a,int b,int c){
//        p_A = a;
//        p_B = b;
//        p_C = c;
//    }
    //利用初始化列表 初始化数据
    //构造函数 : 属性(参数),属性(参数)...
    
    Person() : p_A(11), p_B(21), p_C(31) {
        cout << "p_A = " << p_A << ", p_B = " << p_B << ", p_C = " << p_C << endl;
    }
    Person(int a, int b, int c):p_A(a),p_B(b),p_C(c){
        cout << "p_A = " << p_A << ", p_B = " << p_B << ", p_C = " << p_C << endl;
    }

    int p_A;
    int p_B;
    int p_C;
};
void test01(){
    cout<< "------test 01------" << endl;
    cout<<"person1: ";
    Person person1(10,20,30);
    cout<<"person2: ";
    Person person2;
}

int main(int argc, const char * argv[]) {
    test01();
    return 0;
}
