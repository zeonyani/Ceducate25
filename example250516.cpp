//250516
//1
#include <iostream>
using namespace std;

class Person{
public:
    Person(){ cout << "Constructor" << endl; }
    ~Person() {cout << "Desstructor" << endl;}
    virtual void write() = 0;
};
class Chulsoo : public Person
{
public:
    Chulsoo() : Person() {cout << "C COnstructor" << endl;}
    ~Chulsoo() {cout << "C Destructor" << endl;}
    void write() {cout << "Writing a book" << endl;}
};
class Younghee:public Person{
public:
    Younghee():Person(){cout << "Y Constructor" << endl;}
    ~Younghee() {cout << "Y Destructor" << endl; }
    void wirte() {cout << "bad writing" << endl;}
};
class YC : public Chulsoo, public Younghee{
public:
    YC() : Chulsoo(), Younghee() {cout << "YC constructor" << endl;}
    ~YC() {cout << "YC destructor" << endl;}
    void write() {Chulsoo::write();}
};
int main(void)
{
    YC yc;
    yc.wirte();
    return 0;
}

//2
#include <iostream>
using namespace std;
class Person{
public:
    Person(){ cout << "Constructor" << endl; }
    ~Person() {cout << "Desstructor" << endl;}
    virtual void write() = 0;
    void sleep() {cout << "SLEEPING" << endl;}
};
class Chulsoo:public virtual Person
{
public:
    Chulsoo() : Person() {cout << "C COnstructor" << endl;}
    ~Chulsoo() {cout << "C Destructor" << endl;}
    void write() {cout << "Writing a book" << endl;}
};
class Younghee:public virtual Person{
public:
    Younghee():Person(){cout << "Y Constructor" << endl;}
    ~Younghee() {cout << "Y Destructor" << endl; }
    void wirte() {cout << "bad writing" << endl;}
};
class YC : public Chulsoo, public Younghee{
public:
    YC() : Chulsoo(), Younghee() {cout << "YC constructor" << endl;}
    ~YC() {cout << "YC destructor" << endl;}
    void write() {Chulsoo::write();}
};
int main(void)
{
    YC yc;
    yc.write();
    yc.sleep();
    return 0;
}

//3
#include <iostream>
using namespace std;
template <typename T>
T const add(T const &a, T const &b){
    return a+b;
}

int main(void)
{
    double i = 5.1; double j = 10.2;
    int a = 5; int b = 10;

    cout << i << " + " << j <<  " = " << add(i,j) << endl;
    cout << a << " + " << b <<  " = " << add(a, b) << endl;
    return 0;
}

//4
#include <iostream>
using namespace std;
template <class T1, class T2>
void ShowData(double num) {cout << (T1)num << ", "<< (T2)num << endl;}
int main(void)
{
    ShowData<char, int>(65); // 애네기 템플릿 함수들!
    ShowData<char, int>(67);
    ShowData<char, double>(68.9);
    ShowData<short, double>(69.2);
    ShowData<short, double>(70.4);
    return 0;
}

//5
#include <iostream>
using namespace std;
template <typename T, typename R>
R MaxV(const T n1, const R n2){
    if(n1>n2) return n1;
    else return n2;
}
int main(void)
{
    cout << MaxV(3, 5) << endl;
    cout << MaxV(9.1, 3.6) << endl;
    cout << MaxV(9.13, 3.6) << endl;
    cout << MaxV(9, 3.6) << endl;
    cout << MaxV(9.1, 31.6) << endl;
    cout << MaxV(9.13, 36) << endl;
    cout << MaxV(9.13, 3) << endl;
    //cout << MaxV(9.13) << endl; 인자 하나만 넣으면 안됨
    return 0;
}

//6
#include <iostream>
using namespace std;
template <typename T>
T Max(T a, T b) { return a > b ? a : b; }
template <> char*Max(char *a, char *b)
{
    cout << "char * Max<char*>(char *a, char *b)" << endl;
    return strlen(a) > strlen(b) ? a : b;
}
template <>
const char* Max(const char*a, const char *b)
{
    cout << "const char * Max<const char*> (const char*a, const char *b)" << endl;
    return strcmp(a, b) > 0 ? a : b;
}
int main(void)
{
    cout << Max(11, 15) << endl;
    cout << Max('T', 'Q') << endl;
    cout << Max(3.5, 7.5) << endl;
    cout << Max("Simple", "Best") << endl;

    char str1[]="Simple";
    char str2[]="Best";
    cout << Max(str1, str2) << endl;
    return 0;
}

