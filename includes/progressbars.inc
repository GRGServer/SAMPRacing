/**
 *  Progress Bar 1.3.1.0
 *  Copyright 2007-2010 Infernus' Group,
 *  Flávio Toribio (flavio_toibio@hotmail.com)
 *
 *  Updated by Southclaw for use with the PlayerTextDraws of 0.3e
 *  Updated again by Southclaw for some bugfixes and removal of the per-player textdraw array
 *  Textdraw IDs are now kept in a separate array that isn't per-player, to save memory.
 *
 */

#if defined _playerprogress_included
	#endinput
#endif

#if !defined _samp_included
	#tryinclude <a_samp>
	#if !defined _samp_included
		#error could not locate a_samp.inc file, please check your server includes
	#endif
#endif

#tryinclude <foreach>

#define _playerprogress_included
#define _playerprogress_version	0x1310

#define MAX_PLAYER_BARS				(MAX_PLAYER_TEXT_DRAWS / 3)
#define INVALID_PLAYER_BAR_VALUE	(Float:0xFFFFFFFF)
#define INVALID_PLAYER_BAR_ID		(PlayerBar:-1)
#define pb_percent(%1,%2,%3,%4)	((%1 - 6.0) + ((((%1 + 6.0 + %2 - 2.0) - %1) / %3) * %4))
//pb_percent(x, width, max, value)

/* Pawno/Infernus Pawn Editor function list
native PlayerBar:CreatePlayerProgressBar(playerid, Float:x, Float:y, Float:width=55.5, Float:height=3.2, color, Float:max=100.0);
native DestroyPlayerProgressBar(playerid, PlayerBar:barid);
native ShowPlayerProgressBar(playerid, PlayerBar:barid);
native HidePlayerProgressBar(playerid, PlayerBar:barid);
native SetPlayerProgressBarValue(playerid, PlayerBar:barid, Float:value);
native Float:GetPlayerProgressBarValue(playerid, PlayerBar:barid);
native SetPlayerProgressBarMaxValue(playerid, PlayerBar:barid, Float:max);
native SetPlayerProgressBarColor(playerid, PlayerBar:barid, color);
native UpdatePlayerProgressBar(playerid, PlayerBar:barid);
*/

forward PlayerBar:CreatePlayerProgressBar(playerid, Float:x, Float:y, Float:width=55.5, Float:height=3.2, color, Float:max=100.0);
forward Float:GetPlayerProgressBarValue(playerid, PlayerBar:barid);

enum E_BAR_DATA
{
	Float:pbar_x,
	Float:pbar_y,
	Float:pbar_w,
	Float:pbar_h,
	Float:pbar_m,
	Float:pbar_v,
	pbar_colour,
	bool:pbar_valid
}
enum E_BAR_TEXT_DRAW
{
	PlayerText:pbar_textdraw1,
	PlayerText:pbar_textdraw2,
	PlayerText:pbar_textdraw3,
}

static
	PlayerBars[MAX_PLAYERS][MAX_PLAYER_BARS][E_BAR_DATA],
	PlayerBarText[MAX_PLAYER_BARS][E_BAR_TEXT_DRAW];


