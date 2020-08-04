//
//  circle.h
//  day03_CircleAndPointCase
//
//  Created by 陈庆华 on 2020/3/18.
//  Copyright © 2020 陈庆华. All rights reserved.
//

#ifndef circle_h

#pragma once
#include <iostream>
#include <math.h>
using namespace std;
#include "point.h"

class Circle{
private:
    double c_R; //半径
    Point c_Center; //圆心
public:
    double get_R();
//    {
//        return c_R;
//    }
    void set_R(double r);
//    {
//        c_R = r;
//    }
    Point get_Center();
//    {
//        return c_Center;
//    }
    void set_Center(Point p);
//    {
//        c_Center = p;
//    }
    
    //利用成员函数判断 点和圆的关系
    void IsInCircle(Point & point);
//    {
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
};

#endif /* circle_h */
