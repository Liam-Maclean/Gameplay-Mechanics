// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "WeaponSlotComponent.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeaponSlotComponent() {}
// Cross Module References
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UWeaponSlotComponent_NoRegister();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UWeaponSlotComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_PropNavigationGame();
// End Cross Module References
	void UWeaponSlotComponent::StaticRegisterNativesUWeaponSlotComponent()
	{
	}
	UClass* Z_Construct_UClass_UWeaponSlotComponent_NoRegister()
	{
		return UWeaponSlotComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UWeaponSlotComponent()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UActorComponent();
			Z_Construct_UPackage__Script_PropNavigationGame();
			OuterClass = UWeaponSlotComponent::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20B00080u;


				static TCppClassTypeInfo<TCppClassTypeTraits<UWeaponSlotComponent> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Custom"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("WeaponSlotComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("WeaponSlotComponent.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWeaponSlotComponent, 3432780115);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWeaponSlotComponent(Z_Construct_UClass_UWeaponSlotComponent, &UWeaponSlotComponent::StaticClass, TEXT("/Script/PropNavigationGame"), TEXT("UWeaponSlotComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWeaponSlotComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
