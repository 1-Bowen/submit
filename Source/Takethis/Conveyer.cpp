// Fill out your copyright notice in the Description page of Project Settings.


#include "Conveyer.h"
#include "TakethisCharacter.h"

// Sets default values
AConveyer::AConveyer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	RootComponent = BaseMesh;
	Forward = 250000;
	Up = { 0,0,25000 };
	
}

// Called when the game starts or when spawned
void AConveyer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConveyer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}


void AConveyer::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto player = Cast<ACharacter>(OtherActor);
	if(player != nullptr)
	{
		OtherActor->GetComponentByClass(UCharacterMovementComponent::StaticClass());
		player->GetCharacterMovement()->AddImpulse(player->GetActorForwardVector() * Forward + Up);
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Black, TEXT("Conveyer Touched"));

		if (Sound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation());
		}
	}

}
