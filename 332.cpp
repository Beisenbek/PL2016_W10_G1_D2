#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student{
	string sname;
	string name;
	int a;
	int b;
	int c;
	double avg;
	void printInfo(){
		cout << sname << " " << name  << endl;
	}
};

vector<student> v;
vector<int> avgs;

int main(){

	int n;

	cin >> n;

	for(int i = 0; i < n; ++i){
		student t;
		cin >> t.sname >> t.name >> t.a >> t.b >> t.c;
		t.avg = t.a + t.b + t.c;
		v.push_back(t);


		bool found = false;
		for(int j = 0; j < avgs.size(); ++j){
			if(avgs[j] == t.avg){
				found = true;
				break;
			}
		}

		if(!found){
			avgs.push_back(t.avg);
		}
	}

	sort(avgs.rbegin(), avgs.rend());

	for(int j = 0; j < avgs.size(); ++j){
		for(int i = 0; i < v.size(); ++i){
			if(avgs[j] == v[i].avg) v[i].printInfo();
		}
	}

	return 0;
}