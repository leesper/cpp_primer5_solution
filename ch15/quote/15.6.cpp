#include "quote.h"
#include "bulk_quote.h"
using namespace std;

int main()
{
	Quote qt("computer", 5.5);
	print_total(cout, qt, 3);
	Bulk_quote bp("networks", 5.6, 3, 0.7);
	print_total(cout, bp, 2);
	print_total(cout, bp, 10);
	return 0;
}
