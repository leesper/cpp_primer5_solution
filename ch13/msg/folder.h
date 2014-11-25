#ifndef FOLDER_H
#define FOLDER_H
#include <set>
#include "message.h"
using std::set;

class Folder
{
	friend void swap(Folder &lhs, Folder &rhs);
public:
	Folder() = default;
	Folder(const Folder &f);
	Folder& operator=(const Folder &f);
	~Folder();
	void addMsg(Message *pmsg);
	void remMsg(Message *pmsg);
private:
	void add_to_messages(const Folder &f);
	void remove_from_messages();
	set<Message*> messages;
};
void swap(Folder &lhs, Folder &rhs);
#endif//FOLDER_H
