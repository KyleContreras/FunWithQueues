#pragma once

#include "Queue.h"
//#include "structProfile.cpp"

template <typename T>
class Facebook {
	public:

		Facebook()
			: numOfFriends(0), user(), friendsList() {}
		
		//~Facebook();

		void addFriend(T*& node)
		{
			numOfFriends += 1;
			this->friendsList.enqueue(node);
		}

		void removeFriend()
		{
			this->friendsList.dequeue();
		}

		void printFriendsF()
		{
			this->friendsList.print();
		}

		void printFriendsR()
		{
			this->friendsList.reversePrint();
		}

		void firstFriend()
		{
			this->friendsList.peek();
		}

		void resetFriends()
		{
			this->friendsList.makeEmpty();
		}

		void checklist()
		{
			this->friendsList.isEmpty();
		}

	private:
		int numOfFriends;
		T user;
		Queue<T> friendsList;
};