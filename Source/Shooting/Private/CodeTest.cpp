// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeTest.h"
#include "PointerTest.h"

// 기본 값을 설정 할 수 있다.
// 생성자 함수
ACodeTest::ACodeTest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACodeTest::BeginPlay()
{
	Super::BeginPlay();

#pragma region 사칙연산
	////Add 함수에 입력값 8, 4를 넣어서 결과를 result 변수에 받는다.
	//int32 result1 = Add(8, 4, 10);
	//int32 result2 = Subtract(8, 4);
	//int32 result3 = Multiply(8, 4);
	//float result4 = Divide(3, 11);


	//// result 변수에 있는 값을 화면에 출력한다.
	//UE_LOG(LogTemp, Warning, TEXT("Result1 : %d"), result1);
	//UE_LOG(LogTemp, Warning, TEXT("Result2 : %d"), result2);
	//UE_LOG(LogTemp, Warning, TEXT("Result3 : %d"), result3);
	//UE_LOG(LogTemp, Warning, TEXT("Result4 : %f"), result4);
	//

	////number 변수에 3을 넣는다
	////number = 3;
	////number2 = number;
	////number2 = -7;

	//fnumber1 = 3.14f;

	//number의 값을 output 콘솔창에 출력한다.
	/*UE_LOG(LogTemp, Warning, TEXT("number1 is %d,number2 is %d"), number, number2);
	UE_LOG(LogTemp, Warning, TEXT("float number is %.2f"), fnumber1);
	UE_LOG(LogTemp, Warning, TEXT("Hello World! %s"), *name2);

	isTeacher = true;

	if (isTeacher == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("그는 선생이다!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("그는 학생이다!"));
	}*/

#pragma endregion

#pragma region 조건문
	/*
	//만일 나이가 30살 이상이면 "꼰"이라고 출력하고 싶다.
	if (age >= 30)
	{
		UE_LOG(LogTemp, Warning, TEXT("틀"));
	}
	//그렇지 않고, 만일 나이가 20살 이상이면 "아조씨"라고 출력하고 싶다.
	else if (age >= 20)
	{
		UE_LOG(LogTemp, Warning, TEXT("아조씨"));
	}
	// 그렇지 않다면, "응애"라고 출력하고 싶다.
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("응애"));
	}

	//만일 나이가 20살 이상 이면서, 키가 160 이상인 경우에는
	if (age >= 20 && height >= 165)
	{
		// "환영" 이라고 출력한다
		UE_LOG(LogTemp, Warning, TEXT("어서와요"));
	}
	//그렇지 않으면
	else
	{
		//"넌 나가라"라고 출력한다
		UE_LOG(LogTemp, Warning, TEXT("넌 나가라"));
	}
	*/




	//만일 국적이 "한국"이면서 나이가 20살 이상 40살 미만이면
	//if (nation == TEXT("한국") && age >= 20 && age < 40)
	//{
	//	//군대가라 라고 출력
	//	UE_LOG(LogTemp, Warning, TEXT("군대가라"));

	//}
	//else
	//{
	//	//아닐시 군대아님 출력

	//	UE_LOG(LogTemp, Warning, TEXT("군대아님"));
	//}


#pragma endregion

#pragma region 조건문 실습
	//// 임시함수 fullName 선언, 문자열에 경우에는 *선언
	//// 한글로 출력하려면 TEXT로 감싸야함 영어는 그냥써도 상관없음
	//FString fullName = StringApender(TEXT("김"),(TEXT("주영")));
	//UE_LOG(LogTemp, Warning, TEXT("나의 이름은 : %s"), *fullName);
	//
	//int32 checker = 37;


	//// checker변수의 값이 짝수라면
	//if (checker % 2 == 0)
	//{
	//	//"even"이라고 출력한다.
	//	UE_LOG(LogTemp, Warning, TEXT("even"));
	//}
	////그렇지 않고, 변수의 값이 홀수라면,
	//else
	//{
	//	//"odd"라고 출력한다.
	//	UE_LOG(LogTemp, Warning, TEXT("odd"));
	//}
#pragma endregion

#pragma region 반복문
	//반복문
	// "안녕하세요" 라는 문자열을 10번 출력한다

	//for (int32 i = 0; i < 10; i = i + 1)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("%d"), i + 1);
	//}

	//int32 numb = 3;
	//// 누적 시킬때는 등호 앞에다 + 를 함 numb += 2;
	//numb += 2;
	//numb = numb + 2;
	//// 뺼때는 등호 앞에다 - 를 함 numb -= 2;
	//numb -= 2;
	//numb = numb - 2;


	//1단부터 9단까지 한번에 출력하게 하려면?
	//for (int32 i = 2; i < 10; i = i + 1)
	//{
	//	for (int32 j = 1; j < 10; j = j + 1)
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("%d * %d = %d"), i, j, i * j);
	//	}
	//	UE_LOG(LogTemp, Warning, TEXT("=============="));
	//}
	//내부 반복문이 한싸이클 돌면 외부 반복문이 한번 증가하게 하기

	/*for (int32 i = 1; i < 10; i = i + 1)
	{
		int32 resultM = 7 * i;
		UE_LOG(LogTemp, Warning, TEXT("7 * %d = %d"), i, resultM);
	}*/
