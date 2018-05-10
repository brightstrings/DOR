// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "GameFramework/Actor.h"
//#include "Runtime."
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "SEQ.h"
#include "M3dCharacter.h"
//#include "MeshActor.h"
#include "Runtime/Engine/Classes/Sound/AmbientSound.h"
#include "LightActor.h"
#include "SceneController.generated.h"

TCHAR ord(unsigned char byte);

float DecodeToFloat(uint8 a, uint8 b, uint8 c, uint8 d);

struct DBEntry
{
	DBEntry();

	wchar_t ID[3];//3
	unsigned char Flags;
	unsigned char KeySeq;
	unsigned char zero;
	unsigned char MouthWidth;
	unsigned char MouthHeight;
	unsigned char MouthX;
	unsigned char MouthY;
	unsigned char EyesWidth;
	unsigned char EyesHeight;
	unsigned char EyesX;
	unsigned char EyesY;

	char body_mesh_id;
	signed char body_x;
	signed char body_y;
	signed char body_z;

	char head_mesh_id;
	signed char head_x;
	signed char head_y;
	signed char head_z;

	char head_movement_multiplier;//I think this is the multiplier for 03 00 entries. multiply degrees by this value.
	char KeyID;//I can't think what this is. always 0?

	char NeckID;
	signed char neck_x;
	signed char neck_y;
	signed char neck_z;

	char WeaponID;
	signed char weapon_x;
	signed char weapon_y;
	signed char weapon_z;

	char BackPackID;
	signed char back_pack_x;
	signed char back_pack_y;
	signed char back_pack_z;

	char HelmetID;
	signed char helmet_x;
	signed char helmet_y;
	signed char helmet_z;

	static DBEntry ReadNextEntry(IFileHandle* FileHandle);
};
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

//USTRUCT()
USTRUCT()
struct FPortrait {
	GENERATED_BODY()

	FPortrait()
	{
		//Inst = NULL;//Material instance from editor
		//MIDynamic = NULL;//MI1 is the dynamic and Inst is the editor material
		MIDynamicBackground = NULL;
	}

	int PortraitID;
	UPROPERTY()
	UImage* portrait_image;
	UPROPERTY()
	UImage* portrait_border;
	UPROPERTY()
	UImage* portrait_background;
	int CharacterID;

	//StaticMesh* Head;
	//StaticMesh* Body;
	//StaticMesh* 
	//SEQ

	//UMaterialInstance* Inst;
	//UMaterialInstanceDynamic* MIDynamic;
	UPROPERTY()
	UMaterialInstanceDynamic* MIDynamicBackground;
	UPROPERTY()
	UTexture* tex_background;
};

struct COMMAND
{
	COMMAND() {
		create_character = false;
		spawn_portrait = false;
		set_focus = false;
		DestroyPortrait = false;
		stop_talking = false;
		//audio_delay = 0.0f;//time until start audio
		start_talking = false;
		skip_on_click = false;//do not skip
	}
	bool stop_talking;
	bool create_character;
	int CharacterID;//id of character for future reference e.g. DestroyCharacter(CharacterID) or DestroyPortrait(CharacterID)
					//CharacterID and PortraitID are not the same but not same as dbPortraitID
	float duration;//how long till next command?
	bool spawn_portrait;
	int dbPortraitID;//the 12b entry holding texture MB etc. use this to load .m3d files and create character
	int PortraitID;//1 to 4, there might be 4 portraits and 5 characters so PortraitID is not the same as CharacterID.
	int DisplayCharacterID;//the character to display in this portait
	FString BackgroundName;//background texture
	float spawn_x;//without scaling at 640x480
	float spawn_y;
	int AnimationSet;//I should calculate the key(when the animation set starts==last key of loaded set), and save it to the character or portrait for later when focus is set
					 //the animation set used when lit by the portrait, should always be set in every command, hopefully one animation set is enough
	int AnimationSet2;//ignore this for now
	bool set_focus;
	int focusPortraitID;//1to4
	bool DestroyPortrait;
	int DestroyPortraitID;//1to4
	//I did vertex colours today, that's good, 
	FString audio;//name of file in Sounds directory
	bool start_talking;//separate from set focus command
	//float audio_delay;
	bool skip_on_click;
};

struct RENDER_SLOT
{
	RENDER_SLOT() {
		mat = NULL;
		taken = false;
		//c = NULL;
		CharacterID = -1;
	}

	//M3dCharacter* c;
	int CharacterID;//the character assigned to the slot
					//used for finding the slot when I know the character.

	//position of slot origin
	FVector Position;
	//position of white(mask) slot origin
	FVector MaskPosition;

	bool taken;

	//UMaterial* img1mat;//loading materials must be done in constructors, so use fixed name, or could use list, I'll go with fixed name "img1mat"
	UMaterial* mat;//TargetMaterial1 has render target 1, targetMaterial2 has render target 2, TargetMaterial3 has render target 3, that's the difference
	UMaterial* mat_border;
};
/*
class BodyHeadAnimationSet
{
public:
	TArray<KEYFRAME> HEAD_KEYS;//1-to-1 with BODY_KEYS
	TArray<KEYFRAME> BODY_KEYS;//1-to-1 with HEAD_KEYS
	TArray<HeadEyes> EyesMouth;//empty(-1) if body head keyframe is encountered so that index is correct
							   //insert these into eyes mouth seq at index e.g. EyesMouth[i] to i of mouth_eyes_keyframes
};
*/
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

