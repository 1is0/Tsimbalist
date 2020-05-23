object Form11: TForm11
  Left = 0
  Top = 0
  Caption = 'Form11'
  ClientHeight = 166
  ClientWidth = 268
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 23
    Width = 67
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1088#1077#1081#1089#1072':'
  end
  object Label2: TLabel
    Left = 24
    Top = 58
    Width = 48
    Height = 13
    Caption = #1058#1080#1087' '#1084#1077#1089#1090':'
  end
  object Number: TEdit
    Left = 108
    Top = 20
    Width = 134
    Height = 19
    TabOrder = 0
  end
  object Button1: TButton
    Left = 96
    Top = 120
    Width = 75
    Height = 25
    Caption = #1042#1074#1077#1089#1090#1080
    TabOrder = 1
    OnClick = Button1Click
  end
  object Coupe: TRadioButton
    Left = 108
    Top = 54
    Width = 113
    Height = 17
    Caption = #1050#1091#1087#1077
    Checked = True
    TabOrder = 2
    TabStop = True
  end
  object Reserved: TRadioButton
    Left = 108
    Top = 87
    Width = 113
    Height = 17
    Caption = #1055#1083#1072#1094#1082#1072#1088#1090#1099
    TabOrder = 3
  end
end