stock PlayerBar:CreatePlayerProgressBar(playerid, Float:x, Float:y, Float:width=55.5, Float:height=3.2, color, Float:max=100.0)
{
	new
		barid;

	for(barid = 0; barid < MAX_PLAYER_BARS; ++barid) // Changed from `Bars` to `MAX_PLAYER_BARS` rather than getting the size of the second cell
		if(!PlayerBars[playerid][barid][pbar_valid]) break;

	if(PlayerBars[playerid][barid][pbar_valid] || barid == MAX_PLAYER_BARS)
		return INVALID_PLAYER_BAR_ID;

	new PlayerText:in_t = PlayerBarText[barid][pbar_textdraw1] = CreatePlayerTextDraw(playerid, x, y, "_");
	PlayerTextDrawUseBox		(playerid, in_t, 1);
	PlayerTextDrawTextSize		(playerid, in_t, x + width, 0.0);
	PlayerTextDrawLetterSize	(playerid, in_t, 1.0, height / 10);
	PlayerTextDrawBoxColor		(playerid, in_t, 0x00000000 | (color & 0x000000FF));

	in_t = PlayerBarText[barid][pbar_textdraw2] = CreatePlayerTextDraw(playerid, x + 1.2, y + 2.15, "_");
	PlayerTextDrawUseBox		(playerid, in_t, 1);
	PlayerTextDrawTextSize		(playerid, in_t, x + width - 2.0, 0.0);
	PlayerTextDrawLetterSize	(playerid, in_t, 1.0, height / 10 - 0.35);
	PlayerTextDrawBoxColor		(playerid, in_t, (color & 0xFFFFFF00) | (0x66 & ((color & 0x000000FF) / 2)));

	in_t = PlayerBarText[barid][pbar_textdraw3] = CreatePlayerTextDraw(playerid, x + 1.2, y + 2.15, "_");
	PlayerTextDrawTextSize		(playerid, in_t, pb_percent(x, width, max, 1.0), 0.0);
	PlayerTextDrawLetterSize	(playerid, in_t, 1.0, height / 10 - 0.35);
	PlayerTextDrawBoxColor		(playerid, in_t, color);

	PlayerBars[playerid][barid][pbar_x] = x;
	PlayerBars[playerid][barid][pbar_y] = y;
	PlayerBars[playerid][barid][pbar_w] = width;
	PlayerBars[playerid][barid][pbar_h] = height;
	PlayerBars[playerid][barid][pbar_m] = max;
	PlayerBars[playerid][barid][pbar_colour] = color;
	PlayerBars[playerid][barid][pbar_valid] = true;
	return PlayerBar:barid;
}

stock DestroyPlayerProgressBar(playerid, PlayerBar:barid)
{
	if(barid != INVALID_PLAYER_BAR_ID && PlayerBar:-1 < barid < PlayerBar:MAX_PLAYER_BARS)
	{
		if(!PlayerBars[playerid][_:barid][pbar_valid])
			return 0;

		PlayerTextDrawDestroy(playerid, PlayerBarText[_:barid][pbar_textdraw1]);
		PlayerTextDrawDestroy(playerid, PlayerBarText[_:barid][pbar_textdraw2]);
		PlayerTextDrawDestroy(playerid, PlayerBarText[_:barid][pbar_textdraw3]);

		PlayerBars[playerid][_:barid][pbar_x] = 0.0;
		PlayerBars[playerid][_:barid][pbar_y] = 0.0;
		PlayerBars[playerid][_:barid][pbar_w] = 0.0;
		PlayerBars[playerid][_:barid][pbar_h] = 0.0;
		PlayerBars[playerid][_:barid][pbar_m] = 0.0;
		PlayerBars[playerid][_:barid][pbar_v] = 0.0;
		PlayerBars[playerid][_:barid][pbar_colour] = 0;
		PlayerBars[playerid][_:barid][pbar_valid] = false;
		return 1;
	}
	return 0;
}

stock ShowPlayerProgressBar(playerid, PlayerBar:barid)
{
	if(IsPlayerConnected(playerid) && barid != INVALID_PLAYER_BAR_ID && PlayerBar:-1 < barid < PlayerBar:MAX_PLAYER_BARS)
	{
		if(!PlayerBars[playerid][_:barid][pbar_valid])
			return 0;

		PlayerTextDrawShow(playerid, PlayerBarText[_:barid][pbar_textdraw1]);
		PlayerTextDrawShow(playerid, PlayerBarText[_:barid][pbar_textdraw2]);
		PlayerTextDrawShow(playerid, PlayerBarText[_:barid][pbar_textdraw3]);
		return 1;
	}
	return 0;
}

