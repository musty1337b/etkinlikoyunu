//ARat:

		if ((item2 = GetItem(DestCell)) && item != item2 && item2->IsStackable() &&
			!IS_SET(item2->GetAntiFlag(), ITEM_ANTIFLAG_STACK) &&
			item2->GetVnum() == item->GetVnum() && !item2->IsExchanging()) //@fixme444	- For items that can be combined
		{
			for (int i = 0; i < ITEM_SOCKET_MAX_NUM; ++i)
			{
				if (item2->GetSocket(i) != item->GetSocket(i))
					return false;
			}

			if (count == 0)
				count = item->GetCount();

			sys_log(0, "%s: ITEM_STACK %s (window: %d, cell : %d) -> (window:%d, cell %d) count %d", GetName(), item->GetName(), Cell.window_type, Cell.cell,
				DestCell.window_type, DestCell.cell, count);

			count = MIN(g_bItemCountLimit - item2->GetCount(), count);

			item->SetCount(item->GetCount() - count);
			item2->SetCount(item2->GetCount() + count);

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
			if (item2->GetVnum() == FIND_M_DROP_ITEM && item2->GetCount() >= 27)
			{
				const LPITEM& MemoSet = AutoGiveItem(FIND_M_PLAY_ITEM);
				if (MemoSet != nullptr)
					item2->SetCount(item2->GetCount() - 27);
			}
#endif

//Arat:

			else
			{
				if (item->IsStackable() && !IS_SET(item->GetAntiFlag(), ITEM_ANTIFLAG_STACK))
				{
					uint8_t bCount = item->GetCount();

					//@fixme414
					for (uint16_t i = BELT_INVENTORY_SLOT_START; i < BELT_INVENTORY_SLOT_END; ++i)
					{
						LPITEM item2 = GetInventoryItem(i);

						if (!item2)
							continue;

						if (item2->GetVnum() == item->GetVnum())
						{
							int j;

							for (j = 0; j < ITEM_SOCKET_MAX_NUM; ++j)
							{
								if (item2->GetSocket(j) != item->GetSocket(j))
									break;
							}

							if (j != ITEM_SOCKET_MAX_NUM)
								continue;

							const uint8_t bCount2 = MIN(g_bItemCountLimit - item2->GetCount(), bCount);
							bCount -= bCount2;

							item2->SetCount(item2->GetCount() + bCount2);

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
							if (item2->GetVnum() == FIND_M_DROP_ITEM && item2->GetCount() >= 27)
							{
								const LPITEM& MemoSet = AutoGiveItem(FIND_M_PLAY_ITEM);
								if (MemoSet != nullptr)
									item2->SetCount(item2->GetCount() - 27);
							}
#endif

//Arat:

			int iEmptyCell = -1;

			//@fixme418
			if (owner)
			{
				if (item->IsStackable() && !IS_SET(item->GetAntiFlag(), ITEM_ANTIFLAG_STACK))
				{
					uint8_t bCount = item->GetCount();

					for (int i = 0; i < INVENTORY_MAX_NUM; ++i)
					{
						LPITEM item2 = owner->GetInventoryItem(i);

						if (!item2)
							continue;

						if (item2->GetVnum() == item->GetVnum())
						{
							int j;

							for (j = 0; j < ITEM_SOCKET_MAX_NUM; ++j)
							{
								if (item2->GetSocket(j) != item->GetSocket(j))
									break;
							}

							if (j != ITEM_SOCKET_MAX_NUM)
								continue;

							const uint8_t bCount2 = MIN(g_bItemCountLimit - item2->GetCount(), bCount);
							bCount -= bCount2;

							item2->SetCount(item2->GetCount() + bCount2);

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
							if (item2->GetVnum() == FIND_M_DROP_ITEM && item2->GetCount() >= 27)
							{
								const LPITEM& MemoSet = AutoGiveItem(FIND_M_PLAY_ITEM);
								if (MemoSet != nullptr)
									item2->SetCount(item2->GetCount() - 27);
							}
#endif