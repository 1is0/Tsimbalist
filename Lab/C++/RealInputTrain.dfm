object Form9: TForm9
  Left = 0
  Top = 0
  Caption = 'Form9'
  ClientHeight = 324
  ClientWidth = 362
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
    Left = 7
    Top = 8
    Width = 347
    Height = 305
    TabOrder = 0
    object Label1: TLabel
      Left = 21
      Top = 33
      Width = 115
      Height = 16
      Caption = #1044#1077#1085#1100' '#1086#1090#1087#1088#1072#1074#1083#1077#1085#1080#1103':'
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
      Width = 80
      Height = 16
      Caption = #1053#1086#1084#1077#1088' '#1088#1077#1081#1089#1072':'
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
      Width = 99
      Height = 16
      Caption = #1050#1086#1085#1077#1095#1085#1099#1081' '#1087#1091#1085#1082#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 19
      Top = 141
      Width = 70
      Height = 16
      Caption = #1063#1080#1089#1083#1086' '#1082#1091#1087#1077':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 19
      Top = 114
      Width = 121
      Height = 16
      Caption = #1042#1088#1077#1084#1103' '#1086#1090#1087#1088#1072#1074#1083#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 21
      Top = 168
      Width = 112
      Height = 16
      Caption = #1063#1080#1089#1083#1086' '#1087#1083#1072#1094#1082#1072#1088#1090#1086#1074':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 21
      Top = 195
      Width = 137
      Height = 16
      Caption = #1063#1080#1089#1083#1086' '#1089#1074#1086#1073#1086#1076#1085#1099#1093' '#1082#1091#1087#1077':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 21
      Top = 221
      Width = 179
      Height = 16
      Caption = #1063#1080#1089#1083#1086' '#1089#1074#1086#1073#1086#1076#1085#1099#1093' '#1087#1083#1072#1094#1082#1072#1088#1090#1086#1074':'
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
      Width = 45
      Height = 16
      Caption = '1 '#1087#1086#1077#1079#1076
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Number: TEdit
      Left = 209
      Top = 59
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Date: TEdit
      Left = 209
      Top = 32
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object End: TEdit
      Left = 209
      Top = 86
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object Coupe: TEdit
      Left = 209
      Top = 140
      Width = 121
      Height = 21
      TabOrder = 3
      OnChange = CoupeChange
      OnKeyPress = CoupeKeyPress
    end
    object Reserved: TEdit
      Left = 209
      Top = 167
      Width = 121
      Height = 21
      TabOrder = 4
      OnChange = ReservedChange
      OnKeyPress = ReservedKeyPress
    end
    object CoupeFree: TEdit
      Left = 209
      Top = 194
      Width = 121
      Height = 21
      TabOrder = 5
      OnChange = CoupeFreeChange
      OnKeyPress = CoupeFreeKeyPress
    end
    object ReservedFree: TEdit
      Left = 209
      Top = 221
      Width = 121
      Height = 21
      TabOrder = 6
      OnChange = ReservedFreeChange
      OnKeyPress = ReservedFreeKeyPress
    end
    object Button1: TButton
      Left = 136
      Top = 264
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
      TabOrder = 7
      OnClick = Button1Click
    end
    object Time: TMaskEdit
      Left = 209
      Top = 113
      Width = 119
      Height = 21
      EditMask = '!90:00;1;_'
      MaxLength = 5
      TabOrder = 8
      Text = '  :  '
    end
  end
end
