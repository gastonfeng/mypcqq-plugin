// Msg2DB.xx.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Msg2DB.h"


// This is an example of an exported variable
MSG2DBXX_API int nMsg2DBxx=0;

// This is an example of an exported function.
MSG2DBXX_API int fnMsg2DBxx(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Msg2DB.xx.h for the class definition
CMsg2DBxx::CMsg2DBxx()
{
	return;
}
