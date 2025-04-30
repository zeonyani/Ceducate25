#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


/*
//WriteString.c
int main(void)
{
	char* str = "Simple String";

	printf("1. puts test -----\n");
	puts(str);					//	puts함수의 호출. 문자열이 선언된 위치에는 문자열의 주소값 반환되므로 문자열 주소값 전달
	puts("So simple String");	//	puts함수의 호출. 문자열이 선언된 위치에는 문자열의 주소값 반환되므로 문자열 주소값 전달

	printf("2. fputs test -----\n");
	fputs(str, stdout);			//	fputs 함수 호출. stdout이 전달되어서 모니터로 출력.
	printf("\n");				//	개행문자를 꼭 쓴다
	fputs("So simple String", stdout);
	printf("\n");

	printf("3. end of main -----\n");

	return 0;
}


//ReadString.c
int main(void)
{
	char str[7];
	int i;

	for (i = 0;i < 3;i++) {
		fgets(str, sizeof(str), stdin);			//	개행문자를 만날때까지 읽어들임. 그래서 줄바꿈에 있는 걸 알아서 제외해야 scanf와 같음
		//	공백도 인식(scanf와의 차이)
		printf("Read : %d %s\n", i + 1, str);
	}

	return 0;
}


//NeedInputButFlush.c
void ClearBuffer(void);
int main(void)
{
	char perID[7];
	char name[10];

	fputs("주민번호 6자리 : ", stdout);
	fgets(perID, sizeof(perID), stdin);
	ClearBuffer();						//	이 함수 없이는 6자리 숫자 후 "엔터키인 개행문자"를 이름으로 인식해버린다!

	//fflush(stdin);					//	이게 적용안되는 이유는 비쥬얼스튜디오 15이상부터는 안된다고 함

	fputs("이름 : ", stdout);
	fgets(name, sizeof(name), stdin);

	printf("주민번호는 %s\n", perID);
	printf("이름은 %s\n", name);

	return 0;
}
void ClearBuffer(void)
{
	while ((getchar()) != '\n');
}


int main(int argc, char* argv[])
{
	int i;
	float f;
	char c, str[32];

	scanf("%d ", &i);		printf("1: %d\n", i);
	scanf("%f", &f);		printf("2: %f\n", f);
	//scanf("%f\n", &f);		printf("엔터키 먹는 거 방지 첫번째 방법\n"); //엔터키 입력 자체를 다음 3의 문자로 인식되는 거 방지
	//scanf("%c", &c);		printf("3: %c\n", c);
	scanf("%*c%c", &c);		printf("두 번째 방법\n"); printf("3: %c\n", c);
	//scanf("%f\n", &f);		printf("엔터키 먹지마(첫번째 방법)\n");
	scanf("%s", str);		printf("4: %s\n", str);	

	return 0;
}


//RemoveBSN.c
void RemoveBSN(char str[]);
int main(void)
{
	char str[100];
	printf("문자열 입력 : ");
	fgets(str, sizeof(str), stdin);
	printf("길이: %d 내용: %s\n", strlen(str), str);

	RemoveBSN(str);
	printf("길이 %d 내용 %s\n", strlen(str), str);

	return 0;
}

void RemoveBSN(char str[])					//	백슬래쉬가 사라짐!
{
	int len = strlen(str);
	str[len - 1] = 0;
}


//StringCoipyCase.c
int main(void)
{
	char str1[20] = "1234567890";
	char str2[20];
	char str3[5];

	//case 1
	strcpy(str2, str1);
	puts(str2);

	//case 2
	strncpy(str3, str1, sizeof(str3));
	puts(str3);

	//case 3
	strncpy(str3, str1, sizeof(str3) - 1);
	str3[sizeof(str3) - 1] = 0;
	puts(str3);

	return 0;
}


//StringConcatCase.c
int main(void)
{
	char str1[20] = "First~";
	char str2[20] = "Second";

	char str3[20] = "Simple num";
	char str4[20] = "1234567890";

	//case 1
	strcat(str1, str2);
	puts(str1);

	//case2
	strncat(str3, str4, 7);
	puts(str3);

	return 0;
}


//StringCompCase.c
int main(void)
{
	char str1[20];
	char str2[20];
	
	printf("문자열 입력1: ");
	scanf("%s", str1);

	printf("문자열 입력2: ");
	scanf("%s", str2);

	if (!strcmp(str1, str2)) puts("완전 동일");
	else {
		puts("동일하지 않음");
		if (!strncmp(str1, str2, 3)) puts("그러나 앞 3글자는 동일");
	}
	(
	return 0;
}


//ConvString.c
int main(void)
{
	char str[20];
	printf("정수 입력: ");
	scanf("%s", str);
	printf("%d\n", atoi(str));

	printf("실수 입력: ");
	scanf("%s", str);
	printf("%g\n", atof(str));

	return 0;
}


//21-2-1
int main(void)
{
	char str[BUFSIZ], tmp[BUFSIZ];
	long sum = 0, cnt = 0;

	printf("Input some string : ");
	scanf("%s", str);

	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			tmp[cnt++] = str[i];
		}
		else if (cnt != 0) {
			tmp[cnt] = '\0';
			printf("%s+", tmp);
			sum += atoi(tmp);
			cnt = 0;
		}
	}
	printf("\b=%ld\n", sum);

	return 0;
}


//21-2-2
void ClearBuffer(void);
int main(void)
{
	char str1[20];
	char str2[20];
	char str3[40];

	printf("str1 입력 ");
	fgets(str1, sizeof(str1), stdin);
	//ClearBuffer();

	printf("str2 입력 ");
	fgets(str2, sizeof(str2), stdin);

	strncpy(str3, str1, sizeof(str3));
	
	strcat(str3, str2);
	puts(str3);

	return 0;
}

void ClearBuffer(void)
{
	while ((getchar()) != '\n');
}


//21-2-3 worll 12 world 12를 같은 사람으로 취급하는 문제 해결하기
int main(void)
{
	char name1[BUFSIZ], name2[BUFSIZ];
	int age1, age2;

	printf("1 이름 나이 입력");
	scanf("%s %d", name1, &age1);
	printf("2 이름 나이 입력");
	scanf("%s %d", name2, &age2);

	
	if (age1 == age2) {
		for (int i = 0;i < strlen(name1);i++) {
			if (name1[i] == name2[i]) {
				if (strlen(name1) == strlen(name2)) {
					printf("같은 나이 같은 사람");
					break;
				}
				else {
					printf("같은 나이 다른 사람");
					break;
				}
			}
		}
	}
	else printf("나이 다름");
	return 0;
}


//TwoPointerDistance.c
struct point
{
	int xpos;
	int ypos;
};

int main(void)
{
	struct point ps1, ps2;
	double dis;

	fputs("pos1: ", stdout);
	scanf("%d %d", &ps1.xpos, &ps1.ypos);

	fputs("pos1: ", stdout);
	scanf("%d %d", &ps2.xpos, &ps2.ypos);

	dis = sqrt((double)((ps1.xpos - ps2.xpos) * (ps1.xpos-ps2.xpos)
		+ (ps1.ypos - ps2.ypos)*(ps1.ypos - ps2.ypos)));

	printf("거리는 %g\n", dis);

	return 0;
}


//TelephoneInfo.c
struct person {
	char name[20];
	char phoneNum[20];
	int age;
};

int main(void)
{
	struct person man1, man2;
	strcpy(man1.name, "안성준");
	strcpy(man1.phoneNum, "010-1234-1234");
	man1.age = 23;


	printf("이름: "); scanf("%s", man2.name);
	printf("번호: "); scanf("%s", man2.phoneNum);
	printf("나이: "); scanf("%d", &(man2.age));

	printf("이름: %s\n", man1.name);
	printf("번호: %s\n", man1.phoneNum);
	printf("나이: %d\n", man1.age);

	printf("이름: %s\n", man2.name);
	printf("번호: %s\n", man2.phoneNum);
	printf("나이: %d\n", man2.age);

	return 0;
}


//22-1
struct employee {
	char name[BUFSIZ];
	char perID[BUFSIZ];
	int money;
};

int main(void)
{
	struct employee e1;

	printf("종업원 이름: "); scanf("%s", e1.name);
	printf("주민등록 번호: "); scanf("%s", e1.perID);
	printf("급여 정보(만원 단위): "); scanf("%d", &(e1.money));

	printf("%s\n", e1.name);
	printf("%s\n", e1.perID);
	printf("%d\n", e1.money);

	return 0;
}


//InitStructVal.c
struct point {
	int xpos;
	int ypos;
};
struct person {
	char name[20];
	char phoneNum[20];
	int age;
};
int main(void)
{
	struct point pos = { 10,20 };
	struct person man = { "이승기", "010-1111-2222", "21" };
	printf("%d %d\n\n", pos.xpos, pos.ypos);
	printf("%s %s %d\n\n", man.name, man.phoneNum, man.age);

	return 0;
}


//22-2
struct employee {
	char name[BUFSIZ];
	char phone[BUFSIZ];
	int money;
};

int main(void)
{
	struct employee arr[3];
	for (int i = 0;i < 3;i++) {
		printf("이름: "); scanf("%s", arr[i].name);
		printf("번호: "); scanf("%s", arr[i].phone);
		printf("연봉: "); scanf("%d", &(arr[i].money));

		//printf("%d", arr[i].money);
	}
	printf("\n\n\n");

	for (int i = 0;i < 3;i++) {
		printf("%s\n", arr[i].name);
		printf("%s\n", arr[i].phone);
		printf("%d", arr[i].money);
	}
}
*/