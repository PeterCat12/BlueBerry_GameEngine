#include <windows.h>
#ifdef _DEBUG
bool _trace(TCHAR *format, ... );
#define TRACE _trace
#else
#define TRACE __noop
#endif

//The Trace Macro is used for Debug Purposes.
// It allows for printf style prints