//7
#include <iostream>
#include <string.h>
using namespace std;
template <typename T>
T const add(T const&a, T const &b){
    cout << "typename T~";
    return a+b;
}
template <>
char*const add<char*>(char*const& a, char *const &b){
    cout << "specialized" << endl;
    strcat_s(a, 20, b);
    return a;
}
char *const add(char *a, char *const &b){
    cout << "overloading" << endl;
    strcat_s(a, 20, b);
    return a;
}

int main(void)
{
    int i=5; int j=10;
    double a=5.1; double b = 10.2;

    char m[20] = "Hello"; char n[20] = "World";

    cout << i << " + " << j << " = " << add(i, j) << endl;
    cout << a << " + " << b << " = " << add(a, b) << endl;

    cout << add<char*>(m,n) << endl;
    cout << add(m,n) << endl;

    return 0;
}

//8
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class MyArray{
private:
    vector<T> list;
public:
    void add_list(T const&);
    void delete_last_list(void);
    void show_list(void);
};
template <typename T>
void MyArray<T>::add_list(T const& element){
    list.push_back(element);
}
template <typename T>
void MyArray<T>::delete_last_list(void){
    list.pop_back();
}
template <typename T>
void MyArray<T>::show_list(){
    cout << "[My Array list look up]" << endl;
    for(typename vector<T>::iterator i = list.begin(); i!=list.end();++i) cout << *i << endl;
}
int main(void)
{
    MyArray<int> array1;
    array1.add_list(1);
    array1.add_list(2);
    array1.add_list(3);
    array1.add_list(4);
    array1.add_list(5);
    array1.show_list();

    array1.delete_last_list();
    array1.delete_last_list();
    array1.show_list();

    cout << endl << endl;

    MyArray<double> arr2;
    arr2.add_list(1.1); arr2.add_list(2.1); arr2.add_list(3.1); arr2.add_list(4.1); arr2.add_list(5.1);
    arr2.show_list(); arr2.delete_last_list(); arr2.delete_last_list();
    arr2.show_list();

    return 0;
}
//9
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class MyArr
{
private:
    vector<T> list;
public:
    void add_list(T const&);
    void delete_last_list(void);
    void show_list(void);
};
template <typename T>
void MyArr<T>::add_list(T const& element){
    list.push_back(element);
}
template <typename T>
void MyArr<T>::delete_last_list(void){
    list.pop_back();
}
template <typename T>
void MyArr<T>::show_list() {
    cout << "   My Arr List   " << endl;
    for(typename vector<T>::iterator i=list.begin();i!=list.end();++i) cout << *i << endl;
}
template<>
class MyArr<int>{
private:
    vector<int> list;
public:
    void add_list(int const&);
    void delete_last_list(void);
    void show_list(void);
};

void MyArr<int>::add_list(int const& element){
    list.push_back(element);
}
void MyArr<int>::delete_last_list(void){
    list.pop_back();
}
void MyArr<int>::show_list(void)
{
    cout << " *** specialization *** " << endl;
    for(vector<int>::iterator i=list.begin();i!=list.end();++i) cout << *i << endl;
}
int main(void)
{
    MyArr<int> arr1;
    arr1.add_list(1);
    arr1.add_list(2);
    arr1.add_list(3);
    arr1.add_list(4);
    arr1.add_list(5);
    arr1.show_list();
    arr1.delete_last_list();
    arr1.delete_last_list();
    arr1.show_list();

    MyArr<double> arr2;
    arr2.add_list(1.1);
    arr2.add_list(2.1);
    arr2.add_list(3.1);
    arr2.add_list(4.1);
    arr2.add_list(5.1);
    arr2.show_list();
    arr2.delete_last_list();
    arr2.delete_last_list();
    arr2.show_list();

    return 0;
}

