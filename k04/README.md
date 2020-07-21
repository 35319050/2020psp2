# 課題4 レポート

aa83988848 薗田光太郎

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
構造体を宣言。ファイルを入力する。調べたい学籍番号を入力する。ファイルの値を宣言した構造体に格納していく。調べたい学籍番号がファイル内にあれば、その他もろもろのデータを出力する。ちなみにgenderの値が１なら男性、２なら女性と出力。学籍番号がなければ、No Data

## 入出力結果
```
input the filename of sample height:../sample/heights.csv
input the filename of sample ID:../sample/IDs.csv
Which ID's data do you want? : 45313002
---
ID : 45313002
gender : Male
height : 183.9

input the filename of sample height:../sample/heights.csv
input the filename of sample ID:../sample/IDs.csv
Which ID's data do you want? : 35319050
---
No data
```


例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴
[comment #20200721]
- 修正の指示、コメント等は特にありません。引き続き先生に提出をお願いします。
