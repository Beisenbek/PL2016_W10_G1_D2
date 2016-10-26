#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student{
	string sname;
	string name;
	string cls;
	string bdate;
};

struct cls_students{
	string cls;
	vector<student> students;
};


int main(){
	
	int n;
	cin >> n;

	vector<cls_students> classes;
 
	for(int i = 0; i < n; ++i){
		student s;
		cin >> s.sname >> s.name >> s.cls >> s.bdate;

		bool found = false;
		for(int j = 0; j < classes.size(); ++j){
			if(s.cls == classes[j].cls){
				found = true;
				classes[j].students.push_back(s);
				break;
			}
		}

		if(!found){
			vector<student> tv;
			tv.push_back(s);

			cls_students t;
			t.cls = s.cls;
			t.students = tv;

			classes.push_back(t);
		}
	}	


	for(int i = 0; i < classes.size(); ++i){
		cout << classes[i].cls <<": ";
		for(int j = 0; j < classes[i].students.size(); ++j){
			cout << classes[i].students[j].sname;
			if(j < classes[i].students.size()-1){
				cout << ", ";
			}
		}
		cout << endl;
	}

	
	return 0;
}