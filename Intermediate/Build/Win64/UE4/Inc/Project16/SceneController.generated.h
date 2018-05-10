// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECT16_SceneController_generated_h
#error "SceneController.generated.h already included, missing '#pragma once' in SceneController.h"
#endif
#define PROJECT16_SceneController_generated_h

#define Project16_Source_Project16_SceneController_h_95_GENERATED_BODY \
	friend PROJECT16_API class UScriptStruct* Z_Construct_UScriptStruct_FPortrait(); \
	PROJECT16_API static class UScriptStruct* StaticStruct();


#define Project16_Source_Project16_SceneController_h_213_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLeftMousePressed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LeftMousePressed(); \
		P_NATIVE_END; \
	}


#define Project16_Source_Project16_SceneController_h_213_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLeftMousePressed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LeftMousePressed(); \
		P_NATIVE_END; \
	}


#define Project16_Source_Project16_SceneController_h_213_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASceneController(); \
	friend PROJECT16_API class UClass* Z_Construct_UClass_ASceneController(); \
public: \
	DECLARE_CLASS(ASceneController, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Project16"), NO_API) \
	DECLARE_SERIALIZER(ASceneController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project16_Source_Project16_SceneController_h_213_INCLASS \
private: \
	static void StaticRegisterNativesASceneController(); \
	friend PROJECT16_API class UClass* Z_Construct_UClass_ASceneController(); \
public: \
	DECLARE_CLASS(ASceneController, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Project16"), NO_API) \
	DECLARE_SERIALIZER(ASceneController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project16_Source_Project16_SceneController_h_213_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASceneController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASceneController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASceneController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASceneController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASceneController(ASceneController&&); \
	NO_API ASceneController(const ASceneController&); \
public:


#define Project16_Source_Project16_SceneController_h_213_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASceneController(ASceneController&&); \
	NO_API ASceneController(const ASceneController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASceneController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASceneController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASceneController)


#define Project16_Source_Project16_SceneController_h_213_PRIVATE_PROPERTY_OFFSET
#define Project16_Source_Project16_SceneController_h_210_PROLOG
#define Project16_Source_Project16_SceneController_h_213_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project16_Source_Project16_SceneController_h_213_PRIVATE_PROPERTY_OFFSET \
	Project16_Source_Project16_SceneController_h_213_RPC_WRAPPERS \
	Project16_Source_Project16_SceneController_h_213_INCLASS \
	Project16_Source_Project16_SceneController_h_213_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project16_Source_Project16_SceneController_h_213_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project16_Source_Project16_SceneController_h_213_PRIVATE_PROPERTY_OFFSET \
	Project16_Source_Project16_SceneController_h_213_RPC_WRAPPERS_NO_PURE_DECLS \
	Project16_Source_Project16_SceneController_h_213_INCLASS_NO_PURE_DECLS \
	Project16_Source_Project16_SceneController_h_213_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project16_Source_Project16_SceneController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
