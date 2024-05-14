#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

vector<int> solution(vector<int> numbers);
int solution0(vector<int> array);
int solution1(vector<int> array);
vector<int> solution2(int n);
vector<int> solution3(vector<int> arr);
int solution4(vector<int> arr);
int solution5(vector<int> num_list);
int solution6(vector<int> num_list);
int solution7(string myString, string pat);
string solution8(string myString);
string solution9(string myString);
vector<string> solution10(vector<string> strArr);
string solution11(string myString);
string solution12(string my_string, string alp);

int main()
{
   
}

// https://school.programmers.co.kr/learn/courses/30/lessons/120809
// 배열 두 배 만들기
// 정수 배열 numbers, numbers의 각 원소에 두배한 원소를 가지도록 return
vector<int> solution(vector<int> numbers)
{
	// for문을 실행해서  각 인덱스마다 2를 곱해준다.
	for (int i = 0; i < numbers.size(); i++)
	{
		numbers[i] *= 2;
	}

	return numbers;

}


// https://school.programmers.co.kr/learn/courses/30/lessons/120811
// 중앙값 구하기
// 중앙값은 순서대로 정렬했을 때, 가장 중앙에 위치하는 값
// array의 중앙값을 return
int solution0(vector<int> array)
{
	// 오름차순 정렬
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = i; j < array.size(); j++)
		{
			if (array[i] < array[j])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}

	}


	// 중앙의 인덱스를 구해서 반환
	int mid = (array.size() / 2) ;

	return array[mid];

}

// https://school.programmers.co.kr/learn/courses/30/lessons/120812
// 최빈값 구하기
// 최빈값은 주어진 값중에서 가장 많이 나오는 값을 의미.
// array의 최빈값을 return 하도록한다. 최빈값이 여러개면 -1을 return;
int solution1(vector<int> array)
{

	// 개수가 1개이면 비교를 안해도 되서 예외처리.
	if (array.size() == 1)
	{
		return array[0];
	}

	// 정렬!
	sort(array.begin(), array.end());

	vector<int> maxNumbers; // 최빈값의 수를 넣기 위한 변수
	int maxCount = 0; // 최빈값의 개수를 확인하기 위한 변수
	int beforeNum = array[0]; // 현재 값이 확인하기 위한 변수
	int curCount = 1; // 현재값의 개수를 확인하기 위한 변수

	for (int i = 1; i < array.size(); i++)
	{
		// 1. array[i]가 다른 숫자로 넘어갔다면, 
		// array[i-1]의 개수로 비교한다.
		if (array[i] != beforeNum)
		{
			// 1. 현재 개수가 최빈값의 개수인 경우
			if (curCount == maxCount)
			{
				// 이전의 값을 최빈값 배열에 넣어준다.
				maxNumbers.push_back(array[i-1]);

			}
			// 2. 현재 개수가 최빈값으로 갱신된 경우
			else if (curCount > maxCount)
			{
				// 이전에 넣은 값들을 지운 후 넣어준다.
				maxNumbers.clear();
				maxNumbers.push_back(array[i - 1]);
				maxCount = curCount; // 최빈값의 개수를 갱신해준다.
			}
			// 3. 현재 개수가 최빈값 보다 작은경우 
			else
			{
				// maxNumbers에 넣을 조건이 되지 않기때문에 else는 실행하지 않는다.
			}

			// count랑 beforeNum을 바꿔준다.
			curCount = 1;
			beforeNum = array[i];
		}

		// 2. array[i]가 이전의 숫자랑 똑같다면
		else if(array[i]==beforeNum)
		{
			// 개수를 더해준다.
			curCount++;
		}
	}

	// 마지막 값을 비교해준다.
	// 1. 현재 개수가 최빈값의 개수인 경우
	if (curCount == maxCount)
	{
		// 마지막 값을 최빈값 배열에 넣어준다.
		maxNumbers.push_back(array[array.size()-1]);

	}
	// 2. 현재 개수가 최빈값으로 갱신된 경우
	else if (curCount > maxCount)
	{
		// 이전에 넣은 값들을 지운 후 넣어준다.
		maxNumbers.clear();
		maxNumbers.push_back(array[array.size() - 1]);
		maxCount = curCount; // 최빈값의 개수를 갱신해준다.
	}


	// array의 순회가 끝나면 최빈값의 개수를 비교해서 return 해준다
	if (maxNumbers.size() == 1)
	{
		return maxNumbers[0];
	}
	else
	{
		return -1;
	}

}

