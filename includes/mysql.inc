/**
 *     SA:MP MySQL v2.1 Functions
 *  (c) Copyright 2011, StrickenKid
 *
 **/

#if defined __mysql_included
	#endinput
#endif

#define __mysql_included
#pragma library mysql

// plugin error id's

#define P_ERROR_NONE                                0
#define P_ERROR_INCPARAMCNT                         1
#define P_ERROR_INCVALUE                            2
#define P_ERROR_MAXCONN                             3
#define P_ERROR_DBNOCONN                            4
#define P_ERROR_NORES                               5
#define P_ERROR_RES                                 6
#define P_ERROR_NOFIELD                             7
#define P_ERROR_NOFIELDDATA                         8
#define P_ERROR_NOROWDATA                           9
#define P_ERROR_CANTALLOC                           10
#define P_ERROR_NOCALLBACK                          11
#define P_ERROR_NOQUERY                             12

// mysql headers defines

#define REFRESH_GRANT								1
#define REFRESH_LOG									2
#define REFRESH_TABLES								4
#define REFRESH_HOSTS								8
#define REFRESH_STATUS								16
#define REFRESH_THREADS								32
#define REFRESH_SLAVE   							64
#define REFRESH_MASTER 							 	128

// mysql error id's

#define CR_ERROR_FIRST  							2000
#define CR_UNKNOWN_ERROR							2000
#define CR_SOCKET_CREATE_ERROR						2001
#define CR_CONNECTION_ERROR							2002
#define CR_CONN_HOST_ERROR							2003
#define CR_IPSOCK_ERROR								2004
#define CR_UNKNOWN_HOST								2005
#define CR_SERVER_GONE_ERROR						2006
#define CR_VERSION_ERROR							2007
#define CR_OUT_OF_MEMORY							2008
#define CR_WRONG_HOST_INFO							2009
#define CR_LOCALHOST_CONNECTION 					2010
#define CR_TCP_CONNECTION							2011
#define CR_SERVER_HANDSHAKE_ERR 					2012
#define CR_SERVER_LOST								2013
#define CR_COMMANDS_OUT_OF_SYNC 					2014
#define CR_NAMEDPIPE_CONNECTION 					2015
#define CR_NAMEDPIPEWAIT_ERROR  					2016
#define CR_NAMEDPIPEOPEN_ERROR  					2017
#define CR_NAMEDPIPESETSTATE_ERROR 					2018
#define CR_CANT_READ_CHARSET						2019
#define CR_NET_PACKET_TOO_LARGE						2020
#define CR_EMBEDDED_CONNECTION						2021
#define CR_PROBE_SLAVE_STATUS   					2022
#define CR_PROBE_SLAVE_HOSTS    					2023
#define CR_PROBE_SLAVE_CONNECT  					2024
#define CR_PROBE_MASTER_CONNECT 					2025
#define CR_SSL_CONNECTION_ERROR 					2026
#define CR_MALFORMED_PACKET     					2027
#define CR_WRONG_LICENSE							2028
#define CR_NULL_POINTER								2029
#define CR_NO_PREPARE_STMT							2030
#define CR_PARAMS_NOT_BOUND							2031
#define CR_DATA_TRUNCATED							2032
#define CR_NO_PARAMETERS_EXISTS 					2033
#define CR_INVALID_PARAMETER_NO 					2034
#define CR_INVALID_BUFFER_USE						2035
#define CR_UNSUPPORTED_PARAM_TYPE 					2036
#define CR_SHARED_MEMORY_CONNECTION             	2037
#define CR_SHARED_MEMORY_CONNECT_REQUEST_ERROR 		2038
#define CR_SHARED_MEMORY_CONNECT_ANSWER_ERROR   	2039
#define CR_SHARED_MEMORY_CONNECT_FILE_MAP_ERROR 	2040
#define CR_SHARED_MEMORY_CONNECT_MAP_ERROR      	2041
#define CR_SHARED_MEMORY_FILE_MAP_ERROR         	2042
#define CR_SHARED_MEMORY_MAP_ERROR              	2043
#define CR_SHARED_MEMORY_EVENT_ERROR     			2044
#define CR_SHARED_MEMORY_CONNECT_ABANDONED_ERROR 	2045
#define CR_SHARED_MEMORY_CONNECT_SET_ERROR      	2046
#define CR_CONN_UNKNOW_PROTOCOL 					2047
#define CR_INVALID_CONN_HANDLE						2048
#define CR_SECURE_AUTH                          	2049
#define CR_FETCH_CANCELED                       	2050
#define CR_NO_DATA                              	2051
#define CR_NO_STMT_METADATA                     	2052
#define CR_NO_RESULT_SET                        	2053
#define CR_NOT_IMPLEMENTED                      	2054
#define CR_SERVER_LOST_EXTENDED						2055
#define CR_STMT_CLOSED								2056
#define CR_NEW_STMT_METADATA                    	2057
#define CR_ERROR_LAST                      			2057

