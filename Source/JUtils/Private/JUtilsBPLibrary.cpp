// Copyright Epic Games, Inc. All Rights Reserved.

#include "JUtilsBPLibrary.h"
#include "JUtils.h"

#include "Kismet/GameplayStatics.h"

UJUtilsBPLibrary::UJUtilsBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

EPlatform UJUtilsBPLibrary::GetPlatform()
{
	FString platformName = UGameplayStatics::GetPlatformName();
	return EPlatform::WINDOWS;
}

