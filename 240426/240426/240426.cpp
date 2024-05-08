#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list);
int solution(vector<int> num_list);
vector<int> solution(vector<int> arr, vector<vector<int>> intervals);
vector<int> solution2(vector<int> arr);
vector<int> solution(vector<int> arr, vector<int> query);
vector<int> solution3(vector<int> num_list, int n);
vector<int> solution4(vector<int> num_list, int n);
vector<string> solution(vector<string> str_list);
vector<int> solution5(vector<int> num_list, int n);
vector<int> solution6(vector<int> num_list, int n);
bool solution(string s);
int solution2(string s);
string solution3(string s);
bool solution4(string s);
int solution(vector<int> num_list);
vector<string> solution(vector<string> names);
int solution(vector<int> numbers, int n);
vector<int> solution(vector<int> arr, vector<vector<int>> queries);


int main()
{

}


// https://school.programmers.co.kr/learn/courses/30/lessons/181897
// 리스트 자르기
// 정수 n, 정수3개가 담긴 slicer, 정수 여러개가 담긴 num_list
// slicer의 정수 3개를 a, b, c, 라고 할 때,
// 1) n=1이라면, num_list의 0~b까지
// 2) n=2라면, num_list의 a부터 마지막까지
// 3) n=3라면, num_list의 a~b까지
// 4) n=4라면, num_list의 a부터 b까지 c 간격으로
// 자른 벡터를 return
vector<int> solution(int n, vector<int> slicer, vector<int> num_list)
{
	vector<int> answer;
	int a = slicer[0];
	int b = slicer[1];
	int c = slicer[2];

	// n의 값에 따라 조건이 다르기 때문에 switch를 사용해서 구분해준다.
	switch (n)
	{
	case 1:
		// n = 1, 0부터 b까지
		for (int i = 0; i <= b; i++)
		{
			answer.push_back(num_list[i]);
		}
		break;

	case 2:
		// n = 2, a부터 마지막까지
		for (int i = a; i < num_list.size(); i++)
		{
			answer.push_back(num_list[i]);
		}

		break;

	case 3:
		// n = 3, a부터 b까지
		for (int i = a; i <= b; i++)
		{
			answer.push_back(num_list[i]);
		}

		break;

	case 4:
		// n = 4, a부터 b까지 c간격으로 (i+=c를 하면 c간격만큼이 된다.)
		for (int i = a; i <= b; i += c)
		{
			answer.push_back(num_list[i]);
		}
		break;
	}

	return answer;

}



