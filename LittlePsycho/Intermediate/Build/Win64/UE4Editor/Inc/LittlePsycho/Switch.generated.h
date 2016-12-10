// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LITTLEPSYCHO_Switch_generated_h
#error "Switch.generated.h already included, missing '#pragma once' in Switch.h"
#endif
#define LITTLEPSYCHO_Switch_generated_h

#define LittlePsycho_Source_LittlePsycho_Switch_h_9_RPC_WRAPPERS
#define LittlePsycho_Source_LittlePsycho_Switch_h_9_RPC_WRAPPERS_NO_PURE_DECLS
#define LittlePsycho_Source_LittlePsycho_Switch_h_9_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesASwitch(); \
	friend LITTLEPSYCHO_API class UClass* Z_Construct_UClass_ASwitch(); \
	public: \
	DECLARE_CLASS(ASwitch, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LittlePsycho"), NO_API) \
	DECLARE_SERIALIZER(ASwitch) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LittlePsycho_Source_LittlePsycho_Switch_h_9_INCLASS \
	private: \
	static void StaticRegisterNativesASwitch(); \
	friend LITTLEPSYCHO_API class UClass* Z_Construct_UClass_ASwitch(); \
	public: \
	DECLARE_CLASS(ASwitch, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LittlePsycho"), NO_API) \
	DECLARE_SERIALIZER(ASwitch) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LittlePsycho_Source_LittlePsycho_Switch_h_9_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASwitch(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASwitch) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASwitch); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASwitch); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASwitch(ASwitch&&); \
	NO_API ASwitch(const ASwitch&); \
public:


#define LittlePsycho_Source_LittlePsycho_Switch_h_9_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASwitch(ASwitch&&); \
	NO_API ASwitch(const ASwitch&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASwitch); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASwitch); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASwitch)


#define LittlePsycho_Source_LittlePsycho_Switch_h_6_PROLOG
#define LittlePsycho_Source_LittlePsycho_Switch_h_9_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LittlePsycho_Source_LittlePsycho_Switch_h_9_RPC_WRAPPERS \
	LittlePsycho_Source_LittlePsycho_Switch_h_9_INCLASS \
	LittlePsycho_Source_LittlePsycho_Switch_h_9_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LittlePsycho_Source_LittlePsycho_Switch_h_9_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LittlePsycho_Source_LittlePsycho_Switch_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
	LittlePsycho_Source_LittlePsycho_Switch_h_9_INCLASS_NO_PURE_DECLS \
	LittlePsycho_Source_LittlePsycho_Switch_h_9_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LittlePsycho_Source_LittlePsycho_Switch_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
