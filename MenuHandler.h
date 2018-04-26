#ifndef _MENU_HANDLER_H
#define _MENU_HANDLER_H

#include <Application.h>
#include <AppKit.h>
#include <StorageKit.h>

#include "ShowWindow.h"

class MenuHandler : public BHandler
{
        entry_ref dir_ref;
        BMessage *msg;
public:
                     MenuHandler(entry_ref, BMessage*);
        virtual void MessageReceived(BMessage*);
};

#endif
