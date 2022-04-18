#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

bool chkWord(string word)
{
    for(char c : word)
        if('a' <= c && c <= 'z')
            return false;
    return true;
}


string solution(string sentence) {
    string answer = "";
    string invalid = "invalid";
    vector<string> words;
    unordered_map<char, int> special_char;

    //--------------------단어 추출-------------------------
    string temp = "";
    for(int i = 0 ; i < sentence.length() ; i++)
    {
        char c = sentence[i];

        if('a' <= c && c <= 'z')
        {
            temp += c;
            do
            {
                i++;
                if(sentence[i] == ' ') return invalid;
                temp += sentence[i];
                if(i == sentence.length()) return invalid;
            }while(sentence[i] != c);
            words.push_back(temp);
            temp = "";
        }
        else if('A' <= c && c <= 'Z')
        {
            if(i == sentence.length() - 1)
            {
                temp += c;
                words.push_back(temp);
                temp = "";
            }
            else if('a' <= sentence[i+1] && sentence[i+1] <= 'z')
            {
                int j = i+2;
                int chk = 0;
                for( ; j < sentence.length() ; j++)
                {
                    if(sentence[i+1] == sentence[j])
                    {
                        chk = j;
                        break;
                    }
                }
                if(chk - i > 3)
                {
                    temp += c;
                    words.push_back(temp);
                    temp = "";
                    continue;
                }

                if(temp != "")
                {
                    words.push_back(temp);
                    temp = "";
                }
                temp += c;
                c = sentence[i+1];

                bool isSpecial = true;
                while(1)
                {
                    i++;
                    if(sentence[i] == ' ') return invalid;
                    if(isSpecial && sentence[i] == c)
                    {
                        temp += sentence[i];
                        isSpecial = false;
                    }
                    else if(!isSpecial && 'A' <= sentence[i] && sentence[i] <= 'Z')
                    {
                        temp += sentence[i];
                        isSpecial = true;
                    }
                    else
                    {
                        i--;
                        words.push_back(temp);
                        temp = "";
                        break;
                    }
                }
            }
            else
            {
                temp += c;
            }
        }
        else if(c == ' ')
        {
            return invalid;
        }
    }
    
    //-------------------단어 변환 시작-----------------------
    for(int i = 0 ; i < words.size() ; i++)
    {
        //cout << words[i] << "\n";
        char c = words[i][0];

        if('a' <= c && c <= 'z')
        {
            special_char[c]++;
            if(special_char[c] > 1) return invalid;
            if(words[i][words[i].length()-1] != c) return invalid;
            words[i] = words[i].substr(1, words[i].length()-2);
            if(words[i].length() < 1) return invalid;
        }
        if(words[i].length() > 1)
        {
            c = words[i][1];
            if('a' <= c && c <= 'z')
            {
                special_char[c]++;
                if(special_char[c] > 1) return invalid;

                bool isSpecial = false;
                temp = "";
                for(int j = 0 ; j < words[i].length() ; j++)
                {
                    char cur_c = words[i][j];
                    if(cur_c == c && isSpecial)
                    {
                        isSpecial = false;
                    }
                    else if('A' <= cur_c && cur_c <= 'Z' && !isSpecial)
                    {
                        temp += cur_c;
                        isSpecial = true;
                    }
                    else
                    {
                        return invalid;
                    }
                }
                if(!isSpecial) return invalid;
                words[i] = temp;
                temp = "";
            }
        }
        if(!chkWord(words[i])) return invalid;
    }
    
    for(int i = 0 ; i < words.size() ; i++)
    {
        answer += words[i];
        if(i < words.size() - 1) answer += " ";
    }

    return answer;
}

