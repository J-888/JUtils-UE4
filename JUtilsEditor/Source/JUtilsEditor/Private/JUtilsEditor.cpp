// Copyright Epic Games, Inc. All Rights Reserved.

#include "JUtilsEditor.h"
#include "JUtilsEditorStyle.h"
#include "JUtilsEditorCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName JUtilsEditorTabName("JUtilsEditor");

#define LOCTEXT_NAMESPACE "FJUtilsEditorModule"

void FJUtilsEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FJUtilsEditorStyle::Initialize();
	FJUtilsEditorStyle::ReloadTextures();

	FJUtilsEditorCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FJUtilsEditorCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FJUtilsEditorModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FJUtilsEditorModule::RegisterMenus));
}

void FJUtilsEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FJUtilsEditorStyle::Shutdown();

	FJUtilsEditorCommands::Unregister();
}

void FJUtilsEditorModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FJUtilsEditorModule::PluginButtonClicked()")),
							FText::FromString(TEXT("JUtilsEditor.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FJUtilsEditorModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FJUtilsEditorCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FJUtilsEditorCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FJUtilsEditorModule, JUtilsEditor)