﻿
// PenandBrushDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "PenandBrush.h"
#include "PenandBrushDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPenandBrushDlg 대화 상자



CPenandBrushDlg::CPenandBrushDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PENANDBRUSH_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPenandBrushDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPenandBrushDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_COLOR_LIST, &CPenandBrushDlg::OnLbnSelchangeColorList)
END_MESSAGE_MAP()


// CPenandBrushDlg 메시지 처리기

BOOL CPenandBrushDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// 표준 20가지 색상 목록
	COLORREF color_table[20] = {
		RGB(0,0,0), RGB(0,0,255), RGB(0,255,0), RGB(0,255,255), RGB(255,0,0), RGB(255,0,255),
		RGB(255,255,0), RGB(255,255,255), RGB(0,0,128), RGB(0,128,0), RGB(0,128,128),
		RGB(128,0,0), RGB(128,0,128), RGB(128,128,0), RGB(128,128,128), RGB(192,192,192),
		RGB(192,220,192), RGB(166,202,240), RGB(255,251,240), RGB(160,160,164)
	};

	m_color_list.SubclassDlgItem(IDC_COLOR_LIST, this);
	m_color_list.SetColumnWidth(20);
	m_color_list.SetItemHeight(0, 20);
	for (int i = 0; i < 20; i++)
	{
		m_color_list.InsertString(i, L""); // 문자열을 추가하지 않아도 이 구문을 써줘야 항목이 추가됨.
		m_color_list.SetItemData(i, color_table[i]);
	}

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPenandBrushDlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPen my_pen(PS_SOLID, 5, m_pen_color);
		CPen* p_old_pen = dc.SelectObject(&my_pen);
		
		dc.Rectangle(20, 20, 150, 150);
		dc.SelectObject(p_old_pen);
		my_pen.DeleteObject();
		// CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CPenandBrushDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPenandBrushDlg::OnLbnSelchangeColorList()
{
	int index = m_color_list.GetCurSel();
	if (LB_ERR != index)
	{
		m_pen_color = m_color_list.GetItemData(index);
		InvalidateRect(CRect(0, 0, 200, 200));
	}
}
