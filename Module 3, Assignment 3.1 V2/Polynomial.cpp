#include "Polynomial.h"

Polynomial::Polynomial() : poly{} {};
Polynomial::Polynomial(const ArrayBag<Term> sourceBag) : poly{ sourceBag } {};
Polynomial::Polynomial(const Polynomial& sourcePolynomial) : poly{ sourcePolynomial.poly } {};
Polynomial::~Polynomial() {
	//cout << "\nPolynomial object released...";
}

Polynomial& Polynomial::operator = (const Polynomial& rightSide) {
	this->poly = rightSide.getPoly();
	return *this;
}

Polynomial& Polynomial::changeCoefficient() {
	Term tmpTerm{};
	cin >> tmpTerm;
	this->poly.add(tmpTerm);
	return *this;
}

const int Polynomial::getDegree() const {
	int highestDegree{};
	for (int i{}; i < poly.getCurrentSize(); i++) {
		if (poly.getItem(i).getExp() > highestDegree) {
			highestDegree = poly.getItem(i).getExp();
		}
	}
	return highestDegree;
}

const int Polynomial::coefficient(const int sourceExponent) const {
	for (int i{}; i < poly.getCurrentSize(); i++) {
		if (poly.getItem(i).getExp() == sourceExponent) {
			return poly.getItem(i).getCoef();
		}
	}

	cout << "\nThe Coefficient does not exist!";
	return 0;
}

Polynomial& Polynomial::increaseCoefficient(const int sourceCoefficient, const int sourceDegree) {
	Term toIncrease{ sourceCoefficient, sourceDegree };

	if (this->poly.contains(toIncrease)) {
		const int index{ this->poly.getIndexOf(toIncrease, 0) };
		this->poly.replaceItem(getPoly().getItem(index) += toIncrease, index);
		cout << "\nCoefficient adjusted!";
	}
	else {
		cout << "\nThe term you were looking for was not found!";
	}

	return *this;
}

const ArrayBag<Term> Polynomial::getPoly() const {
	return poly;
}

const int Polynomial::getHighestPowerCoefficient() const {
	int highestDegree{}, tmpCoef{};
	for (int i{}; i < poly.getCurrentSize(); i++) {
		if (poly.getItem(i).getExp() > highestDegree) {
			highestDegree = poly.getItem(i).getExp();
			tmpCoef = getPoly().getItem(i).getCoef();
		}
	}
	return tmpCoef;
}

Polynomial& Polynomial::removeTerm() {
	if (this->getPoly().getCurrentSize() > 1) {
		int tmpExp{};
		cout << "\n\t- What term do you want to delete? (Enter its exponent) --> ";
		cin >> tmpExp;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid input, please re-enter --> ";
			cin >> tmpExp;
		}

		if (this->poly.remove(Term{ 0,tmpExp })) {
			cout << "\nTerm removed!";
		}
		else {
			cout << "\nUnable to remove it/not found!";
		}
	}
	else {
		cout << "\nCan't remove anymore, for that, delete the polynomial!";
	}

	return *this;
}

Polynomial& Polynomial::sortPolynomial() {
	this->mergeSort(0, (this->poly.getCurrentSize() - 1));
	this->checkSimilarTerms();
	this->mergeSort(0, (this->poly.getCurrentSize() - 1));
	return *this;
}

Polynomial& Polynomial::checkSimilarTerms() {
	int index{};
	do {
		const int repeatedTerms{ this->poly.getFrequencyOf(this->poly.getItem(index)) };
		if (repeatedTerms > 1) {
			ArrayBag<Term> tmpRepeatedTerms{};

			int tmpIndex{ this->poly.getIndexOf(this->poly.getItem(index), 0) };
			tmpRepeatedTerms.add(this->poly.getItem(tmpIndex));
			this->poly.remove(tmpRepeatedTerms.getItem(0));

			for (int i{}; i < (repeatedTerms - 1); i++) {
				tmpIndex = this->poly.getIndexOf(tmpRepeatedTerms.getItem(0), 0);
				tmpRepeatedTerms.add(this->poly.getItem(tmpIndex));
				this->poly.remove(tmpRepeatedTerms.getItem(0));
			}

			Term total{};
			int counter{};
			while (counter <= repeatedTerms - 1) {
				total += tmpRepeatedTerms.getItem(counter);
				counter++;
			}

			this->poly.add(total);
		}
		index++;
	} while (index < this->poly.getCurrentSize());
	return *this;
}

Polynomial& Polynomial::merge(int first, int mid, int last) {
	Term* tempArray{ new Term[(last + 1)] {} };
	int first1{ first },
		last1{ mid },
		first2{ (mid + 1) },
		last2{ last },
		index{ first1 };

	while ((first1 <= last1) && (first2 <= last2)) {
		if (this->poly.getItem(first1) >= this->poly.getItem(first2)) {
			tempArray[index] = this->poly.getItem(first1);
			first1++;
		}
		else {
			tempArray[index] = this->poly.getItem(first2);
			first2++;
		}
		index++;
	}

	while (first1 <= last1) {
		tempArray[index] = this->poly.getItem(first1);
		first1++;
		index++;
	}

	while (first2 <= last2) {
		tempArray[index] = this->poly.getItem(first2);
		first2++;
		index++;
	}

	for (index = first; index <= last; index++) {
		this->poly.replaceItem(tempArray[index], index);
	}
}

