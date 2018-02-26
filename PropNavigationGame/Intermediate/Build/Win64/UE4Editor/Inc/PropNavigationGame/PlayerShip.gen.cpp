// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "PlayerShip.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerShip() {}
// Cross Module References
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_APlayerShip_NoRegister();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_APlayerShip();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_PropNavigationGame();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	void APlayerShip::StaticRegisterNativesAPlayerShip()
	{
	}
	UClass* Z_Construct_UClass_APlayerShip_NoRegister()
	{
		return APlayerShip::StaticClass();
	}
	UClass* Z_Construct_UClass_APlayerShip()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APawn();
			Z_Construct_UPackage__Script_PropNavigationGame();
			OuterClass = APlayerShip::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				UProperty* NewProp_mesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("mesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(mesh, APlayerShip), 0x0010000000080009, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_springArm = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("springArm"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(springArm, APlayerShip), 0x0010000000080009, Z_Construct_UClass_USpringArmComponent_NoRegister());
				UProperty* NewProp_maxTurningSpeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("maxTurningSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(maxTurningSpeed, APlayerShip), 0x0010000000000001);
				UProperty* NewProp_maxForwardSpeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("maxForwardSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(maxForwardSpeed, APlayerShip), 0x0010000000000001);
				UProperty* NewProp_maxTurningAngle = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("maxTurningAngle"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(maxTurningAngle, APlayerShip), 0x0010000000000001);
				UProperty* NewProp_timeBetweenShots = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("timeBetweenShots"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(timeBetweenShots, APlayerShip), 0x0010000000000001);
				static TCppClassTypeInfo<TCppClassTypeTraits<APlayerShip> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(NewProp_mesh, TEXT("Category"), TEXT("PlayerShip"));
				MetaData->SetValue(NewProp_mesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_mesh, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(NewProp_springArm, TEXT("Category"), TEXT("PlayerShip"));
				MetaData->SetValue(NewProp_springArm, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_springArm, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(NewProp_maxTurningSpeed, TEXT("Category"), TEXT("Movement|Rotation and turning"));
				MetaData->SetValue(NewProp_maxTurningSpeed, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(NewProp_maxForwardSpeed, TEXT("Category"), TEXT("Movement|Acceleration and deceleration"));
				MetaData->SetValue(NewProp_maxForwardSpeed, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(NewProp_maxTurningAngle, TEXT("Category"), TEXT("Movement|Rotation and turning"));
				MetaData->SetValue(NewProp_maxTurningAngle, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(NewProp_timeBetweenShots, TEXT("Category"), TEXT("Shooting|Shooting Speed"));
				MetaData->SetValue(NewProp_timeBetweenShots, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlayerShip, 856020887);
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlayerShip(Z_Construct_UClass_APlayerShip, &APlayerShip::StaticClass, TEXT("/Script/PropNavigationGame"), TEXT("APlayerShip"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerShip);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
