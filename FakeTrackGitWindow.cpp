#include "FakeTrackGitWindow.h"

FakeTrackGitWindow::FakeTrackGitWindow(entry_ref dir_ref, BMessage* msg)
	:
	BWindow(BRect(0, 0, 0, 0), "TrackGit", B_TITLED_WINDOW, B_NO_WORKSPACE_ACTIVATION)
{
	this->dir_ref = dir_ref;
	this->msg = msg;
}


void FakeTrackGitWindow::MessageReceived(BMessage *msg)
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
			// _inherited::MessageRecieved(msg);
			break;
	}
}


void FakeTrackGitWindow::SetTargetOf(BMenu *item)
{
	item->SetTargetForItems(this);
}

void FakeTrackGitWindow::SetTargetOf(BMenuItem *item)
{
	item->SetTarget(this);
}
