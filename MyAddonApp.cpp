#include "MyAddonApp.h"
#include "ShowWindow.h"

#include <InterfaceKit.h>
#include <SupportKit.h>

class MyAddonAppWindow : public BWindow {
public:
	MyAddonAppWindow();
	virtual bool QuitRequested()
	{
		be_app->PostMessage(B_QUIT_REQUESTED);
		return true;
	}
};


MyAddonAppWindow::MyAddonAppWindow()
	:
	BWindow(BRect(100,100,300,300),
		"MyAddon", B_TITLED_WINDOW, 0)
{
	BTextView *view = new BTextView(BRect(0,0,200,200), "view",
		BRect(0,0,200,200), B_FOLLOW_ALL_SIDES, B_WILL_DRAW |
		B_FULL_UPDATE_ON_RESIZE);
	view->SetText("Hello World!!!");
	view->MakeEditable(false);
	AddChild(view);

	CenterOnScreen();
	Show();
}


MyAddonApp::MyAddonApp()
	: 
	BApplication("application/x-vnd.haiku-myaddon")
{
}


void
MyAddonApp::MessageReceived(BMessage* msg)
{
	int32 itemId;
	MyAddonAppWindow* window;

	if (msg->FindInt32("addon_item_id", &itemId) != B_OK)
			return;

	switch (itemId) {
		case kShowWindow:
			if (!windowMap[kShowWindow])
				windowMap[kShowWindow] = new MyAddonAppWindow();
			windowMap[kShowWindow]->Activate(true);
			break;
		default:
			break;
	}
}
