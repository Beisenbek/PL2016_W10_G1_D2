#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student{
	string sname;
	string name;
	string cls;
	int n_cls;
	char c_cls;
	string bdate;
	void divide(){

		/*
		
		cls = "11" = int(cls[0])*10 + int(cls[1]) = (49-48)*10+(49-48) = 10 + 1= 11

		cls = "11B"
		0 - '0' 48 - 48 = 0
		1 - '1' 49 - 48 = 1
		2 - '2' 50
		3 - '3' 51
		4 - '4' 52
		5 - '5' 53
		6 - '6' 54


		int('1') = 49
		*/
		if(cls.length() == 3){
			n_cls = (int(cls[0])-48)*10 + int(cls[1])- 48;
			c_cls = cls[2];
		}
		else if(cls.length() == 2){
			n_cls = int(cls[0])-48;
			c_cls = cls[1];
		}
	}
};


bool f(student l, student r){
	if(l.n_cls > r.n_cls) return false;

	if(l.n_cls == r.n_cls){
		if(l.c_cls > r.c_cls) return false;
		if(l.c_cls == r.c_cls){
			if(l.sname > r.sname) return false;
		}
	}

	return true;
}

int main(){
	
	int n;
	cin >> n;
	vector<student> v;

	for(int i = 0; i < n; ++i){
		student s;
		cin >> s.sname >> s.name >> s.cls >> s.bdate;
		s.divide();
		v.push_back(s);
	}	

	sort(v.begin(),v.end(),f);

	for(int i = 0; i < n; ++i){
		cout << v[i].cls << " " << v[i].sname << " " << v[i].name << " " << v[i].bdate << endl;
	}
	
	return 0;
}