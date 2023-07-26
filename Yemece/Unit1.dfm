object Form1: TForm1
  Left = 471
  Top = 432
  BorderStyle = bsDialog
  Caption = 'Yemece'
  ClientHeight = 214
  ClientWidth = 341
  Color = clBtnFace
  Font.Charset = TURKISH_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Courier New'
  Font.Style = [fsBold]
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnMouseDown = FormMouseDown
  PixelsPerInch = 96
  TextHeight = 18
  object L3: TLabel
    Left = 24
    Top = 40
    Width = 130
    Height = 18
    Caption = 'Oyuncu Sýrasý'
    Visible = False
  end
  object L2: TLabel
    Left = 32
    Top = 104
    Width = 140
    Height = 18
    Caption = 'Hasan TEMURTAÞ'
    Visible = False
  end
  object L1: TLabel
    Left = 24
    Top = 72
    Width = 140
    Height = 18
    Caption = 'Hasan TEMURTAÞ'
    Font.Charset = TURKISH_CHARSET
    Font.Color = clWhite
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object B1: TButton
    Left = 192
    Top = 48
    Width = 120
    Height = 39
    Caption = 'Yeni Oyun'
    TabOrder = 0
    Visible = False
    OnClick = B1Click
  end
  object B2: TButton
    Left = 65
    Top = 145
    Width = 128
    Height = 40
    Caption = 'Hoþ Geldin'
    TabOrder = 1
    OnClick = B2Click
  end
end
