object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'EasyMemo'
  ClientHeight = 343
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
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 24
  object Splitter1: TSplitter
    Left = 179
    Top = 25
    Height = 318
    MinSize = 100
    ExplicitLeft = 171
    ExplicitHeight = 400
  end
  object Memo1: TMemo
    Left = 182
    Top = 25
    Width = 226
    Height = 318
    Align = alClient
    ScrollBars = ssVertical
    TabOrder = 1
    WantTabs = True
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
    Height = 318
    Align = alLeft
    ItemHeight = 24
    TabOrder = 2
    OnClick = ListBox1Click
  end
  object ActionList1: TActionList
    Left = 312
    Top = 224
  end
end