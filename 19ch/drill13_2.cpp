#include <vector>
#include <iostream>
#include <memory>


using namespace::std;
unique_ptr<vector<int>> suspicious()
{
	auto p = make_unique<vector<int>>();
	for(int i; cin >> i; )
	{
		if(i) p->push_back(i);
		else throw exception();
	}
	return p;
}

int main()
try {
	auto p = suspicious();
	for(int i = 0; i < p->size(); ++i)
		cout << p->at(i) << ' ';
		cout << endl;
	return 0;
} catch (std::exception& e){
	std::cerr << "Error!\n";
	return 1;
}