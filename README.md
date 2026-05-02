
# push_swap

[日本語](#日本語) | [English](#english) | [한글](#한글)

## 日本語

### 概要
push_swap は スタック操作（`a`, `b`）と限られたコマンドを用いて整数列を最小操作で昇順にソートするプログラムです。`push_swap` は操作列を出力し、`checker` はその操作列で正しくソートされるか検証します。

### 構成
- `push_swap`: 入力を解析し、操作列を標準出力に出すメインプログラム
- `checker`: 操作列を読み込み、ソートの成否を判定するプログラム

### ビルドと実行
```bash
make
```

ビルド後の実行例:
```bash
./push_swap 3 2 1
./push_swap 3 2 1 | ./checker 3 2 1
```

---

## English

### Overview
`push_swap` is using two stacks (`a`, `b`) and a limited set of operations, it computes a (near-)optimal sequence of operations to sort a list of integers in ascending order. `push_swap` prints the operations; `checker` reads them and validates the result.

### Structure
- `push_swap`: main program that reads input and outputs the operation sequence
- `checker`: reads operations and verifies whether the input becomes sorted

### Build & Run
```bash
make
```

Examples:
```bash
./push_swap 3 2 1
./push_swap 3 2 1 | ./checker 3 2 1
```

---

## 한글

### 개요
`push_swap`는 두 개의 스택(`a`, `b`)과 제한된 명령어로 정수 목록을 최소 또는 최소에 가까운 연산으로 오름차순 정렬하기 위한 명령어 시퀀스를 출력하는 프로그램입니다. `checker`는 해당 명령어 시퀀스로 정렬이 성공하는지 확인합니다.

### 구성
- `push_swap`: 입력을 파싱하고 정렬을 위한 명령어 시퀀스를 출력하는 메인 프로그램
- `checker`: 명령어를 읽어 실행한 뒤 정렬 여부를 검사하는 프로그램

### 빌드 및 실행
```bash
make
```

실행 예시:
```bash
./push_swap 3 2 1
./push_swap 3 2 1 | ./checker 3 2 1
```

### Make ターゲット / Make targets
- `make`: `push_swap`, `checker`, `libft` をビルド / build `push_swap`, `checker`, `libft`
- `make checker`: checker のみビルド / build only `checker`
- `make clean`, `make fclean`, `make re`: 通常のクリーン動作 / standard clean targets
- `make test`: テスト実行スクリプトを 실행 / run tests

詳しいディレクトリ構成や実装の詳細は元のドキュメントとソースコードを参照してください。


