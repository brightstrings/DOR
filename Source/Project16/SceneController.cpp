// Fill out your copyright notice in the Description page of Project Settings.

#include "SceneController.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
//#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/CanvasPanel.h"
#include "Runtime/CoreUObject/Public/UObject/UnrealType.h"//for FindField()
#include "Runtime/Slate/Public/SlateMaterialBrush.h"
//#include "M3dActor.h"
#include "Runtime/CoreUObject/Public/UObject/UnrealType.h"
#include "Engine/engine.h"
#include "SoundManager2.h"
#include "OvodusButton.h"

DBEntry::DBEntry()
{
	ID[0] = L'\0';
	ID[1] = L'\0';
	ID[2] = L'\0';
}

M3D::M3D() {
	code = "";
}

//Make sure all heads are in the Heads(Portrait/Meshes) directory.
FString M3D::ToFileName()
{
	FString path = "";
	path = "/Game/Portrait/Meshes/";

	//FString ContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::GameContentDir());
	//FString ContentDirectory = FPaths::GameDir();
	//ContentDirectory += "Portrait/Meshes/";

	//TODO:to file name 1,2,3m3d etc.
	//using int M3D::name
	//return path + "sven2";
	FString name = path;
	name.AppendInt(m3d_number);

	FString NewName = path;
	NewName.AppendInt(m3d_number);

	return NewName;
}

TCHAR ord(unsigned char byte)
{
	unsigned char char_arr[] = { '\0','\0' };
	char_arr[0] = byte;
	TCHAR c = (TCHAR)(*ANSI_TO_TCHAR((const CHAR*)char_arr));
	return c;
}

UStaticMeshComponent* ASceneController::CreateComponent(FString comp_name)
{
	UStaticMeshComponent* NewComp = NewObject<UStaticMeshComponent>(this, *comp_name);
	if (!NewComp)
	{
		return NULL;
	}
	//~~~~~~~~~~~~~
	/*
	if (GEngine) {
		FString MyStr = "component created ";
		GEngine->AddOnScreenDebugMessage(0, 13.0f, FColor::Green, MyStr);
	}
	*/
	//OnComponentCreated();
	//AddComponent(NewComp);
	NewComp->RegisterComponent();        //You must ConstructObject with a valid Outer that has world, see above	 
	//NewComp->SetWorldLocation(FVector());
	//NewComp->SetWorldRotation(FQuat());
	NewComp->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	/*
	if (GEngine) {
		if (NewComp->ShouldRender()) {
			FString MyStr = "component render ";
			GEngine->AddOnScreenDebugMessage(0, 13.0f, FColor::Green, MyStr);
		}
	}
	*/

	//NewComp->state
	components.Add(NewComp);
	return NewComp;
}

// Sets default values
ASceneController::ASceneController()
{
	//arrow_right_texture->platf

	//delayed_audio = "";
	//delay_elapsed = 0.0f;
	//delay = 0.0f;

	//GetPlayerController().
	//EMouseCursor::
	//ICursor::Show(true);
	//GetWorld()->GetFirstPlayerController()->show
	//GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	command_elapsed = 0.0f;
	duration = 0.0f;
	//next_character_id = 0;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	paused = false;//game gets paused if user presses escape or some other action like minimize-alt-tab.

	//Create light

	/*
	FString name = "test";
	TestComp= CreateDefaultSubobject<UStaticMeshComponent>(*name);
	TestMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Portrait/Meshes/14"));
	TestComp->SetStaticMesh(TestMesh);
	*/
	/*
	FString name = "test1";
	Comp1 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "test2";
	Comp2 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "test3";
	Comp3 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "test4";
	Comp4 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "test5";
	Comp5 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "test6";
	Comp6 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "test7";
	Comp7 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "test8";
	Comp8 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "test9";
	Comp9 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "test10";
	Comp10 = CreateDefaultSubobject<UStaticMeshComponent>(*name);

	components.Add(Comp1);
	components.Add(Comp2);
	components.Add(Comp3);
	components.Add(Comp4);
	components.Add(Comp5);
	components.Add(Comp6);
	components.Add(Comp7);
	components.Add(Comp8);
	components.Add(Comp9);
	components.Add(Comp10);
	*/

	//StaticMeshComponent = NULL;
	//StaticMesh = NULL;
	/*
	//add some mesh slots
	FString name = "";
	name = "component1";
	UStaticMeshComponent* StaticMeshComponent1 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "component2";
	UStaticMeshComponent* StaticMeshComponent2 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "component3";
	UStaticMeshComponent* StaticMeshComponent3 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "component4";
	UStaticMeshComponent* StaticMeshComponent4 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "component5";
	UStaticMeshComponent* StaticMeshComponent5 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "component6";
	UStaticMeshComponent* StaticMeshComponent6 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "component7";
	UStaticMeshComponent* StaticMeshComponent7 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "component8";
	UStaticMeshComponent* StaticMeshComponent8 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "component9";
	UStaticMeshComponent* StaticMeshComponent9 = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	name = "component10";
	UStaticMeshComponent* StaticMeshComponent10 = CreateDefaultSubobject<UStaticMeshComponent>(*name);

	components.Add(StaticMeshComponent1);
	components.Add(StaticMeshComponent2);
	components.Add(StaticMeshComponent3);
	components.Add(StaticMeshComponent4);
	components.Add(StaticMeshComponent5);
	components.Add(StaticMeshComponent6);
	components.Add(StaticMeshComponent7);
	components.Add(StaticMeshComponent8);
	components.Add(StaticMeshComponent9);
	components.Add(StaticMeshComponent10);
	*/

	/*
	StaticMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/sven2"));
	//StaticMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/icemag"));
	//StaticMesh->LightMapCoordinateIndex = 1;
	//StaticMesh->LightMapResolution = 10;
	//StaticMesh->mob

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	StaticMeshComponent->SetStaticMesh(StaticMesh);
	StaticMeshComponent->Mobility = EComponentMobility::Static;
	*/

	//Set up slots 
	slot1.Position = FVector(0,0,0);
	slot2.Position = FVector(-190.0f, 0, 0);
	slot3.Position = FVector(-380.0f, 0, 0);
	slot4.Position = FVector(-570.0f, 0, 0);
	//slot5.Position = FVector(-760.0f, 0, 0);

	FVector LightLocation(-5.000000, 20.000000, 2.000000);
	RelativeToSlotLightPos = LightLocation - slot1.Position;

	//slot3.taken = true;//temp

	GenericHeadMaterial = NULL;

	FString generic_mat_name = "Group01Mat_ncl1_1";
	FString fstr = "Material'/Game/Portrait/" + generic_mat_name + "." + generic_mat_name + "'";

	ConstructorHelpers::FObjectFinder<UMaterial> FGM = ConstructorHelpers::FObjectFinder<UMaterial>(*fstr);
	if (FGM.Succeeded()) {
		GenericHeadMaterial = FGM.Object;//uses TargetMaterial1
	}
	//Background
	GenericBackgroundMaterial = NULL;

	generic_mat_name = "GenericBackgroundMaterial";
	fstr = "Material'/Game/Portrait/" + generic_mat_name + "." + generic_mat_name + "'";

	ConstructorHelpers::FObjectFinder<UMaterial> B = ConstructorHelpers::FObjectFinder<UMaterial>(*fstr);
	if (B.Succeeded()) {
		GenericBackgroundMaterial = B.Object;
	}

	FString mat_name = "";
	FString str = "";
	//Border
	mat_name = "border2_Mat";
	str = "Material'/Game/Portrait/" + mat_name + "." + mat_name + "'";

	ConstructorHelpers::FObjectFinder<UMaterial> FB = ConstructorHelpers::FObjectFinder<UMaterial>(*str);
	if (FB.Succeeded()) {
		//img1mat = F.Object;
		slot1.mat_border = FB.Object;
		slot2.mat_border = FB.Object;
		slot3.mat_border = FB.Object;
		slot4.mat_border = FB.Object;
		//slot5.mat_border = FB.Object;
	}
	//Slot1
	mat_name = "TargetMaterial1";
	str = "Material'/Game/Portrait/Textures/" + mat_name + "." + mat_name + "'";
	//ConstructorHelpers::FObjectFinder<UMaterial> Material(*str);
	//img1mat = NULL;//safe
	
	ConstructorHelpers::FObjectFinder<UMaterial> F1 = ConstructorHelpers::FObjectFinder<UMaterial>(*str);
	if (F1.Succeeded()) {
		//img1mat = F.Object;
		slot1.mat = F1.Object;//uses TargetMaterial1
	}
	//Slot2(TODO)
	mat_name = "TargetMaterial2";
	str = "Material'/Game/Portrait/Textures/" + mat_name + "." + mat_name + "'";
	//ConstructorHelpers::FObjectFinder<UMaterial> Material(*str);
	//img1mat = NULL;//safe
	ConstructorHelpers::FObjectFinder<UMaterial> F2 = ConstructorHelpers::FObjectFinder<UMaterial>(*str);
	if (F2.Succeeded()) {
		//img1mat = F.Object;
		slot2.mat = F2.Object;//uses TargetMaterial2
	}
	//Slot3(TODO)
	mat_name = "TargetMaterial3";
	str = "Material'/Game/Portrait/Textures/" + mat_name + "." + mat_name + "'";
	//ConstructorHelpers::FObjectFinder<UMaterial> Material(*str);
	//img1mat = NULL;//safe
	ConstructorHelpers::FObjectFinder<UMaterial> F3 = ConstructorHelpers::FObjectFinder<UMaterial>(*str);
	if (F3.Succeeded()) {
		//img1mat = F.Object;
		slot3.mat = F3.Object;//uses TargetMaterial3
	}
	//Slot4(TODO)
	mat_name = "TargetMaterial4";
	str = "Material'/Game/Portrait/Textures/" + mat_name + "." + mat_name + "'";
	//ConstructorHelpers::FObjectFinder<UMaterial> Material(*str);
	//img1mat = NULL;//safe
	ConstructorHelpers::FObjectFinder<UMaterial> F4 = ConstructorHelpers::FObjectFinder<UMaterial>(*str);
	if (F4.Succeeded()) {
		//img1mat = F.Object;
		slot4.mat = F4.Object;//uses TargetMaterial4
	}
	mat_name = "TargetMaterial4";
	str = "Material'/Game/Portrait/Textures/" + mat_name + "." + mat_name + "'";
	//ConstructorHelpers::FObjectFinder<UMaterial> Material(*str);
	//img1mat = NULL;//safe
	/*ConstructorHelpers::FObjectFinder<UMaterial> F5 = ConstructorHelpers::FObjectFinder<UMaterial>(*str);
	if (F5.Succeeded()) {
		//img1mat = F.Object;
		slot5.mat = F5.Object;//uses TargetMaterial4
	}
	*/

	//I THINK THE NEXT CODE IS TEMPORARY

	FString mat_instance_name = "";
	FString str2 = "";
	
	mat_instance_name = "MatInst1";
	str2 = "MaterialInstance'/Game/Portrait/Textures/" + mat_instance_name + "." + mat_instance_name + "'";
	//ConstructorHelpers::FObjectFinder<UMaterial> Material(*str);
	Inst = NULL;
	MI1 = NULL;//safe
	ConstructorHelpers::FObjectFinder<UMaterialInstance> FInst = ConstructorHelpers::FObjectFinder<UMaterialInstance>(*str2);
	if (FInst.Succeeded()) {
		Inst = FInst.Object;
		//MI1 = (UMaterialInstanceDynamic*)F2.Object;

		//Set texture to MB
		FString path = "Texture'/Game/Portrait/Textures/";
		FString texture_name = "MB_HEAD";
		ConstructorHelpers::FObjectFinder<UTexture> T = ConstructorHelpers::FObjectFinder<UTexture>(*(path + texture_name + "." + texture_name + "'"));
		if (T.Succeeded()) {
			tex = T.Object;
			//UKismetSystemLibrary::PrintString(GetWorld(), "Found Texture", true, false);
		}
	}
	//The material used by all bodies
	mat_name = "BodyMaterial";
	str = "Material'/Game/Portrait/Textures/" + mat_name + "." + mat_name + "'";
	//ConstructorHelpers::FObjectFinder<UMaterial> Material(*str);
	//img1mat = NULL;//safe

	ConstructorHelpers::FObjectFinder<UMaterial> B1 = ConstructorHelpers::FObjectFinder<UMaterial>(*str);
	if (B1.Succeeded()) {
		//img1mat = F.Object;
		BodyMaterial = B1.Object;//uses TargetMaterial1
	}

	//The material used by all masks
	mat_name = "WhiteMaterial";
	str = "Material'/Game/Portrait/Textures/" + mat_name + "." + mat_name + "'";
	//ConstructorHelpers::FObjectFinder<UMaterial> Material(*str);
	//img1mat = NULL;//safe

	ConstructorHelpers::FObjectFinder<UMaterial> W1 = ConstructorHelpers::FObjectFinder<UMaterial>(*str);
	if (W1.Succeeded()) {
		//img1mat = F.Object;
		WhiteMaterial = W1.Object;//uses TargetMaterial1
	}
	
	wDougUI = NULL;

	//test function: lighting
	//CreateCharacter(M3D(), M3D(), M3D(), M3D());

	FString ContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::GameContentDir());
	FString FileDirectory = ContentDirectory + "Portrait/Script/";
	FString SEQFile = "0.seq";
	FString KEYFile = "0.key";
	LoadBodyHeadAnimationSetsFromFile(FileDirectory, SEQFile, KEYFile);
}

