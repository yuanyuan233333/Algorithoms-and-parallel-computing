#ifndef DOCUMENTSTORE_H
#define DOCUMENTSTORE_H

#include <vector>

#include "Document.h"

const unsigned DRAFT_SIZE = 10;

class DocumentStore {

private:
    /* YOUR CODE GOES HERE */ docs;
    /* YOUR CODE GOES HERE */ docsDraft;
    std::size_t size;
    std::size_t curr;
    std::size_t currDraft;

public:
    explicit DocumentStore (std::size_t);

    /* YOUR CODE GOES HERE */

    void addDocument (const Document&);
    void saveAsDraft (const Document&);
    void print () const;
};

#endif /* DOCUMENTSTORE_H */