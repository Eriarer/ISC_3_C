#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;
using namespace std::literals;

class Chronometer {
private:
	milliseconds current;
	steady_clock::time_point tp1;
	steady_clock::time_point tp2;
public:
	void Start() {
		tp1 = steady_clock::now();
	}

	void CheckCurrentTime() {
		tp2 = steady_clock::now();
		current = duration_cast<milliseconds>(tp2 - tp1);
	}

	long long GetCurrent() {
		return current.count();
	}

	auto GetSecconds() {
		return (current.count() / 1000);
	}

	WORD GetMiliseconds() {
		return (current.count() % 1000);
	}
};

class CTime {
public:
	Chronometer chrono;
	int minutes;
	int hours;
	int seconds;
	int milisecons;
	CTime() {
		hours = minutes = seconds = 0;
		milisecons = 0;
	}

	void Update() {
		milisecons = chrono.GetMiliseconds();
		//int tick = 3600 * 20 + (60 * 10) + (45);
		seconds = chrono.GetSecconds() % 60;
		minutes = chrono.GetSecconds() / 60 % 60;
		hours = chrono.GetSecconds() / 3600 % 24;
	}

	friend ostream& operator<<(ostream& cout, CTime& obj);
};

ostream& operator<<(ostream& cout, CTime& obj) {
	cout << setfill('0');
	cout << setw(2) <<  obj.minutes;
	cout << ':';
	cout << setw(2) << obj.seconds;
	cout << '.';
	cout << setw(3) << obj.milisecons;

	return cout;
}