// Amazon

// {{"ram","shyam"},{"ram","ashish"},{"ashish","gopal"},{"hattimare","nishtha"}
// input  : ram
// output : ram, shyam, ashish, gopal

#include <bits/stdc++.h>

using namespace std;

struct Connection
{
	int item;				// unique ID
	bool visited;			// visited or not while traversing
	vector<int>connect;		// string unique ID connected to it

	Connection(int i) {
		visited = false;	// initially not visited
		item = i;			// assign unique ID corresponding to string
	}// end Connection()
};

void traversal(string input, unordered_map<string, Connection*>& hash, unordered_map<int, string>& indexString, vector<string>& result)
{
	// if the current string is already visited
	if(hash[input]->visited == true) return;

	hash[input]->visited = true;	// make the string node visited
	result.push_back(input);		// insert the input into the result

	// Traverse the string nodes, the current string is connected to
	for(int i = 0; i < hash[input]->connect.size(); i++) {

		traversal(indexString[hash[input]->connect[i]], hash, indexString, result);
	}// end for

	return;
}// end traversal()

vector<string> synonymousString(vector<pair<string, string>>& arr, string input)
{
	vector<string> result;

	unordered_map<string, Connection*> hash;	// string to Connection nod Hash
	unordered_map<int, string> indexString;		// string to ID hash
	unordered_map<string, int> stringIndex;		// ID to string hash

	int items = 0;

	// traverse the pair vector
	for(pair<string, string> x : arr) {
		// make new Connection node to every unique string input in the pair
		
		if(hash.find(x.first) == hash.end()) {
			hash[x.first] = new Connection(items);	// make new Connection node

			indexString[items++] = x.first;			// string to int pair
			stringIndex[x.first] = items-1;			// int to string pair
		}// end if

		if(hash.find(x.second) == hash.end()) {
			hash[x.second] = new Connection(items);	// make new Connection node

			indexString[items++] = x.second;		// string to int pair
			stringIndex[x.second] = items-1;		// int to string pair
		}// end if
	}// end for

	// if the input string is not in the list of given string arr
	if(hash.find(input) == hash.end()) {
		return result;
	}// end if

	// make the connection bidirectional
	for(pair<string, string> x : arr) {
		hash[x.first]->connect.push_back(stringIndex[x.second]);
		hash[x.second]->connect.push_back(stringIndex[x.first]);
	}// end for

	traversal(input, hash, indexString, result);
	return result;

}// end synonymousString()

int main()
{
	int q;
	string str1, str2, input;

	vector<pair<string, string>> arr;

	cin >> q;
	while(q--) {
		cin >> str1 >> str2;
		arr.push_back(make_pair(str1, str2));
	}

	cin >> input;

	vector<string> result = synonymousString(arr, input);

	for(string x : result) {
		cout << x << " ";
	}
	printf("\n");

	return 0;
}