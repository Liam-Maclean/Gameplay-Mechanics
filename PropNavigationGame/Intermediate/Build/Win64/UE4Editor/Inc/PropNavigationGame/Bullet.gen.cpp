// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Bullet.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBullet() {}
// Cross Module References
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_ABullet_NoRegister();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_ABullet();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_PropNavigationGame();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
// End Cross Module References
	void ABullet::StaticRegisterNativesABullet()
	{
	}
	UClass* Z_Construct_UClass_ABullet_NoRegister()
	{
		return ABullet::StaticClass();
	}
	UClass* Z_Construct_UClass_ABullet()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_PropNavigationGame();
			OuterClass = ABullet::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				UProperty* NewProp_speed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("speed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(speed, ABullet), 0x0010000000000001);
				UProperty* NewProp_staticMesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("staticMesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(staticMesh, ABullet), 0x0010000000080009, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_sphereMesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("sphereMesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(sphereMesh, ABullet), 0x0010000000080009, Z_Construct_UClass_USphereComponent_NoRegister());
				static TCppClassTypeInfo<TCppClassTypeTraits<ABullet> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Bullet.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Bullet.h"));
				MetaData->SetValue(NewProp_speed, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_speed, TEXT("ModuleRelativePath"), TEXT("Bullet.h"));
				MetaData->SetValue(NewProp_staticMesh, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_staticMesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_staticMesh, TEXT("ModuleRelativePath"), TEXT("Bullet.h"));
				MetaData->SetValue(NewProp_sphereMesh, TEXT("Category"), TEXT("Bullet"));
				MetaData->SetValue(NewProp_sphereMesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_sphereMesh, TEXT("ModuleRelativePath"), TEXT("Bullet.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABullet, 3018611182);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABullet(Z_Construct_UClass_ABullet, &ABullet::StaticClass, TEXT("/Script/PropNavigationGame"), TEXT("ABullet"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABullet);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