//bool UShooterFunctions::GetFloatByName(UObject * Target, FName VarName, float &outFloat)
bool ASceneController::GetFloatByName(UObject * Target, FName VarName, float &outFloat)
{
	if (Target) //make sure Target was set in blueprints. 
	{
		float FoundFloat;
		UFloatProperty* FloatProp = FindField<UFloatProperty>(Target->GetClass(), VarName);  // try to find float property in Target named VarName
		if (FloatProp) //if we found variable
		{
			FoundFloat = FloatProp->GetPropertyValue_InContainer(Target);  // get the value from FloatProp
			outFloat = FoundFloat;  // return float
			return true; // we can return
		}
	}
	return false; // we haven't found variable return false
}
/*
float ASceneController::GetFloatByName(UObjectBase* o, FString name)
{

	UFloatProperty* FloatProp = FindField<UFloatProperty>(o->GetClass(), "EditorVariableScaleX");
	//float FloatProp = FindField<float>(o->GetClass(), name);
	if (FloatProp != NULL)
	{
		//float* FloatPtr = FloatProp->GetPropertyValue_InContainer(o);
		//if (FloatPtr != NULL)
		//{
			//float MyFloat = *FloatPtr;
			//return MyFloat;
		//}
		float myfloat=FloatProp->GetPropertyValue_InContainer(o);
		return myfloat;
	}
	return 0;
}
*/

UImage* ASceneController::CreateImage() {
	UImage* image = NewObject<UImage>(UImage::StaticClass());
	image->SetVisibility(ESlateVisibility::Visible);
	return image;
}
/*
UMaterial* ASceneController::GetMaterial(FString mat_name)
{
	FString str = "Material'/Game/" + mat_name + "." + mat_name + "'";
	ConstructorHelpers::FObjectFinder<UMaterial> Material(*str);
	LoadedMaterials.Add(Material.Object);

	if (Material.Object != NULL)
	{
		//UMaterial* TheMaterial = (UMaterial*)Material.Object;
		UMaterial* TheMaterial = LoadedMaterials[LoadedMaterials.Num()-1];
		//FVector2D size(256,256);
		return TheMaterial;
	}
	return NULL;
}
*/

UStaticMeshComponent* ASceneController::GetNextMeshComponent()
{
	for (int i = 0; i < components.Num();i++) {
		UStaticMeshComponent* c = components[i];
		if (c->GetStaticMesh()==NULL) {
			return c;
		}
	}

	return NULL;
}

UStaticMeshComponent* ASceneController::SpawnMesh(FString id, FString filename)
{
	/*
	if (GEngine) {
		FString MyStr = "filename "+filename;
		GEngine->AddOnScreenDebugMessage(1, 13.0f, FColor::Green, MyStr);
	}
	*/

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	//A = GetWorld()->SpawnActor<AMeshActor>(Location, Rotation, SpawnInfo);

	FString str = "";
	//StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(*id);
	//components.Add(str, StaticMeshComponent);
	//meshes.Add(id, A);
	//TestMesh = LoadObject<UStaticMesh>(nullptr, *test_name);

	//CreateStaticMesh(filename);

	UStaticMesh* StaticMesh=LoadObject<UStaticMesh>(nullptr, *filename);

	//FString path = "/Game/Portrait/Meshes/14";
	//TestMesh = LoadObject<UStaticMesh>(nullptr, *path);
	//TestMesh = LoadObject<UStaticMesh>(nullptr, *filename);

	//UStaticMeshComponent* next_mesh_component = GetNextMeshComponent();//get next mesh component returns the next component that has no static mesh
	UStaticMeshComponent* next_mesh_component = CreateComponent(id);

	if (next_mesh_component) {
		/*
		if (GEngine) {
			FString MyStr = "mesh ";
			GEngine->AddOnScreenDebugMessage(0, 13.0f, FColor::Green, MyStr);
		}
		*/

		next_mesh_component->SetStaticMesh(StaticMesh);

		next_mesh_component->SetSimulatePhysics(false);
	}
	meshes.Add(id, next_mesh_component);
	//record ptr so not garbage collected
	static_meshes.Add(id, StaticMesh);

	//return;

	//StaticMeshComponent->SetStaticMesh(StaticMesh);
	return next_mesh_component;
}

