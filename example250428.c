#define _CRT_SECURE_NO_WARNINGS	//	이거 안쓰면 scanf_s 처리가 잘 안됨 왜지?
#include <stdio.h>
#include <string.h>			//	BUFSIZ는 stdio내장. strlen사용(문자열길이파악)시 포함시킬 것.(물론 하단은 그냥 널문자로 문자열의 끝을 파악)

/*
//ArrayNameType.c
int main(void)
{
	int arr[3] = { 0,1,2 };
	printf("배열 이름: %p\n", arr);
	printf("첫번째 요소: %p\n", &arr[0]);
	printf("두번째 요소: %p\n", &arr[1]);
	printf("세번째 요소: %p\n", &arr[2]);

	return 0;
}
*/

/*
int main(void)
{
	int arr[3] = { 0, 1, 2 };
	int* p = arr;
	printf("Name of Array : %p\n", arr);
	printf("1st element : %d\n", *(arr + 0));
	printf("2nd element : %d\n", *(arr + 1));
	printf("3rd element : %d\n", *(arr + 2));

	printf("1st element : %d\n", p[0]);
	printf("2nd element : %d\n", p[1]);
	printf("3rd element : %d\n", p[2]);
	return 0;
}
*/

/*
//ArrayNamePointerOperation.c
int main(void)
{
	int arr1[3] = { 1,2,3 };
	double arr2[3] = { 1.1, 2.2, 3.3 };

	printf("%d %g\n", *arr1, *arr2);
	*arr1 += 100;
	*arr2 += 120.5;
	printf("%d %g\n", arr1[0], arr2[0]);

	return 0;
}


//ArrayNameIsPointer.c
int main(void)
{
	int arr[3] = { 15,25,35 };
	int* ptr = &arr[0];

	printf("%d %d \n", ptr[0], arr[0]);
	printf("%d %d \n", ptr[1], arr[1]);
	printf("%d %d \n", ptr[2], arr[2]);
	printf("%d %d \n", *ptr, *arr);

	return 0;
}


//PointerOperationResult.c
int main(void)
{
	int* ptr1 = 0x0010;
	double* ptr2 = 0x0010;

	printf("%p %p\n", ptr1 + 1, ptr1 + 2);
	printf("%p %p\n", ptr2 + 1, ptr2 + 2);

	printf("%p %p\n", ptr1, ptr2);
	ptr1++;
	ptr2++;
	printf("%p %p\n", ptr1, ptr2);

	return 0;
}


//PointerBaseArrayAccess.c
int main(void)
{
	int arr[3] = { 11,22,33 };
	int* ptr = arr;
	printf("%d %d %d\n", *ptr, *(ptr + 1), *(ptr + 2));

	printf("%d    ", *ptr); ptr++;
	printf("%d    ", *ptr); ptr++;
	printf("%d    ", *ptr); ptr--;
	printf("%d    ", *ptr); ptr--;
	printf("%d    ", *ptr); printf("\n");

	return 0;
}


//13-1-2
int main(void)
{
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = arr;

	for (int i = 0;i < 5;i++) {
		*(ptr + i) += 2;
		printf("%d \n", *(ptr + i));
	}
	return 0;
}


//13-1-1
int main(void)
{
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = arr;

	for (int i = 0;i < 5;i++) {
		*ptr += 2;
		printf("%d \n", *ptr);
	}

	return 0;
}


//13-1-3
int main(void)
{
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = &arr[4];
	int sum = 0;

	for (int i = 0;i < 5;i++) {
		sum += *ptr;
		printf("%d\n", *ptr);
		ptr--;
	}

	printf("\n\n 합은: %d", sum);

	return 0;
}


// 다시 해야함!
//13-1-4
int main(void)
{
	int arr[6] = { 1,2,3,4,5,6 };
	int* ptr1 = arr;
	int* ptr2 = &arr[5];

	for (int i = 0;i < 6;i++) {
		ptr1
	}

	return 0;
}


//TwoStringType.c
int main(void)
{
	char str1[] = "My String";
	char* str2 = "Your String";
	printf("%s %s\n", str1, str2);

	str2 = "Our String";
	printf("%s\n", str2);

	str1[0] = 'X';										//	가능
//	str2[0] = 'X';										//	불가
	printf("%s %s\n", str1, str2);

	return 0;
}


//PointerArray.c
int main(void)
{
	int num1 = 10, num2 = 20, num3 = 30;
	int* arr[3] = { &num1, &num2, &num3 };

	printf("%p\n", arr[0]);
	printf("%p\n", &num1);

	printf("%p\n", arr[1]);
	printf("%p\n", arr[2]);


	printf("%d\n", *arr[0]);
	printf("%d\n", *arr[1]);
	printf("%d\n", *arr[2]);

	return 0;
}


//StringArray.c
int main(void)
{
	char* strArr[3] = { "Simple", "String", "Array" };
	printf("%s \n", strArr[0]);
	printf("%s \n", strArr[1]);
	printf("%s \n", strArr[2]);

	return 0;
}


//ArrayParam.c
void ShowArrayElement(int* param, int len)
{
	int i;
	for (i = 0;i < len;i++) printf("%d  ", param[i]);
	printf("\n");
}

int main(void)
{
	int arr1[3] = { 1,2,3 };
	int arr2[5] = { 4,5,6,7,8 };
	ShowArrayElement(arr1, sizeof(arr1) / sizeof(int));
	ShowArrayElement(arr2, sizeof(arr2) / sizeof(int));

	return 0;
}


//ArrayParamAccess.c
void ShowArrayElem(int* param, int len)
{
	int i = 0;
	for (i = 0;i < len;i++) printf("%d ", param[i]);
	printf("\n");
}
void AddArrayElem(int* param, int len, int add)
{
	for (int i = 0;i < len;i++) param[i] += add;
}
int main(void)
{
	int arr[3] = { 1,2,3 };
	AddArrayElem(arr, sizeof(arr) / sizeof(int), 1);
	ShowArrayElem(arr, sizeof(arr) / sizeof(int));

	AddArrayElem(arr, sizeof(arr) / sizeof(int), 2);
	ShowArrayElem(arr, sizeof(arr) / sizeof(int));

	AddArrayElem(arr, sizeof(arr) / sizeof(int), 3);
	ShowArrayElem(arr, sizeof(arr) / sizeof(int));

	return 0;
}


//CallByValue.c
void Swap(int n1, int n2)
{
	int tmp = n1;
	n1 = n2;
	n2 = tmp;
	printf("2. n1 n2 : %d %d \n", n1, n2);
}

int main(void)
{
	int num1 = 10, num2 = 20;
	printf("1. num1 num2 : %d %d\n", num1, num2);

	Swap(num1, num2);
	printf("3. num1 num2 : %d %d", num1, num2);

	return 0;
}


//CallByRefSwap.c
void Swap(int* p1, int* p2);

int main(void)
{
	int num1 = 10, num2 = 20;
	printf("1. num1 num2 : %d %d\n", num1, num2);

	Swap(&num1, &num2);
	printf("2. num1 num2 : %d %d", num1, num2);

	return 0;
}
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//14-1-1
int SquareByValue(int n1);
int SquareByReference(int* p);

int main(void)
{
	int num1 = 5, num2 = 10;
	int* pnum = &num2;

	printf("%d\n", SquareByValue(num1));
	printf("%d\n", SquareByReference(pnum));

	return 0;
}

int SquareByValue(int n1)
{
	int tmp = n1 * n1;
	return tmp;
}

int SquareByReference(int* p)
{
	int tmp = *p * (*p);
	return tmp;
}


//14-2-2
void Swap3(int* n1, int* n2, int* n3);

int main(void)
{
	int num1 = 1, num2 = 2, num3 = 3;
	Swap3(&num1, &num2, &num3);
	return 0;
}

void Swap3(int* n1, int* n2, int* n3)
{
	int ptmp = *n1;
	*n1 = *n2;
	*n2 = *n3;
	*n3 = ptmp;
	printf("%d %d %d\n", *n1, *n2, *n3);
}
*/
/*
//exercise 15-1 "제발! 포인터 연습하는 거 잘하자"
int main(void)
{
	int num[10];
	for (int i = 0; i < 10; i++) {
		printf("%d : ", i + 1), scanf_s("%d", &num[i]);
	}
	printf("Odd number :");
	for (int i = 0; i < 10; i++) {
		//printf("%d!!!!!!\n", (num[i] & 01));
		if ((num[i] & 1) == 1)
			printf(" %d", num[i]);
	}

	printf("\nEven number :");
	for (int i = 0; i < 10; i++) {
		if ((num[i] & 1) == 0)
			printf(" %d", num[i]);
	}
	printf("\n");


	return 0;
}
*/


