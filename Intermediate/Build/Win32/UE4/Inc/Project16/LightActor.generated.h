// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECT16_LightActor_generated_h
#error "LightActor.generated.h already included, missing '#pragma once' in LightActor.h"
#endif
#define PROJECT16_LightActor_generated_h

#define Project16_Source_Project16_LightActor_h_13_RPC_WRAPPERS
#define Project16_Source_Project16_LightActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define Project16_Source_Project16_LightActor_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALightActor(); \
	friend PROJECT16_API class UClass* Z_Construct_UClass_ALightActor(); \
public: \
	DECLARE_CLASS(ALightActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Project16"), NO_API) \
	DECLARE_SERIALIZER(ALightActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project16_Source_Project16_LightActor_h_13_INCLASS \
private: \
	static void StaticRegisterNativesALightActor(); \
	friend PROJECT16_API class UClass* Z_Construct_UClass_ALightActor(); \
public: \
	DECLARE_CLASS(ALightActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Project16"), NO_API) \
	DECLARE_SERIALIZER(ALightActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project16_Source_Project16_LightActor_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALightActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALightActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALightActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALightActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALightActor(ALightActor&&); \
	NO_API ALightActor(const ALightActor&); \
public:


#define Project16_Source_Project16_LightActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALightActor(ALightActor&&); \
	NO_API ALightActor(const ALightActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALightActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALightActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALightActor)


#define Project16_Source_Project16_LightActor_h_13_PRIVATE_PROPERTY_OFFSET
#define Project16_Source_Project16_LightActor_h_10_PROLOG
#define Project16_Source_Project16_LightActor_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project16_Source_Project16_LightActor_h_13_PRIVATE_PROPERTY_OFFSET \
	Project16_Source_Project16_LightActor_h_13_RPC_WRAPPERS \
	Project16_Source_Project16_LightActor_h_13_INCLASS \
	Project16_Source_Project16_LightActor_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project16_Source_Project16_LightActor_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project16_Source_Project16_LightActor_h_13_PRIVATE_PROPERTY_OFFSET \
	Project16_Source_Project16_LightActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Project16_Source_Project16_LightActor_h_13_INCLASS_NO_PURE_DECLS \
	Project16_Source_Project16_LightActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project16_Source_Project16_LightActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
