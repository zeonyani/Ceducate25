//250515
//1
#include <iostream>
using namespace std;
class Point {
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {  }
    friend ostream& operator<<(ostream& os, const Point& pos);
};
class Adder
{
public:
    int operator()(const int &n1, const int& n2) {return n1+n2;}
    double operator()(const double &e1, const double &e2) {return e1+e2;}
    //Point operator()(const Point& pos1, const Point& pos2) {return pos1+pos2;}
};
int main(void)
{
    Adder adder; cout << adder(1,3) << endl;
    cout << (1.2222) << endl;
    //cout << adder(Point(3,4), Point(7, 9));
    return 0;
}

//2
#include <iostream>
#include <memory>
using namespace std;
class Chulsoo{
private:
    int age;
public:
    Chulsoo(int age) : age(age){cout << "Constructor" << endl;}
    Chulsoo(){cout << "Default Constructor" << endl;}
    ~Chulsoo() {cout << "Destructor";}
    void introduce();
};
int main(void){
    Chulsoo *cspt = new Chulsoo(32);
    cspt->introduce();
    delete cspt;

    return 0;
}
void Chulsoo::introduce(){cout << "His age is " << age << endl;}

//3
#include <iostream>
#include <memory>
using namespace std;
int main(void)
{
    unique_ptr<int> ptr01 (new int(5)); // int 형 unique_ptr 선언
    auto ptr02 = std::move(ptr01); // ptr01에서 ptr02로 소유권 이전
    // unique_ptr<int> ptr03 = ptr01; -> 대입연산자를 이용한 복사는 오류 발생

    cout << ptr01 << endl;
    cout << ptr02 << "! " << endl;

    ptr02.reset(); // ptr02 가리키는 메모리 영역 삭제
    ptr01.reset(); // ptr01 가리키는 메모리 영역 삭제

    return 0;
}

//3
#include <iostream>
#include <memory>
using namespace std;
int main(void)
{
    shared_ptr<int> ptr01 (new int(5));
    cout << ptr01.use_count() << endl;
    auto ptr02(ptr01);
    cout << ptr01.use_count() << endl;
    auto ptr03 = ptr01;
    cout << ptr01.use_count() << endl;
}

//4
#include <iostream>
using namespace std;
class Person
{
private:
    int age; char name[50];
public:
    Person(int myage, const char *myname) : age(myage){strcpy(name, myname);}
    void WhatName() const {cout << "My name is " << name << endl;}
    void HowOld() const {cout << "year: " << age << endl;}
};
class UnivStu : public Person{
private:
    char major[50];
public:
    UnivStu(int myage, const char *myname,  const char *mymajor) : Person(myage, myname) {strcpy(major, mymajor);}
    void WhoAreU() const {
        WhatName(); HowOld();
        cout << "My major is " << major << endl;
    }
};

int main(void)
{
    Person man = {80, "Trumph"};
    UnivStu univ = {20,"baby Trumph", "computer"};

    man.WhatName();
    man.HowOld();
    univ.WhoAreU();

    return 0;
}

//5
#define MAX 50
#include <iostream>
#include <string>
using namespace std;

class StringCharArray : public std::string
{
public:
    StringCharArray(const char* s) : std::string(s) {}

    void toCharArray(char *str);
};

void StringCharArray::toCharArray(char *str)
{
    int len = this->length();

    for (int i = 0; i < len; ++i) {
        *(str + i) = this->at(i);
    }

    *(str + len) = '\0';
}

int main(void)
{
    StringCharArray customString = "Hello, World!";
    int length = customString.length();
    char* charArray = new char[length + 1];
    customString.toCharArray(charArray);

    cout << charArray << endl;

    delete[] charArray;
    charArray = nullptr;

    return 0;
}

//6
#include <iostream>
using namespace std;
class CON1{
public:
    CON1(const int c);
    ~CON1();
protected:
    int c;
};
CON1::CON1(const int c)
{
    this->c=c;
    cout << "***CON1 Constructor***" << endl;
    cout << "c = " << c << endl;
}
CON1::~CON1() = default;
//CON1::~CON1(){
//cout << "~~~DESTRUCTOR~~~" << endl;
//}
int main(void)
{
    CON1 *p = new CON1(5);
    delete p;
    return 0;;
}

//7
#include <iostream>
using namespace std;
class CON1{
public:
    CON1();
    ~CON1();
};
class CON2:public CON1{
public:
    CON2();
    ~CON2();
};
CON1::CON1(){cout << "con1 constructor" << endl;}
CON1::~CON1() {cout << "con1 destructor" << endl;}
CON2::CON2() {cout << "con2 constructor" << endl;}
CON2::~CON2() {cout << "con2 destructor" << endl;}

int main(void)
{
    CON2 *ptest = new CON2(); //생성자는 상속받은 con1, con2순으로 만들어지고 반대로 소멸자는 본인인 con2부터 사라지고 상속받은 거 사라짐
    delete ptest;
    return 0;
}

