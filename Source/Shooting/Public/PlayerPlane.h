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
	//�ӵ��� ��ü��������ϰ� public�� ����
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

	//�浹 ���۳�Ʈ�����
	//�տ��� ���漱��(class)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = PlayerSettings)
	class UBoxComponent* boxComp;

	// ����ƽ�Ž����۳�Ʈ �����
	// ������ ���������� �ڵ��ϼ� �����غ���
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = PlayerSettings)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = PlayerSettings)
	TSubclassOf<class ABullet> bulletFactory;

private:
	// �Ű������� �ڱ⸾��� �̸����Ⱑ��
	void Horizontal(float value);
	void Vertical(float value);
	void FireBullet();
	// action�� �Ű����� ����
	float h;
	float v;

	FVector direction;
};
