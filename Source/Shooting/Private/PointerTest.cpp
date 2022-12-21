// Fill out your copyright notice in the Description page of Project Settings.


#include "PointerTest.h"

// Sets default values
APointerTest::APointerTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//포인터에서 크래시가 안나려면 생성자 함수에서 적는다.
	myAge = &realAge;
}

// Called when the game starts or when spawned
void APointerTest::BeginPlay()
{
	Super::BeginPlay();

	
	//포인터 변수면 주소값(&)넣음
	
}

// Called every frame
void APointerTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

