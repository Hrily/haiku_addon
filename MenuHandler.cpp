#include "MenuHandler.h"


MenuHandler::MenuHandler(entry_ref dir_ref, BMessage* msg)
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

void MenuHandler::MessageReceived(BMessage *msg)
{
        switch (msg->what) {
                case kShowWindow:
                        show_window(this->dir_ref, this->msg);
                        break;
                default:
                        break;
        }
}

