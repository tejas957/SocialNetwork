// Design and implement an application that maintains the data for a simple social network. Each person in
// the network should have a profile that contains the person’s name, current status, and a list of
// friends. Your application should allow a user to join the network, leave the network, create a profile, modify the
// profile, search for other profiles, and add friends.
#include <iostream>
#include <string>
#include "Profile.h"
#include "GraphList.h"

using namespace std;
Profile createProfile();
void joinNetwork(Profile, list<Profile>&);
void leaveNetwork(Profile, list<Profile>&);
bool checkMembership(Profile, list<Profile>&);
void displayNetwork(list<Profile>);

int main() {
	/*Profile Ken123("Ken Koech");
	Profile TejastheMermaid("Tejas Senthil");
	Profile GatiktheDeadDodo("Gatik Senthil");
	TejastheMermaid.addFriend("Ken Koech");
	TejastheMermaid.addFriend("Ken Koech");
	cout << TejastheMermaid;
	TejastheMermaid.removeFriend("Ken Koech");
	TejastheMermaid.removeFriend("Gatik Senthil");
*/
	list<Profile> network;
	Profile Tejas("Tejas Senthil");
	joinNetwork(Tejas, network);
	displayNetwork(network);
	leaveNetwork(Tejas, network);
	displayNetwork(network);

}

Profile createProfile() {
	string g;
	cout << "Enter a profile name: ";
	getline(cin, g);
	Profile profile(g);
	return profile;
}

bool checkMembership(Profile p, list<Profile>& n) {
	for (Profile e : n) {
		if (e.getUsername() == p.getUsername()) {
			return true;
		}
	}
	return false;
}

void joinNetwork(Profile p, list<Profile>& n) {
	if (checkMembership(p, n)) {
		cout << "This username is already taken. Please try another name" << endl;
	}
	else {
		n.push_back(p);
		cout << "Profile " << p.getName() << " has been add to the network" << endl;
	}
}
void leaveNetwork(Profile p, list<Profile>& n) {
	if (!checkMembership(p, n)) {
		cout << "This user is not yet in the network!" << endl;
	}
	else {
		list<Profile> ::iterator it, gt;
		it = n.begin();
		gt = n.end();
		gt--;
		while (it != n.end()) {
			if ((*it).getUsername() == p.getUsername()) {
				swap(it, gt);
				n.pop_back();
				break;
			}
		}
		cout << "Profile " << p.getName() << " has been removed from the network" << endl;
	}
}

void displayNetwork(list<Profile> n) {
	for (Profile e : n) {
		cout << e << endl;
	}
}