/*
Spawn characters in constructors(must for lighting, couldn't get lighting to work otherwise even when dynamic lighting used)
*/
void ASceneController::CreateCharacter(int NewID, M3D m3d_head, M3D m3d_body, M3D m3d_neck, M3D m3d_helmet)
{
	//UM3dCharacter* c=new UM3dCharacter;

	FString name = "Character";
	name.AppendInt(NewID);

	UM3dCharacter* c = NewObject<UM3dCharacter>(this, *name);
	c->Initialize();

	//c->AddToRoot();//like AddRef, prevents garbage collection

	//AllCharacterIDs.Add(name);//for looking up characters
	characters.Add(NewID, c);

	c->ID = NewID;//for looking up components
	//record m3ds for positioning characters at slots: 
	c->m3d_head = m3d_head;
	c->m3d_body = m3d_body;
	c->m3d_neck = m3d_neck;
	c->m3d_helmet = m3d_helmet;

	//Create head

	//FVector Location(0.0f, 0.0f, 0.0f);
	//FRotator Rotation(0.0f, 0.0f, 0.0f);
	//FActorSpawnParameters SpawnInfo;
	//AM3dActor* A = GetWorld()->SpawnActor<AM3dActor>(my_m3d_actor_blueprint, Location, Rotation, SpawnInfo);

	//FString str = "";
	//UStaticMeshComponent* StaticMeshComponent = NULL;

	//str = "Head" + NewID;
	//StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(*str);
	//components.Add(str, StaticMeshComponent);

	//return;

	//StaticMeshComponent->SetStaticMesh(StaticMesh);

	//AM3dActor* A = GetWorld()->SpawnActor<AM3dActor>(Location, Rotation, SpawnInfo);

	//create the character load it's sequence later
	//return;

	//FString name = m3d_head.ToFileName();

	//return;

	//return;

	//get the file name from m3d struct
	//UStaticMesh* StaticMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, *m3d_head.ToFileName()));
	//c.StaticMeshHead = LoadObject<UStaticMesh>(UStaticMesh::StaticClass(), *m3d_head.ToFileName());

	FString test_name = "/Game/Portrait/Meshes/14";
	//TestMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Portrait/Meshes/14"));
	//TestMesh = LoadObject<UStaticMesh>(nullptr, *test_name);//this works on launch
	//TestComp->SetStaticMesh(TestMesh);//this works for launch

	FString strID = "";
	UStaticMeshComponent* meshHead = NULL;
	UStaticMeshComponent* meshHeadMask = NULL;
	UStaticMeshComponent* meshBody = NULL;
	UStaticMeshComponent* meshBodyMask = NULL;
	UStaticMeshComponent* meshNeck = NULL;
	UStaticMeshComponent* meshNeckMask = NULL;

	////////////////////////////////
	//Head
	////////////////////////////////
	strID = "Head";
	strID.AppendInt(NewID);
	meshHead = SpawnMesh(strID, *m3d_head.ToFileName());
	meshHead->SetWorldLocation(m3d_head.Position);

	strID = "HeadMask";
	strID.AppendInt(NewID);
	meshHeadMask = SpawnMesh(strID, *m3d_head.ToFileName());
	meshHeadMask->SetWorldLocation(m3d_head.Position);
	meshHeadMask->SetMaterial(0, WhiteMaterial);

	FVector HeadMaskPosition = m3d_head.Position;
	HeadMaskPosition.X -= 70.0f;
	meshHeadMask->SetWorldLocation(HeadMaskPosition);
	////////////////////////////////
	//Body
	////////////////////////////////
	strID = "Body";
	strID.AppendInt(NewID);
	meshBody = SpawnMesh(strID, *m3d_body.ToFileName());
	meshBody->SetWorldLocation(m3d_body.Position);

	//Body mask
	strID = "BodyMask";
	strID.AppendInt(NewID);
	meshBodyMask = SpawnMesh(strID, *m3d_body.ToFileName());
	meshBodyMask->SetWorldLocation(m3d_body.Position);
	meshBodyMask->SetMaterial(0, WhiteMaterial);
	
	FVector BodyMaskPosition = m3d_body.Position;
	BodyMaskPosition.X -= 70.0f;
	meshBodyMask->SetWorldLocation(BodyMaskPosition);
	////////////////////////////////
	//Neck
	////////////////////////////////
	
	strID = "Neck";
	strID.AppendInt(NewID);
	meshNeck = SpawnMesh(strID, *m3d_neck.ToFileName());
	meshNeck->SetWorldLocation(m3d_neck.Position);
	
	//neck mask
	strID = "NeckMask";
	strID.AppendInt(NewID);
	meshNeckMask = SpawnMesh(strID, *m3d_neck.ToFileName());
	
	meshNeckMask->SetWorldLocation(m3d_neck.Position);
	meshNeckMask->SetMaterial(0, WhiteMaterial);

	FVector NeckMaskPosition = m3d_neck.Position;
	NeckMaskPosition.X -= 70.0f;
	meshNeckMask->SetWorldLocation(NeckMaskPosition);
	

	c->MeshHead = meshHead;
	c->MeshHeadMask = meshHeadMask;
	c->MeshBody = meshBody;
	c->MeshBodyMask = meshBodyMask;
	c->MeshNeck = meshNeck;
	c->MeshNeckMask = meshNeckMask;

	//For pivot rotations:
	//head
	c->HeadStartPosition = m3d_head.Position;
	c->HeadMaskStartPosition = m3d_head.Position + FVector(-70,0,0);
	c->HeadPivot = m3d_head.Pivot;
	c->HeadMaskPivot = m3d_head.Pivot + FVector(-70,0,0);

	//body
	//c->BodyPivot = m3d_body.Pivot;
	//c->
	c->BodyStartPosition = m3d_body.Position;
	c->BodyMaskStartPosition = m3d_body.Position + FVector(-70, 0, 0);
	c->BodyPivot = m3d_body.Pivot;
	c->BodyMaskPivot = m3d_body.Pivot + FVector(-70, 0, 0);

	//neck
	//c->BodyPivot = m3d_body.Pivot;
	//c->
	c->NeckStartPosition = m3d_neck.Position;
	c->NeckMaskStartPosition = m3d_neck.Position + FVector(-70, 0, 0);
	c->NeckPivot = m3d_neck.Pivot;
	c->NeckMaskPivot = m3d_neck.Pivot + FVector(-70, 0, 0);

	//characters.Add(NewID,c);
	/*
	if (GEngine) {
		FString MyStr = "character added ";
		MyStr.AppendInt(NewID);
		GEngine->AddOnScreenDebugMessage(0, 13.0f, FColor::Green, MyStr);
	}
	*/
	/*
	if (GEngine) {
		FString MyStr = "texture code "+m3d_head.code;
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 13.0f, FColor::Green, MyStr);
	}
	*/

	//return id;
	c->SetHeadTexture(m3d_head.code, GenericHeadMaterial, this);
	c->SetBodyTexture(m3d_body.code, BodyMaterial, this);
	c->SetNeckTexture(m3d_neck.code, BodyMaterial, this);
	/*
	characters.Add(NewID, c);
	*/
	//c = characters[characters.Num() - 1];

	//c.SetHeadTexture("MB", GenericHeadMaterial, this);
	//c.SetHeadTexture
}

/*
Update: sorted, positioning problem fixed
This is actually wrong if character has already been positioned at a slot:
adding slot position
*/
void ASceneController::AssignCharacterToSlot(int ID, RENDER_SLOT* slot) 
{
	//position the character
	//UM3dCharacter* c = characters[ID];
	//FString name = "Character";
	//name.AppendInt(ID);
	//UM3dCharacter* c = FindObject<UM3dCharacter>(this, *name, true);
	UM3dCharacter* c = characters[ID];

	RENDER_SLOT* s = slot;
	RENDER_SLOT offscreen_slot;

	if (slot) {
		slot->CharacterID = ID;
	}
	else {
		//slot1.Position = FVector(0, 0, 0);
		//slot2.Position = FVector(-190.0f, 0, 0);
		//slot3.Position = FVector(-380.0f, 0, 0);
		//slot4.Position = FVector(-570.0f, 0, 0);
		offscreen_slot.Position = FVector(1000.0f,0,0);
		s = &offscreen_slot;
	}

		//adjust pivot points
		//head
		c->HeadStartPosition = c->m3d_head.Position + s->Position;
		c->HeadMaskStartPosition = c->m3d_head.Position + FVector(-70, 0, 0) + s->Position;
		c->HeadPivot = c->m3d_head.Pivot + s->Position;
		c->HeadMaskPivot = c->m3d_head.Pivot + FVector(-70, 0, 0) + s->Position;
		//body
		//c->BodyStartPosition += slot->Position;
		//c->BodyMaskStartPosition += slot->Position;
		//c->BodyPivot += slot->Position;
		//c->BodyMaskPivot += slot->Position;
		c->BodyStartPosition = c->m3d_body.Position + s->Position;
		c->BodyMaskStartPosition = c->m3d_body.Position + FVector(-70, 0, 0) + s->Position;
		c->BodyPivot = c->m3d_body.Pivot + s->Position;
		c->BodyMaskPivot = c->m3d_body.Pivot + FVector(-70, 0, 0) + s->Position;
		//neck
		c->NeckStartPosition = c->m3d_neck.Position + s->Position;
		c->NeckMaskStartPosition = c->m3d_neck.Position + FVector(-70, 0, 0) + s->Position;
		c->NeckPivot = c->m3d_neck.Pivot + s->Position;
		c->NeckMaskPivot = c->m3d_neck.Pivot + FVector(-70, 0, 0) + s->Position;
		//c->NeckStartPosition += slot->Position;
		//c->NeckMaskStartPosition += slot->Position;
		//c->NeckPivot += slot->Position;
		//c->NeckMaskPivot += slot->Position;
	//}

	FString str = "";
	UStaticMeshComponent* component = NULL;
	FVector Position;

	str = "Head";
	str.AppendInt(ID);
	component = meshes[str];
	//Position = component->GetComponentLocation();
	//Position += slot->Position;
	//if (slot) {
		component->SetWorldLocation(c->HeadStartPosition);
	//}
	//else {
		component->SetWorldLocation(c->HeadStartPosition);
		//componen
	//}

	str = "HeadMask";
	str.AppendInt(ID);
	component = meshes[str];
	//Position = component->GetComponentLocation();
	//Position += slot->Position;
	component->SetWorldLocation(c->HeadMaskStartPosition);

	str = "Body";
	str.AppendInt(ID);
	component = meshes[str];
	//Position = component->GetComponentLocation();
	//Position += slot->Position;
	component->SetWorldLocation(c->BodyStartPosition);

	str = "BodyMask";
	str.AppendInt(ID);
	component = meshes[str];
	//Position = component->GetComponentLocation();
	//Position += slot->Position;
	component->SetWorldLocation(c->BodyMaskStartPosition);

	str = "Neck";
	str.AppendInt(ID);
	component = meshes[str];
	//Position = component->GetComponentLocation();
	//Position += slot->Position;
	component->SetWorldLocation(c->NeckStartPosition);

	str = "NeckMask";
	str.AppendInt(ID);
	component = meshes[str];
	//Position = component->GetComponentLocation();
	//Position += slot->Position;
	component->SetWorldLocation(c->NeckMaskStartPosition);

	s->taken = true;
}

void ASceneController::CreateUI()
{
	if (wDougUIBlueprint) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		wDougUI = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), wDougUIBlueprint);
		if (wDougUI)
		{
			//let add it to the view port
			//wDougUI->
			wDougUI->AddToViewport();
			/*
			float scale_x = 0;
			float scale_y = 0;
			GetFloatByName(wDougUI, "EditorVariableScaleX", scale_x);
			GetFloatByName(wDougUI, "VarScaleY", scale_y);
			//GetFloatByName(wDougUI, "VarScaleY", scale_y);

			UOvodusButton* arrow1 = (UOvodusButton*)wDougUI->GetWidgetFromName("OvodusButton_149");
			UCanvasPanelSlot* panel_slot = (UCanvasPanelSlot*)arrow1->Slot;
			//FVector2D Position2 = FVector2D((command.spawn_x*1280.0f / 640.0f)*scale_x, (command.spawn_y*720.0f / 480.0f)*scale_y);
			//panel_slot->SetPosition(Position2);
			//image1->SetDrawSize(230,225);
			FVector2D draw_size = FVector2D(20 * scale_x*1280.0f / 640.0f, 22 * scale_y*720.0f/480.0f);
			panel_slot->SetSize(draw_size);

			if (GEngine) {
				FString str = "scale x ";
				FString sx = FString::SanitizeFloat(scale_x);
				str += sx;
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Green, *str);
			}
			*/

		}
	}
}

