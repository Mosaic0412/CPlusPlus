//
//  main.cpp
//  day03_CubeCase
//
//  Created by 陈庆华 on 2020/3/18.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 设计立方体类(Cube)，
 求出立方体的面积( 2*a*b + 2*a*c + 2*b*c )和体积( a * b * c)，
 分别用全局函数和成员函数判断两个立方体是否相等。
 */
#include <iostream>
using namespace std;
void isIf(bool ret);
class Cube{
private:
    double cube_L;
    double cube_W;
    double cube_H;
public:
    void set_L(double L){
        cube_L = L;
    }
    double get_L(){
        return cube_L;
    }
    void set_W(double W){
        cube_W = W;
    }
    double get_W(){
        return cube_W;
    }
    void set_H(double H){
        cube_H = H;
    }
    //double get_H() const {
    double get_H(){
        return cube_H;
    }
    
    //求长方体面积
    void getCubeArea(){
        cout << "立方体面积：" << (cube_L * cube_W + cube_L * cube_H + cube_W * cube_H) * 2 << endl;
    }
    
    //求长方体体积
    void getCubeVolume(){
       cout << "立方体体积：" << cube_L * cube_W * cube_H << endl;
    }
    
    //通过成员函数判断是否相等
    bool isEqual(Cube & cube2){
        return (cube_L == cube2.get_L() && cube_W == cube2.get_W() && cube_H == cube2.get_H());
    }
};

void test01(){
    cout << "------test 01------" <<endl;
    Cube cube1;
    cube1.set_L(10);
    cube1.set_W(10);
    cube1.set_H(10);
    cube1.getCubeArea();
    cube1.getCubeVolume();
}

//通过全局函数判断是否相等
bool isEqual(Cube & cube1, Cube & cube2){ //引用传递，没有开销，直接使用的原数据
    if(cube1.get_H() == cube2.get_H() && cube1.get_W() == cube2.get_W() && cube1.get_L() == cube2.get_L()){
        return true;
    }
    else
        return false;
}

void test02(){
    cout << "------test 02------" <<endl;
    Cube cube1;
    Cube cube2;
    cube1.set_W(11);
    cube1.set_H(11);
    cube1.set_L(11);
    cube2.set_W(11);
    cube2.set_H(21);
    cube2.set_L(11);
    
    //全局函数
    cout << "全局函数：";
    isIf(isEqual(cube1, cube2));
    //成员函数
    cout << "成员函数：";
    isIf(cube1.isEqual(cube2));
}

void isIf(bool ret){
    if (ret == true) {
        cout << "cube1 和 cube2 相等" << endl;
    }
    else {
        cout << "cube1 和 cube2 不相等" << endl;
    }
}
//不能保证成员函数是否修改了成员属性
//void func(const Cube & cube){ //除非 get_H() 后面也加上 const，都是不能修改
void func(Cube & cube){
    cube.get_H(); //error: this' argument to member function 'get_H' has type 'const Cube', but function is not marked const
}

int main(int argc, const char * argv[]) {
    
//    test01();
    test02();
    
    return 0;
}
