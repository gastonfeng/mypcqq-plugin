#include "stdafx.h"
#include "mypcqq.h"
typedef long(_stdcall *Api_GetVersionDll)();
typedef long(_stdcall *Api_OutPutDll)(char*);
typedef char*(_stdcall *Api_GetGtk_BknDll)(char*);
typedef char*(_stdcall *Api_GetBkn32Dll)(char*);
char* Api_GetGtk_Bkn(char* qq){
	HINSTANCE hLib = LoadLibrary(TEXT("Message.dll"));
	Api_GetGtk_BknDll fun = (Api_GetGtk_BknDll)GetProcAddress(hLib, "Api_GetGtk_Bkn");
	char* m_Result = (*fun)(qq);
	FreeLibrary(hLib);
	return m_Result;
}
char *Api_GetBkn32(char*qq){
	HINSTANCE hLib = LoadLibrary(TEXT("Message.dll"));
	Api_GetBkn32Dll fun = (Api_GetBkn32Dll)GetProcAddress(hLib, "Api_GetBkn32");
	char* m_Result = (*fun)(qq);
	FreeLibrary(hLib);
	return m_Result;
}
long Api_GetVersion(){
	HINSTANCE hLib = LoadLibrary(TEXT("Message.dll"));
	Api_GetVersionDll fun = (Api_GetVersionDll)GetProcAddress(hLib, "Api_GetVersion");
	long m_Result = (*fun)();
	FreeLibrary(hLib);
	return m_Result;
}
long Api_OutPut(char*  content){
	HINSTANCE hLib = LoadLibrary(TEXT("Message.dll"));
	Api_OutPutDll fun = (Api_OutPutDll)GetProcAddress(hLib, "Api_OutPut");
	long m_Result = (*fun)(content);
	FreeLibrary(hLib);
	return m_Result;
}