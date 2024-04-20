#include <iostream>
#include <vector>
#include <string>

using namespace std;
string solution0(vector<int>);
vector<int> solution1(vector<int>);
vector<int> solution2(vector<int>, vector<vector<int>>);
vector<int> solution3(vector<int>, vector<vector<int>>);

vector<int> solution4(vector<int>, vector<vector<int>>);
vector<int> solution5(int, int);
vector<int> solution6(int, int);
vector<int> solution7(int);
vector<int> solution8(vector<int>);

int main()
{
}

// https://school.programmers.co.kr/learn/courses/30/lessons/181925
// 수 조작하기 2
//  w: +1/ s: -1/ d: +10/ a: -10
// i와 i+1의 차이에따라 wsda를 찾아내기
string solution0(vector<int> numlog)
{
    string answer = "";

    for (int i = 1; i < numlog.size(); i++)
    {
        if (numlog[i] - numlog[i-1] == 1)
            answer += "w";
        else if (numlog[i] - numlog[i - 1] == -1)
            answer += "s";
        else if (numlog[i] - numlog[i - 1] == 10)
            answer += "d";
        else
            answer += "a";


        /*
        int num = (numLog[i + 1] - numLog[i]);
        switch (num)
        {
        case 1:
            answer.push_back('w');
            break;

        case -1:
            answer.push_back('s');
            break;

        case 10:
            answer.push_back('d');
            break;

        case -10:
            answer.push_back('a');
            break;
        }
        */
    }
    return answer;
}

// https://school.programmers.co.kr/learn/courses/30/lessons/181927
// 마지막 두 원소
// 마지막의 값이 마지막-1의 값보다 크면 마지막 값 - 마지막 전값 을 추가
// 마지막의 값이 마지막-1의 값보다 작다면 마지막*2의 값을 추가
vector<int> solution1(vector<int>num_list)
{
    int size = num_list.size()-1;
    if (num_list[size] > num_list[size - 1])
    {
        num_list.push_back(num_list[size] - num_list[size - 1]);
    }
    else
    {
        num_list.push_back(num_list[size] * 2);
    }
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181924
// 수열과 구간 쿼리3
// queries의 [i,j]의 값은 arr[i]와 arr[j]를 뜻하고, arr[i]와  arr[j]의 위치를 바꾸는 함수
// ->queries[i][0]과 queries[i][1]의 값을 가져와서 해결한다.
vector<int> solution2(vector<int> arr, vector<vector<int>> queries)
{
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++)
    {
        answer.push_back(arr[i]);
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int temp = answer[queries[i][0]];
        answer[queries[i][0]] = answer[queries[i][1]];
        answer[queries[i][1]] = temp;
       
    }
}

// https://school.programmers.co.kr/learn/courses/30/lessons/181924
// 수열과 구간 쿼리2
// queries는 [s,e,k]로 이루어져있으며, arr[s]부터 arr[e]까지 의 값중 k보다 큰값들 중에서 가장작은 arr[i]를 찾는다. 존재하지 않으면 -1을 저장
vector<int> solution3(vector<int> arr, vector<vector<int>> queries)
{
    vector<int> answer;

    for (int i = 0; i < queries.size(); i++)
    {
        int s, e, k,  min;
        
        s = queries[i][0];
        e = queries[i][1];
        k = queries[i][2];
        min = 0;
        for (int j = s; j <= e; j++) 
        {
            // k보다 클 경우만 저장
            if (k < arr[j])
            {
                // k보다 큰 값들 중에서 가장 작은값
                if (min==0)
                {
                    min = arr[j];
                }
                else if (min > arr[j])
                {
                    min = arr[j];
                }
            }
        }
        if (min == 0)
        {
            answer.push_back(-1);
        }
        else
            answer.push_back(min);
    }

    return answer;
}



// https://school.programmers.co.kr/learn/courses/30/lessons/181922
// 수열과 구간 쿼리 4
//  queries는 [s,e,k]로 이루어져있으며, i의 값이 k의 배수라면 arr[i]에 1을 더해준다.
// k = 2일 경우, i가 2의 배수->  arr[0], arr[2], arr[4]의 값에 +1
vector<int> solution4(vector<int> arr, vector<vector<int>> queries)
{
    for (int i = 0; i < queries.size(); i++)
    {
        int s, e, k;
        s = queries[i][0];
        e = queries[i][1];
        k = queries[i][2];
        
        for (int i = s; i <= e; i++)
        {
            if (i % k == 0)
            {
                arr[i] += 1;
            }
        }
    }

    return arr;
}

// https://school.programmers.co.kr/learn/courses/30/lessons/181921
// 배열만들기 2
// l <= n <=r  사이에있는 n의 값이 0과 5로 이루어진 모든 정수를 오름차순으로 저장한 배열을 return
// 없다면 -1이 담긴 배열 return
vector<int> solution5(int l, int r)
{
    vector<int> answer;
    
    for (int i = l; i <= r; i++)
    {
        if (i % 5 == 0)
        {
            string num = to_string(i);
            bool isTrue = true;

            for (char n : num)
            {
                if (n != '0' && n != '5')
                {
                    isTrue = false;
                    break;
                }
            }
            if (isTrue)
            {
                answer.push_back(i);
            }
        }
    }

    if (answer.empty())
    {
        answer.push_back(-1);
    }



    return answer;

}


// https://school.programmers.co.kr/learn/courses/30/lessons/181920
// 카운트 업
vector<int> solution6(int start_num, int end_num)
{
    vector<int> answer;

    for (int i = start_num; i <= end_num; i++)
    {
        answer.push_back(i);
    }

    return answer;
}

// https://school.programmers.co.kr/learn/courses/30/lessons/181919
// 콜라츠 수열 만들기
// n의 값이 짝수면 2로 나누고, 홀수면 3*n+1 을 해준다. 이런식으로 n이 1이 되는것이 콜라츠 문제
// n이 짝수, 홀수 인지 감별하기 전인 연산횟수가 0일때부터 1이 될때까지 나온 숫자들을 모은것이 콜라츠 수열
vector<int> solution7(int n)
{
    vector<int> answer;

    answer.push_back(n);
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;

        }
        else
        {
            n = n * 3 + 1;
        }
        answer.push_back(n);
    }

    return answer;
}

// https://school.programmers.co.kr/learn/courses/30/lessons/181918
// 배열 만들기 4
// 새로운 배열 stk를 만드는것
// 1) stk가 빈 배열이면 arr[i]를 추가하고,  i++
// 2) stk의 마지막원소 < arr[i]라면, stk의 뒤에 arr[i]를 추가하고 i++
// 3) stk의 마지막 원소 => arr[i] 라면, stk마지마가 원소를 제거
//
vector<int> solution8(vector<int> arr)
{
    vector<int> stk;
    int i = 0;
    while(i < arr.size())
    {
        if (stk.empty() == true)
        {
            stk.push_back(arr[i]);
            i++;
        }
        else if (stk.empty()==false && stk.back() < arr[i])
        {
            stk.push_back(arr[i]);
            i++;
        }
        else if (stk.empty() == false && stk.back() >= arr[i])
        {
            stk.pop_back();
        }
    }




    return stk;
}

