#define _USE_HTML
#define _USE_INIT
#define _USE_MYSQL
#define _USE_MYSQL_MACROS
#include "macros.h"

#include <fcgi-stdio.h>
#include <stdio.h>
#include <cgi.h>
#include <mysql.h>


void handle_it()
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	printf("<head></head><body>\n");
	db_query(conn,res=,"SELECT id,title,href FROM links WHERE nextlook < now()");
	while(row=mysql_fetch_row(res))
	{
		printf("<p data=\"%s\" class=\"linkitem\"><span class=\"title\">%s</span><br />%s</p>\n",row[0],row[1],row[2]);
	}
	printf("</body>\n");
}


int main(int argc,char **argv)
{
	int cmdrepeat=NULL;
	if(argc==2 && !strcmp(argv[1],"repeat")
		cmdrepeat=1;

	while( FCGI_Accept() || cmdrepeat )
	{
		cgi_init();
		handle_it();	
	}
}
