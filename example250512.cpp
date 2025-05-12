//250512
/*
//1
#include <iostream>
using namespace std;

class Carlos{
public:
    void Eat(int SteakWeight);
    inline void EatInline(int SteakWeight); // 인라인 함수 선언
};
int main(void)
{
    Carlos carlos;
    carlos.Eat(500);
    carlos.EatInline(700);
    return 0;
}
void Carlos::Eat(int SteakWeight){
    cout << "Eat()::Carlos ate " << SteakWeight << "g steak." << endl;
}
inline void Carlos::EatInline(int SteakWeight){
    cout << "Eatline()::Carlos ate " << SteakWeight << "g steak." << endl;
}

//2
#include <iostream>
using namespace std;
int main(void)
{
    [](int x, int y){cout << "Sum = " << x+y;}(2,3);
}

#include <iostream>
using namespace std;
class Carlos{
public:
    int count; //스테이크 먹는 횟수
};
int main(void)
{
    Carlos carlos;
    carlos.count = 1;
    for(int i=0 ; i<10; i++){
        [=](int steakWeight)mutable{cout<<"eatLambda()::Carlos ate " << carlos.count++ << " (cnt) " << steakWeight << "g steak." << endl;}(1000);
        // mutable을 사용해야 에러발생안함 (++부분) -> 그럼에도 불구하고 모두 1로찍힘
    }
    cout << carlos.count;
    return 0;
}

//4
#include <iostream>
using namespace std;
class Carlos{
public:
    int count;
};
int main(void)
{
    Carlos carlos;
    carlos.count = 1;
    for(int i=0;i<10;i++){
        [&](int steakWeight){cout<<"eatLamda()::carlos ate " << carlos.count++ << "(cnt) " << steakWeight << "g steak." << endl;}(1000);
    }
    cout << carlos.count;
    return 0;
}

//5
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    auto love = [](string a, string b){
        cout << "I prefer " << a << " to " << b << "!" << endl;
    };
    love("money", "you");
    love("noodles", "mandoo");
    return 0;
}

//6
#include <iostream>
using namespace std;
#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 10
#define CHARACTER_LEN 20

struct Carlos{
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;

    void introuduce(){};
    void eat(const char*food){};
    void sleep(){};
    void drive(const char *destination){};

};
int main(void)
{
    Carlos carlos = {"Carlos", "Male", "Teacher", "dilligent", 32};
    carlos.drive("school");
    carlos.eat("steak");
    return 0;
}

//7
#include <iostream>
using namespace std;
#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 10
#define CHARACTER_LEN 20
class Chulsoo{
public:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    void introduce(){};
    void sleep(){};
public:
    void eat(const char *food){};
    void drive(const char *destination){};
};
int main(void)
{
    Chulsoo chulsoo = {"Chulsoo", "M", "teacher", "cute", 32};
    chulsoo.drive("res");
    chulsoo.eat("steak");
    return 0;
}

//8
#include <iostream>
using namespace std;
class Stack{
public:
    int m_size;
    int m_top;
    int *m_buffer;

    void Initialize(int size=10);
    void RemoveAll();
    bool Push(int value);
    bool Pop(int &value);
};
void Stack::Initialize(int size){
    m_size = size;
    m_top = -1;
    m_buffer = new int[m_size];
    memset(m_buffer, 0, sizeof(int)*m_size);
}
void Stack::RemoveAll(){
    m_size = 0;
    m_top = -1;
    delete[] m_buffer;
    m_buffer = NULL;
}
bool Stack::Push(int value){
    if(m_top>=m_size-1) return false;
    m_buffer[++m_top]=value;
    return true;
}
bool Stack::Pop(int &value){
    if(m_top < 0) return false;
    value = m_buffer[m_top--];
    return true;
}
int main(void)
{
    Stack stack;
    stack.Initialize(10);
    stack.Push(1);
    stack.Push(3);
    stack.Push(10);
    //stack.Pop(&3);
    stack.RemoveAll();
    return 0;
}

//9
#include <iostream>
using namespace std;
class Stack{
protected:
    int m_size;
    int m_top;
    int *m_buffer;
public: //함수 정의를 안쓰면 링크 오류 발생
    void Initialize(int size=10){};
    void RemoveAll(){};
    bool Push(int value){return 1;};
    bool Pop(int &value){return 1;};
};

int main(void)
{
    Stack s1;
    s1.Initialize(5);
    //s1.m_top = 1; protected니까
    int data;
    s1.Pop(data);
    //delete[]s1.m_buffer; protected니까
    s1.Push(123);
    return 0;
}

//10
#include <iostream>
#include <cstring>
using namespace std;
class Stack{
protected:
    int m_size;
    int m_top;
    int *m_buffer;
public:
    int Getsize(){return m_size;};
    int GetTop(){return m_top;};
    bool SetSize(int size){
        if(size < m_size) return false;
        int *tmp = m_buffer;
        m_size = size;
        m_buffer = new int[m_size];
        memcpy(m_buffer, tmp, sizeof(int)*(m_top+1));
        delete []tmp;
        return true;
    };
    bool GetData(int index, int &data){
        if(index<0||index>m_top) return false;
        data = m_buffer[index];
        return true;
    };
};
int main(void)
{
    Stack stackTest;
    cout << stackTest.SetSize(5) << endl;
    cout << stackTest.Getsize() << endl;

    return 0;
}

//11
#include <iostream>
using namespace std;
class TwoNumber{
private:
    int num1=1;
    int num2=2;
public:
    TwoNumber(int n1, int n2){
        this->num1 = n1;
        this->num2 = n2;
    }
};
int main(void)
{
    TwoNumber tn(10, 20);

    return 0;
}

//12
#include <iostream>
using namespace std;
class SelfRef{
private: int num;
public:
    SelfRef(int n) : num(n){
        cout << "Makes Objects" << endl;
    }
    SelfRef& Adder(int n){
        num+=n;
        return *this;
    }
    SelfRef& ShowTwoNumber(){
        cout << num << endl;
        return *this;
    }
};

int main(void)
{
    SelfRef obj(3);
    SelfRef &ref = obj.Adder(2);
    obj.ShowTwoNumber();
    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
    return 0;
}

//13
#include <iostream>
using namespace std;
class Chulsoo{
private:
    int age;
public:
    Chulsoo(int age){ //얘를 생성자라고 한다. 객체 만들면 얘부터 불린다.
        this->age = age;
        cout << "Chulsoo::Chulsoo(age) made" << endl;
    }
    void setAge(int age){
        this->age = age;
    }
    void introduce(){
        cout << "His age is " << age << "!" << endl;
    }
    Chulsoo *returnThisPointer(){
        return this;
    }
    Chulsoo returnThis(){
        return *this;
    }
    Chulsoo& returnThisRef(){
        return *this;
    }
};
int main(void)
{
    Chulsoo chulsoo1(32);
    cout << "obg chulsoo1 introduce" << endl;
    chulsoo1.introduce();
    chulsoo1.setAge(50);
    chulsoo1.introduce();

    Chulsoo chulsoo2(32);
    cout << "chulsooPointer introduce" << endl;
    chulsoo2.returnThisPointer()->introduce();
    chulsoo2.returnThisPointer()->setAge(60);
    chulsoo2.returnThisPointer()->introduce();

    Chulsoo chulsoo3(32);
    cout << "chulsoo3" << endl;
    chulsoo3.returnThis().introduce();
    chulsoo3.returnThis().setAge(70);
    chulsoo3.returnThis().introduce();

    Chulsoo chulsoo4(32);
    cout << "chulsooRef introduce" << endl;
    chulsoo4.returnThisRef().introduce();
    chulsoo4.returnThisRef().setAge(80);
    chulsoo4.returnThisRef().introduce();

    return 0;
}

//14
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
    void introduce(){
        cout << "name : " << name << endl;
        cout << "gender : " << sex << endl;
        cout << "job : " << job << endl;
        cout << "char : " << character << endl;
        cout << "age : " << age << endl;
        cout << "marriage : " << marriageStatus << endl;
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
    void write(){
        cout << "Chulsoo writes a book." << endl;
    }
    void read(){
        cout << "Chulsoo reads a book." << endl;
    }
    void constructor(const char*name, const char*sex, const char*job, const char*character, int age, bool marriageStatus){
        strcpy_s(this->name, name);
        strcpy_s(this->sex, sex);
        strcpy_s(this->job, job);
        strcpy_s(this->character, character);
        this->age = age;
        this->marriageStatus = marriageStatus;
    }
};
class Younghee{
private:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;
public:
    void introduce(){
        cout << "name : " << name << endl;
        cout << "gender : " << sex << endl;
        cout << "job : " << job << endl;
        cout << "char : " << character << endl;
        cout << "age : " << age << endl;
        cout << "marriage : " << marriageStatus << endl;
    }
    void eat(const char*food){
        cout << "Younghee eats " << food << endl;
    }
    void sleep(){
        cout << "Younghee sleeps." << endl;
    }
    void shopping(){
        cout << "Younghee is shopping." << endl;
    }
    void constructor(const char*name, const char*sex, const char*job, const char*character, int age, bool marriageStatus){
        strcpy_s(this->name, name);
        strcpy_s(this->sex, sex);
        strcpy_s(this->job, job);
        strcpy_s(this->character, character);
        this->age = age;
        this->marriageStatus = marriageStatus;
    }
};

int main(void)
{
    Chulsoo cs;
    Younghee yh;
    cs.constructor("chulsoo", "male", "teacher", "cute", 32, true);
    yh.constructor("younghee", "female", "developer", "kind", 34, true);

    cs.drive("restaurant");
    cs.eat("steak");
    yh.eat("pasta");
    cs.drive("house");
    yh.sleep();
    cs.write();
    cs.read();
    cs.sleep();
    cout << endl;
    cs.introduce();
    cout << endl;
    yh.introduce();

    return 0;
}

//15
#include <iostream>
using namespace std;
class IntSample{
public:
    void ShowScore();
    void setScore(const int s);
    int getScore();
private:
    int Score;
};

void IntSample::ShowScore(){
    cout << "SCORE : " << Score << endl;
};

void IntSample::setScore(const int s){
    Score = s;
}
int IntSample::getScore(){
    return Score;
}
int main(void)
{
    IntSample Obj;
    Obj.setScore(100);
    cout << "Your Score : " << Obj.getScore() << endl;

    return 0;
}

//16
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
    Chulsoo(const char* name, const char* sex, const char* job, const char* character, int age, bool marriageStatus); //생성자 선언
    void introduce();
    void eat(const char*food);
    void sleep();
    void drive(const char *destination);
    void write();
    void read();
};
int main(void)
{
    Chulsoo cs("chulsoo", "male", "teacher", "cute", 32, true);
    cs.drive("school");
    cs.eat("snack");
    cs.drive("home");
    cs.write();
    cs.read();
    cout << endl;
    cs.introduce();
    return 0;
}
void Chulsoo::introduce(){
    cout << "name : " << name << endl;
    cout << "gender : " << sex << endl;
    cout << "job : " << job << endl;
    cout << "char : " << character << endl;
    cout << "age : " << age << endl;
    cout << "marriage : " << (marriageStatus ? "Y" : "N") << endl;
}
void Chulsoo::eat(const char*food){
    cout << "He ate " << food << endl;
}
void Chulsoo::sleep(){
    cout << "he slept" << endl;
}
void Chulsoo::drive(const char*destination){
    cout << "he drives to" << destination << endl;
}
void Chulsoo::write(){
    cout << "he wrote" << endl;
}
void Chulsoo::read(){
    cout << "he read." << endl;
}
Chulsoo::Chulsoo(const char*name, const char*sex, const char*job, const char*character, int age, bool marriageStatus){
    cout << "CS class constructor" << endl;
    strcpy_s(this->name, name);
    strcpy_s(this->sex, sex);
    strcpy_s(this->job, job);
    strcpy_s(this->character, character);
    this->age = age;
    this->marriageStatus = marriageStatus;
}

//17
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
        cout << "CS class constructor" << endl;
        strcpy_s(this->name, name);
        strcpy_s(this->sex, sex);
        strcpy_s(this->job, job);
        strcpy_s(this->character, character);
        this->age = age;
        this->marriageStatus = marriageStatus;
        cout << "end!" << endl;
    }
    Chulsoo(){
        cout << "I MADE!" << endl;
    }
    void introduce();
    void eat(const char*food);
    void sleep();
    void drive(const char *destination);
    void write();
    void read();
};
class Younghee{
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
    void introduce();
    void eat(const char*food);
    void sleep();
    void shopping();
};
class DailyLife{
private:
    Chulsoo cs;
    Younghee yh;
public:
    DailyLife(Chulsoo csO, Younghee yhO){
        cout << "D.L::D.L(csO, yhO) START " << endl;
        cs = csO;
        yh = yhO;
        cout << "D>L::D.L(csO, yhO) END " << endl;
    }
    void run(){
        cs.drive("school");
        cs.eat("kimbap");
        yh.eat("steak");
        cs.drive("home");
        yh.sleep();
        cs.write();
        cs.read();
        cs.sleep();

        cout << endl;
        cs.introduce();
        cout << endl;
        yh.introduce();
    }
};
int main(void)
{
    Chulsoo cs("carlos", "male", "teacher", "cute", 32, true);
    Younghee yh("y_h", "female", "student", "kind", 26, true);
    DailyLife dl(cs, yh);
    dl.run();
    return 0;
}
void Chulsoo::introduce(){
    cout << "name : " << name << endl;
    cout << "gender : " << sex << endl;
    cout << "job : " << job << endl;
    cout << "char : " << character << endl;
    cout << "age : " << age << endl;
    cout << "marriage : " << (marriageStatus ? "Y" : "N") << endl;
}
void Chulsoo::eat(const char*food){
    cout << "He ate " << food << endl;
}
void Chulsoo::sleep(){
    cout << "he slept" << endl;
}
void Chulsoo::drive(const char*destination){
    cout << "he drives to" << destination << endl;
}
void Chulsoo::write(){
    cout << "he wrote" << endl;
}
void Chulsoo::read(){
    cout << "he read." << endl;
}
void Younghee::introduce(){
    cout << "name : " << name << endl;
    cout << "gender : " << sex << endl;
    cout << "job : " << job << endl;
    cout << "char : " << character << endl;
    cout << "age : " << age << endl;
    cout << "marriage : " << (marriageStatus ? "Y" : "N") << endl;
}
void Younghee::eat(const char*food){
    cout << "She ate " << food << endl;
}
void Younghee::sleep(){
    cout << "She slept" << endl;
}
void Younghee::shopping(){
    cout << "She is Shopping~" << endl;
}
*/
