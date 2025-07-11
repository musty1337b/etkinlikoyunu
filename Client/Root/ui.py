"Arat:"

class Window(object):
	def NoneMethod(cls):
		pass

	NoneMethod = classmethod(NoneMethod)

	def __init__(self, layer = "UI"):
		self.clickEvent = None
		self.hWnd = None
		self.parentWindow = 0
		self.onMouseLeftButtonUpEvent = None

		if app.ENABLE_MOUSEWHEEL_EVENT:
			self.onMouseWheelScrollEvent=None

		self.RegisterWindow(layer)
		self.Hide()

		if app.ENABLE_QUEST_RENEWAL:
			self.propertyList = {}

"Ekle :"

		if app.ENABLE_MINI_GAME_FINDM:
			self.onMouseLeftButtonUpEventArgs = None

"Aynı Class içinde Arat:"

	def __del__(self):
		wndMgr.Destroy(self.hWnd)

"Ekle :"

		if app.ENABLE_MINI_GAME_FINDM:
			self.onMouseLeftButtonUpEventArgs = None

"Aynı Class İçinde Arat veya Varsa Değiştir:"

	if app.ENABLE_MINI_GAME_FINDM:
		def SetOnMouseLeftButtonUpEvent(self, event, *args):
			self.onMouseLeftButtonUpEvent		= event
			self.onMouseLeftButtonUpEventArgs	= args
			
		def OnMouseLeftButtonUp(self):
			if self.onMouseLeftButtonUpEvent:
				apply( self.onMouseLeftButtonUpEvent, self.onMouseLeftButtonUpEventArgs )
	else:
		def SetOnMouseLeftButtonUpEvent(self, event):
			self.onMouseLeftButtonUpEvent = event
			
		def OnMouseLeftButtonUp(self):
			if self.onMouseLeftButtonUpEvent:
				self.onMouseLeftButtonUpEvent()
