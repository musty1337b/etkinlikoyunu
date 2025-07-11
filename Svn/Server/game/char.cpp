//Yoksa Ekle:

#	include "minigame.h"

//Arat:

	m_iSyncHackCount = 0;

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
	m_vecFindMFieldCards.clear();
	wFindMTryCount = 0;
	bFindMGameStatus = false;
	dwFindMStartTime = 0;
	dwFindMNextReveal = 0;
	dwFindMRewardVnum = 0;
	dwFindMRewardCost = 0;
	iRevealedIndex[0] = -1;
	iRevealedIndex[1] = -1;
	m_revealEvent = nullptr;
#ifdef ENABLE_MINI_GAME_FINDM_HINT
	bFindMHintCount = 0;
#endif
#endif

//Arat:

	// MINING
	event_cancel(&m_pkMiningEvent);
	// END_OF_MINING

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
	event_cancel(&m_revealEvent);
#endif

//Bunu da En Alta Ekleyin

#ifdef ENABLE_MINI_GAME_FINDM
#include "minigame_manager.h"
EVENTFUNC(reveal_timer)
{
	const char_event_info* info = dynamic_cast<char_event_info*>(event->info);

	if (!info)
	{
		sys_err("<reveal_timer> <Factor> Null pointer");
		return 0;
	}

	LPCHARACTER ch = info->ch;

	if (!ch)
		return 0;

	if (!ch->GetDesc())
		return 0;

	const int iFirstCard = ch->iRevealedIndex[0];
	const int iSecondCard = ch->iRevealedIndex[1];
	uint8_t bPickNumber = 0;

	if (iFirstCard == -1 && iSecondCard == -1)
		bPickNumber = 3;
	else if (iFirstCard != -1 && iSecondCard == -1)
		bPickNumber = 2;
	else if (iFirstCard != -1 && iSecondCard != -1)
		bPickNumber = 1;

	while (bPickNumber > 0)
	{
		const int bCardIndex = CMiniGame::Instance().MiniGameFindMPickRandomCard(ch);
		if (bCardIndex == -1)
			return 0;

		const uint8_t bSkipFlag = (bPickNumber == 1) ? 2 : 1;
		CMiniGame::Instance().MiniGameFindMClickCard(ch, bCardIndex, bSkipFlag);
		bPickNumber--;
	}

	return PASSES_PER_SEC(FIND_M_REVEAL_TIME);
}

void CHARACTER::MiniGameFindMStartGame(std::vector<TFindMCard> cardsVector, uint32_t dwStartTime)
{
	m_vecFindMFieldCards = cardsVector;
	dwFindMStartTime = dwStartTime;
	wFindMTryCount = 0;
	bFindMGameStatus = true;
}

bool CHARACTER::MiniGameFindMIsAllRevealed()
{
	bool bIsAllRevealed = true;

	for (size_t i = 0; i < m_vecFindMFieldCards.size(); i++)
	{
		if (!m_vecFindMFieldCards[i].bIsRevealed)
		{
			bIsAllRevealed = false;
			break;
		}
	}

	return bIsAllRevealed;
}

void CHARACTER::MiniGameFindMStartReveal(int seconds)
{
	if (seconds == -1)
	{
		event_cancel(&m_revealEvent);
		dwFindMNextReveal = 0;
		return;
	}

	if (m_revealEvent)
		event_reset_time(m_revealEvent, PASSES_PER_SEC(seconds));
	else
	{
		char_event_info* info = AllocEventInfo<char_event_info>();
		info->ch = this;

		m_revealEvent = event_create(reveal_timer, info, PASSES_PER_SEC(seconds));
	}

	dwFindMNextReveal = time(0) + seconds;
}
#endif
