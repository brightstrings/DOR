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
	ENGINE_API class UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	UMG_API class UClass* Z_Construct_UClass_UButton();
	ENGINE_API class UClass* Z_Construct_UClass_UTexture_NoRegister();
	UMG_API class UClass* Z_Construct_UClass_UImage_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USoundCue_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USoundBase_NoRegister();
	UMG_API class UClass* Z_Construct_UClass_UUserWidget_NoRegister();

	PROJECT16_API class UClass* Z_Construct_UClass_ALightActor_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_ALightActor();
	PROJECT16_API class UClass* Z_Construct_UClass_UM3dCharacter_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_UM3dCharacter();
	PROJECT16_API class UFunction* Z_Construct_UFunction_UOvodusButton_SetAdvancedHitAlpha();
	PROJECT16_API class UFunction* Z_Construct_UFunction_UOvodusButton_SetAdvancedHitTexture();
	PROJECT16_API class UClass* Z_Construct_UClass_UOvodusButton_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_UOvodusButton();
	PROJECT16_API class UScriptStruct* Z_Construct_UScriptStruct_FPortrait();
	PROJECT16_API class UFunction* Z_Construct_UFunction_ASceneController_LeftMousePressed();
	PROJECT16_API class UClass* Z_Construct_UClass_ASceneController_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_ASceneController();
	PROJECT16_API class UFunction* Z_Construct_UFunction_AGrissburgSceneController_SetupLevel();
	PROJECT16_API class UClass* Z_Construct_UClass_AGrissburgSceneController_NoRegister();
	PROJECT16_API class UClass* Z_Construct_UClass_AGrissburgSceneController();
	PROJECT16_API class UPackage* Z_Construct_UPackage__Script_Project16();
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
	void UOvodusButton::StaticRegisterNativesUOvodusButton()
	{
		UClass* Class = UOvodusButton::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "SetAdvancedHitAlpha", (Native)&UOvodusButton::execSetAdvancedHitAlpha },
			{ "SetAdvancedHitTexture", (Native)&UOvodusButton::execSetAdvancedHitTexture },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 2);
	}
	UFunction* Z_Construct_UFunction_UOvodusButton_SetAdvancedHitAlpha()
	{
		struct OvodusButton_eventSetAdvancedHitAlpha_Parms
		{
			int32 InAlpha;
		};
		UObject* Outer=Z_Construct_UClass_UOvodusButton();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SetAdvancedHitAlpha"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535, sizeof(OvodusButton_eventSetAdvancedHitAlpha_Parms));
			UProperty* NewProp_InAlpha = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("InAlpha"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(InAlpha, OvodusButton_eventSetAdvancedHitAlpha_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("AdvancedHitTest"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("OvodusButton.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UOvodusButton_SetAdvancedHitTexture()
	{
		struct OvodusButton_eventSetAdvancedHitTexture_Parms
		{
			UTexture2D* InTexture;
		};
		UObject* Outer=Z_Construct_UClass_UOvodusButton();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SetAdvancedHitTexture"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535, sizeof(OvodusButton_eventSetAdvancedHitTexture_Parms));
			UProperty* NewProp_InTexture = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("InTexture"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(InTexture, OvodusButton_eventSetAdvancedHitTexture_Parms), 0x0010000000000080, Z_Construct_UClass_UTexture2D_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("AdvancedHitTest"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("OvodusButton.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UOvodusButton_NoRegister()
	{
		return UOvodusButton::StaticClass();
	}
	UClass* Z_Construct_UClass_UOvodusButton()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UButton();
			Z_Construct_UPackage__Script_Project16();
			OuterClass = UOvodusButton::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20B00080;

				OuterClass->LinkChild(Z_Construct_UFunction_UOvodusButton_SetAdvancedHitAlpha());
				OuterClass->LinkChild(Z_Construct_UFunction_UOvodusButton_SetAdvancedHitTexture());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_AdvancedHitAlpha = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("AdvancedHitAlpha"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(AdvancedHitAlpha, UOvodusButton), 0x0010000000000015);
				UProperty* NewProp_AdvancedHitTexture = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("AdvancedHitTexture"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(AdvancedHitTexture, UOvodusButton), 0x0010000000000015, Z_Construct_UClass_UTexture2D_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UOvodusButton_SetAdvancedHitAlpha(), "SetAdvancedHitAlpha"); // 3829945258
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UOvodusButton_SetAdvancedHitTexture(), "SetAdvancedHitTexture"); // 977630499
				static TCppClassTypeInfo<TCppClassTypeTraits<UOvodusButton> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("OvodusButton.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("OvodusButton.h"));
				MetaData->SetValue(OuterClass, TEXT("ObjectInitializerConstructorDeclared"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("Classic UMG Button with Advanced Hit implementation.\nUse SetAdvancedHitTexture to set unique button's geometry, determined by it's alpha channel.\nUse SetAdvancedHitAlpha to set an integer in range 0-255. If pixel's alpha is lower than this value, it will be treated as an empty space."));
				MetaData->SetValue(NewProp_AdvancedHitAlpha, TEXT("Category"), TEXT("AdvancedHitTest"));
				MetaData->SetValue(NewProp_AdvancedHitAlpha, TEXT("ClampMax"), TEXT("255.0"));
				MetaData->SetValue(NewProp_AdvancedHitAlpha, TEXT("ClampMin"), TEXT("0.0"));
				MetaData->SetValue(NewProp_AdvancedHitAlpha, TEXT("ModuleRelativePath"), TEXT("OvodusButton.h"));
				MetaData->SetValue(NewProp_AdvancedHitAlpha, TEXT("UIMax"), TEXT("255.0"));
				MetaData->SetValue(NewProp_AdvancedHitAlpha, TEXT("UIMin"), TEXT("0.0"));
				MetaData->SetValue(NewProp_AdvancedHitTexture, TEXT("Category"), TEXT("AdvancedHitTest"));
				MetaData->SetValue(NewProp_AdvancedHitTexture, TEXT("ModuleRelativePath"), TEXT("OvodusButton.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UOvodusButton, 3516793015);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UOvodusButton(Z_Construct_UClass_UOvodusButton, &UOvodusButton::StaticClass, TEXT("/Script/Project16"), TEXT("UOvodusButton"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOvodusButton);
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
	UPackage* Z_Construct_UPackage__Script_Project16()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/Project16")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x2B2A0CF5;
			Guid.B = 0xB96ADF89;
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
