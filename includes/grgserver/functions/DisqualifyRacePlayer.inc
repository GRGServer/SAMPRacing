DisqualifyRacePlayer(playerID)
{
    FormatNew:string[100]("~r~%s", LanguageString(playerID, StringID:182("You got disqualified from the race!")));
    GameTextForPlayer(playerID, string, 3000, 3);

    EndRace(playerID);

    KillTimer(PVar:playerID[RACE_DISQUALIFY_TIMER]);
}