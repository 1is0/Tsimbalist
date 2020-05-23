object Form6: TForm6
  Left = 0
  Top = 0
  Caption = 'Form6'
  ClientHeight = 392
  ClientWidth = 549
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 272
    Top = 24
    Width = 257
    Height = 225
    TabOrder = 0
  end
  object CopyButton: TButton
    Left = 40
    Top = 24
    Width = 145
    Height = 25
    Caption = #1057#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1080#1079' '#1092#1072#1081#1083#1072
    TabOrder = 1
    OnClick = CopyButtonClick
  end
  object InputButton: TButton
    Left = 40
    Top = 64
    Width = 145
    Height = 25
    Caption = #1042#1074#1077#1089#1090#1080' '#1076#1072#1085#1085#1099#1077
    TabOrder = 2
    OnClick = InputButtonClick
  end
  object OpenDialog1: TOpenDialog
    Filter = '1|*.txt'
    InitialDir = 'C:\Homework\2 semester\OAiP2\Lab2\Win32\Source'
    Left = 24
    Top = 336
  end
  object SaveDialog1: TSaveDialog
    Left = 96
    Top = 336
  end
end
