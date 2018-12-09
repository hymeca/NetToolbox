#ifndef __UICONTROL_H__
#define __UICONTROL_H__

#pragma once

namespace DuiLib {

	/////////////////////////////////////////////////////////////////////////////////////
	//

	typedef CControlUI* (CALLBACK* FINDCONTROLPROC)(CControlUI*, LPVOID);

	class UILIB_API CControlUI {
		DECLARE_DUICONTROL (CControlUI)
	public:
		CControlUI ();
		virtual ~CControlUI ();

	public:
		virtual string_view_t GetName () const;
		virtual void SetName (string_view_t pstrName);
		virtual string_view_t GetClass () const;
		virtual LPVOID GetInterface (string_view_t pstrName);
		virtual UINT GetControlFlags () const;

		virtual bool Activate ();
		virtual CPaintManagerUI* GetManager () const;
		virtual void SetManager (CPaintManagerUI* pManager, CControlUI* pParent, bool bInit = true);
		virtual CControlUI* GetParent () const;
		void setInstance (HINSTANCE instance) { m_instance = instance; };

		// ��ʱ��
		bool SetTimer (UINT nTimerID, UINT nElapse);
		void KillTimer (UINT nTimerID);

		// �ı����
		virtual CDuiString GetText () const;
		virtual void SetText (string_view_t pstrText);

		virtual bool IsResourceText () const;
		virtual void SetResourceText (bool bResource);

		virtual bool IsDragEnabled () const;
		virtual void SetDragEnable (bool bDrag);

		virtual bool IsDropEnabled () const;
		virtual void SetDropEnable (bool bDrop);

		// ͼ�����
		string_view_t GetGradient ();
		void SetGradient (string_view_t pStrImage);
		DWORD GetBkColor () const;
		void SetBkColor (DWORD dwBackColor);
		DWORD GetBkColor2 () const;
		void SetBkColor2 (DWORD dwBackColor);
		DWORD GetBkColor3 () const;
		void SetBkColor3 (DWORD dwBackColor);
		DWORD GetForeColor () const;
		void SetForeColor (DWORD dwForeColor);
		string_view_t GetBkImage ();
		void SetBkImage (string_view_t pStrImage);
		string_view_t GetForeImage () const;
		void SetForeImage (string_view_t pStrImage);

		DWORD GetFocusBorderColor () const;
		void SetFocusBorderColor (DWORD dwBorderColor);
		bool IsColorHSL () const;
		void SetColorHSL (bool bColorHSL);
		SIZE GetBorderRound () const;
		void SetBorderRound (SIZE cxyRound);
		bool DrawImage (HDC hDC, string_view_t pStrImage, string_view_t pStrModify = _T (""));

		//�߿����
		int GetBorderSize () const;
		void SetBorderSize (int nSize);
		DWORD GetBorderColor () const;
		void SetBorderColor (DWORD dwBorderColor);
		void SetBorderSize (RECT rc);
		int GetLeftBorderSize () const;
		void SetLeftBorderSize (int nSize);
		int GetTopBorderSize () const;
		void SetTopBorderSize (int nSize);
		int GetRightBorderSize () const;
		void SetRightBorderSize (int nSize);
		int GetBottomBorderSize () const;
		void SetBottomBorderSize (int nSize);
		int GetBorderStyle () const;
		void SetBorderStyle (int nStyle);

