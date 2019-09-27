#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

string upcase(string s)
{
	for(char &c: s)
		c = toupper(c);
	return s;
}

vector<string> getWords(string s)
{
	stringstream ss;
	ss<<s;
	vector<string> r;
	string i;
	while(ss>>i)
	{
		if(i.back()=='.'||i.back()==','||i.back()==';')
		{
			i.erase(i.end()-1);
		}
		r.push_back(upcase(i));
	}
	return r;
}

void addToMap(map<string,int> &m, vector<string> words)
{
	for(string s: words)
	{
		m[s]++;
	}
}

int main(int argc, char const *argv[])
{
	freopen("data/modelo.txt","r",stdin);
	string s;
	map<string, int> m;
	int i = 0;
	while(getline(cin, s))
	{
		addToMap(m, getWords(s));
		i++;
	}
	cout<<i<<endl;
	for(auto &t: m)
	{
		cout<<t.first<<" = "<<t.second<<endl;
	}
	return 0;
}