// Called when the game starts or when spawned
void ASceneController::BeginPlay()
{
	Super::BeginPlay();

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	//AM3dActor* A = GetWorld()->SpawnActor<AM3dActor>(my_m3d_actor_blueprint, Location, Rotation, SpawnInfo);
	focus_light = GetWorld()->SpawnActor<ALightActor>(Location, Rotation, SpawnInfo);

	FVector Location1 = FVector(-5.000000, 20.000000, 2.000000);
	light1 = GetWorld()->SpawnActor<ALightActor>(Location1, Rotation, SpawnInfo);
	light1->SetActorLocation(Location1);
	FVector Location2 = FVector(-195.000000, 20.000000, 2.000000);
	light2 = GetWorld()->SpawnActor<ALightActor>(Location2, Rotation, SpawnInfo);
	light2->SetActorLocation(Location2);
	FVector Location3 = FVector(-385.000000, 20.000000, 2.000000);
	light3 = GetWorld()->SpawnActor<ALightActor>(Location3, Rotation, SpawnInfo);
	light3->SetActorLocation(Location3);
	FVector Location4 = FVector(-575.000000, 20.000000, 2.000000);
	light4 = GetWorld()->SpawnActor<ALightActor>(Location4, Rotation, SpawnInfo);
	light4->SetActorLocation(Location4);

	//FVector Location(0.0f, 0.0f, 0.0f);
	//FRotator Rotation(0.0f, 0.0f, 0.0f);
	//FActorSpawnParameters SpawnInfo;

	//AM3dActor::strings.Add("/Game/sven2");
	//SpawnInfo.
	//AM3dActor* A = NULL;
	//AM3dActor* A = GetWorld()->SpawnActor<AM3dActor>(my_m3d_actor_blueprint, Location, Rotation, SpawnInfo);
	//A->LoadMesh("/Game/sven2");

	//A->Init("/Game/sven2");

	//MI1->TextureParameterValues[0].ParameterValue = texture;
	/*
	if (Inst) {
		MI1 = UMaterialInstanceDynamic::Create(Inst, NULL);
		if (MI1) {
			//Inst->TextureParameterValues[0].ParameterValue = tex;
			//Inst->SetTextureParameterValue("HeadTexture", tex);
			MI1->SetTextureParameterValue("HeadTexture", tex);
			if (A) {
				if (A->GetMeshComponentHead()) {
					A->GetMeshComponentHead()->SetMaterial(0, MI1);
				}
			}
			UKismetSystemLibrary::PrintString(GetWorld(), "Setting Texture", true, false);
		}
	}
	*/
	/*
	if (wDougUIBlueprint) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		wDougUI = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), wDougUIBlueprint);

		// now you can use the widget directly since you have a referance for it.
		// Extra check to  make sure the pointer holds the widget.
		if (wDougUI)
		{
			//let add it to the view port
			//wDougUI->
			wDougUI->AddToViewport();

			//spawn an image
			UCanvasPanel* Panel = (UCanvasPanel*)wDougUI->GetWidgetFromName("CanvasPanel_0");//include header
			//UImage* img = (UImage*)wDougUI->GetWidgetFromName("Image_91");
			//Panel->AddChildToCanvas(img);
			float scale_x = 0;// GetFloatByName(wDougUI, "EditorVariableScaleX");
			if (GetFloatByName(wDougUI, "EditorVariableScaleX", scale_x)) {

				FString Mystr = "scale_x " + FString::SanitizeFloat(scale_x);
				UKismetSystemLibrary::PrintString(GetWorld(), Mystr, true, false);
			}
			float scale_y = 0;// GetFloatByName(wDougUI, "EditorVariableScaleX");
			if (GetFloatByName(wDougUI, "VarScaleY", scale_y)) {

				FString Mystr = "scale_y " + FString::SanitizeFloat(scale_y);
				UKismetSystemLibrary::PrintString(GetWorld(), Mystr, true, false);
			}

			if (img1mat) {
				portrait_image1 = CreateImage();
				//UMaterial* brush_mat = GetMaterial("TargetMaterial1");
				//FVector2D size(256, 256);
				FVector2D size(32, 32);
				FSlateMaterialBrush brush(*((UMaterialInterface*)img1mat), size);
				portrait_image1->SetBrush(brush);
				Panel->AddChildToCanvas(portrait_image1);
				UCanvasPanelSlot* slot = (UCanvasPanelSlot*)portrait_image1->Slot;
				//image1->SetDrawSize(230,225);
				FVector2D draw_size(230*scale_x, 225*scale_y);
				slot->SetSize(draw_size);
			}

			//wDougUI->
		}

		//Show the Cursor.
		//bShowMouseCursor = true;
	}
	*/
	//UE_LOG(LogTemp, Warning, TEXT("hello"));
}

void ASceneController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (GEngine) {
		FString MyStr = "EndPlay called";
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 13.0f, FColor::Green, MyStr);
	}
	/*
	for (auto& Elem : characters)
	{
		//delete (Elem.Value);
		//Elem.Value->BeginDestroy();

		if (GEngine) {
			FString MyStr = "character deleted";
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 13.0f, FColor::Green, MyStr);
		}
	}
	*/
}

void ASceneController::PlayScene(float DeltaTime) {
	elapsed += DeltaTime;

	//for (characters.it) {

	//Update each character
	/*
	for (M3dCharacter& Elem : characters)
	{
		Elem.Update(DeltaTime);
	}
	*/
	//FScriptMapHelper H(&characters);
	//M3dCharacter* c = Prop->ContainerPtrToValuePtr<M3dCharacter>(
		//(UObject*)&characters,
		//0
		//);
	/*
	for (int i = 0; i < AllCharacterIDs.Num();i++) {
		FString name = AllCharacterIDs[i];

		UM3dCharacter* c = FindObject<UM3dCharacter>(this, *name, true);

		c->Update(DeltaTime, this);
	}
	*/
	
	for (auto& Elem : characters)
	{
		(Elem.Value)->Update(DeltaTime, this);
	}
	
	//TArray<AActor*> FoundActors;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), YourClass::StaticClass(), FoundActors);
	//GetWorld()->getall

	//for (auto It = characters.CreateConstIterator(); It; ++It)
	//{
		//((M3dCharacter&)It.Value()).Update(DeltaTime);
	//}

	//}
	//execute current command:
	command_elapsed += DeltaTime;

	if (command_elapsed >= duration) {
		//execute command 0, remove it
		if (commands.Num() > 0) {
			ExecuteCommand(commands[0]);

			duration = commands[0].duration;

			commands.RemoveAt(0);
			//count time elapsed since current command
			command_elapsed = 0.0f;
		}
	}
	/*
	if (commands.Num()>0) {
		COMMAND last_command = commands[0];

		if (command_elapsed>=last_command.duration) {
			//current(well last) command has ended

			//execute next command
			if (commands.Num()>1) {
				COMMAND current_command = commands[1];
				ExecuteCommand(current_command);
				//remove last command

			}
			//remove last command
			commands.RemoveAt(0);
			//count time elapsed since current command
			command_elapsed = 0.0f;
		}

		//remove last command
		//commands.RemoveAt(0);
	}
	*/
}//called if the game is not paused.

//TODO:
//void ASceneController::SpawnCharacter(RENDER_SLOT* out_slot)
//{
//}//spawns a character to a free slot

void ASceneController::SpawnImage(float screen_x, float screen_y, float scale_x, float scale_y) 
{
}

DBEntry DBEntry::ReadNextEntry(IFileHandle* FileHandle)
{
	DBEntry entry;

	//BYTE byte;
	//uint8* byteBuffer;
	//byteBuffer = reinterpret_cast<uint8*>(&byte);

	// Create our byte buffer
	BYTE* byteBuffer = reinterpret_cast<uint8*>(FMemory::Malloc(sizeof(BYTE)*39));

	//First 2 characters
	//read all

	//Just forgot I could pass the struct itself rather than
	//set bytes manually one-by-one:
	//I've done it now, however the first 2 bytes I've used ord so good
	FileHandle->Read(byteBuffer, 39);

	entry.ID[0] = ord(byteBuffer[0]);
	entry.ID[1] = ord(byteBuffer[1]);

	entry.Flags= byteBuffer[2];
	entry.KeySeq=byteBuffer[3];
	entry.zero = byteBuffer[4];
	entry.MouthWidth = byteBuffer[5];
	entry.MouthHeight = byteBuffer[6];
	entry.MouthX = byteBuffer[7];
	entry.MouthY = byteBuffer[8];
	entry.EyesWidth = byteBuffer[9];
	entry.EyesHeight = byteBuffer[10];
	entry.EyesX = byteBuffer[11];
	entry.EyesY = byteBuffer[12];

	entry.body_mesh_id = byteBuffer[13];
	entry.body_x = byteBuffer[14];
	entry.body_y = byteBuffer[15];
	entry.body_z = byteBuffer[16];

	entry.head_mesh_id = byteBuffer[17];
	entry.head_x = byteBuffer[18];
	entry.head_y = byteBuffer[19];
	entry.head_z = byteBuffer[20];

	entry.head_movement_multiplier = byteBuffer[21];//I think this is the multiplier for 03 00 entries. multiply degrees by this value.
	entry.KeyID = byteBuffer[22];//I can't think what this is. always 0?

	entry.NeckID = byteBuffer[23];
	entry.neck_x = byteBuffer[24];
	entry.neck_y = byteBuffer[25];
	entry.neck_z = byteBuffer[26];

	entry.WeaponID = byteBuffer[27];
	entry.weapon_x = byteBuffer[28];
	entry.weapon_y = byteBuffer[29];
	entry.weapon_z = byteBuffer[30];

	entry.BackPackID = byteBuffer[31];
	entry.back_pack_x = byteBuffer[32];
	entry.back_pack_y = byteBuffer[33];
	entry.back_pack_z = byteBuffer[34];

	entry.HelmetID = byteBuffer[35];
	entry.helmet_x = byteBuffer[36];
	entry.helmet_y = byteBuffer[37];
	entry.helmet_z = byteBuffer[38];

	// Free the memory allocated to the byte buffer
	FMemory::Free(byteBuffer);

	return entry;
}

float DecodeToFloat(uint8 a, uint8 b, uint8 c, uint8 d) {
	TArray<uint8> Bytes;
	Bytes.Add(a);
	Bytes.Add(b);
	Bytes.Add(c);
	Bytes.Add(d);

	return *reinterpret_cast<float*>(Bytes.GetData());
}