Polynomial& Polynomial::mergeSort(int first, int last) {
	if (first < last) {
		int mid{ (last + first) / 2 };
		this->mergeSort(first, mid);
		this->mergeSort(mid + 1, last);
		this->merge(first, mid, last);
	}
	return *this;
}

const bool Polynomial::operator == (const Polynomial& rightSide) const {
	const int leftSize{ getPoly().getCurrentSize() }, rightSize{ rightSide.getPoly().getCurrentSize() };

	int counter{};
	if (leftSize == rightSize) {
		for (int i{}; i < leftSize; i++) {
			if (getPoly().getItem(i) == rightSide.getPoly().getItem(i) && 
				getPoly().getItem(i).getCoef() == rightSide.getPoly().getItem(i).getCoef()) {
				counter++;
			}
		}
	}

	if (counter == leftSize) {
		return true;
	}

	return false;
}

Polynomial& Polynomial::operator + (const Polynomial& rightSide) {
	const int leftSize{ this->poly.getCurrentSize() }, rightSize{ rightSide.poly.getCurrentSize() };
	int combinationsCounter{};

	if (leftSize == rightSize) {
		for (int i{}; i < leftSize; i++) {
			if (this->poly.getItem(i) == rightSide.poly.getItem(i)) {
				this->poly.replaceItem((this->poly.getItem(i) += rightSide.poly.getItem(i)), i);
				combinationsCounter++;
			}
			else {
				cout << "\n\nUnable to combine this term --> " << rightSide.poly.getItem(i)
					<< "\nIt is going to be appended in the end...";
				this->poly.add(rightSide.poly.getItem(i));
			}
		}
	}
	else if (leftSize > rightSize) {
		Polynomial rightCopy{ rightSide.poly };
		for (int i{}; i < leftSize; i++) {
			for (int j{}; j < rightSize; j++) {
				if (this->poly.getItem(i) == rightSide.poly.getItem(j)) {
					this->poly.replaceItem((this->poly.getItem(i) += rightSide.poly.getItem(j)), i);
					rightCopy.poly.remove(rightSide.poly.getItem(j));
					combinationsCounter++;
				}
			}
		}

		if (rightCopy.poly.getCurrentSize() > 0) {
			for (int i{}; i < rightCopy.poly.getCurrentSize(); i++) {
				cout << "\nUnable to combine this term --> " << rightCopy.poly.getItem(i)
					<< "\nIt is going to be appended in the end...";
				this->poly.add(rightCopy.poly.getItem(i));
			}
		}
	}
	else {
		Polynomial leftCopy{ this->poly }, rightCopy{ rightSide.poly };
		for (int i{}; i < rightSize; i++) {
			for (int j{}; j < leftSize; j++) {
				if (rightSide.poly.getItem(i) == this->poly.getItem(j)) {
					rightCopy.poly.replaceItem(rightCopy.poly.getItem(i) += this->poly.getItem(j), i);
					leftCopy.poly.remove(this->poly.getItem(j));
					combinationsCounter++;
				}
			}
		}

		this->poly = rightCopy.poly;

		if (leftCopy.poly.getCurrentSize() > 0) {
			for (int i{}; i < leftCopy.poly.getCurrentSize(); i++) {
				cout << "\nUnable to combine this term --> " << leftCopy.poly.getItem(i)
					<< "\nIt is going to be appended in the end...";
				this->poly.add(leftCopy.poly.getItem(i));
			}
		}
	}

	cout << "\n\t- In total, --> " << combinationsCounter << " terms were combined!";
	sortPolynomial();

	return *this;
}

ostream& operator << (ostream& output, const Polynomial& sourcePolynomial) {
	int size{ sourcePolynomial.poly.getCurrentSize() };
	if (size == 1) {
		return output << sourcePolynomial.poly.getItem(0);
	}
	else {
		for (int i{}; i < size; i++) {
			if ((i + 1) != size) {
				output << sourcePolynomial.poly.getItem(i) << " + ";
			}
			else {
				return output << sourcePolynomial.poly.getItem(i);
			}
		}
	}
}

istream& operator >> (istream& input, Polynomial& sourceObj) {
	cout << "\n\t- How many terms do you want for this polynomial? (terms > 0 & < " << sourceObj.poly.getDefaultCapacity() << ") --> ";
	int terms{};
	input >> terms;
	while (input.fail() || terms < 1 || terms > sourceObj.poly.getDefaultCapacity()) {
		if (input.fail()) {
			input.clear();
			input.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nPlease re-enter a valid integer --> ";
			input >> terms;
		}
		else {
			cout << "\nPlease re-enter a valid number of terms for this polynomial --> ";
			input >> terms;
		}
	}

	for (int i{}; i < terms; i++) {
		cout << "\nTerm #" << (i + 1);
		sourceObj.changeCoefficient();
	}
	return input;
}