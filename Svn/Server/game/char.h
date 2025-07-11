//Bunu Public Olarak Ekleyiniz.

#ifdef ENABLE_MINI_GAME_FINDM
public:
	void MiniGameFindMStartGame(std::vector<TFindMCard> cardsVector, uint32_t dwStartTime);

	bool MiniGameFindMGetGameStatus() const noexcept { return bFindMGameStatus; }
	void MiniGameFindMSetGameStatus(bool bStatus) noexcept { bFindMGameStatus = bStatus; }

	uint16_t MiniGameFindMGetTryCount() const noexcept { return wFindMTryCount; }
	void MiniGameFindMSetTryCount(uint16_t wCount) noexcept { wFindMTryCount = wCount; }

	uint32_t MiniGameFindMGetNextReveal() const noexcept { return dwFindMNextReveal; }
	uint32_t MiniGameFindMGetStartTime() const noexcept { return dwFindMStartTime; }

	uint32_t MiniGameFindMGetRewardVnum() const noexcept { return dwFindMRewardVnum; }
	void MiniGameFindMSetRewardVnum(uint32_t dwVnum) noexcept { dwFindMRewardVnum = dwVnum; }

	uint32_t MiniGameFindMGetRewardCost() const noexcept { return dwFindMRewardCost; }
	void MiniGameFindMSetRewardCost(uint32_t dwVnum) noexcept { dwFindMRewardCost = dwVnum; }

	void MiniGameFindMStartReveal(int seconds);
	bool MiniGameFindMIsAllRevealed();

	std::vector<TFindMCard> m_vecFindMFieldCards;
	int iRevealedIndex[2];

protected:
	uint16_t wFindMTryCount;
	bool bFindMGameStatus;
	uint32_t dwFindMStartTime;
	uint32_t dwFindMNextReveal;
	uint32_t dwFindMRewardVnum;
	uint32_t dwFindMRewardCost;
	LPEVENT m_revealEvent;

#ifdef ENABLE_MINI_GAME_FINDM_HINT
public:
	uint8_t MiniGameFindMGetHintCount() const noexcept { return bFindMHintCount; }
	void MiniGameFindMSetHintCount(uint8_t bCount) noexcept { bFindMHintCount = bCount; }

protected:
	uint8_t bFindMHintCount;
#endif
#endif // ENABLE_MINI_GAME_FINDM