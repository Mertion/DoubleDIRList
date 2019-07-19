
// SingleDirList_TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SingleDirList_Test.h"
#include "SingleDirList_TestDlg.h"
#include "afxdialogex.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CSingleDirList_TestDlg �Ի���



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


// CSingleDirList_TestDlg ��Ϣ�������

BOOL CSingleDirList_TestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSingleDirList_TestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSingleDirList_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSingleDirList_TestDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  ָ������Ӧ��ʾ��
	int a;
	//��ʼ�������༰����
	for (int i = 0; i < 10; i++)
	{
		m_arrCDequeForListContainer[i].setCardNumber(i);
		m_arrCDequeForListContainer[i].setStationNumber(i);

		m_DequedobleDirList.push_back(&m_arrCDequeForListContainer[i]);
		m_DobleDirList.PushBack(&m_arrCDequeForListContainer[i]);
	}

	CDequeForListContainer<CTestStation*>::iterator * tmpPDoubleDIRList;

	//Deque����ʹ��ʾ��
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
	//Deque����ʹ��ʾ������

	//��������ʹ��ʾ��
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
	//��������ʹ��ʾ������
}
