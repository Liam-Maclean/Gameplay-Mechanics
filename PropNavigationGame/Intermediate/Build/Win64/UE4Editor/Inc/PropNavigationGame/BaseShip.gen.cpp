// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "BaseShip.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseShip() {}
// Cross Module References
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_ABaseShip_NoRegister();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_ABaseShip();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_PropNavigationGame();
// End Cross Module References
	void ABaseShip::StaticRegisterNativesABaseShip()
	{
	}
	UClass* Z_Construct_UClass_ABaseShip_NoRegister()
	{
		return ABaseShip::StaticClass();
	}
	UClass* Z_Construct_UClass_ABaseShip()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_PropNavigationGame();
			OuterClass = ABaseShip::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				static TCppClassTypeInfo<TCppClassTypeTraits<ABaseShip> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BaseShip.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("BaseShip.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABaseShip, 625952054);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABaseShip(Z_Construct_UClass_ABaseShip, &ABaseShip::StaticClass, TEXT("/Script/PropNavigationGame"), TEXT("ABaseShip"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseShip);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
