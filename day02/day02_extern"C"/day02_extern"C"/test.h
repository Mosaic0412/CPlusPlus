//
//  test.h
//  day02_extern"C"
//
//  Created by 陈庆华 on 2020/3/15.
//  Copyright © 2020 陈庆华. All rights reserved.
//

#ifndef test_h

#pragma once //防止头文件重复编译

#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
void show(void);
void show2(void);

#ifdef __cplusplus
}
#endif

#endif

/*
 old：
 #pragma once
 #include <stdio.h>
 void show(void);
 */
