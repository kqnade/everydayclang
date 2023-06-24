# 前回までのあらすじ

- 環境構築をした。
- C言語の基本的な構文を学んだ。
- Hello Worldの出力ができた。

# 今回のテーマ

- 変数、型とはなにか
- 型の種類
- 変数の値を表示する方法
- 型の変換について
- 記憶域クラスについて
- 型修飾子について

# 変数、型とはなにか

変数とはデータを格納しておく領域のこと。変数は通常メモリ上に確保され、値を代入したり参照したりすることができる。
それぞれの領域を区別するために変数名を付けて宣言をする。
型とは、数字や文字などのデータをメモリ上に確保する領域やバイト長、確保した領域の扱い方などを指定するもの。

## 変数の宣言

変数の宣言は以下のように行う。

```c
記憶域クラス名 型修飾子 型名 変数名;
```

記憶域クラスとは、変数を格納する記憶領域を指定するもの。型修飾子とは、変数の用途をこまかく指定するものらしい。

## 変数の初期化

変数の宣言と同時に値を代入することを初期化といい、以下のように行う。

```c
変数名 = 式;
```

## 変数の参照

変数の参照は以下のように行う。

```c
変数名
```

# 型の種類

|   型名   |    説明     |
|:------:|:---------:|
|  void  |    型なし    |
|  char  |    文字型    |
|  int   |    整数型    |
| float  | 単精度浮動小数点型 |
| double | 倍精度浮動小数点型 |
| struct |   構造体型    |
| union  |   共用体型    |
|  enum  |    列挙型    |

`short`、`long`、`unsigned`、`signed`などの型修飾子と組み合わせて、変数のバイト長や値の範囲が決められる。
用途に合わせた型を選択することで、メモリの節約や計算の精度を上げることができる。

# 変数の値を表示する方法

変数の値を表示するには前回「Hello, World!」の際に学んだ、`printf()`関数を使うと標準出力に表示できる。

```c
#include <stdio.h>

int main(void) {
    int num = 1234;
    printf("num: %d\n", num);
return 0;
}
```

# 型の変換について

型を別の型に変換して利用できる。
暗黙的な型変換と明示的な型変換がある。

## 暗黙的な型変換

暗黙的な型変換とは、コンパイラが自動的に型変換を行うこと。

```c
#include <stdio.h>

int main(void) {
    int num = 3;
    double dbl;

    /* 暗黙的型変換
     * double型変数にint型変数を代入 */
    dbl = num;
    printf("double型変数dblの値は: %lf\n", dbl);

    /* 暗黙的型変換
     * int型の変数が式中でdouble型に変換 */
    double result;
    result = dbl + num;
    printf("double型変数resultの値は: %lf\n", result);

return 0;
}
```

## 明示的な型変換

明示的な型変換をキャストという。

```c
(型名)式
```

のように変換をする。

```c
#include <stdio.h>

int main(void) {
    int num = 3;
    double result;
    
    // キャストを行う場合
    result = 1 / (double)num;
    printf("double型変数resultの値は: %lf\n", result);
    
    // キャストを行わない場合
    result = 1 / num;
    printf("double型変数resultの値は: %lf\n", result);
    
    return 0;
}
```

サンプルコードのような状況では、キャストを行わないと、`1 / 3`の結果が`0`となってしまう。
キャストを行うことで型を変換し、`1 / 3`の正しい結果`0.3333333...`を得ることができる。

### キャスト時の注意

#### 小数点以下切り捨て

floatやdouble型の変数にint型の変数を代入する場合、小数点以下の値は切り捨てられるため注意が必要。

```c
#include <stdio.h>

int main(void) {
    int num;
    double dbl = 3.14;
    
    // double型変数からint型変数へのキャスト
    num = (int)dbl;
    printf("int型変数numの値は: %d\n", num);
    
    return 0;
}
```

結果：

```
int型変数numの値は: 3
```

#### 符号付き型と符号なし型の変換

マイナスの値の変数を符号なし型の変数にキャストしてもマイナスを取った値にはならない。意図しない値となるので注意が必要。

```c

#include
<stdio.h>

int main(void) {
char chr = -100;
unsigned char uchr;

// 符号付きchar型変数から符号なしchar型変数へのキャスト
uchr = (unsigned char)chr;
printf("unsigned char型変数uchrの値は: %u\n", uchr);

return 0;
}
```

結果：

```
unsigned char型変数uchrの値は: 156
```

このサンプルコードでは符号付きchar型の変数「chr」を符号なしchar型「uchr」にキャストしている。
だが「uchr」の値は「chr」の値のマイナスを取った値ではなく、意図しない値になっている。

#### オーバーフロー

オーバーフローとは、変数の値がその型の範囲を超えてしまうことで意図しない値になってしまうこと。

```c
#include <stdio.h>

int main(void) {
    int num = 1000;
    char chr;
    
    // int型変数からchar型変数へのキャスト
    chr = (char)num;
    printf("char型変数chrの値は: %d\n", chr);
    
    return 0;
}
```

結果：

