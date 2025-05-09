//250509
/*
//1
int main(void)
{
    int num = 0x040204;
    char *ptr = reinterpret_cast<char*>(&num);
    cout << static_cast<int>(*(ptr+1)) << endl;

    return 0;
}

//2
int main(void)
{
    int *p = NULL;
    p = new int(0); //동적 메모리 할당 및 초기화
    if(p==NULL){
        cout << "failed" << endl;
        return 1;
    }
    cout << "input Integer : ";
    cin >> *p; //동적 메모리 사용
    cout << "you entered " << p[0] << endl; //동적 메모리 사용
    delete p;
    p = NULL;
}

//3
char *NumberToString(int n)
{
    char *p = new char[20];
    sprintf(p, "%d", n);
    return p;
}

int main(void)
{
    int num;
    cout << "Input Integer: " << endl;
    cin >> num;

    char *str = NumberToString(num);
    cout << "num -> string is " << str << endl;

    delete [] str;

    return 0;
}

//4
int main(void)
{
    int a = 0, b = 0, sum1, sum2;

    sum1 = a+++a+++a++;
    sum2 = ++b+ ++b+ ++b;

    printf("%d %d %d %d\n", a, b, sum1, sum2);

    return 0;
}

//5
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main(void)
{
    int i = 3.65;
    long l = M_PI;
    float f = M_PI;
    double d = M_PI;

    printf("%d %ld\n", i, l);
    printf("\n%.20f %.20f\n", f, d);

    return 0;
}

//6
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string str = "Put it!";
    ofstream ofs("file.txt"); //해당 파일을 연다
    ofs << str; //str문자열을 쓴다
    ofs.close(); //파일을 닫는다
    ifstream ifs("fiel.txt"); //해당 파일을 다시 열고
    ifs >> str; //파일의 내용을 문자열에 저장한다
    cout << str << endl; //그 저장한 내용을 화면에 출력한다
    ifs.close(); //파일 닫는다

    return 0;
}
//7
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    fstream fs;
    fs.open("test.txt, ios::out");
    if(fs.fail()) return 0;

    fs << "keyboard" << endl;
    fs << "monitor" << endl;

    fs.close();

    fs.open("test.txt", ios::out|ios::trunc);
    fs << "desk" << endl;

    fs.open("test.txt", ios::in);
    string temp;

    while(fs >> temp, !fs.eof()) cout << temp << endl;

    fs.close();

    return 0;
}

//8
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(void)
{
    fstream fp;
    int data, score[5] = {78,96,100,25,96};

    fp.open("sample.txt", ios::out | ios::binary);
    fp.write((char*)score, 20);
    fp.close();

    fp.open("sample.txt", ios::in | ios::binary);
    if(fp.fail()) return 1;

    fp.read((char*)&data, 4);
    cout << setw(3) << right << data << endl;

    fp.seekg(4, ios::cur);
    fp.read((char*)&data, 4);
    cout << setw(3) << right << endl;

    fp.close();

    //cout << "The End" << endl;

    return 0;
}

//9
#include <iostream>
using namespace std;
int main(void)
{
    int a = 1234, b=0x12345678;

    cout << hex << "16 digit " << a << endl;
    cout << dec << "\n10 digit " << a << endl;
    cout << hex << "16 digit " << b;
    cout << dec << "\n10 digit " << b << endl;

    return 0;
}

//10
#include <fstream>
using namespace std;

int main(void)
{
    ofstream ofs;
    ofs.open("file.txt");

    ofs.write("This is an apple.", 16);

    long pos = ofs.tellp();

    ofs.seekp(pos-7);
    ofs.write("sam", 4);

    ofs.close();

    return 0;
}

//11
#include <iostream>
using namespace std;

class Carlos{
public:
    void Eat();
};

void Carlos::Eat(){
    cout << "Carlos eats sth." << endl;
}

int main(void)
{
    Carlos carlos;
    carlos.Eat();

    return 0;
}

//12
#include <stdio.h>
using namespace std;
//변수에 값을 할당하는 함수
int assignValue(int n){
    n = 10;
    return n;
}

int main(void)
{
    int num = 0, value;
    value = assignValue(num);
    printf("[Input]: %d / : [Output] : %d\n", num, value);
    return 0;
}

//13
int TestFunc1(int a);

int main(void)
{
    int b = 20;
    cout << b << endl;
    TestFunc1(b);
    cout << b << endl;

    return 0;
}

int TestFunc1(int a){
    cout << a << endl;
    a = 100;
    cout << a << endl;

    return 0;
}

//14
#include <iostream>
using namespace std;
class Restaurant{
public:
    int Steak;
};

class Carlos{
public:
    int Eat(int);
};

int Carlos::Eat(int SteakNum){
    SteakNum = 10000;
    cout << "Carlos eats" << endl;

    return SteakNum;
}

int main(void)
{
    Carlos carlos;
    Restaurant res;

    res.Steak = 20000;
    cout << "Carlos lies he ate $" << carlos.Eat(res.Steak) << "!" << endl;
    cout << "Restaurant insists Carlos ate $" << res.Steak << "!!!" << endl;

    return 0;
}

//15 레퍼런스에 의한 인자 전달
#include <iostream>
void Swap(int &ra, int &rb){
    int tmp = ra;
    ra = rb;
    rb = tmp;
}

int main(void)
{
    int a, b;
    cout << "input 2 integers : ";
    cin >> a >> b;
    cout << "Before : " << a << " " << b << endl;
    Swap(a,b);
    cout << "After : " << a << " " << b << endl;

    return 0;
}

//16 포인터에 의한 인자 전달
#include <iostream>
using namespace std;

void Swap2(int *pa, int *pb){
    int ptmp = *pa; //c에서는 int *ptmp했던 것과 다르군.
    *pa = *pb;
    *pb = ptmp;
}

int main(void)
{
    int a, b;
    cout << "input 2 integers : ";
    cin >> a >> b;
    cout << "Before : " << a << " " << b << endl;
    Swap2(&a,&b);
    cout << "After : " << a << " " << b << endl;

    return 0;
}

//17 주소에 의한 호출
#include <iostream>
using namespace std;
//변수에 값을 할당하는 함수
int assignValue(int *n){
    *n = 10;
    return *n;
}
int main(void)
{
    int num = 0, value;
    printf("%d\n\n", num);
    value = assignValue(&num);
    printf("%d %d\n", num, value);
    return 0;
}

//18
#include <iostream>
using namespace std;

class Restaurant{
public:
    int Steak;
};

class Carlos{
public:
    int Eat(int&);
};
int Carlos::Eat(int &SteakNum){
    SteakNum = 10000;
    cout << "Carlos Ate." << endl;
    return SteakNum;
}
int main(void)
{
    Carlos carlos;
    Restaurant res;

    res.Steak = 20000;
    cout << "!!!Carlos " << carlos.Eat(res.Steak) << "***LIE***" << endl;
    cout << "Restaurant says he ate " << res.Steak << "***" << endl;

    return 0;
}

//19
#include <iostream>

using namespace std;

void plus1(int n) { n++; }
void plus2(int &n) { n+=2; }
//void plus3(const int n) { n+=3; }
//void plus4(const int &n) { n+=4; }
int main(void)
{
    int num1 = 1;
    plus1(num1); cout << "1 : " << num1 << endl;
    plus2(num1); cout << "2 : " << num1 << endl;
    //plus3(num1); cout << "3 : " << num1 << endl;
    //plus4(num1); cout << "4 : " << num1 << endl;
    return 0;
}

//20
#include <iostream>
int BoxVolume(int l, int w=1, int h=1){
    return l*w*h;
}
int main(void)
{
    cout << "[3,3,3]: " << BoxVolume(3,3,3) << endl;
    cout << "[5,5,D]: " << BoxVolume(5,5) << endl;
    cout << "[7,D,D]: " << BoxVolume(7) << endl;
    //cout << "[D,D,D]: " << BoxVolume() << endl;
    //아무것도 인자로 넘기지 않은 경우 문제가 됨

    return 0;
}
*/
//21
#include "compare.h"
int Compare(const int a, const int b){
    if(a>b)return 1;
    else if(a==b) return 0;
    else return -1;
}
int Compare(const float a, const float b){
    if(a>b) return 1;
    else if(a==b) return 0;
    else return -1;
}
int Compare(const char a, const char b){
    if(a>b) return 1;
    else if(a==b) return 0;
    else return -1;
}
int Compare(const char str1[], const char str2[]){
    int i;
    for(i=0;str1[i]!='\0' && str2[i]!='\0';i++){
        if(str1[i]>str2[i]) return 1;
        else if(str1[i]<str2[i]) return -1;
        else ;
    }
    if(str1[i]=='\0' && str2[i]!='\0') return -1;
    else if(str1[i]!='\0' && str2[i]=='\0') return -1;
    else return 0;
}
int main(void)
{
    int a = 34, b = 4;
    float c = 1.234f, d = 98.34f;
    char e = 'H', f = 'K';
    char str1[] = "computer", str2[]="computers";

    printf("%d\n", Compare(a,b));
    printf("%d\n", Compare(c,d));
    printf("%d\n", Compare(e,f));
    printf("%d\n", Compare(str1,str2));

    return 0;
}
