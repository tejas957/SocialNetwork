// Design and implement an application that maintains the data for a simple social network. Each person in
// the network should have a profile that contains the person’s name, current status, and a list of
// friends. Your application should allow a user to join the network, leave the network, create a profile, modify the
// profile, search for other profiles, and add friends.
#pragma once
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class Profile
{
private:
	const string USERNAME;
	string name;

	bool status;
	list <string> friends;

public:
	Profile(string n) {
		name = n;
		status = true;
	}

	string getName()const {
		return name;
	}

	string getUsername()const {
		return USERNAME;
	}


	string getStatus(){
		if(status == true) {
			return "Active";
		}
		return "Inactive";
	}
	void getFriends() {
		for(string f:friends)
			cout << f << "   ";
	}
	void setName(string dg) {
		name = dg;
	}
	void setStatus(string dg) {
		if (dg == "Active") {
			status = true;
		}
		else {
			status = false;
		}
	}
	void addFriend(string profileName) {
		list<string>::iterator ot;
		bool friendExists = false;
		for (ot = friends.begin(); ot != friends.end(); ot++) {
			if (*ot == profileName) {
				friendExists = true;
			}
		}
		if (friendExists == false) {
			friends.push_back(profileName);
		}
		else {
			cout << "This friend already exists!" << endl;
		}
	}
	void removeFriend(string profileName) {
		list<string>::iterator lt = friends.begin();
		bool removed = false;
		while (lt != friends.end()) {
			if (*lt == profileName) {
				friends.remove(profileName);
				cout << "This friend has been removed!" << endl;
				removed = true;
				break;
			}
			lt++;
		}
		if(!removed)
			cout << "Friend does not exist!" << endl;
	}
	friend ostream& operator <<(ostream& o, Profile p) {
		o << p.getName() << endl;
		o << p.getStatus() << endl;
		for (string f : p.friends)
			o << f << " ";
		o << endl;
		return o;
	}


	
};

