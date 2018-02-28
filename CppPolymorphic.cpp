#include <iostream>
using namespace std;

//class Base{
//public:
//	virtual void  f(){
//		cout << "Base::f()" << endl;
//	}
//	
//	virtual void  g(){
//		cout << "Base::g()" << endl;
//	}
//
//	virtual void  h(){
//		cout << "Base::h()" << endl;
//	}
//};
//
//class Derive : public Base{
//public:
//	virtual void f1(){
//		cout << "Derive::f1()" << endl;
//	}
//};

class Base1{
public:
	virtual void  f(){
		cout << "Base1::f()" << endl;
	}

	virtual void  g(){
		cout << "Base1::g()" << endl;
	}

	virtual void  h(){
		cout << "Base1::h()" << endl;
	}
};
class Base2{
public:
	virtual void  f(){
		cout << "Base2::f()" << endl;
	}

	virtual void  g(){
		cout << "Base2::g()" << endl;
	}

	virtual void  h(){
		cout << "Base2::h()" << endl;
	}
};
class Base3{
public:
	virtual void  f(){
		cout << "Base3::f()" << endl;
	}

	virtual void  g(){
		cout << "Base3::g()" << endl;
	}

	virtual void  h(){
		cout << "Base3::h()" << endl;
	}
};

class Derive : public Base1, public Base2, public Base3{
public:
	virtual void f(){
		cout << "Derive::f()" << endl;
	}

	virtual void g1(){
		cout << "Derive::g1()" << endl;
	}
};

typedef void(*pf)(void);

int main()
{
	pf Fun = NULL;

	Derive d;
	int **pVtab = (int**)&d;

	Fun = (pf)pVtab[0][0];
	Fun();

	Fun = (pf)pVtab[0][1];
	Fun();

	Fun = (pf)pVtab[0][2];
	Fun();

	Fun = (pf)pVtab[0][3];
	Fun();

	Fun = (pf)pVtab[1][0];
	Fun();

	Fun = (pf)pVtab[1][1];
	Fun();

	Fun = (pf)pVtab[1][2];
	Fun();

	Fun = (pf)pVtab[2][0];
	Fun();

	Fun = (pf)pVtab[2][1];
	Fun();

	Fun = (pf)pVtab[2][2];
	Fun();


	//Base *pb = new Derive;
	
	
	/*
	pf Fun = (pf)*((int*)*(int*)pb + 3);
	Fun();
	*/

	/*Base b;

	pf Fun[3];
	Fun[0] = (pf)*((int*)*(int*)&b + 0);
	Fun[1] = (pf)*((int*)*(int*)&b + 1);
	Fun[2] = (pf)*((int*)*(int*)&b + 2);

	Fun[0]();
	Fun[1]();
	Fun[2]();*/

	//pf Fun = (pf)*((int*)*(int*)&b + 0);
	//Fun();

	//Fun = (pf)*((int*)*(int*)&b + 1);
	//Fun();

	//Fun = (pf)*((int*)*(int*)(&b) + 2);
	//Fun();



	return 0;
}