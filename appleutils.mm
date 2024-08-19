#ifdef VK_USE_PLATFORM_METAL_EXT

#import <Foundation/Foundation.h>
#import <QuartzCore/CAMetalLayer.h>
#include <TargetConditionals.h>

#if TARGET_OS_IPHONE
#include <UIKit/UIView.h>
#else
#import <AppKit/AppKit.h>
#endif

#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>

extern "C" void setWorkingFolderForiOS(void)
{
    // On iOS, only the document directory for the app can be read/written from.
    // This function just sets that as the current working folder.
    NSArray *docPath = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *myPath = [docPath objectAtIndex:0];
    chdir( [myPath UTF8String]);
}

extern "C" const char *getWorkingFolderForiOS(void)
{
    static char cWorkingFolder[512];
    NSArray *docPath = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *myPath = [docPath objectAtIndex:0];
    strncpy(cWorkingFolder, [myPath UTF8String], 512);

    return cWorkingFolder;
}


extern "C" void *makeViewMetalCompatible(void* handle)
{
#if TARGET_OS_IPHONE
    UIView* view = (__bridge UIView*)handle;
    assert([view isKindOfClass:[UIView class]]);

    void *pLayer =(__bridge void*)view.layer;
    return pLayer;
#else
    NSView* view = (__bridge NSView*)handle;
    assert([view isKindOfClass:[NSView class]]);

    void *pLayer = (__bridge void *)view.layer;
    return pLayer;
#endif
}

#endif
