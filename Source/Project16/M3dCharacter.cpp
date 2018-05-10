// Fill out your copyright notice in the Description page of Project Settings.

#include "M3dCharacter.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Engine/engine.h"
#include "SceneController.h"
#include "Runtime/Core/Public/Containers/Map.h"

//#define MOUTH_KEYFRAME_DURATION 0.08

HeadEyes::HeadEyes()
{
	index_eyes = -1;
	index_mouth = -1;
}

bool HeadEyes::ReadKeyframe(IFileHandle* FileHandle, HeadEyes* keyframe_out)
{
	//return true if there is a keyframe, false if 08 encountered
	//read 4 bytes
	//scrub existing values:
	keyframe_out->index_eyes = -1;
	keyframe_out->index_mouth = -1;

	BYTE* byteBuffer = reinterpret_cast<BYTE*>(FMemory::Malloc(sizeof(BYTE)*4));

	//skip first byte
	FileHandle->Read(byteBuffer, 4);

	//interpret 4 bytes read:
	//eyes first
	int N1 = (int)byteBuffer[0];
	int N2 = (int)byteBuffer[1];
	int N3 = (int)byteBuffer[2];
	int N4 = (int)byteBuffer[3];

	if ((N1==5)&&(N3==0)&&(N4==0)) {
		//Found eye keyframe
		keyframe_out->index_eyes = (int)N2;
	}
	if ((N1 == 6) && (N3 == 0) && (N4 == 0)) {
		//Found mouth keyframe
		keyframe_out->index_mouth = (int)N2;
	}

	FMemory::Free(byteBuffer);

	if (keyframe_out->index_mouth != -1) {
		//return here so memory is freed
		return true;
	}
	if (keyframe_out->index_eyes!=-1) {
		//return here so memory is freed
		return true;
	}

	return false;
}

UM3dCharacter::UM3dCharacter(class FObjectInitializer const&)
{
	//change_body_animation = false;
	//int_previous_animation_set = -1;

	MatInst = NULL;
	MatInstHead = NULL;
	MatInstNeck = NULL;
	health = 100.0f;//TODO: load health from game character(Chris project)

	//Animation
	mouth_elapsed = 0.0f;
	mouth_keyframe = 0;

	//character_lit = false;
	is_talking = false;

	int_body_animation = -1;
}

void UM3dCharacter::Initialize()
{
	MatInst = NULL;
	MatInstHead = NULL;
	MatInstNeck = NULL;
	health = 100.0f;//TODO: load health from game character(Chris project)

					//Animation
	mouth_elapsed = 0.0f;
	mouth_keyframe = 0;

	//character_lit = false;
	is_talking = false;

	int_body_animation = -1;
}

UM3dCharacter::~UM3dCharacter()
{
}

void UM3dCharacter::SetBodyTexture(FString code, UTexture* tex, UMaterialInterface* BodyMaterial, ASceneController* scene)
{
	if (MatInst) {
		//matarial already exists
		return;
	}

	//Set texture to MB
	//FString path = "Texture'/Game/";
	//FString texture_name = "MB_HEAD";
	//ConstructorHelpers::FObjectFinder<UTexture> T = ConstructorHelpers::FObjectFinder<UTexture>(*(path + texture_name + "." + texture_name + "'"));
	//if (T.Succeeded()) {
		//UTexture* tex;
		//tex = T.Object;
		//UKismetSystemLibrary::PrintString(GetWorld(), "Found Texture", true, false);
		//UMaterialInterface* M = StaticMeshHead->GetMaterial(0);
		
		if (BodyMaterial) {
			MatInst = UMaterialInstanceDynamic::Create(BodyMaterial, scene);

			//StaticMeshHead->mater

			//MI1 = UMaterialInstanceDynamic::Create(Inst, NULL);
			if (MatInst) {
				//Inst->TextureParameterValues[0].ParameterValue = tex;
				//Inst->SetTextureParameterValue("HeadTexture", tex);
				MatInst->SetTextureParameterValue("MainTexture", tex);

				//Get head component and set it's material
				FString str = "Component" + ID;
				UStaticMeshComponent* C = scene->meshes[str];

				C->SetMaterial(0, MatInst);

				//Getmater
				/*
				if (GEngine) {
					//m3d body
					FString MyStr = "Applying texture ";
					//MyStr.AppendInt(entry1.body_mesh_id);
					GEngine->AddOnScreenDebugMessage(0, 13.0f, FColor::Green, MyStr);
				}
				*/

				/*
				if (A) {
					if (A->GetMeshComponentHead()) {
						A->GetMeshComponentHead()->SetMaterial(0, MI1);
					}
				}
				*/
				//UKismetSystemLibrary::PrintString(GetWorld(), "Setting Texture", true, false);
			}
		}
	//}
}

