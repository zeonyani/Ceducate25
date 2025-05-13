//250513
//1
#include <iostream>
using namespace std;
#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 10
#define CHARACTER_LEN 20

class Chulsoo{
private:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;

public:
    Chulsoo(const char*name, const char*sex, const char*job, const char*character, int age, bool marriageStatus){
        cout << "CS class constructor START" << endl;
        strcpy_s(this->name, name);
        strcpy_s(this->sex, sex);
        strcpy_s(this->job, job);
        strcpy_s(this->character, character);
        this->age = age;
        this->marriageStatus = marriageStatus;
        cout << "END" << endl;
    }
    Chulsoo(){
        cout << "I MADE" << endl;
    }
    void eat(const char*food){
        cout << "Chulsoo eats " << food << endl;
    }
    void sleep(){
        cout << "Chulsoo sleeps." << endl;
    }
    void drive(const char *destination){
        cout << "Chulsoo drives to " << destination << endl;
    }
    void introduce();
};

class Younghee{
private:
private:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;
public:
    Younghee(const char*name, const char*sex, const char*job, const char*character, int age, bool marriageStatus){
        strcpy_s(this->name, name);
        strcpy_s(this->sex, sex);
        strcpy_s(this->job, job);
        strcpy_s(this->character, character);
        this->age = age;
        this->marriageStatus = marriageStatus;
        cout << "The End~" << endl;
    }
    Younghee(){
        cout << "I made~" << endl;
    }
};

class DailyLife{
private:
    Chulsoo cs;
    Younghee yh;
public:
    DailyLife(const char * csN, const char*csS, const char *csJ, const char *csC, int csA, bool csM, const char * yhN, const char*yhS, const char *yhJ, const char *yhC, int yhA, bool yhM)\
        :cs(csN, csS, csJ, csC, csA, csM), yh(yhN, yhS, yhJ, yhC, yhA, yhM){
        cout << "Daily Life Constructor MADE!" << endl;
    }
    void run(){
        cs.drive("restaurant");
        cs.eat("steak");
    }
};

int main(void)
{
    DailyLife dalf("anchulsoo", "Male", "developer", "cute", 32, true, "yunghee", "Female", "anchor", "kind", 28, false);
    dalf.run();
    return 0;
}
void Chulsoo::introduce(){
    cout << "name : " << name << endl;
    cout << "gender : " << sex << endl;
    cout << "job : " << job << endl;
    cout << "char : " << character << endl;
    cout << "age : " << age << endl;
    cout << "marriage : " << marriageStatus << endl;
}

//2
#include <iostream>
#include <cstring>
using namespace std;
class Person{
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage){
        int len = strlen(myname)+1;
        strcpy(name, myname);
        age = myage;
    }
    void ShowPersonInfo() const
    {
        cout << "NAME: " << name << endl;
        cout << "AGE : " << age << endl;
    }
    ~Person()
    {
        delete []name;
        cout << "called destructor!" << endl;
    }
};

//3
#include <iostream>
#include <cstring>
using namespace std;
class MyProfile{
private:
    string name;
public:
    MyProfile(string n){
        name.append(n);
    }
    void setName(string n){
        name.clear();
        name.append(n);
    }
    void getName(){
        cout << "name : " << name << endl;
    }
};
int main(void)
{
    MyProfile pf1("allen");
    pf1.getName();

    MyProfile *ptrPF1 = new MyProfile("andrew");
    ptrPF1->getName();
    delete ptrPF1;
    return 0;
}

//4
#include <iostream>
using namespace std;
class SoSimple{
private:
    int n1, n2;
public:
    SoSimple(int x, int y) : n1(x), n2(y)
    {}
    void ShowSimpleData()
    {
        cout << n1 << endl;
        cout << n2 << endl;
    }
};
int main(void)
{
    SoSimple sim1(15, 20); // 실제 멤버 대 멤버의 복사가 일어남
    SoSimple sim2=sim1;
    sim2.ShowSimpleData();

    return 0;
}

//5
#include <iostream>
using namespace std;
class SoSimple{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {}
    SoSimple(const SoSimple&copy) : num(copy.num){
        cout << "Called SoSimple{const SoSimple &copy)" << endl;
    }
    void ShowData()
    {
        cout << "num : " << num << endl;
    }
};
void SimpleFuncObj(SoSimple ob){
    ob.ShowData();
}

int main(void)
{
    SoSimple obj(7);
    cout << "CALL FUNC BEFORE" << endl;
    SimpleFuncObj(obj);
    cout << "AFTER" << endl;
    return 0;
}

//6
#include <iostream>
using namespace std;
class SoSimple{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {}
    SoSimple(const SoSimple&copy) : num(copy.num){
        cout << "Called SoSimple{const SoSimple &copy)" << endl;
    }
    SoSimple& AddNum(int n)//call by reference
    {
        num += n;
        return *this;
    }
    void ShowData()
    {
        cout << "num : " << num << endl;
    }
};
SoSimple SimpleFuncObj(SoSimple ob){
    cout << "before RETURN" << endl;
    return ob;
}

