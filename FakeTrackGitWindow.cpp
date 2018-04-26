#include "FakeTrackGitWindow.h"
#include "TrackGit.h"

FakeTrackGitWindow::FakeTrackGitWindow(entry_ref dir_ref, BMessage* msg)
	:
	BWindow(BRect(0, 0, 0, 0), "TrackGit", B_TITLED_WINDOW, B_NO_WORKSPACE_ACTIVATION)
{
	this->dir_ref = dir_ref;
	this->msg = msg;
}

void FakeTrackGitWindow::MessageRecieved(BMessage *msg)
{
	switch (msg->what) {
		case kShowWindow:
			show_window(this->dir_ref, this->msg);
			break;
		default:
			// _inherited::MessageRecieved(msg);
			break;
	}
}
