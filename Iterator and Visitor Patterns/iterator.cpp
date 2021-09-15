#include <iostream>
#include <stdexcept>
#include <map>
#include <iterator>

using namespace std;

class Iterator {
 public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual string CurrentItem() = 0;
};

class ArrayIterator : public Iterator {
 private:
	string* _array;
	int _currentPosition{};
	int _length;

 public:
	ArrayIterator(string* array, int length) : _array(array), _length(length) {};

	void First() override {
		_currentPosition = 0;
	}

	void Next() override {
		++_currentPosition;
		if (IsDone()) {
			throw out_of_range("Invalid index");
		}
	}

	bool IsDone() const override {
		return _currentPosition > _length - 1;
	}

	string CurrentItem() override {
		if (IsDone()) {
			throw out_of_range("Invalid index");
		}
		return _array[_currentPosition];
	}

};

class MapIterator : public Iterator {
 private:
	map<string, string> _map;
	int _length{};
	int _current{};

 public:
	MapIterator(map<string, string> map, string substring) {
		for (auto it = map.begin(); it != map.end() ; ++it) {
			string keyValue = it->first;
			for (int i = 0; i < keyValue.length(); ++i)
			{
				if (keyValue[i] == substring[0] && keyValue.length() - i >= substring.length()) {
					int coincidenceCounter = 1;
					for (int j = 1; j < substring.length(); ++j)
					{
						++i;
						if (keyValue[i] == substring[j])
							++coincidenceCounter;
						else break;
					}
					if (coincidenceCounter == substring.length()) {
						_map.insert(pair<string, string>(it->first, it->second));
						++_length;
					}
				}
			}
		}
	}

	void First() override {
		_current = 0;
	}

	void Next() override {
		++_current;
		if (IsDone()) {
			throw out_of_range("Out of range");
		}
	}

	bool IsDone() const override {
		return _current > _length - 1;
	}

	string CurrentItem() override {
		if (IsDone()) {
			throw out_of_range("Out of range");
		}
		auto it = _map.begin();
		for (int i = 0; i < _current; ++i) {
			++it;
		}
		return it->first;
	}
};

int main() {
	string array[] = {"0", "1", "2"};
	ArrayIterator it(array, 3);
	it.First();
	cout << it.CurrentItem() << endl;
	it.Next();
	cout << it.CurrentItem() << endl;
	it.Next();
	cout << endl;


	map<string, string> map;
	map[":(("] = "very sad";
	map[":("] = "sad";
	map[":|"] = "not sad, not happy";
	map[":)"] = "happy";
	map[";)"] = "very happy";
	MapIterator mapIterator(map, ")");
	cout << mapIterator.CurrentItem() << endl;
	mapIterator.Next();
	cout << mapIterator.CurrentItem() << endl;
	return 0;
}
