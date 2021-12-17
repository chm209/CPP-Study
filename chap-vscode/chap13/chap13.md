# C++ 코드의 재활용

C++가 추구하는 중요한 목표 중의 하나가 코드의 재활용성을 높이는것

public 상속은 한 가지 방법일뿐 이번 장에서는 다른 방법들을 공부한다.

1. 컨테인먼트, 컴포지션, 레이어링: 다른 클래스에 속하는 객체를 클래스 멤버로 사용하는 것 (has-a 관계)
2. private 상속 or protected 상속 (has-a 관계)
3. 클래스 템플릿을 사용: 클래스를 포괄적으로 정의 가능, 그 템플릿을 사용하여 특정한 데이터형에 맞게 정의된 특정한 클래스를 생성할 수 있다.

> has-a 관계: 새로운 클래스가 다른 클래스의 객체를 포함하는 관계

---
## 객체 멤버를 가지는 클래스

템플릿 측면에서 보면, 객체를 선언할 때 구체적인 데이터형을 지정해야 한다.

그렇게 하려면 객체를 선언할 때 원하는 데이터형이 들어 있는 각괄호 앞에 식별자를 붙여야한다.

1. valarray &lt;int> q_values; -> int형의 배열
2. valarray &lt;double> weights; -> double형의 배열

클래스 측면에서 보면 valarray 객체를 사용하기 위해서는 클래스 생성자와 그외 클래스 메서드들에 관해 어떤 것을 알 필요가 있다.

1. valarray &lt;double> v1; -> double형의 배열, 크기 0
2. valarray &lt;int> v2(8); -> int형의 배열, 8개짜리 배열
3. valarray &lt;int> v3(10, 8); -> int형의 배열, 8개짜리 배열, 각각 10으로 설정
4. valarray &lt;double> v4(gpa, 4); -> double형 원소 4개짜리 배열, gpa의 첫 4개의 원소로 초기화

### Student 클래스 설계
학생은 이름이 아니고 성적표도 아니기 때문에 is-a 관계인 public 상속은 적합하지 않다.

학생은 이름과 성적표를 가지기 때문에 has-a 관계로 설계하는게 적합하다.

C++에서 has-a 관계를 모델링하는 일반적인 테크닉은, ```컴포지션(컨테인먼트)```을 사용하는 것이다.

즉, 다른 클래스의 객체들을 멤버로 가지는 클래스를 만드는 것이다.

예를 들면, 아래와 같이 클래스를 시작할 수 있다.

``` cpp
class Student
{
    private:
        string name;
        valarray<double> score;
}
```

보통 그 클래스는 데이터 멤버들을 private으로 선언한다.

##### 인터페이스의 구현
public 상속에서, 클래스는 인터페이스와 구현을 상속한다. 반면 컨테인먼트에서는 어떤 클래스가 인터페이스 없이 구현을 획득한다.