/*
Requires that
*/
FVector ASceneController::LoadPivot(int m3d_number)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	//FString ContentDirectory = FPaths::GameContentDir();

	FString ContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::GameContentDir());
	//FString HeadsDB2 = ContentDirectory + "Portrait/Script/HEADS.db";

	FString PivotFile = ContentDirectory + "Portrait/Meshes/";
	PivotFile.AppendInt(m3d_number);
	PivotFile.Append(".pivot");

	//Got filename
	IFileHandle* FileHandle = PlatformFile.OpenRead(*PivotFile);

	if (FileHandle) {

		// Create our byte buffer
		BYTE* byteBuffer = reinterpret_cast<BYTE*>(FMemory::Malloc(sizeof(BYTE)*4*3));

		FileHandle->Read(byteBuffer, 4*3);//3 floats, 4bytes per float(=4*3)

		float x = DecodeToFloat(byteBuffer[0], byteBuffer[1], byteBuffer[2], byteBuffer[3]);
		float y = DecodeToFloat(byteBuffer[4], byteBuffer[5], byteBuffer[6], byteBuffer[7]);
		float z = DecodeToFloat(byteBuffer[8], byteBuffer[9], byteBuffer[10], byteBuffer[11]);
		/*
		if (GEngine) {
			//m3d body
			//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, "Test Message");
			//win64 directory
			FString MyStr="x " + FString::SanitizeFloat(x) + "y " + FString::SanitizeFloat(y) + "z " + FString::SanitizeFloat(z);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 100.0f, FColor::Green, MyStr);
		}
		*/

		// Close the file again
		delete FileHandle;

		// Free the memory allocated to the byte buffer
		FMemory::Free(byteBuffer);

		return FVector(x,y,z);
	}

	return FVector(-1,-1,-1);
}

void ASceneController::AddCommand(COMMAND command)
{
	commands.Add(command);
}

//void ASceneController::PlayScene(float DeltaTime) {
//}//called if the game is not paused.

