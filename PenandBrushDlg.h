﻿
// PenandBrushDlg.h: 헤더 파일
//

#pragma once
#include "SJ_ListBox.h"

#pragma comment(lib, "SJ_ListBox.lib")

class MyColorListBox : public SJ_ListBox
{
public:
	void DrawUserItem(CDC* ap_dc, RECT* ap_rect, int a_index, void* ap_data, unsigned char a_select_flag, unsigned char a_focus_flag)
	{
		COLORREF color = GetItemData(a_index);
		CRect r(ap_rect->left + 2, ap_rect->top + 2, ap_rect->right - 2, ap_rect->bottom - 2);
		ap_dc->FillSolidRect(r, color);
	}


};

// CPenandBrushDlg 대화 상자
class CPenandBrushDlg : public CDialogEx
{
private:
	MyColorListBox m_color_list;
	COLORREF m_pen_color = RGB(0, 0, 0);
// 생성입니다.
public:
	CPenandBrushDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PENANDBRUSH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeColorList();
};
