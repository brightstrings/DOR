// Fill out your copyright notice in the Description page of Project Settings.

#include "LightActor.h"


// Sets default values
ALightActor::ALightActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FString light_name = "FocusLight";
	focus_light = CreateDefaultSubobject<UPointLightComponent>(*light_name);

	//set position and intensity to see if light works
	FVector LightLocation(-5.000000, 20.000000, 2.000000);
	focus_light->SetWorldLocation(LightLocation);
	focus_light->SetIntensity(250.0f);//good

	//focus_light->;

}

// Called when the game starts or when spawned
void ALightActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

