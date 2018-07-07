ShowDialog:Teleports(playerID)
{
    new list[2048];

    Foreach(teleportID, g_teleports)
    {
        if (g_teleports[teleportID][E_TELEPORT_ADMINSONLY] && PVar:playerID[ISADMIN])
        {
            continue;
        }

        AddLine:list("%s\n", g_teleports[teleportID][E_TELEPORT_NAME]);
    }

    CreateDialog(playerID, "Teleports", DIALOG_STYLE_LIST, LanguageString(playerID, StringID:247("Teleport to location")), list, LanguageString(playerID, StringID:40("OK")), LanguageString(playerID, StringID:4("Cancel")));
}

DialogResponse:Teleports(playerID, response, listItem, inputText[])
{
    if (response)
    {
        Foreach(teleportID, g_teleports)
        {
            // Check whether the teleport is the requested one
            if (StrNotNull(g_teleports[teleportID][E_TELEPORT_NAME]) && !strcmp(g_teleports[teleportID][E_TELEPORT_NAME], inputText, true))
            {
                // Check whether the teleport is not only for admins or the player is an admin
                if (!g_teleports[teleportID][E_TELEPORT_ADMINSONLY] || PVar:playerID[ISADMIN])
                {
                    TeleportTo(playerID, teleportID);
                    return;
                }
            }
        }

        SendClientMessageEx(playerID, COLOR_ERROR, StringID:49("Teleport not found!"));
    }
}