void ASceneController::ExecuteCommand(COMMAND command) {
	/*
	if (GEngine) {
		//m3d body
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, "Test Message");
	}
	*/

	if (command.create_character) {
		DBEntry spawn_character;

		/*
		if (GEngine) {
			//m3d body
			FString MyStr = "creating character ";
			MyStr.AppendInt(command.CharacterID);
			GEngine->AddOnScreenDebugMessage(1, 13.0f, FColor::Green, MyStr);
		}
		*/

		//the character should be created off-screen and then
		//re-positioned(to a slot position) when it needs to be displayed

		//Use dbEntry to create the character:
		M3D m3d_head;
		M3D m3d_body;
		M3D m3d_neck;
		M3D m3d_helmet;

		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
		//FString ContentDirectory = FPaths::GameContentDir();
		//FString ContentDirectory = FPaths::GameDir();

		//InstallDir/WindowsNoEditor/GameName/Binaries/Win64
		//FString ContentDirectory = FString(FPlatformProcess::BaseDir())+"../";//The reason I want the .. is so I don't delete Heads.db whenever I need to clear the binaries folder,
																			 //it's a convenience thing.
		//FString ContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::GameDir());

		FString ContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::GameContentDir());

		//UKismetSystemLibrary::PrintString(GetWorld(), *ContentDirectory, true, false);

		//FString HeadsDB = ContentDirectory + "HEADS.DB";
		FString HeadsDB = "HEADS.DB";
		//if (PlatformFile.FileExists(TEXT("HEADS.DB")))
		//{
		FString HeadsDB2 = ContentDirectory + "Portrait/Script/HEADS.db";

		//return;
		/*
		if (GEngine) {
			//m3d body
			//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, "Test Message");
			//win64 directory
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 100.0f, FColor::Green, "directory "+ContentDirectory);
		}
		*/
		
		if(PlatformFile.FileExists(*HeadsDB2)){
			FString MyStr = "Heads.db exists!";
			/*
			if (GEngine) {
				//m3d body
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 13.0f, FColor::Green, MyStr);
			}
			*/

			//UKismetSystemLibrary::PrintString(GetWorld(), MyStr, true, false);

			//return;

			IFileHandle* FileHandle = PlatformFile.OpenRead(*HeadsDB2);

			if (FileHandle) {

				//read 1 byte
				//BYTE byte;
				//uint8* byteBuffer;

				// Create our byte buffer
				BYTE* byteBuffer = reinterpret_cast<BYTE*>(FMemory::Malloc(sizeof(BYTE)));

				//byteBuffer = reinterpret_cast<uint8*>(&byte);
				FileHandle->Read(byteBuffer, 1);

				int num_entries = ((int)(byteBuffer[0]));

				//read entries
				//DBEntry entry1 = DBEntry::ReadNextEntry(FileHandle);

				//read 1 byte
				//hopefully this will be M(e.g. "MB" for morgan burnheartd)
				//BYTE byte;
				//FileHandle->Read(&byte, 1);
				//byteBuffer = reinterpret_cast<uint8*>(&byte);
				//FileHandle->Read(byteBuffer, 1);

				//unsigned char c = (unsigned char)byte;

				//FString b = FString::FromInt((int)byte);
				//int num = (int)byte;
				//const char = 
					//auto twoHundredAnsi = StringCast<ANSICHAR>(*twoHundred);
					//FString s = StringCast<ANSICHAR>(*b);
				//int num = (int)byte;
				//FString b = FString(ANSI_TO_TCHAR((const char*)&byte));
				//FString f = FString::FromInt(num);
				
				//FString b = FString(ANSI_TO_TCHAR((const CHAR*)byte));
				/*
				unsigned char char_arr[] = {'\0','\0'};
				char_arr[0] = byte;

				MyStr = "Char ";
				TCHAR c = (TCHAR)(*ANSI_TO_TCHAR((const CHAR*)char_arr));
				*/
				//TCHAR c = ord(byte);
				//MyStr = "Character ord ";
				//MyStr.AppendChar(c);
				//UKismetSystemLibrary::PrintString(GetWorld(), *MyStr, true, false);

				FString MyStr = "Number of entries ";
				MyStr.AppendInt(num_entries);

				//MyStr.AppendChar(c);
				//UKismetSystemLibrary::DrawDebugString(GetWorld(), FVector(0, 0, 0), MyStr, NULL, FLinearColor::White, 3.0f);
				//UKismetSystemLibrary::PrintString(GetWorld(), *MyStr, true, false);
				//DrawDebugString(GetWorld(), FVector(), MyStr);
				/*
				if (GEngine) {
					GEngine->AddOnScreenDebugMessage(0, 13.0f, FColor::Green, MyStr);

					//m3d body
					MyStr = "body ";
					//MyStr.AppendInt(entry1.body_mesh_id);
					GEngine->AddOnScreenDebugMessage(0, 13.0f, FColor::Green, MyStr);
				}
				*/

				//Extract the character from the database
				TArray<DBEntry> Database;
				for (int i = 0; i < num_entries; i++) {
					DBEntry entry = DBEntry::ReadNextEntry(FileHandle);
					Database.Add(entry);
				}

				//Got "Database"
				//Create character from db entry
				spawn_character = Database[command.dbPortraitID];
				/*
				if (GEngine) {
					//m3d body
					MyStr = "head ";
					MyStr.AppendInt(spawn_character.head_mesh_id);
					GEngine->AddOnScreenDebugMessage(0, 13.0f, FColor::Green, MyStr);
				}
				*/

				//head then body then neck then helmet and backpack and weapon.
				m3d_head.m3d_number = (int)spawn_character.head_mesh_id;
				m3d_head.Position = FVector(spawn_character.head_x, spawn_character.head_y, spawn_character.head_z);
				//TODO: load pivot for this m3d from file
				m3d_head.Pivot=LoadPivot(m3d_head.m3d_number);
				m3d_head.code += FString(spawn_character.ID);

				m3d_body.m3d_number = (int)spawn_character.body_mesh_id;
				m3d_body.Position = FVector(spawn_character.body_x, spawn_character.body_y, spawn_character.body_z);
				m3d_body.Pivot=LoadPivot(m3d_body.m3d_number);
				m3d_body.code += FString(spawn_character.ID);

				//FString path = "";
				//path = "/Game/Portrait/Meshes/cube";
				//TestComp=SpawnMesh("my_id", path);
				//TestComp->SetWorldLocation(m3d_body.Pivot);
				//TestComp->SetMaterial(0, WhiteMaterial);

				m3d_neck.m3d_number = (int)spawn_character.NeckID;
				m3d_neck.Position = FVector(spawn_character.neck_x, spawn_character.neck_y, spawn_character.neck_z);
				m3d_neck.Pivot = LoadPivot(m3d_neck.m3d_number);
				m3d_neck.code += FString(spawn_character.ID);
				
				/*
				if (GEngine) {
					FString MyStr = "m3d number " + m3d_head.m3d_number;
					GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, MyStr);
					MyStr = "m3d number "+ m3d_body.m3d_number;
					GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, MyStr);
				}
				*/
				/*
				if (GEngine) {
					FString MyStr = "neck ";
					MyStr.AppendInt(spawn_character.NeckID);
					GEngine->AddOnScreenDebugMessage(INDEX_NONE, 13.0f, FColor::Green, MyStr);
				}
				*/

				//PlatformFile.close
				// Close the file again
				delete FileHandle;

				// Free the memory allocated to the byte buffer
				FMemory::Free(byteBuffer);
			}
			else {
				if (GEngine) {
					FString MyStr = "couldn't open file ";
					GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, MyStr);
					//MyStr = "m3d number " + m3d_body.m3d_number;
					//GEngine->AddOnScreenDebugMessage(1, 3.0f, FColor::Green, MyStr);
				}
			}
		}
		else {
			if (GEngine) {
				FString MyStr = "file doesn't exist "+HeadsDB2;
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, MyStr);
				//MyStr = "m3d number " + m3d_body.m3d_number;
				//GEngine->AddOnScreenDebugMessage(1, 3.0f, FColor::Green, MyStr);
			}
		}

		//return;

		CreateCharacter(command.CharacterID, m3d_head, m3d_body, m3d_neck, m3d_helmet);

		//FString name = "Character";
		//name.AppendInt(ID);
		//name.AppendInt(command.CharacterID);
		//UM3dCharacter* c = FindObject<UM3dCharacter>(this, *name, true);
		UM3dCharacter* c = characters[command.CharacterID];

		//UM3dCharacter* c = characters[command.CharacterID];
		c->MouthX = (float)(int)spawn_character.MouthX;
		c->MouthY = (float)(int)spawn_character.MouthY;
		c->MouthWidth = (float)(int)spawn_character.MouthWidth;
		c->MouthHeight = (float)(int)spawn_character.MouthHeight;
		c->EyesX = (float)(int)spawn_character.EyesX;
		c->EyesY = (float)(int)spawn_character.EyesY;
		c->EyesWidth = (float)(int)spawn_character.EyesWidth;
		c->EyesHeight = (float)(int)spawn_character.EyesHeight;

		c->LoadMouthSequence(1,this);
		c->LoadMouthSequence(3,this);
		c->SetBodyAnimation(0, this);//hopefully doesn't use up too much memory
		c->MergeMouthSequences(animation_sets);
		//put character off-screen
		AssignCharacterToSlot(c->ID, NULL);
		/*
		if (GEngine) {
			//GEngine->AddOnScreenDebugMessage(0, 13.0f, FColor::Green, MyStr);

			//m3d body
			FString MyStr = "character id ";
			MyStr.AppendInt(c->ID);
			//MyStr.AppendInt(entry1.body_mesh_id);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 13.0f, FColor::Green, MyStr);
		}
		*/

		//if (command.focusPortraitID==command.PortraitID) {
			//c->character_lit = true;
		//}
		/*
		if (GEngine) {
			FString MyStr;
			MyStr = "EyesX ";
			MyStr.AppendInt((int)spawn_character.EyesX);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
			MyStr = "EyesY ";
			MyStr.AppendInt((int)spawn_character.EyesY);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
			MyStr = "EyesWidth ";
			MyStr.AppendInt((int)spawn_character.EyesWidth);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
			MyStr = "EyesHeight ";
			MyStr.AppendInt((int)spawn_character.EyesHeight);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
		}
		*/

		//c->Update(0);
		/*
		if (GEngine) {
			FString MyStr;
			MyStr= "MouthX ";
			MyStr.AppendInt((int)spawn_character.MouthX);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
			MyStr = "MouthY ";
			MyStr.AppendInt((int)spawn_character.MouthY);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
			MyStr = "MouthWidth ";
			MyStr.AppendInt((int)spawn_character.MouthWidth);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
			MyStr = "MouthHeight ";
			MyStr.AppendInt((int)spawn_character.MouthHeight);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
		}
		*/

		//return;

		//characters[ID] = 
	}

	if (command.DestroyPortrait) {
		//destroy the character and portrait
		//You don't need to do anything explicit to destroy the UObject. Once all pointers to it are nulled, the garbage collector will clean it up.
		UCanvasPanel* Panel = (UCanvasPanel*)wDougUI->GetWidgetFromName("CanvasPanel_0");

		for (int i = 0; i < portraits.Num(); i++) {
			FPortrait* pp = &portraits[i];

			if (pp->PortraitID==command.DestroyPortraitID) {
				//destroy portrait.
				Panel->RemoveChild(pp->portrait_image);
				Panel->RemoveChild(pp->portrait_border);
				Panel->RemoveChild(pp->portrait_background);

				//Des
				//pp->portrait_image->BeginDestroy();
				//pp->portrait_border->BeginDestroy();
				//pp->portrait_background->BeginDestroy();
				//pp->MIDynamicBackground->BeginDestroy();

				//Panel->

				//remove references to initiate garbage collec tio
				pp->portrait_image = NULL;
				pp->portrait_border = NULL;
				pp->portrait_background = NULL;

				pp->MIDynamicBackground = NULL;
				pp->tex_background = NULL;


				//remove character(actually just from slot, don't destroy)
				//UM3dCharacter* c = characters[pp->CharacterID];
				/*FString name = "Character";
				//name.AppendInt(ID);
				name.AppendInt(command.CharacterID);
				UM3dCharacter* c = FindObject<UM3dCharacter>(this, *name, true);
				*/
				UM3dCharacter* c = characters[command.CharacterID];

				//c->character_lit = false;
				//do I need that^ code here?
				//might as well stop talking if portrait is not visible
				c->is_talking = false;

				//remove character from slot
				if (slot1.taken) {
					if (slot1.CharacterID == c->ID) {
						//remove character from slot
						slot1.CharacterID = -1;
						slot1.taken = false;
					}
				}
				if (slot2.taken) {
					if (slot2.CharacterID == c->ID) {
						//remove character from slot
						slot2.CharacterID = -1;
						slot2.taken = false;
					}
				}
				if (slot3.taken) {
					if (slot3.CharacterID == c->ID) {
						//remove character from slot
						slot3.CharacterID = -1;
						slot3.taken = false;
					}
				}
				if (slot4.taken) {
					if (slot4.CharacterID == c->ID) {
						//remove character from slot
						slot4.CharacterID = -1;
						slot4.taken = false;
					}
				}
				//if (slot5.CharacterID == c->ID) {
					//remove character from slot
					//slot5.CharacterID = -1;
					//slot5.taken = false;
				//}

				//c->RemoveReferences(this);//garbage collect materials
				//c->RemoveReferences(this);//garbage collect materials
				//delete c;
				//characters.Remove(pp->CharacterID);

				//characters.re

				//remove from portraits
				portraits.RemoveAt(i);
				break;
			}
		}
	}

	//create the 
	if (command.spawn_portrait) 
	{
		//Spawn a new portrait:

		//re-position the character that will be displayed in this
		//portrait frame

		//return;

		RENDER_SLOT* slot = FindFreeSlot();

		//return;

		//UM3dCharacter* c = characters[command.DisplayCharacterID];
		//FString name = "Character";
		//name.AppendInt(command.DisplayCharacterID);
		//UM3dCharacter* c = FindObject<UM3dCharacter>(this, *name,true);
		UM3dCharacter* c = characters[command.DisplayCharacterID];

		//return;
		
		AssignCharacterToSlot(c->ID, slot);

		FPortrait p;
		p.PortraitID = command.PortraitID;
		p.CharacterID = command.DisplayCharacterID;

		p.portrait_image = CreateImage();
		p.portrait_border = CreateImage();
		p.portrait_background = CreateImage();

		//Get the widget panel and screen resolution scale_x,scale_y
		if (wDougUI)
		{
			//let add it to the view port
			//wDougUI->
			//wDougUI->AddToViewport();

			//spawn an image
			UCanvasPanel* Panel = (UCanvasPanel*)wDougUI->GetWidgetFromName("CanvasPanel_0");//include header
																			//UImage* img = (UImage*)wDougUI->GetWidgetFromName("Image_91");
																								//Panel->AddChildToCanvas(img);
			float scale_x = 0;// GetFloatByName(wDougUI, "EditorVariableScaleX");
			if (GetFloatByName(wDougUI, "EditorVariableScaleX", scale_x)) {

				FString Mystr = "scale_x " + FString::SanitizeFloat(scale_x);
				UKismetSystemLibrary::PrintString(GetWorld(), Mystr, true, false);
			}
			float scale_y = 0;// GetFloatByName(wDougUI, "EditorVariableScaleX");
			if (GetFloatByName(wDougUI, "VarScaleY", scale_y)) {

				FString Mystr = "scale_y " + FString::SanitizeFloat(scale_y);
				UKismetSystemLibrary::PrintString(GetWorld(), Mystr, true, false);
			}
			FVector2D size(32, 32);
			FVector2D draw_size(230 * scale_x, 225 * scale_y);

			//Background
			p.MIDynamicBackground = UMaterialInstanceDynamic::Create(GenericBackgroundMaterial, this);
			FString filename = "/Game/Portrait/Textures/" + command.BackgroundName;
			p.tex_background = LoadObject<UTexture>(nullptr, *filename);
			p.MIDynamicBackground->SetTextureParameterValue("BackgroundTex", p.tex_background);
			FSlateMaterialBrush brush = FSlateMaterialBrush(*((UMaterialInterface*)p.MIDynamicBackground), size);
			p.portrait_background->SetBrush(brush);
			Panel->AddChildToCanvas(p.portrait_background);
			UCanvasPanelSlot* panel_slot = (UCanvasPanelSlot*)p.portrait_background->Slot;
			FVector2D Position2 = FVector2D((command.spawn_x*1280.0f / 640.0f)*scale_x, (command.spawn_y*720.0f / 480.0f)*scale_y);
			panel_slot->SetPosition(Position2);
			//image1->SetDrawSize(230,225);
			draw_size = FVector2D(230 * scale_x *128.0f/96.0f, 225 * scale_y);
			panel_slot->SetSize(draw_size);
			panel_slot->ZOrder = 1;

			/*if (img1mat) {
				portrait_image1 = CreateImage();
				//UMaterial* brush_mat = GetMaterial("TargetMaterial1");
				//FVector2D size(256, 256);
				FVector2D size(32, 32);
				FSlateMaterialBrush brush(*((UMaterialInterface*)img1mat), size);
				portrait_image1->SetBrush(brush);
				Panel->AddChildToCanvas(portrait_image1);
				UCanvasPanelSlot* slot = (UCanvasPanelSlot*)portrait_image1->Slot;
				//image1->SetDrawSize(230,225);
				FVector2D draw_size(230 * scale_x, 225 * scale_y);
				slot->SetSize(draw_size);
			}
			*/
			
			brush= FSlateMaterialBrush(*((UMaterialInterface*)slot->mat), size);
			
			p.portrait_image->SetBrush(brush);
			
			Panel->AddChildToCanvas(p.portrait_image);
			panel_slot = (UCanvasPanelSlot*)p.portrait_image->Slot;

			FVector2D Position((command.spawn_x*1280.0f/640.0f)*scale_x, (command.spawn_y*720.0f/480.0f)*scale_y);
			panel_slot->SetPosition(Position);

			//image1->SetDrawSize(230,225);
			draw_size = FVector2D(230 * scale_x, 225 * scale_y);
			panel_slot->SetSize(draw_size);
			panel_slot->ZOrder = 2;
			//tmp
			//Panel->RemoveChild(p.portrait_image);

			//Now put a border over the character portrait
			//FVector2D size(32, 32);
			brush= FSlateMaterialBrush(*((UMaterialInterface*)slot->mat_border), size);
			p.portrait_border->SetBrush(brush);
			Panel->AddChildToCanvas(p.portrait_border);
			panel_slot = (UCanvasPanelSlot*)p.portrait_border->Slot;
			Position= FVector2D((command.spawn_x*1280.0f / 640.0f)*scale_x, (command.spawn_y*720.0f / 480.0f)*scale_y);
			panel_slot->SetPosition(Position);
			//image1->SetDrawSize(230,225);
			draw_size= FVector2D(230 * scale_x, 225 * scale_y);
			panel_slot->SetSize(draw_size);
			panel_slot->ZOrder = 3;

			//wDougUI->
			portraits.Add(p);
		}

		//c->SetBodyTexture("MB", tex);//setting texture must be done after character constructor-so a.k.a in ExecuteCommand, when portrait is spawned

			//Show the Cursor.
			//bShowMouseCursor = true;

		//character now occupies the slot:
		//slot->taken = true;

		//load .m3d files from .db file and assign character
		//to a free slot

		//position the character at the slot

		//now character is being viewed by that slot's camera
		//c->SetBodyTexture("MB", tex, BodyMaterial, this);
	}

	if (command.stop_talking) {
		SoundManager2::StopSound(this);
		//remove focus from other characters
		//for
		
		/*for (auto& Elem : characters)
		{
			if ((Elem.Value)->character_lit) {
				(Elem.Value)->SetBodyAnimation(0, this);
			}
			(Elem.Value)->character_lit = false;
		}
		*/
		for (auto& Elem : characters)
		{
			if ((Elem.Value)->is_talking) {

				if (GEngine) {
					//GEngine->AddOnScreenDebugMessage(0, 13.0f, FColor::Green, MyStr);

					//m3d body
					FString MyStr = "stopping talking character id ";
					MyStr.AppendInt((Elem.Value)->ID);
					//MyStr.AppendInt(entry1.body_mesh_id);
					GEngine->AddOnScreenDebugMessage(INDEX_NONE, 13.0f, FColor::Green, MyStr);
				}

				(Elem.Value)->SetBodyAnimation(0, this);
			}
			(Elem.Value)->is_talking = false;
		}
		/*
		for (int i = 0; i < AllCharacterIDs.Num(); i++) {
			FString name = AllCharacterIDs[i];

			UM3dCharacter* c = FindObject<UM3dCharacter>(this, *name,true);

			//c->Update(DeltaTime, this);
			if (c->character_lit) {
				c->SetBodyAnimation(0, this);
			}
			c->character_lit = false;
		}
		*/
	}

	if (command.set_focus) {
	
		//remove focus from other characters
		//actually, only character that has focus(i.e. not=animation set 0)
		//otherwise they will all be moving in sync
		for (auto& Elem : characters)
		{
			if ((Elem.Value)->int_body_animation!=0) {

				//if (GEngine) {
					//GEngine->AddOnScreenDebugMessage(0, 13.0f, FColor::Green, MyStr);

					//m3d body
					//FString MyStr = "stopping talking character id ";
					//MyStr.AppendInt((Elem.Value)->ID);
					//MyStr.AppendInt(entry1.body_mesh_id);
					//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 13.0f, FColor::Green, MyStr);
				//}

				(Elem.Value)->SetBodyAnimation(0, this);
			}
			//(Elem.Value)->is_talking = false;
		}

		//for
		/*
			for (auto& Elem : characters)
			{
				(Elem.Value)->character_lit=false;
			}
			*/
		/*
		for (auto& Elem : characters)
		{
			if ((Elem.Value)->character_lit) {
				(Elem.Value)->SetBodyAnimation(0, this);
			}
			(Elem.Value)->character_lit = false;
		}
		*/
		
		/*for (int i = 0; i < AllCharacterIDs.Num(); i++) {
			FString name = AllCharacterIDs[i];

			UM3dCharacter* c = FindObject<UM3dCharacter>(this, *name,true);

			//c->Update(DeltaTime, this);
			if (c->character_lit) {
				c->SetBodyAnimation(0, this);
			}
			c->character_lit = false;
		}
		*/
		//FString name=

		UM3dCharacter* c = characters[command.CharacterID];
		//FString name = "Character";
		//name.AppendInt(command.CharacterID);
		//UM3dCharacter* c = FindObject<UM3dCharacter>(this, *name,true);

		//put light at slot position
		
		if (slot1.taken) {
			if (slot1.CharacterID == c->ID) {
				//char is at slot
				FVector LightPosition = slot1.Position + RelativeToSlotLightPos;
				//focus_light->SetWorldLocation(LightLocation);
				//focus_light->SetRelativeLocation(LightPosition);
				focus_light->SetActorLocation(LightPosition);
			}
		}
		
		if (slot2.taken) {
			if (slot2.CharacterID == c->ID) {
				//char is at slot
				FVector LightPosition = slot2.Position + RelativeToSlotLightPos;
				//focus_light->SetWorldLocation(LightLocation);
				//focus_light->SetRelativeLocation(LightPosition);
				//focus_light->SetWorldLocation(LightPosition);
				focus_light->SetActorLocation(LightPosition);
			}
		}
		
		if (slot3.taken) {
			if (slot3.CharacterID == c->ID) {
				//char is at slot
				FVector LightPosition = slot3.Position + RelativeToSlotLightPos;
				//focus_light->SetWorldLocation(LightLocation);
				//focus_light->SetRelativeLocation(LightPosition);
				//focus_light->SetWorldLocation(LightPosition);
				focus_light->SetActorLocation(LightPosition);
			}
		}
		
		if (slot4.taken) {
			if (slot4.CharacterID == c->ID) {
				//char is at slot
				FVector LightPosition = slot4.Position + RelativeToSlotLightPos;
				//focus_light->SetWorldLocation(LightLocation);
				//focus_light->SetRelativeLocation(LightLocation);
				//focus_light->SetWorldLocation(LightPosition);
				focus_light->SetActorLocation(LightPosition);
			}
		}
		

		//c->SetBodyAnimation(2, this);
		//c->SetBodyAnimation(18, this);
		c->SetBodyAnimation(26, this);
		/*
		if (command.audio != "") {
			delayed_audio = command.audio;
			delay_elapsed = 0.0f;
			delay = command.audio_delay;

			//SoundManager2::PlaySound(this, "MB018");
			//SoundManager2::PlaySound(this, command.audio);
		}
		*/
	}

	if (command.start_talking) {
		//start mouth moving
		UM3dCharacter* c = characters[command.CharacterID];//command.DisplayCharacterID

		c->is_talking = true;
		/*
		if (delayed_audio != "") {
			//delayed_audio = command.audio;
			//delay_elapsed = 0.0f;
			delay_elapsed += DeltaTime;

			if (delay_elapsed >= delay) {
				//SoundManager2::PlaySound(this, "MB018");
				SoundManager2::PlaySound(this, delayed_audio);
				delayed_audio = "";
			}
		}
		*/
		if (command.audio != "") {
			//delayed_audio = command.audio;
			//delay_elapsed = 0.0f;
			//delay = command.audio_delay;

			//SoundManager2::PlaySound(this, "MB018");
			SoundManager2::PlaySound(this, command.audio);
		}
	}
}

