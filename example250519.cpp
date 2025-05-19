//250519
//1
#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    for(int i=0;i<q.size();++i){
        cout << q.front() << " ";
        //q.pop();
    }

    cout << endl;
    return 0;
}

//2
#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    priority_queue<int ,deque<int>, greater<int>> pq3;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(40);
    pq.push(10);
    pq.push(20);

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq2.push(pq.top());
        pq.pop();
    }
    cout << endl;
    while (!pq2.empty()) {
        cout << pq2.top() <<  " ";
        pq3.push(pq2.top());
        pq2.pop();
    }
    cout << endl;

    while(!pq3.empty())
    {
        cout << pq3.top() << " ";
        pq3.pop();
    }
    cout << endl;

    return 0;
}

//3
#include <iostream>
#include <stack>
using namespace std;
int main(void)
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

//4
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void)
{
    map<string, int> m;
    m.insert(make_pair("A", 10));
    m.insert(make_pair("B", 20));
    m.insert(make_pair("C", 30));
    m.insert(make_pair("D", 40));
    m.insert(make_pair("E", 50));
    m["F"] = 100;
    for(auto i=m.begin();i!=m.end();++i) cout << "[ " << i->first << " " << i->second << " ]";
    cout << endl;
    auto i = m.find("A");
    cout << i->first << " : " << i->second << endl;
    m.insert(make_pair("E", 150));
    return 0;
}

//5
#include <iostream>
#include <map>
using namespace std;
int main(void)
{
    multimap<string, int> mm;
    mm.insert(make_pair("A", 10));
    mm.insert(make_pair("B", 20));
    mm.insert(make_pair("C", 30));
    mm.insert(make_pair("D", 40));
    mm.insert(make_pair("E", 50));
    mm.insert(make_pair("C", 100));
    mm.insert(make_pair("C", 200));

    for(auto i=mm.begin();i!=mm.end();++i) cout << " [ " << i->first << " " << i->second << " ]";
    cout << endl;

    auto lo_bp = mm.lower_bound("C");
    auto up_bp = mm.lower_bound("C");

    cout << "Key C 's values";
    for(auto i=lo_bp;i!=up_bp;++i) cout << i->second <<" ~";
    cout << endl;

    auto eq_rq = mm.equal_range("C");
    cout << "Another way ";
    for(auto i=eq_rq.first;i!=eq_rq.second;++i) cout << i->second << "   ";
    cout << endl;

    return 0;
}

//6
#include <iostream>
#include <set>
using namespace std;
int main(void)
{
    set<int> s;
    pair<set<int>::iterator, bool> pr;
    s.insert(10);
    s.insert(30);
    s.insert(60);
    s.insert(20);
    s.insert(50);
    pr = s.insert(40);

    for(auto i = s.begin();i!=s.end();i++) cout << *i << " ";
    cout << endl;

    s.insert(pr.first, 55);

    for(auto i = s.begin();i!=s.end();i++) cout << *i << " ";
    cout << endl;

    auto f = s.find(55);
    if(f!=s.end()) cout << *f << " ";
    return 0;
}

//7
#include <iostream>
#include <set>
using namespace std;
int main(void)
{
    multiset<int> ms;
    multiset<int>::iterator ms_iter;
    ms.insert(10);
    ms.insert(30);
    ms.insert(60);
    ms.insert(20);
    ms.insert(50);
    ms.insert(40);
    ms_iter = ms.insert(40);

    for(auto i = ms.begin();i!=ms.end();i++) cout << *i << " ";
    cout << endl;

    cout << "40s : " << ms.count(40) << endl;
    auto f = ms.find(40);
    if(f!=ms.end()) cout << *f << endl;
    return 0;
}

//8
#include <iostream>
#include <unordered_map>
using namespace std;
int main(void)
{
    unordered_map<string, int> um;
    um.insert({"A", 100});
    um.insert(make_pair("B", 200));
    um.insert({{"C", 1000}, {"D", 2000}});

    for(auto i=um.begin();i!=um.end();++i) cout << " [" << i->first << " " << i->second << " ] ";
    cout << endl;

    cout << "What is B's value?" << endl;
    auto bc = um.bucket("B");
    for(auto i=um.begin(bc);i!=um.end(bc);++i) cout << i->first << " : " << i->second;
    cout << endl;
    return 0;
}

//9
#include <iostream>
#include <vector>
#include <algorithm>>
using namespace std;
int main(void)
{
    int arr[10] = {97, 44, 23, 55, 61, 12, 3, 75, 27, 84};
    cout << "sorting : ";

    sort(arr, arr+10);
    for(int i=0;i<10;i++) cout << arr[i] << " ";
    cout << endl;

    vector<string> str;
    string s;
    cout << "input strings : ";
    while(cin>>s) str.push_back(s);

    sort(str.begin(), str.end());
    cout << "after sorting : ";
    for(vector<string>::iterator it = str.begin();it!=str.end();it++) cout << *it << " ";
    cout << endl;

    return 0;
}