		// λ�����
		virtual RECT GetRelativePos () const; // ���(���ؼ�)λ��
		virtual RECT GetClientPos () const; // �ͻ����򣨳�ȥscrollbar��inset��
		virtual const RECT& GetPos () const;
		virtual void SetPos (RECT rc, bool bNeedInvalidate = true);
		virtual void Move (SIZE szOffset, bool bNeedInvalidate = true);
		virtual int GetWidth () const;
		virtual int GetHeight () const;
		virtual int GetX () const;
		virtual int GetY () const;
		virtual RECT GetPadding () const;
		virtual void SetPadding (RECT rcPadding); // ������߾࣬���ϲ㴰�ڻ���
		virtual SIZE GetFixedXY () const;         // ʵ�ʴ�Сλ��ʹ��GetPos��ȡ������õ�����Ԥ��Ĳο�ֵ
		virtual void SetFixedXY (SIZE szXY);      // ��floatΪtrueʱ��Ч
		virtual int GetFixedWidth () const;       // ʵ�ʴ�Сλ��ʹ��GetPos��ȡ������õ�����Ԥ��Ĳο�ֵ
		virtual void SetFixedWidth (int cx);      // Ԥ��Ĳο�ֵ
		virtual int GetFixedHeight () const;      // ʵ�ʴ�Сλ��ʹ��GetPos��ȡ������õ�����Ԥ��Ĳο�ֵ
		virtual void SetFixedHeight (int cy);     // Ԥ��Ĳο�ֵ
		virtual int GetMinWidth () const;
		virtual void SetMinWidth (int cx);
		virtual int GetMaxWidth () const;
		virtual void SetMaxWidth (int cx);
		virtual int GetMinHeight () const;
		virtual void SetMinHeight (int cy);
		virtual int GetMaxHeight () const;
		virtual void SetMaxHeight (int cy);
		virtual TPercentInfo GetFloatPercent () const;
		virtual void SetFloatPercent (TPercentInfo piFloatPercent);
		virtual void SetFloatAlign (UINT uAlign);
		virtual UINT GetFloatAlign () const;
		// �����ʾ
		virtual CDuiString GetToolTip () const;
		virtual void SetToolTip (string_view_t pstrText);
		virtual void SetToolTipWidth (int nWidth);
		virtual int GetToolTipWidth (void);	// ����ToolTip���������

		// ���
		virtual WORD GetCursor ();
		virtual void SetCursor (WORD wCursor);

		// ��ݼ�
		virtual TCHAR GetShortcut () const;
		virtual void SetShortcut (TCHAR ch);

		// �˵�
		virtual bool IsContextMenuUsed () const;
		virtual void SetContextMenuUsed (bool bMenuUsed);

		// �û�����
		virtual const CDuiString& GetUserData (); // �������������û�ʹ��
		virtual void SetUserData (string_view_t pstrText); // �������������û�ʹ��
		virtual UINT_PTR GetTag () const; // �������������û�ʹ��
		virtual void SetTag (UINT_PTR pTag); // �������������û�ʹ��

		// һЩ��Ҫ������
		virtual bool IsVisible () const;
		virtual void SetVisible (bool bVisible = true);
		virtual void SetInternVisible (bool bVisible = true); // �����ڲ����ã���ЩUIӵ�д��ھ������Ҫ��д�˺���
		virtual bool IsEnabled () const;
		virtual void SetEnabled (bool bEnable = true);
		virtual bool IsMouseEnabled () const;
		virtual void SetMouseEnabled (bool bEnable = true);
		virtual bool IsKeyboardEnabled () const;
		virtual void SetKeyboardEnabled (bool bEnable = true);
		virtual bool IsFocused () const;
		virtual void SetFocus ();
		virtual bool IsFloat () const;
		virtual void SetFloat (bool bFloat = true);
		virtual bool IsDynamic (POINT &pt) const;
		virtual void SetIsDynamic (bool bIsDynamic = true);

		virtual CControlUI* FindControl (FINDCONTROLPROC Proc, LPVOID pData, UINT uFlags);

		void Invalidate ();
		bool IsUpdateNeeded () const;
		void NeedUpdate ();
		void NeedParentUpdate ();
		DWORD GetAdjustColor (DWORD dwColor);

		virtual void Init ();
		virtual void DoInit ();

		virtual void Event (TEventUI& event);
		virtual void DoEvent (TEventUI& event);

