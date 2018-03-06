// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "PhaserComponent.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePhaserComponent() {}
// Cross Module References
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UPhaserComponent_NoRegister();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UPhaserComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_PropNavigationGame();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
// End Cross Module References
	void UPhaserComponent::StaticRegisterNativesUPhaserComponent()
	{
	}
	UClass* Z_Construct_UClass_UPhaserComponent_NoRegister()
	{
		return UPhaserComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UPhaserComponent()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UActorComponent();
			Z_Construct_UPackage__Script_PropNavigationGame();
			OuterClass = UPhaserComponent::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20B00080u;


				UProperty* NewProp_phaserEffect = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("phaserEffect"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(phaserEffect, UPhaserComponent), 0x0010000000080009, Z_Construct_UClass_UParticleSystemComponent_NoRegister());
				static TCppClassTypeInfo<TCppClassTypeTraits<UPhaserComponent> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Custom"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("PhaserComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("PhaserComponent.h"));
				MetaData->SetValue(NewProp_phaserEffect, TEXT("Category"), TEXT("PhaserComponent"));
				MetaData->SetValue(NewProp_phaserEffect, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_phaserEffect, TEXT("ModuleRelativePath"), TEXT("PhaserComponent.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPhaserComponent, 2195510267);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPhaserComponent(Z_Construct_UClass_UPhaserComponent, &UPhaserComponent::StaticClass, TEXT("/Script/PropNavigationGame"), TEXT("UPhaserComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPhaserComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