// https://school.programmers.co.kr/learn/courses/30/lessons/181896
// 첫 번째로 나오는 음수
// 첫번째로 나오는  음수의 인덱스를 rerturn, 없다면 -1을 return
int solution(vector<int> num_list)
{
	for (int i = 0; i < num_list.size(); i++)
	{
		// 음수가 나온다면 해당 인덱스를 return
		if (num_list[i] < 0)
		{
			return i;
		}
	}

	// 음수가 없다면 -1 을 return
	return  -1;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181895
// 배열 만들기 3
// 정수배열 arr와, [[a1, b1], [a2, b2]] 의 꼴로 주어진 interval
// a1 ~ b1 과 a2 ~ b2 인덱스 값을 담은 새로운 배열을 return
vector<int> solution(vector<int> arr, vector<vector<int>> intervals)
{
	vector<int> answer;

	// a1, b1, a2, b2 의 값을 저장해준다.
	int a1 = intervals[0][0];
	int b1 = intervals[0][1];

	int a2 = intervals[1][0];
	int b2 = intervals[1][1];


	// 각 구간에 맞는 값을 answer에 넣어준다.
	// arr[a1]~ arr[b1]
	for (int i = a1; i <= b1; i++)
	{
		answer.push_back(arr[i]);
	}

	// arr[a2]~ arr[b2]
	for (int i = a2; i <= b2; i++)
	{
		answer.push_back(arr[i]);
	}

	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181894
// 2의 영역
// 배열 안의 2가 포함된 가장 작은 연속도딘 부분을 retrun
// arr에 2가 없는 경우 -1을 return
vector<int> solution2(vector<int> arr)
{
	vector<int>answer;

	vector<int> count;
	for (int i = 0; i < arr.size(); i++)
	{
		// 값이 2인 인덱스를 찾는다.
		if (arr[i] == 2)
		{
			count.push_back(i);
		}
	}

	// 2가 없다면 -1을 넣어준다.
	if (count.size()== 0)
	{
		answer.push_back(-1);
	}
	// 2가 1개라면 2를 넣어준다. (1개 뿐이여서)
	else if (count.size() == 1)
	{
		answer.push_back(2);
	}
	// size 가 2 이상이라면 구간이 있다는 것으로,
	// count의 0번째와 마지막 값 사이를 answer에 넣어준다.
	else 
	{
		for (int i = count[0]; i <= count.back(); i++)
		{
			answer.push_back(arr[i]);
		}
	}

	return answer;

}


// https://school.programmers.co.kr/learn/courses/30/lessons/181893
// 배열 조각하기
// query를 순회한다.
// 짝수 인덱스에서는 arr에서 query[i]번 인덱스를 제외하고 arr의 query[i]번 인덱스의 뒷부분을 잘라서 버린다.
// 홀수 인덱스에서는 arr에서 query[i]번 인덱스를 제외하고 arrr의 query[i]번 인덱스의 앞부분을 잘라서  버린다.
// !!query[i]의 값이 아닌 query 인덱스를 기준으로 홀,짝이 나뉜다!!
vector<int> solution(vector<int> arr, vector<int> query)
{

	vector<int> answer;

	for (int a : arr)
	{
		answer.push_back(arr[a]);
	}

	// vector.erase(vector.begin()+idx)를 쓰게 되면 해당 인덱스를 지울 수 있다.
	// 이렇게 지우게된다면 size까지 줄어들게 된다.


	for (int i = 0; i < query.size(); i++)
	{
		// 짝수 인덱스 일 경우
		if (i % 2 == 0)
		{
			// 뒷부분을 지울경우 -> query[i]을 포함하지 않는 값~ 마지막
			// 마지막 값(arr.size()-1)을 포함해서 query[i] 전까지를 조건으로 지운다.
			// erase를 써서 size도 줄지만, j--를 하기때문에 항상  마지막 값을 지우게 된다.
			for (int j = arr.size()-1; j >query[i]; j--)
			{
				arr.erase(arr.begin()+ j);
			}
		}
		// 홀수 인덱스 일 경우
		else
		{
			// 앞부분을 지울경우 -> 처음 ~ query[i]를 포함하지 않는 값
			// 앞에만 지우기 때문에 arr.begin() + i를 하지않고, arr.begin()을 하여 가장 앞에 값만 지운다.
			// for 문으로 j가 0부터 query[i]가 되기 전까지만 실행하여
			//  arr.begin()은 0부터 query[i]까지의 수만큼 반복하게되어 지워지게 된다.
			for (int j = 0; j <query[i]; j++)
			{
				arr.erase(arr.begin());
			}
		}
	}

	return arr;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181892
// n번째 원소부터
// num_list의 n번째부터 마지막까지 담은 리스트를 return
vector<int> solution3(vector<int> num_list, int n)
{
	vector<int> answer;

	// n번째는 0을 포함하지 않고 시작되는 수이기 때문에  n-1을 해준다.
	// n-1 부터 마지막까지 push_back해준다.
	for (int i = n-1; i < num_list.size(); i++)
	{
		answer.push_back(num_list[i]);
	}

	return answer;
}



// https://school.programmers.co.kr/learn/courses/30/lessons/181891
// 순서 바꾸기
// [num_list의 n번째 이후의 원소] 와 [num_list의 n번째 까지의 원소]로 나뉘어서
// 이후의 원소를 앞에두고 + 까지의 원소를 뒤에 붙인 리스트를 return
vector<int> solution4(vector<int> num_list, int n)
{
	vector<int> answer;
	
	// 1) n번째 이후의 원소들을 먼저 넣는다.
	// n-1은 n번째 이고, n번째 이후여서 n부터  시작해준다.
	for (int i = n; i < num_list.size(); i++)
	{
		answer.push_back(num_list[i]);
	}

	// 2) n번째 까지의 원소를 넣는다.
	// 까지이기때문에 n-1까지 포함되는 < n 을 조건으로 설정해준다.
	for (int i = 0; i < n; i++)
	{
		answer.push_back(num_list[i]);
	}

	return answer;
}



// https://school.programmers.co.kr/learn/courses/30/lessons/181890
// 왼쪽 오른쪽
// str_list는 u, d, l, r 4개의 문자열이 저장되어있고,
// 1) l이 먼저 나온다면, l을 기준으로 왼쪽에 있는 문자열을
// 2) r이 먼저 나온다면, r을 기준으로 오른쪽에 있는 문자열을 
// 순서대로 담은 리스트를 return
// l이나 r이 없다면 비어있는 리스트를 return
vector<string> solution(vector<string> str_list)
{
	vector<string> answer;
	
	// l과 r중 먼저 나오는것을 파악 하기 위해 bool 변수 생성
	bool isL = false;
	bool isR = false;

	// l과 r의 인덱스를 알기위해 int변수 생성
	int idx = 0;

	for (int i = 0; i < str_list.size(); i++)
	{
		// l과 r이 있는 경우 해당 값에 맞는 bool 변수가 true가 되도록하고
		// i값을 idx에 저장후 break를 한다. (먼저 나온 값만 필요하기때문)
		if (str_list[i] == "l")
		{
			isL = true;
			idx = i;
			break;
		}
		else if (str_list[i] == "r")
		{
			isR = true;
			idx = i;
			break;
		}
	}
	// for문에 종료 되었을때, true에 들어가지 않았다면 둘다 false 여서 
	// if문에 들어가지 않고 비어있는 리스트가 retrun 된다.
	

	// l이나 r이 있었다면 조건문에 들어가게 되고,
	if (isL == true)
	{
		// l은 왼쪽이기 때문에 0부터 idx(l전까지)를 넣어준다.
		for (int i = 0; i < idx; i++)
		{
			answer.push_back(str_list[i]);
		}
	}
	if (isR == true)
	{
		// r은 오른쪽이긱 때문에 r을제외 한(idx + 1)부터 마지막까지 넣어준다.
		for (int i = idx + 1; i < str_list.size(); i++)
		{
			answer.push_back(str_list[i]);
		}
	}


	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181889
// n번째 원소까지
// num_list의 첫번째부터 n번째 까지의 원소를 담은 list
vector<int> solution5(vector<int> num_list, int n)
{
	vector<int> answer;

	// 첫번째(0)부터 n번째까지(<n - 이미 첫번째에서 -1 이 되어서 n까지 포함하지 않아도 된다.)
	for (int i = 0; i < n; i++)
	{
		answer.push_back(num_list[i]);
	}

	return answer;

}



// https://school.programmers.co.kr/learn/courses/30/lessons/181888
// n개 간격의 원소들
// num_list의 첫번째 부터 마지막까지 n개 간격의 원소들을 담은 list를 return
vector<int> solution6(vector<int> num_list, int n)
{
	vector<int> answer;

	// 0부터 +=n씩 해서 넣어준다.
	for (int i = 0; i < num_list.size(); i += n)
	{
		answer.push_back(num_list[i]);
	}

	return answer;

}


// https://school.programmers.co.kr/learn/courses/30/lessons/12916
// 문자열 내 p와 y의 개수
// 대문자와 소문자가 섞인 s
// 'p' 와 'y'의 개수를 비교해서 같으면 true, 다르면 false
// 두개다 없을 경우에도 true
// 대소문자는 구별하지 않는다.
bool solution(string s)
{
	// p와 y의 개수를 확인하기 위해 int 변수 생성
	int pCount = 0;
	int yCount = 0;


	// 대소문자를 구별하지 않아서 p, P거나 y, Y일 경우 개수를 증가시켜준다.
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'p' || s[i] == 'P')
		{
			pCount++;
		}
		else if (s[i] == 'y' || s[i] == 'Y')
		{
			yCount++;
		}
	}

	// 개수가 같거나, 둘 다 없는 경우이기 때문에 0 == 0도 성립한다.
	if (pCount == yCount)
	{
		return true;
	}
	else
		return false;
}



// https://school.programmers.co.kr/learn/courses/30/lessons/12925
// 문자열을 정수로 바꾸기
// 문자열 s를 숫자로 변환한 결과를 반환하는 함수
int solution2(string s)
{
	// stoi를 이용해서 문자열을 int로 변환
	int answer = stoi(s);

	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/12939
// 최댓값과 최솟값
// s에는 공백으로 구분된  숫자들이 저장되어 있다.
// s의 최소값과 최대값을 "최소값 최대값" 형태의 문자열을 반환
// s는 둘 이상의 정수가 공백으로 구분되어있다.
string solution3(string s)
{
	string answer;

	// 공백을 제외한 정수를 구분하기 위해 vector<int>를 생성
	vector<int> v;
	string temp;

	// 공백이 아닌 경우에만 temp 문자열에 넣고,
	// 공백인 경우 temp를 vector에 넣고, clear하여서 다음 문자를 넣을 수 있도록 한다.
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			temp += s[i];
		}
		else
		{
			v.push_back(stoi(temp));
			temp.clear();
		}
	}
	// 마지막 값은 공백으로 구분되지 않기 때문에 따로 넣어준다.
	v.push_back(stoi(temp));

	// vector에 있는 원소들을 오름차순으로 정렬하여 최소값과 최대값으로 구분한다.
	sort(v.begin(), v.end());


	answer += to_string(v[0]) + ' ';
	answer += to_string(v[v.size() - 1]);

	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181887
// 홀수 vs 짝수
// 가장 첫번째 원소를 1번원소, 홀수번째 원소들의 합과 짝수원소들의 합중 큰 값을 return
int solution(vector<int> num_list)
{
	int answer = 0;

	int evenNum = 0; // 짝수
	int oddNum = 0; // 홀수


	// list의 끝까지 인덱스의 홀 짝을 구분해서, 인덱스들의 합을 구한 후
	for (int i = 0; i < num_list.size(); i++)
	{
		// 1번째 = 짝수
		if (i % 2 == 0)
		{
			evenNum += num_list[i];
		}
		else
			oddNum += num_list[i];
	}

	// 가장 큰 값을 리턴해준다.
	// 값이 같다면 그 값을 리턴해주기 때문에 어느 숫자가 되든 상관이 없다.
	if (evenNum > oddNum)
	{
		return evenNum;
	}
	else
		return oddNum;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181886
// 5명씩
// 사람들의 이름이 담긴 문자열 list names
// 앞에서 5명씩 묶고, 그룹의 가장 앞에 있는 사람의 이름을 담은 리스트를 return
vector<string> solution(vector<string> names)
{
	vector<string>answer;

	// 5명씩 묶이는  첫번째 이름만 넣으면 되서, i += 5 해준다.
	for (int i = 0; i < names.size(); i+=5)
	{
		answer.push_back(names[i]);
	}

	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181885
// 할 일 목록
// 할 일이 담긴 문자열 todo_list와, 각각의 일을 마쳤는지 나타내는 bool배열 finished
// todo_list에서 아직 마치지 못한일을 순서대로 담은 문자열 배열 return
vector<string> solution(vector<string> todo_list, vector<bool> finished)
{
	vector<string> answer;

	// 마치지 못한 일을 기준으로 해서 finished가 false라면, 배열에 넣어준다.
	for (int i = 0; i < finished.size(); i++)
	{
		if (finished[i] == false)
		{
			answer.push_back(todo_list[i]);
		}
	}

	return answer;
}



// https://school.programmers.co.kr/learn/courses/30/lessons/181884
// n보다 커질 때까지 더하기
// 정수배열 numbers, 정수 n
// numbers의 원소를 앞에서부터 하나씩 더하다가, 합이 n보다 커지는 순간 그 합들을 return
int solution(vector<int> numbers, int n)
{
	int answer = 0;

	// 인덱스 0번부터 n보다 작거나 같을때 까지 계속 더해준다.
	// 만약 값이 커졌다면, break를 해서 return해준다.
	for (int i = 0; i < numbers.size(); i++)
	{
		if (answer <= n)
		{
			answer += numbers[i];
		}
		else
			break;
	}

	return answer;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181883
// 수열과 구간 쿼리1
// 정수 배열 arr와 2차원배열 queries , queries는 [s, e] 꼴이다.
// s <= i <= e 인 arr[i]에 1을 더해준다.
// queries를 처리한 이후의 arr를 return
vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{

	for (int i = 0; i < queries.size(); i++)
	{
		// queries의 s와 e의 값을 변수로 저장해준다.
		int s = queries[i][0];
		int e = queries[i][1];

		// s부터 e까지의 인덱스에있는 arr[j]의 값에 1을 더해준다.
		for (int j = s; j <= e; j++)
		{
			arr[j]++;
		}
	}

	return arr;
}






// **************************************************
// https://school.programmers.co.kr/learn/courses/30/lessons/12909
// 올바른 괄호
// '('문자로 열렸으면 반드시 ')'로 짝지어서 닫혀야한다.
// 문자열 s는 (나 )로 되어있고, 올바른 괄호일 경우 true 아닐경우 false
bool solution4(string s)
{
	// ')'로 시작할경우 올바르지 않으니 false를 반환한다.
	if (s[0] == ')') return false;
	// ++) 시작이 '))))'인 경우도 있으니까 이것도 생각하기.
	
	// 
	// s[j]에 ')'가 있다면 완전괄호 count++; 해당 값은 0 으로 바꿔준다.
	// 다음 s[i]도 같은 작업을 반복한다.  완전괄호 count가 s.size()/2라면 통과
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			for (int j = i; j < s.size(); j++)
			{
				if (s[j] == ')')
				{
					
				}
			}
		}
	}
}