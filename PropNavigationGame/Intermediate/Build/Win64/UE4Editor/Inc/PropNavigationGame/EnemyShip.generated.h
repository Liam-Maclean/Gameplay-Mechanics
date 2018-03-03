// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef PROPNAVIGATIONGAME_EnemyShip_generated_h
#error "EnemyShip.generated.h already included, missing '#pragma once' in EnemyShip.h"
#endif
#define PROPNAVIGATIONGAME_EnemyShip_generated_h

#define PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemyShip(); \
	friend PROPNAVIGATIONGAME_API class UClass* Z_Construct_UClass_AEnemyShip(); \
public: \
	DECLARE_CLASS(AEnemyShip, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/PropNavigationGame"), NO_API) \
	DECLARE_SERIALIZER(AEnemyShip) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAEnemyShip(); \
	friend PROPNAVIGATIONGAME_API class UClass* Z_Construct_UClass_AEnemyShip(); \
public: \
	DECLARE_CLASS(AEnemyShip, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/PropNavigationGame"), NO_API) \
	DECLARE_SERIALIZER(AEnemyShip) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemyShip(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemyShip) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyShip); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyShip); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyShip(AEnemyShip&&); \
	NO_API AEnemyShip(const AEnemyShip&); \
public:


#define PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyShip(AEnemyShip&&); \
	NO_API AEnemyShip(const AEnemyShip&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyShip); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyShip); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemyShip)


#define PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_PRIVATE_PROPERTY_OFFSET
#define PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_12_PROLOG
#define PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_PRIVATE_PROPERTY_OFFSET \
	PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_RPC_WRAPPERS \
	PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_INCLASS \
	PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_PRIVATE_PROPERTY_OFFSET \
	PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_INCLASS_NO_PURE_DECLS \
	PropNavigationGame_Source_PropNavigationGame_EnemyShip_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PropNavigationGame_Source_PropNavigationGame_EnemyShip_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