/*
//exercise15-3
int main(void)
{
  int num[10], a;
  int *start = num; //&num[0]
  int *end = num+9; //&num[9]
  for(int i = 0; i < 10; i++) {
	printf("%d : ", i+1), scanf_s("%d", &a);
	if((a&01)==0)*(end--)=a; else *(start++)=a;
  }
  printf("Print the Element of Array : [");
  for(int i = 0; i < 10; i++) {
	printf("%d, ", num[i]);
  }
  printf("\b\b]\n");							// 띄어쓰기와 ','를 지우기 위함

  return 0;
}
*/


//int main(void)
//{
//	char* pString = "12345";
//	int tmp = strlen(pString);
//	
//	printf("%d", (int)strlen(pString)); //만약 12345문자열 중간에 \0있으면 거길 끝으로 판단 -> 여기서 5 출력(6이 아니고)
//	//strlen은 널문자를 제외하고 문자열 길이 알려줌
//
//	printf("\n%d", tmp / 2); // 홀수면 버림 취급
//	return 0;
//}


/*
//거울문자열
int main(void)
{
	char str[BUFSIZ];
	int len = 0;
	printf("Input some string : ");
	//scanf("%s", str);
	scanf_s("%s", str, (unsigned int)sizeof(str)); //	scanf_s는 인자를 하나 더 요구, scanf는 기존보다 문자 많이 받아서 보안 위험 있으니까
	//sizeof는 unsigned int로 지정해줘야(vs가 64비트라서 4바이트보다 자료형이 커서)

	while (1) { //string.h에 있는 strlen대신 구현
		if (str[len] == '\0')
			break;
		len++;
	}
	printf("Length : %d\n", len);

	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) {
			printf("This is not Palindrome\n");
			break;
		}
		else {
			printf("This is Palindrome");
			break;
		}
	}

	return 0;
}
*/

