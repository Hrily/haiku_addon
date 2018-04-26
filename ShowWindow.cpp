#include "ShowWindow.h"

void
show_window (entry_ref dir_ref, BMessage *msg)
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
	view->Insert("\n");

	int refs;
	entry_ref file_ref;
	for (refs=0;
		 msg->FindRef("refs", refs, &file_ref) == B_NO_ERROR;
		 refs++) {
		if (refs == 0)
		      view->Insert("Selected files:\n");
		entry.SetTo(&file_ref);
		entry.GetPath(&path);
		view->Insert(path.Path());
		view->Insert("\n");
	}

	if (refs == 0)
		view->Insert("\nNo files selected.\n");

	view->MakeEditable(false);
	window->AddChild(view);
	window->Show();
}

