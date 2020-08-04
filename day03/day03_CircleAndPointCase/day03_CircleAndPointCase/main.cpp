//
//  main.cpp
//  day03_CircleAndPointCase
//
//  Created by 陈庆华 on 2020/3/18.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 设计一个圆形类（AdvCircle），和一个点类（Point），计算点和圆的关系。
 假如圆心坐标为x0, y0, 半径为r，点的坐标为x1, y1：
 1）点在圆上：(x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) == r*r
 2）点在圆内：(x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) < r*r
 3）点在圆外：(x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) > r*r
 */

#include <iostream>
#include <math.h>
#include "circle.h"
#include "point.h"
using namespace std;


//！！！！！！分文件写！！！！！！
//class Point{
//private:
//    double p_X;
//    double p_Y;
//public:
//    double get_X(){
//        return p_X;
//    }
//    void set_X(double x){
//        p_X = x;
//    }
//    double get_Y(){
//        return p_Y;
//    }
//    void set_Y(double y){
//        p_Y = y;
//    }
//};

//class Circle{
//private:
//    double c_R; //半径
//    Point c_Center; //圆心
//public:
//    double get_R(){
//        return c_R;
//    }
//    void set_R(double r){
//        c_R = r;
//    }
//    Point get_Center(){
//        return c_Center;
//    }
//    void set_Center(Point p){
//        c_Center = p;
//    }
//
//    //利用成员函数判断 点和圆的关系
//    void IsInCircle(Point & point){
//        //获取圆心和点的距离
//        double distance = pow(c_Center.get_X() - point.get_X(), 2) + pow(c_Center.get_Y() - point.get_Y(), 2);
//        distance = sqrt(distance);
//        if (distance == c_R) {
//            cout << "点在圆上" << endl;
//        } else if (distance > c_R){
//            cout << "点在圆外" << endl;
//        } else {
//            cout << "点在圆内" << endl;
//        }
//    }
//};

//全局函数 判断点和圆的距离
void IsInCircle(Circle & circle, Point & point){
    //获取圆心和点的距离
    double distance = pow(circle.get_Center().get_X() - point.get_X(), 2) + pow(circle.get_Center().get_Y() - point.get_Y(), 2);
    distance = sqrt(distance);
    if (distance == circle.get_R()) {
        cout << "点在圆上" << endl;
    } else if (distance > circle.get_R()){
        cout << "点在圆外" << endl;
    } else {
        cout << "点在圆内" << endl;
    }
}

void test01(){
    cout << "------test 01------" << endl;
    Point point1;
    point1.set_X(3.8);
    point1.set_Y(2);
    
    Point center1;
    center1.set_X(2);
    center1.set_Y(2);
    
    Circle circle1;
    circle1.set_R(2);
    circle1.set_Center(center1);
    
    //全局函数
    cout << "全局函数：";
    IsInCircle(circle1, point1);
    //成员函数
    cout << "成员函数：";
    circle1.IsInCircle(point1);
}

int main(int argc, const char * argv[]) {
    test01();
    return 0;
}
