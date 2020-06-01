#pragma once
#ifdef DLL2_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif // DLL_EXPORTS

extern "C" DLL_API int multiply(int x, int y);