//10
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<int> v(6,1);
    cout << "v.capicity(): " << v.capacity() << " / v.size(): " << v.size() << endl;
    for(auto i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl << endl;

    v.assign(4,3);
    cout << "v.capicity(): " << v.capacity() << " / v.size(): " << v.size() << endl;
    for(auto i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl << endl;

    v[2] = 7;
    for(vector<int>::iterator it=v.begin()+3;it!=v.end();it++) *it = 9;

    v.push_back(10);
    cout << "v.capacity(): " << v.capacity() << " / size(): " << v.size() << endl;
    for(auto i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl << endl;

    v.push_back(30);
    cout << "v.capacity(): " << v.capacity() << " / size(): " << v.size() << endl;
    for(auto i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl << endl;

    v.resize(17);
    cout << "v.capacity(): " << v.capacity() << " / size(): " << v.size() << endl;
    for(auto i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl << endl;

    return 0;
}

//11
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Person
{
private:
    int age; string name;
public:
    Person(const int a, const string&s): age(a), name(s) {}
    int getAge() {return age;}
    string getName() {return name;}
};
int main(void)
{
    vector<Person> vec{
        {21, "Smith"}, {39, "John"}, {23, "Mary"}, {45, "Ted"}
    };
}

//12
#include <iostream>
#include <algorithm>  // sort함수 사용을 위함
#include <vector>
using namespace std;
class Multi
{
    int first; int second;
public:
    Multi(int f, int s){
        first = f; second = s;
    }
    int getResult(){ return first*second;}
};
int main(void)
{
    vector<Multi> multiData;
    for(int i=0;i<10;i++){
        Multi m = Multi(rand()%10, rand() % 10);
        multiData.push_back(m);
    }
    cout << "not sort" << endl;
    for(vector<Multi>::iterator iter = multiData.begin(); iter != multiData.end();iter++){
        cout << iter->getResult() << endl;
    }
    sort(multiData.begin(), multiData.end(), [](Multi&m1, Multi&m2){
        return m1.getResult() < m2.getResult();
    });

    cout << "SOOOOORT AFTER" << endl;

    for(vector<Multi>::iterator iter=multiData.begin(); iter!=multiData.end(); iter++){
        cout << iter->getResult() << endl;
    }
}

//13
#include <iostream>
#include <deque>
using namespace std;
int main(void)
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    cout << "dq.size():" << dq.size() << endl;
    cout << "[dq]: ";
    for(auto i=0;i<dq.size();i++) cout << dq[i] << " ";
    cout << endl;
    for(auto i=0;i<dq.size();i++) cout << "dq[ " << i << " ] adress : " << &dq[i] << endl;
    cout << endl;

    deque<int> dq2;
    dq2.push_back(100);
    dq2.push_back(200);
    dq2.push_back(300);
    cout << "dq2.size() : " << dq2.size() << endl;
    cout << "[dq2]";
    for(auto i=0;i<dq2.size();i++) cout << dq2[i] << " ";
    cout << endl;
    for(auto i=0;i<dq2.size();i++) cout << "dq2[ " << i << " ] adress : " << &dq2[i] << endl;
    cout << endl;

    dq.push_back(40);
    dq.push_back(50);
    dq.push_back(60);
    cout << "dq.size(): " << dq.size() << endl;
    cout << "[dq] : ";
    for(auto i=0;i<dq.size();i++) cout << dq[i] << " ";
    cout << endl;

    for(auto i=0;i<dq.size();i++) cout<< "dq[ " << i << "] address :" << &dq[i] << endl;
    cout << endl;

    for(int i= 70;i<2000;i+=10) dq.push_back(i);

    cout << "dq.size() : " << dq.size() << endl;
    cout << "[dq]: ";

    for(auto i=0;i<dq.size();i++) cout << dq[i] << " ";
    cout << endl;

    for(auto i=0;i<dq.size();i++) cout << "dq[ " << i << " ] address: " << &dq[i] << endl;
    cout << endl;

    cout << "dq[127]" << &dq[127] << "*****" << dq[127] << endl;
    cout << "dq[128]" << &dq[128] << "*****" << dq[128] << endl;
    deque<int>::iterator i = dq.begin()+127;
    cout << *i << endl;
    i++;
    cout << *i << endl;
    int *j = &dq[127];
    j++;
    cout << j << " : " << *j << endl;

    return 0;
}
//14
#include <iostream>
#include <list>
using namespace std;
int main(void)
{
    list<int> lt;
    list<int> lt2;
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_front(-10);
    lt.push_front(-20);
    lt.push_front(-30);

    for(auto i = lt.begin(); i!=lt.end();i++) cout << *i << " ";
    cout << endl;

    for(auto i = 0;i<10;i++) lt2.push_back(i);

    for(auto i = 0;i<10;i++) lt2.push_back(i);

    for(auto i=lt2.begin();i!=lt2.end();i++) cout << *i << " ";
    cout << endl;

    for(auto p = lt.begin(); p!=lt.end(); p++){
        if(*p==10){
            lt.splice(p, lt2);
            break;
        }
    }
    for(auto i=lt.begin(); i!=lt.end();i++) cout << *i << " ";
    cout << endl;

    return 0;
}
*/