#include <stdio.h>
#include <stdbool.h>
#include <stdint.h> //c99표준 등장
#define _USE_MATH_DEFINES // math.h쓰려고 (표준 아니라서)
#include <math.h> //M_PI 쓰기 위함


/*
//OperatorFour.c
int main(void)
{
	int num1 = 12;
	int num2 = 12;

	printf("num1: %d \n", num1);
	printf("num1++: %d \n", num1++);								//	후위증가
	printf("num1: %d \n\n", num1);

	printf("num2: %d \n", num2);
	printf("++num2: %d \n", ++num2);								//	전위증가
	printf("num12 %d \n\n", num2);

	return 0;
}


//OperatorSeven.c
int main(void)
{
	int num1 = 10;
	int num2 = 12;
	int result1, result2, result3;

	result1 = (num1 == 10 && num2 == 12);
	result2 = (num1 < 12 || num2 > 12);
	result3 = (!num1);

	printf("result1: %d \n", result1);
	printf("result2: %d \n", result2);
	printf("result3: %d \n", result3);

	return 0;
}


//CommaOp.c 원칙은 printf는 나눠서 써야 함
int main(void)
{
	int num1 = 1, num2 = 2;
	printf("Hello "), printf("world!  \n");
	num1++, num2++;
	printf("%d ", num1), printf("%d ", num2), printf("\n");

	return 0;
}


//SimpleAddThree.c
int main(void)
{
	int result;
	int num1, num2;

	printf("정수 one: ");
	scanf_s("%d", &num1);
	printf("정수 two: ");
	scanf_s("%d", &num2);

	result = num1 + num2;
	printf("%d + %d = %d \n", num1, num2, result);

	return 0;
}


// 4-3-1 01001111=79 00110011=51
// 4-3-2 10101001=-41 11110000=-112 다시 확인

//실수값 비교의 문제
int main(void)
{
	float f = 0.0F;
	int i = 0;
	for (f = 0.0;f < 100.0f; f+=.1f, i++) {
		printf("f : %f\n", f);
	}

	printf("i: %d\n", i);
	return 0;
}


//BitAndOperation.c -> 왜 4가 출력? 곱셈취급 00000100 이라서!
int main(void)
{
	int num1 = 15;
	int num2 = 20;
	int num3 = num1 & num2;
	printf("AND 연산의 결과: %d \n", num3);

	return 0;
	
}


//BitNotOperation.c
int main(void)
{
	int num1 = 15;
	int num2 = ~num1;
	printf("NOT연산의 결과 %d \n", num2);

	return 0;
}


//BitLeftShift.c
int main(void)
{
	int num = 15;

	int result1 = num << 1;
	int result2 = num << 2;
	int result3 = num << 3;

	printf("1칸 이동 : %d \n", result1);
	printf("2칸 이동 : %d \n", result2);
	printf("3칸 이동 : %d \n", result3);

	return 0;
}


//SizeOfOperator.c
int main(void)
{
	char ch = 9;
	int inum = 1052;
	double dnum = 3.1415;

	printf("변수 ch크기 : %d \n", sizeof(ch));
	printf("변수 inum크기 : %d \n", sizeof(inum));
	printf("변수 dnum크기 : %d \n", sizeof(dnum));

	printf("char크기 : %d \n", sizeof(int8_t));
	printf("short크기 : %d \n", sizeof(int16_t));
	printf("int크기 : %d \n", sizeof(int32_t));
	printf("long크기 : %d \n", sizeof(int64_t));
	printf("long long크기 : %d \n", sizeof(long long));
	printf("float크기 : %d \n", sizeof(float));
	printf("double크기 : %d \n", sizeof(double));

	return 0;
}


//CharShortBaseAdd.c
int main(void)
{
	char num1 = 1, num2 = 2, result1 = 0;
	short num3 = 300, num4 = 400, result2 = 0;

	printf("size of num1 & num2 : %d %d \n", sizeof(num1), sizeof(num2));
	printf("size of num3 & num4 : %d %d \n", sizeof(num3), sizeof(num4));

	printf("size of char add : %d \n", sizeof(num1 + num2));
	printf("size of short add: %d \n", sizeof(num3 + num4));

	result1 = num1 + num2;
	result2 = num3 + num4;
	printf("size of result1 & result2 : %d %d\n", sizeof(result1), sizeof(result2));
	
	return 0;
}


//CircleArea.c
int main(void)
{
	double rad;
	double area;
	printf("원의 반지름 입력: ");
	scanf_s("%lf", &rad);

	area = rad * rad * M_PI;
	printf("원의 넓이: %f", area);
	
	return 0;
}


//HowChar.c
int main(void)
{
	char ch1 = 'A', ch2 = 65;
	int ch3 = 'Z', ch4 = 90;

	printf("%c %d \n", ch1, ch1);
	printf("%c %d \n", ch2, ch2);
	printf("%c %d \n", ch3, ch3);
	printf("%c %d \n", ch4, ch4);
	
	return 0;
}


//5-1-1
int main(void)
{
	int lx = 0, ly = 0, rx = 0, ry = 0;
	int area = 0;

	printf("좌상단의 x, y 좌표 : ");
	scanf_s("%d %d", &lx, &ly);
	printf("우하단의 x, y 좌표 : ");
	scanf_s("%d %d", &rx, &ry);

	area = (rx - lx) * (ry - ly);
	printf("\n넓이는 %d", area);

	return 0;
}


//5-1-2
int main(void)
{
	double f1 = 0, f2 = 0;
	printf("실수 두 개 입력 : ");
	scanf_s("%lf %lf", &f1, &f2);

	printf("%f + %f = %f\n", f1, f2, f1 + f2); //.2f 이런 식으로 쓰면 소수점 2까지
	printf("%f - %f = %f\n", f1, f2, f1 - f2);
	printf("%f x %f = %f\n", f1, f2, f1 * f2);
	printf("%f ÷ %f = %f\n", f1, f2, f1 / f2);

	return 0;
}


//5-1-3
//1: 0 ~ 127
//2: 1비트씩 증가
//3: a(97) A(65) 32차이 사유: 알파벳 차이 25, 중간에 특수문자

//5-1-4
int main(void)
{
	int asc = 0;
	printf("아스키코드 범위 내 정수 입력: ");
	scanf_s("%d", &asc);

	printf("%c", asc);

	return 0;
}


//5-1-5
int main(void)
{
	char alphabet = '0';

	printf("알파벳 문자 하나 입력 : ");
	scanf_s("%c", &alphabet);

	printf("\n정수는 %d", alphabet);

	return 0;
}


//AutoConvOne.c
int main(void)
{
	double num1 = 245;
	int num2 = 3.1415;							//	소수부 손실
	int num3 = 129;								//	상위비트의 손실
	char ch = num3;

	printf("정수 245 실수로 : %f\n", num1);
	printf("실수 3.1415 정수로 : %d\n", num2);
	printf("큰 정수 129 작은 정수로 : %d\n", ch); 

	return 0;
}


//ConvDiv.c
int main(void)
{
	int num1 = 3, num2 = 4;
	double divResult;

	divResult = num1 / num2;
	printf("나눗셈 결과 : %f \n", divResult);
	
	return 0;
}


//ConvDiv2.c
int main(void)
{
	int num1 = 3, num2 = 4;
	double divResult;

	divResult = (double)num1 / (double)num2; //둘 중 하나에만 강제형변환 해도 같은 결과나옴!
	printf("나눗셈 결과 : %f \n", divResult);

	return 0;
}


//OctHex.c
int main(void)
{
	int num1 = 7, num2 = 13;
	printf("%o %#o \n", num1, num1);
	printf("%x %#x \n", num2, num2);

	return 0;
}


//UsingPG.c
int main(void)
{
	double d1 = 1.23e-3;		//	0.00123
	double d2 = 1.23e-4;		//	0.000123
	double d3 = 1.23e-5;		//	0.0000123
	double d4 = 1.23e-6;		//	0.00000123

	printf("%g \n", d1);		//	%f스타일 출력
	printf("%g \n", d2);		//	%f스타일 출력
	printf("%g \n", d3);		//	%e스타일 출력
	printf("%g \n", d4);		//	%e스타일 출력

	return 0;
}


//FiedlWidth.c
int main(void)
{
	printf("%-8s %14s %5s \n", "이  름", "전공학과", "학년");
	printf("%-8s %14s %5d \n", "김동수", "전자공학", 3);
	printf("%-8s %14s %5d \n", "이을수", "컴퓨터공학", 2);
	printf("%-8s %14s %5d \n", "한선수", "미술교육학", 4);

	return 0;
}


//SimpleWhile.c
int main(void)
{
	int num = 0;
	while (num < 5)
	{
		printf("Hello World! %d\n", num);
		num++;
	}
	return 0;
}


//NineNineDan.c
int main(void)
{
	int dan = 0, num = 1;
	printf("몇 단? ");
	scanf_s("%d", &dan);

	while (num < 10)
	{
		printf("%d X %d = %d \n", dan, num, dan * num);
		num++;
	}
	return 0;
}


//7-1-1
int main(void)
{
	int num = 0;
	int index = 0;

	printf("양의 정수 하나 입력 : ");
	scanf_s("%d", &num);

	while (index < num)
	{
		printf("Hello World!\n");
		index++;
	}

	return 0;
}


//7-1-2
int main(void)
{
	int num = 0;
	int index = 1;

	printf("양의 정수 하나 입력: ");
	scanf_s("%d", &num);

	while (index < num+1) {
		printf("%d ", 3 * index);
		index++;
	}

	return 0;
}


//7-1-3
int main(void)
{
	int integer = 0;
	int add = 0;
	printf("정수 입력 : ");
	scanf_s("%d", &integer);
	add = integer + add;

	while (integer != 0) {
		printf("정수 입력 : ");
		scanf_s("%d", &integer);
		add = integer + add;
	}
	printf("합은 %d\n", add);

	return 0;
}


//7-1-4
int main(void)
{
	int index = 9;
	int num = 1;

	printf("자연수 입력 : ");
	scanf_s("%d", &num);

	while (index > 0) {
		printf("%d x %d = %2d\n", num, index, num*index);
		index--;
	}

	return 0;
}


//7-1-5
int main(void)
{
	int howmany = 1;
	int index = 0;
	int tmp = 0;
	double sum = 0;

	printf("몇 개 정수? : ");
	scanf_s("%d", &howmany);

	while (index < howmany) {
		printf("숫자 입력 : ");
		scanf_s("%d", &tmp);
		sum += tmp;
		index++;
	}
	printf("평균은 : %f", sum/index);

	return 0;
}
*/