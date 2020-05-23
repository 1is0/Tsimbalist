object Form5: TForm5
  Left = 0
  Top = 0
  Caption = #1042#1074#1086#1076
  ClientHeight = 144
  ClientWidth = 203
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 23
    Width = 134
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1087#1086#1088#1090#1089#1084#1077#1085#1086#1074': '
  end
  object Amount: TEdit
    Left = 32
    Top = 55
    Width = 134
    Height = 21
    TabOrder = 0
    OnKeyPress = AmountKeyPress
  end
  object Button1: TButton
    Left = 64
    Top = 88
    Width = 75
    Height = 25
    Caption = #1042#1074#1077#1089#1090#1080
    TabOrder = 1
    OnClick = Button1Click
  end
end
