// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "EnemyShip.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyShip() {}
// Cross Module References
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_AEnemyShip_NoRegister();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_AEnemyShip();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_PropNavigationGame();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UHealthComponent_NoRegister();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UShieldComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AEnemyShip::StaticRegisterNativesAEnemyShip()
	{
	}
	UClass* Z_Construct_UClass_AEnemyShip_NoRegister()
	{
		return AEnemyShip::StaticClass();
	}
	UClass* Z_Construct_UClass_AEnemyShip()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_PropNavigationGame();
			OuterClass = AEnemyShip::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				UProperty* NewProp_healthComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("healthComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(healthComponent, AEnemyShip), 0x0010000000080009, Z_Construct_UClass_UHealthComponent_NoRegister());
				UProperty* NewProp_shieldComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("shieldComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(shieldComponent, AEnemyShip), 0x0010000000080009, Z_Construct_UClass_UShieldComponent_NoRegister());
				UProperty* NewProp_staticMesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("staticMesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(staticMesh, AEnemyShip), 0x0010000000080009, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				static TCppClassTypeInfo<TCppClassTypeTraits<AEnemyShip> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("EnemyShip.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("EnemyShip.h"));
				MetaData->SetValue(NewProp_healthComponent, TEXT("Category"), TEXT("EnemyShip"));
				MetaData->SetValue(NewProp_healthComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_healthComponent, TEXT("ModuleRelativePath"), TEXT("EnemyShip.h"));
				MetaData->SetValue(NewProp_shieldComponent, TEXT("Category"), TEXT("EnemyShip"));
				MetaData->SetValue(NewProp_shieldComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_shieldComponent, TEXT("ModuleRelativePath"), TEXT("EnemyShip.h"));
				MetaData->SetValue(NewProp_staticMesh, TEXT("Category"), TEXT("EnemyShip"));
				MetaData->SetValue(NewProp_staticMesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_staticMesh, TEXT("ModuleRelativePath"), TEXT("EnemyShip.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyShip, 1373190878);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyShip(Z_Construct_UClass_AEnemyShip, &AEnemyShip::StaticClass, TEXT("/Script/PropNavigationGame"), TEXT("AEnemyShip"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyShip);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