stock HidePlayerProgressBar(playerid, PlayerBar:barid)
{
	if(IsPlayerConnected(playerid) && barid != INVALID_PLAYER_BAR_ID && PlayerBar:-1 < barid < PlayerBar:MAX_PLAYER_BARS)
	{
		if(!PlayerBars[playerid][_:barid][pbar_valid])
			return 0;

		PlayerTextDrawHide(playerid, PlayerBarText[_:barid][pbar_textdraw1]);
		PlayerTextDrawHide(playerid, PlayerBarText[_:barid][pbar_textdraw2]);
		PlayerTextDrawHide(playerid, PlayerBarText[_:barid][pbar_textdraw3]);
		return 1;
	}
	return 0;
}

stock SetPlayerProgressBarValue(playerid, PlayerBar:barid, Float:value)
{
	if(barid == INVALID_PLAYER_BAR_ID || PlayerBar:MAX_PLAYER_BARS < barid < PlayerBar:-1)
		return 0;

	if(PlayerBars[playerid][_:barid][pbar_valid])
	{
		value =
			(value < 0.0) ? (0.0) : (value > PlayerBars[playerid][_:barid][pbar_m]) ? (PlayerBars[playerid][_:barid][pbar_m]) : (value);

		PlayerTextDrawUseBox(playerid, PlayerBarText[_:barid][pbar_textdraw3], value > 0.0);

        PlayerBars[playerid][_:barid][pbar_v] = value;

		PlayerTextDrawTextSize(playerid, PlayerBarText[_:barid][pbar_textdraw3],
			pb_percent(PlayerBars[playerid][_:barid][pbar_x], PlayerBars[playerid][_:barid][pbar_w], PlayerBars[playerid][_:barid][pbar_m], value), 0.0);

		return 1;
	}
	return 0;
}

stock Float:GetPlayerProgressBarValue(playerid, PlayerBar:barid)
{
	if(barid == INVALID_PLAYER_BAR_ID || PlayerBar:MAX_PLAYER_BARS < barid < PlayerBar:-1)
		return INVALID_PLAYER_BAR_VALUE;

	if(PlayerBars[playerid][_:barid][pbar_valid])
		return PlayerBars[playerid][_:barid][pbar_v];

	return INVALID_PLAYER_BAR_VALUE;
}

stock SetPlayerProgressBarMaxValue(playerid, PlayerBar:barid, Float:max)
{
	if(barid == INVALID_PLAYER_BAR_ID || PlayerBar:MAX_PLAYER_BARS < barid < PlayerBar:-1)
		return 0;

	if(PlayerBars[playerid][_:barid][pbar_valid])
	{
		PlayerBars[playerid][_:barid][pbar_m] = max;
		SetPlayerProgressBarValue(playerid, barid, PlayerBars[playerid][_:barid][pbar_v]);
		return 1;
	}
	return 0;
}

stock SetPlayerProgressBarColor(playerid, PlayerBar:barid, color)
{
	if(barid == INVALID_PLAYER_BAR_ID || PlayerBar:MAX_PLAYER_BARS < barid < PlayerBar:-1)
		return 0;

	if(PlayerBars[playerid][_:barid][pbar_valid])
	{	
		PlayerBars[playerid][_:barid][pbar_colour] = color;
		PlayerTextDrawBoxColor(playerid, PlayerBarText[_:barid][pbar_textdraw1], 0x00000000 | (color & 0x000000FF));

		PlayerTextDrawBoxColor(playerid, PlayerBarText[_:barid][pbar_textdraw2],
			(color & 0xFFFFFF00) | (0x66 & ((color & 0x000000FF) / 2)));

		PlayerTextDrawBoxColor(playerid, PlayerBarText[_:barid][pbar_textdraw3], color);
		return 1;
	}
	return 0;
}

stock UpdatePlayerProgressBar(playerid, PlayerBar:barid)
{
	return ShowPlayerProgressBar(playerid, barid);
}