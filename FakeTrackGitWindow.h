#ifndef _FAKE_TRAKGIT_WINDOW_H_
#define _FAKE_TRAKGIT_WINDOW_H_

#include <AppKit.h>
#include <StorageKit.h>
#include <Window.h>

class FakeTrackGitWindow : public BWindow {
	entry_ref dir_ref;
	BMessage *msg;
public:
	FakeTrackGitWindow(entry_ref dir_ref, BMessage *msg);
	void MessageRecieved(BMessage*);
};

#endif
