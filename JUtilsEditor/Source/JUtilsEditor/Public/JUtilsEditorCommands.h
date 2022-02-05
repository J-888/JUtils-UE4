// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "JUtilsEditorStyle.h"

class FJUtilsEditorCommands : public TCommands<FJUtilsEditorCommands>
{
public:

	FJUtilsEditorCommands()
		: TCommands<FJUtilsEditorCommands>(TEXT("JUtilsEditor"), NSLOCTEXT("Contexts", "JUtilsEditor", "JUtilsEditor Plugin"), NAME_None, FJUtilsEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