/*
TODO: Update this function to support injured textures when health is <70.0%
*/
void UM3dCharacter::SetHeadTexture(FString code, UMaterialInterface* GenericHeadMaterial, ASceneController* scene)
{
	if (MatInstHead) {
		//matarial instance already exists
		return;
	}

	UTexture* tex_head = NULL;
	UTexture* tex_mouth = NULL;
	if (health>=70.0) {//70 percent health is *_HEAD
		FString filename = "/Game/Portrait/Textures/" + code+"_HEAD";
		tex_head = LoadObject<UTexture>(nullptr, *filename);
		filename = "/Game/Portrait/Textures/" + code + "_BITS";
		tex_mouth = LoadObject<UTexture>(nullptr, *filename);
	}

	//Set texture to MB
	//FString path = "Texture'/Game/";
	//FString texture_name = "MB_HEAD";
	//ConstructorHelpers::FObjectFinder<UTexture> T = ConstructorHelpers::FObjectFinder<UTexture>(*(path + texture_name + "." + texture_name + "'"));
	//if (T.Succeeded()) {
	//UTexture* tex;
	//tex = T.Object;
	//UKismetSystemLibrary::PrintString(GetWorld(), "Found Texture", true, false);
	//UMaterialInterface* M = StaticMeshHead->GetMaterial(0);

	if (GenericHeadMaterial) {
		MatInstHead = UMaterialInstanceDynamic::Create(GenericHeadMaterial, scene);
		//MatInstHead->addref
		//StaticMeshHead->mater

		//MI1 = UMaterialInstanceDynamic::Create(Inst, NULL);
		if (MatInstHead) {
			//Inst->TextureParameterValues[0].ParameterValue = tex;
			//Inst->SetTextureParameterValue("HeadTexture", tex);
			MatInstHead->SetTextureParameterValue("HeadTexture", tex_head);
			MatInstHead->SetTextureParameterValue("MouthTexture", tex_mouth);
			MatInstHead->SetTextureParameterValue("EyesTexture", tex_mouth);

			//Get head component and set it's material
			//FString str = "Component" + ID;
			FString strID = "Head";
			strID.AppendInt(ID);
			UStaticMeshComponent* C = scene->meshes[strID];

			C->SetMaterial(0, MatInstHead);
			/*
			if (GEngine) {
				float texture_width = 0.0f;
				float texture_height = 0.0f;
				texture_width = tex_head->GetSurfaceWidth();
				texture_height = tex_head->GetSurfaceHeight();
				FString MyStr;
				MyStr = "head texture width " + FString::SanitizeFloat(texture_width);
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Yellow, MyStr);
				MyStr = "head texture height " + FString::SanitizeFloat(texture_height);
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Yellow, MyStr);
			}
			if (GEngine) {
				float texture_width = 0.0f;
				float texture_height = 0.0f;
				texture_width = tex_mouth->GetSurfaceWidth();
				texture_height = tex_mouth->GetSurfaceHeight();
				FString MyStr;
				MyStr = "mouth texture width " + FString::SanitizeFloat(texture_width);
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Yellow, MyStr);
				MyStr = "mouth texture height " + FString::SanitizeFloat(texture_height);
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Yellow, MyStr);
			}
			*/

			//Getmater
			/*
			if (GEngine) {
			//m3d body
			FString MyStr = "Applying texture ";
			//MyStr.AppendInt(entry1.body_mesh_id);
			GEngine->AddOnScreenDebugMessage(0, 13.0f, FColor::Green, MyStr);
			}
			*/

			/*
			if (A) {
			if (A->GetMeshComponentHead()) {
			A->GetMeshComponentHead()->SetMaterial(0, MI1);
			}
			}
			*/
			//UKismetSystemLibrary::PrintString(GetWorld(), "Setting Texture", true, false);
			//Update(0);
		}
	}
	//}
}

/*
TODO: Update this function to support injured textures when health is <70.0%
*/
void UM3dCharacter::SetBodyTexture(FString code, UMaterialInterface* GenericBodyMaterial, ASceneController* scene)
{
	if (MatInst) {
		//matarial instance already exists
		return;
	}

	UTexture* tex_body = NULL;
	//UTexture* tex_mouth = NULL;
	if (health >= 70.0) {//70 percent health is *_HEAD
		FString filename = "/Game/Portrait/Textures/" + code + "_BODY";
		tex_body = LoadObject<UTexture>(nullptr, *filename);
		//filename = "/Game/Portrait/Textures/" + code + "_BITS";
		//tex_mouth = LoadObject<UTexture>(nullptr, *filename);
	}

	if (GenericBodyMaterial) {
		MatInst = UMaterialInstanceDynamic::Create(GenericBodyMaterial, scene);

		//StaticMeshHead->mater

		if (MatInst) 
		{
			MatInst->SetTextureParameterValue("MainTexture", tex_body);
			//MatInstHead->SetTextureParameterValue("MouthTexture", tex_mouth);
			FString strID = "Body";
			strID.AppendInt(ID);
			UStaticMeshComponent* C = scene->meshes[strID];

			C->SetMaterial(0, MatInst);
		}
	}
}

/*
TODO: Update this function to support injured textures when health is <70.0%
*/
void UM3dCharacter::SetNeckTexture(FString code, UMaterialInterface* GenericBodyMaterial, ASceneController* scene)
{
	if (MatInstNeck) {
		//matarial instance already exists
		return;
	}

	UTexture* tex_neck = NULL;
	//UTexture* tex_mouth = NULL;
	if (health >= 70.0) {//70 percent health is *_HEAD
		FString filename = "/Game/Portrait/Textures/" + code + "_HEAD";
		tex_neck = LoadObject<UTexture>(nullptr, *filename);
		//filename = "/Game/Portrait/Textures/" + code + "_BITS";
		//tex_mouth = LoadObject<UTexture>(nullptr, *filename);
	}

	if (GenericBodyMaterial) {
		MatInstNeck = UMaterialInstanceDynamic::Create(GenericBodyMaterial, scene);

		//StaticMeshHead->mater

		if (MatInstNeck)
		{
			MatInstNeck->SetTextureParameterValue("MainTexture", tex_neck);
			//MatInstHead->SetTextureParameterValue("MouthTexture", tex_mouth);
			FString strID = "Neck";
			strID.AppendInt(ID);
			UStaticMeshComponent* C = scene->meshes[strID];

			C->SetMaterial(0, MatInstNeck);
		}
	}
}

