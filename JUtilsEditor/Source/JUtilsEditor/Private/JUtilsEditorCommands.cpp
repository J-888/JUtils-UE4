// Copyright Epic Games, Inc. All Rights Reserved.

#include "JUtilsEditorCommands.h"

#define LOCTEXT_NAMESPACE "FJUtilsEditorModule"

void FJUtilsEditorCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "JUtilsEditor", "Execute JUtilsEditor action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
