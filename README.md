# haiku_addon

This repo demonstrates the usage of _Dynamic AddOn Menu_ in Tracker.

# Usage

## Compiling

```
g++ ShowWindow.cpp addon.cpp -o addon -ltracker -lbe
```

## Installing

To install just copy the executable:
```
cp addon ~/config/non-packaged/add-ons/Tracker/
```

or you can just run `run.sh` file

# How does it work?

![AddOn-Working]( https://github.com/Hrily/haiku_addon/raw/master/AddOn-Working.jpg )

## Tracker

### BContainterWindow::AddOnMenuGenerate

This function loads the addon image and calls `populate_menu` function of this addon if it has one. The parameters passed are a `BMessage`, `BMenu` pointer of the root menu of Tracker and `BHandler` to handle the message. The `BMessage` is of type `B_TRACKER_ADDON_MESSAGE`. Contents of `BMessage` are:

+ “dir_ref” : entry_ref of current directory.
+ “refs” : refs to selected files.

### BContainerWindow::MessageReceived

This function is called when user clicks on any item from addon. This function redirects the control to `_PassMessageToAddOn` which loads the addon image and calls `message_received` of addon. The parameter passed is `BMessage` which contains refs to current directory and selected items.

## Addon
### populate_menu

This function should add items to the `BMenu` pointer passed. The `BMessage` passed should be used for creating items. The necessary information should be added to `BMessage` of the item to distinguish it. This function should set target of the menu or items created as the `BHandler` passed. This should be done after adding the children.

### message_received

This function is called when user clicks on the addon item. The information added to the `BMessage` in the `populate_menu` can be used to determine the action needed to be taken.
