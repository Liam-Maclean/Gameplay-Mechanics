// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "HealthComponent.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHealthComponent() {}
// Cross Module References
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UHealthComponent_NoRegister();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UHealthComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_PropNavigationGame();
// End Cross Module References
	void UHealthComponent::StaticRegisterNativesUHealthComponent()
	{
	}
	UClass* Z_Construct_UClass_UHealthComponent_NoRegister()
	{
		return UHealthComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UHealthComponent()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UActorComponent();
			Z_Construct_UPackage__Script_PropNavigationGame();
			OuterClass = UHealthComponent::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20B00080u;


				UProperty* NewProp_maxHealthStrength = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("maxHealthStrength"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(maxHealthStrength, UHealthComponent), 0x0010000000000001);
				UProperty* NewProp_healthStrength = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("healthStrength"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(healthStrength, UHealthComponent), 0x0010000000000001);
				static TCppClassTypeInfo<TCppClassTypeTraits<UHealthComponent> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Custom"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("HealthComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("HealthComponent.h"));
				MetaData->SetValue(NewProp_maxHealthStrength, TEXT("Category"), TEXT("Health stats"));
				MetaData->SetValue(NewProp_maxHealthStrength, TEXT("ModuleRelativePath"), TEXT("HealthComponent.h"));
				MetaData->SetValue(NewProp_healthStrength, TEXT("Category"), TEXT("Health stats"));
				MetaData->SetValue(NewProp_healthStrength, TEXT("ModuleRelativePath"), TEXT("HealthComponent.h"));
				MetaData->SetValue(NewProp_healthStrength, TEXT("ToolTip"), TEXT("stat"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UHealthComponent, 1040545325);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UHealthComponent(Z_Construct_UClass_UHealthComponent, &UHealthComponent::StaticClass, TEXT("/Script/PropNavigationGame"), TEXT("UHealthComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHealthComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
