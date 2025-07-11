//Eğer Yoksa Ekle :

#	include "minigame.h"

//Arat:

		case HEADER_CG_FISHING:
			Fishing(ch, c_pData);
			break;

		case HEADER_CG_HACK:
			Hack(ch, c_pData);
			break;

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
		case HEADER_CG_MINI_GAME_FIND_M:
			if ((iExtraLen = CMiniGame::instance().MiniGameFindM(ch, c_pData, m_iBufferLeft)) < 0)
				return -1;
			break;
#endif