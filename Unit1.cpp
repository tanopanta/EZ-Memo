//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
	UnicodeString fName = "aaa.txt";
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
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if(Memo1->Modified){
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
		UnicodeString fName = "aaa.txt";
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

	 if(Memo1->Modified == true){
		if(!(Memo1->Text == "")){
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
   if(!(Memo1->Text == "")){
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
	SaveFile();
}


void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if(Memo1->Modified){
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