UCLASS()
class PROJECT16_API ASceneController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASceneController();

	//FString delayed_audio;
	//float delay_elapsed;
	//float delay;

	UFUNCTION(BlueprintCallable, Category = "Functions")
	void LeftMousePressed();

	//UPROPERTY()
	//UTexture2D* arrow_right_texture;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors")
	//AM3dActor* my_m3d_actor_blueprint;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors")
	//TSubclassOf<class AM3dActor> my_m3d_actor_blueprint;

	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> wDougUIBlueprint;
	//Not set in editor, set in Level Blueprint:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Background Music")
	USoundBase* base_sound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Background Music")
	USoundCue* sound;
	//TSubclassOf<class AActor> sound;
	//TSubclassOf<class AAmbientSound> sound;// wDougUIBlueprint;
	UAudioComponent* audio_component;

	//UFUNCTION(BlueprintCallable, Category="Functions")
	void CreateUI();

	//UStaticMesh* StaticMesh;
	UPROPERTY()
	//TArray<FString> AllCharacterIDs;
	TMap<int, UM3dCharacter*> characters;//id character
	TArray<FPortrait> portraits;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lights")
	FVector RelativeToSlotLightPos;
	ALightActor* focus_light;
	ALightActor* light1;
	ALightActor* light2;
	ALightActor* light3;
	ALightActor* light4;
	//UPointLightComponent* focus_light;

	//TArray<UStaticMeshComponent> MeshComponents;

	//int next_character_id;

	float elapsed;//A variable that controls the whole sequence of the scene, each command, this is only increased if the game is not paused.
	bool paused;//the paused state of the game
	//TODO:
	//void SpawnCharacter(RENDER_SLOT* out_slot);//spawns a character to a free slot
	//virtual void LoadCharactersFromFile();
	void CreateCharacter(int NewID, M3D m3d_head, M3D m3d_body, M3D m3d_neck, M3D m3d_helmet);//returns id
	void AssignCharacterToSlot(int ID, RENDER_SLOT* slot);
	//void AssignCharacterToSlot(int ID, RENDER_SLOT* slot);
	void SpawnImage(float screen_x, float screen_y, float scale_x, float scale_y);
	void PlayScene(float DeltaTime);//called if the game is not paused.
	void ExecuteCommand(COMMAND command);

	TArray<COMMAND> commands;
	float command_elapsed;//time elapsed since last command was executed
	float duration;//0 for fist c

	void AddCommand(COMMAND command);

	RENDER_SLOT* FindFreeSlot();

	//slots used by characters that are being rendered to targets,
	//only  4 max for any scene in dark omen, maybe 5
	//if 5 can fit
	//these can also be called "render slots"
	//bool slot1;
	//bool slot2;
	//bool slot3;
	//bool slot4;
	RENDER_SLOT slot1;
	RENDER_SLOT slot2;
	RENDER_SLOT slot3;
	RENDER_SLOT slot4;
	//RENDER_SLOT slot5;


	//AM3dActor test_actor;

	// Variable to hold the widget After Creating it.
	UUserWidget* wDougUI;
	//methods for UUserWidget http://api.unrealengine.com/INT/API/Runtime/UMG/Blueprint/UUserWidget/index.html

	//UStaticMeshComponent* StaticMeshComponent;
	//UPROPERTY(Category=Meshes, EditAnywhere)
	//UStaticMesh* StaticMesh;
	UStaticMeshComponent* CreateComponent(FString comp_name);
	//UStaticMeshComponent* NewComp;

	UStaticMeshComponent* TestComp;//this works on launch
	UStaticMesh* TestMesh;//this works on launch

	//10 slots
	/*
	UStaticMeshComponent* Comp1;
	UStaticMeshComponent* Comp2;
	UStaticMeshComponent* Comp3;
	UStaticMeshComponent* Comp4;
	UStaticMeshComponent* Comp5;
	UStaticMeshComponent* Comp6;
	UStaticMeshComponent* Comp7;
	UStaticMeshComponent* Comp8;
	UStaticMeshComponent* Comp9;
	UStaticMeshComponent* Comp10;
	*/

	//float GetFloatByName(UClass* oclass, FString str);
	//float GetFloatByName(UObjectBase* o, FString name);
	bool GetFloatByName(UObject * Target, FName VarName, float &outFloat);

	UImage* CreateImage();
	//UMaterial* GetMaterial(FString mat_name);

	TArray<UStaticMeshComponent*> components;
	TMap<FString, UStaticMeshComponent*> meshes;
	TMap<FString, UStaticMesh*> static_meshes;

	UStaticMeshComponent* SpawnMesh(FString id, FString filename);
	UStaticMeshComponent* GetNextMeshComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UImage* portrait_image1;
	//TArray<UMaterial*> LoadedMaterials;
	
	UTexture* tex;

private:
	//4 material instances
	UMaterialInstance* Inst;
	UMaterialInstanceDynamic* MI1;//The dynamic instance of Inst1

	UMaterial* BodyMaterial;
	UMaterial* WhiteMaterial;

	//Set pivot from *.pivot file
	FVector LoadPivot(int m3d_number);

	void LoadBodyHeadAnimationSetsFromFile(FString directory, FString seq_filename, FString key_filename);
	void RemoveDeadFrames(TArray<BodyHeadAnimationSet>& animation_sets);

public:
	TArray<BodyHeadAnimationSet> animation_sets;
	//TArray<BodyHeadAnimationSet> animation_sets2;//for testing
	//AMeshActor* A;

private:
	UMaterialInterface* GenericHeadMaterial;
	UMaterialInterface* GenericBackgroundMaterial;
};
