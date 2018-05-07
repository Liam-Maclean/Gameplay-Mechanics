// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "BaseWeaponComponent.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseWeaponComponent() {}
// Cross Module References
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UBaseWeaponComponent_NoRegister();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UBaseWeaponComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_PropNavigationGame();
// End Cross Module References
	void UBaseWeaponComponent::StaticRegisterNativesUBaseWeaponComponent()
	{
	}
	UClass* Z_Construct_UClass_UBaseWeaponComponent_NoRegister()
	{
		return UBaseWeaponComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UBaseWeaponComponent()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UActorComponent();
			Z_Construct_UPackage__Script_PropNavigationGame();
			OuterClass = UBaseWeaponComponent::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20B00080u;


				static TCppClassTypeInfo<TCppClassTypeTraits<UBaseWeaponComponent> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Custom"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BaseWeaponComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("BaseWeaponComponent.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBaseWeaponComponent, 2581038920);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBaseWeaponComponent(Z_Construct_UClass_UBaseWeaponComponent, &UBaseWeaponComponent::StaticClass, TEXT("/Script/PropNavigationGame"), TEXT("UBaseWeaponComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBaseWeaponComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
