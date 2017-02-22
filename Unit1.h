//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TMemo *Memo1;
	TListBox *ListBox1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TPanel *Panel1;
	TSplitter *Splitter1;
	TButton *Button5;
	TActionList *ActionList1;
	TAction *Action1;
	TAction *ActionSave;
	TEditSelectAll *EditSelectAll1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TButton *Button4;
	TButton *Button6;
	TAction *MoveTop;
	TMenuItem *N2;
	TAction *Action2;
	TMenuItem *N3;
	TMenuItem *N4;
	TSaveDialog *SaveDialog1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall Action1Execute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall MoveTopExecute(TObject *Sender);
	void __fastcall Action2Execute(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
	void __fastcall SaveFile();
	void __fastcall NewMemo();
    void __fastcall AddMemo(UnicodeString s);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
