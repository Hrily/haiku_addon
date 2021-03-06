#include <Alert.h>
#include <Application.h>
#include <AppKit.h>
#include <InterfaceKit.h>
#include <StorageKit.h>
#include <SupportKit.h>
#include <MenuItem.h>

#include <stdio.h>
#include <strings.h>
#include <add-ons/tracker/TrackerAddOn.h>

#include "ShowWindow.h"

extern "C" {
	void populate_menu (BMessage* msg, BMenu* menu, BHandler* handler);
	void message_received (BMessage* msg);
}

const char* ADDON_NAME = "MyAddOn";

void 
process_refs (entry_ref dir_ref, BMessage* msg, void*)
{
	BString buffer("Hello World");
	BAlert *alert = new BAlert("", buffer.String(), "Cancel", 
			0, 0, B_WIDTH_AS_USUAL, B_WARNING_ALERT);
	alert->Go();
}


void
populate_menu (BMessage* msg, BMenu* menu, BHandler* handler)
{
	if (menu == NULL){
		BString buffer("Null menu");
		BAlert *alert = new BAlert("", buffer.String(), "Cancel", 
				0, 0, B_WIDTH_AS_USUAL, B_WARNING_ALERT);
		alert->Go();
		return;
	}
	printf("into populate_menu\n");

	BMenuItem* item = menu->FindItem(ADDON_NAME);
	if (item != NULL)
		menu->RemoveItem(item);

	BMenu* submenu = new BMenu(ADDON_NAME);

	BMessage* itemMsg = new BMessage(*msg);
	itemMsg->AddInt32("addon_item_id", kShowWindow);
	BMenuItem *menuitem = new BMenuItem("hello", itemMsg);

	submenu->AddItem(menuitem);
	menu->AddItem(submenu);

	submenu->SetTargetForItems(handler);
}


void 
message_received (BMessage* msg)
{
	int32 itemId;
	if (msg->FindInt32("addon_item_id", &itemId) != B_OK)
		return;

	switch (itemId) {
		case kShowWindow:
			show_window(msg);
			break;
		default:
			break;
	}
}


int 
main ()
{
	return 0;
}
