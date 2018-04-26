#include <Alert.h>
#include <AppKit.h>
#include <InterfaceKit.h>
#include <StorageKit.h>
#include <SupportKit.h>
#include <MenuItem.h>

#include <strings.h>
#include <add-ons/tracker/TrackerAddOn.h>

extern "C" void
	populate_menu (entry_ref dir_ref, BMessage *msg, BMenu* menu);

entry_ref dir_ref;
BMessage *msg;
const uint32 kShowWindow = 'swnd';

void
show_window ()
{
	BWindow *window = new BWindow(BRect(100,100,300,300),
		"Sample Tracker Add-on", B_TITLED_WINDOW, 0);
	BTextView *view = new BTextView(BRect(0,0,200,200), "view",
		BRect(0,0,200,200), B_FOLLOW_ALL_SIDES, B_WILL_DRAW |
		B_FULL_UPDATE_ON_RESIZE);

	BPath path;
	BEntry entry(&dir_ref);
	entry.GetPath(&path);
	view->Insert("Current Directory: ");
	view->Insert(path.Path());
	view->Insert("n");

	int refs;
	entry_ref file_ref;
	for (refs=0;
		 msg->FindRef("refs", refs, &file_ref) == B_NO_ERROR;
		 refs++) {
		if (refs == 0)
		      view->Insert("Selected files:n");
		entry.SetTo(&file_ref);
		entry.GetPath(&path);
		view->Insert(path.Path());
		view->Insert("n");
	}

	if (refs == 0)
		view->Insert("No files selected.n");

	view->MakeEditable(false);
	window->AddChild(view);
	window->Show();
}


void 
process_refs (entry_ref dir_ref, BMessage *msg, void*)
{
	BString buffer("3yyHello World");
	BAlert *alert = new BAlert("", buffer.String(), "Cancel", 
			0, 0, B_WIDTH_AS_USUAL, B_WARNING_ALERT);
	alert->Go();
}

void
populate_menu (entry_ref dir_reference, BMessage *message, BMenu* menu)
{
	dir_ref = dir_reference;
	msg = message;

	BString buffer("Called");
	BAlert *alert = new BAlert("", buffer.String(), "Cancel", 
			0, 0, B_WIDTH_AS_USUAL, B_WARNING_ALERT);
	alert->Go();

	if (menu == NULL){
		BString buffer("Null menu");
		BAlert *alert = new BAlert("", buffer.String(), "Cancel", 
				0, 0, B_WIDTH_AS_USUAL, B_WARNING_ALERT);
		alert->Go();
		return;
	}

	BMenu* submenu = new BMenu("submenu");
	BMenuItem *menuitem = new BMenuItem("hello", new BMessage(kShowWindow));
	submenu->AddItem(menuitem);

	menu->AddItem(submenu);
}

int 
main ()
{
	return 0;
}
