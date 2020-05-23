object Form8: TForm8
  Left = 0
  Top = 0
  Caption = 'Form8'
  ClientHeight = 400
  ClientWidth = 529
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Filename: TLabel
    Left = 40
    Top = 272
    Width = 3
    Height = 13
  end
  object Memo1: TMemo
    Left = 243
    Top = 24
    Width = 257
    Height = 225
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object CopyButton: TButton
    Left = 40
    Top = 22
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
  object OutputButton: TButton
    Left = 40
    Top = 104
    Width = 145
    Height = 25
    Caption = #1042#1099#1074#1077#1089#1090#1080' '#1076#1072#1085#1085#1099#1077
    Enabled = False
    TabOrder = 3
    OnClick = OutputButtonClick
  end
  object AddButton: TButton
    Left = 40
    Top = 144
    Width = 145
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
    Enabled = False
    TabOrder = 4
    OnClick = AddButtonClick
  end
  object DeleteButton: TButton
    Left = 40
    Top = 184
    Width = 145
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
    Enabled = False
    TabOrder = 5
    OnClick = DeleteButtonClick
  end
  object CorrectButton: TButton
    Left = 40
    Top = 224
    Width = 145
    Height = 25
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
    Enabled = False
    TabOrder = 6
    OnClick = CorrectButtonClick
  end
  object PlaceButton: TButton
    Left = 243
    Top = 361
    Width = 190
    Height = 25
    Caption = #1056#1077#1081#1089#1099' '#1087#1086' '#1087#1091#1085#1082#1090#1091' '#1085#1072#1079#1085#1072#1095#1077#1085#1080#1103
    Enabled = False
    TabOrder = 7
    OnClick = PlaceButtonClick
  end
  object DayButton: TButton
    Left = 243
    Top = 330
    Width = 190
    Height = 25
    Caption = #1056#1077#1081#1089#1099' '#1087#1086' '#1076#1085#1103#1084' '#1085#1077#1076#1077#1083#1080
    Enabled = False
    TabOrder = 8
    OnClick = DayButtonClick
  end
  object TypeButton: TButton
    Left = 243
    Top = 299
    Width = 190
    Height = 25
    Caption = #1053#1086#1084#1077#1088' '#1088#1077#1081#1089#1072' '#1080' '#1090#1080#1087' '#1084#1077#1089#1090
    Enabled = False
    TabOrder = 9
    OnClick = TypeButtonClick
  end
  object OpenDialog1: TOpenDialog
    Filter = '1|*.txt'
    InitialDir = 'C:\Homework\2 semester\OAiP2\Lab2\Win32\Source'
    Left = 24
    Top = 317
  end
  object SaveDialog1: TSaveDialog
    Left = 96
    Top = 317
  end
end
