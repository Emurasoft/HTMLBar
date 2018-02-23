#pragma once

#ifndef _DEBUG
#define _SECURE_SCL	0
#endif

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <malloc.h>
#include <crtdbg.h>
#include <commctrl.h>
#include <olectl.h>
#include <shlwapi.h>
#include <commdlg.h>

#ifdef _DEBUG
#define VERIFY(f)          _ASSERTE(f)
#else
#define VERIFY(f)          ((void)(f))
#endif

#pragma warning( push )
#pragma warning( disable : 4995 ) // 'function': name was marked as #pragma deprecated
#pragma warning( disable : 4244 )  // 'argument' : conversion from '__w64 unsigned int' to 'rsize_t', possible loss of data
#include <strsafe.h>
#include <vector>
#pragma warning( pop )

using namespace std;


#ifdef _DEBUG
#define TRACE	AfxTrace
inline void __cdecl AfxTrace(LPCTSTR lpszFormat, ...)
{
	int nBuf;
	TCHAR szBuffer[512];
	va_list args;
	va_start(args, lpszFormat);
	nBuf = StringCchVPrintf( szBuffer, _countof( szBuffer ), lpszFormat, args );
	_ASSERTE(nBuf < _countof(szBuffer));
	OutputDebugString( szBuffer );
	va_end(args);
}
#define UNUSED(x) __noop
#else
#define TRACE  __noop // (void(0))
#define UNUSED(x) x
#endif

#ifdef _UNICODE
typedef wstring tstring;
#else
typedef string tstring;
#endif

#ifdef _DEBUG
   #define _DEBUG_NEW   new( _NORMAL_BLOCK, __FILE__, __LINE__)
   #define _RELEASE_NEW
#else
   #define _DEBUG_NEW
   #define _RELEASE_NEW new(nothrow)
#endif // _DEBUG
