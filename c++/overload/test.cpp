/**
 * @file 
 *  * @author xiaoguodong 1799553128@qq.com
 *   * @date 
 *    * @brief
 *     **/

#include <iostream>
using namespace std;

class A{}; 
class B:public A{};

class C
{
public:
    virtual void func1()
    { cout << "C::func1()" << endl; }

    virtual A* func2()
    {
        cout << "C::func2()" << endl;
        return new A;

    } 

    virtual A& func3()
    {
        cout << "C::func3()" << endl;
        return *(new A);        
        // 这里返回的必须是一个堆对象（heap object），
        //             // 而不能是栈对象（stack object）或者叫局部对象
        //                         // 因为栈对象会在函数退出时被销毁，皮之不存毛将焉附
        //                                     // 对象都不存在了，引用自然无所适从 
        //                                         
    }

    void showFunc4()
    {
        func4();

    }

    virtual void func5() const
    {
        cout << "C::func5()" << endl;

    }

    virtual A func6()
    {
        cout << "C::func6()" << endl;

    }

private:
    virtual void func4()
    {
        cout << "C::func4()" << endl;

    }

};

class D:public C
{
public:
    // 构成重写
    void func1()
    {
        cout << "D::func1()" << endl;
    }
    // 返回值的类型是父类返回值类型的子类的指针，构成重写
    B* func2()
    {
        cout << "D::func2()" << endl;
        return new B;
    } 
    // 返回值的类型是父类返回值类型的子类的引用，构成重写
    B& func3()
    {
        cout << "D::func3()" << endl;
        return *(new B);
    }

    // 可以对访问修饰符进行重写
    void func4()
    {
        cout << "D::func4()" << endl;
    }

    // 不构成重写
    void func5() 
    {
        cout << "D::func5()" << endl;
    }
    // 无法通过编译 
    //B func6()
    //{ 
    //  cout << "D::func6()" << endl;
    //}
};

int main(int, char**)
{
    C* c = new D;       // 父类指针指向子类对象
    c->func1();
    c->func2();
    c->func3();
    c->showFunc4();
    c->func5();
    return 0;
}


