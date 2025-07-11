//En Alta Ekle:

#ifdef ENABLE_MINI_GAME_FINDM
ACMD(do_find_m_event)
{
	char arg1[256], arg2[256];
	int iCommand = 1;
	int iDays = 1;
	two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2));

	if (!*arg1 && !*arg2)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Usage: find_m_event <command> <days_number>");
		ch->ChatPacket(CHAT_TYPE_INFO, "	0 = Disable.");
		ch->ChatPacket(CHAT_TYPE_INFO, "	1 = Enable.");
		ch->ChatPacket(CHAT_TYPE_INFO, "<days_number> Is the number of days that event is on.");
		return;
	}

	if (isnhdigit(*arg1) && isnhdigit(*arg2))
	{
		str_to_number(iCommand, arg1);
		str_to_number(iDays, arg2);
	}

	if (iDays <= 0)
		return;

	if (iCommand == 1)
	{
		if (quest::CQuestManager::instance().GetEventFlag("mini_game_findm_event") == 0)
		{
			int iEndTime = time(0) + 60 * 60 * 24 * iDays;

			quest::CQuestManager::instance().RequestSetEventFlag("findm_event_end_day", iEndTime);

			quest::CQuestManager::instance().RequestSetEventFlag("mini_game_findm_event", 1);
			quest::CQuestManager::instance().RequestSetEventFlag("enable_find_m_event_drop", 1);

			ch->ChatPacket(CHAT_TYPE_COMMAND, "is_active_event");
		}
		else
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "This event is already opened.");
		}
	}
	else
	{
		quest::CQuestManager::instance().RequestSetEventFlag("mini_game_findm_event", 0);
		quest::CQuestManager::instance().RequestSetEventFlag("enable_find_m_event_drop", 0);
		ch->ChatPacket(CHAT_TYPE_INFO, "You deactivated find monster event.");
	}
}
#endif
