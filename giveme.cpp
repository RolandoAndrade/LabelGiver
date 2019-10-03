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
		if(s.size()>3)
			m[s]++;
	}
}

int searchMin(vector<pair<string, int>> v, int value)
{
	int i = 0;
	for(; i < v.size()&&v[i].second>value; i++);
	return i;
}

vector<pair<string, int>> results(map<string, int> m)
{
	vector<pair<string, int>> r;
	for(auto &q: m)
	{
		r.insert(r.begin()+searchMin(r,q.second), q);
	}
	return r;
}

int main(int argc, char const *argv[])
{
	if(freopen(argv[1],"r",stdin))
	{
			string s;
		map<string, int> m;
		int i = 0;
		while(getline(cin, s))
		{
			addToMap(m, getWords(s));
			i++;
		}
		cout<<"Leídos "<<i<<" ejemplos"<<endl;

		vector<pair<string, int>> r = results(m);
		int j = 0;
		for(auto &t: r)
		{
			cout<<t.first<<" = "<<t.second<<", "<<(t.second*100/i)<<"%"<<endl;
			j++;
		}
		cout<<"Total de palabras extraídas "<<j<<endl;
	}
	else
	{
		cout<<"Archivo no encontrado"<<endl;
	}

	return 0;
}