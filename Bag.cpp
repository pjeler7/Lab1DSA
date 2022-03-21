#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	this->nrElements = 0;
	this->capacity = 500;
	this->elements = new TElem[this->capacity];
	this->xCapacity = 500;
	this->xNrElements = 0;
	this->x = new int[this->xCapacity];
}

//Best: Theta(1), avg: O(n), worst: O(n)
void Bag::add(TElem elem) {
	int poz = this->find(elem);

	if (poz == -1) {
		if (this->nrElements == this->capacity) {
			this->capacity *= 2;
			TElem* auxElems = new TElem[this->capacity];
			for (int i = 0; i < this->nrElements; i++) {
				auxElems[i] = this->elements[i];
			}
			delete[] this->elements;
			this->elements = auxElems;
		}
		this->elements[this->nrElements++] = elem;
		poz = this->nrElements - 1;
	}

	if (this->xNrElements == this->xCapacity) {
		this->xCapacity *= 2;
		TElem* auxElems = new TElem[this->xCapacity];
		for (int i = 0; i < this->xNrElements; i++) {
			auxElems[i] = this->x[i];
		}
		delete[] this->x;
		this->x = auxElems;
	}

	this->x[xNrElements++] = poz;
}

//best: O(n), avg:O(n), worst: O(n)
bool Bag::remove(TElem elem) {
	TElem i;
	int freq = 0;
	int pos = -1;
	int posElement = -1;

	for (i = 0; i < this->xNrElements; i++)
	{
		if (elem == this->elements[this->x[i]])
		{
			freq++;
			pos = i;
			posElement = this->x[i];
		}
	}


	if (freq == 1) {
		this->elements[posElement] = this->elements[this->nrElements - 1];
		this->x[pos] = this->x[this->xNrElements - 1];
		this->xNrElements--;

		for (i = 0; i < this->xNrElements; i++)
		{
			if (this->x[i] == nrElements - 1)
				this->x[i] = posElement;
		}
		this->nrElements--;

		/*if (this->nrElements * 2 <= this->capacity) {
			this->capacity /= 2;
			TElem* auxElems = new TElem[this->capacity];
			for (int i = 0; i < this->nrElements; i++) {
				auxElems[i] = this->elements[i];
			}
			delete[] this->elements;
			this->elements = auxElems;
		}*/

		/*	if (this->xNrElements * 2 <= this->xCapacity) {
				this->xCapacity /= 2;
				TElem* auxElems = new TElem[this->xCapacity];
				for (int i = 0; i < this->xNrElements; i++) {
					auxElems[i] = this->x[i];
				}
				delete[] this->x;
				this->x = auxElems;
			}*/

		return true;
	}

	if (freq > 1) {
		this->x[pos] = this->x[this->xNrElements - 1];
		this->xNrElements--;

		//	if (this->xNrElements * 2 <= this->xCapacity) {
		//		this->xCapacity /= 2;
		//		TElem* auxElems = new TElem[this->xCapacity];
		//		for (int i = 0; i < this->xNrElements; i++) {
		//			auxElems[i] = this->x[i];
		//		}
		//		delete[] this->x;
		//		this->x = auxElems;
		//	}
		return true;
	}

	return false;
}

//best: O(1), avg:O(n), worst: O(n)
bool Bag::search(TElem elem) const {
	bool found = false;
	int index = 0;

	while (index < this->nrElements && found == false) {
		if (this->elements[index] == elem) {
			found = true;
		}
		else {
			index++;
		}
	}

	return found;
}

//best: O(1), avg:O(n), worst: O(n)
int Bag::nrOccurrences(TElem elem) const {
	int index = 0;
	int count = 0;
	int a = this->find(elem);

	if (a != -1) {
		while (index < this->xNrElements) {
			if (this->x[index] == a) {
				count++;
			}
			index++;
		}
	}

	return count;
}

//Total complexity: Theta(1)
int Bag::size() const {
	return this->xNrElements;
}

//Total complexity: Theta(1)
bool Bag::isEmpty() const {
	return this->xNrElements == 0;
}

//Total complexity: Theta(1)
BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

//best: O(1), avg:O(n), worst: O(n)
int Bag::find(TElem e) const {
	int index = 0;

	while (index < this->nrElements) {
		if (this->elements[index] == e) {
			return index;
		}
		index++;
	}

	return -1;
}


Bag::~Bag() {
	delete[] this->elements;
}