//8
#include <iostream>
using namespace std;
class CON1{
public:
    CON1(const int c);
    ~CON1();
};
class CON2:public CON1{
public:
    CON2();
    ~CON2();
};
CON1::CON1(const int c){cout << "con1 constructor" << endl;}
CON1::~CON1() {cout << "con1 destructor" << endl;}
CON2::CON2():CON1(300) {cout << "con2 constructor" << endl;} // 이렇게 써주면 CON2()그냥 썼을 때 문제 없음
// CON1에는 디폴트 생성자가 존재하지 않으므로 CON2에서 명시적으로 CON1(int)를 :를 이용해서 호출해 줘야 한다.
CON2::~CON2() {cout << "con2 destructor" << endl;}

int main(void)
{
    CON2 *ptest = new CON2;
    delete ptest;
    return 0;
}

//9
#include <iostream>
using namespace std;
class SoBase{
private:
    int baseNum;
public:
    SoBase() : baseNum(20) {cout << "SoBase() " << endl;}
    SoBase(int m) : baseNum(m) {cout << "SoBase(int n)" << endl;}
    void ShowBaseData() {cout << baseNum << endl;}
};
class SoDerived : public SoBase{
private:
    int derivNum;
public:
    SoDerived() : derivNum(30) {cout << "derivNum()" << endl;}
    SoDerived(int n) : derivNum(n) {cout << "deriveNum(n)" << endl;}
    SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2) { cout << "SoDerived(int n1, int n2)" << endl;}
    void ShowDerivData() {ShowBaseData(); cout << derivNum << endl;}
};
int main(void)
{
    cout << "case1..." << endl;
    SoDerived dr1;
    dr1.ShowDerivData();
    cout << "-----------------" << endl;

    cout << "case2..." << endl;
    SoDerived dr2(12);
    dr2.ShowDerivData();
    cout << "-----------------" << endl;

    cout << "case3..." << endl;
    SoDerived dr3(23, 34);
    dr3.ShowDerivData();
    cout << "-----------------" << endl;
    return 0;
}

//10
#include <iostream>
#include <string>
using namespace std;
class GeometricFig
{
public:
    GeometricFig();
    GeometricFig(const string col);
    void SetColor(const string col);
    bool IsPaint();
    string GetColor();
protected:
    string color;
};
GeometricFig::GeometricFig(){color = "white";}
GeometricFig::GeometricFig(const string col) {this->color = col;}
void GeometricFig::SetColor(const string col) {this->color = col;}
bool GeometricFig::IsPaint() {return (color=="white")? false : true;}
string GeometricFig::GetColor() {return color;}

int main(void)
{
    GeometricFig ob1;
    cout << "obj color :" << ob1.GetColor() << endl;
    ob1.SetColor("pink");
    cout << "ob1 color " << ob1.GetColor() << endl;
    return 0;
}

//11
#include <iostream>
using namespace std;
class First{
public: void MyFunc() {cout<<"First Func"<< endl;}
};
class Second: public First{
public: void MyFunc() {cout << "Second Func" << endl;}
};
class Third: public Second{
public: void MyFunc() {cout << "Third Func" << endl;}
};
int main(void)
{
    Third *tp = new Third(); // Third형 만들어지고 그게 tp에 할당
    Second *sp = tp; // 그걸 다시 Second 형 포인터에 할당하고
    First *fp = sp; // 결국 처음꺼, 두번째꺼, 세번째꺼 모두 같은 Third형 객체를 가리키고 있다.

    fp->MyFunc(); // First 타입 호출
    sp->MyFunc(); // Second 타입
    tp->MyFunc(); // Third 타입
    delete tp;
    return 0;
}

//12
#include <iostream>
#include <string>
using namespace std;
class AbstractClass{
public:
    virtual string SampleFunc() = 0;
};
class TestClass:public AbstractClass{
public:
    string SampleFunc(){return "SampleFunction";}
};
int main(void)
{
    //AbstractClass ob1; //추상 클래스는 객체를 만들 수 없다!
    //cout << ob1.SampleFunc() << endl;

    TestClass ob2;
    cout << ob2.SampleFunc() << endl;
    return 0;
}
*/
//13
#include <iostream>
using namespace std;
class First{
public:
    void MyFunc() {cout<<"First Func"<< endl;}
    virtual ~First() = default;
};
class Second: public First{
public:
    void MyFunc() {cout << "Second Func" << endl;}
    virtual ~Second() = default;
};
class Third: public Second{
public:
    void MyFunc() {cout << "Third Func" << endl;}
    virtual ~Third() = default;
};
int main(void)
{
    Third *tp = new Third();
    Second *sp = tp;
    First *fp = sp;

    fp->MyFunc();
    sp->MyFunc();
    tp->MyFunc();
    delete tp;
    return 0;
}
