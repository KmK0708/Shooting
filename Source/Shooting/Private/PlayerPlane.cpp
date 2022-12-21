// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPlane.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"			// ������� Ŭ���� �����ϸ� cpp������ ���ֱ�
#include "UObject/ConstructorHelpers.h"
#include "Bullet.h"

// Sets default values
APlayerPlane::APlayerPlane()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �浹 �ڽ� ���۳�Ʈ�� �����Ѵ�
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT(" Box Collision "));

	// ������ �浹 �ڽ� ���۳�Ʈ�� ��Ʈ ���۳�Ʈ�� �����Ѵ�.
	SetRootComponent(boxComp);

	// �ڽ� �ݸ����� ũ�⸦ ����x����x���� ��� 50cm(������)�� �����Ѵ�
	// ��� ���� ������ (������)->���̱�
	boxComp->SetBoxExtent(FVector(50.0f));		// �Ȱ��� ���̸� 50.0f�� �ص� ���� �����

	// �޽� ���۳�Ʈ�� �����Ѵ�.
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	// �޽� ���۳�Ʈ�� ��Ʈ ���۳�Ʈ�� ���� ��ü�� ����Ѵ�.
	// ��Ʈ ���۳�Ʈ�� ������� �̸� �ٲ㵵 �����ؼ� �������
	meshComp->SetupAttachment(RootComponent);

	// �޽� ���۳�Ʈ�� Static mesh �׸� cube ������ �Ҵ��Ѵ�.
	// �޽ó� ����ƽ�� FObjectFinder
	ConstructorHelpers::FObjectFinder<UStaticMesh> cubeMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	// ����, ť�� ������ �ε��ϴµ� �����ߴٸ�..
	if (cubeMesh.Succeeded())
	{
		// �ε��� ������ �޽� ���۳�Ʈ�� static mesh �׸� �ִ´�.
		meshComp->SetStaticMesh(cubeMesh.Object);
	}

}

// Called when the game starts or when spawned
void APlayerPlane::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ����ڰ� �Է��� ������ �̵��ϰ� �ʹ�.
	// ������ ����ȭ
	direction.Normalize();

	// P = P0 + vt -> �������� ���� ����
	FVector dir = GetActorLocation() + direction * moveSpeed * DeltaTime;

	SetActorLocation(dir);
}

// Called to bind functionality to input
void APlayerPlane::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Horizontal Axis �Է¿� �Լ��� �����Ѵ�.
	PlayerInputComponent->BindAxis("HorizontalMove", this, &APlayerPlane::Horizontal);
	
	// Vertical Axis �Է¿� �Լ��� �����Ѵ�.
	PlayerInputComponent->BindAxis("VerticalMove", this, &APlayerPlane::Vertical);

	// Fire Action �Է¿� �Լ��� �����Ѵ�.
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerPlane::FireBullet);
}

// �¿� �Է��� ���� �� ����� �Լ�
void APlayerPlane::Horizontal(float value)
{
	h = value;
	//UE_LOG(LogTemp, Warning, TEXT(" h : %.4f"), h);
	direction.Y = h;
}

// ���� �Է��� ���� �� ����� �Լ�
void APlayerPlane::Vertical(float value)
{
	v = value;
	//UE_LOG(LogTemp, Warning, TEXT(" v : %.4f"), v);
	direction.Z = v;
}

// ���콺 ���� ��ư�� ��������, ���� �� �Լ�
void APlayerPlane::FireBullet()
{
	// �Ѿ��� �����Ѵ�.
	// �Ѿ� blueprint ���� 
	FVector spawnPosition = GetActorLocation() + GetActorUpVector() * 90.0f;
	//���� ȸ���ؼ� �������̱⿡ pitch �������� ȸ����Ų��.
	FRotator spawnRotation = FRotator(90.0f, 0, 0);
	FActorSpawnParameters param;
	param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<ABullet>(bulletFactory, spawnPosition, spawnRotation, param);
}

