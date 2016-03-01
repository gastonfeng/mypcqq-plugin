#include "stdafx.h"
#include <mysql.h>
#include "mypcqq.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "globalVar.h"
size_t strcat2(char **dst_out, ...)
{
	size_t len = 0, len_sub;
	va_list argp;
	char *src;
	char *dst = NULL, *dst_p;

	*dst_out = NULL;

	va_start(argp, dst_out);
	for (;;)
	{
		if ((src = va_arg(argp, char *)) == NULL) break;
		len += strlen(src);
	}
	va_end(argp);

	if (len == 0) return 0;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL) return -1;
	dst_p = dst;

	va_start(argp, dst_out);
	for (;;)
	{
		if ((src = va_arg(argp, char *)) == NULL) break;
		len_sub = strlen(src);
		memcpy(dst_p, src, len_sub);
		dst_p += len_sub;
	}
	va_end(argp);
	*dst_p = '\0';

	*dst_out = dst;

	return len;
}
void GroupMsg2Mysql(char* qq, int msgType, int msgSubType, char* msgFrom, char* fromQQ, char* toQQ, char* msg, char* oriMsg, int outPointer){
	MYSQL *con = mysql_init(NULL);
	if (con == NULL)
	{
		return;
	}
	if (mysql_real_connect(con, Msg2DBHost, Msg2DBName, Msg2DBPassword,
		"test", 0, NULL, 0) == NULL)
	{
		Api_OutPut("连接数据库失败！");
		return;
	}
	mysql_query(con, "set names gbk");
	char* str = "INSERT INTO `test`.`qqmessage`(`QQ`,`Group`,`Who`,`Content`)VALUES('";
	char *s = NULL;
	size_t len;
	len = strcat2(&s, str, qq, "','", msgFrom, "','", fromQQ, "','", msg, "');",NULL);
	if (s == NULL) return;
	Api_OutPut(s);
	if (mysql_query(con,s)) {//s
		Api_OutPut("插入数据失败!");
		/*const  char* ss = mysql_error(con);
		char *buf = new char[strlen(ss)+1];
		strcpy_s(buf, strlen(ss)+1,ss);
		Api_OutPut(buf);*/
	}
	mysql_close(con);
	Api_OutPut("访问数据库成功!");
}
 