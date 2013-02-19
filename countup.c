#define _USE_PLAIN
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
	char *idtext;
	if( (idtext=ispset("id")) )
		db_query(conn,res=,"UPDATE links SET nextweek=new()+ONEDAY*2^views");
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
