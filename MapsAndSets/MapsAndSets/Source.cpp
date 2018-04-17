#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<time.h>
#include<cstdbool>
using namespace std;

void store_set(string fileName)
{
	ifstream inFile;
	set<string> setWords;
	string data;
	ofstream outFile;
	string outFileName = fileName + "_set.txt";
	string inFileName = fileName + ".txt";
	inFile.open(inFileName);
	while (inFile >> data)
	{
		string res;
		for (int i = 0; i < data.length(); i++)
			if (isalpha(data[i]))
				res = res + data[i];
		setWords.insert(res);
	}
	inFile.close();

	outFile.open(outFileName);
	for (set<string>::iterator it = setWords.begin(); it != setWords.end(); it++)
	{
		string el = *it;
		outFile << el << endl;
	}
	outFile.close();
	//cout << "Set size: " << setWords.size() << endl;
}

vector<string> store_vector(string fileName)
{
	ifstream inFile;
	vector<string> words;
	string data;
	ofstream outFile;
	string outFileName = fileName + "_vector.txt";
	string inFileName = fileName + ".txt";
	inFile.open(inFileName);
	while (inFile >> data)
	{
		string res;
		for (int i = 0; i < data.length(); i++)
				if (isalpha(data[i]))
					res = res + data[i];
		words.push_back(res);
	}
	inFile.close();
	outFile.open(outFileName);
	for (int i=0; i<words.size();i++)
	{
		outFile << words.at(i) << endl;
	}
	outFile.close();
	//cout << "Vector size: " << words.size() << endl;
	return words;
}

int main(int argc, char **argv)
{
	store_set(argv[1]);
	vector<string> words = store_vector(argv[1]);

	//---------------------------------------------part 3
	map<string, string> wordmap3;
	string last = "";
	for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
	{
		wordmap3[last] = *it;
		last = *it;
	}
	ofstream outMap;
	string outMapName = argv[1];
	outMapName = outMapName +"_1_1.txt";
	outMap.open(outMapName);
	for (map<string, string>::iterator it = wordmap3.begin(); it != wordmap3.end(); it++)
		outMap << it->first << ", " << it->second << endl;
	outMap.close();
	//---------------------------------------------end part3

	//---------------------------------------------part4
	cout << "This is part4" << endl;
	string state4 = "";
	for (int i = 0; i < 100; i++)
	{
		cout << wordmap3[state4] << " ";
		state4 = wordmap3[state4];
	}
	cout << endl;
	
	//---------------------------------------------end part4

	//---------------------------------------------part5
	cout << "This is part5" << endl;
	map<string, vector<string>>wordmap5;
	string state5 = "";
	for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
	{
		wordmap5[state5].push_back(*it);
		state5 = *it;
	}
	int cnt = 0;
	for (map<string, vector<string>>::iterator it = wordmap5.begin(); it != wordmap5.end(); it++)
	{
		if (cnt == 5)
			for (int i = 0; i < it->second.size(); i++)
				cout << it->second.at(i) << " ";
		cnt++;
	}
	cout << endl;
	srand(time(NULL));
	string state51 = "";
	for (int i = 0; i < 100; i++)
	{
		int ind = rand() % wordmap5[state51].size();
		cout << wordmap5[state51][ind] << " ";
		state51 = wordmap5[state51][ind];
	}
	cout << endl;
	cout << endl;
	//---------------------------------------------end part5

	//---------------------------------------------part6
	cout << "This is part6" << endl;
	map <list<string>, vector<string>> wordmap6;
	list<string> state6;
	for (int i = 0; i < 2; i++)
		state6.push_back("");
	for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
	{
		wordmap6[state6].push_back(*it);
		state6.push_back(*it);
		state6.pop_front();
	}

	list<string> state61;
	for (int i = 0; i < 2; i++)
		state61.push_back("");
	for (int i = 0; i < 100; i++)
	{
		int ind = rand() % wordmap6[state61].size();
		cout << wordmap6[state61][ind] << " ";
		state61.push_back(wordmap6[state61][ind]);
		state61.pop_front();
	}
	cout << endl;
	//---------------------------------------------end part6

	//---------------------------------------------part7
	cout << "This is part7" << endl;
	vector<string> words7 = store_vector("Frost");
	map <list<string>, vector<string>> wordmap7;
	list<string> state7;
	for (int i = 0; i < 2; i++)
		state7.push_back("");
	for (vector<string>::iterator it = words7.begin(); it != words7.end(); it++)
	{
		wordmap7[state7].push_back(*it);
		state7.push_back(*it);
		state7.pop_front();
	}

	list<string> state71;
	for (int i = 0; i < 2; i++)
		state71.push_back("");
	for (int i = 0; i < 100; i++)
	{
		int ind = rand() % wordmap7[state71].size();
		cout << wordmap7[state71][ind] << " ";
		state71.push_back(wordmap7[state71][ind]);
		state71.pop_front();
	}
	cout << endl;
	//---------------------------------------------end part7
	return 0;
}