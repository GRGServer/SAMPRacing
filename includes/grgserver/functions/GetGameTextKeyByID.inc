GetGameTextKeyByID(id, inVehicleState)
{
	new onFoot[100];
	new inVehicle[100];

	switch (id)
	{
		case KEY_ACTION:
		{
			onFoot = "~k~~PED_ANSWER_PHONE~";
			inVehicle="~k~~VEHICLE_FIREWEAPON_ALT~";
		}
		case KEY_CROUCH:
		{
			onFoot = "~k~~PED_DUCK~";
			inVehicle = "~k~~VEHICLE_HORN~";
		}
		case KEY_FIRE:
		{
			onFoot = "~k~~PED_FIREWEAPON~";
			inVehicle = "~k~~VEHICLE_FIREWEAPON~";
		}
		case KEY_SPRINT:
		{
			onFoot = "~k~~PED_SPRINT~";
			inVehicle = "~k~~VEHICLE_ACCELERATE~";
		}
		case KEY_SECONDARY_ATTACK:
		{
			onFoot = "~k~~VEHICLE_ENTER_EXIT~";
			inVehicle = "~k~~VEHICLE_ENTER_EXIT~";
		}
		case KEY_JUMP:
		{
			onFoot = "~k~~PED_JUMPING~";
			inVehicle = "~k~~VEHICLE_BRAKE~";
		}
		case KEY_LOOK_RIGHT:
		{
			onFoot = "";
			inVehicle = "~k~~VEHICLE_LOOKRIGHT~";
		}
		case KEY_HANDBRAKE:
		{
			onFoot = "~k~~PED_LOCK_TARGET~";
			inVehicle = "~k~~VEHICLE_HANDBRAKE~";
		}
		case KEY_LOOK_LEFT:
		{
			onFoot = "";
			inVehicle = "~k~~VEHICLE_LOOKLEFT~";
		}
		// Same as KEY_LOOK_BEHIND
		/*case KEY_SUBMISSION:
		{
			onFoot = "";
			inVehicle = "~k~~TOGGLE_SUBMISSIONS~";
		}*/
		case KEY_LOOK_BEHIND:
		{
			onFoot = "~k~~PED_LOOKBEHIND~";
			inVehicle = "~k~~VEHICLE_LOOKBEHIND~";
		}
		case KEY_WALK:
		{
			onFoot = "~k~~SNEAK_ABOUT~";
			inVehicle = "";
		}
		case KEY_ANALOG_UP:
		{
			onFoot = "";
			inVehicle = "~k~~VEHICLE_TURRETUP~";
		}
		case KEY_ANALOG_DOWN:
		{
			onFoot = "";
			inVehicle = "~k~~VEHICLE_TURRETDOWN~";
		}
		case KEY_ANALOG_LEFT:
		{
			onFoot = "~k~~VEHICLE_LOOKLEFT~";
			inVehicle = "~k~~VEHICLE_TURRETLEFT~";
		}
		case KEY_ANALOG_RIGHT:
		{
			onFoot = "~k~~VEHICLE_LOOKRIGHT~";
			inVehicle = "~k~~VEHICLE_TURRETRIGHT~";
		}
		case KEY_YES:
		{
			onFoot = "~k~~CONVERSATION_YES~";
			inVehicle = "~k~~CONVERSATION_YES~";
		}
		case KEY_NO:
		{
			onFoot = "~k~~CONVERSATION_NO~";
			inVehicle = "~k~~CONVERSATION_NO~";
		}
		case KEY_CTRL_BACK:
		{
			onFoot = "~k~~GROUP_CONTROL_BWD~";
			inVehicle = "~k~~GROUP_CONTROL_BWD~";
		}
	}

	if (inVehicleState)
	{
		return inVehicle;
	}
	else
	{
		return onFoot;
	}
}