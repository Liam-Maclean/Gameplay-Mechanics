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
	PROPNAVIGATIONGAME_API UFunction* Z_Construct_UFunction_UShieldComponent_GetFrontShieldStrength();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UShieldComponent();
	PROPNAVIGATIONGAME_API UFunction* Z_Construct_UFunction_UShieldComponent_GetLeftShieldStrength();
	PROPNAVIGATIONGAME_API UFunction* Z_Construct_UFunction_UShieldComponent_GetReerShieldStrength();
	PROPNAVIGATIONGAME_API UFunction* Z_Construct_UFunction_UShieldComponent_GetRightShieldStrength();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UShieldComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_PropNavigationGame();
// End Cross Module References
	void UShieldComponent::StaticRegisterNativesUShieldComponent()
	{
		UClass* Class = UShieldComponent::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "GetFrontShieldStrength", (Native)&UShieldComponent::execGetFrontShieldStrength },
			{ "GetLeftShieldStrength", (Native)&UShieldComponent::execGetLeftShieldStrength },
			{ "GetReerShieldStrength", (Native)&UShieldComponent::execGetReerShieldStrength },
			{ "GetRightShieldStrength", (Native)&UShieldComponent::execGetRightShieldStrength },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_UShieldComponent_GetFrontShieldStrength()
	{
		struct ShieldComponent_eventGetFrontShieldStrength_Parms
		{
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_UShieldComponent();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetFrontShieldStrength"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x14020401, 65535, sizeof(ShieldComponent_eventGetFrontShieldStrength_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, ShieldComponent_eventGetFrontShieldStrength_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Shield Values"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UShieldComponent_GetLeftShieldStrength()
	{
		struct ShieldComponent_eventGetLeftShieldStrength_Parms
		{
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_UShieldComponent();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetLeftShieldStrength"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x14020401, 65535, sizeof(ShieldComponent_eventGetLeftShieldStrength_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, ShieldComponent_eventGetLeftShieldStrength_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Shield Values"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UShieldComponent_GetReerShieldStrength()
	{
		struct ShieldComponent_eventGetReerShieldStrength_Parms
		{
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_UShieldComponent();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetReerShieldStrength"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x14020401, 65535, sizeof(ShieldComponent_eventGetReerShieldStrength_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, ShieldComponent_eventGetReerShieldStrength_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Shield Values"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UShieldComponent_GetRightShieldStrength()
	{
		struct ShieldComponent_eventGetRightShieldStrength_Parms
		{
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_UShieldComponent();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetRightShieldStrength"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x14020401, 65535, sizeof(ShieldComponent_eventGetRightShieldStrength_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, ShieldComponent_eventGetRightShieldStrength_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Shield Values"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
#endif
		}
		return ReturnFunction;
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

				OuterClass->LinkChild(Z_Construct_UFunction_UShieldComponent_GetFrontShieldStrength());
				OuterClass->LinkChild(Z_Construct_UFunction_UShieldComponent_GetLeftShieldStrength());
				OuterClass->LinkChild(Z_Construct_UFunction_UShieldComponent_GetReerShieldStrength());
				OuterClass->LinkChild(Z_Construct_UFunction_UShieldComponent_GetRightShieldStrength());

				UProperty* NewProp_maxShieldStrength = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("maxShieldStrength"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(maxShieldStrength, UShieldComponent), 0x0010000000000001);
				UProperty* NewProp_shieldStrength = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("shieldStrength"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(shieldStrength, UShieldComponent), 0x0010000000000001);
				UProperty* NewProp_reerShieldValue = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("reerShieldValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(reerShieldValue, UShieldComponent), 0x0010000000000001);
				UProperty* NewProp_rightShieldValue = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("rightShieldValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(rightShieldValue, UShieldComponent), 0x0010000000000001);
				UProperty* NewProp_leftShieldValue = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("leftShieldValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(leftShieldValue, UShieldComponent), 0x0010000000000001);
				UProperty* NewProp_frontShieldValue = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("frontShieldValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(frontShieldValue, UShieldComponent), 0x0010000000000001);
				UProperty* NewProp_regenInCombatP5 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("regenInCombatP5"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(regenInCombatP5, UShieldComponent), 0x0010000000000001);
				UProperty* NewProp_regenOutOfCombatP5 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("regenOutOfCombatP5"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(regenOutOfCombatP5, UShieldComponent), 0x0010000000000001);
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UShieldComponent_GetFrontShieldStrength(), "GetFrontShieldStrength"); // 3136856029
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UShieldComponent_GetLeftShieldStrength(), "GetLeftShieldStrength"); // 3665071279
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UShieldComponent_GetReerShieldStrength(), "GetReerShieldStrength"); // 995933969
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UShieldComponent_GetRightShieldStrength(), "GetRightShieldStrength"); // 695818262
				static TCppClassTypeInfo<TCppClassTypeTraits<UShieldComponent> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Custom"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ShieldComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
				MetaData->SetValue(NewProp_maxShieldStrength, TEXT("Category"), TEXT("Shield Values|Max Values"));
				MetaData->SetValue(NewProp_maxShieldStrength, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
				MetaData->SetValue(NewProp_shieldStrength, TEXT("Category"), TEXT("Shield Values|Strength"));
				MetaData->SetValue(NewProp_shieldStrength, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
				MetaData->SetValue(NewProp_shieldStrength, TEXT("ToolTip"), TEXT("Total Shield Strength"));
				MetaData->SetValue(NewProp_reerShieldValue, TEXT("Category"), TEXT("Shield Values|Strength"));
				MetaData->SetValue(NewProp_reerShieldValue, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
				MetaData->SetValue(NewProp_reerShieldValue, TEXT("ToolTip"), TEXT("directional shield values (reer)"));
				MetaData->SetValue(NewProp_rightShieldValue, TEXT("Category"), TEXT("Shield Values|Strength"));
				MetaData->SetValue(NewProp_rightShieldValue, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
				MetaData->SetValue(NewProp_rightShieldValue, TEXT("ToolTip"), TEXT("directional shield values (right)"));
				MetaData->SetValue(NewProp_leftShieldValue, TEXT("Category"), TEXT("Shield Values|Strength"));
				MetaData->SetValue(NewProp_leftShieldValue, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
				MetaData->SetValue(NewProp_leftShieldValue, TEXT("ToolTip"), TEXT("directional shield values (left)"));
				MetaData->SetValue(NewProp_frontShieldValue, TEXT("Category"), TEXT("Shield Values|Strength"));
				MetaData->SetValue(NewProp_frontShieldValue, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
				MetaData->SetValue(NewProp_frontShieldValue, TEXT("ToolTip"), TEXT("directional shield values (front)"));
				MetaData->SetValue(NewProp_regenInCombatP5, TEXT("Category"), TEXT("Shield Values|Regeneration"));
				MetaData->SetValue(NewProp_regenInCombatP5, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
				MetaData->SetValue(NewProp_regenInCombatP5, TEXT("ToolTip"), TEXT("Regen of shield in combat"));
				MetaData->SetValue(NewProp_regenOutOfCombatP5, TEXT("Category"), TEXT("Shield Values|Regeneration"));
				MetaData->SetValue(NewProp_regenOutOfCombatP5, TEXT("ModuleRelativePath"), TEXT("ShieldComponent.h"));
				MetaData->SetValue(NewProp_regenOutOfCombatP5, TEXT("ToolTip"), TEXT("Regen out of combat per second"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UShieldComponent, 3336165650);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UShieldComponent(Z_Construct_UClass_UShieldComponent, &UShieldComponent::StaticClass, TEXT("/Script/PropNavigationGame"), TEXT("UShieldComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UShieldComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
