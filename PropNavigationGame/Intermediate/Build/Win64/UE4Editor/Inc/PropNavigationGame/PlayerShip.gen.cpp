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
	PROPNAVIGATIONGAME_API UFunction* Z_Construct_UFunction_APlayerShip_GetImpulseSpeed();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_APlayerShip();
	PROPNAVIGATIONGAME_API UFunction* Z_Construct_UFunction_APlayerShip_GetTargetHealthStrength();
	PROPNAVIGATIONGAME_API UFunction* Z_Construct_UFunction_APlayerShip_GetTargetName();
	PROPNAVIGATIONGAME_API UFunction* Z_Construct_UFunction_APlayerShip_GetTargetShieldStrength();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_APlayerShip_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_PropNavigationGame();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	PROPNAVIGATIONGAME_API UClass* Z_Construct_UClass_UPhaserComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	void APlayerShip::StaticRegisterNativesAPlayerShip()
	{
		UClass* Class = APlayerShip::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "GetImpulseSpeed", (Native)&APlayerShip::execGetImpulseSpeed },
			{ "GetTargetHealthStrength", (Native)&APlayerShip::execGetTargetHealthStrength },
			{ "GetTargetName", (Native)&APlayerShip::execGetTargetName },
			{ "GetTargetShieldStrength", (Native)&APlayerShip::execGetTargetShieldStrength },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_APlayerShip_GetImpulseSpeed()
	{
		struct PlayerShip_eventGetImpulseSpeed_Parms
		{
			FName ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_APlayerShip();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetImpulseSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x14020401, 65535, sizeof(PlayerShip_eventGetImpulseSpeed_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UNameProperty(CPP_PROPERTY_BASE(ReturnValue, PlayerShip_eventGetImpulseSpeed_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Target functions"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_APlayerShip_GetTargetHealthStrength()
	{
		struct PlayerShip_eventGetTargetHealthStrength_Parms
		{
			int32 ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_APlayerShip();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetTargetHealthStrength"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x14020401, 65535, sizeof(PlayerShip_eventGetTargetHealthStrength_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(ReturnValue, PlayerShip_eventGetTargetHealthStrength_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Target functions"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_APlayerShip_GetTargetName()
	{
		struct PlayerShip_eventGetTargetName_Parms
		{
			FName ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_APlayerShip();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetTargetName"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x14020401, 65535, sizeof(PlayerShip_eventGetTargetName_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UNameProperty(CPP_PROPERTY_BASE(ReturnValue, PlayerShip_eventGetTargetName_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Target functions"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_APlayerShip_GetTargetShieldStrength()
	{
		struct PlayerShip_eventGetTargetShieldStrength_Parms
		{
			int32 ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_APlayerShip();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetTargetShieldStrength"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x14020401, 65535, sizeof(PlayerShip_eventGetTargetShieldStrength_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(ReturnValue, PlayerShip_eventGetTargetShieldStrength_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Target functions"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
#endif
		}
		return ReturnFunction;
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

				OuterClass->LinkChild(Z_Construct_UFunction_APlayerShip_GetImpulseSpeed());
				OuterClass->LinkChild(Z_Construct_UFunction_APlayerShip_GetTargetHealthStrength());
				OuterClass->LinkChild(Z_Construct_UFunction_APlayerShip_GetTargetName());
				OuterClass->LinkChild(Z_Construct_UFunction_APlayerShip_GetTargetShieldStrength());

				UProperty* NewProp_mesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("mesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(mesh, APlayerShip), 0x0010000000080009, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_skeleMesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("skeleMesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(skeleMesh, APlayerShip), 0x0010000000080009, Z_Construct_UClass_USkeletalMeshComponent_NoRegister());
				UProperty* NewProp_phaserComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("phaserComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(phaserComponent, APlayerShip), 0x0010008000000009);
				UProperty* NewProp_phaserComponent_Inner = new(EC_InternalUseOnlyConstructor, NewProp_phaserComponent, TEXT("phaserComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000080008, Z_Construct_UClass_UPhaserComponent_NoRegister());
				UProperty* NewProp_springArm = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("springArm"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(springArm, APlayerShip), 0x0010000000080009, Z_Construct_UClass_USpringArmComponent_NoRegister());
				UProperty* NewProp_zoomSensitivity = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("zoomSensitivity"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(zoomSensitivity, APlayerShip), 0x0010000000000001);
				UProperty* NewProp_maxCameraZoom = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("maxCameraZoom"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(maxCameraZoom, APlayerShip), 0x0010000000000001);
				UProperty* NewProp_minCameraZoom = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("minCameraZoom"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(minCameraZoom, APlayerShip), 0x0010000000000001);
				UProperty* NewProp_maxTurningSpeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("maxTurningSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(maxTurningSpeed, APlayerShip), 0x0010000000000001);
				UProperty* NewProp_maxForwardSpeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("maxForwardSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(maxForwardSpeed, APlayerShip), 0x0010000000000001);
				UProperty* NewProp_maxTurningAngle = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("maxTurningAngle"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(maxTurningAngle, APlayerShip), 0x0010000000000001);
				UProperty* NewProp_timeBetweenShots = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("timeBetweenShots"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(timeBetweenShots, APlayerShip), 0x0010000000000001);
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_APlayerShip_GetImpulseSpeed(), "GetImpulseSpeed"); // 3588433959
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_APlayerShip_GetTargetHealthStrength(), "GetTargetHealthStrength"); // 2279389958
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_APlayerShip_GetTargetName(), "GetTargetName"); // 1661370068
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_APlayerShip_GetTargetShieldStrength(), "GetTargetShieldStrength"); // 175059321
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
				MetaData->SetValue(NewProp_skeleMesh, TEXT("Category"), TEXT("PlayerShip"));
				MetaData->SetValue(NewProp_skeleMesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_skeleMesh, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(NewProp_phaserComponent, TEXT("Category"), TEXT("PlayerShip"));
				MetaData->SetValue(NewProp_phaserComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_phaserComponent, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(NewProp_springArm, TEXT("Category"), TEXT("PlayerShip"));
				MetaData->SetValue(NewProp_springArm, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_springArm, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(NewProp_zoomSensitivity, TEXT("Category"), TEXT("Camera|Zoom"));
				MetaData->SetValue(NewProp_zoomSensitivity, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(NewProp_maxCameraZoom, TEXT("Category"), TEXT("Camera|Zoom"));
				MetaData->SetValue(NewProp_maxCameraZoom, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(NewProp_minCameraZoom, TEXT("Category"), TEXT("Camera|Zoom"));
				MetaData->SetValue(NewProp_minCameraZoom, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
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
	IMPLEMENT_CLASS(APlayerShip, 217826836);
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlayerShip(Z_Construct_UClass_APlayerShip, &APlayerShip::StaticClass, TEXT("/Script/PropNavigationGame"), TEXT("APlayerShip"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerShip);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
