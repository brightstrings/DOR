// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundManager2.h"

SoundManager2::SoundManager2()
{
}

SoundManager2::~SoundManager2()
{
}

//UAudioComponent* SoundManager2::audio_component = NewObject<UAudioComponent>(NULL, *FString("comp_name"));
UAudioComponent* SoundManager2::audio_component = NULL;

void SoundManager2::Initialize(UObject* outer)
{
	audio_component = NewObject<UAudioComponent>(outer, *FString("comp_name"));
}

USoundWave* SoundManager2::current_sound = NULL;

void SoundManager2::PlaySound(UObject* outer, FString name)
{
	FString full_name = "/Game/Sounds/" + name + "." + name;
	current_sound = LoadObject<USoundWave>(outer, *full_name);
	audio_component->SetSound(current_sound);
	//sound->
	//sound->w
	//sound->
	audio_component->Play();
	//audio_component->
}

void SoundManager2::StopSound(UObject* outer)
{
	//FString full_name = "/Game/Sounds/" + name + "." + name;
	//current_sound = LoadObject<USoundWave>(outer, *full_name);
	//audio_component->SetSound(current_sound);
	//sound->
	//sound->w
	//sound->
	audio_component->Stop();
	//audio_component->
}