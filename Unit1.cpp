//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <IOUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int lastSelect = -1;
bool inEditMode = false;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	UnicodeString fName = "EZ_Memo.txt";
	if(!(FileExists(fName))){
	   THandle fp = FileCreate(fName);
	   FileClose(fp);
	}

	TStringList *sList = new TStringList();
	try{
		sList->LoadFromFile(fName);
		for(int i = 0;i < sList->Count;i++){
			sList->Strings[i] = StringReplace(sList->Strings[i],"kvnewr","\r\n",TReplaceFlags()<<rfReplaceAll);
		}
		for(int i = 0;i < sList->Count;i++){
			ListBox1->Items->Add(sList->Strings[i]);
		}
	}__finally{
		delete sList;
	}

	if(ParamCount() > 0){
		Memo1->Lines->LoadFromFile(ParamStr(1));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(Memo1->Text == ""){
		return;
	}
	AddMemo(Memo1->Text);
	NewMemo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if(ListBox1->ItemIndex == -1){
		MessageDlgPos("リストから削除するアイテムを選択してください。",mtConfirmation, TMsgDlgButtons() << mbOK,0,Form1->Left + Form1->Width/4,Form1->Top + Form1->Height/3);
		return;
	}
	int res = MessageDlgPos("本当に削除しますか？",mtConfirmation, mbOKCancel ,0,Form1->Left + Form1->Width/4,Form1->Top + Form1->Height/3);
	if(res == mrOk){
	   ListBox1->Items->Delete(ListBox1->ItemIndex);
	   NewMemo();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if(!MemoKuhaku()){
		if(inEditMode){
			switch(MessageDlgPos("変更を上書きしますか？",mtConfirmation, mbYesNoCancel ,0,Form1->Left + Form1->Width/4,Form1->Top + Form1->Height/3)){
			case mrYes:
				ListBox1->Items->Strings[ListBox1->ItemIndex] = Memo1->Text;
				break;
			case mrNo:
				break;
			case mrCancel:
				return;
			}
		}else{
			switch(MessageDlgPos("変更を保存しますか？",mtConfirmation, mbYesNoCancel ,0,Form1->Left + Form1->Width/4,Form1->Top + Form1->Height/3)){
			case mrYes:
				AddMemo(Memo1->Text);
				break;
			case mrNo:
				break;
			case mrCancel:
				return;
			}
		}

	}
	NewMemo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	 SaveFile();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SaveFile()
{
	TStringList *sList = new TStringList();
	try{
		for(int i = 0;i < ListBox1->Items->Count;i++){
			sList->Add(ListBox1->Items->Strings[i]);
		}
		UnicodeString fName = "EZ_Memo.txt";
		for(int i = 0;i < sList->Count;i++){
			sList->Strings[i] = StringReplace(sList->Strings[i],"\r\n","kvnewr",TReplaceFlags()<<rfReplaceAll);
		}
		sList->SaveToFile(fName);
	}__finally{
		delete sList;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ListBox1Click(TObject *Sender)
{

	 if(ListBox1->ItemIndex == -1){
		return;
	 }

	 if(!MemoKuhaku()){
		if(inEditMode){
		   switch(MessageDlgPos("変更を上書きしますか？",mtConfirmation, mbYesNoCancel ,0,Form1->Left + Form1->Width/4,Form1->Top + Form1->Height/3)){
				case mrYes:
					ListBox1->Items->Strings[lastSelect] = Memo1->Text;
					break;
				case mrNo:
					break;
				case mrCancel:
					ListBox1->ItemIndex = lastSelect;
					return;
		   }
		}else{
			switch(MessageDlgPos("変更を保存しますか？",mtConfirmation, mbYesNoCancel ,0,Form1->Left + Form1->Width/4,Form1->Top + Form1->Height/3)){
				case mrYes:
					AddMemo(Memo1->Text);
					break;
				case mrNo:
					break;
				case mrCancel:
					return;
		   }
		}
	 }
	 Memo1->Text = ListBox1->Items->Strings[ListBox1->ItemIndex];
	 lastSelect = ListBox1->ItemIndex;
	 inEditMode = true;
	 Button5->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
    Memo1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
   if(!MemoKuhaku()){
	   switch(MessageDlgPos("変更を上書きしますか？",mtConfirmation, mbOKCancel ,0,Form1->Left + Form1->Width/4,Form1->Top + Form1->Height/3)){
			case mrOk:
				ListBox1->Items->Strings[ListBox1->ItemIndex] = Memo1->Text;
				NewMemo();
				break;
			case mrCancel:
				return;
	   }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NewMemo()
{
	Memo1->Text = "";
	ListBox1->ItemIndex = -1;
	Memo1->SetFocus();
	Button5->Enabled = false;
	inEditMode = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddMemo(UnicodeString s)
{
	ListBox1->Items->Insert(0,s);
	//SaveFile();
}


void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if(!MemoKuhaku()){
		if(inEditMode){
		   switch(MessageDlgPos("変更を上書きしますか？",mtConfirmation, mbYesNoCancel ,0,Form1->Left + Form1->Width/4,Form1->Top + Form1->Height/3)){
				case mrYes:
					ListBox1->Items->Strings[ListBox1->ItemIndex] = Memo1->Text;
					break;
				case mrNo:
					break;
				case mrCancel:
					CanClose = false;
					break;
		   }
	   }else{
			switch(MessageDlgPos("変更を保存しますか？",mtConfirmation, mbYesNoCancel ,0,Form1->Left + Form1->Width/4,Form1->Top + Form1->Height/3)){
				case mrYes:
					AddMemo(Memo1->Text);
					break;
				case mrNo:
					break;
				case mrCancel:
					CanClose = false;
					break;
		   }
	   }
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Action1Execute(TObject *Sender)
{
	Button3Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ActionSaveExecute(TObject *Sender)
{
	if(inEditMode){
	   Button5Click(Sender);
	}else{
       Button1Click(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
	Button2Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if(ListBox1->ItemIndex >= 1){
		ListBox1->Items->Exchange(ListBox1->ItemIndex - 1,ListBox1->ItemIndex);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	if(ListBox1->ItemIndex < ListBox1->Count - 1 && ListBox1->ItemIndex != -1){
		ListBox1->Items->Exchange(ListBox1->ItemIndex,ListBox1->ItemIndex+1);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MoveTopExecute(TObject *Sender)
{
	if(ListBox1->ItemIndex > 0){
		ListBox1->Items->Move(ListBox1->ItemIndex,0);
		ListBox1->ItemIndex = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Action2Execute(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N4Click(TObject *Sender)
{
	if(ListBox1->Items->Count <= 0){
		return;
	}
	int res = MessageDlgPos("メモの一覧をファイルにエクスポートしますか？",mtConfirmation, mbOKCancel ,0,Form1->Left + Form1->Width/4,Form1->Top + Form1->Height/3);
	if(res == mrOk){
        char buff[MAX_PATH];
		SHGetSpecialFolderPathA(HWND_DESKTOP, &buff[0], CSIDL_DESKTOP, FALSE);
		UnicodeString desktopPath = String(buff);
		desktopPath += "\\MemoExport";
		if(!(DirectoryExists(desktopPath))){
			if(!(CreateDir(desktopPath))){
			   ShowMessage(L"フォルダの作成に失敗しました。");
			   return;
			}
		}
		desktopPath += "\\";
		for(int i = 0;i < ListBox1->Items->Count;i++){
			UnicodeString str =  ListBox1->Items->Strings[i];
			int pos = str.Pos("\r");
			UnicodeString fName = IntToStr(i);
			if(pos > 0){
				fName += str.SubString(0,str.Pos("\r")-1);
			}else{
				fName += str;
			}
			if(!(Ioutils::TPath::HasValidFileNameChars(fName,false))){
				fName = IntToStr(i) + "MEMO";
			}
			try{
				TFile::WriteAllText(desktopPath + fName + ".txt",str,TEncoding::UTF8);
			}catch(...){
				ShowMessage(L"エクスポートに失敗しました。");
				return;
			}
		}
		ShowMessage(L"デスクトップにエクスポートしました。");
	}

}
//---------------------------------------------------------------------------
bool __fastcall TForm1::MemoKuhaku()
{
	return Memo1->Text.Trim() == "" || Memo1->Modified == false;
}
//---------------------------------------------------------------------------


