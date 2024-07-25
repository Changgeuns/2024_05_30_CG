24 - 07 - 22
-  언리얼5
-- 게임엔진들은 영화촬영에 비유할 수가 있다.
 => 세트장 : 월드
 => 배우 :  Actor

- 언리얼은 상속구조와 컴포넌트 패턴이 핵심 철학.
-- 언리얼의 모든 오브젝트들은  UObject를 상속받아 만들어진다.
... 앞에 U가 붙으면 UOjbect를 상속받았다는 컨벤션이다.
... Actor만 제외. 그리고  Actor를 상속받는 자식들은 앞에 A가 붙는다.
... F가 붙으면 UObject를 상속받은 객체가 아니다.

UPROPERTY( ? )

ConstructorHelpers
 -  생성자에서 언리얼에디터에 존재(프로젝트 파일에 저장되어있는)하는 정보들을 읽어올 수 있게 도와준다.

// 과제
- ContructHelper::FindObject, FindClass 용도

- Local 과 Local 이 안붙은 수학 함수들의 차이

- 언리얼의 Cast

- 언리얼 엑터의 수명 주기

-Delegate
--1. Delegate_myDelegate3.ExecuteIfBound(50,50)

-- 2. 클래스 객체로 직접 함수 호출 auto myAninI = GetMesh()->GetAnimInstance();
  Cast<UMyAnimInstance>(myAninI)->DelegateTest2(50, 30);
   단점
   - 클래스간의 결합도