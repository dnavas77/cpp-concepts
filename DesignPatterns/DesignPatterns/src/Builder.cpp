#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <sstream>

using namespace std;

// forward declare
struct HtmlBuilder;

struct HtmlElement {
	string name;
	string text;
	vector<HtmlElement> elements;
	const size_t indent_size = 2;

	string str(int indent = 0) const {
		ostringstream oss;
		string i(indent_size * indent, ' ');
		oss << i << "<" << name << ">\n";
		if (text.size() > 0) {
			oss << string(indent_size*(indent + 1), ' ') << text << '\n';
		}
		for (const auto& e : elements) {
			oss << e.str(indent + 1);
		}
		oss << i << "</" << name << ">" << '\n';
		return oss.str();
	}

	static unique_ptr<HtmlBuilder> build(string root_name) {
		return make_unique<HtmlBuilder>(root_name);
	}
private:
	friend class HtmlBuilder;
	HtmlElement() { }

	HtmlElement(const string& name, const string& text)
	: name(name), text(text)
	{ }
};

struct HtmlBuilder {
	HtmlBuilder(string root_name) {
		root.name = root_name;
	}
	HtmlElement root;

	operator HtmlElement() const { return root; }

	// fluent
	HtmlBuilder& add_child(string child_name, string child_text) {
		HtmlElement e{ child_name, child_text };
		root.elements.emplace_back(e);
		return *this;
	}
};

int main() {
	string words[] = { "hello", "world" };

	HtmlElement e = HtmlElement::build("ul")
					->add_child("li", "hello")
					.add_child("li", "world");

	cout << e.str() << '\n';

	cin.get();
	return 0;
}
