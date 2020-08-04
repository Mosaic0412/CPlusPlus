//
//  point.h
//  day03_CircleAndPointCase
//
//  Created by 陈庆华 on 2020/3/18.
//  Copyright © 2020 陈庆华. All rights reserved.
//

#ifndef point_h

#pragma once
#include <iostream>
using namespace std;
class Point{
private:
    double p_X;
    double p_Y;
public:
    double get_X();
//    {
//        return p_X;
//    };
    void set_X(double x);
//    {
//        p_X = x;
//    };
    double get_Y();
//    {
//        return p_Y;
//    };
    void set_Y(double y);
//    {
//        p_Y = y;
//    };
};

#endif /* point_h */