int main(){
    vector<string> testcase;

/*
    testcase.push_back("SpIpGpOpNpGJqOqA"); //SIGONG JOA
    testcase.push_back("HaEaLaLaObWORLDb"); //HELLO WORLD
    testcase.push_back("A"); //A
    testcase.push_back("HELLOWORLD"); //HELLOWORLD
    testcase.push_back("aHbEbLbLbOacWdOdRdLdDc"); //HELLO WORLD
    testcase.push_back("HaEaLaLObWORLDb"); //HELL O WORLD
    testcase.push_back("AAA"); //AAA
    testcase.push_back("aHELLOWORLDa"); //HELLOWORLD
    testcase.push_back("AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR"); //AA ABA BBBB C BBBB C BB GG GGG RRRRRR
    testcase.push_back("aIaAM"); //I AM
    testcase.push_back("bAaOb"); //AO
    testcase.push_back("AxAxAxAoBoBoB"); //invalid
    testcase.push_back("a"); //invalid
    testcase.push_back("Aa"); //invalid
    testcase.push_back("aA"); //invalid
    testcase.push_back("HaEaLaLaOWaOaRaLaD"); //invalid
    testcase.push_back("abHELLObaWORLD"); //invalid
    testcase.push_back("aHELLOa bWORLDb"); //invalid
    testcase.push_back("TxTxTxbAb"); //invalid
    testcase.push_back("bTxTxTaTxTbkABaCDk"); //invalid
    testcase.push_back("baHELLOabWORLD"); //invalid
    testcase.push_back("AxAxAxABcBcBcB"); //AAAA BBBB
    testcase.push_back("A B"); //invalid
    testcase.push_back("oBBoA"); //BB A
    testcase.push_back("AxAxAxA"); //AAAA
    testcase.push_back("HaEaLaLaObWORLDbSpIpGpOpNpGJqOqAdGcWcFcDdeGfWfLeoBBoAAAAxAxAxAA"); //HELLO WORLD SIGONG J O A GWFD GWL BB AAA AAAA A
    testcase.push_back("aBcAadDeEdvAvlElmEEEEm"); //BA DE A E EEEE
    testcase.push_back("aGbWbFbDakGnWnLk"); //GWFD GWL
    testcase.push_back("aCaCa"); //invalid
    testcase.push_back("aHbEbLbLbacWdOdRdLdDc"); //invalid
    testcase.push_back("HELLOWbObRbLb"); //invalid
    testcase.push_back("aaA"); //invalid
    testcase.push_back("Aaa"); //invalid
    testcase.push_back("xAaAbAaAx"); //invalid
    testcase.push_back("AbAaAbAaCa"); //invalid
    testcase.push_back("AbAaAbAaC"); //invalid
    testcase.push_back("XcXbXcX"); //X XX X
*/
    testcase.push_back("AAABBB");
    testcase.push_back("AAABbBbB");
    testcase.push_back("AAAbBBBb");
    testcase.push_back("AAAbBcBcBb");

    testcase.push_back("AaAaABBB");
    testcase.push_back("AaAaABbBbB");
    testcase.push_back("AaAaAbBBBb");
    testcase.push_back("AaAaAbBcBcBb");

    testcase.push_back("aAAAaBBB");
    testcase.push_back("aAAAaBbBbB");
    testcase.push_back("aAAAabBBBb");
    testcase.push_back("aAAAabBcBcBb");
    
    testcase.push_back("aAcAcAaBBB");
    testcase.push_back("aAcAcAaBbBbB");
    testcase.push_back("aAcAcAabBBBb");
    testcase.push_back("aAcAcAabBdBdBb");

    testcase.push_back("");
    testcase.push_back("A A");
    testcase.push_back("aa");
    testcase.push_back("AAaAA");

    for (int i = 0; i < testcase.size(); ++i)
    { 
        cout << testcase[i] << '[' << solution(testcase[i]) << ']' << '\n';
    }
    return 0; 
}

// https://programmers.co.kr/learn/courses/30/lessons/1830

/*
규칙1 : 글자 사이에 같은 기호를 넣음
규칙2 :  글자 양 끝에 같은 기호를 넣음
규칙3 : 공백을 제거
의 규칙을 사용해 광고문이 만들어짐

문장에 존재하는 단어를 찾아서 벡터에 저장

1. 문장이 특문으로 시작하는 경우
    특수 문자로 시작한다는 것은 단어를 특문으로 규칙 2인 것
    특수문자를 찾을 때 까지 temp에 저장, 특수 문자를 찾으면 종료
    ex) aBBBBaBbBbB -> a를 찾고 2번쨰 a를 찾아 aBBBBa를 저장 남은 문장 :BbBbB
2. 문장이 일반 문자로 시작하는 경우
    2.1. 다음 문자가 특수 문자인 경우 AaBaC 식으로 특수 문자가 반복될 것임
        -AaBaCxAAAx 처럼 x를 발견할 떄 까지 저장, AaBaC를 저장, 남은문장 : xAAAX
        -AaBaCXbXbX 처럼 X를 발견할 떄 까지 저장, AaBaC를 저장, 남은문장 : XbXbX

단어를 해체한 후, 단어를 원래 단어로 변환
단어에 적용될 수 있는 규칙 : 1, 2, 1+2, X
-단어가 특문으로 시작하는 경우
    aBBBBa -> 처음과 끝의 특문이 똑같아야함(aBBBc, aBBB 인 경우 invalid)
    처음과 끝의 문자를 지워 BBBB만 추출해 저장함(또한, aBcBcBa인 경우 BcBcB가 저장되어짐)
        단, aa인 경우, 내부의 단어가 없기 떄문에 invalid
-단어가 일반문자로 시작하는 경우
    단어는 무조건 특문과 일반 문자가 번갈아가며 나올 것임
    -중간에 특문이나 일반 문자가 동시에 같이 나오는 경우 invalid
    -특수문자가 다른 문자가 나올 경우 invalid
    -단어의 끝이 일반 문자가 아닌 경우 invalid
    특수 문자를 제외한 일반 문자를 추출해서 저장
    BcBcB -> BBB

모든 단어를 변환한 뒤, answer저장, return;

문장이 나올 수 있는 경우의 수
단어의 경우 : 없음 규칙1, 규칙2, 규칙12

없음-없음  AAA,BBB
없음-규칙1 AAA,BbBbB
없음-규칙2 AAA,bBBBb
없음-규칙12 AAA,bBcBcBb

규칙1-없음 AaAaA,BBB
규칙1-규칙1 AaAaA,BbBbB
규칙1-규칙2 AaAaA,bBBBb
규칙1-규칙12 AaAaA,bBcBcBb

규칙2-없음 aAAAa,BBB
규칙2-규칙1 aAAAa,BbBbB
규칙2-규칙2 aAAAa,bBBBb
규칙2-규칙12 aAAAa,bBcBcBb

규칙12-없음 aAcAcAa,BBB
규칙12-규칙1 aAcAcAa,BbBbB
규칙12-규칙2 aAcAcAa,bBBBb
규칙12-규칙12 aAcAcAa,bBdBdBb

invalid
-문장에 공백이 있는 경우
-하나의 규칙을 같은 단어에 사용한 경우
-특수 기호를 여러번 쓴 경우
-규칙1은 모든 단어에 사용되야함
-규칙2는 하나의 단어에 사용되어야 함
*/