void ASceneController::LeftMousePressed()
{
	//duration = 0;
	//next command
	//if (command_elapsed >= duration) {
		//execute command 0, remove it
	/**/
	/*
		if (commands.Num() > 0) {
			ExecuteCommand(commands[0]);

			duration = commands[0].duration;

			commands.RemoveAt(0);
			//count time elapsed since current command
			command_elapsed = 0.0f;
		}
		*/
	//duration = 1;
	//go to the next focus command or end of scene if no more focus commands
	if (commands.Num() > 0) {
		//more_focus_commands = false;

		bool more_focus_commands = false;

		for (int i = 0; i < commands.Num();i++) {
			if (commands[i].set_focus) {
				more_focus_commands = true;
			}
		}

		if (more_focus_commands) 
		{
			//while (true) {
			while(commands.Num()>0)
			{
				//go to next command
				if (commands[0].skip_on_click) {
					//skip
					commands.RemoveAt(0);
				}
				else {
					//execute command.
					ExecuteCommand(commands[0]);

					bool halt = false;

					if (commands[0].set_focus)
					{
						//focus reached
						halt = true;
						//if (!commands[0].skip_on_click) {
							//do not skip
							//break;
						//}
					}

					duration = commands[0].duration;

					commands.RemoveAt(0);
					//count time elapsed since current command
					command_elapsed = 0.0f;

					if (halt) {
						//stop ex
						break;
					}
				}
			}
		}
		else {
			//execute remaining commands
			while (commands.Num()>0) 
			{
				if (commands[0].skip_on_click) {
					commands.RemoveAt(0);
				}
				else {
					//execute command.
					ExecuteCommand(commands[0]);

					//if (commands[0)

					duration = commands[0].duration;

					commands.RemoveAt(0);
					//count time elapsed since current command
					command_elapsed = 0.0f;
				}
			}
		}
	}
	//}
}

RENDER_SLOT * ASceneController::FindFreeSlot()
{
	if (!slot1.taken) {
		/*
		if (GEngine) {

			FString MyStr = "slot1 free ";
			GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Green, MyStr);
		}
		*/
		return &slot1;
	}
	if (!slot2.taken) {
		/*
		if (GEngine) {

			FString MyStr = "slot2 free ";
			GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Green, MyStr);
		}
		*/
		return &slot2;
	}
	if (!slot4.taken) {

		if (GEngine) {

			FString MyStr = "slot4 free ";
			GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Green, MyStr);
		}

		return &slot4;
	}
	if (!slot3.taken) {
		/*
		if (GEngine) {

			FString MyStr = "slot3 free ";
			GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Green, MyStr);
		}
		*/
		return &slot3;
	}
	
	//if (!slot5.taken) {

		//if (GEngine) {

			//FString MyStr = "slot4 free ";
			//GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Green, MyStr);
		//}

		//return &slot5;
	//}
	return nullptr;
}

// Called every frame
void ASceneController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!paused) {
		PlayScene(DeltaTime);

		if (GEngine) {
			FString MyStr = "playing scene ";
			//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Yellow, MyStr);
		}
	}

	//UE_LOG(LogTemp, Warning, TEXT("hello"));
	//FString MyStr = "Mystr";
	//UKismetSystemLibrary::PrintString(GetWorld(), MyStr, true, false);
}

