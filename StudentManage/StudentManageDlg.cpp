// StudentManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StudentManage.h"
#include "StudentManageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

#include "AdoRecordset.h"

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentManageDlg dialog

CStudentManageDlg::CStudentManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentManageDlg)
	m_editName = _T("");
	m_editAge = _T("");
	m_editAddress = _T("");
	m_comboClass = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_operator.OpenDataSource();
}

void CStudentManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentManageDlg)
	DDX_Control(pDX, IDC_COMBO1, m_com1);
	DDX_Control(pDX, IDC_LIST1, m_wndList);
	DDX_Text(pDX, IDC_EDIT1, m_editName);
	DDX_Text(pDX, IDC_EDIT3, m_editAge);
	DDX_Text(pDX, IDC_EDIT4, m_editAddress);
	DDX_CBString(pDX, IDC_COMBO1, m_comboClass);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStudentManageDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentManageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_QUERY, OnBtnQuery)
	ON_BN_CLICKED(IDC_BTN_UPDATE, OnBtnUpdate)
	ON_BN_CLICKED(IDC_BTN_ADD, OnBtnAdd)
	ON_BN_CLICKED(IDC_BTN_DELETE, OnBtnDelete)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_WM_CLOSE()
	ON_NOTIFY(HDN_ITEMCLICK, IDC_LIST1, OnItemclickList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_WM_SHOWWINDOW()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentManageDlg message handlers

BOOL CStudentManageDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	
	
	// TODO: Add extra initialization here
	m_com1.AddString("请选择");
    m_com1.SetCurSel(0);

	//m_bign = 0;
	//m_preLineBign = 1;

	m_wndList.DeleteAllItems();
	while(m_wndList.DeleteColumn(0));
	m_wndList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	OStartup();
	m_odatabase.Open("ORCL_127.0.0.1","TEST","c123456");
	InitClassCtrl();

	OnBtnQuery();

	//SetTimer(1,500,NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStudentManageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStudentManageDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStudentManageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStudentManageDlg::OnBtnQuery() 
{
	// TODO: Add your control notification handler code here
   // if(m_bign ==0)
   //		return ;
	// 表示用户刚才选了一行，此时改行不是用户查询的内容，应该清空编辑框。然后在显示所有内容
	if(m_preLineBign ==1)
	{
		m_preLineBign = 0;
        EmptyCtrlData();
	}

	UpdateData(TRUE);

	m_wndList.DeleteAllItems();
	while(m_wndList.DeleteColumn(0));

	//CAdoRecordset set;
    ODynaset  set;
	CString strName,strAge,strAddress;
	CString strSql;
	int  nClass,nAge;
	CString strClass;
	strSql = "select student1.Id as 编号,student1.SName as 姓名, student1.Age as 年龄,student1.Address as 地址, \
		class.CName as 班级 from student1,class where class.ID = student1.CID";


	CString strID;
	CString strClassName;


	strSql = "select student1.Id as 编号,student1.SName as 姓名, student1.Age as 年龄,student1.Address as 地址, \
		class.CName as 班级 from student1,class where class.ID = student1.CID";
	set.Open(m_odatabase,strSql);

	int nCount = set.GetFieldCount();
	for(int i=0;i<nCount;i++)
	{
		//set.GetFiledName(i,strName);
		strName = (CString)(set.GetFieldName(i));
		// f_ofield = set.GetField(i);
		m_wndList.InsertColumn(i,strName,LVCFMT_LEFT,85);
	}


    nClass = m_com1.GetCurSel();
	if(nClass >0)
    {
		strClass.Format("  and class.id = %d",nClass);	 
        strSql += strClass;
	}
	if(!m_editName.IsEmpty())
	{
        strName.Format("  and student1.SName = '%s' ",m_editName);
		strSql += strName;
	}

	if(!m_editAge.IsEmpty())
	{
	 	nAge = atoi(m_editAge);
        strAge.Format("  and student1.Age = %d",nAge);
		strSql += strAge;
	}

	if(!m_editAddress.IsEmpty())
	{
        strAddress.Format("  and student1.Address = '%s' ",m_editAddress);
		strSql += strAddress;
	}

	// set.OpenSql(strSql,&m_operator);
	set.Open(m_odatabase,strSql);

	CString strValue;
	OValue  f_ovalue;
	int nItem = 0;
	if(!set.IsBOF())
	{
		set.MoveFirst();
	}
	while(!set.IsEOF())
	{
		int nCount = set.GetFieldCount();
		for(int i=0;i<nCount;i++)
		{
			set.GetFieldValue(i,&f_ovalue);
			strValue = (CString)f_ovalue;
			if(0 == i)
			{
				m_wndList.InsertItem(nItem,strValue);
			}
			else
			{
				m_wndList.SetItemText(nItem,i,strValue);
			}
		}
		nItem++;
		set.MoveNext();
	}
}

void CStudentManageDlg::OnBtnUpdate() 
{
	// TODO: Add your control notification handler code here

	if(m_bign == 0)
		return;

	int nNum = 0;
	CString str ;
	DWORD ClassID;
	UpdateData(TRUE);
	if( m_editName.IsEmpty() ||  m_editAge.IsEmpty() || m_editAddress.IsEmpty())
	{
		MessageBox("请双击选中一行!");
		return ;
	}
	nNum = m_com1.GetCurSel();
	if(nNum == 0)
	{
		MessageBox("请选择班级!");
		return;
	}

    str.Format("Update student1 set SName ='%s',Age = %s,Address='%s',CID=%d where ID = %s",m_editName,m_editAge,m_editAddress,nNum,m_strID);
    m_odatabase.ExecuteSQL(str);
	EmptyCtrlData();
	OnBtnQuery();

	MessageBox("更新数据成功!");
}

void CStudentManageDlg::OnBtnAdd() 
{
	// TODO: Add your control notification handler code here
	//if(m_bign == 0)
	//	return;

	int nNum = 0;
	int ntest = 0;
	DWORD f_ClassId;
	CString str;
    UpdateData(TRUE);
	if(m_editName.IsEmpty() || m_editAge.IsEmpty() || m_editAddress.IsEmpty())
	{
		MessageBox("请输入姓名、年龄或地址!");
		return ;
	}
    
	if((nNum = m_com1.GetCurSel()) == 0)
	{
        MessageBox("请选择要增加的班级!");
		return;
	}
    nNum = m_com1.GetCurSel();

	str.Format("insert into student1 (id,SName,Age,Address,CID) values(for_test.nextval,'%s',%s,'%s',%d)",m_editName,m_editAge,m_editAddress,nNum);
	
    //m_operator.HandOperator(str);

	m_odatabase.ExecuteSQL(str);
    EmptyCtrlData();
    OnBtnQuery();

	MessageBox("添加数据成功!");
}

void CStudentManageDlg::OnBtnDelete() 
{
	// TODO: Add your control notification handler code here

	CString strSql;
	POSITION pos = m_wndList.GetFirstSelectedItemPosition();
	if(pos == NULL)
	{
        MessageBox("请选择要删除的内容!");
		return;
	}

	if( IDNO == MessageBox("确定要删除吗!","警告",MB_YESNO))
	{
		return;
	}

	int nItem = m_wndList.GetNextSelectedItem(pos);
	CString strID;
	strID = m_wndList.GetItemText(nItem,0);
	strSql.Format("delete from student1 where id = %s",strID);


	//strSql.Format("delete from student1 where id = %d ", );
    m_odatabase.ExecuteSQL(strSql);
	EmptyCtrlData();
	OnBtnQuery();

	MessageBox("删除数据成功!");
}

void CStudentManageDlg::OnItemclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	// TODO: Add your control notification handler code here
	
// 	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
// 	int nItem = pNMItemActivate->iItem;
// 	if(nItem == -1) return;
// 	
//     m_strID = m_wndList.GetItemText(nItem,0);
// 	m_editName = m_wndList.GetItemText(nItem,1);
// 	m_editAge = m_wndList.GetItemText(nItem,2);
// 	m_editAddress = m_wndList.GetItemText(nItem,3);
// 	m_comboClass = m_wndList.GetItemText(nItem,4);
// 	
// 	UpdateData(FALSE);



	*pResult = 0;
}


void CStudentManageDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	int nItem = pNMItemActivate->iItem;
	if(nItem == -1) return;
	
    m_strID = m_wndList.GetItemText(nItem,0);
	m_editName = m_wndList.GetItemText(nItem,1);
	m_editAge = m_wndList.GetItemText(nItem,2);
	m_editAddress = m_wndList.GetItemText(nItem,3);
	m_comboClass = m_wndList.GetItemText(nItem,4);
	
	UpdateData(FALSE);
	*pResult = 0;
}


void CStudentManageDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	int nItem = pNMItemActivate->iItem;
	if(nItem == -1) return;

    m_strID = m_wndList.GetItemText(nItem,0);
	m_editName = m_wndList.GetItemText(nItem,1);
	m_editAge = m_wndList.GetItemText(nItem,2);
	m_editAddress = m_wndList.GetItemText(nItem,3);
	m_comboClass = m_wndList.GetItemText(nItem,4);

	UpdateData(FALSE);

	*pResult = 0;
}

void CStudentManageDlg::InitClassCtrl()
{
    // 定义一个记录集对象

	ODynaset  set;
	// CAdoRecordset set;
	CString strValue;
	CString strSql;
	strSql = "select ID,CName from Class";
    int val =0;
	OValue  f_ovalue;
	// set.OpenSql(strSql,&m_operator);
	set.Open(m_odatabase,strSql);

	CString strID;
	CString strClassName;
	while(!set.IsEOF())
	{
        //set.GetFileValue(0,strID);
		set.GetFieldValue(0,&val);
		set.GetFieldValue(1,&f_ovalue);
		strClassName = (CString)f_ovalue;
		//set.GetFileValue(1,strClassName);
		int nIndex = m_com1.AddString(strClassName);
		//m_com1.SetItemData(nIndex,atoi(strID));
		set.MoveNext();
	}
}


void CStudentManageDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	m_odatabase.Close();
	//m_operator.CloseDataSource();
	//KillTimer(1);
	CDialog::OnClose();
}

void CStudentManageDlg::EmptyCtrlData()
{
     CString str = _T("");
	 SetDlgItemText(IDC_EDIT1,str);
	 SetDlgItemText(IDC_EDIT3,str);
	 SetDlgItemText(IDC_EDIT4,str);
	 m_com1.SetCurSel(0);
}


void CStudentManageDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
}

void CStudentManageDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	//连接逻辑
    static int nNum = 0;

    if(nNum == 0)
	{
       nNum = m_operator.OpenDataSource();
	   InitClassCtrl();
	   m_bign = 1;
	   KillTimer(1);
	}
	
	CDialog::OnTimer(nIDEvent);
}


