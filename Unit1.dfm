object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'EasyMemo'
  ClientHeight = 363
  ClientWidth = 408
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = #12513#12452#12522#12458
  Font.Style = []
  OldCreateOrder = False
  StyleElements = [seFont, seClient]
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 24
  object Splitter1: TSplitter
    Left = 179
    Top = 25
    Height = 338
    MinSize = 100
    ExplicitLeft = 171
    ExplicitHeight = 400
  end
  object Memo1: TMemo
    Left = 182
    Top = 25
    Width = 226
    Height = 338
    Align = alClient
    ScrollBars = ssVertical
    TabOrder = 1
    WantTabs = True
    ExplicitHeight = 318
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 408
    Height = 25
    Align = alTop
    TabOrder = 0
    object Button2: TButton
      Left = 0
      Top = 1
      Width = 75
      Height = 25
      Caption = 'Delete'
      TabOrder = 0
      OnClick = Button2Click
    end
    object Button1: TButton
      Left = 257
      Top = 1
      Width = 75
      Height = 23
      Align = alRight
      Caption = 'Add'
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button3: TButton
      Left = 182
      Top = 1
      Width = 75
      Height = 23
      Align = alRight
      Caption = 'New'
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button5: TButton
      Left = 332
      Top = 1
      Width = 75
      Height = 23
      Align = alRight
      Caption = 'Update'
      Enabled = False
      TabOrder = 3
      OnClick = Button5Click
    end
  end
  object ListBox1: TListBox
    Left = 0
    Top = 25
    Width = 179
    Height = 338
    Align = alLeft
    ItemHeight = 24
    TabOrder = 2
    OnClick = ListBox1Click
    ExplicitHeight = 318
  end
  object ActionList1: TActionList
    Left = 312
    Top = 224
    object Action1: TAction
      Caption = 'Action1'
      ShortCut = 16462
      OnExecute = Action1Execute
    end
    object ActionSave: TAction
      Caption = 'ActionSave'
      ShortCut = 16467
      OnExecute = ActionSaveExecute
    end
  end
end