void UM3dCharacter::Update(float DeltaTime, ASceneController* scene)
{
	//Animate the character
	if (MatInstHead) {

		if (is_talking) {
			PlayMouthSequence(DeltaTime,false);
			//PlayBodySequence(DeltaTime);
			//PlayEyesSequence(DeltaTime);
		}
		else {
			//PlayMouthSequence(DeltaTime);
			//PlayEyesSequence(DeltaTime);
			PlayMouthSequence(DeltaTime,true);
		}
		if (int_body_animation!=-1) {
			PlayBodySequence(DeltaTime*0.8f , scene);
		}

		//if (GEngine) {
			//float texture_width = 0.0f;
			//float texture_height = 0.0f;
			//texture_width = tex_mouth->GetSurfaceWidth();
			//texture_height = tex_mouth->GetSurfaceHeight();
			//FString MyStr;
			//MyStr = "message ";
			//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Yellow, MyStr);
		//}
		/*
		if (GEngine) {
			//float texture_width = 0.0f;
			//float texture_height = 0.0f;
			//texture_width = tex_mouth->GetSurfaceWidth();
			//texture_height = tex_mouth->GetSurfaceHeight();
			FString MyStr;
			MyStr = "mouth width "+FString::SanitizeFloat(MouthWidth);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Yellow, MyStr);
			MyStr = "mouth height " + FString::SanitizeFloat(MouthHeight);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Yellow, MyStr);
			MyStr = "mouth x " + FString::SanitizeFloat(MouthX);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Yellow, MyStr);
			MyStr = "mouth y " + FString::SanitizeFloat(MouthY);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Yellow, MyStr);
		}
		*/

		//Not anymore: Work out ResUV(VectorParameter)
		//Not anymore: PercentH Scalar
		//Not anymore: PercentW Scalar

		//BitsRegionNormalized
		//DisplayRegionNormalized

		//InputRect1 is the position of the mouth on the final image
		//FLinearColor V;
		//FLinearColor V2;

		UTexture* tex_head;
		float texture_head_width = 0.0f;
		float texture_head_height = 0.0f;
		bool got_tex = false;
		if (MatInstHead->GetTextureParameterValue("HeadTexture", tex_head)) {

			texture_head_width = tex_head->GetSurfaceWidth();
			texture_head_height = tex_head->GetSurfaceHeight();
			got_tex = true;
		}
		/*
		UTexture* tex_mouth;
		float texture_mouth_width = 0.0f;
		float texture_mouth_height = 0.0f;
		if (MatInstHead->GetTextureParameterValue("MouthTexture", tex_mouth)) {

			texture_mouth_width = tex_mouth->GetSurfaceWidth();
			texture_mouth_height = tex_mouth->GetSurfaceHeight();

		}
		*/
		if (got_tex) {
			FLinearColor DisplayRegion;
			DisplayRegion.R = MouthX / texture_head_width;
			DisplayRegion.G = MouthY / texture_head_height;
			DisplayRegion.B = MouthWidth / texture_head_width;
			DisplayRegion.A = MouthHeight / texture_head_height;

			/*
			This is the region I need to animate:
			this is the current mouth that
			is displayed:
			*/
			/*
			FRECT BitsRegion;
			BitsRegion.R = 0.0f / texture_mouth_width;
			BitsRegion.G = 0.0f / texture_mouth_height;
			BitsRegion.B = MouthWidth / texture_mouth_width;
			BitsRegion.A = MouthHeight / texture_mouth_height;
			*/

			MatInstHead->SetVectorParameterValue("DisplayRegionNormalized", DisplayRegion);
			//MatInstHead->getvec
		}

		MatInstHead->SetVectorParameterValue("BitsRegionNormalized", BitsRegionMouth);

		//Do Eyes Now:
		if (got_tex) {
			FLinearColor DisplayRegionEyes;
			DisplayRegionEyes.R = EyesX / texture_head_width;
			DisplayRegionEyes.G = EyesY / texture_head_height;
			DisplayRegionEyes.B = EyesWidth / texture_head_width;
			DisplayRegionEyes.A = EyesHeight / texture_head_height;

			/*
			This is the region I need to animate:
			this is the current eyes that
			is displayed:
			*/
			/*
			FLinearColor BitsRegionEyes;
			BitsRegionEyes.R = 0.0f / texture_mouth_width;
			BitsRegionEyes.G = 0.0f / texture_mouth_height;
			BitsRegionEyes.B = EyesWidth / texture_mouth_width;
			BitsRegionEyes.A = EyesHeight / texture_mouth_height;
			*/

			MatInstHead->SetVectorParameterValue("DisplayRegionNormalized_Eyes", DisplayRegionEyes);
		}

		MatInstHead->SetVectorParameterValue("BitsRegionNormalized_Eyes", BitsRegionEyes);

		//Maybe it's not working(displaying messages) cause too frequent, every update:
		/*
		if (GEngine) {
			FString MyStr;
			MyStr = "texture width " + FString::SanitizeFloat(texture_width);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Yellow, MyStr);
		}
		*/

		//pixel 15 for example is 15/230
		/*
		V.R = MouthX / texture_width;
		V.G = 0.6;
		MatInstHead->SetVectorParameterValue("InputRect1", V);
		V2.R = (MouthX + MouthWidth) / texture_width;
		V2.G = 1.0f;
		MatInstHead->SetVectorParameterValue("InputRect1_2", V2);
		*/

		//InputRect2 is the section of mouth on the bits image

		UpdateBody();
	}
}

