//Yoksa Ekle:

#	include "minigame.h"

//Arat:

	ALUA(game_get_safebox_level)
	{
		CQuestManager& q = CQuestManager::Instance();
		lua_pushnumber(L, q.GetCurrentCharacterPtr()->GetSafeboxSize()/SAFEBOX_PAGE_SIZE);
		return 1;
	}

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
	ALUA(mini_game_find_m_get_score)
	{
		uint32_t dwArg = (uint32_t)lua_tonumber(L, 1);
		bool isTry = dwArg ? true : false;

		CMiniGame::instance().MiniGameFindMGetScore(L, isTry);
		return 1;
	}
#endif

//Arat:

	void RegisterGameFunctionTable()
	{
		luaL_reg game_functions[] =
		{
			{ "get_safebox_level",			game_get_safebox_level			},

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
			{ "mini_game_find_m_get_score",	mini_game_find_m_get_score		},
#endif
