#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H
#include <string>
#include "quote.h"

class Limit_quote : public Quote
{
public:
	Limit_quote() = default;
	Limit_quote(const std::string&, double, std::size_t, double);
	virtual double net_price(std::size_t) const override;
private:
	std::size_t limit = 0;
	double discount = 0.0;
};

Limit_quote::Limit_quote(const std::string &book, double p, std::size_t l, double disc):
		Quote(book, p), limit(l), discount(disc)
{}

double Limit_quote::net_price(std::size_t n) const
{
	double net;
	if (n <= limit)
		net = n * price * (1 - discount);
	else
		net = limit * price * (1 - discount) + (n - limit) * price;
	return net;
}
#endif//LIMIT_QUOTE_H
