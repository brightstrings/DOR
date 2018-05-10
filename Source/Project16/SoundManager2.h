// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"
#include "Runtime/Engine/Classes/Components/AudioComponent.h"
#include "Runtime/Engine/Classes/Sound/AmbientSound.h"

/**
 * 
 */
class PROJECT16_API SoundManager2
{
public:
	SoundManager2();
	~SoundManager2();

	static void PlaySound(UObject* outer, FString name);
	static void StopSound(UObject* outer);

	static void Initialize(UObject* outer);

private:
	//static TArray<USoundWave*> playing_sounds;
	static USoundWave* current_sound;

	//FString comp_name = "AudioComponent";
	static UAudioComponent* audio_component;// = NewObject<UAudioComponent>(this, *comp_name);
};
