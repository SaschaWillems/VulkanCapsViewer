#ifdef VK_USE_PLATFORM_IOS_MVK
// iOS Utility Functions
#import <UIKit/UIKit.h>


extern "C" void setWorkingFolderForiOS(void)
{
    // On iOS, only the document directory for the app can be read/written from.
    // This function just sets that as the current working folder.
    NSArray *docPath = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *myPath = [docPath objectAtIndex:0];
    chdir( [myPath UTF8String]);
}

#endif
