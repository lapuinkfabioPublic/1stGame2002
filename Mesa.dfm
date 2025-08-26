object MesaJogo: TMesaJogo
  Left = 250
  Top = 153
  Width = 569
  Height = 409
  Caption = 'MesaJogo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 89
    Height = 33
    Caption = 'Label1'
  end
  object criaJogador: TButton
    Left = 272
    Top = 8
    Width = 75
    Height = 25
    Caption = 'criaJogador'
    TabOrder = 0
    OnClick = criaJogadorClick
  end
  object Jogar: TButton
    Left = 272
    Top = 336
    Width = 75
    Height = 25
    Caption = 'Vencedor?'
    TabOrder = 1
    OnClick = JogarClick
  end
  object mResultados: TMemo
    Left = 88
    Top = 48
    Width = 449
    Height = 273
    Lines.Strings = (
      '')
    ScrollBars = ssVertical
    TabOrder = 2
  end
end
