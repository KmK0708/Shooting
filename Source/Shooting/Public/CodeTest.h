// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodeTest.generated.h"			// 헤더파일 가져올 시, ~generated.h 파일 위에 적어야함

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

	UPROPERTY(EditAnywhere, Category = "CodeVariable")
	class APointerTest* pointerTest;

private:


};
