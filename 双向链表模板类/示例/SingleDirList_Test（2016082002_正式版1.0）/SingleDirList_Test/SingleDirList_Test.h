
// SingleDirList_Test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSingleDirList_TestApp: 
// �йش����ʵ�֣������ SingleDirList_Test.cpp
//

class CSingleDirList_TestApp : public CWinApp
{
public:
	CSingleDirList_TestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSingleDirList_TestApp theApp;