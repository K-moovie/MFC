
// YHKimThreadDlg.h: 헤더 파일
//

#pragma once


// CYHKimThreadDlg 대화 상자
class CYHKimThreadDlg : public CDialogEx
{
// 생성입니다.
public:
	CYHKimThreadDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHKIMTHREAD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bWorkerPause1;
	BOOL m_bWorkerPause2;
	afx_msg void OnBnClickedButtOne();
	afx_msg void OnBnClickedButtTwo();
	afx_msg void OnBnClickedButtEixt();
	afx_msg void OnBnClickedCheckOne();
	afx_msg void OnBnClickedCheckTwo();
	static UINT ThreadWorker1(LPVOID pParam);
	static UINT ThreadWorker2(LPVOID pParam);   
	CWinThread *m_pWorkerThread1;
	CWinThread *m_pWorkerThread2; 
	UINT r1,r2;

};
