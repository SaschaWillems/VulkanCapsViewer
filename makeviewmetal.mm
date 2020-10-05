#import <Cocoa/Cocoa.h>
#include <QuartzCore/CAMetalLayer.h>
static CALayer *orilayer;

extern "C" void makeViewMetalCompatible(void* handle)
{
    NSView* view = (NSView*)handle;
    assert([view isKindOfClass:[NSView class]]);
    if (![view.layer isKindOfClass:[CAMetalLayer class]])
    {
        orilayer=[view layer];
        [view setLayer:[CAMetalLayer layer]];
        //[view setWantsLayer:NO];
    }
}

extern "C" void unmakeViewMetalCompatible2(void* handle)
{
    NSView* view = (NSView*)handle;
    assert([view isKindOfClass:[NSView class]]);
    if ([view.layer isKindOfClass:[CAMetalLayer class]])
    {
        [view setLayer:orilayer];
    }
}