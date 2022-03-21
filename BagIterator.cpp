#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	this->current = 0;
}

//Total complexity: Theta(1)
void BagIterator::first() {
	this->current = 0;
}

//Total complexity: Theta(1)
void BagIterator::next() {
	if (this->current >= this->bag.xNrElements) {
		throw exception();
	}
	else {
		this->current++;
	}
}

//Total complexity: Theta(1)
bool BagIterator::valid() const {
	if (this->current < this->bag.xNrElements) {
		return true;
	}
	else {
		return false;
	}
}

//Total complexity: Theta(1)
TElem BagIterator::getCurrent() const
{	if (this->current >= this->bag.xNrElements) {
		throw exception();
	}
	int poz = this->bag.x[this->current];
	return this->bag.elements[poz];
	return 0;
}
