#include "pch.h"
#include "Vector2.h"

float Vector2::Length() const
{
    // 벡터의 유클리드 길이(크기)를 계산합니다.
    return sqrt(_x * _x + _y * _y);

    /*
    역할: 벡터의 길이(크기)를 계산합니다.
    작동 원리: 벡터의 각 성분 𝑥 와 𝑦 의 제곱을 더한 후, 그 합의 제곱근을 구합니다.
    이는 2차원 벡터의 유클리드 거리 공식을 사용한 것입니다
    */
}

float Vector2::Distance(Vector2 other) const
{
    Vector2 temp = other - *this;

    return temp.Length();
}

void Vector2::Normalize()
{
    // 벡터의 길이를 계산합니다.
    float length = Length();
    if (length != 0)
    {
        // 각 요소를 길이로 나누어 단위 벡터를 만듭니다.
        _x /= length;
        _y /= length;
    }

    /*
    역할: 벡터를 단위 벡터로 만듭니다. 단위 벡터는 길이가 1인 벡터를 의미합니다.
    작동 원리: 먼저, 벡터의 길이를 계산합니다.
    길이가 0이 아닌 경우, 벡터의 각 성분을 그 길이로 나누어 정규화합니다.
    예를 들어, 벡터가 (3, 4)일 경우, 길이는 5입니다. 이를 정규화하면, 
    (3/5,4/5)=(0.6,0.8)이 됩니다.
    길이가 0인 벡터는 이미 영벡터이므로, 나눗셈을 할 필요가 없습니다.
    */
}

Vector2 Vector2::NormalVector2()
{
    // 벡터의 길이를 계산합니다.
    float length = Length();

    Vector2 temp = *this;
    temp.Normalize();

    return temp;

    //if (length != 0)
    //{
    //    // 새로운 정규화된 벡터를 반환합니다.
    //    return Vector2(_x / length, _y / length);
    //}
    //// 벡터가 영벡터인 경우, 영벡터를 반환합니다.
    //return Vector2(0, 0);

    /*
    역할: 현재 벡터의 정규화된 버전을 새로운 벡터로 반환합니다.
    작동 원리:
    먼저, 벡터의 길이를 계산합니다.
    길이가 0이 아닌 경우, 각 성분을 길이로 나눈 새로운 벡터를 반환합니다.
    예를 들어, 벡터가 (3, 4)일 경우, 길이는 5입니다. 정규화된 새로운 벡터는 (0.6, 0.8)이 됩니다.
    벡터가 영벡터(0, 0)인 경우, 나누기를 할 필요 없이 영벡터를 반환합니다.
    */
}