/*
//TwoDimArraySize.c
int main(void)
{
	int arr1[3][4];
	int arr2[7][9];

	printf("세로3 가로4 : %d\n", sizeof(arr1));
	printf("세로7 가로9 : %d\n", sizeof(arr2));

	return 0;
}


//PopuResearch.c
int main(void)
{
	int villa[4][2];
	int popu, i, j;

	//가구별 거주인원 입력 받기
	for (i = 0;i < 4;i++) {
		for (j = 0;j < 2;j++) {
			printf("%d층 %d호 인구수: ", i + 1, j + 1);
			scanf_s("%d", &villa[i][j]);
		}
	}

	//빌라의 층별 인구수 출력하기
	for (i = 0;i < 4;i++) {
		popu = 0;
		popu += villa[i][0];
		popu += villa[i][1];
		printf("%d층 인구수 : %d \n", i + 1, popu);
	}

	return 0;
}


//TwoDimArrayInit.c
int main(void)
{
	int i, j = 0;

	//2차원 배열 초기화 예1
	int arr1[3][3] = {
		{1,2,3},
		{ 4,5,6 },
		{ 7,8,9 }
	};

	//2차원 배열 초기화 예2
	int arr2[3][3] = {
		{1},
		{ 4,5,},
		{ 7,8,9 }
	};

	//2차원 배열 초기화 예3
	int arr3[3][3] = { 1,2,3,4,5,6,7 };

	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}


//16-1-1
int main(void)
{
	int arr[3][9];
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 9;j++) {
			arr[i][j] = (i + 2) * (j + 1);
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}


//16-1-2
int main(void)
{
	int arrA[2][4] = { 1,2,3,4,5,6,7,8 };
	int arrB[4][2] = { 0 };

	for (int j = 0;j < 4;j++) {
		for (int i = 0;i < 2;i++) {
			arrB[j][i] = arrA[i][j];
			printf("%d ", arrB[j][i]);
		}
		printf("\n");
	}

	return 0;
}


//16-1-3
int main(void)
{
	int arrScr[5][5] = { 0 };

	for (int i = 0;i < 4;i++) {
		printf("\n사람 %d? ", i+1);
		for (int j = 0;j < 4;j++) {
			printf("\n점수 입력: ");
			scanf_s("%d", &arrScr[i][j]);
		}
	}
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			arrScr[4][j] += arrScr[i][j];
		}
	}
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 4;j++) {
			arrScr[i][4] += arrScr[i][j];
		}
	}

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			printf("%4d", arrScr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
*/