// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROPNAVIGATIONGAME_PlayerShip_generated_h
#error "PlayerShip.generated.h already included, missing '#pragma once' in PlayerShip.h"
#endif
#define PROPNAVIGATIONGAME_PlayerShip_generated_h

#define PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetImpulseSpeed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FName*)Z_Param__Result=this->GetImpulseSpeed(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTargetName) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FName*)Z_Param__Result=this->GetTargetName(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTargetHealthStrength) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetTargetHealthStrength(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTargetShieldStrength) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetTargetShieldStrength(); \
		P_NATIVE_END; \
	}


#define PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetImpulseSpeed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FName*)Z_Param__Result=this->GetImpulseSpeed(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTargetName) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FName*)Z_Param__Result=this->GetTargetName(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTargetHealthStrength) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetTargetHealthStrength(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTargetShieldStrength) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetTargetShieldStrength(); \
		P_NATIVE_END; \
	}


#define PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerShip(); \
	friend PROPNAVIGATIONGAME_API class UClass* Z_Construct_UClass_APlayerShip(); \
public: \
	DECLARE_CLASS(APlayerShip, APawn, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/PropNavigationGame"), NO_API) \
	DECLARE_SERIALIZER(APlayerShip) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerShip(); \
	friend PROPNAVIGATIONGAME_API class UClass* Z_Construct_UClass_APlayerShip(); \
public: \
	DECLARE_CLASS(APlayerShip, APawn, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/PropNavigationGame"), NO_API) \
	DECLARE_SERIALIZER(APlayerShip) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerShip(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerShip) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerShip); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerShip); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerShip(APlayerShip&&); \
	NO_API APlayerShip(const APlayerShip&); \
public:


#define PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerShip(APlayerShip&&); \
	NO_API APlayerShip(const APlayerShip&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerShip); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerShip); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerShip)


#define PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_PRIVATE_PROPERTY_OFFSET
#define PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_13_PROLOG
#define PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_PRIVATE_PROPERTY_OFFSET \
	PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_RPC_WRAPPERS \
	PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_INCLASS \
	PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_PRIVATE_PROPERTY_OFFSET \
	PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_INCLASS_NO_PURE_DECLS \
	PropNavigationGame_Source_PropNavigationGame_PlayerShip_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PropNavigationGame_Source_PropNavigationGame_PlayerShip_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
