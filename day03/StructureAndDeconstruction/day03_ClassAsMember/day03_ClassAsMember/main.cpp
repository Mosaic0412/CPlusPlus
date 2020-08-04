//
//  main.cpp
//  day03_ClassAsMember
//
//  Created by 陈庆华 on 2020/3/19.
//  Copyright © 2020 陈庆华. All rights reserved.
//

/*
 类对象作为成员
        当调用构造函数时，首先按各对象成员在类定义中的顺序（和参数列表的顺序无关）依次调用它们的构造函数，
    对这些对象初始化，最后再调用本身的函数体。也就是说，先调用对象成员的构造函数，再调用本身的构造函数。
    析构函数和构造函数调用顺序相反，先构造，后析构。
 */

#include <iostream>
using namespace std;

class Phone{
public:
    Phone() { cout<<"Phone's 默认构造函数"<<endl; }
    Phone(string name) { phone_Name = name; cout<<"Phone's 有参构造函数"<<endl; }
    ~Phone(){ cout<<"Phone's 析构函数"<<endl; }
    
    string phone_Name;
};

class Game{
public:
    Game() { cout<<"Game's 默认构造函数"<<endl; }
    Game(string name) { game_Name = name; cout<<"Game's 有参构造函数"<<endl; }
    ~Game(){ cout<<"Game's 析构函数"<<endl; }
    
    string game_Name;
};

class Person{
public:
    Person() { cout<<"Person's 默认构造函数"<<endl; }
//    |①｜Person(string name){ person_Name = name; cout<<"Person's 有参构造函数"<<endl; }
    Person(string name, string phone,string game):person_Name(name),person_Phone(phone),person_Game(game){
        cout<<"Person's 初始化列表构造函数"<<endl;
    }
    void playGame(){
        cout << person_Name << "拿着" << person_Phone.phone_Name << "玩着" << person_Game.game_Name << endl;
        /*
         Phone's 默认构造函数
         Game's 默认构造函数
         Person's 默认构造函数
         Mosaic拿着iPhone 11玩着oceanhorn 2!
         Person's 析构函数
         Game's 析构函数
         Phone's 析构函数
         */
    }
    ~Person() { cout<<"Person's 析构函数"<<endl; }
    
    string person_Name;
    Phone person_Phone;
    Game person_Game;
};

//类对象 作为 类成员 时候，构造顺序先将类对象一一构造，然后析构顺序是相反的
void test01(){
    Person person;
    person.person_Name = "Mosaic";
    /* |①｜②③--->
     Phone's 默认构造函数
     Game's 默认构造函数
     Person's 默认构造函数
     Person's 析构函数
     Game's 析构函数
     Phone's 析构函数
     */
    person.person_Phone.phone_Name = "iPhone 11";
    person.person_Game.game_Name = "oceanhorn 2";
    
    person.playGame();
}

int main(int argc, const char * argv[]) {
    test01();
    return 0;
}
