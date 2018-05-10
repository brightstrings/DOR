// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SceneController.h"
#include "GrissburgSceneController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT16_API AGrissburgSceneController : public ASceneController
{
	GENERATED_BODY()
	
public:
	//Place Actor in level at start
	AGrissburgSceneController();

	UFUNCTION(BlueprintCallable, Category = "Functions")
	void SetupLevel();

	void LoadLevel();

	void BeginPlay() override;
	
private:
	//void LoadCharactersFromFile();
};
