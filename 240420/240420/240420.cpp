#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool solution0(bool, bool, bool, bool);
int solution1(int, int, int, int);
string solution2(string, vector<int>);
int solution3(string);
string solution4(string, vector<vector<int>>);
vector<int> solution5(vector<string>, int, int, int);
string solution6(vector<string>, vector<vector<int>>);
string solution7(string, int);
vector<string> solution8(string);
int solution9(string, string);
int solution10(vector<vector<int>>);
int solution(vector<string> );
string solution(string my_string, int m, int c);
string solution(string my_string, int n);
int solution(string my_string, string is_prefix);
string solution2(string my_string, int s, int e);
string solution(int q, int r, string code);
vector<int> solution(string my_string);
vector<int> solution(int n, int k);
string solution(string my_string, vector<int> indices);
vector<int> solution(int start, int end_num);
int solution(vector<int> arr, int idx);


int main()
{
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181917
// 간단한 논리 연산
// (x1 V x2) ^ (x3 V x4)의 결과를 return 
bool solution0(bool x1, bool x2, bool x3, bool x4)
{
	bool answer = true; // 최종 return값

	bool left = true; // 왼쪽의 합연산
	bool right = true; // 오른쪽의 합연산

	// 합연산은 true 가 1개만 있어도 true로 반환 된다.
	// 그래서 두개다 false인 경우만 확인해준다.
	if (x1 == false && x2 == false)
	{
		left = false;
	}
	else
	{
		left = true;
	}

	if (x3 == false && x4 == false)
	{
		right == false;
	}
	else
	{
		right = true;
	}

	// 곱연산은 false가 1개만 있어도 false로 반환된다.
	// 두개다  true인 경우만 확인해준다.
	if (left == true && right == true)
	{
		return answer = true;
	}
	else
	{
		return answer = false;
	}
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181916
// 주사위 게임3
// 1) 4개의 숫자가 p로 같다면, 1111*p 점수
// 2) 3개의 숫자가 p로 같고, 나머지 하나가 q라면 (10 * p + q)^2 점수
// 3) 2개의 숫자가 p로 같고, 나머지 2개가 q로 같다면 (p+q) * |p-q| 점수
// 4) 2개의 숫자가 p로 같고, 나머지 2개가 q, r 로 다르다면 q*r 점수
// 5) 4개의 숫자가 다르다면 가장 작은 수를  return
// 같은 숫자가 몇개인지 확인해서 조건에 맞게 점수 return
int solution1(int a, int b, int c, int d)
{
	int answer = 0;
	int num[4] = { a, b, c, d }; // 주사위로 나온 값을 배열에 넣어준다.
	int dice[7] = { 0 ,0, 0, 0, 0, 0, 0 }; // 0 1 2 3 4 5 6 
	// 주사위로 0은 나오지 않기때문에 1부터 6까지 7크기의 배열을 만든다.(0포함)
	// 같은 숫자가 몇 번 나온지 확인해야 해서 각 인덱스를 0으로  초기화 해준다.
	

	// 주사위의 값(num)이 j(1~6)과 같다면 dice[j]의 값을 1 올려준다.
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (num[i] == j)
			{
				dice[j] = dice[j] + 1;
			}
		}
	}


	// 중복이 많은 순 부터 확인한다.
	for (int i = 0; i < 7; i++)
	{
		// 같은 숫자가 4번 나왔을 경우
		if (dice[i]== 4)
		{
			return answer = 1111 * i;
		}
		// 같은숫자가 3번 나왔을 경우
		else if (dice[i] == 3)
		{
			// 0부터 남은 다른 숫자 1개를 찾는다
			for (int j = 0; j < 7; j++)
			{
				if (dice[j] == 1)
				{
					int p = ((10 * i) + j);
					return p * p;
				}
			}
		}
		// 같은 숫자가 2번 나왔을 경우
		else if (dice[i] == 2)
		{
			// 1) 주사위가 2 2 로 나누어진 경우
			// 2번 나온 숫자 i < j 총 2개 이기때문에 j = i + 1 부터 찾는다.
			for (int j = i+1; j < 7; j++)
			{
				
				if (dice[j] == 2)
				{

					return answer = ((i + j) * (j - i));
				}
			}

			// 2) 주사위가 2 1 1 로 나누어진 경우
			// 0부터 다시 1번 나온 숫자를  찾는다.
			for (int j = 0; j < 7; j++)
			{
				if (dice[j] == 1)
				{
					// 1번 나온 숫자가 2개 이기 때문에
					// j < k 이므로 k= j +1 부터 찾는다.
					for (int k = j+1; k < 7; k++)
					{
						if (dice[k] == 1)
						{
							return answer = j * k;
						}
					}
				}
			}
		}
	}

	// 만약 다 다르면 가장 작은수 부터 찾는다.
	for (int i = 0; i < 7; i++)
	{
		if (dice[i] == 1)
		{
			return answer = i;
		}
	}

}



