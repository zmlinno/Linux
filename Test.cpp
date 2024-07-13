#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;

void test_set1()
{
	//keyģ��
	//����+ȥ��
	set<int> s1;
	s1.insert(1);
	s1.insert(11);
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);

	set<int>::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


	vector<int> v = { 3,2,8,1,10,2 };
	set<int> s2(v.begin(), v.end());
	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int>s3 = { 3,2,8,1,10,2 };
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;
	//��������ɾ��8��3�������֡�
	s3.erase(8);
	s3.erase(3);
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;

	auto pos = s3.find(10);
	if (pos != s3.end())
	{
		cout << *pos << endl;
		s3.erase(pos);
		//���������ҵ�10�Ժ�ɾ����10
	}
	else
	{
		cout << "�Ҳ���" << endl;
	}
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;

}



void test_set2()
{
	std::set<int>myset;
	for (int i = 1; i < 10; i++)
	{
		myset.insert(i * 10);
	}
	for (auto e : myset)
	{
		cout << e << " ";
	}
	cout << endl;
	auto itlow = myset.lower_bound(25);
	//lower_bound(x) ���ڲ��ҵ�һ�����ڻ���� x ��Ԫ�ء�
	auto itup = myset.upper_bound(60);
	//upper_bound(x) ���ڲ��ҵ�һ������ x ��Ԫ��
	myset.erase(itlow, itup);
	//ɾ����30-60������
	for (auto e : myset)
	{
		cout << e << " ";
	}
	cout << endl;
}




void test_set3()
{
	//keyģ������
	//����ȥ�أ�
	multiset<int>s1;
	s1.insert(1);
	s1.insert(11);
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(2);
	s1.insert(1);

	multiset<int>::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	auto pos = s1.find(2);
	//�����Ļ���������ֱ���ҵ���2��
	//��������������2
	while (pos != s1.end() && *pos == 2)
	{
		cout << *pos << " ";
		++pos;
	}
	cout << endl;
}



void test_map1()
{
	map<string, string>dict;
	pair<string, string>kvl("sort", "����");
	dict.insert(kvl);
	dict.insert(pair<string, string>("left", "���"));
	dict.insert(make_pair("right", "�ұ�"));
	dict.insert(make_pair("right", "xxxx"));

	dict.insert({ "string", "�ַ���" });
	auto it = dict.begin();

	while (it != dict.end())
	{
		it->second += 'x';
		//�������˼������������x
		cout << it->first << ":" << it->second << endl;
		//������ĸ��ʼ��β�ͽ���
		++it;
	}
	cout << endl;


	//��������ӡ�Ľ����һ����
	//ֻ����һ�����˷�Χfor
	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}


void test_map2()
{
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
"ƻ��", "�㽶", "ƻ��", "�㽶","ƻ��","��ݮ", "ƻ��","��ݮ" };
	map<string, int>countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
	}
	//��һ�д����ǶԽ���һ��ͳ��
	//����˵��ݮ���ٸ���ƻ�����ٸ�֮��ġ�
	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	multimap<int, string>sortMap;
	for (auto& kv : countMap)
	{
		sortMap.insert({ kv.second,kv.first });
	}
	cout << endl;

	for (auto& kv : sortMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

int main()
{
	//test_set1();
	//test_set2();
	//test_set3();
	//test_map1();
	test_map2();
	return 0;
}