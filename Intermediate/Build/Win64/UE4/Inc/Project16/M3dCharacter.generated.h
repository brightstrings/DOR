// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECT16_M3dCharacter_generated_h
#error "M3dCharacter.generated.h already included, missing '#pragma once' in M3dCharacter.h"
#endif
#define PROJECT16_M3dCharacter_generated_h

#define Project16_Source_Project16_M3dCharacter_h_69_RPC_WRAPPERS
#define Project16_Source_Project16_M3dCharacter_h_69_RPC_WRAPPERS_NO_PURE_DECLS
#define Project16_Source_Project16_M3dCharacter_h_69_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUM3dCharacter(); \
	friend PROJECT16_API class UClass* Z_Construct_UClass_UM3dCharacter(); \
public: \
	DECLARE_CLASS(UM3dCharacter, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Project16"), NO_API) \
	DECLARE_SERIALIZER(UM3dCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project16_Source_Project16_M3dCharacter_h_69_INCLASS \
private: \
	static void StaticRegisterNativesUM3dCharacter(); \
	friend PROJECT16_API class UClass* Z_Construct_UClass_UM3dCharacter(); \
public: \
	DECLARE_CLASS(UM3dCharacter, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Project16"), NO_API) \
	DECLARE_SERIALIZER(UM3dCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project16_Source_Project16_M3dCharacter_h_69_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UM3dCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UM3dCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UM3dCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UM3dCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UM3dCharacter(UM3dCharacter&&); \
	NO_API UM3dCharacter(const UM3dCharacter&); \
public:


#define Project16_Source_Project16_M3dCharacter_h_69_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UM3dCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UM3dCharacter(UM3dCharacter&&); \
	NO_API UM3dCharacter(const UM3dCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UM3dCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UM3dCharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UM3dCharacter)


#define Project16_Source_Project16_M3dCharacter_h_69_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MatInst() { return STRUCT_OFFSET(UM3dCharacter, MatInst); } \
	FORCEINLINE static uint32 __PPO__MatInstHead() { return STRUCT_OFFSET(UM3dCharacter, MatInstHead); } \
	FORCEINLINE static uint32 __PPO__MatInstNeck() { return STRUCT_OFFSET(UM3dCharacter, MatInstNeck); }


#define Project16_Source_Project16_M3dCharacter_h_65_PROLOG
#define Project16_Source_Project16_M3dCharacter_h_69_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project16_Source_Project16_M3dCharacter_h_69_PRIVATE_PROPERTY_OFFSET \
	Project16_Source_Project16_M3dCharacter_h_69_RPC_WRAPPERS \
	Project16_Source_Project16_M3dCharacter_h_69_INCLASS \
	Project16_Source_Project16_M3dCharacter_h_69_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project16_Source_Project16_M3dCharacter_h_69_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project16_Source_Project16_M3dCharacter_h_69_PRIVATE_PROPERTY_OFFSET \
	Project16_Source_Project16_M3dCharacter_h_69_RPC_WRAPPERS_NO_PURE_DECLS \
	Project16_Source_Project16_M3dCharacter_h_69_INCLASS_NO_PURE_DECLS \
	Project16_Source_Project16_M3dCharacter_h_69_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class M3dCharacter."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project16_Source_Project16_M3dCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
