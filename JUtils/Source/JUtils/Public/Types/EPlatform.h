// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EPlatform.generated.h"

UENUM(BlueprintType, Category = "NexPlayerUnreal|Types")
enum class EPlatform : uint8 {
	NONE = 0			UMETA(DisplayName = "None"),
	ANDROID = 1			UMETA(DisplayName = "Android"),
	HOLOLENS = 2		UMETA(DisplayName = "HoloLens"),
	LINUX = 3			UMETA(DisplayName = "Linux"),
	LINUXAARCH64 = 4	UMETA(DisplayName = "LinuxAArch64"),
	IOS = 5				UMETA(DisplayName = "IOS"),
	LUMIN = 6			UMETA(DisplayName = "Lumin"),
	MAC = 7				UMETA(DisplayName = "Mac"),
	TVOS = 8			UMETA(DisplayName = "TVOS"),
	WINDOWS = 9			UMETA(DisplayName = "Windows")
};