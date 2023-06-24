---
title: 初心者C言語 第2回 「Hello, World!をしてみる」
tags: C 初心者 HelloWorld C言語入門 初心者エンジニア
author: k4nade
slide: false
---

# ここまでのあらすじ
ことの発端

https://qiita.com/k4nade/items/f65f518d2b795407a797

前回　

https://qiita.com/k4nade/items/16d83cafb59e9753934c

前回は、環境構築ができました。

# 今回のテーマ　「Hello, World!」

- なぜかプログラミングの一番最初のコードとして扱われる「Hello World!」を実装する。
- 「Hello, World!」を通して基本的な構造を理解する。
- Clionの基礎的な操作を理解する。

# やってみよう

とりあえず先駆者さんたちの記事を見ながらコードを書いてみる。

CLionを開いて、新規プロジェクトを作る。
![image.png](https://qiita-image-store.s3.ap-northeast-1.amazonaws.com/0/2821686/fbe46266-fbfa-6473-f636-6358743465e1.png)

![image.png](https://qiita-image-store.s3.ap-northeast-1.amazonaws.com/0/2821686/7627e03e-dff1-0dc6-244b-c0227314e9ac.png)

![image.png](https://qiita-image-store.s3.ap-northeast-1.amazonaws.com/0/2821686/28260b6f-8c1c-83c6-4d8c-423f76829c7b.png)

![image.png](https://qiita-image-store.s3.ap-northeast-1.amazonaws.com/0/2821686/1933ae75-15c6-986c-50d2-994ba9c65913.png)

**も...もうある...**
昨日の時点で気づいてはいたけど新規プロジェクト作ったらHelloWorldのコード自動で作られる...

## 書いてあること調べてみる。

```c
// ヘッダーファイルをインクルード
#include <stdio.h>

// main関数
int main() {
    // printf関数で文字列を表示
    printf("Hello, world!\n");

    // 終了ステータスを返す
    return 0;
}
```
1. `#include <stdio.h>`: この行は、ヘッダーファイル`stdio.h`をインクルードしている。`stdio.h`に定義されているマクロ、型や関数を利用できるようにしている。
2. `int main()`: `main`関数は、C言語プログラムのエントリーポイント（開始点）です。`int`は、関数が整数を返すことを示しています。
3. `{`と`}`: 関数の処理内容を波括弧で囲む必要がある。
4. `printf("Hello, world!\n");`: `printf`関数は、標準出力（通常は画面）にテキストを表示するための関数。サンプルコードでは、`Hello, world!`という文字列と`\n`（改行文字）が表示される。各文はセミコロン（;）で終わる必要がある。
5. `return 0;`: `main`関数の最後に、`return`キーワードを使って終了ステータスを返す。`0`は、成功を意味する標準的な値。これもセミコロンで終わる必要がある。
このプログラムをコンパイルして実行すると、`Hello, world!`という表示ができますよと。

案外書きやすいのかも。
今回はここまで!

# 次回予告
**変数とデータ型**：C言語での変数の宣言、初期化、基本データ型（整数型、浮動小数点型、文字型）を学びます。

