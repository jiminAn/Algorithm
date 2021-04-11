# LIST

## 1차시. List

### List의 특성
: 순서를 가진 데이터의 집합을 가리키는 추상자료형(abstract data type)
1. 동일한 데이터를 가지고 있어도 됨
2. 구현 방법에 따라 크게 두가지로 나뉨
- 순차 List : 배열을 기반으로 구현됨
- 연결 List : 메모리의 동적할당을 기반으로 구현됨

### List의 주요 함수
- addtoFirst() : List 앞에 원소 추가
- addtoLast() : List 뒤에 원소 추가
- add() : List의 특정 위치에 원소 추가
- delete() : List의 특정 위치에 원소 삭제
- get() : List의 특정 위치에 있는 원소 반환

### 순차List
1. 구현 방법
- 1차원 배열에 항목들을 순서대로 저장
- 데이터의 종류와 구조에 따라 구조화된 자료구조를 만들어 배열로 구현할 수 있음(ex. struct Person...)
2. 데이터 접근
- 배열의 인덱스를 이용해 원하는 위치의 데이터에 접근할 수 있음
3. 삽입 연산, 삭제 연산
- 삽입/삭제 위치 다음의 항목들을 이동해야 함 -> 비효율적

### 단순 배열을 이용한 순차List 구현의 단점
1. 자료의 삽입/삭제 연산 시 연속적인 메모리 배열을 위해 원소들을 이동시키는 작업이 필요
2. 원소의 개수가 많고, 삽입/삭제 연산이 빈번하게 일어날수록 작업에 소요되는 시간이 크게 증가
3. 배열의 크기가 정해져 있는 경우, 실제 사용될 메모리보다 크게 할당하는 메모리 낭비가 발생할 수 있으며 반대로 할당된 메모리보다 많은 자료를 사용하여 새롭게 배열을 만들어 작업을 해야 하는 경우가 발생할 수도 있음

### 연결List
: 단순 배열을 이용한 순차List의 단점을 보완한 자료 구조
1. 자료의 논리적인 순서와 메모리 상의 물리적인 순서가 비일치
2. 개별적으로 위치하고 있는 원소의 주소를 연결하여 하나의 전체적인 자료구조를 이룸
3. 링크를 통해 원소에 접근하므로 순차List에서 물리적인 순서를 맞추기 위한 작업이 불필요
4. 자료구조의 크기를 동적으로 조정할 수 있어, 메모리의 효율적 사용 가능
5. 단점: 구현이 복잡

### 연결List의 구조
1. 노드. 
: 연결 List에서 하나의 원소에 필요한 데이터를 갖고 있는 자료단위
- 데이터 필드 : 원소의 값을 저장하는 자료구조
- 링크 필드 : 다음 노드의 주소를 저장하는 자료구조
2. 헤드. 
: List의 처음 노드를 가리키는 자료구조

### 단순 연결 삽입정렬
: 노드가 하나의 링크 필드에 의해 다음 노드와 연결되는 구조

### 이중 연결 List
: 양쪽 방향으로 순회할 수 있도록 노드를 연결한 List로 두 개의 링크 필드와 한개의 데이터 필드로 구성



## 2차시. 삽입정렬

### 삽입정렬의 특징
- 도서관 사서가 책을 정렬할 때, 일반적으로 활용되는 방식
- 자료 배열의 모든 원소들을 앞에서부터 차례대로 이미 정렬된 부분과 비교하여, 자신의 위치를 찾아냄으로써 정렬을 완성
 - 삽입정렬의 정렬 과정
 1. 정렬할 자료를 두 개의 부분집합 S,U로 가정    
 S : 정렬된 앞부분의 원소들 
 U : 아직 정렬되지 않은 나머지 원소들
 2. U의 원소를 하나씩 꺼내 S의 마지막 원소부터 비교하며 위치를 찾아 삽입
 3. U가 공집합이 될 때까지 이를 반복


## 3차시. 병합정렬

### 병합정렬의 특징
: 여러 개의 정렬된 자료의 집합을 병합하여 한 개의 정렬된 집합으로 만드는 방식
1. 분할 정복 알고리즘 활용
- 자료를 최소 단위의 문제까지 나눈 후에 차례대로 정렬하여 최종 결과를 얻어냄
- Top-Down 방식
2. 시간 복잡도
- O(nlogn)


## 4차시. List의 활용

### List를 이용한 Stack
1. Stack의 원소 : List의 노드
- Stack 내의 순서는 List의 링크를 통해 연결됨
- Push: List의 마지막 노드 삽입
- Pop: List의 마지막 노드 반환/삭제

2. 변수 Top
- List의 마지막 노드를 가리키는 변수
- 초기 상태 Top = NULL  

### 우선순위 큐
1. 우선순위 큐의 구현
- 배열 이용
- List 이용
2. 우선순위 큐의 기본 연산
- 삽입 : enQueue
- 삭제 : deQueue

### 배열을 이용한 우선순위 큐 구현
- 원소를 삽입하는 과정에서 우선순위를 비교하여 적절한 위치에 삽입하는 구조
- 가장 앞에 최고 우선순위의 원소가 위치하게 됨
- 문제점 : 배열을 사용하므로, 삽입/삭제 연산이 일어날 때 원소의 재배치가 발생하여 소요 시간과 메모리 낭비가 큼

### List를 이용한 우선순위 큐 구현
- 연결 List를 이용하여 자료 저장
- 배열 대비 장점
1. 삽입/삭제 연산 이후 원소의 재배치가 필요 없음
2. 메모리의 효율적인 사용이 가능함