#pragma endregion

#pragma region Array, Map
	//배열 예시

	////한글 쓸때는 text로 감싸지만 영어는 그냥 써도 상관없음
	/*distances.Add(TEXT("Seoul"), 250.51f);
	distances.Add(TEXT("Incheon"), 450.51f);
	distances.Add(TEXT("SeongNam"), 130.51f);*/
	// value는 중복가능, key는 중복시 크랙나서 튕김
	// 여기도 영어는 text로 안감싸도됨
	/*FString myKey = TEXT("Incheon");

	UE_LOG(LogTemp, Warning, TEXT(" %s : %f "), *myKey, distances[myKey]);*/

// 	for (auto dist : distances)
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT(" %s - %f "), *dist.Key, dist.Value);
// 	}

	//UE_LOG(LogTemp, Warning, TEXT(" Array Length %d "), ages.Num());

	/*for (int32 i = 0; i < ages.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d"), ages[i]);
	}*/

	//int32 number1 = 10;
	//int32 copyNum = number1;
	//number1 = 30;
	////number1 이 마지막줄에 30이 대입되서 copynum도 30 이 될거같지만,
	////이미 copynum은 number1이 10일때 복사된것이라 copynum은 10이 유지된채로 출력된다.

	//UE_LOG(LogTemp, Warning, TEXT(" number1 : %d, copyNum : %d "), number1, copyNum);

// 	int32 number1 = 10;
// 	int32* copyNum = &number1;
// 	//&는 number1의 주소값
// 	number1 = 30;
// 
// 	UE_LOG(LogTemp, Warning, TEXT(" number1 : %p, copyNum : %p "), &number1, copyNum);

// 	int32 aa = 10;
// 	int32 bb = 15;
// 	int32 cc = 30;
// 	int32 result;
// 	result = Add(&aa, &bb, &cc);
// 
// 	UE_LOG(LogTemp, Warning, TEXT("Result = %d, aa = %d, bb = %d , cc = %d"), result, aa, bb, cc);
#pragma endregion



	// 포인터가 nullptr로 인해 크러시가 나는걸 방지하려면 if문으로 방어한다.
	if (pointerTest != nullptr)
	{
		*(pointerTest->myAge) = 40;
	}
	


}
// Called every frame
void ACodeTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// int32 ACodeTest::Add(int32* num1, int32* num2, int32* num3)
// {
// 	// 구현 내용적는곳 반환시 앞에 return 달기
// 	*num1 *= 2;
// 	*num2 *= 2;
// 	*num3 *= 2;
// 
// 	int32 result = *num1 + *num2 + *num3;
// 	return result;
// }
// int32 ACodeTest::Subtract(int32 num1, int32 num2)
// {
// 	return num1 - num2;
// }
// int32 ACodeTest::Multiply(int32 num1, int32 num2)
// {
// 	return num1 * num2;
// }
// float ACodeTest::Divide(int32 num1, int32 num2)
// {
// 	return (float)num1 / (float)num2;
// }
// 
// // 함수이름앞에 클래스 붙여주기,클래스에 소속된 함수라는걸 알려주기위해 클래스뒤에::붙이기
// FString ACodeTest::StringApender(FString firstname1, FString lastname1)
// {
// 	// 문자열은 더하기만 된다.
// 	return firstname1 + lastname1;
//}