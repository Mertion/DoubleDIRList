#pragma once
// SingleDirList_TestDlg.h : 头文件
//
#include "DoubleDIRListContainer.h"
#include "DequeForListContainer.h"
#include "TestStation.h"

// CSingleDirList_TestDlg 对话框
class CSingleDirList_TestDlg : public CDialogEx
{
// 构造
public:
	CSingleDirList_TestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SINGLEDIRLIST_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

//测试用全局变量
public:
	CDoubleDIRListContainer<int> DoubleDIRListContainer;
	CDequeForListContainer<int> DequeForListContainer;


	CTestStation m_arrCDequeForListContainer[10];
	CDequeForListContainer<CTestStation *> m_DequedobleDirList;//deque链表
	CDoubleDIRListContainer<CTestStation *> m_DobleDirList;//简易链表
public:
	afx_msg void OnBnClickedOk();

	
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
