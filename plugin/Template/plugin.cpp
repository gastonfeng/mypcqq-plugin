#include "stdafx.h"
# include <stdio.h>
# include <stdlib.h>
#include "plugin.h"
#include "mypcqq.h"
char* info(){
	char*str;
	long m_Result = Api_GetVersion();
	if (m_Result >= 1447304063)
	{
		str = "123123";
	}
	else{
		str = "321321";
	}
	return str;
}

int Message(char* qq, int communicationType, char* oriMsg, char* cookies, char* sessionKey, char* clientKey){
	return 1;
}
int EventFun(char* qq, int msgType, int msgSubType, char* msgFrom, char* fromQQ, char* toQQ, char* msg, char* oriMsg, int outPointer){
	Api_OutPut("我是中国人!");
	return 1;
}
void set(){

}
int end(){
	return 1;
}