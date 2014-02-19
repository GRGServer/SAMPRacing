ACMD:goto(playerID, params[], String:100("Teleporting"))
{
	new ToPlayerID;
    if(sscanf(params,"u",ToPlayerID)) return SendClientMessage(playerid,0x00FF00FF,"Benutzung: /goto [USER]");
    new Float:x; new Float:y; new Float:z;
    GetPlayerPos(ToPlayerID,x,y,z);
    SetPlayerPos(playerID,x+2,y,z);
    return COMMAND_OK;
}
