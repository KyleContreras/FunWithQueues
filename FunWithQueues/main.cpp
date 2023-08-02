#include <fstream>
#include <iostream>
#include <string>

#include "Queue.h"
#include "Facebook.h"
#include "structProfile.cpp"

using namespace std;

int main(int argc, char* argv[])
{
    string presidents = argv[1];

    Facebook<Profile> fbPerson;
    Queue<Profile> queueStart;
    Profile* pres = NULL;

    int lineLength;
    string line;
    string presName;
    string presState;

    ifstream inStream;
    inStream.open(presidents, ios::in);

    fbPerson.checklist();
    cout << endl;

    while (inStream.peek() != EOF)
    {
        getline(inStream, line);

        lineLength = line.length();
        presName = line.substr(0, (lineLength - 3));
        presState = line.substr((lineLength - 2), lineLength);

        pres = new Profile(presName, presState);

        cout << "Adding: " << pres->name << " " << pres->state << endl;

        fbPerson.addFriend(pres);
    }

    cout << endl;

    fbPerson.firstFriend();
    cout << endl;

    fbPerson.removeFriend();
    cout << endl;

    fbPerson.printFriendsF();
    cout << endl;

    fbPerson.printFriendsR();
    cout << endl;

    fbPerson.resetFriends();
    cout << endl;

    fbPerson.checklist();
    cout << endl;
}
