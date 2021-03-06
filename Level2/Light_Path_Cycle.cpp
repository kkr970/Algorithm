#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int path_length = 0;
    int v = grid.size(); // 室稽
    int h = grid[0].size(); // 亜稽

    //亜舌 照楕税 汽戚斗 : (蟹姶)雌酔馬疎
    vector<vector<vector<int>>> vec3(v, vector<vector<int>>(h, vector<int>(4, 0)));

    //i-室稽, j-亜稽, k-汽戚斗
    for(int i = 0 ; i < v ; i++)
    {
        for(int j = 0 ; j < h ; j++)
        {
            // 号狽精 蟹亜澗 依幻 持唖馬心製
            for(int k = 0 ; k < 4 ; k++)
            {
                //廃腰亀 紫遂馬走 省精 号狽
                if(vec3[i][j][k] == 0)
                {
                    // 欠闘 貼事 獣拙
                    int a = i;
                    int b = j;
                    int c = k;
                    while(vec3[a][b][c] != 1)
                    {
                        vec3[a][b][c] = 1; //1=path 紫遂
                        path_length++;
                        
                        switch (c)
                        {
                        //是稽 蟹姶
                        case 0:
                            a = ((a+v) - 1)%v;
                            break;
                        //神献楕生稽 蟹姶
                        case 1:
                            b = ((b+h) - 1)%h;
                            break;
                        //焼掘稽 蟹姶
                        case 2:
                            a = (a+1)%v;
                            break;
                        //図楕生稽 蟹姶
                        case 3:
                            b = (b+1)%h;
                            break;
                        default:
                            break;
                        }
                        //葛球拭 魚虞 蟹哀 号狽聖 痕井 / S澗 痕井戚 蒸製
                        if(grid[a][b] == 'R') 
                            c = (c + 1) % 4;
                        else if(grid[a][b] == 'L')
                            c = ((c + 4) - 1) % 4;
                    }
                    answer.push_back(path_length);
                    path_length = 0;
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/86052

/*
grid拭 葛球亜 爽嬢像, 葛球澗 s, r l亜 爽嬢像

脊切雁 級嬢臣 呪 赤澗 号狽精 4亜走, 雌馬疎酔
脊切雁 蟹哀 呪 赤澗 号狽精 4亜走, 雌馬疎酔

脊切 鉱生稽 狽馬檎 鋼企畷拭 赤澗 脊切稽 級嬢姶 -> 壕伸税 鉱聖 込嬢劾 呪 蒸製
笹戚 戚疑馬陥 戚穿拭 走蟹穐揮 井稽研 業旭戚 走蟹亜惟 鞠檎 紫戚適
(sl, lr)
s l
l r
       蟹姶    級嬢身
壕伸 = 雌馬疎酔 雌馬疎酔
S = けけけけ けけけけ L = けけけけ けけけけ
L = けけけけ けけけけ R = けけけけ けけけけ


1. 雌酔馬疎(蟹姶)
1.1)脊切亜 疎酔稽 尻衣吉 壕伸税 index
x1x2/x2x1

1.2)脊切亜 雌馬稽 尻衣吉 壕伸税 index
1x2x
2x1x

->葛球稽 級嬢神澗 汽戚斗亜 琶推廃亜? -> 葛球澗 蟹亜澗 依引 級嬢神澗 依精 牌雌 瞬聖 戚結
    ->琶推 蒸陥壱 持唖馬食 薦暗

号狽聖 痕井
1. S
    -焼掘拭辞 級嬢身
        ->穿 葛球拭辞 是楕生稽 蟹穐生艦 c == 0
        是楕生稽 蟹亜醤 馬艦 c == 0
    -図楕拭辞 級嬢身
        ->穿 葛球拭辞 神献楕生稽 蟹穐生艦 c == 1
        神献楕生稽 蟹亜醤 馬艦 c == 1
    -是拭辞 級嬢身
        ->穿 葛球拭辞 焼掘楕生稽 蟹穐生艦 c == 2
        焼掘楕生稽 蟹絢焼 馬艦 c == 2
    -神献楕拭辞 級嬢身
        ->穿 葛球拭辞 図楕生稽 蟹穐生艦 c == 3
        図楕生稽 蟹亜醤 馬艦 c == 3
    -> 戚穿税 c

2. R
    -焼掘拭辞 級嬢身
        -> 穿 葛球拭辞 是楕生稽 蟹穐生艦 c == 0
        神献楕生稽 蟹絢焼 馬艦 c == 1
    -図楕拭辞 級嬢身
        ->穿 葛球拭辞 神献楕生稽 蟹穐生艦 c == 1
        焼掘楕生稽 蟹亜醤 馬艦 c == 2
    -是拭辞 級嬢身
        ->穿 葛球拭辞 焼掘楕生稽 蟹穐生艦 c == 2
        図楕生稽 蟹絢焼 馬艦 c == 3
    -神献楕拭辞 級嬢身
        ->穿 葛球拭辞 図楕生稽 蟹穐生艦 c == 3
        是楕生稽 蟹亜醤 馬艦 c == 0
    -> 戚穿税 (c + 1) % 4
    
3. L
    -焼掘拭辞 級嬢身
        -> 穿 葛球拭辞 是楕生稽 蟹穐生艦 c == 0
        図楕生稽 蟹絢焼 馬艦 c == 3
    -図楕拭辞 級嬢身
        ->穿 葛球拭辞 神献楕生稽 蟹穐生艦 c == 1
        是楕生稽 蟹亜醤 馬艦 c == 0
    -是拭辞 級嬢身
        ->穿 葛球拭辞 焼掘楕生稽 蟹穐生艦 c == 2
        神献楕生稽 蟹絢焼 馬艦 c == 1
    -神献楕拭辞 級嬢身
        ->穿 葛球拭辞 図楕生稽 蟹穐生艦 c == 3
        焼掘楕生稽 蟹亜醤 馬艦 c == 2
    -> 戚穿税 ((c + 4) - 1) % 4
*/