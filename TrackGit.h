#ifndef _TRACKGIT_H
#define _TRACKGIT_H

#include <AppKit.h>
#include <InterfaceKit.h>
#include <StorageKit.h>

const uint32 kShowWindow = 'swnd';

void
show_window (entry_ref dir_ref, BMessage *msg);

#endif
