#include "DocumentStore.h"

DocumentStore::DocumentStore (std::size_t s):
    /* YOUR CODE GOES HERE */, size(s), curr(0), currDraft(0)
{}

/* YOUR CODE GOES HERE */

void DocumentStore::addDocument (const Document& doc)
{
  /* YOUR CODE GOES HERE */
}

void DocumentStore::saveAsDraft (const Document& draft)
{
  /* YOUR CODE GOES HERE */
}

void DocumentStore::print () const
{
    std::cout << "List of Documents:" << std::endl;
    for (std::size_t j = 0; j < curr; ++j)
        docs[j].print();

    std::cout << "List of Drafts:" << std::endl;
    for (std::size_t j = 0; j < currDraft; ++j)
        docsDraft[j].print();
}
