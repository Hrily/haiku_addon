#include <Alert.h>
#include <Application.h>
#include <AppKit.h>
#include <InterfaceKit.h>
#include <StorageKit.h>
#include <SupportKit.h>
#include <MenuItem.h>

#include <strings.h>
#include <add-ons/tracker/TrackerAddOn.h>

#include "MenuHandler.h"

extern "C" void
	populate_menu (entry_ref dir_ref, BMessage *msg, BMenu* menu);


void 
process_refs (entry_ref dir_ref, BMessage *msg, void*)
{
	BString buffer("3yyHello World");
	BAlert *alert = new BAlert("", buffer.String(), "Cancel", 
			0, 0, B_WIDTH_AS_USUAL, B_WARNING_ALERT);
	alert->Go();
}


void
populate_menu (entry_ref dir_ref, BMessage *msg, BMenu* menu)
{
	if (menu == NULL){
		BString buffer("Null menu");
		BAlert *alert = new BAlert("", buffer.String(), "Cancel", 
				0, 0, B_WIDTH_AS_USUAL, B_WARNING_ALERT);
		alert->Go();
		return;
	}

	BMenuItem* item = menu->FindItem("submenu");
	if (item != NULL)
		menu->RemoveItem(item);

	MenuHandler *handler = new MenuHandler(dir_ref, msg);

	BMenu* submenu = new BMenu("submenu");
	BMenuItem *menuitem = new BMenuItem("hello", new BMessage(kShowWindow));
	submenu->AddItem(menuitem);
	submenu->SetTargetForItems(handler);

	menu->AddItem(submenu);
}

int 
main ()
{
	return 0;
}
