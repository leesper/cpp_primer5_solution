#include <iostream>
#include <memory>
using namespace std;

struct destination {};
struct connection {};

connection connect(destination*)
{
	cout << "connect" << endl;
	connection con;
	return con;
}

void disconnect(connection)
{
	cout << "disconnect" << endl;
}

void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });
	cout << "use the connection" << endl;
}

int main()
{
	destination dest;
	f(dest);
	return 0;
}
