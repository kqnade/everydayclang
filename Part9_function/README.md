# 関数とは

関数とは処理をまとめて再利用できるようにしたもの

## 関数の定義

関数は以下のように定義する

```c
戻り値の型 関数名(引数1の型 引数1の名前, 引数2の型 引数2の名前, ...) {
    処理
}
```

例えば、以下のように定義すると、`int`型の引数を2つ受け取り、その和を返す関数が定義できる

```c
int sum(int a, int b) {
    return a + b;
}
```

## 関数の呼び出し

関数を呼び出すには、以下のようにする

```c
関数名(引数1, 引数2, ...)
```

例えば、先ほど定義した`sum`関数を呼び出すには、以下のようにする

```c
int a = 1;
int b = 2;
int c = sum(a, b);
```

## 関数の戻り値

関数の戻り値は、`return`文で指定する

```c
return 戻り値;
```

例えば、先ほど定義した`sum`関数の戻り値は、以下のように指定する

```c
return a + b;
```

## 関数の引数

関数の引数は、関数の定義と呼び出しの両方で、以下のように指定する

```c
関数名(引数1の値, 引数2の値, ...)
```

例えば、先ほど定義した`sum`関数の引数は、以下のように指定する

```c
sum(a, b);
```

## 関数の戻り値の型

関数の戻り値の型は、関数の定義と呼び出しの両方で、指定する

## プロトタイプ宣言

関数の定義よりも前に、関数のプロトタイプ宣言を行うことで、関数の定義よりも後に関数を呼び出すことができる

```c
戻り値の型 関数名(引数1の型 引数1の名前, 引数2の型 引数2の名前, ...);
```

例えば、以下のようにすると、`sum`関数のプロトタイプ宣言を行っている

```c
int sum(int a, int b);
```
