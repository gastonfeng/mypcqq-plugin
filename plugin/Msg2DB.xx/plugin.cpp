#include "stdafx.h"
# include <stdio.h>
# include <stdlib.h>
#include "plugin.h"
#include "mypcqq.h"
#include "SaveMsg.h"

char* info(){
	return "消息存储到数据库";
}

int Message(char* qq, int communicationType, char* oriMsg, char* cookies, char* sessionKey, char* clientKey){
	return 1;
}
int EventFun(char* qq, int msgType, int msgSubType, char* msgFrom, char* fromQQ, char* toQQ, char* msg, char* oriMsg, int outPointer){
	
	if (msgType == 2)//2
	{
		GroupMsg2Mysql(qq, msgType, msgSubType, msgFrom, fromQQ, toQQ, msg, oriMsg, outPointer);
	}
	else if (msgType == 12003){
		if (msgSubType==1){
			
		}
	}
	return 1;
}
void set(){

}
int end(){
	return 1;
}