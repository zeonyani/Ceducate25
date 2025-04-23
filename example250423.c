#include <stdio.h>								//	stdio.h 헤더파일 포함

/*
//2-1
int main(void) {
	printf("김정향\n김 정 향\n김  정  향");
	return 0;
}


//2-2
int main(void) {
	printf("김정향\n");
	printf("서울특별시\n");
	printf("01012345678");
	return 0;
}


//HelloComment.c
int main(void) {								//	main 함수의 시작
//	printf 함수는 모니터로 출력을 하는 경우에 쓴다.
//	인자로 문자열을 전달하면 문자열을 출력한다.
	
//	printf("Hello World!\n");					//	모니터로 문자열 출력
	return 0;									//	0을 반환한다.
}
												//	main 함수의 끝
												

//PrintfOne.c
int main(void) {
	printf("Hello Everybody\n");
	printf("%d \n", 1234);
	printf("%d %d\n", 10, 20);

	return 0;
}

//PrintfTwo.c
int main(void) {
	printf("My age : %d \n", 20);
	printf("%d is my point\n", 100);
	printf("Good \nmorning \neverybody");
	return 0;
}


//ex2-2-1
int main(void) {
	printf("제 아름은 홍길동입니다.\n");
	printf("제 낭는 %d살이고요.\n", 20);
	printf("제가 사는 곳의 번지수는 %d-%d 입니다.\n", 123, 456);

	return 0;
}


//2-2-2
int main(void) {
	printf("%dX%d=%d\n", 4, 5, 20);
	printf("%dX%d=%d\n", 7, 9, 63);

	return 0;
}


//VarDeclAndInin.c
int main(void) {
	int num1, num2;								//	변수 num1, num2의 선언
	int num3 = 30, num4 = 40;					//	변수 num3, num4의 선언 및 초기화

	printf("num1: %d, num2: %d\n", num1, num2);
	num1 = 10;									//	변수 num1의 초기화
	num2 = 20;									//	변수 num1의 초기화

	printf("num1: %d , num2: %d \n", num1, num2);
	printf("num3: %d , num4: %d \n", num3, num4);

	return 0;
}
*/

//SimpleAddTwo.c
int main(void) {
	int num1 = 3;								//	변수선언
	int num2 = 4;
	int result = num1 + num2;					

	printf("덧셈 결과: %d \n", result);
	printf("%d+%d=%d\n", num1, num2, result);
	printf("%d와(과) %d의 합은 %d입니다.\n", num1, num2, result);

	return 0;
}