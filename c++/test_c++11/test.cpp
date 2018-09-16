/**
 * @file 
 * @author xiaoguodong 1799553128@qq.com
 * @date 
 * @brief
 **/

#include <iostream>
#include <string>
using namespace std;

// 接口类
class IShape{
public:
    virtual float Area() = 0;
    virtual string Name() = 0;
};

class Circle: public IShape{
public:
    Circle(float r):m_area(3.14*r*r){}
    virtual ~Circle(){}

    float Area(){
        return m_area;
    }

    string Name(){
        return string("circle");
    }
private:
    float m_area;
};

class Square: public IShape{
public:
    Square(float l):m_area(l*l){}
    virtual ~Square(){}

    float Area(){
        return m_area;
    }

    string Name(){
        return string("square");
    }
private:
    float m_area;
};

void ShowShape(IShape *shape){
    cout << "name: " << shape->Name() << endl;
    cout << "area: " << shape->Area() << endl;
}

int main()
{
    Circle c(10);
    Square s(10);
    ShowShape(&c);
    ShowShape(&s);

    return 0;
}