// https://school.programmers.co.kr/learn/courses/30/lessons/120813
// 짝수는 싫어요
// n이하의 홀수가 오름차순으로 담긴 배열을 return 
vector<int> solution2(int n)
{
	vector<int> answer; 
	// 홀수이기 때문에 1부터 시작한다.
	int i = 1;

	// n보다 커질때까지 while문을 반복한다.
	// answer에 값을 넣고, 홀수이기 때문에 +2 해준다.
	while (i <= n)
	{
		answer.push_back(i);
		i += 2;
	}

	return answer;
}



// https://school.programmers.co.kr/learn/courses/30/lessons/181882
// 조건에 맞게 수열 변환하기 1
// 정수 배열 arr, 
// arr의 각 원소에 대해 값이 50보다 크거나 같은 짝수라면 2로 나누고
// 50보다 작은 홀수라면 2를 곱한 결과의 정수 배열을 return
vector<int> solution3(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		// 50보다 크거나 같고, 짝수일경우 2로 나누고
		if (arr[i] >= 50 && arr[i] % 2 == 0)
		{
			arr[i] /= 2;
		}
		// 50보다 작고, 홀수일경우 2를 곱해준다.
		else if (arr[i] < 50 && arr[i] % 2 == 1)
		{
			arr[i] *= 2;
		}

	}

	return arr;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181881
// 조건에 맞게 수열 변환하기2
// 정수배열 arr
// 각 원소 값이 50보다 크거나 같은 짝수라면 2로 나누고
// 50보다 작은 홀수라면 *2 +1 을 해준다.
// 이작업을 x번 반복한 결과물 arr(x)라고 했을때
// arr(x)=arr(x+1) (같다)인 x는 항상 존재한다. 이러한 x를 return하기
int solution4(vector<int> arr)
{
	int x = 0; 	// x의 값
	vector<int> arrX; // x의 값을 저장할 배열

	bool isDifferent = true; // while문을 반복하기 위한 bool 변수

	while (isDifferent)
	{
		// X를 비워준다.
		arrX.clear();

		for (int i = 0; i < arr.size(); i++)
		{
			// 값이 바뀌기전에 arrX에 값을 넣어준다.
			arrX.push_back(arr[i]);

			// 50보다 크거나 같고, 짝수라면 2로 나누고
			if (arr[i] >= 50 && arr[i] % 2 == 0)
			{
				arr[i] /= 2;
			}
			// 50보다 작고, 홀수라면 *2+1을 해준다.
			else if (arr[i] < 50 && arr[i] % 2 == 1)
			{
				arr[i] = ((arr[i] * 2) + 1);
			}
		}

		// arr[i]와 arrX[i]가 같은지 확인하고
		for (int i = 0; i < arr.size(); i++)
		{
			// 만약 다르다면 다시 반복해야 하므로, X를 더해주고 for문을 중단한다.
			if (arr[i] != arrX[i])
			{
				x++;
				break;
			}

			// 만약  마지막까지 같다면 
			if (i == arr.size() - 1 && arr[i]==arrX[i])
			{
				// bool변수를 바꾸어서 whle문을 빠져나오고
				isDifferent = false;
			}
		}
	}
	
	// x를 반환해준다.
	return x;

}


// https://school.programmers.co.kr/learn/courses/30/lessons/181880
// 1로 만들기
// 짝수라면 반으로 나누고, 홀수라면 -1 후 반으로 나누면 마지막엔 1이 된다.
// num_list의 모든 원소를 1로 만들기 위해서 필요한 나누기 현산 횟수를 return
int solution5(vector<int> num_list)
{
	int answer = 0;

	for (int i = 0; i < num_list.size(); i++)
	{
		// 1이 아니라면 반복문을 실행한다.
		// 나눌때마다 연산횟수를 1씩 더해준다.
		while (num_list[i] != 1)
		{
			// 짝수라면 2로 나누고
			if (num_list[i] % 2 == 0)
			{
				num_list[i] /= 2;
				answer++;
			}
			// 홀수라면 -1 후 2로 나누어준다.
			else
			{
				num_list[i]--;
				num_list[i] /= 2;
				answer++;
			}
		}
	}

	return answer;

}


// https://school.programmers.co.kr/learn/courses/30/lessons/181879
// 길이에 따른 연산
// 리스트의 길이가 11이상이면 리스트에 있는 모든 원소의 합을
// 리스트의 길이가 10이하이면 리스트에 있는 모든 원소의 곱을
int solution6(vector<int> num_list)
{
	// 11 이상이면
	if (num_list.size() >= 11)
	{
		// 원소들의 합을 return
		int answer = 0;
		for (int i = 0; i < num_list.size(); i++)
		{
			answer += num_list[i];
		}

		return answer;
	}
	// 10 이하이면
	else if (num_list.size() <= 10)
	{
		// 원소들의 곱을 return
		int answer = 1;
		for (int i = 0; i < num_list.size(); i++)
		{
			answer *= num_list[i];
		}

		return answer;
	}

}