```
char型変数chrの値は: -24
```

このサンプルコードではint型の変数「num」の値をchar型の変数「chr」にキャストしている。
だが「num」の値は「1000」とchar型の値の範囲-128～127外の値からキャストしているので「chr」の値は意図しない値になっている。

## char型とint型の型変換

charは文字列の型であり、intは整数の型であるが、char型の変数にint型の値を代入することができる。
char型の変数は文字を格納できるとともに、-128から127までの値も格納できる。

```c
#include <stdio.h>

int main(void) {
    char chr = 'a';
    int num;
    unsigned char uchr;
    
    // 文字から数値への変換
    num = (int)chr;
    printf("int型変数numの値は%d\n", num);
    
    // 数値から文字への変換
    uchr = (char)num;
    printf("unsigned char型変数uchrの値は%c\n", uchr);
    return 0;
}
```

実行結果

```
int型変数numの値は97
unsigned char型変数uchrの値はa
```

# 記憶域クラス

記憶域クラスとは、変数の宣言時に変数のメモリ上の配置を指定するもの。
以下のような記憶域クラスがある。

- auto
- static
- register
- extern
- typedef

記憶域にはメモリの割り当て方で3種類に分けられる。自動記憶域のスタック領域と、静的記憶域のスタティック領域とヒープ領域。
また、この他にもデータを記憶する領域としてCPU内のレジスタが使われることがある。

メモリの割り当てや管理の方法は、第16回で詳しく学習する。

## autoとstatic

スタック領域では自動的にメモリの割り当てと解除が行われる。したがって自動変数と呼ばれ、記憶クラス名は「auto」を用いるが、記述を省略するのが一般的。
記憶域クラスの指定のない変数は自動変数として扱われる。
スタティック領域ではプログラムの起動時にメモリが割り当てられ、プログラム終了時まで割り当てが変化しない。記憶クラス名は「static」を用いる。

```c
#include <stdio.h>

int main(void) {
    int num1 = 10;
    int num2 = 20;
    static int num3 = 30;
    
    printf("num1の値は%d\n", num1);
    printf("num2の値は%d\n", num2);
    printf("num3の値は%d\n", num3);
    
    return 0;
}
```

## register

レジスタはアクセスが比較的高速で、可能な限り高速に処理したい場合に用いられる。記憶クラス名は「register」を使用。

```c
#include <stdio.h>

int main(void) {
    register int num1 = 10;
    register int num2 = 20;
    
    printf("num1の値は%d\n", num1);
    printf("num2の値は%d\n", num2);
    
    return 0;
}
```

:::note warn
必ずしも高速になるとは限らないらしい
:::

## extern

複数のファイルで共通して使用する変数を宣言する場合に用いられる。記憶クラス名は「extern」を使用。

```c
#include <stdio.h>

extern int num;

int main(void) {
    printf("numの値は%d\n", num);
    
    return 0;
}
```

```c
#include <stdio.h>

int num = 10;
```

使用される度に値が更新される。
ソースコード全体での利用ができるため、ヘッダファイルに記述することが多い。
また、グローバル変数として宣言する際にも使用される。

## typedef

データ型に新しい型を付ける場合に使用し、構造体を宣言するときなどによく使われる。記憶クラス名は「typedef」を使用。
構造体については第14回で学習する。

# 形修飾子

形修飾子とは、変数の型の前に付けて、変数の値の範囲を拡張したり、変数に性質を付け加えるもの。

| 形修飾子     | 説明    |
|----------|-------|
| short    | 短     |
| long     | 長     |
| signed   | 符号付き  |
| unsigned | 符号なし  |
| const    | 定数    |
| restrict | 最適化促進 |
| volatile | 最適化抑制 |

## const

constは定数を宣言するときに使用する。定数は変数とは異なり、値を変更することができない。

書き換えようとしても

```c
#include <stdio.h>

int main(void) {
    const int num = 10;
    
    printf("numの値は%d\n", num);
    
    num = 20;
    
    printf("numの値は%d\n", num);
    
    return 0;
}
```

エラーになる

```
error: read-only variable is not assignable
```

## restrict

restrictは、ポインタ変数に付けて、そのポインタ変数が指し示すメモリ領域が、そのポインタ変数以外からアクセスされないことを示す。
ポインタは第11回以降で学習する。

## volatile

volatileは、割り込み処理や他のスレッドから変数が変更される可能性がある場合に指定する。
変数がコンパイラの知らないうちで変更される場合に使われ、コンパイラの最適化によって起こる不具合を回避することができる。

# まとめ

- 変数は、データを記憶するためのメモリ領域に付けられた名前
- 変数の宣言は、変数名と型を指定する
- 変数の初期化は、変数の宣言時に値を代入する
- 変数の宣言時に記憶域クラスを指定することで、変数のメモリ上の配置を指定することができる
- 変数の型の前に形修飾子を付けることで、変数の値の範囲を拡張することができる
- 定数は、値を変更することができない変数

# 次回

**入力と出力**：`printf()`と`scanf()`関数を使って、標準入出力を行う方法を学びます。
