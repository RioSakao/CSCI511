#include "search_engine.h"
#include "book.h"
#include "periodical.h"
#include "video.h"
#include "film.h"
#include "media.h"
#include <iostream>
#include <fstream>
#include <sstream>

/**free memory of vector<*Media> card_catalog**/
Search_engine::~Search_engine(){
        for(auto it=card_catalog.begin(); it!=card_catalog.end(); it++){
                delete *it;
        }//for
}

vector<Media*> Search_engine::subject_search(const string &s){
        vector<Media*> matches;
        for(auto it=card_catalog.begin(); it!=card_catalog.end(); it++){
                if((*it)->compare_subjects(s) == true)
                        matches.push_back(*it);
        }
        return matches;
}

vector<Media*> Search_engine::title_search(const string &s){
        vector<Media*> matches;
        for(auto it=card_catalog.begin(); it!=card_catalog.end(); it++){
                if((*it)->compare_title(s) == true)
                        matches.push_back(*it);
        }
        return matches;
}

vector<Media*> Search_engine::other_search(const string &s){
        vector<Media*> matches;
        for(auto it=card_catalog.begin(); it!=card_catalog.end(); it++){
                if((*it)->compare_other(s) == true)
                        matches.push_back(*it);
        }
        return matches;
}

vector<Media*> Search_engine::cn_search(const string &s){
        vector<Media*> matches;
        for(auto it=card_catalog.begin(); it!=card_catalog.end(); it++){
                if((*it)->compare_cn(s) == true)
                        matches.push_back(*it);
        }
        return matches;
}

/**construct card_catalog**/
Search_engine::Search_engine(){
        
        string line;
        string token, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12;

        ifstream btxt;
        btxt.open("book.txt");
        if (!btxt) {
            cerr << "Issue opeing book.txt" << endl;
        }
        while ( getline(btxt, line) ) {
                int count = 0;
                istringstream iss(line);
                while(getline(iss, token, '|')) {
                        count++;
                        switch(count) {
                                case 1:
                                        arg1 = token;
                                        break;
                                case 2:
                                        arg2 = token;
                                        break;
                                case 3:
                                        arg3 = token;
                                        break;
                                case 4:
                                        arg4 = token;
                                        break;
                                case 5:
                                        arg5 = token;
                                        break;
                                case 6:
                                        arg6 = token;
                                        break;
                                case 7:
                                        arg7 = token;
                                        break;
                                case 8:
                                        arg8 = token;
                                        break;
                                case 9:
                                        arg9 = token;
                                        break;
                                case 10:
                                        arg10 = token;
                                        break;
                        }//switch
                }//in-while
                Book *bp = new Book(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);
                card_catalog.push_back(bp);
        }//out-while
        btxt.close();
        

        ifstream ftxt;
        ftxt.open("film.txt");
        if (!ftxt) {
            cerr << "Issue opeing film.txt" << endl;
        }
        while ( getline(ftxt, line) ) {
                int count = 0;
                istringstream iss(line);
                while(getline(iss, token, '|')) {
                        count++;
                        switch(count) {
                                case 1:
                                        arg1 = token;
                                        break;
                                case 2:
                                        arg2 = token;
                                        break;
                                case 3:
                                        arg3 = token;
                                        break;
                                case 4:
                                        arg4 = token;
                                case 5:
                                        arg5 = token;
                                        break;
                                case 6:
                                        arg6 = token;
                                        break;
                        }//switch
                }//in-while
                Film *fp = new Film(arg1,arg2,arg3,arg4,arg5,arg6);
                card_catalog.push_back(fp);
        }//out-while
        ftxt.close();
        

        ifstream vtxt;
        vtxt.open("video.txt");
        if (!vtxt) {
            cerr << "Issue opeing video.txt" << endl;
        }
        while ( getline(vtxt, line) ) {
                int count = 0;
                istringstream iss(line);
                while(getline(iss, token, '|')) {
                        count++;
                        switch(count) {
                                case 1:
                                        arg1 = token;
                                        break;
                                case 2:
                                        arg2 = token;
                                        break;
                                case 3:
                                        arg3 = token;
                                        break;
                                case 4:
                                        arg4 = token;
                                case 5:
                                        arg5 = token;
                                        break;
                                case 6:
                                        arg6 = token;
                                        break;
                                case 7:
                                        arg7 = token;
                                        break;
                                case 8:
                                        arg8 = token;
                                        break;

                        }//switch
                }//in-while
                Video *vp = new Video(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);
                card_catalog.push_back(vp);
        }//out-while
        vtxt.close();

        
        ifstream ptxt;
        ptxt.open("periodic.txt");
        if (!ptxt) {
            cerr << "Issue opeing periodic.txt" << endl;
        }
        while ( getline(ptxt, line) ) {
                int count = 0;
                istringstream iss(line);
                while(getline(iss, token, '|')) {
                        count++;
                        switch(count) {
                                case 1:
                                        arg1 = token;
                                        break;
                                case 2:
                                        arg2 = token;
                                        break;
                                case 3:
                                        arg3 = token;
                                        break;
                                case 4:
                                        arg4 = token;
                                        break;
                                case 5:
                                        arg5 = token;
                                        break;
                                case 6:
                                        arg6 = token;
                                        break;
                                case 7:
                                        arg7 = token;
                                        break;
                                case 8:
                                        arg8 = token;
                                        break;
                                case 9:
                                        arg9 = token;
                                        break;
                                case 10:
                                        arg10 = token;
                                        break;
                                case 11:
                                        arg11 = token;
                                        break;
                                case 12:
                                        arg12 = token;
                                        break;
                        }//switch
                }//in-while
                Periodical *pp = new Periodical(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12);
                card_catalog.push_back(pp);
        }//out-while
        ptxt.close();




}

