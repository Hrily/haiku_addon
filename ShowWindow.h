#ifndef _SHOW_WINDOW_H
#define _SHOW_WINDOW_H

#include <AppKit.h>
#include <InterfaceKit.h>
#include <StorageKit.h>

const uint32 kShowWindow = 'swnd';

void
show_window (BMessage *msg);

#endif
