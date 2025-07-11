//Yoksa Ekle:

#	include "minigame.h"

//Arat:

		else if (name == "new_xmas_event")
		{
			// 20126 new»êÅ¸.
			static uint32_t new_santa = 20126;
			if (value != 0)

//Üstüme Ekle(!!!!!!!) :

#ifdef ENABLE_MINI_GAME_FINDM
		else if (name == "mini_game_findm_event")
		{
			CMiniGame::instance().InitializeMiniGameFindM(value);
		}
		else if (name == "findm_event_end_day")
		{
			CMiniGame::instance().InitializeMiniGameFindMEndTime(value);
		}
#endif