/*
Loads keyframes into 
TArray<BodyHeadAnimationSet> animation_sets;
*/
void ASceneController::LoadBodyHeadAnimationSetsFromFile(FString directory, FString seq_filename, FString key_filename)
{/*/
 /*	BodyHeadAnimationSet set;
	animation_sets.Add(set);
	KEYFRAME f_head;
	KEYFRAME f_body;
	HeadEyes f_eyes;
	f_head.is_keyframe = true;
	f_head.float_degrees_y = 45.0f;
	f_head.time = 15.0f;
	f_head.is_half_y = false;

	f_body.is_keyframe = true;
	f_body.time = 15.0f;
	f_body.is_half_y = false;
	
	animation_sets[0].HEAD_KEYS.Add(f_head);
	animation_sets[0].BODY_KEYS.Add(f_body);
	animation_sets[0].EyesMouth.Add(f_eyes);

	f_head.is_keyframe = true;
	f_head.float_degrees_y = 0.0f;
	f_head.time = 15.0f;
	f_head.is_half_y = false;

	animation_sets[0].HEAD_KEYS.Add(f_head);
	animation_sets[0].BODY_KEYS.Add(f_body);
	animation_sets[0].EyesMouth.Add(f_eyes);

	f_head.is_keyframe = true;
	f_head.float_degrees_y = 45.0f;
	f_head.time = 15.0f;
	f_head.is_half_y = false;

	animation_sets[0].HEAD_KEYS.Add(f_head);
	animation_sets[0].BODY_KEYS.Add(f_body);
	animation_sets[0].EyesMouth.Add(f_eyes);
	return;
	*/

	//Here we go
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	//FString ContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::GameContentDir());

	FString SEQFile = directory + seq_filename;
	FString KEYFile = directory + key_filename;

	if (PlatformFile.FileExists(*SEQFile)&&PlatformFile.FileExists(*KEYFile)) {
		/*
		if (GEngine) {
			FString MyStr = "seq exists!";
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
		}
		if (GEngine) {
			FString MyStr = "key exists!";
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
		}
		*/

		IFileHandle* FileHandleSEQ = PlatformFile.OpenRead(*SEQFile);
		IFileHandle* FileHandleKEY = PlatformFile.OpenRead(*KEYFile);

		if (FileHandleSEQ&&FileHandleKEY) {

			//Read contents of file
			//allocate memory for 1 byte
			BYTE* byteBuffer = reinterpret_cast<BYTE*>(FMemory::Malloc(sizeof(BYTE)));

			//skip first byte
			FileHandleSEQ->Read(byteBuffer, 1);
			//th
			int num_sets = (int)*byteBuffer;

			if (GEngine) {
				//FString MyStr;
				//MyStr = "Byte value ";
				//MyStr.AppendInt((int)*byteBuffer);
				//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
			}

			int sets_read = 0;
			int last_key = 0;
			while (sets_read != num_sets)
			{
				//read next byte(number of frames in animation set)
				//arrived at animation set
				//read next byte(number of frames in animation set)
				//actually skip it:
				FileHandleSEQ->Read(byteBuffer, 1);
				int count = (int)*byteBuffer;

				//count is frames in set including 02 and 08
				int start = FileHandleSEQ->Tell();

				//Now read keyframes for head body
				BodyHeadAnimationSet set;
				animation_sets.Add(set);
				//animation_sets2.Add(set);
				KEYFRAME f_head;
				KEYFRAME f_body;
				HeadEyes f_eyes;
				//Implement ReadFileKeyframe():
				int current_set = sets_read;
				//the tricky bit is getting is_keyframe
				while (KEYFRAME::ReadFileKeyframe(FileHandleSEQ, FileHandleKEY, &f_head, &f_body, &f_eyes, &last_key)) {
					//mouth_eyes_keyframes.Add(f);
					//int current_set = sets_read;//index of current set
					//if ((f_eyes.index_eyes==-1)&&(f_eyes.index_mouth == -1)) {
						//Not a face keyframe
						animation_sets[current_set].HEAD_KEYS.Add(f_head);
						animation_sets[current_set].BODY_KEYS.Add(f_body);
						animation_sets[current_set].EyesMouth.Add(f_eyes);
						//animation_sets2[current_set].HEAD_KEYS.Add(f_head);
						//animation_sets2[current_set].BODY_KEYS.Add(f_body);
						//animation_sets2[current_set].EyesMouth.Add(f_eyes);
					//}

				}

				//remove last frame
				/* (animation_sets[sets_read].HEAD_KEYS.Num()>0) {
					animation_sets[sets_read].HEAD_KEYS.RemoveAt(animation_sets[sets_read].HEAD_KEYS.Num()-1);
					animation_sets[sets_read].BODY_KEYS.RemoveAt(animation_sets[sets_read].BODY_KEYS.Num()-1);
					animation_sets[sets_read].EyesMouth.RemoveAt(animation_sets[sets_read].EyesMouth.Num()-1);
				}
				*/

				//add a 0 frame at the end
				//KEYFRAME f_head;
				//KEYFRAME f_body;

				//move cursor to next set
				FileHandleSEQ->Seek(start+4*count);//each frame is 4 bytes, 02 and 08 are 4 bytes too, 4*count

				sets_read++;
			}

			RemoveDeadFrames(animation_sets);//if a dead frame is encountered, increase the time of the previous frame(first encountered left-wise) by length_eyes(0.08)
			//add a zero frame at the end to blend nicely back to zero
			/*
			for (int l = 0; l < animation_sets.Num();l++) {
				KEYFRAME f_head = KEYFRAME();
				KEYFRAME f_body = KEYFRAME();
				f_head.float_degrees_x = 0;
				f_head.float_degrees_y = 0;
				f_head.float_degrees_z = 0;
				f_head.is_half_x = false;
				f_head.is_half_y = false;
				f_head.is_half_z = false;
				f_head.is_keyframe = true;
				f_head.time = 1.0;
				f_body.float_degrees_x = 0;
				f_body.float_degrees_y = 0;
				f_body.float_degrees_z = 0;
				f_body.is_half_x = false;
				f_body.is_half_y = false;
				f_body.is_half_z = false;
				f_body.is_keyframe = true;
				f_body.time = 1.0;
				animation_sets[l].HEAD_KEYS.Add(f_head);
				animation_sets[l].BODY_KEYS.Add(f_body);
			}
			*/
			

			delete FileHandleSEQ;
			delete FileHandleKEY;

			// Free the memory allocated to the byte buffer
			FMemory::Free(byteBuffer);

			//Update mouth start state
			//PlayMouthSequence(0.0f);
			//Update(0.0f);
		}
	}
}

/*
This is a wee bit complicated, but make sure it's right
each keyframe that isn't HeadEyes should have is_keyframe=true or false
before calling this function.
is_keyframe means the keyframe is body(true) or mouth(false)
*/
void ASceneController::RemoveDeadFrames(TArray<BodyHeadAnimationSet>& animation_sets)
{
	float time_from_start = 0.0f;

	for (int i = 0; i < animation_sets.Num(); i++) 
	{
		if (animation_sets[i].BODY_KEYS.Num()==0) {
			//no keys loaded, empty animation set
			//continue to prevent application from crashing,
			//e.g. animation_sets[i].HEAD_KEYS[0] will be NULL
			continue;
		}

		int last_frame = 0;
		//there needs to be a frame at start in case there are eyes frames at
		//start, the time it takes for those eyes frames must be
		//accumulated
		if (!animation_sets[i].HEAD_KEYS[0].is_keyframe) {
			//first frame is not a body frame so create a body frame
			KEYFRAME frame;
			frame.is_keyframe = true;
			frame.float_degrees_x = 0;
			frame.float_degrees_y = 0;
			frame.float_degrees_z = 0;
			frame.is_half_x = false;
			frame.is_half_y = false;
			frame.is_half_z = false;
			frame.time = 0.1f;//1 second
			//BodyHeadAnimationSet set1;
			//set1.HEAD_KEYS.Add(frame);
			//set1.BODY_KEYS.Add(frame);
			//animation_sets.Insert(set1, 0);
			animation_sets[i].BODY_KEYS.Insert(frame,0);
			animation_sets[i].HEAD_KEYS.Insert(frame, 0);
			animation_sets[i].EyesMouth.Insert(HeadEyes(),0);

			time_from_start = 0.1f;
		}

		//int valid_key = 0;
		int valid_index = 0;

		for (int j = 0; j < animation_sets[i].BODY_KEYS.Num(); j++) 
		{
			//fix animation set
			if (animation_sets[i].BODY_KEYS[j].is_keyframe) {
				last_frame = j;//index into BODY_KEYS
				time_from_start += animation_sets[i].BODY_KEYS[j].time;
			}
			else {
				//eyes or mouth encountered
				time_from_start += MOUTH_KEYFRAME_DURATION*1.0f;

				//delete from list
				animation_sets[i].BODY_KEYS[last_frame].time += MOUTH_KEYFRAME_DURATION*1.0f;
				animation_sets[i].HEAD_KEYS[last_frame].time += MOUTH_KEYFRAME_DURATION*1.0f;
				animation_sets[i].BODY_KEYS.RemoveAt(j);
				animation_sets[i].HEAD_KEYS.RemoveAt(j);
				/*
				if (GEngine &&(i==0)) {
					FString MyStr = "removed ";
					MyStr.AppendInt(valid_index);
					MyStr += "animation set ";
					MyStr.AppendInt(i);
					GEngine->AddOnScreenDebugMessage(INDEX_NONE, 13.0f, FColor::White, *MyStr);
				}
				*/

				//animation_sets[i].EyesMouth contains a list of eye keyframes and therefore the valid ones
				//
				animation_sets[i].EyesMouth[valid_index].time_from_start = time_from_start;
				
				j--;
			}

			valid_index++;//index into eyes list, because j is modified, j no longer is valid for that list
		}
	}
	//remove dead eye frames
	for (int i = 0; i < animation_sets.Num(); i++) {
		for (int j = 0; j < animation_sets[i].EyesMouth.Num(); j++) {
			if ((animation_sets[i].EyesMouth[j].index_eyes==-1)&& (animation_sets[i].EyesMouth[j].index_mouth == -1)) {
				//dead frame
				animation_sets[i].EyesMouth.RemoveAt(j);
				j--;
			}
		}
	}

	//Now animation_sets[n].EyesMouth contains states and the time each state should be inserted into another list and only valid HeadEyes
	//Now animation_sets[n].BODY_KEYS contains correct times for each frame and only body+head frames
	//Now animation_sets[n].HEAD_KEYS contains correct times for each frame and only body+head frames
}