/**
 * <summary>
 *    This callback is called when a player presses any of the buttons on a dialog.
 * </summary>
 *
 * <param name="playerid">
 *    The ID of the player which responded to the dialog.
 * </param>
 *
 * <param name="dialogid">
 *    The ID of the dialog the player responded to.
 *    This is not used in this gamemode, because named dialogs were used.
 *    The current dialog is stored in the PVar CURRENTDIALOG.
 * </param>
 *
 * <param name="response">
 *    <b>true</b> for first button and <b>false</b> for second button.
 * </param>
 *
 * <param name="listitem">
 *    The ID of the list item selected by the player (If the dialog is of type DIALOG_STYLE_LIST).
 * </param>
 *
 * <param name="inputtext">
 *    The text entered into the dialog or the selected list item text.
 * </param>
 */

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if (!strlen(PVar:playerid[CURRENTDIALOG]))
    {
        return false;
    }

    FormatNew:functionName[MAX_FUNCTION_NAME]("DR_%s", PVar:playerid[CURRENTDIALOG]);// DR = DialogResponse
    if (funcidx(functionName) == -1)
    {
        printf("[DialogResponse] Undefined dialog: %s", PVar:playerid[CURRENTDIALOG]);
        SetPVarStr:playerid[CURRENTDIALOG][STRINGLENGTH_DIALOGNAME]("");

        return false;
    }

    SetPVarStr:playerid[CURRENTDIALOG][STRINGLENGTH_DIALOGNAME]("");
    if (!strlen(inputtext))
    {
        inputtext[0] = '\1';
    }
    CallLocalFunction(functionName, "ddds", playerid, response, listitem, inputtext);

    return true;
}