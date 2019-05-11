#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, int> pa;

struct cmp
{
	bool operator() (pa a, pa b)
	{
		if (a.second > b.second)
			return false;
		else if (a.second == b.second)
		{
			if (a.first > b.first)
				return false;
			else if (a.first <= b.first)
				return true;
		}
		else
			return true;
	}
};


int main()
{
	//����5���ƣ�ֻ����������������ƶ���ͬ�����ж��ӣ��ж�������ӷ���ǰ��������С���� 2345678910JQKA
	//����Ϊchar���ͣ�priority_queue�д�pair��cmp�ȽϺ������ȱȽϸ������ٱȽϴ�С��
	vector<char> input = { '4', '4', '4', 'K', 'J' };
	priority_queue<pa, vector<pa>, cmp> result;
	int tmp[13] = { 0 };
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 'J')
			tmp[9]++;
		else if (input[i] == 'Q')
			tmp[10]++;
		else if (input[i] == 'K')
			tmp[11]++;
		else if (input[i] == 'A')
			tmp[12]++;
		else
			tmp[input[i] - '2']++;
	}

	for (int i = 0; i < 13; i++)
		if (tmp[i] != 0)
		{
#if _DEBUG
			cout << i << " : " << tmp[i] << endl;
#endif
			result.push(pa(i, tmp[i]));
		}
	while (!result.empty())
	{
		for (int i = 0; i < result.top().second; i++)
		{
			if (result.top().first == 9)
				cout << "J ";
			else if (result.top().first == 10)
				cout << "Q ";
			else if (result.top().first == 11)
				cout << "K ";
			else if (result.top().first == 12)
				cout << "A ";
			else
				cout << result.top().first + 2  << " ";
		}

		result.pop();
	}

	return 0;
}