		// �Զ���(δ������)����
		void AddCustomAttribute (string_view_t pstrName, string_view_t pstrAttr);
		string_view_t GetCustomAttribute (string_view_t pstrName);
		bool RemoveCustomAttribute (string_view_t pstrName);
		void RemoveAllCustomAttribute ();

		virtual void SetAttribute (string_view_t pstrName, string_view_t pstrValue);
		CControlUI* ApplyAttributeList (string_view_t pstrList);

		virtual SIZE EstimateSize (SIZE szAvailable);
		virtual bool Paint (HDC hDC, const RECT& rcPaint, CControlUI* pStopControl = nullptr); // ����Ҫ��Ҫ��������
		virtual bool DoPaint (HDC hDC, const RECT& rcPaint, CControlUI* pStopControl);
		virtual void PaintBkColor (HDC hDC);
		virtual void PaintBkImage (HDC hDC);
		virtual void PaintStatusImage (HDC hDC);
		virtual void PaintForeColor (HDC hDC);
		virtual void PaintForeImage (HDC hDC);
		virtual void PaintText (HDC hDC);
		virtual void PaintBorder (HDC hDC);

		virtual void DoPostPaint (HDC hDC, const RECT& rcPaint);

		//���ⴰ�ڲ���
		void SetVirtualWnd (string_view_t pstrValue);
		CDuiString GetVirtualWnd () const;

	public:
		CEventSource		OnInit;
		CEventSource		OnDestroy;
		CEventSource		OnSize;
		CEventSource		OnEvent;
		CEventSource		OnNotify;

	protected:
		CPaintManagerUI		*m_pManager				= nullptr;
		CControlUI			*m_pParent				= nullptr;
		CDuiString			m_sVirtualWnd;
		CDuiString			m_sName;
		bool				m_bUpdateNeeded			= true;
		bool				m_bMenuUsed				= false;
		RECT				m_rcItem;
		RECT				m_rcPadding;
		SIZE				m_cXY;
		SIZE				m_cxyFixed;
		SIZE				m_cxyMin;
		SIZE				m_cxyMax;
		bool				m_bVisible				= true;
		bool				m_bInternVisible		= true;
		bool				m_bEnabled				= true;
		bool				m_bMouseEnabled			= true;
		bool				m_bKeyboardEnabled		= true;
		bool				m_bFocused				= false;
		bool				m_bFloat				= false;
		TPercentInfo		m_piFloatPercent;
		UINT				m_uFloatAlign			= DT_LEFT;
		bool				m_bSetPos				= false; // ��ֹSetPosѭ������

		bool				m_bDragEnabled			= false;
		bool				m_bDropEnabled			= false;

		bool				m_bResourceText			= false;
		CDuiString			m_sText;
		CDuiString			m_sToolTip;
		TCHAR				m_chShortcut			= _T ('\0');
		CDuiString			m_sUserData;
		UINT_PTR			m_pTag					= NULL;

		CDuiString			m_sGradient;
		DWORD				m_dwBackColor			= 0;
		DWORD				m_dwBackColor2			= 0;
		DWORD				m_dwBackColor3			= 0;
		DWORD				m_dwForeColor			= 0;
		CDuiString			m_sBkImage;
		CDuiString			m_sForeImage;
		DWORD				m_dwBorderColor			= 0;
		DWORD				m_dwFocusBorderColor	= 0;
		bool				m_bColorHSL				= false;
		int					m_nBorderSize			= 0;
		int					m_nBorderStyle			= PS_SOLID;
		int					m_nTooltipWidth			= 300;
		WORD				m_wCursor				= 0;
		SIZE				m_cxyBorderRound;
		RECT				m_rcPaint;
		RECT				m_rcBorderSize;
		bool				m_isDynamic				= false;
		HINSTANCE			m_instance				= NULL;

		std::map<string_t, string_t>	m_mCustomAttrs;
	};

} // namespace DuiLib

#endif // __UICONTROL_H__