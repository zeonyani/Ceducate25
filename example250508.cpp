//250508
//1
int main(void)
{
    int val1;
    cout << "first num: ";
    cin >> val1;

    int val2;
    cout << "second num: ";
    cin >> val2;

    int result = val1+val2;
    cout << "SUM: " << result << endl;

    return 0;
}

//2
int main(void)
{
    int val1, val2;
    int result=0;
    cout<< "Enter 2 integers: ";
    cin>>val1>>val2;
    if(val1<val2){
        for(int i=val1+1;i<val2;i++){
            result += i;
        }
    }
    else{
        for(int i=val2+1;i<val2;i++){
            result +=i;
        }
    }
    cout << "Sum between 2 integers is "<<result<<endl;
    return 0;
}

//3
int main(void)
{
    char name[100];
    char lang[100];
    cout<<"name? ";
    cin >> name;
    cout<<"language? ";
    cin >> lang;

    cout << "My name is " << name << endl;
    cout << "MY favorite programming language is " << lang << endl;

    return 0;
}

//4
#include "header1.h"
#include "header2.h"

using namespace square;
int main(void)
{
    int y=x;    // 애매해서 출력되지 않음
    cout << "y is " << y << endl;
    cout << "namespace header1's is " << rectangle::x;

    return 0;
}

//5
using std::cout;    //  cout으로만 좁혀서 네임스페이스를 지정해서 cin은 선언되지 않은 식별자
int main(void)
{
    int i = 0;
    //cin >> i;   //  cin 선언되지 않은 식별자
    cout << i;

    return 0;
}

//6
using namespace std;
namespace first
{
int value = 1;
}

namespace second
{
int value = 2;
}

int main(void)
{
    cout << first::value << endl;
    //fflush(stdout);
    cout << second::value;

    return 0;
}

//7
namespace BestComImpl
{
void SimpleFunc(void){
    std::cout<<"BestCom 's fuction " << std::endl;
}
}

namespace ProComImpl
{
void SimpleFunc(void){
    std::cout<<"ProComImpl 's function " << std::endl;
}
}

int main(void)
{
    BestComImpl::SimpleFunc();
    ProComImpl::SimpleFunc();

    return 0;
}

//8
using namespace std;

namespace AAA{
namespace BBB{
namespace CCC{
int num1;
int num2;
}
}
}

int main(void)
{
    AAA::BBB::CCC::num1 = 20;
    AAA::BBB::CCC::num2 = 30;

    namespace ABC = AAA::BBB::CCC;

    cout << ABC::num1 << endl;
    fflush(stdout);
    cout << ABC::num2 << endl;

    return 0;
}

//9 : 왜 스왑 안 먹는지? 그리고 포인터 변수 call by reference할 때 c와 왜 다른지? 별표 쓰냐 마냐
using namespace std;
void Swap(int *p, int *q);
int main(void)
{
    int n1=1, n2=2;
    cout << n1;
    fflush(stdout);
    cout << n2 << endl;
    Swap(&n1, &n2);
    cout << n1 << " " << n2 << endl;
    return 0;
}
void Swap(int *p, int *q){
    int *tmp;
    tmp = p;
    p = q;
    q = tmp;
}


//10
int main(void)
{
    char x, y;  // 범위는 -128 ~ +127
    x = -128;
    y = -x; // y는 127이었다가 그 다음은 범위를 넘어가지만 서클이니까 -128

    if(x==y) printf("1");
    if((x-y)==0) printf("2");
    if((x+y)==2*x) printf("3");
    if(x!=-y) printf("4");

    return 0;
}

//11
#include <stdio.h>

int foo(){
    //int i, j; //213, 214 줄을 살리고 215,216 줄을 주석처리하면 : i변수가 초기화되지 않았기에 계속 i값(쓰레기값)에 따라 다른 값 출력
    //j = i +2;
    int i =0;
    int j = i +2;

    return j;
}
int main(void)
{
    for(int i = 0; i < 10;i++){
        printf("Result %d : %d\n", i, foo());
    }

    return 0;
}

//12
#include <iostream>
using namespace std;

int main(void)
{
    bool a = true;

    cout << a << endl;
    a = false;
    cout << a << endl;
    a = -98;
    cout << a << endl;
    a=0;
    cout << a << endl;

    return 0;
}

//13
#include <iostream>
using namespace std;

int main(void)
{
    int num = 10;
    int &ref = num; // ref는 num의 별명 (처음부터 초기화 해줘야!)

    cout << "num = " << num << endl;
    cout << "ref = " << ref << endl;

    ref = 100;

    cout << "num = " << num << endl;
    cout << "ref = " << ref << endl;

    cout << "&num = " << &num << endl;
    cout << "&ref = " << &ref << endl;
}

//14
#include <iostream>
using namespace std;
int main(void)
{
    int val1 = 100;
    int &val2 = val1;
    const int &val3 = 200; //const쓰면 가능한 이유 : lvalue는 변수만 있을 수 있어서 가능해진듯 -> 모던 cpp 에서 int &&lref = 200; 형식으로 씀
    int &val4 = val2;
    //int &val5; 초기화 같이 해줘야

    val1 = val1*3;

    cout << val1 << endl;
    cout << val2 << endl;
    cout << val3 << endl;
    cout << val4 << endl;

    return 0;
}

//15
#include <iostream>
using namespace std;

int main(void)
{
    int num = 12;
    int *ptr = &num;
    int **dptr = &ptr;

    int &ref = num;
    int *(&pref) = ptr;
    int **(&dpref) = dptr;

    cout << ref << endl;
    cout << *pref << endl;
    cout << **dpref << endl;

    return 0;
}

//16
#include <iostream>
using namespace std;
int main(void)
{
    int n = 1234;
    double d = 1.231;

    auto autoVar1 = d;
    auto autoVar2 = n;
    auto autoVar3 = d + n;
    autoVar3 = 1.234;

    cout << autoVar1 << endl;
    cout << autoVar2 << endl;
    cout << autoVar3 << endl;

    return 0;
}

//17
#include <iostream>
using namespace std;
int f(){
    return 20+30;
}

int main(void)
{
    double d = 1.414;
    decltype(f()) decVar1 = d;
    decltype(d) decVar2 = decVar1;
    decltype((d)) decVar3 = decVar2;
    decVar2 = 3.141592;

    cout << &decVar1 << endl;
    cout << &decVar2 << endl;
    cout << &decVar3 << endl;

    return 0;
}
*/