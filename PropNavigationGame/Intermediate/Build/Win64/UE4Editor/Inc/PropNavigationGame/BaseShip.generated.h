// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROPNAVIGATIONGAME_BaseShip_generated_h
#error "BaseShip.generated.h already included, missing '#pragma once' in BaseShip.h"
#endif
#define PROPNAVIGATIONGAME_BaseShip_generated_h

#define PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_RPC_WRAPPERS
#define PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABaseShip(); \
	friend PROPNAVIGATIONGAME_API class UClass* Z_Construct_UClass_ABaseShip(); \
public: \
	DECLARE_CLASS(ABaseShip, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/PropNavigationGame"), NO_API) \
	DECLARE_SERIALIZER(ABaseShip) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_INCLASS \
private: \
	static void StaticRegisterNativesABaseShip(); \
	friend PROPNAVIGATIONGAME_API class UClass* Z_Construct_UClass_ABaseShip(); \
public: \
	DECLARE_CLASS(ABaseShip, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/PropNavigationGame"), NO_API) \
	DECLARE_SERIALIZER(ABaseShip) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABaseShip(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABaseShip) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseShip); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseShip); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABaseShip(ABaseShip&&); \
	NO_API ABaseShip(const ABaseShip&); \
public:


#define PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABaseShip(ABaseShip&&); \
	NO_API ABaseShip(const ABaseShip&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseShip); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseShip); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABaseShip)


#define PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_PRIVATE_PROPERTY_OFFSET
#define PropNavigationGame_Source_PropNavigationGame_BaseShip_h_9_PROLOG
#define PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_PRIVATE_PROPERTY_OFFSET \
	PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_RPC_WRAPPERS \
	PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_INCLASS \
	PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_PRIVATE_PROPERTY_OFFSET \
	PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_INCLASS_NO_PURE_DECLS \
	PropNavigationGame_Source_PropNavigationGame_BaseShip_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PropNavigationGame_Source_PropNavigationGame_BaseShip_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
