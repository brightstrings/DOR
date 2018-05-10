// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Project16.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1Project16() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API class UClass* Z_Construct_UClass_UObject();
	ENGINE_API class UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UTexture_NoRegister();
	UMG_API class UClass* Z_Construct_UClass_UImage_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USoundCue_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USoundBase_NoRegister();
	UMG_API class UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	COREUOBJECT_API class UClass* Z_Construct_UClass_UObject_NoRegister();

	PROJECT16_API class UClass* Z_Construct_UClass_ABeginPlayActor_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_ABeginPlayActor();
	PROJECT16_API class UClass* Z_Construct_UClass_AGameCharacter_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_AGameCharacter();
	PROJECT16_API class UClass* Z_Construct_UClass_ALightActor_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_ALightActor();
	PROJECT16_API class UClass* Z_Construct_UClass_AM3d_14_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_AM3d_14();
	PROJECT16_API class UClass* Z_Construct_UClass_AM3dActor_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_AM3dActor();
	PROJECT16_API class UClass* Z_Construct_UClass_UM3dCharacter_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_UM3dCharacter();
	PROJECT16_API class UClass* Z_Construct_UClass_AMeshActor_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_AMeshActor();
	PROJECT16_API class UScriptStruct* Z_Construct_UScriptStruct_FPortrait();
	PROJECT16_API class UFunction* Z_Construct_UFunction_ASceneController_LeftMousePressed();
	PROJECT16_API class UClass* Z_Construct_UClass_ASceneController_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_ASceneController();
	PROJECT16_API class UFunction* Z_Construct_UFunction_AGrissburgSceneController_SetupLevel();
	PROJECT16_API class UClass* Z_Construct_UClass_AGrissburgSceneController_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_AGrissburgSceneController();
	PROJECT16_API class UClass* Z_Construct_UClass_ASpawnLevel1_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_ASpawnLevel1();
	PROJECT16_API class UPackage* Z_Construct_UPackage__Script_Project16();
	void ABeginPlayActor::StaticRegisterNativesABeginPlayActor()
	{
	}
	UClass* Z_Construct_UClass_ABeginPlayActor_NoRegister()
	{
		return ABeginPlayActor::StaticClass();
	}
	UClass* Z_Construct_UClass_ABeginPlayActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_Project16();
			OuterClass = ABeginPlayActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<ABeginPlayActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BeginPlayActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("BeginPlayActor.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABeginPlayActor, 2130231260);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABeginPlayActor(Z_Construct_UClass_ABeginPlayActor, &ABeginPlayActor::StaticClass, TEXT("/Script/Project16"), TEXT("ABeginPlayActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABeginPlayActor);
	void AGameCharacter::StaticRegisterNativesAGameCharacter()
	{
	}
	UClass* Z_Construct_UClass_AGameCharacter_NoRegister()
	{
		return AGameCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_AGameCharacter()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_Project16();
			OuterClass = AGameCharacter::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<AGameCharacter> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("GameCharacter.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("GameCharacter.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGameCharacter, 4139089886);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGameCharacter(Z_Construct_UClass_AGameCharacter, &AGameCharacter::StaticClass, TEXT("/Script/Project16"), TEXT("AGameCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGameCharacter);
	void ALightActor::StaticRegisterNativesALightActor()
	{
	}
	UClass* Z_Construct_UClass_ALightActor_NoRegister()
	{
		return ALightActor::StaticClass();
	}
	UClass* Z_Construct_UClass_ALightActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_Project16();
			OuterClass = ALightActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<ALightActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("LightActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("LightActor.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALightActor, 421394053);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALightActor(Z_Construct_UClass_ALightActor, &ALightActor::StaticClass, TEXT("/Script/Project16"), TEXT("ALightActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALightActor);
	void AM3d_14::StaticRegisterNativesAM3d_14()
	{
	}
	UClass* Z_Construct_UClass_AM3d_14_NoRegister()
	{
		return AM3d_14::StaticClass();
	}
	UClass* Z_Construct_UClass_AM3d_14()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_Project16();
			OuterClass = AM3d_14::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<AM3d_14> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("M3d_14.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("M3d_14.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AM3d_14, 1405774127);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AM3d_14(Z_Construct_UClass_AM3d_14, &AM3d_14::StaticClass, TEXT("/Script/Project16"), TEXT("AM3d_14"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AM3d_14);
	void AM3dActor::StaticRegisterNativesAM3dActor()
	{
	}
	UClass* Z_Construct_UClass_AM3dActor_NoRegister()
	{
		return AM3dActor::StaticClass();
	}
	UClass* Z_Construct_UClass_AM3dActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_Project16();
			OuterClass = AM3dActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<AM3dActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("M3dActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("M3dActor.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AM3dActor, 3565886027);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AM3dActor(Z_Construct_UClass_AM3dActor, &AM3dActor::StaticClass, TEXT("/Script/Project16"), TEXT("AM3dActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AM3dActor);
	void UM3dCharacter::StaticRegisterNativesUM3dCharacter()
	{
	}
	UClass* Z_Construct_UClass_UM3dCharacter_NoRegister()
	{
		return UM3dCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_UM3dCharacter()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UObject();
			Z_Construct_UPackage__Script_Project16();
			OuterClass = UM3dCharacter::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_MatInstNeck = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MatInstNeck"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MatInstNeck, UM3dCharacter), 0x0040000000000000, Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister());
				UProperty* NewProp_MatInstHead = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MatInstHead"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MatInstHead, UM3dCharacter), 0x0040000000000000, Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister());
				UProperty* NewProp_MatInst = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MatInst"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MatInst, UM3dCharacter), 0x0040000000000000, Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister());
				UProperty* NewProp_MeshNeckMask = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MeshNeckMask"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MeshNeckMask, UM3dCharacter), 0x0010000000080008, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_MeshNeck = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MeshNeck"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MeshNeck, UM3dCharacter), 0x0010000000080008, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_MeshBodyMask = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MeshBodyMask"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MeshBodyMask, UM3dCharacter), 0x0010000000080008, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_MeshBody = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MeshBody"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MeshBody, UM3dCharacter), 0x0010000000080008, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_MeshHeadMask = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MeshHeadMask"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MeshHeadMask, UM3dCharacter), 0x0010000000080008, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_MeshHead = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MeshHead"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MeshHead, UM3dCharacter), 0x0010000000080008, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				static TCppClassTypeInfo<TCppClassTypeTraits<UM3dCharacter> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("M3dCharacter.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("M3dCharacter.h"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("UCLASS() to indicate class(M3dCharacter) is reflected"));
				MetaData->SetValue(NewProp_MatInstNeck, TEXT("ModuleRelativePath"), TEXT("M3dCharacter.h"));
				MetaData->SetValue(NewProp_MatInstNeck, TEXT("ToolTip"), TEXT("for reflection(null on garbage collect)"));
				MetaData->SetValue(NewProp_MatInstHead, TEXT("ModuleRelativePath"), TEXT("M3dCharacter.h"));
				MetaData->SetValue(NewProp_MatInstHead, TEXT("ToolTip"), TEXT("Body\nfor reflection(null on garbage collect)"));
				MetaData->SetValue(NewProp_MatInst, TEXT("ModuleRelativePath"), TEXT("M3dCharacter.h"));
				MetaData->SetValue(NewProp_MatInst, TEXT("ToolTip"), TEXT("for reflection(null on garbage collect)"));
				MetaData->SetValue(NewProp_MeshNeckMask, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_MeshNeckMask, TEXT("ModuleRelativePath"), TEXT("M3dCharacter.h"));
				MetaData->SetValue(NewProp_MeshNeck, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_MeshNeck, TEXT("ModuleRelativePath"), TEXT("M3dCharacter.h"));
				MetaData->SetValue(NewProp_MeshBodyMask, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_MeshBodyMask, TEXT("ModuleRelativePath"), TEXT("M3dCharacter.h"));
				MetaData->SetValue(NewProp_MeshBody, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_MeshBody, TEXT("ModuleRelativePath"), TEXT("M3dCharacter.h"));
				MetaData->SetValue(NewProp_MeshHeadMask, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_MeshHeadMask, TEXT("ModuleRelativePath"), TEXT("M3dCharacter.h"));
				MetaData->SetValue(NewProp_MeshHead, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_MeshHead, TEXT("ModuleRelativePath"), TEXT("M3dCharacter.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UM3dCharacter, 1424641182);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UM3dCharacter(Z_Construct_UClass_UM3dCharacter, &UM3dCharacter::StaticClass, TEXT("/Script/Project16"), TEXT("UM3dCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UM3dCharacter);
	void AMeshActor::StaticRegisterNativesAMeshActor()
	{
	}
	UClass* Z_Construct_UClass_AMeshActor_NoRegister()
	{
		return AMeshActor::StaticClass();
	}
	UClass* Z_Construct_UClass_AMeshActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_Project16();
			OuterClass = AMeshActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<AMeshActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("MeshActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("MeshActor.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMeshActor, 931827368);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMeshActor(Z_Construct_UClass_AMeshActor, &AMeshActor::StaticClass, TEXT("/Script/Project16"), TEXT("AMeshActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMeshActor);
class UScriptStruct* FPortrait::StaticStruct()
{
	extern PROJECT16_API class UPackage* Z_Construct_UPackage__Script_Project16();
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PROJECT16_API class UScriptStruct* Z_Construct_UScriptStruct_FPortrait();
		extern PROJECT16_API uint32 Get_Z_Construct_UScriptStruct_FPortrait_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPortrait, Z_Construct_UPackage__Script_Project16(), TEXT("Portrait"), sizeof(FPortrait), Get_Z_Construct_UScriptStruct_FPortrait_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPortrait(FPortrait::StaticStruct, TEXT("/Script/Project16"), TEXT("Portrait"), false, nullptr, nullptr);
static struct FScriptStruct_Project16_StaticRegisterNativesFPortrait
{
	FScriptStruct_Project16_StaticRegisterNativesFPortrait()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("Portrait")),new UScriptStruct::TCppStructOps<FPortrait>);
	}
} ScriptStruct_Project16_StaticRegisterNativesFPortrait;
	UScriptStruct* Z_Construct_UScriptStruct_FPortrait()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_Project16();
		extern uint32 Get_Z_Construct_UScriptStruct_FPortrait_CRC();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("Portrait"), sizeof(FPortrait), Get_Z_Construct_UScriptStruct_FPortrait_CRC(), false);
		if (!ReturnStruct)
		{
			ReturnStruct = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Portrait"), RF_Public|RF_Transient|RF_MarkAsNative) UScriptStruct(FObjectInitializer(), NULL, new UScriptStruct::TCppStructOps<FPortrait>, EStructFlags(0x00000005));
			UProperty* NewProp_tex_background = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("tex_background"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(tex_background, FPortrait), 0x0010000000000000, Z_Construct_UClass_UTexture_NoRegister());
			UProperty* NewProp_MIDynamicBackground = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("MIDynamicBackground"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MIDynamicBackground, FPortrait), 0x0010000000000000, Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister());
			UProperty* NewProp_portrait_background = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("portrait_background"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(portrait_background, FPortrait), 0x0010000000080008, Z_Construct_UClass_UImage_NoRegister());
			UProperty* NewProp_portrait_border = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("portrait_border"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(portrait_border, FPortrait), 0x0010000000080008, Z_Construct_UClass_UImage_NoRegister());
			UProperty* NewProp_portrait_image = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("portrait_image"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(portrait_image, FPortrait), 0x0010000000080008, Z_Construct_UClass_UImage_NoRegister());
			ReturnStruct->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnStruct->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnStruct, TEXT("ModuleRelativePath"), TEXT("SceneController.h"));
			MetaData->SetValue(ReturnStruct, TEXT("ToolTip"), TEXT("USTRUCT()"));
			MetaData->SetValue(NewProp_tex_background, TEXT("ModuleRelativePath"), TEXT("SceneController.h"));
			MetaData->SetValue(NewProp_MIDynamicBackground, TEXT("ModuleRelativePath"), TEXT("SceneController.h"));
			MetaData->SetValue(NewProp_MIDynamicBackground, TEXT("ToolTip"), TEXT("UMaterialInstance* Inst;\nUMaterialInstanceDynamic* MIDynamic;"));
			MetaData->SetValue(NewProp_portrait_background, TEXT("EditInline"), TEXT("true"));
			MetaData->SetValue(NewProp_portrait_background, TEXT("ModuleRelativePath"), TEXT("SceneController.h"));
			MetaData->SetValue(NewProp_portrait_border, TEXT("EditInline"), TEXT("true"));
			MetaData->SetValue(NewProp_portrait_border, TEXT("ModuleRelativePath"), TEXT("SceneController.h"));
			MetaData->SetValue(NewProp_portrait_image, TEXT("EditInline"), TEXT("true"));
			MetaData->SetValue(NewProp_portrait_image, TEXT("ModuleRelativePath"), TEXT("SceneController.h"));
#endif
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPortrait_CRC() { return 4114053706U; }
	void ASceneController::StaticRegisterNativesASceneController()
	{
		UClass* Class = ASceneController::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "LeftMousePressed", (Native)&ASceneController::execLeftMousePressed },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 1);
	}
	UFunction* Z_Construct_UFunction_ASceneController_LeftMousePressed()
	{
		UObject* Outer=Z_Construct_UClass_ASceneController();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("LeftMousePressed"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Functions"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("SceneController.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("FString delayed_audio;\nfloat delay_elapsed;\nfloat delay;"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASceneController_NoRegister()
	{
		return ASceneController::StaticClass();
	}
	UClass* Z_Construct_UClass_ASceneController()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_Project16();
			OuterClass = ASceneController::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_ASceneController_LeftMousePressed());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_characters = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("characters"), RF_Public|RF_Transient|RF_MarkAsNative) UMapProperty(CPP_PROPERTY_BASE(characters, ASceneController), 0x0010000000000000);
				UProperty* NewProp_characters_Key_KeyProp = new(EC_InternalUseOnlyConstructor, NewProp_characters, TEXT("characters_Key"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				UProperty* NewProp_characters_ValueProp = new(EC_InternalUseOnlyConstructor, NewProp_characters, TEXT("characters"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 1, 0x0000000000000000, Z_Construct_UClass_UM3dCharacter_NoRegister());
				UProperty* NewProp_sound = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("sound"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(sound, ASceneController), 0x0010000000000005, Z_Construct_UClass_USoundCue_NoRegister());
				UProperty* NewProp_base_sound = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("base_sound"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(base_sound, ASceneController), 0x0010000000000005, Z_Construct_UClass_USoundBase_NoRegister());
				UProperty* NewProp_wDougUIBlueprint = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("wDougUIBlueprint"), RF_Public|RF_Transient|RF_MarkAsNative) UClassProperty(CPP_PROPERTY_BASE(wDougUIBlueprint, ASceneController), 0x0014000000000005, Z_Construct_UClass_UUserWidget_NoRegister(), UClass::StaticClass());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASceneController_LeftMousePressed(), "LeftMousePressed"); // 2589958559
				static TCppClassTypeInfo<TCppClassTypeTraits<ASceneController> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SceneController.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("SceneController.h"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("class BodyHeadAnimationSet\n{\npublic:\n       TArray<KEYFRAME> HEAD_KEYS;//1-to-1 with BODY_KEYS\n       TArray<KEYFRAME> BODY_KEYS;//1-to-1 with HEAD_KEYS\n       TArray<HeadEyes> EyesMouth;//empty(-1) if body head keyframe is encountered so that index is correct\n                                                          //insert these into eyes mouth seq at index e.g. EyesMouth[i] to i of mouth_eyes_keyframes\n};"));
				MetaData->SetValue(NewProp_characters, TEXT("ModuleRelativePath"), TEXT("SceneController.h"));
				MetaData->SetValue(NewProp_characters, TEXT("ToolTip"), TEXT("UStaticMesh* StaticMesh;\nTArray<FString> AllCharacterIDs;"));
				MetaData->SetValue(NewProp_sound, TEXT("Category"), TEXT("Background Music"));
				MetaData->SetValue(NewProp_sound, TEXT("ModuleRelativePath"), TEXT("SceneController.h"));
				MetaData->SetValue(NewProp_base_sound, TEXT("Category"), TEXT("Background Music"));
				MetaData->SetValue(NewProp_base_sound, TEXT("ModuleRelativePath"), TEXT("SceneController.h"));
				MetaData->SetValue(NewProp_base_sound, TEXT("ToolTip"), TEXT("Not set in editor, set in Level Blueprint:"));
				MetaData->SetValue(NewProp_wDougUIBlueprint, TEXT("Category"), TEXT("Widgets"));
				MetaData->SetValue(NewProp_wDougUIBlueprint, TEXT("ModuleRelativePath"), TEXT("SceneController.h"));
				MetaData->SetValue(NewProp_wDougUIBlueprint, TEXT("ToolTip"), TEXT("Reference UMG Asset in the Editor"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASceneController, 2348208078);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASceneController(Z_Construct_UClass_ASceneController, &ASceneController::StaticClass, TEXT("/Script/Project16"), TEXT("ASceneController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASceneController);
	void AGrissburgSceneController::StaticRegisterNativesAGrissburgSceneController()
	{
		UClass* Class = AGrissburgSceneController::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "SetupLevel", (Native)&AGrissburgSceneController::execSetupLevel },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 1);
	}
	UFunction* Z_Construct_UFunction_AGrissburgSceneController_SetupLevel()
	{
		UObject* Outer=Z_Construct_UClass_AGrissburgSceneController();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SetupLevel"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Functions"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("GrissburgSceneController.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGrissburgSceneController_NoRegister()
	{
		return AGrissburgSceneController::StaticClass();
	}
	UClass* Z_Construct_UClass_AGrissburgSceneController()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ASceneController();
			Z_Construct_UPackage__Script_Project16();
			OuterClass = AGrissburgSceneController::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_AGrissburgSceneController_SetupLevel());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AGrissburgSceneController_SetupLevel(), "SetupLevel"); // 3519455124
				static TCppClassTypeInfo<TCppClassTypeTraits<AGrissburgSceneController> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("GrissburgSceneController.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("GrissburgSceneController.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGrissburgSceneController, 1363378475);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGrissburgSceneController(Z_Construct_UClass_AGrissburgSceneController, &AGrissburgSceneController::StaticClass, TEXT("/Script/Project16"), TEXT("AGrissburgSceneController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGrissburgSceneController);
	void ASpawnLevel1::StaticRegisterNativesASpawnLevel1()
	{
	}
	UClass* Z_Construct_UClass_ASpawnLevel1_NoRegister()
	{
		return ASpawnLevel1::StaticClass();
	}
	UClass* Z_Construct_UClass_ASpawnLevel1()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_Project16();
			OuterClass = ASpawnLevel1::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_controller = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("controller"), RF_Public|RF_Transient|RF_MarkAsNative) UClassProperty(CPP_PROPERTY_BASE(controller, ASpawnLevel1), 0x0010000000000005, Z_Construct_UClass_UObject_NoRegister(), UClass::StaticClass());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				static TCppClassTypeInfo<TCppClassTypeTraits<ASpawnLevel1> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SpawnLevel1.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("SpawnLevel1.h"));
				MetaData->SetValue(NewProp_controller, TEXT("Category"), TEXT("SceneController"));
				MetaData->SetValue(NewProp_controller, TEXT("ModuleRelativePath"), TEXT("SpawnLevel1.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASpawnLevel1, 1320988679);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpawnLevel1(Z_Construct_UClass_ASpawnLevel1, &ASpawnLevel1::StaticClass, TEXT("/Script/Project16"), TEXT("ASpawnLevel1"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpawnLevel1);
	UPackage* Z_Construct_UPackage__Script_Project16()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/Project16")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0xB1D84F06;
			Guid.B = 0x8C01595E;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
