ShowDialog:Register_Password1(playerID)
{
	CreateDialog(playerID, "Register_Password1", DIALOG_STYLE_PASSWORD, LanguageString(playerID, StringID:33("Register")), LanguageString(playerID, StringID:36("Please enter a new password for your account.")), LanguageString(playerID, StringID:37("Next")), LanguageString(playerID, StringID:34("Back")));
}

DialogResponse:Register_Password1(playerID, response, listItem, inputText[])
{
	if (response)
	{
		if (strlen(inputText) >= REGISTER_PASSWORD_MIN && strlen(inputText) <= STRINGLENGTH_HASHSTRING)
		{
			SetPVarStr:playerID[REGISTERPASSWORD][STRINGLENGTH_HASHSTRING](inputText);
			ShowDialog:Register_Password2(playerID);
		}
		else
		{
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:30("Please use a password with a length between %d and %d!"), REGISTER_PASSWORD_MIN, STRINGLENGTH_HASHSTRING);
			ShowDialog:Register_Password1(playerID);
		}
	}
	else
	{
		ShowDialog:Register_Language(playerID);
	}
}