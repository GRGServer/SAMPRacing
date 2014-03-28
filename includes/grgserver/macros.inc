// CMD:name(playerID, params, languageStringID)
#define CMD:%0(%1,%2,%3) COMMAND:%0(%1, %2)

// PCMD:name[PVarName](playerID, params, languageStringID)
#define PCMD:%0[%1](%2,%3,%4) COMMAND:%0(%2, %3) if (!PVar:%2[%1]) return COMMAND_PERMISSION_DENIED; else

// COMMAND:name(playerID, params)
#define COMMAND:%0(%1,%2) forward cmd_%0(%1, %2); public cmd_%0(%1, %2) if (!PVar:%1[ALLOWCMDS] && !PVar:%1[ISADMIN]) return COMMAND_NO_CMDS_ALLOWED; else

// AddLine:string(string[, formatParameters])
#define AddLine:%0(%1) if (strlen(%0)) strcat(%0, "\n"); Format:g_addLineString(%1); strcat(%0, g_addLineString)

// Count(countingVariable, maximumValue)
#define Count(%0,%1) for (new %0 = 0; %0 < %1; %0++)

// Count1(countingVariable, maximumValue) -> Same as Count(countingVariable, maximumValue) but starts at 1 and includes maximumValue
#define Count1(%0,%1) for (new %0 = 1; %0 <= %1; %0++)

// DialogResponse:DIALOGNAME(playerID, response, listItem, inputText[])
#define DialogResponse:%0(%1) forward DR_%0(%1); public DR_%0(%1)

// Foreach(countingVariable, array)
#define Foreach(%0,%1) for (new %0 = 0; %0 < sizeof(%1); %0++)

// Format:string(formatString, parameters)
#define Format:%0(%1) format(%0, sizeof(%0), %1)

// FormatNew:string[size](formatString, parameters)
#define FormatNew:%0[%1](%2) new %0[%1]; Format:%0(%2)

// FormatMoney(floatValue)
#define FormatMoney(%0) FormatNumber(Float:%0, 2, '.', ',')

// GetStringArg(argumentIndex, returnString)
#define GetStringArg(%0,%1); \
for (new i_%0 = 0; ; ++i_%0) \
{ \
	if ((%1[i_%0] = getarg((%0), i_%0)) != EOS) \
		continue; \
	else \
		break; \
}

// IsKeyPressed(keys)
#define IsKeyPressed(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

// IsStr(string1, string2)
#define IsStr(%0,%1) (strlen(%0) && strlen(%1) && !strcmp(%0, %1, true))

// LanguageStringLimit(number)
// Language String Editor searches for this and replaces the number with the required number of strings
#define LanguageStringLimit(%0) %0

// LoggedInPlayers(returningPlayerID)
#define LoggedInPlayers(%0) Count(%0, g_maxPlayers) if (IsLoggedIn(%0))

// MySQLFormat(format, {Float,_}:...)
#define MySQLFormat(%0) mysql_format(1, g_sqlQuery, sizeof(g_sqlQuery), %0)

// Object:objectID[field]
#define Object:%0[%1] g_objects[%0 - 1][E_OBJECT_%1]

// PlayerLoop(returningPlayerID)
#define PlayerLoop(%0) Count(%0, g_maxPlayers) if (IsPlayerConnected(%0))

// PVar:playerID[field]
#define PVar:%0[%1] g_playerVariables[%0][E_PVAR_%1]

// RandomEx(min, max)
#define RandomEx(%0,%1) (random(%1 - %0 + 1) + %0)

// SetPVarStr:playerID[field][size](string)
#define SetPVarStr:%0[%1][%2](%3) format(PVar:%0[%1], %2, %3)

// ShowDialog:DIALOGNAME(playerID [,parameters...])
#define ShowDialog:%0(%1) SD_%0(%1)

// StartScreenFader(playerID, red, green, blue, steps, waitOnEnd, extraID)
#define StartScreenFader(%0) Timer_ScreenFader(%0)

// StringID:ID("englishString")
#define StringID:%0(%1) %0

// Timer:name(parameters)
#define Timer:%0(%1) forward Timer_%0(%1); public Timer_%0(%1)

// VehicleProperty:vehicleID[property]
#define VehicleProperty:%0[%1] g_vehicles[%0 - 1][E_VEHICLE_%1]