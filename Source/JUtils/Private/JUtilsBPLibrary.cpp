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
#if PLATFORM_WINDOWS
	return EPlatform::WINDOWS;
#elif PLATFORM_XBOXONE
	// TODO
#elif PLATFORM_MAC
	return EPlatform::MAC;
#elif PLATFORM_PS4
	// TODO
#elif PLATFORM_IOS
	return EPlatform::IOS;
#elif PLATFORM_TVOS
	return EPlatform::TVOS;
#elif PLATFORM_ANDROID
	return EPlatform::ANDROID;
#elif PLATFORM_ANDROID_ARM
	return EPlatform::ANDROID;
#elif PLATFORM_ANDROID_ARM64
	return EPlatform::ANDROID;
#elif PLATFORM_ANDROID_X86
	return EPlatform::ANDROID;
#elif PLATFORM_ANDROID_X64
	return EPlatform::ANDROID;
#elif PLATFORM_ANDROID_VULKAN
	return EPlatform::ANDROID;
#elif PLATFORM_ANDROIDGL4
	return EPlatform::ANDROID;
#elif PLATFORM_LUMINGL4
	return EPlatform::LUMIN;
#elif PLATFORM_LUMIN
	return EPlatform::LUMIN;
#elif PLATFORM_APPLE
	// TODO
#elif PLATFORM_LINUX
	return EPlatform::LINUX;
#elif PLATFORM_LINUXAARCH64
	return EPlatform::LINUXAARCH64;
#elif PLATFORM_SWITCH
	// TODO
#elif PLATFORM_FREEBSD
	// TODO
#elif PLATFORM_UNIX
	// TODO
#elif PLATFORM_MICROSOFT
	// TODO
#elif PLATFORM_HOLOLENS
	return EPlatform::HOLOLENS;
#endif
	return EPlatform::NONE;
}

