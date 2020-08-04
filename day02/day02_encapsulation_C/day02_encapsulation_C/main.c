//
//  main.c
//  day02_encapsulation_C
//
//  Created by 陈庆华 on 2020/3/15.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 C语言下的封装
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person{
    char pName[64];
    int pAge;
};
//要单独实现出来PersonEat
void PersonEat(struct Person *p){
    printf("%s 在吃晚饭\n",p->pName);
}
void test01(){
    printf("------test 01------\n");
    struct Person person1;
    strcpy(person1.pName, "Mosaic");
    PersonEat(&person1);
}


struct Dog{
    char dName[64];
    int dAge;
};
void DogEat(struct Dog * d){
    printf("%s 在吃狗粮\n",d->dName);
}
void test02(){
    printf("------test 02------\n");
    struct Dog dog1;
    strcpy(dog1.dName, "旺财");
    DogEat(&dog1);
    
    struct Person person2;
    strcpy(person2.pName, "老王");
    DogEat(&person2);
}
//C语言封装中，行为和属性分开处理
//类型检测不够

int main(int argc, const char * argv[]) {
    
    test01();
    test02();
    return 0;
}
