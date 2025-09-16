# push_swap

정수 스택을 최소한의 명령으로 정렬하는 프로그램. 두 개의 스택(`a`, `b`)과 제한된 명령어 집합을 사용하여 주어진 입력을 정렬한다.
- **push_swap**: 입력을 받아 최적의 명령어 시퀀스를 출력하는 메인 프로그램
- **checker**: 명령어를 받아 시뮬레이션하여 입력이 정렬되었는지 확인하는 프로그램

## 알고리즘 개요
`push_swap`은 입력 크기에 따라 정렬 방식을 다르게 최적화한다:
* 3개 이하: 조건 분기
* 5개 이하: 최소한의 스왑+삽입 정렬
* 그 이상: 분할 정복 기반의 퀵소트 변형

## 디렉토리 구조

```
push_swap/ 
├── docs/                               # 프로젝트 문서 디렉토리
│   └── 00_requirements.md                 # 과제 요구사항 정리 문서
├── includes/                           # 헤더 파일 디렉토리 (함수 선언 및 자료구조 정의)
│   ├── checker.h                          # checker 전용 함수 및 자료구조 선언
│   ├── common.h                           # 공통 유틸리티 및 구조체 선언
│   └── push_swap.h                        # push_swap 전용 함수 및 자료구조 선언
├── libft/                              # 서브모듈 - libft 사용자 정의 표준 라이브러리
│   ├── Makefile                           # libft 전용 Makefile
│   ├── includes/                          # libft용 헤더 디렉토리
│   └── srcs/                              # libft 함수 소스 코드
├── srcs/                               # push_swap 주요 소스 코드 디렉토리
│   ├── checker/                           # checker 프로그램 관련 코드
│   │   ├── sort_cmd/                        # checker 명령어 처리 함수
│   │   └── main.c                           # checker main
│   ├── common/                            # push_swap & checker 공통 모듈
│   │   ├── cmd/                             # 스택 명령어 실행 함수 (push, swap, rotate 등)
│   │   └── set/                             # 입력 파싱, 리스트 생성 등 환경 설정 함수
│   └── push_swap/                      # push_swap 프로그램 관련 코드
│       ├── quick_sort/                      # 퀵소트 기반 정렬 로직 구현
│       └── main.c                           # push_swap main
├── tests/                              # 테스트 디렉토리
│   └── test.sh                            # 테스트 자동 실행 스크립트
├── Makefile                            # 전체 빌드 자동화 파일 (push_swap, checker, libft 포함)
└── README.md                           # 프로젝트 설명, 사용법, 빌드 방법 등 정리한 문서
```


## 빌드 및 실행 방법 

| 명령어            | 설명                                 |
| -------------- | ---------------------------------- |
| `make`         | `push_swap`, `checker`, `libft` 빌드 |
| `make checker` | checker 바이너리만 빌드                   |
| `make clean`   | 객체 파일(.o) 제거                       |
| `make fclean`  | 실행 파일, 객체 파일, libft 제거             |
| `make re`      | 전체 클린 후 다시 빌드                      |
| `make test`    | `push_swap`, `checker` 빌드 후 테스트    |

### 빌드

```bash
make
```

* `push_swap`과 `checker`가 함께 컴파일됩니다.
* 내부적으로 `libft`도 자동으로 컴파일됩니다.

### 실행 방법

### 1. push\_swap

```bash
./push_swap [숫자들]
```

* 예시:

```bash
./push_swap 3 2 1
```

* 출력: 주어진 숫자를 정렬하기 위한 명령어 시퀀스

### 2. checker

```bash
./push_swap [숫자들] | ./checker [같은 숫자들]
```

또는

```bash
echo "명령어들" | ./checker [숫자들]
```

* 예시:

```bash
./push_swap 3 2 1 | ./checker 3 2 1
# 출력: OK (정렬 성공) 또는 KO (실패)
```

### 테스트 방법

테스트 자동 실행:

```bash
make test
```
* `./tests/test.sh` 스크립트를 실행한다.

