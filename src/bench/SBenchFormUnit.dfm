object BenchFormUnit: TBenchFormUnit
  Left = 0
  Top = 0
  Caption = 'BenchFormUnit'
  ClientHeight = 484
  ClientWidth = 1034
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  HelpFile = 'doc.chm'
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 16
    Top = 0
    Width = 1017
    Height = 97
    TabOrder = 0
    object LabelImmo: TLabel
      Left = 600
      Top = 58
      Width = 75
      Height = 19
      Caption = 'Immo Pc :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LabelName: TLabel
      Left = 3
      Top = 58
      Width = 135
      Height = 19
      Caption = 'Type Equipement :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object TextName: TEdit
      Left = 144
      Top = 56
      Width = 129
      Height = 21
      ReadOnly = True
      TabOrder = 0
      Text = 'TextName'
    end
    object TextImmo: TEdit
      Left = 720
      Top = 56
      Width = 129
      Height = 21
      ReadOnly = True
      TabOrder = 1
      Text = 'Edit1'
    end
    object BitBtn1: TBitBtn
      Left = 885
      Top = 0
      Width = 81
      Height = 40
      HelpKeyword = 'h'
      Align = alCustom
      Kind = bkHelp
      NumGlyphs = 2
      TabOrder = 2
      OnClick = BitBtn1Click
    end
  end
  object GroupBox1: TGroupBox
    Left = 327
    Top = 103
    Width = 706
    Height = 373
    Align = alCustom
    Caption = 'Parametre du banc  de test :'
    TabOrder = 1
    DesignSize = (
      706
      373)
    object Label1: TLabel
      Left = 20
      Top = 25
      Width = 150
      Height = 19
      Anchors = []
      Caption = 'Tension Applicable : '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitLeft = 3
    end
    object Label2: TLabel
      Left = 20
      Top = 90
      Width = 145
      Height = 19
      Anchors = []
      Caption = 'Courant Applicable :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitLeft = 3
    end
    object Label3: TLabel
      Left = 12
      Top = 178
      Width = 79
      Height = 19
      Anchors = []
      Caption = 'Puissance :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitLeft = 3
    end
    object Label5: TLabel
      Left = 25
      Top = 256
      Width = 229
      Height = 19
      Anchors = []
      Caption = 'Chemin de Calibration d'#39'entr'#233'e :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitLeft = 0
    end
    object Label6: TLabel
      Left = 26
      Top = 297
      Width = 234
      Height = 19
      Anchors = []
      Caption = 'Chemin de Calibration de sortie :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitLeft = 0
    end
    object Label7: TLabel
      Left = 28
      Top = 338
      Width = 223
      Height = 18
      Anchors = []
      Caption = 'Chemin de Calibration du spectre :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitLeft = 3
    end
    object TextTension: TAdvSmoothLedLabel
      Left = 324
      Top = 25
      Width = 200
      Height = 50
      Fill.Color = clBlack
      Fill.ColorTo = clBlack
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.BorderColor = clNone
      Fill.Rounding = 0
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      Caption.ColorStart = clWhite
      Caption.ColorEnd = clWhite
      Caption.ColorOff = clBlack
      Caption.Format = '000.00'
      Caption.TimeFormat = 'hh:nn:ss'
      Caption.TimeValue = 42892.670126712960000000
      Version = '1.1.0.3'
      Anchors = []
      ExplicitLeft = 247
    end
    object TextCourant: TAdvSmoothLedLabel
      Left = 324
      Top = 105
      Width = 200
      Height = 50
      Fill.Color = clBlack
      Fill.ColorTo = clBlack
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.BorderColor = clNone
      Fill.Rounding = 0
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      Caption.ColorStart = clWhite
      Caption.ColorEnd = clWhite
      Caption.ColorOff = clBlack
      Caption.Format = '00.000'
      Caption.TimeFormat = 'hh:nn:ss'
      Caption.TimeValue = 42892.670126712960000000
      Version = '1.1.0.3'
      Anchors = []
      ExplicitLeft = 247
    end
    object TextPower: TAdvSmoothLedLabel
      Left = 324
      Top = 178
      Width = 200
      Height = 50
      Fill.Color = clBlack
      Fill.ColorTo = clBlack
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.BorderColor = clNone
      Fill.Rounding = 0
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      Caption.ColorStart = clWhite
      Caption.ColorEnd = clWhite
      Caption.ColorOff = clBlack
      Caption.Format = '000.00'
      Caption.TimeFormat = 'hh:nn:ss'
      Caption.TimeValue = 42892.670126712960000000
      Version = '1.1.0.3'
      Anchors = []
      ExplicitLeft = 247
    end
    object TCal_In: TEdit
      Left = 324
      Top = 256
      Width = 331
      Height = 22
      Anchors = []
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 14
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object TCal_Out: TEdit
      Left = 324
      Top = 296
      Width = 331
      Height = 22
      Anchors = []
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 14
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object TCal_Spectrum: TEdit
      Left = 324
      Top = 335
      Width = 331
      Height = 22
      Anchors = []
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 14
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 103
    Width = 305
    Height = 373
    TabOrder = 2
    DesignSize = (
      305
      373)
    object Label4: TLabel
      Left = 3
      Top = 24
      Width = 211
      Height = 19
      Anchors = []
      Caption = 'Listes des Appareils du Banc :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object ListView1: TListView
      Left = 3
      Top = 64
      Width = 250
      Height = 297
      Anchors = []
      Columns = <>
      TabOrder = 0
    end
  end
end