int main(void)
{
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();
    return 0;
}

//7
#include <iostream>
using namespace std;
class Temporary{
private:
    int num;
public:
    Temporary(int n) : num(n){
        cout << "create obj : " << endl;
    }
    ~Temporary(){
        cout << "destroy obj : " << endl;
    }
    void ShowTempInfo(){
        cout << "My num is " << num << endl;
    }
};
int main(void)
{
    Temporary(100);
    cout << "***********after make!" << endl << endl;
    Temporary(200).ShowTempInfo();
    cout << "**********after make!!" << endl << endl;
    const Temporary &ref = Temporary(300); //참조값이 반환되므로 참조자로 참조 가능
    cout << "**********end of main!" << endl << endl;
    return 0;
}

//8
#include <iostream>
using namespace std;
class MyProfile{
private:
    int *ptrN;
    int zipCode;
public:
    MyProfile(int n, int zc){
        ptrN = new int;
        *ptrN = n;
        zipCode = zc;
    }
    void setProfile(int n, int zc){
        *ptrN = n;
        zipCode = zc;
    }
    void getProfile(){
        cout << "ptrNum : " << ptrN << endl;
        cout << "ptrNum : " << *ptrN << endl;
        cout << "zipcode : " << zipCode << endl;
        cout << endl;
    }
    //얕은 복사의 문제
    //아래 부분(소멸자)이 얕은 복사의 문제가 발생하는 부분! 같은 곳을 두 번 지우려고 하니까 중단/다시시도/무시 의 문제가 나타났다!!!
    //~MyProfile(){
    //    delete ptrN;
    //    cout << "DESTRUCTOR!" << endl;
    //}
};

int main(void)
{
    MyProfile mp1(10, 90031);
    mp1.getProfile();

    MyProfile mp2(mp1);
    mp1.getProfile();
    mp2.getProfile();
    mp2.setProfile(500, 90000);
    mp1.getProfile(); //mp1의 ptrN은 포인터 변수라서 같이 바뀌었다. 단! zipcode는 call by value형태라서 90031 그대로 출력
    mp2.getProfile(); //주소는 항상 그대로 처음 정해진 위치에서 단 한번도 바뀐 적 없음

    return 0;
}

//9
#include <iostream>
using namespace std;
class MyProfile{
private:
    int *ptrN;
    int zipCode;
public:
    MyProfile(int n, int zc){
        ptrN = new int;
        *ptrN = n;
        zipCode = zc;
    }
    MyProfile(const MyProfile& obj) : zipCode(obj.zipCode){
        ptrN = new int;
        *ptrN = *obj.ptrN;
        cout << "Copy constructor" << endl;
    }
    ~MyProfile(){
        delete ptrN;
        cout << "DESTRUCTOR!" << endl;
    }
    void setProfile(int n, int zc){
        *ptrN = n;
        zipCode = zc;
    }
    void getProfile(){
        cout << "ptrNum : " << ptrN << endl;
        cout << "ptrNum : " << *ptrN << endl;
        cout << "zipcode : " << zipCode << endl;
        cout << endl;
    }
};

int main(void)
{
    MyProfile mp1(10, 90031);
    mp1.getProfile();

    MyProfile mp2(mp1);
    mp1.getProfile();
    mp2.getProfile();
    mp2.setProfile(500, 90000);
    mp1.getProfile(); //mp1의 ptrN은 포인터 변수라서 같이 바뀌었다. 단! zipcode는 call by value형태라서 90031 그대로 출력
    mp2.getProfile(); //주소는 항상 그대로 처음 정해진 위치에서 단 한번도 바뀐 적 없음

    return 0;
}

//10
#include <iostream>
using namespace std;
void print(int &a){
    cout << "1st print" << endl;
}
void print(const int&b){
    cout << "2nd print" << endl;
}
void print(int &&c){
    cout << "3rd print" << endl;
}
int main(void)
{
    int tmp = 1;
    int &tmp1 = tmp;
    const int&num=3;
    print(tmp); //이렇게 부르면 call by reference의 형태로 첫번째거를 부른다.
    print(tmp1); //이것 역시 tmp1자체가 레퍼런스 변수라서 첫번째거를 부른다.
    print(num); //num은 >>const가 붙은<< 레퍼런스 변수라서 두번째거를 부른다.
    print(7); //세번째거를 부른다.
    return 0;
}

//11
#include <iostream>
#include <string>
using namespace std;
class MyClass{
public:
    MyClass(){}
    MyClass(string str) : m_str(str){}
    void print(){ cout << m_str << endl; }
private:
    string m_str;
};
int main(void)
{
    MyClass A("aaa");
    MyClass B;
    MyClass C;

    B = A;
    C = move(A);

    A.print();
    B.print();
    C.print();
    return 0;
}