// logging types

#define INVALID_MYSQL_ID							(-1)
#define LOG_OFF										(0)
#define LOG_ALL           							(1)
#define LOG_ONLY_ERRORS   							(2)

// function defines

#define mysql_reload(%1) mysql_refresh(REFRESH_GRANT, %1)

// plugin callbacks

forward OnMysqlQueryArray(resultid, extravars[], MySQL:handle);
forward OnMysqlQuery(resultid, spareid, MySQL:handle);
forward OnMysqlError(error[], errorid, MySQL:handle);

// plugin natives

native MySQL:mysql_init(logtype = LOG_ONLY_ERRORS, printerrors = 1);
native mysql_connect(const host[], const user[], const pass[], const db[], MySQL:handle = (MySQL:0), auto_reconnect = 0);
native mysql_close(MySQL:handle = (MySQL:0));
native mysql_refresh(options, MySQL:handle = (MySQL:0));
native mysql_select_db(const db[], MySQL:handle = (MySQL:0));
native mysql_query(const query[], resultid = (-1), spareid = (0), MySQL:handle = (MySQL:0));
native mysql_query_array(const query[], resultid = (-1), {Float,_}:extravars[], MySQL:handle = (MySQL:0));
native mysql_store_result(MySQL:handle = (MySQL:0));
native mysql_free_result(MySQL:handle = (MySQL:0));
native mysql_result_stored(MySQL:handle = (MySQL:0));
native mysql_fetch_field(const fieldname[], dest[], MySQL:handle = (MySQL:0));
native mysql_fetch_field_num(fieldnum, dest[], MySQL:handle = (MySQL:0));
native mysql_fetch_row(dest[], const splitter[] = "|", MySQL:handle = (MySQL:0));
native mysql_fetch_row_data(MySQL:handle = (MySQL:0));
native mysql_real_escape_string(const string[], dest[], MySQL:handle = (MySQL:0));
native mysql_num_rows(MySQL:handle = (MySQL:0));
native mysql_num_fields(MySQL:handle = (MySQL:0));
native mysql_affected_rows(MySQL:handle = (MySQL:0));
native mysql_insert_id(MySQL:handle = (MySQL:0));
native mysql_ping(MySQL:handle = (MySQL:0));
native mysql_error(dest[], MySQL:handle = (MySQL:0));
native mysql_errno(MySQL:handle = (MySQL:0));
native mysql_warning_count(MySQL:handle = (MySQL:0));
native mysql_info(dest[], MySQL:handle = (MySQL:0));
native mysql_stat(dest[], MySQL:handle = (MySQL:0));
native mysql_get_server_info(dest[], MySQL:handle = (MySQL:0));
native mysql_get_host_info(dest[], MySQL:handle = (MySQL:0));
native mysql_data_seek(rownum, MySQL:handle = (MySQL:0));
native mysql_set_character_set(const csname[], MySQL:handle = (MySQL:0));
native mysql_get_character_set(csname[], MySQL:handle = (MySQL:0));
native mysql_fetch_int(MySQL:handle = (MySQL:0));
native Float:mysql_fetch_float(MySQL:handle = (MySQL:0));
native mysql_fetch_string(dest[], MySQL:handle = (MySQL:0));

#if !defined split
// split function - thanks to Blacklite
stock split(const strsrc[], strdest[][], delimiter = '|')
{
	new i, li, aNum, len, srclen = strlen(strsrc);
	while(i <= srclen)
	{
		if (strsrc[i] == delimiter || i == srclen)
		{
			len = strmid(strdest[aNum], strsrc, li, i, 128);
			strdest[aNum][len] = 0;
			li = i + 1;
			aNum++;
		}
		i++;
	}
}
#endif