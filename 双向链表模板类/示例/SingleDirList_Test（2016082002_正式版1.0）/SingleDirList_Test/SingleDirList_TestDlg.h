#pragma once
// SingleDirList_TestDlg.h : ͷ�ļ�
//
#include "DoubleDIRListContainer.h"
#include "DequeForListContainer.h"
#include "TestStation.h"

// CSingleDirList_TestDlg �Ի���
class CSingleDirList_TestDlg : public CDialogEx
{
// ����
public:
	CSingleDirList_TestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SINGLEDIRLIST_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

//������ȫ�ֱ���
public:
	CDoubleDIRListContainer<int> DoubleDIRListContainer;
	CDequeForListContainer<int> DequeForListContainer;


	CTestStation m_arrCDequeForListContainer[10];
	CDequeForListContainer<CTestStation *> m_DequedobleDirList;//deque����
	CDoubleDIRListContainer<CTestStation *> m_DobleDirList;//��������
public:
	afx_msg void OnBnClickedOk();

	
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