//12
#include <iostream>

using namespace std;

void print(int &x)
{
    cout << "&x : " << x << endl;
}

void print(const int &x)
{
    cout << "const &x : " << x << endl;
}

void print(int &&x)
{
    cout << "&&x : " << x << endl;
}

int main(void)
{
    int a;
    a = 10;
    int &x1 = a;
    const int &x2 = 10;
    int &&x3 = 10;
    int &&x4 = std::move(a);

    print(x1);    // 1
    print(x2);    // 2
    print(x3);    // 1
    print(x4);    // 1
    print(std::move(x4));    // 3
    print(3);     // 3

    return 0;
}
//14
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string name1 = "allen";
    cout << "name1: " << name1 << endl;

    string name2 = move(name1);
    cout << "After, name2 = move(name1)" << endl;
    cout << "-> name1: " << name1 << endl;
    cout << "-> name2: " << name2 << endl << endl;

    int zipcode1 = 90031; //객체와 달리 값은 그대로 박힌다.
    cout << "zipcode1 : " << zipcode1 << endl;
    int zipcode2 = move(zipcode1);
    cout << "After zipcode2 : " << endl;
    cout << "-> zipcode1 : " << zipcode1 << endl;
    cout << "-> zipcode2 : " << zipcode2 << endl;
    return 0;
}

//15
#include <iostream>
using namespace std;
class Integer{
public:
    int *val;
    Integer() = default;
    Integer(int val){
        this->val = new int(val);
    }
    ~Integer(){
        delete val;
    }
};
Integer Add(const Integer &a, const Integer &b){
    Integer tmp;
    // tmp.val = new int(a.val+b.val); 댕글링 레퍼런스 꼴(레퍼런스로 넘겨받았고 그걸 tmp를 통해서 가리켰지만 해당 Add 함수가 끝나면 사라진다!
    return tmp;
}
int main(void)
{
    Integer i1(1), i2(3);
    i1.val = Add(i1, i2).val;
    cout << i1.val;

    return 0;
}

//16
#include <iostream>
using namespace std;
class MyArray{
private:
    int num;
public:
    MyArray(int n){
        cout << "Call constructor" << endl;
        num = n;
    }
    MyArray(const MyArray& copy){
        cout << "Copy Constructor" << endl;
        num = copy.num;
    }
    MyArray(MyArray&&move){
        cout << "shift constructor" << endl;
        num = move.num;
        move.num = 0;
    }
    MyArray operator = (MyArray&&move){
        cout << "shift and allocate constructor" << endl;
        swap(num, move.num);
        return *this;
    }
    int getNum(){
        return num;
    }
};
MyArray CreateMyArray(){
    return MyArray(100);
}
int main(void)
{
    MyArray ar1(10);
    MyArray ar2(ar1);

    cout << "ar1.getnum" << ar1.getNum() << endl;
    cout << "ar2.getnum" << ar2.getNum() << endl;

    ar2 = CreateMyArray();
    cout << "ar1.getnum" << ar1.getNum() << endl;
    cout << "ar2.getnum" << ar2.getNum() << endl;

    MyArray ar3(std::move(ar1));
    cout << "ar1.getnum" << ar1.getNum() << endl;
    cout << "ar3.getnum" << ar3.getNum() << endl;

    return 0;
}

//17
#include <iostream>
#include <string>
using namespace std;
class MyClass{
public:
    MyClass(){}
    MyClass(string str, int a) : m_str(str), m_ptr(new int(a)) {}
    ~MyClass(){
        cout << "Destructor" << endl;
        if(m_ptr != nullptr) delete m_ptr;
    }
    void print(){
        cout << "String : " << m_str << endl;
        if(m_ptr != nullptr) cout << "PTR: " << *m_ptr << endl << endl;
        else cout << "PTR: " << endl << endl;
    }
    MyClass& operator=(MyClass& other){
        cout << "operator=(MyClass& other)" << endl;
        m_str = other.m_str;
        m_ptr = new int(*other.m_ptr);
        return *this;
    }
#if 0
MyClass & operator = (MyClass && other) = default;
#else
    MyClass& operator=(MyClass && other){
        cout << "operator=(MyClass&& other)" << endl;
        m_str = std::move(other.m_str);
        m_ptr = std::move(other.m_ptr);
        other.m_ptr = nullptr;
        return *this;
    }
#endif
private:
    string m_str = "ABC";
    int *m_ptr = nullptr;
};
int main(void)
{
    MyClass A("aaa", 10);
    MyClass B; MyClass C;

    B = A; C = std::move(A);

    A.print();
    B.print();
    C.print();

    return 0;
}
*/
