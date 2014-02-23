#include <a_samp>
#include <sscanf2>

stock const
	ERROR_INVALID_CLIENT[] = "Invalid client connecting from ",
	ERROR_RCON_EXPLOIT[] = "Warning: /rcon command exploit from: ",
	ERROR_PLAYER_DIALOG[] = "Warning: PlayerDialogResponse PlayerId: ",
	ERROR_DIALOG_CRASH[] = "Warning: PlayerDialogResponse crash exploit from PlayerId: ",
	ERROR_PACKET_MODIFIED[] = "Packet was modified, sent by id: ",
	ERROR_PORT_REFUSED[] = "Remote Port Refused for Player: ",
	ERROR_BLOCKING[] = "Blocking ",
	ERROR_SERVER_FULL[] = " due to a 'server full' attack";

/*
native FIXES_ReadIp(const str[]);
*/

stock FIXES_ReadIp(const str[])
{
	static
		sNo[16] = "255.255.255.255",
		sIP[16];
	sscanf(str, "p<:>s[16]", sIP);
	if (strfind(sIP, ".") == -1)
	{
		if (sscanf(str, "p<:>{d}s[16]", sIP))
		{
			return sNo;
		}
	}
	if (strfind(sIP, " ") != -1)
	{
		sIP[strfind(sIP, " ")] = '\0';
	}
	return sIP;
}

/*
native FIXES_ExtractIp(const str[]);
*/

stock FIXES_ExtractIp(const str[])
{
	new ip0, ip1, ip2, ip3;
	if (sscanf(FIXES_ReadIp(str), "p<.>dddd", ip0, ip1, ip2, ip3))
	{
		return -1;
	}
	return (ip0 << 24) | (ip1 << 16) | (ip2 << 8) | (ip3);
}

/*
native FIXES_SilentBanPlayer(playerid);
*/

stock FIXES_SilentBanPlayer(playerid)
{
	static
		sBanIP[22];
	if (GetPlayerIp(playerid, sBanIP, sizeof (sBanIP)))
	{
		printf("fixes.plugin: Banning IP %s", sBanIP);
		format(sBanIP, sizeof (sBanIP), "banip %s", sBanIP);
		SendRconCommand(sBanIP);
	}
	//Kick(playerid);
}

/*
native FIXES_SilentBanIP(const ip[]);
*/

stock FIXES_SilentBanIP(const ip[])
{
	printf("fixes.plugin: Banning IP %s", ip);
	static
		sBanIP[22];
	format(sBanIP, sizeof (sBanIP), "banip %s", ip);
	SendRconCommand(sBanIP);
}

forward OnServerMessage(const msg[]);

native SetTimer_(const func[], const delay, const interval, const count);
native SetTimerEx_(const func[], const delay, const interval, const count, const format[], {Float, _}:...);
native KillTimer_(timer) = KillTimer;
