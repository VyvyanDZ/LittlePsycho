// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "LittlePsycho.h"
#include "LittlePsycho.generated.dep.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1LittlePsycho() {}
	void ALittlePsychoGameMode::StaticRegisterNativesALittlePsychoGameMode()
	{
	}
	IMPLEMENT_CLASS(ALittlePsychoGameMode, 465030595);
	void ASwitch::StaticRegisterNativesASwitch()
	{
	}
	IMPLEMENT_CLASS(ASwitch, 3311192281);
	void ASwitchOff::StaticRegisterNativesASwitchOff()
	{
	}
	IMPLEMENT_CLASS(ASwitchOff, 1673985150);
	void ADoubleSwitch::StaticRegisterNativesADoubleSwitch()
	{
	}
	IMPLEMENT_CLASS(ADoubleSwitch, 862884140);
	void AMainCharacter::StaticRegisterNativesAMainCharacter()
	{
	}
	IMPLEMENT_CLASS(AMainCharacter, 1424150169);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AGameMode();
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_ACharacter();

	LITTLEPSYCHO_API class UClass* Z_Construct_UClass_ALittlePsychoGameMode_NoRegister();
	LITTLEPSYCHO_API class UClass* Z_Construct_UClass_ALittlePsychoGameMode();
	LITTLEPSYCHO_API class UClass* Z_Construct_UClass_ASwitch_NoRegister();
	LITTLEPSYCHO_API class UClass* Z_Construct_UClass_ASwitch();
	LITTLEPSYCHO_API class UClass* Z_Construct_UClass_ASwitchOff_NoRegister();
	LITTLEPSYCHO_API class UClass* Z_Construct_UClass_ASwitchOff();
	LITTLEPSYCHO_API class UClass* Z_Construct_UClass_ADoubleSwitch_NoRegister();
	LITTLEPSYCHO_API class UClass* Z_Construct_UClass_ADoubleSwitch();
	LITTLEPSYCHO_API class UClass* Z_Construct_UClass_AMainCharacter_NoRegister();
	LITTLEPSYCHO_API class UClass* Z_Construct_UClass_AMainCharacter();
	LITTLEPSYCHO_API class UPackage* Z_Construct_UPackage__Script_LittlePsycho();
	UClass* Z_Construct_UClass_ALittlePsychoGameMode_NoRegister()
	{
		return ALittlePsychoGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_ALittlePsychoGameMode()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameMode();
			Z_Construct_UPackage__Script_LittlePsycho();
			OuterClass = ALittlePsychoGameMode::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x2090028C;


				OuterClass->ClassConfigName = FName(TEXT("Game"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("LittlePsychoGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("LittlePsychoGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALittlePsychoGameMode(Z_Construct_UClass_ALittlePsychoGameMode, &ALittlePsychoGameMode::StaticClass, TEXT("ALittlePsychoGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALittlePsychoGameMode);
	UClass* Z_Construct_UClass_ASwitch_NoRegister()
	{
		return ASwitch::StaticClass();
	}
	UClass* Z_Construct_UClass_ASwitch()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_LittlePsycho();
			OuterClass = ASwitch::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Switch.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Switch.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASwitch(Z_Construct_UClass_ASwitch, &ASwitch::StaticClass, TEXT("ASwitch"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASwitch);
	UClass* Z_Construct_UClass_ASwitchOff_NoRegister()
	{
		return ASwitchOff::StaticClass();
	}
	UClass* Z_Construct_UClass_ASwitchOff()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ASwitch();
			Z_Construct_UPackage__Script_LittlePsycho();
			OuterClass = ASwitchOff::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_TagToBound = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TagToBound"), RF_Public|RF_Transient|RF_MarkAsNative) UNameProperty(CPP_PROPERTY_BASE(TagToBound, ASwitchOff), 0x0010000000000001);
				UProperty* NewProp_SwitchLightToOff = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SwitchLightToOff"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(SwitchLightToOff, ASwitchOff), 0x0010000000080009, Z_Construct_UClass_UPointLightComponent_NoRegister());
				UProperty* NewProp_SwitchFirstLight = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SwitchFirstLight"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(SwitchFirstLight, ASwitchOff), 0x0010000000080009, Z_Construct_UClass_UPointLightComponent_NoRegister());
				UProperty* NewProp_SwitchCollision = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SwitchCollision"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(SwitchCollision, ASwitchOff), 0x0010000000080009, Z_Construct_UClass_USphereComponent_NoRegister());
				UProperty* NewProp_SwitchMesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SwitchMesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(SwitchMesh, ASwitchOff), 0x0010000000080009, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SwitchOff.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("SwitchOff.h"));
				MetaData->SetValue(NewProp_TagToBound, TEXT("Category"), TEXT("Switch - tag to bounded light"));
				MetaData->SetValue(NewProp_TagToBound, TEXT("ModuleRelativePath"), TEXT("SwitchOff.h"));
				MetaData->SetValue(NewProp_SwitchLightToOff, TEXT("Category"), TEXT("Switch - light to turn off"));
				MetaData->SetValue(NewProp_SwitchLightToOff, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_SwitchLightToOff, TEXT("ModuleRelativePath"), TEXT("SwitchOff.h"));
				MetaData->SetValue(NewProp_SwitchFirstLight, TEXT("Category"), TEXT("Switch - light to toggle"));
				MetaData->SetValue(NewProp_SwitchFirstLight, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_SwitchFirstLight, TEXT("ModuleRelativePath"), TEXT("SwitchOff.h"));
				MetaData->SetValue(NewProp_SwitchCollision, TEXT("Category"), TEXT("Switch - collision"));
				MetaData->SetValue(NewProp_SwitchCollision, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_SwitchCollision, TEXT("ModuleRelativePath"), TEXT("SwitchOff.h"));
				MetaData->SetValue(NewProp_SwitchMesh, TEXT("Category"), TEXT("Switch - mesh"));
				MetaData->SetValue(NewProp_SwitchMesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_SwitchMesh, TEXT("ModuleRelativePath"), TEXT("SwitchOff.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASwitchOff(Z_Construct_UClass_ASwitchOff, &ASwitchOff::StaticClass, TEXT("ASwitchOff"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASwitchOff);
	UClass* Z_Construct_UClass_ADoubleSwitch_NoRegister()
	{
		return ADoubleSwitch::StaticClass();
	}
	UClass* Z_Construct_UClass_ADoubleSwitch()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ASwitch();
			Z_Construct_UPackage__Script_LittlePsycho();
			OuterClass = ADoubleSwitch::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_doubleSwitchSecondLight = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("doubleSwitchSecondLight"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(doubleSwitchSecondLight, ADoubleSwitch), 0x0010000000080009, Z_Construct_UClass_UPointLightComponent_NoRegister());
				UProperty* NewProp_TagToBound = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TagToBound"), RF_Public|RF_Transient|RF_MarkAsNative) UNameProperty(CPP_PROPERTY_BASE(TagToBound, ADoubleSwitch), 0x0010000000000001);
				UProperty* NewProp_SwitchFirstLight = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SwitchFirstLight"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(SwitchFirstLight, ADoubleSwitch), 0x0010000000080009, Z_Construct_UClass_UPointLightComponent_NoRegister());
				UProperty* NewProp_SwitchCollision = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SwitchCollision"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(SwitchCollision, ADoubleSwitch), 0x0010000000080009, Z_Construct_UClass_USphereComponent_NoRegister());
				UProperty* NewProp_SwitchMesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SwitchMesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(SwitchMesh, ADoubleSwitch), 0x0010000000080009, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("DoubleSwitch.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("DoubleSwitch.h"));
				MetaData->SetValue(NewProp_doubleSwitchSecondLight, TEXT("Category"), TEXT("Switch - second light to toggle"));
				MetaData->SetValue(NewProp_doubleSwitchSecondLight, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_doubleSwitchSecondLight, TEXT("ModuleRelativePath"), TEXT("DoubleSwitch.h"));
				MetaData->SetValue(NewProp_TagToBound, TEXT("Category"), TEXT("Switch - tag to bounded light"));
				MetaData->SetValue(NewProp_TagToBound, TEXT("ModuleRelativePath"), TEXT("DoubleSwitch.h"));
				MetaData->SetValue(NewProp_SwitchFirstLight, TEXT("Category"), TEXT("Switch - light to toggle"));
				MetaData->SetValue(NewProp_SwitchFirstLight, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_SwitchFirstLight, TEXT("ModuleRelativePath"), TEXT("DoubleSwitch.h"));
				MetaData->SetValue(NewProp_SwitchCollision, TEXT("Category"), TEXT("Switch - collision"));
				MetaData->SetValue(NewProp_SwitchCollision, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_SwitchCollision, TEXT("ModuleRelativePath"), TEXT("DoubleSwitch.h"));
				MetaData->SetValue(NewProp_SwitchMesh, TEXT("Category"), TEXT("Switch - mesh"));
				MetaData->SetValue(NewProp_SwitchMesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_SwitchMesh, TEXT("ModuleRelativePath"), TEXT("DoubleSwitch.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADoubleSwitch(Z_Construct_UClass_ADoubleSwitch, &ADoubleSwitch::StaticClass, TEXT("ADoubleSwitch"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADoubleSwitch);
	UClass* Z_Construct_UClass_AMainCharacter_NoRegister()
	{
		return AMainCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_AMainCharacter()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ACharacter();
			Z_Construct_UPackage__Script_LittlePsycho();
			OuterClass = AMainCharacter::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bIsInLight, AMainCharacter, bool);
				UProperty* NewProp_bIsInLight = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bIsInLight"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bIsInLight, AMainCharacter), 0x0040000000020001, CPP_BOOL_PROPERTY_BITMASK(bIsInLight, AMainCharacter), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bCheckLightingCondition, AMainCharacter, bool);
				UProperty* NewProp_bCheckLightingCondition = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bCheckLightingCondition"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bCheckLightingCondition, AMainCharacter), 0x0040000000000001, CPP_BOOL_PROPERTY_BITMASK(bCheckLightingCondition, AMainCharacter), sizeof(bool), true);
				UProperty* NewProp_maxWalkSpeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("maxWalkSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(maxWalkSpeed, AMainCharacter), 0x0010000000000001);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("MainCharacter.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("MainCharacter.h"));
				MetaData->SetValue(NewProp_bIsInLight, TEXT("Category"), TEXT("Character"));
				MetaData->SetValue(NewProp_bIsInLight, TEXT("ModuleRelativePath"), TEXT("MainCharacter.h"));
				MetaData->SetValue(NewProp_bCheckLightingCondition, TEXT("Category"), TEXT("Character"));
				MetaData->SetValue(NewProp_bCheckLightingCondition, TEXT("ModuleRelativePath"), TEXT("MainCharacter.h"));
				MetaData->SetValue(NewProp_maxWalkSpeed, TEXT("Category"), TEXT("MainCharacter"));
				MetaData->SetValue(NewProp_maxWalkSpeed, TEXT("ModuleRelativePath"), TEXT("MainCharacter.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMainCharacter(Z_Construct_UClass_AMainCharacter, &AMainCharacter::StaticClass, TEXT("AMainCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMainCharacter);
	UPackage* Z_Construct_UPackage__Script_LittlePsycho()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/LittlePsycho")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x2268E1C6;
			Guid.B = 0xA5DC4243;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
