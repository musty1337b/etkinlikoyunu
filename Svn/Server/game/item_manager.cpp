//Arat:

	if (item->IsDragonSoul() && 0 == id)
	{
		DSManager::instance().DragonSoulItemInitialize(item);
	}

	return item;
}

//Üstüne Ekle(!!!!!) :

#ifdef ENABLE_MINI_GAME_FINDM
	if (item->GetVnum() == FIND_M_DROP_ITEM || item->GetVnum() == FIND_M_PLAY_ITEM)
	{
		if (quest::CQuestManager::Instance().GetEventFlag("mini_game_findm_event"))
		{
			int iEndTime = quest::CQuestManager::Instance().GetEventFlag("findm_event_end_day");
			if (iEndTime)
				item->SetSocket(0, iEndTime);
		}
	}
#endif



//Ayrıca Etkinlik Aktif Olduğunda void ITEM_MANAGER::CreateQuestDropItem içinde düşecek kart'ı ayarlayınız.

