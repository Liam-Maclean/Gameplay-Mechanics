// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ShieldComponent.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShieldComponent() {}
// Cross Module References
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UShieldComponent_NoRegister();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UShieldComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_PropNavigationGame();
// End Cross Module References
	void UShieldComponent::StaticRegisterNativesUShieldComponent()
	{
	}
	UClass* Z_Construct_UClass_UShieldComponent_NoRegister()
	{
		return UShieldComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UShieldComponent()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UActorComponent();
			Z_Construct_UPackage__Script_PropNavigationGame();
			OuterClass = UShieldComponent::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20B00080u;


				UProperty* NewProp_shieldStrength = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("shieldStrength"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(shieldStrength, UShieldComponent), 0x0010000000000001);
				static TCppClassTypeInfo<TCppClassTypeTraits<UShieldComponent> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Custom"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ShieldComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
				MetaData->SetValue(NewProp_shieldStrength, TEXT("Category"), TEXT("Shield Values"));
				MetaData->SetValue(NewProp_shieldStrength, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UShieldComponent, 1171369694);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UShieldComponent(Z_Construct_UClass_UShieldComponent, &UShieldComponent::StaticClass, TEXT("/Script/PropNavigationGame"), TEXT("UShieldComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UShieldComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