void UM3dCharacter::UpdateBody()
{
	//return;

	if (MeshHead==nullptr) {return;}
	if (MeshHeadMask == nullptr) { return; }
	if (MeshBody == nullptr) { return; }
	if (MeshBodyMask == nullptr) { return; }
	if (MeshNeck == nullptr) { return; }
	if (MeshNeckMask == nullptr) { return; }

	const FRotator r = FRotator(HeadAnimation.GetRotZ(),-HeadAnimation.GetRotY(), -HeadAnimation.GetRotX());
	//const FRotator r = FRotator(0, 0, 0.0f);
	//r.Pitch = 0;
	//r.Yaw = -45.0f;//degrees
	//r.Yaw = HeadAnimation.GetRotY();
	//r.Roll = 0.0f;
	//MeshHead->SetRelativeRotation(r.Quaternion());
	//MeshHeadMask->SetRelativeRotation(r.Quaternion());

	//rotate body around pivot
	//rotate pivot
	const FRotator pivot_rotator(BodyAnimation.GetRotZ(), -BodyAnimation.GetRotY(),-BodyAnimation.GetRotX());
	//pivot_rotator.Roll = -BodyAnimation.GetRotX();
	//pivot_rotator.Pitch = BodyAnimation.GetRotZ();
	//pivot_rotator.Yaw = BodyAnimation.GetRotY();

	//FVector StartPos = FVector();
	//FVector StartPos = this->BodyStartPosition;

	/*
	Do body rotation
	*/
	{
		FVector P = this->BodyPivot;

		FVector V = this->BodyStartPosition - P;
		const FRotationMatrix M1 = FRotationMatrix(pivot_rotator);
		const FTranslationMatrix M3 = FTranslationMatrix(V);
		const FTranslationMatrix M4 = FTranslationMatrix(P);
		const FMatrix Result = M3*M1*M4;

		MeshBody->SetWorldTransform(FTransform(Result));

		FVector NeckPivotRelative = this->NeckPivot - this->BodyStartPosition;
		const FTranslationMatrix MRel_NeckPivot = FTranslationMatrix(NeckPivotRelative);
		const FMatrix MChild_NeckPivot = MRel_NeckPivot*Result;
		//MeshNeck->SetWorldTransform(FTransform(MChild_NeckPivot));

		//do neck(not pivot):
		//neck mask is a child of neck mask pivot
		FVector NeckRelative = this->NeckStartPosition - this->NeckPivot;
		const FTranslationMatrix MRel_Neck = FTranslationMatrix(NeckRelative);
		const FMatrix MChild_Neck = MRel_Neck*MChild_NeckPivot;

		MeshNeck->SetWorldTransform(FTransform(MChild_Neck));

		//do head pivot, head pivot is a child of neck pivot
		FVector HeadPivotRelative = this->HeadPivot - this->NeckPivot;
		const FTranslationMatrix MRel_HeadPivot = FTranslationMatrix(HeadPivotRelative);
		const FMatrix MChild_HeadPivot = MRel_HeadPivot*MChild_NeckPivot;

		//Now I have the world position of the head pivot, I need the world position of the head
		//and then FVector V = this->HeadPosition - P;, 
		//P is the pivot itself(HeadPivot)
		FVector HeadRelative = this->HeadStartPosition - this->HeadPivot;
		const FTranslationMatrix MRel_Head = FTranslationMatrix(HeadRelative);
		const FMatrix MChild_Head = MRel_Head*MChild_HeadPivot;//good MChild_Head is good

		//get world position from matrix
		FVector Head = MChild_Head.GetOrigin();

		//I've got the world position and rotation M1
		//Now I want to rotate around pivot HeadPivotWorld
		FVector HeadPivotWorld = MChild_HeadPivot.GetOrigin();
		const FTranslationMatrix HeadPivotWorldM = FTranslationMatrix(HeadPivotWorld);
		FVector V2 = Head - HeadPivotWorld;
		const FTranslationMatrix M5 = FTranslationMatrix(V2);

		//const FTranslationMatrix WorldHead = FTranslationMatrix(WorldPosition);
		//const FRotationMatrix HeadR = FRotationMatrix(pivot_rotator);
		const FRotationMatrix HeadR = FRotationMatrix(r);
		//FMatrix MHeadPosition 
		const FTranslationMatrix MHeadPosition = MChild_Head.GetOrigin();
		//
		//rotation around a point
		
		//const FMatrix WorldRotHead = M5*HeadR*HeadPivotWorldM*MChild_Head;
		const FMatrix WorldRotHead = M1*M5*HeadR*HeadPivotWorldM;

			//FVector HeadPivotRelative = this->HeadPivot - this->NeckPivot;
		//const FTranslationMatrix MRel_HeadPivot = FTranslationMatrix(HeadPivotRelative);
		//const FMatrix MChild_HeadPivot = MRel_HeadPivot*MChild_NeckPivot;
		//const FTranslationMatrix test_mat = FTranslationMatrix(HeadStartPosition);
		MeshHead->SetWorldTransform(FTransform(WorldRotHead));//here
		//MeshHead->SetWorldTransform(FTransform(MChild_Head));
	}
	/*
	Do body mask rotation
	*/
	{
		FVector P = this->BodyMaskPivot;

		FVector V2 = this->BodyMaskStartPosition - P;
		const FRotationMatrix M1 = FRotationMatrix(pivot_rotator);
		const FTranslationMatrix M3 = FTranslationMatrix(V2);
		const FTranslationMatrix M4 = FTranslationMatrix(P);
		const FMatrix Result = M3*M1*M4;
		MeshBodyMask->SetWorldTransform(FTransform(Result));

		//Do neck mask pivot:
		FVector NeckMaskPivotRelative = this->NeckMaskPivot - this->BodyMaskStartPosition;
		const FTranslationMatrix MRel_NeckMaskPivot = FTranslationMatrix(NeckMaskPivotRelative);
		const FMatrix MChild_NeckMaskPivot = MRel_NeckMaskPivot*Result;

		//do neck(not pivot) mask:
		//neck mask is a child of neck mask pivot
		FVector NeckMaskRelative = this->NeckMaskStartPosition - this->NeckMaskPivot;
		const FTranslationMatrix MRel_NeckMask = FTranslationMatrix(NeckMaskRelative);
		const FMatrix MChild_NeckMask = MRel_NeckMask*MChild_NeckMaskPivot;

		MeshNeckMask->SetWorldTransform(FTransform(MChild_NeckMask));

		//do head pivot, head pivot is a child of neck pivot
		//FVector HeadMaskPivotRelative = this->HeadMaskPivot - this->NeckMaskPivot;
		//const FTranslationMatrix MRel_HeadMaskPivot = FTranslationMatrix(HeadPivotRelative);
		//const FMatrix MChild_HeadPivot = MRel_HeadPivot*MChild_NeckPivot;

		//do head pivot, head pivot is a child of neck pivot
		FVector HeadMaskPivotRelative = this->HeadMaskPivot - this->NeckMaskPivot;
		const FTranslationMatrix MRel_HeadMaskPivot = FTranslationMatrix(HeadMaskPivotRelative);
		const FMatrix MChild_HeadMaskPivot = MRel_HeadMaskPivot*MChild_NeckMaskPivot;//head pivot is child of neck pivot

		//Now I have the world position of the head pivot, I need the world position of the head
		//and then FVector V = this->HeadPosition - P;, 
		//P is the pivot itself(HeadPivot)
		FVector HeadMaskRelative = this->HeadMaskStartPosition - this->HeadMaskPivot;
		const FTranslationMatrix MRel_HeadMask = FTranslationMatrix(HeadMaskRelative);
		const FMatrix MChild_HeadMask = MRel_HeadMask*MChild_HeadMaskPivot;//child of pivot
		//get world position from matrix
		FVector WorldPosition = MChild_HeadMask.GetOrigin();//world position of head

		FVector HeadMaskPivotWorld/*world position of head pivot*/ = MChild_HeadMaskPivot.GetOrigin();
		const FTranslationMatrix HeadMaskPivotWorldM = FTranslationMatrix(HeadMaskPivotWorld);
		FVector HeadMaskWorldPosition = MChild_HeadMask.GetOrigin();//world position of head
		FVector V3 = WorldPosition - HeadMaskPivotWorld;
		const FTranslationMatrix M5 = FTranslationMatrix(V3);

		//const FTranslationMatrix WorldHeadMask = FTranslationMatrix(WorldPosition);
		//const FRotationMatrix HeadR = FRotationMatrix(pivot_rotator);
		const FRotationMatrix HeadR = FRotationMatrix(r);
		//const FMatrix WorldRotHeadMask = M5*HeadR*HeadMaskPivotWorldM*MChild_HeadMask;
		const FMatrix WorldRotHeadMask = M1*M5*HeadR*HeadMaskPivotWorldM;

		//MeshNeckMask->SetWorldTransform(FTransform(MChild_NeckMask));

		MeshHeadMask->SetWorldTransform(FTransform(WorldRotHeadMask));
	}

	//A child has RelativeTransform*ParentWorldTransform
	/*
	FVector NeckPivotRelative = this->NeckPivot - this->BodyStartPosition;
	const FTranslationMatrix MRel_NeckPivot = FTranslationMatrix(NeckPivotRelative);
	const FMatrix MChild_NeckPivot = MRel_NeckPivot*Result;
	MeshNeck->SetWorldTransform(FTransform(MChild_NeckPivot));
	*/
	
	//FMatrix Res
	//Body then mask
	//Ft
	/*
	FTransform T;
	T.SetIdentity();
	T.SetLocation(BodyPivot);
	T.SetRotation(pivot_rotator.Quaternion());
	FMatrix PivotWorld = T.ToMatrixNoScale();

	//transform the body
	//body parent is the pivot
	FTransform BodyWorldTransform;
	BodyWorldTransform.SetIdentity();
	BodyWorldTransform.SetLocation(BodyStartPosition);
	FMatrix body_mat = BodyWorldTransform.ToMatrixNoScale();

	FTransform TRotation;
	TRotation.SetIdentity();
	TRotation.SetRotation(pivot_rotator.Quaternion());
	FMatrix Rotation=TRotation.ToMatrixNoScale();

	FTransform Inv(PivotWorld);//need this to copy matrix
	FMatrix InvMat = Inv.ToMatrixNoScale();
	FMatrix MRel = Rotation*InvMat.Inverse()*FMatrix(body_mat);
	
	//FMatrix Rel1= FTransform(MRel).tom
	FMatrix Rel1 = FTransform(MRel).ToMatrixNoScale();
	FMatrix Res = FMatrix(Rel1*PivotWorld);
	MeshBody->SetWorldTransform(FTransform(Res));
	*/
	/*
	//Now the mask
	T.SetIdentity();
	T.SetLocation(BodyMaskPivot);
	T.SetRotation(pivot_rotator.Quaternion());
	FMatrix PivotMaskWorld = T.ToMatrixNoScale();

	//transform the body
	//body parent is the pivot
	FTransform BodyMaskWorldTransform;
	BodyMaskWorldTransform.SetIdentity();
	BodyMaskWorldTransform.SetLocation(BodyMaskStartPosition);
	FMatrix bodymask_mat = BodyMaskWorldTransform.ToMatrixNoScale();

	//FTransform TRotation;
	TRotation.SetIdentity();
	TRotation.SetRotation(pivot_rotator.Quaternion());
	Rotation = TRotation.ToMatrixNoScale();

	FTransform InvMask(PivotMaskWorld);//need this to copy matrix
	FMatrix InvMaskMat = InvMask.ToMatrixNoScale();
	//MRel = Rotation*InvMaskMat.Inverse()*FMatrix(bodymask_mat);
	FMatrix Rel2 = FTransform(MRel).ToMatrixNoScale();
	Res = FMatrix(Rel2*PivotMaskWorld);
	MeshBodyMask->SetWorldTransform(FTransform(Res));
	*/
}

