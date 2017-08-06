object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'EasyMemo'
  ClientHeight = 383
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
    Height = 358
    MinSize = 100
    ExplicitLeft = 171
    ExplicitHeight = 400
  end
  object Memo1: TMemo
    Left = 182
    Top = 25
    Width = 226
    Height = 358
    Align = alClient
    ScrollBars = ssVertical
    TabOrder = 1
    WantTabs = True
    ExplicitLeft = 185
    ExplicitTop = 30
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 408
    Height = 25
    Align = alTop
    TabOrder = 0
    object Button2: TButton
      Left = 1
      Top = 1
      Width = 75
      Height = 23
      Align = alLeft
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
    object Button4: TButton
      Left = 76
      Top = 1
      Width = 33
      Height = 23
      Align = alLeft
      Caption = #8593
      TabOrder = 4
      OnClick = Button4Click
    end
    object Button6: TButton
      Left = 109
      Top = 1
      Width = 33
      Height = 23
      Align = alLeft
      Caption = #8595
      TabOrder = 5
      OnClick = Button6Click
    end
  end
  object ListBox1: TListBox
    Left = 0
    Top = 25
    Width = 179
    Height = 358
    Align = alLeft
    ItemHeight = 24
    PopupMenu = PopupMenu1
    TabOrder = 2
    OnClick = ListBox1Click
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
    object EditSelectAll1: TEditSelectAll
      Category = #32232#38598
      Caption = #12377#12409#12390#36984#25246'(&A)'
      Hint = #12377#12409#12390#36984#25246'|'#12489#12461#12517#12513#12531#12488#20840#20307#12434#36984#25246#12375#12414#12377
      ShortCut = 16449
    end
    object MoveTop: TAction
      Category = #32232#38598
      Caption = 'MoveTop'
      OnExecute = MoveTopExecute
    end
    object Action2: TAction
      Caption = 'Action2'
      ShortCut = 16472
      OnExecute = Action2Execute
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 112
    Top = 192
    object N1: TMenuItem
      Caption = #12450#12452#12486#12512#12434#21066#38500
      OnClick = N1Click
    end
    object N2: TMenuItem
      Action = MoveTop
      Caption = #12450#12452#12486#12512#12434#12488#12483#12503#12408#31227#21205
    end
    object N3: TMenuItem
      Caption = '-'
    end
    object N4: TMenuItem
      Caption = #12456#12463#12473#12509#12540#12488
      OnClick = N4Click
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 256
    Top = 192
  end
end
