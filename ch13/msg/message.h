#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <set>
#include "folder.h"
using std::string;
using std::set;

class Message
{
	friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
public:
	explicit Message(const string &str = ""):
		contents(str) {}
	// copy control
	Message(const Message &msg);
	Message& operator=(const Message &msg);
	~Message();
	Message(Message &&msg);
	Message& operator=(Message &&msg);
	void save(Folder &folder);
	void remove(Folder &folder);
	void addFolder(Folder *f);
	void remFolder(Folder *f);
private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message &msg);
	void remove_from_Folders();
	void move_Folders(Message *m);
};
#endif//MESSAGE_H
