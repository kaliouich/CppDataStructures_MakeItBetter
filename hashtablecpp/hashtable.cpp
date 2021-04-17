// CPP program to implement hashing with chaining
#include<bits/stdc++.h>
using namespace std;

class Hash
{
	int BUCKET; // No. of buckets

	// Pointer to an array containing buckets
	list<pair<int,string>> *table;
public:
	Hash(int V); // Constructor

	// inserts a key into hash table
	void insertItem(pair<int,string>);

	// deletes a key from hash table
	void deleteItem(pair<int,string>);

	// hash function to map values to key
	int hashFunction(int x) {
		return (x % BUCKET);
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<pair<int,string>>[BUCKET];
}

void Hash::insertItem(pair<int,string> key)
{
	int index = hashFunction(key.first);
	table[index].push_back(key);
}

void Hash::deleteItem(pair<int,string> key)
{
// get the hash index of key
int index = hashFunction(key.first);

// find the key in (inex)th list
list <pair<int,string>> :: iterator i;
for (i = table[index].begin();
		i != table[index].end(); i++) {
	if (*i == key)
	break;
}

// if key is found in hash table, remove it
if (i != table[index].end())
	table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() {
for (int i = 0; i < BUCKET; i++) {
	cout << i;
	for (auto x : table[i])
	cout << " --> " << x.first << "," << x.second;
	cout << endl;
}
}

// Driver program
int main()
{
// array that contains keys to be mapped
pair<int,string> a[] = {make_pair(14,"salwa"),
						make_pair(10,"khalil"),
						make_pair(9,"yahya"),
						make_pair(5,"aya"),
						make_pair(15,"ibtihal"),
						make_pair(11,"maroua")};

int n = sizeof(a)/sizeof(a[0]);

// insert the keys into the hash table
Hash h(10); // 10 is count of buckets in
			// hash table
for (int i = 0; i < n; i++)
	h.insertItem(a[i]);

// display the Hash table
h.displayHash();

cout << endl;

// delete 12 from hash table
h.deleteItem(make_pair(5,"aya"));

// display the Hash table
h.displayHash();

return 0;
}
