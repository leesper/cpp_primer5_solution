#include "message.h"

void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

Message::Message(const Message &msg):
	contents(msg.contents), folders(msg.folders)
{
	add_to_Folders(msg);
}

Message& Message::operator=(const Message &msg)
{
	remove_from_Folders();
	contents = msg.contents;
	folders = msg.folders;
	add_to_Folders(msg);
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

Message::Message(Message &&msg): contents(std::move(msg.contents))
{
	move_Folders(&m);
}

Message& Message::operator=(Message &&msg)
{
	if (*this != &msg)
	{
		remove_from_Folders();
		contents = std::move(msg.contents);
		move_Folders(&msg);
	}
	return *this;
}

void Message::save(Folder &folder)
{
	folders.insert(&folder);
	folder.addMsg(this);
}

void Message::remove(Folder &folder)
{
	folders.erase(&folder);
	folder.remMsg(this);
}

void Message::add_to_Folders(const Message &msg)
{
	for (auto f : msg.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

void Message::move_Folders(Message *m)
{
	folders = std::move(m->folders);
	for (auto f : folders)
	{
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

void Message::addFolder(Folder *f)
{
	folders.insert(f);
	f->addMsg(this);
}

void Message::remFolder(Folder *f)
{
	folders.erase(f);
	f->remMsg(this);
}
