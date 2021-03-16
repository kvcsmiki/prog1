#include <iostream>
#include <fstream>

class B1 {
public:
	virtual void vf() const
			{ std::cout << "B1::vf\n";}
	void f() const { std::cout << "B1::f\n"; }
	virtual void pvf() = 0;
};

class D1 : public B1 {
public:	
	void vf() const override 
		{ std::cout << "D1::vf\n";}
	void f() const
		{ std::cout << "D1::f\n";}
};

class D2 : public D1{
public:
	void pvf() override
		{std::cout << "D2::pvf\n";}
};

class B2{
public:
	virtual void pvf() = 0;
};

class D21 : public B2{
public:
	void pvf() override {std::cout << "D21::pvf\n" << jajaj << "\n";}
private:
	int jajaj = 22;
};
class D22 : public B2{
public:
	void pvf() override {std::cout << "D22::pvf\n" << hehej << "\n";}
private:
	int hehej = 22;
};

void f(B2& b){
	b.pvf();
}


int main()
{
	/*B1 b;
	b.vf();
	b.f();

	D1 d;
	d.vf();
	d.f();

	B1& bref{d};
	bref.vf();
	bref.f();*/

	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);
	return 0;
}