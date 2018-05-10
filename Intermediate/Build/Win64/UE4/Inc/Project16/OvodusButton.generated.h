// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTexture2D;
#ifdef PROJECT16_OvodusButton_generated_h
#error "OvodusButton.generated.h already included, missing '#pragma once' in OvodusButton.h"
#endif
#define PROJECT16_OvodusButton_generated_h

#define Project16_Source_Project16_OvodusButton_h_54_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetAdvancedHitAlpha) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_InAlpha); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetAdvancedHitAlpha(Z_Param_InAlpha); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAdvancedHitTexture) \
	{ \
		P_GET_OBJECT(UTexture2D,Z_Param_InTexture); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetAdvancedHitTexture(Z_Param_InTexture); \
		P_NATIVE_END; \
	}


#define Project16_Source_Project16_OvodusButton_h_54_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetAdvancedHitAlpha) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_InAlpha); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetAdvancedHitAlpha(Z_Param_InAlpha); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetAdvancedHitTexture) \
	{ \
		P_GET_OBJECT(UTexture2D,Z_Param_InTexture); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetAdvancedHitTexture(Z_Param_InTexture); \
		P_NATIVE_END; \
	}


#define Project16_Source_Project16_OvodusButton_h_54_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOvodusButton(); \
	friend PROJECT16_API class UClass* Z_Construct_UClass_UOvodusButton(); \
public: \
	DECLARE_CLASS(UOvodusButton, UButton, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Project16"), NO_API) \
	DECLARE_SERIALIZER(UOvodusButton) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project16_Source_Project16_OvodusButton_h_54_INCLASS \
private: \
	static void StaticRegisterNativesUOvodusButton(); \
	friend PROJECT16_API class UClass* Z_Construct_UClass_UOvodusButton(); \
public: \
	DECLARE_CLASS(UOvodusButton, UButton, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Project16"), NO_API) \
	DECLARE_SERIALIZER(UOvodusButton) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project16_Source_Project16_OvodusButton_h_54_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOvodusButton(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOvodusButton) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOvodusButton); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOvodusButton); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOvodusButton(UOvodusButton&&); \
	NO_API UOvodusButton(const UOvodusButton&); \
public:


#define Project16_Source_Project16_OvodusButton_h_54_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOvodusButton(UOvodusButton&&); \
	NO_API UOvodusButton(const UOvodusButton&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOvodusButton); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOvodusButton); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOvodusButton)


#define Project16_Source_Project16_OvodusButton_h_54_PRIVATE_PROPERTY_OFFSET
#define Project16_Source_Project16_OvodusButton_h_53_PROLOG
#define Project16_Source_Project16_OvodusButton_h_54_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project16_Source_Project16_OvodusButton_h_54_PRIVATE_PROPERTY_OFFSET \
	Project16_Source_Project16_OvodusButton_h_54_RPC_WRAPPERS \
	Project16_Source_Project16_OvodusButton_h_54_INCLASS \
	Project16_Source_Project16_OvodusButton_h_54_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project16_Source_Project16_OvodusButton_h_54_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project16_Source_Project16_OvodusButton_h_54_PRIVATE_PROPERTY_OFFSET \
	Project16_Source_Project16_OvodusButton_h_54_RPC_WRAPPERS_NO_PURE_DECLS \
	Project16_Source_Project16_OvodusButton_h_54_INCLASS_NO_PURE_DECLS \
	Project16_Source_Project16_OvodusButton_h_54_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project16_Source_Project16_OvodusButton_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
