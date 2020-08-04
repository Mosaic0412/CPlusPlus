//
//  main.cpp
//  day02_extern"C"
//
//  Created by 陈庆华 on 2020/3/15.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 extern "C" 浅析，在C++中调用C语言中的代码
 */

#include <iostream>
#include "test.h"
using namespace std;

//方法一：C++中想要调用C语言方法
//extern "C" void show(); //不用包含.h头文件
//方法二：更改 test.h 头文件
/*
 #ifdef __cplusplus
 extern "C"{
 #endif

 ...

 #ifdef __cplusplus
 }
 #endif
 */

int main(int argc, const char * argv[]) {
    
    //在C++中，函数是可以发生重载的，编译器会把这个函数名偷偷改变，eg. _showv
    show();
    show2();
    
    return 0;
}
