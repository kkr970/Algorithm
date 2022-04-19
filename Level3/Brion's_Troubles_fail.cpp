#include <string>
#include <unordered_map>
#include <unordered_set>
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

    //--------------------�ܾ� ����-------------------------
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
    
    //-------------------�ܾ� ��ȯ ����-----------------------
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
    testcase.push_back("AAA");
    testcase.push_back("AaA");
    testcase.push_back("aAAAa");
    testcase.push_back("bAaAaAb");

    testcase.push_back("cAaAaABbBbBc");

    for (int i = 0; i < testcase.size(); ++i)
    { 
        cout << testcase[i] << '[' << solution(testcase[i]) << ']' << '\n';
    }
    return 0; 
}

// https://programmers.co.kr/learn/courses/30/lessons/1830

/*
��Ģ1 : ���� ���̿� ���� ��ȣ�� ����
��Ģ2 :  ���� �� ���� ���� ��ȣ�� ����
��Ģ3 : ������ ����
�� ��Ģ�� ����� ������ �������

���忡 �����ϴ� �ܾ ã�Ƽ� ���Ϳ� ����

1. ������ Ư������ �����ϴ� ���
    Ư�� ���ڷ� �����Ѵٴ� ���� �ܾ Ư������ ��Ģ 2�� ��
    Ư�����ڸ� ã�� �� ���� temp�� ����, Ư�� ���ڸ� ã���� ����
    ex) aBBBBaBbBbB -> a�� ã�� 2���� a�� ã�� aBBBBa�� ���� ���� ���� :BbBbB
2. ������ �Ϲ� ���ڷ� �����ϴ� ���
    2.1. ���� ���ڰ� Ư�� ������ ��� AaBaC ������ Ư�� ���ڰ� �ݺ��� ����
        -AaBaCxAAAx ó�� x�� �߰��� �� ���� ����, AaBaC�� ����, �������� : xAAAX
        -AaBaCXbXbX ó�� X�� �߰��� �� ���� ����, AaBaC�� ����, �������� : XbXbX

�ܾ ��ü�� ��, �ܾ ���� �ܾ�� ��ȯ
�ܾ ����� �� �ִ� ��Ģ : 1, 2, 1+2, X
-�ܾ Ư������ �����ϴ� ���
    aBBBBa -> ó���� ���� Ư���� �Ȱ��ƾ���(aBBBc, aBBB �� ��� invalid)
    ó���� ���� ���ڸ� ���� BBBB�� ������ ������(����, aBcBcBa�� ��� BcBcB�� ����Ǿ���)
        ��, aa�� ���, ������ �ܾ ���� ������ invalid
-�ܾ �Ϲݹ��ڷ� �����ϴ� ���
    �ܾ�� ������ Ư���� �Ϲ� ���ڰ� �����ư��� ���� ����
    -�߰��� Ư���̳� �Ϲ� ���ڰ� ���ÿ� ���� ������ ��� invalid
    -Ư�����ڰ� �ٸ� ���ڰ� ���� ��� invalid
    -�ܾ��� ���� �Ϲ� ���ڰ� �ƴ� ��� invalid
    Ư�� ���ڸ� ������ �Ϲ� ���ڸ� �����ؼ� ����
    BcBcB -> BBB

��� �ܾ ��ȯ�� ��, answer����, return;

�ùٸ� ������ ���� �� �ִ� ����� ��
�ܾ��� ��� : ���� ��Ģ1, ��Ģ2, ��Ģ12
����-����  AAA,BBB
����-��Ģ1 AAA,BbBbB
����-��Ģ2 AAA,bBBBb
����-��Ģ12 AAA,bBcBcBb

��Ģ1-���� AaAaA,BBB
��Ģ1-��Ģ1 AaAaA,BbBbB
��Ģ1-��Ģ2 AaAaA,bBBBb
��Ģ1-��Ģ12 AaAaA,bBcBcBb

��Ģ2-���� aAAAa,BBB
��Ģ2-��Ģ1 aAAAa,BbBbB
��Ģ2-��Ģ2 aAAAa,bBBBb
��Ģ2-��Ģ12 aAAAa,bBcBcBb

��Ģ12-���� aAcAcAa,BBB
��Ģ12-��Ģ1 aAcAcAa,BbBbB
��Ģ12-��Ģ2 aAcAcAa,bBBBb
��Ģ12-��Ģ12 aAcAcAa,bBdBdBb

�ܾ ����  ""
����        AAA
��Ģ1       AaAaA
��Ģ2       aAAAa
��Ģ12      bAaAaAb

invalid
-���忡 ������ �ִ� ���                A A
-�ϳ��� ��Ģ�� ���� �ܾ ����� ���   abAAba
-Ư�� ��ȣ�� ������ �� ���             aAAaBaBaB
-��Ģ1�� �ܾ��� ��� ���ڿ� �����ؾ� ��  HaEaLaLObWORLDb , HELLO WORLD�� ��� invalid������, HELL O WORLD�� ��� ���
-��Ģ2�� �ϳ��� �ܾ ���Ǿ�� ��     cAaAaABbBbBc
*/
