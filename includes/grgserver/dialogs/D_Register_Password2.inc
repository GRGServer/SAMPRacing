ShowDialog:Register_Password2(playerID)
{
	CreateDialog(playerID, "Register_Password2", DIALOG_STYLE_PASSWORD, LanguageString(playerID, StringID:39("Repeat password")), LanguageString(playerID, StringID:38("Please repeat your new password to verfify.")), LanguageString(playerID, StringID:37("Next")), LanguageString(playerID, StringID:34("Back")));
}

DialogResponse:Register_Password2(playerID, response, listItem, inputText[])
{
	if (response)
	{
		if (!strcmp(inputText, PVar:playerID[REGISTERPASSWORD]))
		{
			ShowDialog:Register_Language(playerID);
		}
		else
		{
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:31("The entered passwords do not match! Please try again."));
			ShowDialog:Register_Password1(playerID);
		}
	}
	else
	{
		ShowDialog:Register_Password1(playerID);
	}
	return true;
}