// https://school.programmers.co.kr/learn/courses/30/lessons/181915
// 글자 이어 붙여 문자열 만들기
// index_list의  값에 해당하는 my_string[i]의 값을 return하기
string solution2(string my_string, vector<int> index_list)
{
	string answer = "";

	//  index_list[i]가 my_string의 index로, 해당 값을 문자열에 넣어 return
	for (int i = 0; i < index_list.size(); i++)
	{
		answer += my_string[index_list[i]];
	}

	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181914
// 9로 나눈 나머지
// 정수 n의 각 자리수의 합을 9 로 나눈 나머지  == 9로나눈 나머지와 같다.
// 이를 이용해서 나머지를 return
int solution3(string number)
{
	int answer = 0;

	// number의 각 자리수를 더해준다.
	// 문자열이기 때문에  아스키코드를 이용해서 0부터 시작하는 정수로 바꾸어준다.
	for (int i = 0; i < number.size(); i++)
	{
		int num = number[i] - '0';
		answer = answer + num;
	}
	
	// 각 자리수의 합을 9로 나눈 나머지를 return
	return answer % 9;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181913
// 문자열 여러 번 뒤집기
// queris는 [s, e]로 되어있고, my_string의  s부터 e 까지를 뒤집어서 queris의 size까지 처리 한후 마지막 문자열을 return
string solution4(string my_string, vector<vector<int>> queries)
{
	for (int i = 0; i < queries.size(); i++)
	{
		// queries는 [s,e]이기 때문에 [i][0]과 [i][1]로 s와  e를 구한다.
		int s = queries[i][0];
		int e = queries[i][1];

		// e부터 s까지의 문자열을 저장한 후(뒤집어진 문자)
		string temp = "";
		for (int j = e; j >= s; j--)
		{
			temp += my_string[j];
		}

		// my_string s부터 저장된 문자열을 넣어준다.
		for (int j = 0; j < temp.size(); j++)
		{
			my_string[j + s] = temp[j];
		}
	}

	return my_string;
}


//https://school.programmers.co.kr/learn/courses/30/lessons/181912
// 배열 만들기 5
// 문자열 intStrs[i]의 s번 부터 l길이만큼의 부분 문자열을 정수로 변환하고, 변환된 정수가 k보다 클 경우 배열에 담는다. 해당 배열을 return
vector<int> solution5(vector<string> intStrs, int k, int s, int l)
{
	vector<int> answer;

	for (int i = 0; i < intStrs.size(); i++)
	{
		string  partStr = "";
		// s부터 l길이만큼(s+l)의 문자열을 구해서
		for (int j = s; j < s+l; j++)
		{
			partStr = partStr + intStrs[i][j];
		}

		// 해당 문자열을 정수로 바꾼다.
		int num = stoi(partStr);

		// 바꾼 정수가 k보다 크다면 배열에 담는다.
		if (num > k)
		{
			answer.push_back(num);
		}
	}

	return answer;

}



// https://school.programmers.co.kr/learn/courses/30/lessons/181911
// 부분 문자열 이어 붙여 문자열 만들기
// parts[i]는 [s,e]형태
// my_string.size() == parts.size()
// my_strings[s]부터 my_strings[e]까지 부분 문자열을 의미
// 부분 문자열을 이어 붙인 문자열을 return
string solution6(vector<string> my_strings, vector<vector<int>> parts)
{
	string answer = "";


	for (int i = 0; i < my_strings.size(); i++)
	{
		// i는 s,e 형태이기 때문에  0과 1의 사이즈만 있어서 s와 e를 구해준다.
		int s = parts[i][0];
		int e = parts[i][1];

		// s부터 e까지의 문자열을 더해서 문자열을 붙여준다.
		for (int j = s; j <= e; j++)
		{
			answer += my_strings[i][j];
		}
	}

	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181910
// 문자열의 뒤의 n글자
// my_string 의 뒤에서 n만큼의 글자를 return
string solution7(string my_string, int n)
{
	string answer = "";

	// 뒤에서 n만큼이기때문에 전체크기에서 n을 빼면 시작 인덱스를 구할 수 있다.
	int num = my_string.size() - n;

	// num부터 size까지 하면, n크기 만큼의 문자열을  구할 수 있다.
	for (int i = num; i < my_string.size(); i++)
	{
		answer += my_string[i];
	}

	return answer;

}


// https://school.programmers.co.kr/learn/courses/30/lessons/181909
// 접미사 배열
// banana 의 경우 'banana', 'anana', 'nana', 'ana', 'na' ,  'a' 가 접미사
// 문자열 0부터 끝까지, 1부터 끝까지, 2부터끝까지 ... 이 접미사에 해당
// 이 접미사를 사전순으로 정렬한 배열을 return
vector<string> solution8(string my_string)
{
	vector<string>  answer;

	// 전체 문자에서 앞의 문자가 1개씩 빠진다.
	for (int i = 0; i < my_string.size(); i++)
	{
		string part = "";
		// 시작점을 i로 해서 한글자씩 빠지도록 해서 배열에 넣어준다.
		for (int j = i; j < my_string.size(); j++)
		{
			part += my_string[j];

		}
		answer.push_back(part);
	}

	// sort를 이용해서 사전순으로 정렬해준다.
	sort(answer.begin(), answer.end());

	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181908
// 접미사인지 확인하기
// banana 의 경우 'banana', 'anana', 'nana', 'ana', 'na' ,  'a' 가 접미사
// is_suffix가 my_string의 접미사 일 경우 1 아니라면 0을 return
int solution9(string my_string, string is_suffix)
{
	vector<string> parts;

	//  전체 문자들 중에서 앞의 문자가 1개씩 빠지게 된다.
	for (int i = 0; i < my_string.size(); i++)
	{
		string part = "";
		// 시작지점을 i로 해서 한글자씩 빠지도록 해준다.
		for (int j = i; j < my_string.size(); j++)
		{
			part += my_string[j];
		}
		parts.push_back(part);
	}

	// 접미사 배열과 같다면 1, 다르다면 0을 return
	for (int i = 0; i < parts.size(); i++)
	{
		if (parts[i] == is_suffix)
		{
			return 1;
		}
	}
	return 0;

}



// ********************************* 미해결
// https://school.programmers.co.kr/learn/courses/30/lessons/120866
// 안전지대
// 지뢰가있는 지역은 1로 표시되고, 없는 지역은 0이다.
// 지뢰의 상하좌우와 대각선은 위험지역 , 안전한 지역의 칸수를 return
// board는 n*n배열 
// 지뢰의 위험지역을 2로 표시해서 0만 카운트
int solution10(vector<vector<int>> board)
{
	// 지뢰의 위치를 bomb에 넣어서 그 주변을 2로 바꾼다.
	vector <int> bomb;

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 1)
			{
				bomb.push_back(i);
				bomb.push_back(j);
			}
		}
	}


	// bomb 0,1 번째 2,3번째 ... 가 지뢰의 위치
	for (int i = 0; i < bomb.size(); i += 2)
	{
		int x = i;
		int y = i + 1;

		// board[x][y] ==1

		// x가 제일 윗줄이고, y가 제일 왼쪽, 제일 오른쪽 일 경우
		if (x == 0)
		{
			if (y == 0)
			{
			}
		}
	}
}

// ********************************* 미해결
// https://school.programmers.co.kr/learn/courses/30/lessons/120956
// 옹알이(1)
// 조카는 "aya", "ya", "woo",  "ma" 4가지 발음을 최대 1번씩 조합해서 밖에 발음하지 못한다
// babbling 중에서 조카가 발음할 수있는 단어의 개수
int solution(vector<string> babbling)
{
	int answer = 0;
	string aya = "aya";
	string ye = "ye";
	string woo = "woo";
	string ma = "ma";



	// babbling[i]의 0번째부터 0이 a라면 3글자를 확인해서 맞다면 다음으로
	for (int i = 0; i < babbling.size(); i++)
	{
		bool isAya = false;
		bool isYa = false;
		bool isWoo = false;
		bool isMa = false;

		for (int j = 0; j < babbling[i].size(); )
		{
			string temp = "";
			if (babbling[i][j] != ('a' || 'y' || 'w' || 'm'))
			{
				continue;
			}

			switch (babbling[i][j])
			{
			case 'a':
				if (isAya == false)
				{
					temp = babbling[i].substr(j, 3);
					if (temp == aya)
					{
						j += 3;
						isAya = true;
					}
					else continue;
				}
				else
					continue;
				break;

			case 'y':
				if (isYa == false)
				{
					temp = babbling[i].substr(j, 2);
					if (temp == ye)
					{

						j += 2;
						isYa = true;
					}
					else continue;
				}
				else
					continue;

				break;

			case 'w':
				if (isWoo == false)
				{
					temp = babbling[i].substr(j, 3);
					if (temp == woo)
					{
						j += 3;
						isWoo = true;
					}
					else continue;
				}
				else
					continue;
				break;

			case 'm':
				if (isMa == false)
				{
					temp = babbling[i].substr(j, 2);
					if (temp == ma)
					{
						j += 2;
						isMa == true;
					}
					else continue;
				}
				else
					continue;
				break;
			}

		}
		answer++;
	}

	return answer;


}


// https://school.programmers.co.kr/learn/courses/30/lessons/181904
// 세로읽기
// my_string을 한줄에 m 글자씩 넣고, 왼쪽에서부터 세로로 c번째 열에 적힌 글자들을 문자열로 return하는 함수
string solution(string my_string, int m, int c)
{
	string answer = "";

	// c는 1부터 시작하기때문에 -1을 해주어서 0부터 시작하게  해준다. (인덱스를 맞추기 위함)
	// c번째의 글자를 구하기때문에 c +m은 다음번 글자가 된다. (i += m)
	for (int i = c-1; i < my_string.size(); i+=m)
	{
		answer += my_string[i];
	}

	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181907
// 문자열의 앞의 n글자
// my_string 문자열 앞에서 n글자까지를 return
string solution(string my_string, int n)
{
	// 0부터 n까지 글자를 더해서 return 해준다.
	string answer = "";
	for (int i = 0; i < n; i++)
	{
		answer += my_string[i];
	}
	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181906
// 접두사인지 확인하기
// banana 의 경우 'b', 'ba', 'ban', 'bana', 'banan','banana' 가 접미사
// is_prefix가 my_string의 접두사라면 1, 아니라면 0
int solution(string my_string, string is_prefix)
{
	vector<string>  parts;

	// 접두사가 0부터 +1씩 증가하기 때문에
	// 접두사 part에 한글자씩 더한 문자열을 push_back 해준다.
	for (int i = 0; i < my_string.size(); i++)
	{
		string part = "";
		
		for (int j = 0; j <= i; j++)
		{
			part += my_string[j];
		}
		parts.push_back(part);

	}

	// 접두사 vector와 같은지 확인해서 맞다면 1, 아니라면 0을 return
	for (int i = 0; i < parts.size(); i++)
	{
		if (is_prefix == parts[i])
		{
			return 1;
		}
	}
	return 0;
}



// https://school.programmers.co.kr/learn/courses/30/lessons/181905
// 문자열 뒤집기
// my_string의 s부터 e까지 뒤집는 문자열
string solution2(string my_string, int s, int e)
{
	string parts;

	// s부터 e까지 뒤집기 때문에
	// e부터 s까지 i--를 하면서 새로운 문자열을 만든다.

	for (int i = e; i >=s; i--)
	{
		parts += my_string[i];
	}

	// 뒤집어진 parts 문자열의 값을 s부터 parts의 size까지 넣어준다.
	for (int i = 0; i < parts.size(); i++)
	{
		my_string[s + i] = parts[i];
	}

	return my_string;
}



// https://school.programmers.co.kr/learn/courses/30/lessons/181903
// qr code
// code의 각 인덱스를 q로 나누었을때 나머지가 r과 같은 문자를 순서대로 이어 붙이기
string solution(int q, int r, string code)
{
	string answer = "";

	// 인덱스(i)를 q로 나눈값 ->  i%q가 r과 같으면(==r) answer에 넣어준다.
	for (int i = 0; i < code.size(); i++)
	{
		if (i % q == r)
		{
			answer += code[i];
		}
	}

	return answer;

}


// https://school.programmers.co.kr/learn/courses/30/lessons/181902
// 문자 개수 세기
// my_string의 A~Z a~z의 개수를 담은 길이 52의 정수 배열을 return
#include <cctype>
vector<int> solution(string my_string)
{
	vector<int> answer;

	// 문자열 길이만큼 0으로 초기화 해준다.
	for (int i = 0; i < 52; i++)
	{
		answer.push_back(0);
	}

	for (int i = 0; i < my_string.size(); i++)
	{
		int index;
		// 아스키 코드를 이용
		// 소문자 a 97 보다 크다면 26이상의 배열에 넣어준다.
		// 대문자의 경우 알파벳의 숫자를 알기위해 my_string[i] - 97을 해준다.
		// 소문자는 my_string[i] - 65
		if (my_string[i] >= 97)
		{
			index = (my_string[i] - 97) + 26;
		}
		else
			index = (my_string[i] - 65);

		answer[index] += 1;
	}

	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181901
// 배열만들기 1
// n과 k가 주어 졌을때
// 1<= N <= n 정수 중에서, k의 배수를 오름차순으로 정렬
vector<int> solution(int n, int k)
{
	vector<int>answer;

	int num = k;
	int i = 1;
	// num을 먼저 곱한후 push_back 하면 
	// 해당 값이 n을 초과할 수 있기 때문에, 
	// 1. push_back을 하고 , 2. i을 1 증가 시키고 // 3.  k*i를 해서 다음 배수를 넣어준다.
	// 다음배수가 된 num의 값을 확인하고 n보다 작다면 push_back 아니라면 while문이 끝나게된다.
	while (num <= n)
	{
		answer.push_back(num);
		i++;
		num = k * i;
		
	}

	return answer;

}


// https://school.programmers.co.kr/learn/courses/30/lessons/181900
// 글자 지우기
// my_string에서 indices의 원소에 해당되는 인덱스의 글자를 지우고, 이어붙인 문자를 return
string solution(string my_string, vector<int> indices)
{
	string answer = "";
	
	bool isTrue = false;

	// indices[j]의 값이 인덱스의 값(i)라면 bool이 true로 조건을 만족해서 
	// 해당 인덱스(i)는 answer에 들어가지 못한다.
	for (int i = 0; i < my_string.size(); i++)
	{
		for(int j = 0; j<indices.size(); j++)
		{
			if (i == indices[j])
			{
				isTrue = true;
				break;
			}
		}

		// 조건을 만족하지 않았다면 answer에 넣어준다.
		if (isTrue == false)
		{
			answer += my_string[i];
		}

	}

	return answer;
}



// https://school.programmers.co.kr/learn/courses/30/lessons/181899
// 카운트 다운
// start부터 end_num까지 1씩 감소하는 수를 차례로 담은 배열 return
vector<int> solution(int start, int end_num)
{
	vector<int> answer;

	// start부터 end까지 1씩 감소 하기때문에 i--로 for문을 실행
	// i를 start로 -1씩해서 end까지 push_back 해준다.
	for (int i = start; i >= end_num; i--)
	{
		answer.push_back(i);
	}
	
	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181898
// 가까운 1 찾기
// 정수 배열 arr는 0과 1로 구성되어있다.
// idx가 주어졌을때, idx보다 크면서 값이1인 가장 작은 인덱스를 반환
//  없다면 -1을  반환
int solution(vector<int> arr, int idx)
{
	// idx 부터 1인 값을 찾는다.
	// 가장 작은 값이면 되기때문에 바로 return
	for (int i = idx; i < arr.size(); i++)
	{
		if (arr[i] == 1)
			return i;
	}

	// for문에서 return 되지 않았다면 없다는 뜻이므로 rerturn -1을 해준다.
	return -1;
}