// https://school.programmers.co.kr/learn/courses/30/lessons/181878
// 원하는 문자열 찾기
// 알파벳으로 이루어진 문자열  myStrring, pat
// mystring의 연속된 부분 문자열 중 pat이 존재하면 1을 return
// 아니라면 0을 rerturn
// 대소문자는 구분하지 않는다.
int solution7(string myString, string pat)
{
	// 만약 myStrirng이 pat보다 길이가 작다면 찾을수 없으므로 0을 return
	if (myString.size() < pat.size())
	{
		return 0;
	}

	// 문자를 소문자로 모두 변환한다.
	for (int i = 0; i < myString.size(); i++)
	{
		myString[i] = tolower(myString[i]);
	}
	for (int i = 0; i < pat.size(); i++)
	{
		pat[i] = tolower(pat[i]);
	}

	// mystring에서 pat이 있다면 1을 ,아니라면 0을 return해준다.
	// find함수는 index를 반환해주는데, 없다면 npos를 반환해준다.
	// npos가 아니라면, 즉 찾았다면. 같은 문자열이 있다는 것
	if (myString.find(pat) != string::npos)
	{
		return 1;
	}
	return 0;
	
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181877
// 대문자로 바꾸기
// 모든 알파벳을 대문자로 변환하여  return
string solution8(string myString)
{
	// toupper을 이용해서 대문자로 변환해준다.
	for (int i = 0; i < myString.size(); i++)
	{
		myString[i] = toupper(myString[i]);
	}

	return myString;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181876
// 소문자로 바꾸기
// 모든 알파벳을 소문자로 변환하여 return
string solution9(string myString)
{
	// foreach문
	// myString의 원소와 같은 타입으로 순회를한다. 
	// 원본값을 바꾸기 위해서는  참조자가 필요하다.
	// ch는 myString[i]와 같은 것이다.
	// tolower을 사용해서 소문자로 바꾸어준다.
	for (char& ch : myString)
	{
		ch = tolower(myString[ch]);
	}
	
	return myString;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181875
// 배열에서 문자열 대소문자 변환하기
// 홀수번째 인덱스의 문자는 대문자로
// 짝수번째 인덱스의 문자는 소문자로 변환하여 return
vector<string> solution10(vector<string> strArr)
{
	for (int i = 0; i < strArr.size(); i++)
	{
		// 짝수일 경우 소문자로 변환
		if (i % 2 == 0)
		{
			for (int j = 0; j < strArr[i].size(); j++)
			{
				strArr[i][j] = tolower(strArr[i][j]);
			}
		}
		// 홀수일 경우 대문자로 변환
		else
		{
			for (int j = 0; j < strArr[i].size(); j++)
			{
				strArr[i][j] = toupper(strArr[i][j]);
			}
		}
	}

	return strArr;

}


// https://school.programmers.co.kr/learn/courses/30/lessons/181874
// A 강조하기
// 'a'가 등장하면 전부 'A'로 변환하고,
// 'A'가 아닌 모든 대문자 알파벳은 소문자 알파벳으로 변환하여 return
string solution11(string myString)
{
	for (int i = 0; i < myString.size(); i++)
	{
		// 'a'라면 'A'로 변환한다.
		if (myString[i] == 'a' || myString[i] == 'A')
		{
			myString[i] = 'A';
		}
		// 'A'보다 큰 대문자라면 모두 소문자로 바꾼다.
		// == 'a'와 'A' 는 'A'가되고, 나머지는 다 소문자로 바꾼다.
		else
		{
			myString[i] = tolower(myString[i]);
		}
	}

	return myString;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/181873
// 특정한 문자를 대문자로 바꾸기
// 영소문자로 이루어진 문자열 my_string과 영소문자1글자 alp
// my_string에서 alp에 해당하는 모든 글자를 대문자로 바꾼 문자열 return
string solution12(string my_string, string alp)
{
	// my_string[i]와 같은 ch가 alp와 같다면,
	// ch글자를 대문자로 바꾸어준다.
	// 참조자를 붙어야 원본이 바뀌므로 char&로 설정
	for (char& ch : my_string)
	{
		// alp는 1글자로 이루어진 문자열이기 때문에
		// ch가 alp[0]이랑 비교되어야한다.
		if (ch == alp[0])
		{
			ch = toupper(ch);
		}
	}

	return my_string;
}