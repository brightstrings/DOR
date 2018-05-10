// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECT16_GrissburgSceneController_generated_h
#error "GrissburgSceneController.generated.h already included, missing '#pragma once' in GrissburgSceneController.h"
#endif
#define PROJECT16_GrissburgSceneController_generated_h

#define Project16_Source_Project16_GrissburgSceneController_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetupLevel) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetupLevel(); \
		P_NATIVE_END; \
	}


#define Project16_Source_Project16_GrissburgSceneController_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetupLevel) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetupLevel(); \
		P_NATIVE_END; \
	}


#define Project16_Source_Project16_GrissburgSceneController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGrissburgSceneController(); \
	friend PROJECT16_API class UClass* Z_Construct_UClass_AGrissburgSceneController(); \
public: \
	DECLARE_CLASS(AGrissburgSceneController, ASceneController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Project16"), NO_API) \
	DECLARE_SERIALIZER(AGrissburgSceneController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project16_Source_Project16_GrissburgSceneController_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAGrissburgSceneController(); \
	friend PROJECT16_API class UClass* Z_Construct_UClass_AGrissburgSceneController(); \
public: \
	DECLARE_CLASS(AGrissburgSceneController, ASceneController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Project16"), NO_API) \
	DECLARE_SERIALIZER(AGrissburgSceneController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project16_Source_Project16_GrissburgSceneController_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGrissburgSceneController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGrissburgSceneController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGrissburgSceneController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGrissburgSceneController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGrissburgSceneController(AGrissburgSceneController&&); \
	NO_API AGrissburgSceneController(const AGrissburgSceneController&); \
public:


#define Project16_Source_Project16_GrissburgSceneController_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGrissburgSceneController(AGrissburgSceneController&&); \
	NO_API AGrissburgSceneController(const AGrissburgSceneController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGrissburgSceneController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGrissburgSceneController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGrissburgSceneController)


#define Project16_Source_Project16_GrissburgSceneController_h_15_PRIVATE_PROPERTY_OFFSET
#define Project16_Source_Project16_GrissburgSceneController_h_12_PROLOG
#define Project16_Source_Project16_GrissburgSceneController_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project16_Source_Project16_GrissburgSceneController_h_15_PRIVATE_PROPERTY_OFFSET \
	Project16_Source_Project16_GrissburgSceneController_h_15_RPC_WRAPPERS \
	Project16_Source_Project16_GrissburgSceneController_h_15_INCLASS \
	Project16_Source_Project16_GrissburgSceneController_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project16_Source_Project16_GrissburgSceneController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project16_Source_Project16_GrissburgSceneController_h_15_PRIVATE_PROPERTY_OFFSET \
	Project16_Source_Project16_GrissburgSceneController_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Project16_Source_Project16_GrissburgSceneController_h_15_INCLASS_NO_PURE_DECLS \
	Project16_Source_Project16_GrissburgSceneController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project16_Source_Project16_GrissburgSceneController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
