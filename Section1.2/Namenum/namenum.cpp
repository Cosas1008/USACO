/*
ID: yuweiic1
LANG: C++
TASK: namenum
*/
#include <iostream>
#include <fstream>

// having trouble chosing the suitable container for dict
#include <set>
// #include <map>
using namespace std;


int main()
{
	ifstream fin("namenum.in");
	ifstream dict("dict.txt");
	int namenum;
	fin >> namenum;
	set<string> dictionary;
	string name;
	// read dictionary in
	while(getline(dict,name))
		dictionary.insert(name);
	dict.close();

	//// debug: output the name set
	// for(auto it = dictionary.begin(); it != dictionary.end(); it++){
	// 	cout << " " << *it;
	// }
	// cout << endl;
	
	dict.close();
	fin.close();
	return 0;
}