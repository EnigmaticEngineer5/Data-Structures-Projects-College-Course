#include "BookInfo.h"

BookInfo::BookInfo() : title{}, author{}, publisher{} {};
BookInfo::BookInfo(const string sourceTitle, const string sourceAuthor, const string sourcePublisher) 
	: title{ sourceTitle }, author{ sourceAuthor }, publisher{ sourcePublisher } {};

BookInfo::BookInfo(const BookInfo& sourceBook) :
	title{ sourceBook.getTitle() },
	author{ sourceBook.getAuthor() },
	publisher{ sourceBook.getPublisher()} {};

BookInfo::~BookInfo() { cout << "\n\tObject released..."; };

BookInfo& BookInfo::setTitle(const string sourceTitle)
{
	this->title = sourceTitle;
	return *this;
}

BookInfo& BookInfo::setAuthor(const string sourceAuthor)
{
	this->author = sourceAuthor;
	return *this;
}

BookInfo& BookInfo::setPublisher(const string sourcePublisher)
{
	this->publisher = sourcePublisher;
	return *this;
}

void BookInfo::setBookInfo(const string sourceTitle, const string sourceAuthor, const string sourcePublisher)
{
	this->setTitle(sourceTitle).setAuthor(sourceAuthor).setPublisher(sourcePublisher);
}

const string BookInfo::getTitle() const
{
	return (this->title);
}

const string BookInfo::getAuthor() const
{
	return (this->author);
}

const string BookInfo::getPublisher() const
{
	return (this->publisher);
}

const bool BookInfo::operator==(const BookInfo& sourceBookInfo)
{
	return (this->title.compare(sourceBookInfo.getTitle()) == 0);
}

istream& operator >> (istream& input, BookInfo& sourceBook)
{
	cout << "\n\t- Enter the BOOK TITLE --> ";
	getline(input >> ws, sourceBook.title);

	cout << "\t- Enter the BOOK AUTHOR --> ";
	getline(input >> ws, sourceBook.author);

	cout << "\t- Enter the BOOK PUBLISHER --> ";
	getline(input >> ws, sourceBook.publisher);

	return input;
}

ostream& operator << (ostream& output, const BookInfo& sourceBook)
{
	output << "\n\t- The BOOK TITLE is --> " << sourceBook.getTitle()
		<< "\n\t- The BOOK AUTHOR is --> " << sourceBook.getAuthor()
		<< "\n\t- The BOOK PUBLISHER is --> " << sourceBook.getPublisher();

	return output;
}