// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SEQ.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "M3dCharacter.generated.h"//for reflection system
									//annotate variables I want to be visible to the reflection system using UCLASS() etc.
									//UENUM(), UCLASS(), USTRUCT(), UFUNCTION(), and UPROPERTY()
									//https://www.unrealengine.com/en-US/blog/unreal-property-system-reflection
//#include "Filename.generated.h"

class ASceneController;

#define MOUTH_KEYFRAME_DURATION 0.06

#ifndef HEAD_EYES
	#define HEAD_EYES

	struct HeadEyes
	{
		HeadEyes();

		float time_from_start;//used to insert eyes or mouth state into existing list of eyesmouth at a particular time
		int index_eyes;
		int index_mouth;

		static bool ReadKeyframe(IFileHandle* FileHandle, HeadEyes* keyframe_out);
	};
#endif

#ifndef BODY_HEAD_ANIMATION_SET
#define BODY_HEAD_ANIMATION_SET
	class BodyHeadAnimationSet
	{
	public:
		TArray<KEYFRAME> HEAD_KEYS;//1-to-1 with BODY_KEYS
		TArray<KEYFRAME> BODY_KEYS;//1-to-1 with HEAD_KEYS
		TArray<HeadEyes> EyesMouth;//empty(-1) if body head keyframe is encountered so that index is correct
								   //insert these into eyes mouth seq at index e.g. EyesMouth[i] to i of mouth_eyes_keyframes
	};
#endif

#ifndef STRUCT_M3D
#define STRUCT_M3D
struct M3D
{
	M3D();

	FString code;
	int m3d_number;//e.g. 1-60, this is used for getting filename in ToFileName().
	FVector Position;
	FVector Pivot;

	FString ToFileName();
};
#endif

typedef FLinearColor FRECT;

/**
 * UCLASS() to indicate class(M3dCharacter) is reflected
 */
UCLASS()

class PROJECT16_API UM3dCharacter : public UObject
{
	GENERATED_UCLASS_BODY()//I think this is needed for reflection, yes it is required

public:
	//UM3dCharacter(class FObjectInitializer const&);
	~UM3dCharacter();

	void Initialize();
	//m3d objects here are used for positioning characters, after they have
	//been assigned to a slot and need to be assigned to a different slot
	M3D m3d_head;
	M3D m3d_body;
	M3D m3d_neck;
	M3D m3d_helmet;

	void RemoveReferences(ASceneController* scene);//puts character materials up for garbage collection(UObjects)

	void SetBodyAnimation(int animation_set, ASceneController* scene);
	//int int_previous_animation_set;
	int int_body_animation;
	//ASceneController* scene;//holds loaded animation sets

	//TArray<BodyHeadAnimationSet>* animation_sets;

	void LoadMouthSequence(int animation_set, ASceneController* scene);
	void MergeMouthSequences(TArray<BodyHeadAnimationSet>& loaded_sets);

	int ID;

	float health;//regiment health used to determine injured looks
				 //e.g. use MB_HEADI if health is <70.0%
	//bool character_lit;//has focus
	bool is_talking;
	float MouthX;
	float MouthY;
	float MouthWidth;//from heads.db
	float MouthHeight;
	float EyesX;
	float EyesY;
	float EyesWidth;//from heads.db
	float EyesHeight;

	void SetBodyTexture(FString code, UTexture* tex, UMaterialInterface* BodyMaterial,ASceneController* scene);
	void SetHeadTexture(FString code, UMaterialInterface* GenericHeadMaterial, ASceneController* scene);
	void SetBodyTexture(FString code, UMaterialInterface* GenericBodyMaterial, ASceneController* scene);
	void SetNeckTexture(FString code, UMaterialInterface* GenericBodyMaterial, ASceneController* scene);
	UPROPERTY()
	UStaticMeshComponent* MeshHead;
	UPROPERTY()
	UStaticMeshComponent* MeshHeadMask;
	FVector HeadStartPosition;//so precision is not lost
	FVector HeadMaskStartPosition;
	FVector HeadPivot;
	FVector HeadMaskPivot;
	UPROPERTY()
	UStaticMeshComponent* MeshBody;
	UPROPERTY()
	UStaticMeshComponent* MeshBodyMask;
	FVector BodyStartPosition;//so precision is not lost
	FVector BodyMaskStartPosition;
	FVector BodyPivot;
	FVector BodyMaskPivot;
	UPROPERTY()
	UStaticMeshComponent* MeshNeck;
	UPROPERTY()
	UStaticMeshComponent* MeshNeckMask;
	FVector NeckStartPosition;//so precision is not lost
	FVector NeckMaskStartPosition;
	FVector NeckPivot;
	FVector NeckMaskPivot;

	void Update(float DeltaTime, ASceneController* scene);//this is where the mouth will be animated

private:
	UPROPERTY()//for reflection(null on garbage collect)
	UMaterialInstanceDynamic* MatInst;//Body
	UPROPERTY()//for reflection(null on garbage collect)
	UMaterialInstanceDynamic* MatInstHead;
	UPROPERTY()//for reflection(null on garbage collect)
	UMaterialInstanceDynamic* MatInstNeck;

	//SEQ HeadAnimationKeys;
	//SEQ BodyAnimationKeys;

	TArray<HeadEyes> mouth_eyes_keyframes;
	//FRECT DisplayRegionMouth;
	FRECT BitsRegionMouth;//Mouth state
	//FRECT DisplayRegionEyes;
	FRECT BitsRegionEyes;

	FRECT ToFRectMouth(int index);
	FRECT ToFRectEyes(int index);
	void PlayMouthSequence(float DeltaTime, bool eyes_only);
	//void PlayEyesSequence(float DeltaTime);
	float mouth_elapsed;//used to determine which keyframe to display
	int mouth_keyframe;

	//Body animation
	void PlayBodySequence(float DeltaTime, ASceneController* scene);
	void UpdateBody();//rotates head and body
	float animation_elapsed;
	SEQ HeadAnimation;
	SEQ BodyAnimation;
};
