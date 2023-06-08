#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H
#include "media.h"
#include <vector>

class Search_engine {
        public:
                Search_engine();
                ~Search_engine();
                vector<Media*> subject_search(const string &s);
                vector<Media*> cn_search(const string &s);
                vector<Media*> title_search(const string &s);
                vector<Media*> other_search(const string &s);
        private:
                vector<Media*> card_catalog;
};

#endif
