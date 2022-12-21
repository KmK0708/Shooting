// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPlane.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"			// 헤더에서 클래스 선언하면 cpp에서도 해주기
#include "UObject/ConstructorHelpers.h"
#include "Bullet.h"

// Sets default values
APlayerPlane::APlayerPlane()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 충돌 박스 컴퍼넌트를 생성한다
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT(" Box Collision "));

	// 생성된 충돌 박스 컴퍼넌트를 루트 컴퍼넌트로 설정한다.
	SetRootComponent(boxComp);

	// 박스 콜리젼에 크기를 가로x세로x높이 모두 50cm(반지름)로 설정한다
	// 멤버 변수 보려면 (포인터)->붙이기
	boxComp->SetBoxExtent(FVector(50.0f));		// 똑같은 값이면 50.0f만 해도 전부 적용됨

	// 메시 컴퍼넌트를 생성한다.
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	// 메시 컴퍼넌트를 루트 컴퍼넌트의 하위 개체로 등록한다.
	// 루트 컴퍼넌트를 써놓으면 이름 바꿔도 추적해서 등록해줌
	meshComp->SetupAttachment(RootComponent);

	// 메시 컴퍼넌트의 Static mesh 항목에 cube 파일을 할당한다.
	// 메시나 스테틱은 FObjectFinder
	ConstructorHelpers::FObjectFinder<UStaticMesh> cubeMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	// 만일, 큐브 파일을 로드하는데 성공했다면..
	if (cubeMesh.Succeeded())
	{
		// 로드한 파일을 메시 컴퍼넌트의 static mesh 항목에 넣는다.
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

	// 사용자가 입력한 방향대로 이동하고 싶다.
	// 벡터의 정규화
	direction.Normalize();

	// P = P0 + vt -> 어제보다 나은 오늘
	FVector dir = GetActorLocation() + direction * moveSpeed * DeltaTime;

	SetActorLocation(dir);
}

// Called to bind functionality to input
void APlayerPlane::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Horizontal Axis 입력에 함수를 연결한다.
	PlayerInputComponent->BindAxis("HorizontalMove", this, &APlayerPlane::Horizontal);
	
	// Vertical Axis 입력에 함수를 연결한다.
	PlayerInputComponent->BindAxis("VerticalMove", this, &APlayerPlane::Vertical);

	// Fire Action 입력에 함수를 연결한다.
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerPlane::FireBullet);
}

// 좌우 입력이 있을 때 실행될 함수
void APlayerPlane::Horizontal(float value)
{
	h = value;
	//UE_LOG(LogTemp, Warning, TEXT(" h : %.4f"), h);
	direction.Y = h;
}

// 상하 입력이 있을 때 실행될 함수
void APlayerPlane::Vertical(float value)
{
	v = value;
	//UE_LOG(LogTemp, Warning, TEXT(" v : %.4f"), v);
	direction.Z = v;
}

// 마우스 왼쪽 버튼을 눌렀을때, 실행 될 함수
void APlayerPlane::FireBullet()
{
	// 총알을 생성한다.
	// 총알 blueprint 변수 
	FVector spawnPosition = GetActorLocation() + GetActorUpVector() * 90.0f;
	//위로 회전해서 보낼것이기에 pitch 방향으로 회전시킨다.
	FRotator spawnRotation = FRotator(90.0f, 0, 0);
	FActorSpawnParameters param;
	param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<ABullet>(bulletFactory, spawnPosition, spawnRotation, param);
}

