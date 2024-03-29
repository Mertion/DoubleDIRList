
// SingleDirList_TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SingleDirList_Test.h"
#include "SingleDirList_TestDlg.h"
#include "afxdialogex.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSingleDirList_TestDlg 对话框



CSingleDirList_TestDlg::CSingleDirList_TestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSingleDirList_TestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);


	
}

void CSingleDirList_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSingleDirList_TestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CSingleDirList_TestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CSingleDirList_TestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSingleDirList_TestDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSingleDirList_TestDlg 消息处理程序

BOOL CSingleDirList_TestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSingleDirList_TestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSingleDirList_TestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSingleDirList_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSingleDirList_TestDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	int nSize = 0;

	

	int a[100];
	
	DoubleDIRListContainer.clear();

	if (DoubleDIRListContainer.GetIsEmpty())
	{
		AfxMessageBox(_T("List is empty !"));
	}
	else
	{
		AfxMessageBox(_T("List is not empty !"));
	}

	for (int i = 0; i < 100;i++)
	{
		a[i] = i;
		DoubleDIRListContainer.PushBack(a[i]);
		DoubleDIRListContainer.PushFront(a[i]);
	}
	
	CDoubleDIRListContainer<int>::iterator tmpPDoubleDIRList;
	tmpPDoubleDIRList = DoubleDIRListContainer.at(10);
	tmpPDoubleDIRList = DoubleDIRListContainer.GetBegin();
	tmpPDoubleDIRList = DoubleDIRListContainer.GetEnd();

	int nA = tmpPDoubleDIRList->GetData();
	nA = DoubleDIRListContainer.GetBegin()->GetData();
	while (!DoubleDIRListContainer.GetIsEmpty())
	{
		nSize = DoubleDIRListContainer.GetCount();
		DoubleDIRListContainer.PopBack();
		DoubleDIRListContainer.PopFront();
	}
	for (int i = 0; i < 100; i++)
	{
		a[i] = i;
		DoubleDIRListContainer.PushBack(a[i]);
		DoubleDIRListContainer.PushFront(a[i]);
	}
}


void CSingleDirList_TestDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	int nSize = 0;
	int a[100];

	DequeForListContainer.clear();
	if (DequeForListContainer.GetIsEmpty())
	{
		AfxMessageBox(_T("List is empty !"));
	}
	else
	{
		AfxMessageBox(_T("List is not empty !"));
		DequeForListContainer.pop_back();
		DequeForListContainer.pop_front();
	}
	
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
		DequeForListContainer.push_back(a[i]);
		DequeForListContainer.push_front(a[i]);
	}

	CDequeForListContainer<int>::iterator * tmpPDoubleDIRList;
	tmpPDoubleDIRList = DequeForListContainer.at(10);
	tmpPDoubleDIRList = DequeForListContainer.begin();
	tmpPDoubleDIRList = DequeForListContainer.end();

	CDequeForListContainer<int>::iterator tmplist;
	tmplist = DequeForListContainer.back();
	tmplist = DequeForListContainer.front();

	tmpPDoubleDIRList = tmplist.GetNext();
	tmpPDoubleDIRList = tmplist.GetPrevious();
}


void CSingleDirList_TestDlg::OnBnClickedButton2()
{
	// TODO:  指针链表应用示例
	int a;
	//初始化测试类及链表
	for (int i = 0; i < 10; i++)
	{
		m_arrCDequeForListContainer[i].setCardNumber(i);
		m_arrCDequeForListContainer[i].setStationNumber(i);

		m_DequedobleDirList.push_back(&m_arrCDequeForListContainer[i]);
		m_DobleDirList.PushBack(&m_arrCDequeForListContainer[i]);
	}

	CDequeForListContainer<CTestStation*>::iterator * tmpPDoubleDIRList;

	//Deque链表使用示例
	tmpPDoubleDIRList = m_DequedobleDirList.begin();
	do 
	{
		
		a = tmpPDoubleDIRList->GetData()->getCardNumber() ;
		a = tmpPDoubleDIRList->GetData()->getStationNumber();
		tmpPDoubleDIRList = tmpPDoubleDIRList->GetNext();
	} while (tmpPDoubleDIRList != m_DequedobleDirList.begin());

	tmpPDoubleDIRList = m_DequedobleDirList.at(5);
	a = tmpPDoubleDIRList->GetData()->getCardNumber();
	a = tmpPDoubleDIRList->GetData()->getStationNumber();

	tmpPDoubleDIRList = m_DequedobleDirList.end();
	a = tmpPDoubleDIRList->GetData()->getCardNumber();
	a = tmpPDoubleDIRList->GetData()->getStationNumber();
	m_DequedobleDirList.clear();
	//Deque链表使用示例结束

	//简易链表使用示例
	tmpPDoubleDIRList = m_DobleDirList.GetBegin();
	do
	{

		a = tmpPDoubleDIRList->GetData()->getCardNumber();
		a = tmpPDoubleDIRList->GetData()->getStationNumber();
		tmpPDoubleDIRList = tmpPDoubleDIRList->GetNext();
	} while (tmpPDoubleDIRList != m_DobleDirList.GetBegin());

	tmpPDoubleDIRList = m_DobleDirList.at(5);
	a = tmpPDoubleDIRList->GetData()->getCardNumber();
	a = tmpPDoubleDIRList->GetData()->getStationNumber();

	tmpPDoubleDIRList = m_DobleDirList.GetEnd();
	a = tmpPDoubleDIRList->GetData()->getCardNumber();
	a = tmpPDoubleDIRList->GetData()->getStationNumber();
	m_DobleDirList.clear();
	//简易链表使用示例结束
}
