#ifndef _MYADDON_APP_H
#define _MYADDON_APP_H

#include <map>

#include <AppKit.h>

class MyAddonApp : public BApplication
{
	map<int, BWindow*> windowMap;
	public:
	MyAddonApp();
	virtual void MessageReceived(BMessage*);
};

#endif