//10
#include <iostream>
using namespace std;
int main(void)
{
    int a, b, result;

    cout << "a / b , input a and b" << endl;
    cout << "a : "; cin >> a;
    cout << "b : "; cin >> b;

    result =a/b;
    cout << "result is " << result << endl;
    return 0;
}

//11
#include <iostream>
using namespace std;
int main(void)
{
    int a, b, result;

    cout << "a / b , input a and b" << endl;
    cout << "a : "; cin >> a;
    cout << "b : "; cin >> b;

    if(b==0) cout << "can't divide by 0!" << endl; // 0으로 나누면 문제 발생하므로 이를 해결하고자
    else{
        result =a/b;
        cout << "result is " << result << endl;
    }
    return 0;
}

//12
#include <iostream>
using namespace std;
int main(void)
{
    int n1, n2;
    cout << "input 2 nums : ";
    cin >> n1 >> n2;
    try{
        if(n2==0) throw n2;
        cout << "share : " << n1/n2 << endl;
        cout << "reminder : " << n1%n2 << endl;
    }
    catch(int expn)
    {
        cout << expn << "is impossible" << endl;
        cout << "try again" << endl;
    }
    cout << "End" << endl;

    return 0;
}

//13
#include <iostream>
using namespace std;
void inputName(char *name){
    cout << "name ? :" ;
    cin >> name;
    if(strlen(name)<=2) throw name;
}
int inputAge(void)
{
    int age;
    cout << "Age ? : ";
    cin >> age;
    if(age < 1 || age > 150) throw age;
    return age;
}
int main(void)
{
    char name[512];
    int age;
    try{
        inputName(name);
        age = inputAge();

        cout << "My name is " << name << "~!" << endl;
        cout << "I am " << age << "years old." << endl;
    }
    catch(char *e)
    {
        cout << "Error - name --- " << e << endl;
    }
    catch (int e)
    {
        cout << "Error - age --- " << e << endl;
    }
    return 0;
}

//14
#include <iostream>
using namespace std;
void handler()
{
    cout << "in handler" << endl;
}

void f1(void) noexcept(false)
{
    cout << "about to throw 1" << endl;
    if(1) throw 1;
}

void f2(void) noexcept
{
    try{
        f1();
    }
    catch(...){
        handler();
    }
}
int main(void)
{
    //f1(); 주석처리를 해줘야 프로그램이 죽지 않음

    try{
        f2();
    }
    catch(...){
        cout << "caught exception from f2" << endl;
    }
    return 0;
}

//15
#include <iostream>
//#include <exception>
using namespace std;
void MyErrorHandler()
{
    cout << "still ERROR" << endl;
    exit(-1);
}
int main(void)
{
    set_terminate(MyErrorHandler);
    try{
        throw 1;
    }
    catch(char*const ex){
    }
    return 0;
}

//16
#include <iostream>
using namespace std;
class Myexception
{
    int myValue;
public:
    Myexception(int v) {myValue = v;}
    void excpetionResult(){
        if(myValue<10) cout << "Enter num more than 10" << endl;
        else if(myValue>20) cout << "Enter num less than 20" << endl;
        else if(myValue%7!=0) cout << "Enter num which is 7mods" << endl;
    }
};
int main(void)
{
    int Value;
    try {
        cout << "Num between 10 and 20 which is 7mods"; cin >> Value;

        if(Value<=10 | Value>=20 | Value &7!=0) throw Myexception(Value);
        // =을 사용하지 않으면 10과 20에 대해 그냥 answer로 처리해서 논리상 오류
        cout << "Answer : " << Value << endl;
    } catch (Myexception &e) {
        e.excpetionResult();
    }
    return 0;
}

//17
#include <iostream>
#include <exception>
using namespace std;
class Myexception : public exception
{
    int myValue;
public:
    Myexception(int v) {myValue = v;}
    void excpetionResult(){
        if(myValue<10) cout << "Enter num more than 10" << endl;
        else if(myValue>20) cout << "Enter num less than 20" << endl;
        else if(myValue%7!=0) cout << "Enter num which is 7mods" << endl;
    }
};
int main(void)
{
    int value;
    try
    {
        cout << "10~20 7mods   : " << endl;
        cin >> value;

        if(value<=10 | value >=20 | value %7!=0) throw Myexception(value);
        cout << "The Answer is " << value << endl;
    }
    catch(exception &e){
        cout << e.what() << endl;
    }
    return 0;
}

//18
#include <iostream>
#include <exception>
using namespace std;
class MyException : public exception{
    int myValue;
public:
    MyException(int v){
        myValue = v;
    }
    virtual const char *what() const throw()
    {
        if(myValue < 10)return "more than 10";
        else if(myValue >20) return "less than 20";
        else if(myValue%7!=0) return "7mods plz~";
        return "ODDS VALUE";
    }
};
int getMul()
{
    int val;
    cout << "10~20 & 7mods :";
    cin >> val;
    if(val<10 || val>20 || val%7!=0) throw MyException(val);
    return val;
}
int getVal()
{
    int va;
    va = getMul();
    return va;
}
int main(void)
{
    int vl;
    try {
        vl = getVal();
        cout << "ANSWER: 10~20 7mods " << vl << " !!!" << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}
*/
