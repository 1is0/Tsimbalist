object Form4: TForm4
  Left = 0
  Top = 0
  Caption = #1042#1074#1077#1089#1090#1080' '#1080#1075#1088#1086#1082#1072
  ClientHeight = 346
  ClientWidth = 266
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
  object Panel1: TPanel
    AlignWithMargins = True
    Left = 21
    Top = 8
    Width = 232
    Height = 329
    TabOrder = 0
    object Label1: TLabel
      Left = 19
      Top = 33
      Width = 51
      Height = 16
      Caption = #1057#1090#1088#1072#1085#1072': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 19
      Top = 60
      Width = 59
      Height = 16
      Caption = #1050#1086#1084#1072#1085#1076#1072': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 19
      Top = 87
      Width = 32
      Height = 16
      Caption = #1048#1084#1103': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 19
      Top = 114
      Width = 62
      Height = 16
      Caption = #1060#1072#1084#1080#1083#1080#1103': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 19
      Top = 141
      Width = 64
      Height = 16
      Caption = #1054#1090#1095#1077#1089#1090#1074#1086': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 19
      Top = 168
      Width = 46
      Height = 16
      Caption = #1053#1086#1084#1077#1088': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 19
      Top = 195
      Width = 55
      Height = 16
      Caption = #1042#1086#1079#1088#1072#1089#1090': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 19
      Top = 222
      Width = 35
      Height = 16
      Caption = #1056#1086#1089#1090': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 19
      Top = 249
      Width = 29
      Height = 16
      Caption = #1042#1077#1089': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label10: TLabel
      Left = 19
      Top = 11
      Width = 72
      Height = 16
      Caption = '1 '#1089#1087#1086#1088#1090#1089#1084#1077#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Team: TEdit
      Left = 105
      Top = 59
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Country: TEdit
      Left = 105
      Top = 32
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object Name: TEdit
      Left = 105
      Top = 86
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object Surname: TEdit
      Left = 105
      Top = 113
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object Patronymic: TEdit
      Left = 105
      Top = 140
      Width = 121
      Height = 21
      TabOrder = 4
    end
    object Number: TEdit
      Left = 105
      Top = 167
      Width = 121
      Height = 21
      TabOrder = 5
    end
    object Age: TEdit
      Left = 105
      Top = 194
      Width = 121
      Height = 21
      TabOrder = 6
      OnChange = AgeChange
      OnKeyPress = AgeKeyPress
    end
    object Height: TEdit
      Left = 105
      Top = 221
      Width = 121
      Height = 21
      TabOrder = 7
    end
    object Weight: TEdit
      Left = 105
      Top = 248
      Width = 121
      Height = 21
      TabOrder = 8
    end
    object Button1: TButton
      Left = 72
      Top = 288
      Width = 75
      Height = 25
      Caption = #1042#1074#1077#1089#1090#1080
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnClick = Button1Click
    end
  end
end
