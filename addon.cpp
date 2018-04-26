#include <Alert.h>
#include <Application.h>
#include <AppKit.h>
#include <InterfaceKit.h>
#include <StorageKit.h>
#include <SupportKit.h>
#include <MenuItem.h>

#include <strings.h>
#include <add-ons/tracker/TrackerAddOn.h>

#include "FakeTrackGitWindow.h"

extern "C" void
	populate_menu (entry_ref dir_ref, BMessage *msg, BMenu* menu);

class TrackGitMenu : public BMenu {
	entry_ref dir_ref;
	BMessage *msg;
public:
	TrackGitMenu(const char *name, entry_ref dir_ref, BMessage* msg)
		:
		BMenu(name)
	{
		this->dir_ref = dir_ref;
		this->msg = msg;
		SetTargetForItems(this);
	}
	virtual void MessageReceived(BMessage*);
};

void TrackGitMenu::MessageReceived(BMessage *msg)
{
	BString buffer("Called MessageRecieved");
	BAlert *alert = new BAlert("", buffer.String(), "Cancel", 
	     0, 0, B_WIDTH_AS_USUAL, B_WARNING_ALERT);
	alert->Go();
	switch (msg->what) {
		case kShowWindow:
			show_window(this->dir_ref, this->msg);
			break;
		default:
			break;
	}
}

class TrackGitHandler : public BHandler
{
	entry_ref dir_ref;
	BMessage *msg;
public:
	             TrackGitHandler(entry_ref, BMessage*);
	virtual void MessageReceived(BMessage*);
};

TrackGitHandler::TrackGitHandler(entry_ref dir_ref, BMessage* msg)
	:
	BHandler("TrackGit")
{
	this->dir_ref = dir_ref;
	this->msg = msg;
	if (be_app->Lock()) {
		be_app->AddHandler(this);
		be_app->Unlock();
	}
}

void TrackGitHandler::MessageReceived(BMessage *msg)
{
	BString buffer("Called MessageRecieved");
	BAlert *alert = new BAlert("", buffer.String(), "Cancel", 
	     0, 0, B_WIDTH_AS_USUAL, B_WARNING_ALERT);
	alert->Go();
	switch (msg->what) {
		case kShowWindow:
			show_window(this->dir_ref, this->msg);
			break;
		default:
			break;
	}
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
populate_menu (entry_ref dir_ref, BMessage *msg, BMenu* menu)
{
	FakeTrackGitWindow *fakeWindow = new FakeTrackGitWindow(dir_ref, msg);

	// BString buffer("Called");
	// BAlert *alert = new BAlert("", buffer.String(), "Cancel", 
	// 		0, 0, B_WIDTH_AS_USUAL, B_WARNING_ALERT);
	// alert->Go();

	if (menu == NULL){
		BString buffer("Null menu");
		BAlert *alert = new BAlert("", buffer.String(), "Cancel", 
				0, 0, B_WIDTH_AS_USUAL, B_WARNING_ALERT);
		alert->Go();
		return;
	}

	// BMenu* submenu = new BMenu("submenu");
	// fakeWindow->SetTargetOf(submenu);
	// BMenuItem *menuitem = new BMenuItem("hello", new BMessage(kShowWindow));
	// submenu->AddItem(menuitem);
	// fakeWindow->SetTargetOf(submenu);
	// fakeWindow->SetTargetOf(menuitem);
	
	TrackGitHandler *handler = new TrackGitHandler(dir_ref, msg);

	TrackGitMenu* submenu = new TrackGitMenu("submenu", dir_ref, msg);
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
