object RxFormUnit: TRxFormUnit
  Left = 0
  Top = 0
  Caption = 'Rx Form'
  ClientHeight = 577
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
  object PageControl: TPageControl
    Left = 0
    Top = 0
    Width = 1034
    Height = 577
    ActivePage = PageParam
    Align = alClient
    TabOrder = 0
    object PageParam: TTabSheet
      Caption = 'Parametres'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'PageParametres'
      Font.Style = []
      ParentFont = False
      object PanelDesc: TPanel
        Left = -24
        Top = 0
        Width = 1068
        Height = 185
        Align = alCustom
        Anchors = []
        Color = clBackground
        ParentBackground = False
        TabOrder = 0
        DesignSize = (
          1068
          185)
        object LabelCourant: TAdvSmoothLabel
          AlignWithMargins = True
          Left = 615
          Top = 144
          Width = 186
          Height = 23
          AutoShadowCaption = False
          AutoSize = True
          Fill.ColorMirror = clNone
          Fill.ColorMirrorTo = clNone
          Fill.GradientType = gtVertical
          Fill.GradientMirrorType = gtSolid
          Fill.BorderColor = clNone
          Fill.Rounding = 0
          Fill.ShadowOffset = 0
          Fill.Glow = gmNone
          Caption.Text = 'Courant Fonctionnel :'
          Caption.Font.Charset = JOHAB_CHARSET
          Caption.Font.Color = clWindowText
          Caption.Font.Height = -16
          Caption.Font.Name = 'Tahoma'
          Caption.Font.Style = [fsBold]
          Caption.ColorStart = clWhite
          Caption.ColorEnd = clWhite
          CaptionShadow.Text = 'Courant Fonctionnel :'
          CaptionShadow.Font.Charset = DEFAULT_CHARSET
          CaptionShadow.Font.Color = clWindowText
          CaptionShadow.Font.Height = -27
          CaptionShadow.Font.Name = 'Tahoma'
          CaptionShadow.Font.Style = []
          Version = '1.6.0.2'
          Anchors = [akLeft, akTop, akRight, akBottom]
        end
        object LabelName: TAdvSmoothLabel
          AlignWithMargins = True
          Left = 9
          Top = 7
          Width = 147
          Height = 23
          AutoShadowCaption = False
          AutoSize = True
          Fill.ColorMirror = clNone
          Fill.ColorMirrorTo = clNone
          Fill.GradientType = gtVertical
          Fill.GradientMirrorType = gtSolid
          Fill.BorderColor = clNone
          Fill.Rounding = 0
          Fill.ShadowOffset = 0
          Fill.Glow = gmNone
          Caption.Text = 'AdvSmoothLabel'
          Caption.Font.Charset = JOHAB_CHARSET
          Caption.Font.Color = clWindowText
          Caption.Font.Height = -16
          Caption.Font.Name = 'Tahoma'
          Caption.Font.Style = [fsBold]
          Caption.ColorStart = clWhite
          Caption.ColorEnd = clWhite
          CaptionShadow.Text = 'AdvSmoothLabel'
          CaptionShadow.Font.Charset = DEFAULT_CHARSET
          CaptionShadow.Font.Color = clWindowText
          CaptionShadow.Font.Height = -27
          CaptionShadow.Font.Name = 'Tahoma'
          CaptionShadow.Font.Style = []
          Version = '1.6.0.2'
          Anchors = [akLeft, akTop, akRight, akBottom]
        end
        object LabelNbAlim: TAdvSmoothLabel
          AlignWithMargins = True
          Left = 3
          Top = 88
          Width = 147
          Height = 23
          AutoShadowCaption = False
          AutoSize = True
          Fill.ColorMirror = clNone
          Fill.ColorMirrorTo = clNone
          Fill.GradientType = gtVertical
          Fill.GradientMirrorType = gtSolid
          Fill.BorderColor = clNone
          Fill.Rounding = 0
          Fill.ShadowOffset = 0
          Fill.Glow = gmNone
          Caption.Text = 'AdvSmoothLabel'
          Caption.Font.Charset = JOHAB_CHARSET
          Caption.Font.Color = clWindowText
          Caption.Font.Height = -16
          Caption.Font.Name = 'Tahoma'
          Caption.Font.Style = [fsBold]
          Caption.ColorStart = clWhite
          Caption.ColorEnd = clWhite
          CaptionShadow.Text = 'AdvSmoothLabel'
          CaptionShadow.Font.Charset = DEFAULT_CHARSET
          CaptionShadow.Font.Color = clWindowText
          CaptionShadow.Font.Height = -27
          CaptionShadow.Font.Name = 'Tahoma'
          CaptionShadow.Font.Style = []
          Version = '1.6.0.2'
          Anchors = [akLeft, akTop, akRight, akBottom]
        end
        object LabelNbTmtc: TAdvSmoothLabel
          Left = 753
          Top = 88
          Width = 147
          Height = 23
          AutoShadowCaption = False
          AutoSize = True
          Fill.ColorMirror = clNone
          Fill.ColorMirrorTo = clNone
          Fill.GradientType = gtVertical
          Fill.GradientMirrorType = gtSolid
          Fill.BorderColor = clNone
          Fill.Rounding = 0
          Fill.ShadowOffset = 0
          Fill.Glow = gmNone
          Caption.Text = 'AdvSmoothLabel'
          Caption.Font.Charset = JOHAB_CHARSET
          Caption.Font.Color = clWindowText
          Caption.Font.Height = -16
          Caption.Font.Name = 'Tahoma'
          Caption.Font.Style = [fsBold]
          Caption.ColorStart = clWhite
          Caption.ColorEnd = clWhite
          CaptionShadow.Text = 'AdvSmoothLabel'
          CaptionShadow.Font.Charset = DEFAULT_CHARSET
          CaptionShadow.Font.Color = clWindowText
          CaptionShadow.Font.Height = -27
          CaptionShadow.Font.Name = 'Tahoma'
          CaptionShadow.Font.Style = []
          Version = '1.6.0.2'
          Align = alCustom
        end
        object LabelNbTranche: TAdvSmoothLabel
          AlignWithMargins = True
          Left = 391
          Top = 88
          Width = 147
          Height = 23
          AutoShadowCaption = False
          AutoSize = True
          Fill.ColorMirror = clNone
          Fill.ColorMirrorTo = clNone
          Fill.GradientType = gtVertical
          Fill.GradientMirrorType = gtSolid
          Fill.BorderColor = clNone
          Fill.Rounding = 0
          Fill.ShadowOffset = 0
          Fill.Glow = gmNone
          Caption.Text = 'AdvSmoothLabel'
          Caption.Font.Charset = JOHAB_CHARSET
          Caption.Font.Color = clWindowText
          Caption.Font.Height = -16
          Caption.Font.Name = 'Tahoma'
          Caption.Font.Style = [fsBold]
          Caption.ColorStart = clWhite
          Caption.ColorEnd = clWhite
          CaptionShadow.Text = 'AdvSmoothLabel'
          CaptionShadow.Font.Charset = DEFAULT_CHARSET
          CaptionShadow.Font.Color = clWindowText
          CaptionShadow.Font.Height = -27
          CaptionShadow.Font.Name = 'Tahoma'
          CaptionShadow.Font.Style = []
          Version = '1.6.0.2'
          Anchors = [akLeft, akTop, akRight, akBottom]
        end
        object LabelTension: TAdvSmoothLabel
          AlignWithMargins = True
          Left = 3
          Top = 144
          Width = 184
          Height = 23
          AutoShadowCaption = False
          AutoSize = True
          Fill.ColorMirror = clNone
          Fill.ColorMirrorTo = clNone
          Fill.GradientType = gtVertical
          Fill.GradientMirrorType = gtSolid
          Fill.BorderColor = clNone
          Fill.Rounding = 0
          Fill.ShadowOffset = 0
          Fill.Glow = gmNone
          Caption.Text = 'Tension Fonctionnel :'
          Caption.Font.Charset = JOHAB_CHARSET
          Caption.Font.Color = clWindowText
          Caption.Font.Height = -16
          Caption.Font.Name = 'Tahoma'
          Caption.Font.Style = [fsBold]
          Caption.ColorStart = clWhite
          Caption.ColorEnd = clWhite
          CaptionShadow.Text = 'Tension Fonctionnel :'
          CaptionShadow.Font.Charset = DEFAULT_CHARSET
          CaptionShadow.Font.Color = clWindowText
          CaptionShadow.Font.Height = -27
          CaptionShadow.Font.Name = 'Tahoma'
          CaptionShadow.Font.Style = []
          Version = '1.6.0.2'
          Anchors = [akLeft, akTop, akRight, akBottom]
        end
        object LabelType: TAdvSmoothLabel
          Left = 473
          Top = 17
          Width = 147
          Height = 23
          AutoShadowCaption = False
          AutoSize = True
          Fill.ColorMirror = clNone
          Fill.ColorMirrorTo = clNone
          Fill.GradientType = gtVertical
          Fill.GradientMirrorType = gtSolid
          Fill.BorderColor = clNone
          Fill.Rounding = 0
          Fill.ShadowOffset = 0
          Fill.Glow = gmNone
          Caption.Text = 'AdvSmoothLabel'
          Caption.Font.Charset = JOHAB_CHARSET
          Caption.Font.Color = clWindowText
          Caption.Font.Height = -16
          Caption.Font.Name = 'Tahoma'
          Caption.Font.Style = [fsBold]
          Caption.ColorStart = clWhite
          Caption.ColorEnd = clWhite
          CaptionShadow.Text = 'AdvSmoothLabel'
          CaptionShadow.Font.Charset = DEFAULT_CHARSET
          CaptionShadow.Font.Color = clWindowText
          CaptionShadow.Font.Height = -27
          CaptionShadow.Font.Name = 'Tahoma'
          CaptionShadow.Font.Style = []
          Version = '1.6.0.2'
          Align = alCustom
        end
        object TensionF: TAdvSmoothLedLabel
          Left = 187
          Top = 136
          Width = 150
          Height = 41
          Fill.Color = clBlack
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
          Caption.Format = '000.00'
          Caption.TimeFormat = 'hh:nn:ss'
          Caption.TimeValue = 42976.709747789350000000
          Version = '1.1.0.3'
        end
        object CourantF: TAdvSmoothLedLabel
          Left = 823
          Top = 136
          Width = 162
          Height = 41
          Fill.Color = clBlack
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
          Caption.Format = '0.000'
          Caption.TimeFormat = 'hh:nn:ss'
          Caption.TimeValue = 42976.709747789350000000
          Version = '1.1.0.3'
        end
        object BitBtn1: TBitBtn
          Left = 892
          Top = 7
          Width = 93
          Height = 25
          Kind = bkHelp
          NumGlyphs = 2
          TabOrder = 0
          OnClick = BitBtn1Click
        end
      end
      object GridParam: TGridPanel
        AlignWithMargins = True
        Left = 3
        Top = 190
        Width = 1020
        Height = 356
        Align = alBottom
        Alignment = taLeftJustify
        Anchors = []
        ColumnCollection = <
          item
            Value = 10.885412949516540000
          end
          item
            Value = 11.221302772497770000
          end
          item
            Value = 11.635198409789450000
          end
          item
            Value = 12.120730044314850000
          end
          item
            Value = 12.664525960441190000
          end
          item
            Value = 13.243759623811930000
          end
          item
            Value = 13.823039466745200000
          end
          item
            Value = 14.406030772883070000
          end>
        ControlCollection = <
          item
            Column = 1
            Control = TTension
            Row = 0
          end
          item
            Column = 0
            Control = LTension
            Row = 0
          end
          item
            Column = 2
            Control = LCourant
            Row = 0
          end
          item
            Column = 3
            Control = TCourant
            Row = 0
          end
          item
            Column = 4
            Control = LPuissance
            Row = 0
          end
          item
            Column = 5
            Control = TPuissance
            Row = 0
          end
          item
            Column = 0
            Control = LTensionMax
            Row = 1
          end
          item
            Column = 1
            Control = TTensionMax
            Row = 1
          end
          item
            Column = 2
            Control = LCourantMin
            Row = 1
          end
          item
            Column = 3
            Control = TCourantMin
            Row = 1
          end
          item
            Column = 6
            Control = LPuissanceMax
            Row = 0
          end
          item
            Column = 6
            Control = LGain
            Row = 1
          end
          item
            Column = 7
            Control = TGain
            Row = 1
          end
          item
            Column = 0
            Control = LFreqStart
            Row = 2
          end
          item
            Column = 1
            Control = TFreqStart
            Row = 2
          end
          item
            Column = 2
            Control = LFreqStop
            Row = 2
          end
          item
            Column = 3
            Control = TFreqStop
            Row = 2
          end
          item
            Column = 5
            Control = TFreqMin
            Row = 2
          end
          item
            Column = 7
            Control = TfreqMax
            Row = 2
          end
          item
            Column = 1
            Control = TBandwidth
            Row = 3
          end
          item
            Column = 3
            Control = Tstep
            Row = 3
          end
          item
            Column = 5
            Control = TPower
            Row = 3
          end
          item
            Column = 7
            Control = TFreqOl
            Row = 3
          end
          item
            Column = 1
            Control = TpowerOl
            Row = 4
          end
          item
            Column = 3
            Control = TPowerMin
            Row = 4
          end
          item
            Column = 5
            Control = TPowerMax
            Row = 4
          end
          item
            Column = 7
            Control = TPowerOlMax
            Row = 4
          end
          item
            Column = 4
            Control = LFreqMin
            Row = 2
          end
          item
            Column = 6
            Control = LFreqMax
            Row = 2
          end
          item
            Column = 0
            Control = LBandwidth
            Row = 3
          end
          item
            Column = 2
            Control = LStep
            Row = 3
          end
          item
            Column = 4
            Control = LPower
            Row = 3
          end
          item
            Column = 6
            Control = LFreqOl
            Row = 3
          end
          item
            Column = 0
            Control = LpowerOl
            Row = 4
          end
          item
            Column = 2
            Control = LPowerMin
            Row = 4
          end
          item
            Column = 4
            Control = LPowerMax
            Row = 4
          end
          item
            Column = 6
            Control = LPowerOlMax
            Row = 4
          end
          item
            Column = 7
            Control = TPuissanceMax
            Row = 0
          end
          item
            Column = 4
            Control = LCourantMax
            Row = 1
          end
          item
            Column = 5
            Control = TCourantMax
            Row = 1
          end>
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = 12
        Font.Name = 'PageParametres'
        Font.Pitch = fpVariable
        Font.Style = []
        ParentFont = False
        RowCollection = <
          item
            Value = 20.418372810682260000
          end
          item
            Value = 19.881682229321430000
          end
          item
            Value = 19.710353409484320000
          end
          item
            Value = 19.952275287049510000
          end
          item
            Value = 20.037316263462500000
          end
          item
            SizeStyle = ssAuto
          end>
        TabOrder = 1
        DesignSize = (
          1020
          356)
        object TTension: TEdit
          Left = 118
          Top = 27
          Width = 99
          Height = 20
          Anchors = []
          ReadOnly = True
          TabOrder = 0
          Text = 'TTension'
        end
        object LTension: TLabel
          Left = 38
          Top = 31
          Width = 35
          Height = 12
          Anchors = []
          Caption = 'LTension'
          ExplicitLeft = 18
          ExplicitTop = 28
        end
        object LCourant: TLabel
          Left = 265
          Top = 31
          Width = 38
          Height = 12
          Anchors = []
          Caption = 'LCourant'
          ExplicitLeft = 215
          ExplicitTop = 28
        end
        object TCourant: TEdit
          Left = 354
          Top = 27
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 1
          Text = 'TCourant'
        end
        object LPuissance: TLabel
          Left = 516
          Top = 31
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 438
          ExplicitTop = 28
        end
        object TPuissance: TEdit
          Left = 611
          Top = 27
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 2
          Text = 'Edit1'
        end
        object LTensionMax: TLabel
          Left = 42
          Top = 102
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 25
          ExplicitTop = 99
        end
        object TTensionMax: TEdit
          Left = 118
          Top = 98
          Width = 99
          Height = 20
          Anchors = []
          TabOrder = 3
          Text = 'Edit1'
        end
        object LCourantMin: TLabel
          Left = 270
          Top = 102
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 223
          ExplicitTop = 99
        end
        object TCourantMin: TEdit
          Left = 354
          Top = 98
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 4
          Text = 'Edit1'
        end
        object LPuissanceMax: TLabel
          Left = 784
          Top = 31
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 438
          ExplicitTop = 99
        end
        object LGain: TLabel
          Left = 784
          Top = 102
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 672
          ExplicitTop = 99
        end
        object TGain: TEdit
          Left = 893
          Top = 98
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 5
          Text = 'Edit1'
        end
        object LFreqStart: TLabel
          Left = 42
          Top = 171
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 25
          ExplicitTop = 168
        end
        object TFreqStart: TEdit
          Left = 118
          Top = 167
          Width = 99
          Height = 20
          Anchors = []
          TabOrder = 6
          Text = 'Edit1'
        end
        object LFreqStop: TLabel
          Left = 270
          Top = 171
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 223
          ExplicitTop = 168
        end
        object TFreqStop: TEdit
          Left = 354
          Top = 167
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 7
          Text = 'Edit1'
        end
        object TFreqMin: TEdit
          Left = 611
          Top = 167
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 8
          Text = 'Edit1'
        end
        object TfreqMax: TEdit
          Left = 893
          Top = 167
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 9
          Text = 'Edit1'
        end
        object TBandwidth: TEdit
          Left = 118
          Top = 237
          Width = 99
          Height = 20
          Anchors = []
          TabOrder = 10
          Text = 'Edit1'
        end
        object Tstep: TEdit
          Left = 354
          Top = 237
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 11
          Text = 'Edit1'
        end
        object TPower: TEdit
          Left = 611
          Top = 237
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 12
          Text = 'Edit1'
        end
        object TFreqOl: TEdit
          Left = 893
          Top = 237
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 13
          Text = 'Edit1'
        end
        object TpowerOl: TEdit
          Left = 118
          Top = 307
          Width = 99
          Height = 20
          Anchors = []
          TabOrder = 14
          Text = 'Edit1'
        end
        object TPowerMin: TEdit
          Left = 354
          Top = 307
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 15
          Text = 'Edit1'
        end
        object TPowerMax: TEdit
          Left = 611
          Top = 307
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 16
          Text = 'Edit1'
        end
        object TPowerOlMax: TEdit
          Left = 893
          Top = 307
          Width = 100
          Height = 20
          Anchors = []
          TabOrder = 17
          Text = 'Edit1'
        end
        object LFreqMin: TLabel
          Left = 516
          Top = 171
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 438
          ExplicitTop = 168
        end
        object LFreqMax: TLabel
          Left = 784
          Top = 171
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 672
          ExplicitTop = 168
        end
        object LBandwidth: TLabel
          Left = 42
          Top = 241
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 25
          ExplicitTop = 238
        end
        object LStep: TLabel
          Left = 270
          Top = 241
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 223
          ExplicitTop = 238
        end
        object LPower: TLabel
          Left = 516
          Top = 241
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 438
          ExplicitTop = 238
        end
        object LFreqOl: TLabel
          Left = 784
          Top = 241
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 672
          ExplicitTop = 238
        end
        object LpowerOl: TLabel
          Left = 42
          Top = 311
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 25
          ExplicitTop = 309
        end
        object LPowerMin: TLabel
          Left = 270
          Top = 311
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 223
          ExplicitTop = 309
        end
        object LPowerMax: TLabel
          Left = 516
          Top = 311
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 438
          ExplicitTop = 309
        end
        object LPowerOlMax: TLabel
          Left = 784
          Top = 311
          Width = 27
          Height = 12
          Anchors = []
          Caption = 'Label1'
          ExplicitLeft = 672
          ExplicitTop = 309
        end
        object TPuissanceMax: TEdit
          Left = 883
          Top = 27
          Width = 121
          Height = 20
          Anchors = []
          TabOrder = 18
          Text = 'Edit1'
        end
        object LCourantMax: TLabel
          Left = 502
          Top = 102
          Width = 55
          Height = 12
          Anchors = []
          Caption = 'LCourantMax'
          ExplicitLeft = 448
          ExplicitTop = 288
        end
        object TCourantMax: TEdit
          Left = 602
          Top = 98
          Width = 117
          Height = 20
          Anchors = []
          TabOrder = 19
          Text = 'TCourantMax'
        end
      end
    end
  end
end
