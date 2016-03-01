// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MSG2DBXX_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MSG2DBXX_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MSG2DBXX_EXPORTS
#define MSG2DBXX_API __declspec(dllexport)
#else
#define MSG2DBXX_API __declspec(dllimport)
#endif

// This class is exported from the Msg2DB.xx.dll
class MSG2DBXX_API CMsg2DBxx {
public:
	CMsg2DBxx(void);
	// TODO: add your methods here.
};

extern MSG2DBXX_API int nMsg2DBxx;

MSG2DBXX_API int fnMsg2DBxx(void);
