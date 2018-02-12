object AlimFormUnit: TAlimFormUnit
  Left = 0
  Top = 0
  Caption = 'AlimFormUnit'
  ClientHeight = 482
  ClientWidth = 1034
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ShapeActive: TShape
    Left = 203
    Top = 168
    Width = 25
    Height = 25
  end
  object PageControl: TPageControl
    Left = 0
    Top = 2
    Width = 1034
    Height = 480
    Cursor = crDrag
    ActivePage = TabSheet2
    Align = alBottom
    Style = tsFlatButtons
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Vue'
      object GroupBoxAlim: TGroupBox
        Left = 0
        Top = 0
        Width = 506
        Height = 449
        Align = alLeft
        Caption = 'ACTIF'
        TabOrder = 0
        DesignSize = (
          506
          449)
        object VoltUnitLabel: TLabel
          Left = 347
          Top = 41
          Width = 19
          Height = 39
          Anchors = []
          Caption = 'V'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object CurrUnitLabel: TLabel
          Left = 320
          Top = 115
          Width = 46
          Height = 39
          Anchors = []
          Caption = 'mA'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object ShapeOverVoltage: TShape
          Left = 50
          Top = 168
          Width = 25
          Height = 25
          Anchors = []
          DragMode = dmAutomatic
          ExplicitLeft = 28
        end
        object ShapeOverCurrent: TShape
          Left = 97
          Top = 168
          Width = 25
          Height = 25
          Anchors = []
          ExplicitLeft = 59
        end
        object ShapeOverTemperature: TShape
          Left = 145
          Top = 168
          Width = 25
          Height = 25
          Anchors = []
          ExplicitLeft = 90
        end
        object ShapeRemote: TShape
          Left = 193
          Top = 168
          Width = 25
          Height = 25
          Anchors = []
          ExplicitLeft = 121
        end
        object ShapeUnregulation: TShape
          Left = 271
          Top = 168
          Width = 25
          Height = 25
          Anchors = []
          ExplicitLeft = 172
        end
        object VoltageLabel: TAdvSmoothLedLabel
          Left = 50
          Top = 30
          Width = 247
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
        end
        object CurrentLabel: TAdvSmoothLedLabel
          Left = 50
          Top = 104
          Width = 247
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
          Caption.TimeValue = 42892.670592222210000000
          Version = '1.1.0.3'
          Anchors = []
        end
      end
      object GroupBoxParamAlim: TGroupBox
        Left = 462
        Top = 0
        Width = 564
        Height = 449
        Align = alRight
        Caption = 'PROGRAMME'
        TabOrder = 1
        DesignSize = (
          564
          449)
        object VoltageProgLabel: TAdvSmoothLedLabel
          Left = 312
          Top = 30
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
          Caption.TimeValue = 42894.697259618050000000
          Version = '1.1.0.3'
          Anchors = []
        end
        object VoltageProtLabel: TAdvSmoothLedLabel
          Left = 312
          Top = 104
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
          Caption.TimeValue = 42894.697259618050000000
          Version = '1.1.0.3'
          Anchors = []
        end
        object CurrentProtLabel: TAdvSmoothLedLabel
          Left = 312
          Top = 182
          Width = 200
          Height = 50
          Fill.Color = clBlack
          Fill.ColorTo = clBlack
          Fill.ColorMirror = clBackground
          Fill.ColorMirrorTo = clBackground
          Fill.GradientType = gtVertical
          Fill.GradientMirrorType = gtSolid
          Fill.BorderColor = clWhite
          Fill.Rounding = 0
          Fill.ShadowColor = clWhite
          Fill.ShadowOffset = 0
          Fill.Glow = gmNone
          Fill.GlowGradientColor = clBlack
          Fill.GlowRadialColor = clBlack
          Caption.ColorStart = clWhite
          Caption.ColorEnd = clWhite
          Caption.ColorOff = clBlack
          Caption.Format = '0.0000'
          Caption.TimeFormat = 'hh:nn:ss'
          Caption.TimeValue = 42894.697259618050000000
          Version = '1.1.0.3'
          Anchors = []
        end
        object Label2: TLabel
          Left = 12
          Top = 57
          Width = 175
          Height = 19
          Anchors = []
          Caption = 'Tension Programme :'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label1: TLabel
          Left = 12
          Top = 213
          Width = 179
          Height = 19
          Anchors = []
          Caption = 'Courant de protection'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label3: TLabel
          Left = 12
          Top = 131
          Width = 190
          Height = 19
          Anchors = []
          Caption = 'Tension de Protection :'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Action'
      ImageIndex = 1
      object GroupBox3: TGroupBox
        Left = 32
        Top = 24
        Width = 321
        Height = 105
        Caption = 'Tension'
        TabOrder = 0
        object ActionTensionText: TEdit
          Left = 24
          Top = 40
          Width = 121
          Height = 21
          TabOrder = 0
        end
        object ButTensionparam: TAdvGlassButton
          Left = 176
          Top = 40
          Width = 100
          Height = 32
          BackColor = clGray
          Caption = 'Appliquer'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ForeColor = clWhite
          GlowColor = 16760205
          InnerBorderColor = clBlack
          OuterBorderColor = clWhite
          ParentFont = False
          ShineColor = clWhite
          TabOrder = 1
          Version = '1.3.0.2'
          OnClick = ButTensionparamClick
        end
      end
      object GroupBox4: TGroupBox
        Left = 448
        Top = 24
        Width = 353
        Height = 105
        Caption = 'Courant'
        TabOrder = 1
        object ActionCourantText: TEdit
          Left = 32
          Top = 48
          Width = 121
          Height = 21
          TabOrder = 0
        end
        object ButCourantApp: TAdvGlassButton
          Left = 216
          Top = 40
          Width = 100
          Height = 32
          BackColor = clGray
          Caption = 'Appliquer'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ForeColor = clWhite
          GlowColor = 16760205
          InnerBorderColor = clBlack
          OuterBorderColor = clWhite
          ParentFont = False
          ShineColor = clWhite
          TabOrder = 1
          Version = '1.3.0.2'
          OnClick = ButCourantAppClick
        end
      end
      object ButDisjonctionApp: TAdvGlassButton
        Left = 32
        Top = 160
        Width = 137
        Height = 41
        BackColor = clRed
        BackGroundSymbolColor = clRed
        ButtonDirection = bdLeft
        Caption = 'Disjonction'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ForeColor = clWhite
        GlowColor = 16760205
        InnerBorderColor = clBlack
        OuterBorderColor = clWhite
        ParentFont = False
        ShineColor = clWhite
        TabOrder = 2
        Version = '1.3.0.2'
        OnClick = ButDisjonctionAppClick
      end
      object ButSurchauffeApp: TAdvGlassButton
        Left = 224
        Top = 160
        Width = 137
        Height = 40
        BackColor = clRed
        BackGroundSymbolColor = clRed
        Caption = 'Surchauffe'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ForeColor = clWhite
        GlowColor = 16760205
        InnerBorderColor = clBlack
        OuterBorderColor = clWhite
        ParentFont = False
        ShineColor = clWhite
        TabOrder = 3
        Version = '1.3.0.2'
        OnClick = ButSurchauffeAppClick
      end
      object ButRegulApp: TAdvGlassButton
        Left = 448
        Top = 160
        Width = 121
        Height = 40
        BackColor = clRed
        BackGroundSymbolColor = clRed
        Caption = 'Non -Regulation'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ForeColor = clWhite
        GlowColor = 16760205
        InnerBorderColor = clBlack
        OuterBorderColor = clWhite
        ParentFont = False
        ShineColor = clWhite
        TabOrder = 4
        Version = '1.3.0.2'
      end
      object AdvGlassButton1: TAdvGlassButton
        Left = 664
        Top = 160
        Width = 137
        Height = 41
        BackColor = clRed
        BackGroundSymbolColor = clRed
        Caption = 'R'#233'-Initialiser'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ForeColor = clWhite
        GlowColor = 16760205
        InnerBorderColor = clBlack
        OuterBorderColor = clWhite
        ParentFont = False
        ShineColor = clWhite
        TabOrder = 5
        Version = '1.3.0.2'
        OnClick = AdvGlassButton1Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Parametre'
      ImageIndex = 2
      object GroupBoxParameters: TGroupBox
        Left = 0
        Top = 0
        Width = 1026
        Height = 449
        Align = alClient
        TabOrder = 0
        object LTitre: TLabel
          Left = 16
          Top = 16
          Width = 237
          Height = 23
          Caption = 'Parametres Alimentation'
          Color = clBlue
          FocusControl = GroupBoxAlim
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Tahoma'
          Font.Style = [fsBold, fsUnderline]
          ParentColor = False
          ParentFont = False
        end
        object GroupBox1: TGroupBox
          Left = 129
          Top = 92
          Width = 561
          Height = 125
          Caption = 'Parametres Tension'
          TabOrder = 0
          object LTensionMax: TLabel
            Left = 16
            Top = 25
            Width = 60
            Height = 13
            Caption = 'Tension Max'
          end
          object LPuissanceMax: TLabel
            Left = 296
            Top = 25
            Width = 70
            Height = 13
            Caption = 'Puissance Max'
          end
          object LtensionPeak: TLabel
            Left = 292
            Top = 64
            Width = 106
            Height = 13
            Caption = 'Tension Peak tot Peak'
          end
          object LTensionRMS: TLabel
            Left = 296
            Top = 96
            Width = 61
            Height = 13
            Caption = 'Tension RMS'
          end
          object TextTensionMax: TEdit
            Left = 100
            Top = 22
            Width = 121
            Height = 21
            AutoSelect = False
            AutoSize = False
            Color = clMenuBar
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindow
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
          end
          object TextPowerMax: TEdit
            Left = 404
            Top = 22
            Width = 121
            Height = 21
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindow
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
          end
          object TextTensionpeak: TEdit
            Left = 404
            Top = 56
            Width = 121
            Height = 21
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindow
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
          end
          object TextTensionRMS: TEdit
            Left = 404
            Top = 93
            Width = 121
            Height = 21
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindow
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
          end
        end
        object GroupBox2: TGroupBox
          Left = 129
          Top = 288
          Width = 561
          Height = 105
          Caption = 'Parametres Courant'
          TabOrder = 1
          object LCourantMax: TLabel
            Left = 16
            Top = 36
            Width = 62
            Height = 13
            Caption = 'Courant Max'
          end
          object LCourantRMS: TLabel
            Left = 312
            Top = 36
            Width = 63
            Height = 13
            Caption = 'Courant RMS'
          end
          object TextCourantMax: TEdit
            Left = 108
            Top = 28
            Width = 121
            Height = 21
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindow
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
          end
          object TextCourantRMS: TEdit
            Left = 404
            Top = 28
            Width = 121
            Height = 21
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindow
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
          end
        end
      end
    end
  end
  object ButHelpAlim: TBitBtn
    Left = 897
    Top = 2
    Width = 81
    Height = 28
    Align = alCustom
    Kind = bkHelp
    NumGlyphs = 2
    TabOrder = 1
    OnClick = ButHelpAlimClick
  end
  object Timer1: TTimer
    Left = 768
    Top = 390
  end
end
