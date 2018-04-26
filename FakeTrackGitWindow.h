#ifndef _FAKE_TRAKGIT_WINDOW_H_
#define _FAKE_TRAKGIT_WINDOW_H_

#include <AppKit.h>
#include <InterfaceKit.h>
#include <StorageKit.h>
#include <Window.h>

#include "TrackGit.h"

class FakeTrackGitWindow : public BWindow {
	entry_ref dir_ref;
	BMessage *msg;
public:
	FakeTrackGitWindow(entry_ref dir_ref, BMessage *msg);
	virtual void MessageReceived(BMessage*);
	        void SetTargetOf(BMenu*);
	        void SetTargetOf(BMenuItem*);
};

#endif
