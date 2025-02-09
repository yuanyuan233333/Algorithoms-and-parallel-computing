#ifndef DOCUMENTSTORE_H
#define DOCUMENTSTORE_H

#include <vector>

#include "Document.h"

const unsigned DRAFT_SIZE = 10;

class DocumentStore {

private:
    std::vector<Document> docs;
    std::vector<Document> docsDraft;
    std::size_t size;
    std::size_t curr;
    std::size_t currDraft;

public:
    explicit DocumentStore (std::size_t);

    DocumentStore(const DocumentStore & rhs); // copy-constructor
    DocumentStore& operator=(const DocumentStore& rhs); // copy-assignment operator

    void addDocument (const Document&);
    void saveAsDraft (const Document&);
    void print () const;
};

#endif /* DOCUMENTSTORE_H */