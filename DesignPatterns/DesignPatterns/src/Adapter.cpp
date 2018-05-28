#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <sstream>

using namespace std;

class String {
	string s;
public:
	String(const string &s) : s(s) {}

	String toLowerCopy() const {
		return { boost::to_lower_copy(s) };
	}

	vector<String> split(const string& delimiter = " ") const {
		vector<string> parts;
		boost::split(
			parts,
			s,
			boost::is_any_of(delimiter),
			boost::token_compress_on
		);
		return vector<String>(parts.begin(), parts.end());
	}

	size_t getLength() const {
		return s.length();
	}
};

int main() {
	String s{ "Hello    world" };

	for (auto& w : s.toLowerCopy().split()) {
		cout << w.getLength() << "\n";
	}

	char a;
	cin >> a;
	return 0;
}
