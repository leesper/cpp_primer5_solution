#include "folder.h"

void swap(Folder &lhs, Folder &rhs)
{
	for (auto m : lhs.messages)
		m->remFolder(&lhs);
	for (auto m : rhs.messages)
		m->remFolder(&rhs);
	swap(lhs.messages, rhs.messages);
	for (auto m : lhs.messages)
		m->addFolder(&lhs);
	for (auto m : rhs.messages)
		m->addFolder(&rhs);
}

Folder::Folder(const Folder &f):
	messages(f.messages)
{
	add_to_messages(f);
}

Folder& Folder::operator=(const Folder &f)
{
	remove_from_messages();
	messages = f.messages;
	add_to_messages(f);
	return this;
}

Folder::~Folder()
{
	remove_from_messages();
}

void Folder::addMsg(Message *pmsg)
{
	messages.insert(pmsg);
	pmsg->addFolder(this);
}

void Folder::remMsg(Message *pmsg)
{
	messages.erase(pmsg);
	pmsg->remFolder(this);
}

void Folder::add_to_messages(const Folder &f)
{
	for (auto m : f.messages)
		m->addFolder(this);
}

void Folder::remove_from_messages()
{
	for (auto m : messages)
		m->remFolder(this);
}
