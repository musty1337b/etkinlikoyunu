//Arat:

PyObject * netSetOfflinePhase(PyObject * poSelf, PyObject * poArgs)
{
	CPythonNetworkStream & rkNetStream = CPythonNetworkStream::Instance();
	rkNetStream.SetOffLinePhase();
	return Py_BuildNone();
}

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
PyObject* netSendMiniGameFindM(PyObject* poSelf, PyObject* poArgs)
{
	int iSubHeader;
	if (!PyTuple_GetInteger(poArgs, 0, &iSubHeader))
		return Py_BuildException();

	int iSubArgument;
	if (!PyTuple_GetInteger(poArgs, 1, &iSubArgument))
		return Py_BuildException();

	CPythonNetworkStream::Instance().SendMiniGameFindM(iSubHeader, iSubArgument);
	return Py_BuildNone();
}
#endif


//Arat:

	{"SetOfflinePhase", netSetOfflinePhase, METH_VARARGS},

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
		{ "SendMiniGameFindM",						netSendMiniGameFindM,						METH_VARARGS },
#endif