void UM3dCharacter::LoadMouthSequence(int animation_set, ASceneController* scene)
{
	//there needs to be one keyframe for eyes and mouth to be updated:
	HeadEyes f;
	f.index_eyes = 0;
	f.index_mouth = 0;
	mouth_eyes_keyframes.Add(f);

	if (animation_set==0) {
		//precaution, if user thinks it's 0-based
		animation_set = 1;
	}

	//Here we go
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	FString ContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::GameContentDir());

	FString SEQFile = ContentDirectory + "Portrait/Script/126.seq";

	if (PlatformFile.FileExists(*SEQFile)) {
		/*FString MyStr = "126.seq exists!";
		if (GEngine) {
			//FString MyStr;
			//MyStr = "EyesX ";
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
		}
		*/
		
		IFileHandle* FileHandle = PlatformFile.OpenRead(*SEQFile);

		if (FileHandle) {

			//Read contents of file
			//allocate memory for 1 byte
			BYTE* byteBuffer = reinterpret_cast<BYTE*>(FMemory::Malloc(sizeof(BYTE)));

			//skip first byte
			FileHandle->Read(byteBuffer, 1);
			/*
			if (GEngine) {
				//FString MyStr;
				MyStr = "Byte value ";
				MyStr.AppendInt((int)*byteBuffer);
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
			}
			*/

			//read a byte
			/*
			FileHandle->Read(byteBuffer, 1);

			if (GEngine) {
				//FString MyStr;
				MyStr = "Byte value ";
				MyStr.AppendInt((int)*byteBuffer);
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
			}
			*/

			//skip to "animation_set e.g. 3"
			int current_set = 1;
			while (current_set!=animation_set) 
			{
				//read next byte(number of frames in animation set)
				FileHandle->Read(byteBuffer, 1);
				int count = (int)*byteBuffer;

				int bytes_to_skip = 4 * count;
				for (int bytes_read = 0; bytes_read < bytes_to_skip; bytes_read++) {
					//skip 1 byte
					FileHandle->Read(byteBuffer, 1);
				}

				current_set++;
			}
			//arrived at animation set
			//read next byte(number of frames in animation set)
			//actually skip it:
			FileHandle->Read(byteBuffer, 1);
			int count = (int)*byteBuffer;
			//Now read keyframes for mouth and eyes
			HeadEyes f;
			while (HeadEyes::ReadKeyframe(FileHandle, &f)) {
				mouth_eyes_keyframes.Add(f);
			}

			delete FileHandle;

			// Free the memory allocated to the byte buffer
			FMemory::Free(byteBuffer);

			//Update mouth start state
			PlayMouthSequence(0.0f,false);
			Update(0.0f,scene);
		}
	}
}
void UM3dCharacter::RemoveReferences(ASceneController* scene) {
	MatInst = NULL;//Body
	//UMaterialInstanceDynamic* MatInstHead;
	//UMaterialInstanceDynamic* MatInstNeck;
	MatInstHead = NULL;
	MatInstNeck = NULL;

	//remove mesh components used by this character
	//scene->ASceneController* scene
	{
	scene->components.Remove(MeshHead);
	scene->components.Remove(MeshHeadMask);
	//get
	FString str = "";
	FString id = str + *scene->meshes.FindKey(MeshHead);
	scene->meshes.Remove(id);
	scene->static_meshes.Remove(id);
    }
	{
		scene->components.Remove(MeshBody);
		scene->components.Remove(MeshBodyMask);
		//get
		FString str = "";
		FString id = str+*scene->meshes.FindKey(MeshBody);
		scene->meshes.Remove(id);
		scene->static_meshes.Remove(id);
	}
	{
		scene->components.Remove(MeshNeck);
		scene->components.Remove(MeshNeckMask);
		//get
		FString str = "";
		FString id = str + *scene->meshes.FindKey(MeshNeck);
		scene->meshes.Remove(id);
		scene->static_meshes.Remove(id);
	}
}
void UM3dCharacter::MergeMouthSequences(TArray<BodyHeadAnimationSet>& loaded_sets)
{
	//for (int i = 0; i < loaded_sets.Num(); i++) 
	//{
	if (loaded_sets.Num()>(int_body_animation)) 
	{
		BodyHeadAnimationSet set = loaded_sets[int_body_animation];

		for (int i = 0; i < set.EyesMouth.Num(); i++) 
		{//for each eye frame in the set
			HeadEyes eyes_mouth = set.EyesMouth[i];
			float time = eyes_mouth.time_from_start;
			bool ins = false;

			//insert at right time
			//insert if time_from_start is below time of current index
			//or if there are no more frames
			for (int j = 0; j < mouth_eyes_keyframes.Num();j++) {

				//int index =
				//float time_of_one_frame = 0.08;
				float j_time = j*MOUTH_KEYFRAME_DURATION;

				if (time<=j_time)
				{
					//insert here
					mouth_eyes_keyframes.Insert(eyes_mouth, j);
					ins = true;
					break;
				}

			}
			if (!ins) {
				//insert at end
				mouth_eyes_keyframes.Insert(eyes_mouth, mouth_eyes_keyframes.Num()-1);
			}
		}

		//set used by character is int_animation_set-1
	}
	//}
}
void UM3dCharacter::PlayBodySequence(float DeltaTime, ASceneController* scene)
{
	//Make sure keys are valid:
	//e.g. if they were changed then assign
	//address of new keys to pointers
	//also do -1from int_body_animation to convert from 1-based to 0-based index:
	//check if animation set exists(animation_sets.Num()>(int_body_animation - 1)):
	/*
	if (int_previous_animation_set!=-1) {
		if (this->scene->animation_sets.Num() > (int_previous_animation_set - 1))
		{
			if (this->scene->animation_sets[int_previous_animation_set - 1].BODY_KEYS.Num() != 0) {
				//HeadAnimation.KEYS_PREV = &this->scene->animation_sets[int_previous_animation_set - 1].HEAD_KEYS;
				//BodyAnimation.KEYS_PREV = &this->scene->animation_sets[int_previous_animation_set - 1].BODY_KEYS;

				//HeadAnimation.Play(DeltaTime);
				//BodyAnimation.Play(DeltaTime);
			}
		}
	}
	*/
	if ((int_body_animation>=0)&&(scene->animation_sets.Num()>(int_body_animation))) 
	{
		if (scene->animation_sets[int_body_animation].BODY_KEYS.Num() != 0) {
			//HeadAnimation.KEYS = &this->scene->animation_sets[int_body_animation - 1].HEAD_KEYS;
			//BodyAnimation.KEYS = &this->scene->animation_sets[int_body_animation - 1].BODY_KEYS;

			//Make sure HeadAnimation.StartAnimationSet has been called before this:

			HeadAnimation.Play(DeltaTime);
			BodyAnimation.Play(DeltaTime);
		}
	}
}
/*
This is the function I was working on-no
Load keyframes using 
We could have our own file type for keyframes

NOT 0-based animation_set
*/
void UM3dCharacter::SetBodyAnimation(int animation_set, ASceneController* scene)
{
	//HeadAnimation.ToFirstFrame();
	//BodyAnimation.ToFirstFrame();

	//HeadAnimation = SEQ();//reset animation to first frame
	//BodyAnimation = SEQ();

	//HeadAnimation.change_body_animation = true;
	//BodyAnimation.change_body_animation = true;
	HeadAnimation.StartAnimationSet(animation_set, &scene->animation_sets[animation_set].HEAD_KEYS);
	BodyAnimation.StartAnimationSet(animation_set, &scene->animation_sets[animation_set].BODY_KEYS);

	//int_previous_animation_set = int_body_animation;

	//this->scene = scene;//animation sets are stored in the scene
						//so take a pointer to the current scene here
	int_body_animation = animation_set;

	/*
	//there needs to be one keyframe for eyes and mouth to be updated:
	//HeadEyes f;
	//f.index_eyes = 0;
	//f.index_mouth = 0;
	//HeadAnimationKeys.AddKey(0,0,0,1);
	//BodyAnimationKeys.AddKey(0, 0, 0, 1);

	if (animation_set == 0) {
		//precaution, if user thinks it's 0-based
		animation_set = 1;
	}

	//Here we go
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	FString ContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::GameContentDir());

	FString SEQFile = ContentDirectory + "Portrait/Script/0.seq";

	if (PlatformFile.FileExists(*SEQFile)) {
		FString MyStr = "0.seq exists!";
		if (GEngine) {
			//FString MyStr;
			//MyStr = "EyesX ";
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
		}

		IFileHandle* FileHandle = PlatformFile.OpenRead(*SEQFile);

		if (FileHandle) {

			//Read contents of file
			//allocate memory for 1 byte
			BYTE* byteBuffer = reinterpret_cast<BYTE*>(FMemory::Malloc(sizeof(BYTE)));

			//skip first byte
			FileHandle->Read(byteBuffer, 1);

			if (GEngine) {
				//FString MyStr;
				MyStr = "Byte value ";
				MyStr.AppendInt((int)*byteBuffer);
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
			}
			*/
			//read a byte
			/*
			FileHandle->Read(byteBuffer, 1);

			if (GEngine) {
			//FString MyStr;
			MyStr = "Byte value ";
			MyStr.AppendInt((int)*byteBuffer);
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 7.0f, FColor::Green, MyStr);
			}
			*/
	/*
			//skip to "animation_set e.g. 3"
			int current_set = 1;
			while (current_set != animation_set)
			{
				//read next byte(number of frames in animation set)
				FileHandle->Read(byteBuffer, 1);
				int count = (int)*byteBuffer;

				int bytes_to_skip = 4 * count;
				for (int bytes_read = 0; bytes_read < bytes_to_skip; bytes_read++) {
					//skip 1 byte
					FileHandle->Read(byteBuffer, 1);
				}

				current_set++;
			}
			//arrived at animation set
			//read next byte(number of frames in animation set)
			//actually skip it:
			FileHandle->Read(byteBuffer, 1);
			int count = (int)*byteBuffer;
			//Now read keyframes for mouth and eyes
			HeadEyes f;
			while (HeadEyes::ReadKeyframe(FileHandle, &f)) {
				mouth_eyes_keyframes.Add(f);
			}

			delete FileHandle;

			// Free the memory allocated to the byte buffer
			FMemory::Free(byteBuffer);

			//Update mouth start state
			PlayMouthSequence(0.0f);
			Update(0.0f);
		}
	}
	*/
}
FRECT UM3dCharacter::ToFRectMouth(int index){
	//FRECT R;
	FRECT BitsRegionMouth;

	if (MatInstHead) {//will be set to null by reflection if object is destroyed
		UTexture* tex_mouth;
		if (MatInstHead->GetTextureParameterValue("MouthTexture", tex_mouth)) {
			float texture_mouth_width = 0.0f;
			float texture_mouth_height = 0.0f;
			texture_mouth_width = tex_mouth->GetSurfaceWidth();
			texture_mouth_height = tex_mouth->GetSurfaceHeight();

			//2 columns, could use 3 but 2 for now cause
			//index will be from 0 to 4 most of time(5 mouth states)

			//float col = floor((float)index) - (row*2.0f);
			float col = floor(((float)index) / 16.0f);
			float row = index - (col*16.0f);//I've got columns and rows mixed up, there are 16 rows
			BitsRegionMouth.R = col*MouthWidth / texture_mouth_width;
			BitsRegionMouth.G = row*MouthHeight / texture_mouth_height;
			BitsRegionMouth.B = MouthWidth / texture_mouth_width;
			BitsRegionMouth.A = MouthHeight / texture_mouth_height;
		}
	}

	return BitsRegionMouth;
}
FRECT UM3dCharacter::ToFRectEyes(int index) {
	//FRECT R;
	FRECT BitsRegionEyes;

	if (MatInstHead) {
		UTexture* tex_mouth;
		if (MatInstHead->GetTextureParameterValue("MouthTexture", tex_mouth)) {
			float texture_mouth_width = 0.0f;
			float texture_mouth_height = 0.0f;
			texture_mouth_width = tex_mouth->GetSurfaceWidth();
			texture_mouth_height = tex_mouth->GetSurfaceHeight();

			//index 1 is eyes open
			//index 0 is eyes closed
			//1 column
			float row = floor(((float)index) / 1.0f);
			float col = ((float)index) - (row*1.0f);
			BitsRegionEyes.R = (texture_mouth_width - ((col + 1.0f)*EyesWidth)) / texture_mouth_width;
			BitsRegionEyes.G = (texture_mouth_height - ((row + 1.0f)*EyesHeight)) / texture_mouth_height;
			BitsRegionEyes.B = EyesWidth / texture_mouth_width;
			BitsRegionEyes.A = EyesHeight / texture_mouth_height;
		}
	}

	return BitsRegionEyes;
}
void UM3dCharacter::PlayMouthSequence(float DeltaTime, bool eyes_only)
{
	mouth_elapsed += DeltaTime;

	while (mouth_elapsed>=MOUTH_KEYFRAME_DURATION) {
		mouth_keyframe += 1;
		mouth_elapsed -= MOUTH_KEYFRAME_DURATION;
	}

	//cycle
	while (mouth_keyframe>=mouth_eyes_keyframes.Num()) {
		mouth_keyframe -= mouth_eyes_keyframes.Num();
	}

	if (!eyes_only) {
		if ((mouth_keyframe>=0)&&(mouth_keyframe<mouth_eyes_keyframes.Num())) {
			if (mouth_eyes_keyframes[mouth_keyframe].index_mouth != -1) {
				BitsRegionMouth = ToFRectMouth(mouth_eyes_keyframes[mouth_keyframe].index_mouth);
			}
		}
	}
	else {
		//close mouth
		if (mouth_eyes_keyframes.Num()>0) {
			if (mouth_eyes_keyframes[0].index_mouth != -1) {
				BitsRegionMouth = ToFRectMouth(mouth_eyes_keyframes[0].index_mouth);
			}
		}
		/*

		for (auto& Elem : characters)
	{
		(Elem.Value)->Update(DeltaTime);
	}
		*/
	}
	if ((mouth_keyframe >= 0)&&(mouth_keyframe < mouth_eyes_keyframes.Num())) {
		if (mouth_eyes_keyframes[mouth_keyframe].index_eyes != -1) {
			BitsRegionEyes = ToFRectEyes(mouth_eyes_keyframes[mouth_keyframe].index_eyes);
		}
	}
}