# SSU 19 PROGRAMMING(for developer) LECTURE


### 2019.04.30

- `malloc(sizeof(int) * n)` : 메모리 동적 할당
- `calloc(sizeof(int), n)`  : 메모리 동적 할당, 기본 값
- `realloc(sizeof(int), n)` : 메모리 재할당, memcopy없이 주소를 확장, 컨플릭트 나는 경우가 있긴 하나 보통 여유분을 두고 할당하므로 발생하지는 않는다.


*주의할 점*
- 가비지           : 할당은 받았으나, 메모리 주소를 잃어버린 경우
- 댕글링 포인터     : 목짤린 포인터, 포인터는 알고 있으나 이미 다른 코드에서 해제가 되어버린 포인터