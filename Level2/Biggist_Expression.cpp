#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

#include <iostream>
using namespace std;

vector<char> operand = {'*', '+', '-'};

long long calculate(long long a, long long b, char op)
{
    if (op == '*')
        return a * b;
    if (op == '+')
        return a + b;
    if (op == '-')
        return b - a;
    return -1;
}

long long infix_to_postfix(string expression)
{
    vector<string> postfix;
    stack<char> op_stack;
    stack<long long> post_stack;

    string num_temp = "";
    for(char c : expression)
    {
        if(c == operand[0])
        {
            postfix.push_back(num_temp);
            num_temp = "";

            //낮은 연산자, 1, 2를 만날 때 까지 진행 == 0인 경우에 진행
            while(!op_stack.empty())
            {
                char top = op_stack.top();
                if(top == operand[0])
                {
                    string temp = "";
                    temp += top;
                    postfix.push_back(temp);
                    op_stack.pop();
                }
                else
                {
                    break;
                }
            }
            op_stack.push(c);
        }
        else if(c == operand[1])
        {
            postfix.push_back(num_temp);
            num_temp = "";

            //낮은 연산자, 2를 만날 때 까지 진행 == 0, 1인 경우에 진행
            while(!op_stack.empty())
            {
                char top = op_stack.top();
                if(top == operand[0] || top == operand[1])
                {
                    string temp = "";
                    temp += top;
                    postfix.push_back(temp);
                    op_stack.pop();
                }
                else
                {
                    break;
                }
            }
            op_stack.push(c);
        }
        else if(c == operand[2])
        {
            postfix.push_back(num_temp);
            num_temp = "";

            //0, 1, 2인 경우에 진행 -> 스택이 빌 때까지 진행
            while(!op_stack.empty())
            {
                char top = op_stack.top();
                string temp = "";
                temp += top;
                postfix.push_back(temp);
                op_stack.pop();
            }
            op_stack.push(c);
        }
        //연산자가 아닌 경우
        else // if(c != operand[0] && c != operand[1] && c != operand[2])
        {
            num_temp += c;
        }
    }
    postfix.push_back(num_temp);
    while(!op_stack.empty())
    {
        char top = op_stack.top();
        string temp = "";
        temp += top;
        postfix.push_back(temp);
        op_stack.pop();
    }

    string one = "";
    one += operand[0];
    string two = "";
    two += operand[1];
    string three = "";
    three += operand[2];
    for(string temp : postfix)
    {
        if(temp == one || temp == two || temp == three)
        {
            long long a = post_stack.top();
            post_stack.pop();
            long long b = post_stack.top();
            post_stack.pop();
            post_stack.push(calculate(a, b, temp[0]));
        }
        else
        {
            post_stack.push(stoll(temp));
        }
    }

    return post_stack.top();
}

long long solution(string expression) {
    long long answer = 0;
    operand = {'*', '+', '-'};

    sort(operand.begin(), operand.end());

    do
    {
        long long result = abs(infix_to_postfix(expression));
        if(answer < result) answer = result;
    }while(next_permutation(operand.begin(), operand.end()));

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/67257

/*
연산자에 대한 string * + - 에 대해 순열을 이용해 우선순위를 지정해줌

중위표기법을 후위표기법으로 변경, stack을 이용해 수를 계산함


--------------다른사람 풀이
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> op;

    int idx = 0;
    for(int i=0;i<expression.size();i++){
        char ch = expression[i];
        if(ch == '*' | ch == '+' | ch == '-'){
            op.push_back(ch);
            nums.push_back(stoi(expression.substr(idx,i-idx)));
            idx = i+1;
        }else if(i == expression.size()-1){
            nums.push_back(stoi(expression.substr(idx,i-idx+1)));
        }
    }

    string prior[6] = {
        "*+-", "*-+",
        "+*-", "+-*", 
        "-*+", "-+*",
    };

    for(int i=0;i<6;i++){
        vector<long long> temp_nums = nums;
        vector<char> temp_op = op;
        string pr = prior[i];
        for(int j=0;j<3;j++){
            for(int k=0;k<temp_op.size();k++){
                if(pr[j] == temp_op[k]){
                    if(pr[j] == '*'){
                        temp_nums[k] = temp_nums[k]*temp_nums[k+1];
                        temp_nums.erase(temp_nums.begin()+k+1);
                    }else if(pr[j] == '+'){
                        temp_nums[k] = temp_nums[k]+temp_nums[k+1];
                        temp_nums.erase(temp_nums.begin()+k+1);
                    }else if(pr[j] == '-'){
                        temp_nums[k] = temp_nums[k]-temp_nums[k+1];
                        temp_nums.erase(temp_nums.begin()+k+1);
                    }
                    temp_op.erase(temp_op.begin()+k--);
                }
            }
        }
        answer = max(answer, abs(temp_nums[0]));
    }

    return answer;
}
*/