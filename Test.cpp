#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;

void test_set1()
{
	//key模型
	//排序+去重
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
	//在这里是删除8和3两个数字。
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
		//在这里是找到10以后删除了10
	}
	else
	{
		cout << "找不到" << endl;
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
	//lower_bound(x) 用于查找第一个大于或等于 x 的元素。
	auto itup = myset.upper_bound(60);
	//upper_bound(x) 用于查找第一个大于 x 的元素
	myset.erase(itlow, itup);
	//删除了30-60的数字
	for (auto e : myset)
	{
		cout << e << " ";
	}
	cout << endl;
}




void test_set3()
{
	//key模型搜索
	//排序不去重，
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
	//这样的话就在里面直接找到了2，
	//比如里面有三个2
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
	pair<string, string>kvl("sort", "排序");
	dict.insert(kvl);
	dict.insert(pair<string, string>("left", "左边"));
	dict.insert(make_pair("right", "右边"));
	dict.insert(make_pair("right", "xxxx"));

	dict.insert({ "string", "字符串" });
	auto it = dict.begin();

	while (it != dict.end())
	{
		it->second += 'x';
		//这个的意思是在最后面插入x
		cout << it->first << ":" << it->second << endl;
		//从首字母开始到尾巴结束
		++it;
	}
	cout << endl;


	//这和上面打印的结果是一样的
	//只不过一个用了范围for
	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}


void test_map2()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
"苹果", "香蕉", "苹果", "香蕉","苹果","草莓", "苹果","草莓" };
	map<string, int>countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
	}
	//这一行代码是对进行一个统计
	//比如说草莓多少个，苹果多少个之类的。
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