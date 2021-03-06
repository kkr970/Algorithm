using namespace std;

long long GetGCD(long long a, long long b)
{
    int c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w,int h) {
    long long a = w;
    long long b = h;
    long long gcd = GetGCD(a, b);

    return (a * b) - (agcd + b/gcd - 1) * gcd;
}

// https://programmers.co.kr/learn/courses/30/lessons/62048

/*
持唖
笛 紫唖莫 w x h 聖 企唖識生稽 切硯
蟹袴走 1x1昔 紫唖莫聖 幻球澗汽 置企税 呪研 姥馬澗 依
8 x 12
置企 因鉦呪 4
4*2 x 4*3
-> 2x3 * 4
2x3拭 獄形走澗 紫唖莫 * 4亜 喫

獄形走澗 紫唖莫 姥馬奄
2x3
いけ
いい
けい

1x1
い

3x5
いけけ
いいけ
けいけ
けいい
けけい

->
い戚 焼掘稽 崇送析凶人 神献楕生稽 戚疑拝 凶亜 赤製
い戚 神献楕生稽 戚疑馬澗 恥 判授 亜稽-1 腰績
い戚 焼掘稽 崇送戚澗 恥 判授 歯稽 腰績
聡 亜稽 + 室稽 - 1 聖 馬檎 喫


*/