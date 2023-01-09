﻿
// PenandBrush.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "PenandBrush.h"
#include "PenandBrushDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPenandBrushApp

BEGIN_MESSAGE_MAP(CPenandBrushApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CPenandBrushApp 생성

CPenandBrushApp::CPenandBrushApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CPenandBrushApp 개체입니다.

CPenandBrushApp theApp;


// CPenandBrushApp 초기화

BOOL CPenandBrushApp::InitInstance()
{
	CWinApp::InitInstance();

	CPenandBrushDlg dlg;
	dlg.DoModal();
	
	return FALSE;
}

