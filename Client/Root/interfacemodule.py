"//importlara ekle :"

if app.ENABLE_MINI_GAME_FINDM:
	import uiMiniGameFindM

"//Arat:"

		self.wndGuild								= None
		self.wndGuildBuilding						= None

"//Ekle :"

		if app.ENABLE_MINI_GAME_FINDM:
			self.wndFindMGame						= None

"//Arat:"

		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			self.wndDragonSoul.SetDragonSoulRefineWindow(self.wndDragonSoulRefine)
			self.wndDragonSoulRefine.SetInventoryWindows(self.wndInventory, self.wndDragonSoul)
			self.wndInventory.SetDragonSoulRefineWindow(self.wndDragonSoulRefine)

"//Ekle :"

		if app.ENABLE_MINI_GAME_FINDM:
			self.wndFindMGame						= uiMiniGameFindM.MiniGameFindM()

"//Arat:"

		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			self.wndDragonSoul.SetItemToolTip(self.tooltipItem)
			self.wndDragonSoulRefine.SetItemToolTip(self.tooltipItem)

"//Ekle :"

		if app.ENABLE_MINI_GAME_FINDM:
			self.wndFindMGame.SetItemToolTip(self.tooltipItem)

"//Arat:"

		if self.privateShopBuilder:
			self.privateShopBuilder.Hide()
			self.privateShopBuilder.Destroy()

"//Ekle :"

		if app.ENABLE_MINI_GAME_FINDM:
			if self.wndFindMGame:
				self.wndFindMGame.Hide()
				self.wndFindMGame.Destroy()

"//Arat:"

		del self.dlgExchange
		del self.dlgPointReset
		del self.dlgShop

"//Üstüne Ekle (!!!!!) :"

		if app.ENABLE_MINI_GAME_FINDM:
			if self.wndFindMGame:
				del self.wndFindMGame

"//Arat:"

	## Show & Hide
	def ShowDefaultWindows(self):
		self.wndTaskBar.Show()

"//Üstüme Ekle (!!!!!):"

	if app.ENABLE_MINI_GAME_FINDM:
		def MiniGameFindMEventStart(self, startTime, nextRevealTime):
			if self.wndFindMGame:
				self.wndFindMGame.GameStart(startTime, nextRevealTime)

		def MiniGameFindMClickCard(self, cardIndex, monsterVnum, revealFlag, nextRevealTime, tryCount):
			if self.wndFindMGame:
				self.wndFindMGame.ClickCard(cardIndex, monsterVnum, revealFlag, nextRevealTime, tryCount)

		def MiniGameFindMReward(self, rewardVnum):
			if self.wndFindMGame:
				self.wndFindMGame.RewardQuestion(rewardVnum)

		def MiniGameFindMUpgrade(self, rewardVnum, needMoney):
			if self.wndFindMGame:
				self.wndFindMGame.RewardUpgrade(rewardVnum, needMoney)

		def MiniGameFindMGameEnd(self):
			if self.wndFindMGame:
				self.wndFindMGame.GameEnd()

		if app.ENABLE_MINI_GAME_FINDM_HINT:
			def MiniGameFindMHintCount(self, hCount, nextRevealTime):
				if self.wndFindMGame:
					self.wndFindMGame.SetHintCount(hCount, nextRevealTime)

			def MiniGameFindMHint(self, cardIndex, monsterVnum):
				if self.wndFindMGame:
					self.wndFindMGame.AppendHint(cardIndex, monsterVnum)

		def ClickFindMonsterButton(self):
			if self.wndFindMGame:
				self.wndFindMGame.Open()

"//ARat:"

		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			hideWindows += self.wndDragonSoul,\
						self.wndDragonSoulRefine,

"//Ekle :"

		if app.ENABLE_MINI_GAME_FINDM:
			if self.wndFindMGame:
				hideWindows += self.wndFindMGame,

