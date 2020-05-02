// StudentManageDlg.h : header file
//

#if !defined(AFX_STUDENTMANAGEDLG_H__583908AB_A755_40B1_B3AC_45BC27D43222__INCLUDED_)
#define AFX_STUDENTMANAGEDLG_H__583908AB_A755_40B1_B3AC_45BC27D43222__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStudentManageDlg dialog
#include "OperatorDB.h"
#include "ORACL.H"

class CStudentManageDlg : public CDialog
{
// Construction
public:
	CStudentManageDlg(CWnd* pParent = NULL);	// standard constructor
    int m_bign;
	int m_preLineBign;
// Dialog Data
	//{{AFX_DATA(CStudentManageDlg)
	enum { IDD = IDD_STUDENTMANAGE_DIALOG };
	CComboBox	m_com1;
	CListCtrl	m_wndList;
	CString m_strID;
	CString	m_editName;
	CString	m_editAge;
	CString	m_editAddress;
	CString	m_comboClass;

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStudentManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnQuery();
	afx_msg void OnBtnUpdate();
	afx_msg void OnBtnAdd();
	afx_msg void OnBtnDelete();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	afx_msg void OnItemclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    OperatorDB  m_operator;

	ODatabase   m_odatabase;
	//ODynaset    m_odynaset;
private:
	void InitClassCtrl();
	void EmptyCtrlData();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTMANAGEDLG_H__583908AB_A755_40B1_B3AC_45BC27D43222__INCLUDED_)
