//
//  main.cpp
//  day01_using
//
//  Created by 陈庆华 on 2020/3/7.
//  Copyright © 2020 陈庆华. All rights reserved.
//

//using 声明和 using 编译指令
#include <iostream>
using namespace std;

namespace K1 {
int K_id=10;
}

//using声明，注意避免二义性问题
void test01(){
    int K_id=20;
    //就近原则
    cout<<K_id<<endl;
    
//    using K1::K_id;
    //error:Target of using declaration conflicts with declaration already in scope【重复声明】
    //写了上一行代码 *using K1::K_id* 说明以后看到K_id是用K1下的
    //但是，编译器又有就近原则，出现二义性
    cout<<K_id<<endl;
}

//using编译指令
void test02(){
    int K_id=20;
    //using编译指令
    using namespace K1;//打开房间
    //未使用还是以 就近原则
    cout<<K_id<<endl;
}

namespace K2 {
int K_id=30;
}

void test03(){
    //打开多个包含K_id的房间，也要避免二义性问题
    using namespace K1;
    using namespace K2;
    //cout<<K_id<<endl;
    //error:Reference to 'K_id' is ambiguous,有歧义
    cout<<"K1 K_id："<<K1::K_id<<endl;
    cout<<"K2 K_id："<<K2::K_id<<endl;
    
}
int main(int argc, const char * argv[]) {
//    test01();
//    test02();
    test03();
    std::cout << "Hello, World!\n";
    return 0;
}
