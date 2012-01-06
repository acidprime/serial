#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>


int main (int argc, const char * argv[]) {
	CFDataRef data;
	
	io_service_t platformExpert = IOServiceGetMatchingService(kIOMasterPortDefault,
															  IOServiceMatching("IOPlatformExpertDevice"));
	if (platformExpert)
	{
		data = IORegistryEntryCreateCFProperty(platformExpert,
											   CFStringCreateWithCString(
																		 NULL,
																		 "IOPlatformSerialNumber",
																		 kCFStringEncodingUTF8),
											   kCFAllocatorDefault, 0);
	}
	IOObjectRelease(platformExpert);
	CFShow(data);
	return 0;
	
}