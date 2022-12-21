// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPlane.generated.h"

UCLASS()
class SHOOTING_API APlayerPlane : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPlane();
	//속도는 상시수정가능하게 public에 선언
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerSettings)
	float moveSpeed = 500;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//충돌 컴퍼넌트만들기
	//앞에다 전방선언(class)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = PlayerSettings)
	class UBoxComponent* boxComp;

	// 스태틱매쉬컴퍼넌트 만들기
	// 쓰더라도 마지막으로 자동완성 검증해보기
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = PlayerSettings)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = PlayerSettings)
	TSubclassOf<class ABullet> bulletFactory;

private:
	// 매개변수는 자기맘대로 이름짓기가능
	void Horizontal(float value);
	void Vertical(float value);
	void FireBullet();
	// action은 매개변수 비우기
	float h;
	float v;

	FVector direction;
};
