"//En Alta Ekle :"

	if app.ENABLE_MINI_GAME_FINDM:
		def MiniGameFindMEventStart(self, startTime, nextRevealTime):
			self.interface.MiniGameFindMEventStart(startTime, nextRevealTime)

		def MiniGameFindMClickCard(self, cardIndex, monsterVnum, revealFlag, nextRevealTime, tryCount):
			self.interface.MiniGameFindMClickCard(cardIndex, monsterVnum, revealFlag, nextRevealTime, tryCount)

		def MiniGameFindMReward(self, rewardVnum):
			self.interface.MiniGameFindMReward(rewardVnum)

		def MiniGameFindMUpgrade(self, rewardVnum, needMoney):
			self.interface.MiniGameFindMUpgrade(rewardVnum, needMoney)

		def MiniGameFindMGameEnd(self):
			self.interface.MiniGameFindMGameEnd()

		if app.ENABLE_MINI_GAME_FINDM_HINT:
			def MiniGameFindMHintCount(self, hCount, nextRevealTime = 0):
				self.interface.MiniGameFindMHintCount(hCount, nextRevealTime)

			def MiniGameFindMHint(self, cardIndex, monsterVnum):
				self.interface.MiniGameFindMHint(cardIndex, monsterVnum)
