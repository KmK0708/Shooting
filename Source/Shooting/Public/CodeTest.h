// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodeTest.generated.h"

UCLASS()
class SHOOTING_API ACodeTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACodeTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 주석다는걸 생활화하기
	// 순서를 정하기,명확하게 설명하기
	// 정수형 변수 number를 설명한다
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CodeVariable)
	int32 number;
	//int32 number; = 0
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CodeVariable)
	int32 number2;

	// 실수형 변수 fnumber를 선언한다.
	float fnumber1 = 3.14f;
	float fnumber2 = 10;

	// 문자열 변수 name을 선언한다.
	FString name;
	//FString name = "";
	FString name2 = FString(TEXT("김주영"));

	// 논리형 변수 isStudent를 선언한다.
	bool isStudent;
	//bool isStudent = false; 아무것도 안써있으면 0이나 false
	bool isTeacher = true; 

	// 문자열 2개를 받아서 문자열 1개로 합쳐서 반환하는 함수를 만들려고 한다.
	// 함수선언 한것을 블루프린트에 불러오려면 UFUNCTION(BlueprintCallable)을 붙여준다.
	// 종속적으로 쓰이는 함수 블루프린트로 만들려면? UFUNCTION(BlueprintPure)를 붙여준다.
	UFUNCTION(BlueprintCallable)
	FString StringApender(FString firstname1, FString lastname1);

	int32 Add(int32 num1, int32 num2, int32 num3);
	int32 Subtract(int32 num1, int32 num2);
	int32 Multiply(int32 num1, int32 num2);
	float Divide(int32 num1, int32 num2);

	//UPROPERTY 는 언리얼 프로퍼티
	UPROPERTY(EditAnywhere, Category=CodeVariable)
	int32 age = 23;

	UPROPERTY(EditAnywhere, Category = CodeVariable)
    int32 height = 160;

	UPROPERTY(EditAnywhere, Category = CodeVariable)
	FString nation = FString(TEXT("한국"));

private:


};
