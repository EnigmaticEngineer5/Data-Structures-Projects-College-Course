#include "BookList.h"

BookList::BookList() : top{}
{
    std::cout << "\nDefault constructor invoked...";
    for (auto& it : books)
    {
        it = "";
    }
}

BookList::BookList(const std::string sourceBooks[], const int sourceDimension) : top{ sourceDimension }
{
    std::cout << "\nParametrized constructor invoked...";
    for (size_t i{}; i < sourceDimension; i++)
    {
        books[i] = sourceBooks[i];
    }
}

BookList::BookList(const BookList& sourceBookList) : top{ sourceBookList.top }
{
    std::cout << "\nCopy constructor invoked...";
    for (size_t i{}; i < top; i++)
    {
        books[i] = sourceBookList.books[i];
    }
}

const bool BookList::isEmpty() const
{
    int counter{};
    for (const auto& it : books)
    {
        if (it.empty())
        {
            counter++;
        }
    }

    if (counter == top)
    {
        true;
    }
    else
    {
        false;
    }
}

const bool BookList::isFull() const
{
    int counter{};
    for (const auto& it : books)
    {
        if (!it.empty())
        {
            counter++;
        }
    }

    if (counter == top)
    {
        true;
    }
    else
    {
        false;
    }
}

const int BookList::getCurrentSize() const
{
    return top;
}

const bool BookList::addBook(const std::string)
{
    return false;
}

const int BookList::containsBook(const std::string sourceTitle) const
{
    int left{}, right{ (top - 1) };

    while (left <= right)
    {
        int middle{ ((left + right) / 2) };

        if (books[middle].compare(sourceTitle) == 0)
        {
            return middle;
        }
        else if (books[middle].compare(sourceTitle) < 0)
        {
            right = (middle - 1);
        }
        else
        {
            left = (middle + 1);
        }
    }

    return -1;
}

void BookList::removeBook(const std::string sourceName)
{

}

void BookList::displayBooks() const
{
}

std::string& BookList::operator[](const int&)
{
    // TODO: insert return statement here
}

BookList::~BookList()
{
}

std::istream& operator>>(std::istream&, BookList&)
{
    // TODO: insert return statement here
}

std::ostream& operator<<(std::ostream&, const BookList&)
{
    // TODO: insert return statement here
}
