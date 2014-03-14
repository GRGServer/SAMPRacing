UnFreezeCar(playerid)
{
	for(new i=0; i<PLAYERS; i++)
	{
		TogglePlayerControllable(playerid,1);
		KillTimer(LUnFreeze);
	}
	return 1;
}
