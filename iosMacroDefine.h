#pragma mark - Numeric define
#define NavigationBar_HEIGHT 44
#define STATUSBAR_HEIGHT 20
#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)
#define PI 3.1415926 

#define  IS_LEAP_YEAR(y)  y%4==0&&y%100!=0||y%400==0   

#pragma mark - System info
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion ([[UIDevice currentDevice] systemVersion])  
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0]) 


#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

 
#pragma mark - Localizable
#define LocalString(x, ...) NSLocalizedString(x, nil)
#define AppLanguage @"appLanguage"
#define CustomLocalizedString(key, comment) \
[[NSBundle bundleWithPath:[[NSBundle mainBundle] \
		   pathForResource:[NSString stringWithFormat:@"%@",\
		   	[[NSUserDefaults standardUserDefaults] 
		   		objectForKey:@"appLanguage"]]\
		        ofType:@"lproj"]] \
		   localizedStringForKey:(key)\
		    value:@"" table:nil]
 
 
//use dlog to print while in debug model
#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\nfunction:%s line:%d content:%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif
 
 
#define isRetinaPhone ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
 
 
#if TARGET_OS_IPHONE
//iPhone Device
#endif
 
#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif
 
 
//ARC
#if __has_feature(objc_arc)
    //compiling with ARC
#else
    // compiling without ARC
#endif
 
 
//G－C－D
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)
 
 
#define USER_DEFAULT [NSUserDefaults standardUserDefaults]
#define ImageNamed(_pointer) [UIImage imageNamed:[UIUtil imageName:_pointer]]
#define ImageFromSource(fileName,fileType) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:fileName ofType:fileType]]
#define CLEARCOLOR [UIColor clearColor]
 
#pragma mark - common functions 
#define RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }
#define SAFE_RELEASE(x) [x release];x=nil
 
 
#pragma mark - degrees/radian functions 
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)
 
#pragma mark - color functions 
#define SYS_BACKGROUND_COLOR [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
// rgb颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]


#define alertContent(title,content,ok) \
UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title \
                                                  message:content \
                                                  delegate:nil   \
                                                  cancelButtonTitle:ok \
                                                  otherButtonTitles:nil];  \
[alert show];  \
[alert release]; 

 
#define MARK    NSLog(@"\nMARK: %s, %d", __PRETTY_FUNCTION__, __LINE__)
                                             


  /*!
 * @function Singleton GCD Macro 线程安全的
 */
#ifndef SINGLETON_GCD
#define SINGLETON_GCD(classname)                        \
                                                        \
+ (classname *)shared##classname {                      \
                                                        \
    static dispatch_once_t pred;                        \
    __strong static classname * shared##classname = nil;\
    dispatch_once( &pred, ^{                            \
        shared##classname = [[self alloc] init]; });    \
    return shared##classname;                           \
}                                                           
#endif