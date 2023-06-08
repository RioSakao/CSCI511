#include "search_engine.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
        
        Search_engine cards; //construct <vector>card_catalog
        
        string input, key;
        vector<Media*> matches;
        while(true) {
            cout << "1) call_number" << endl;
            cout << "2) title" << endl;
            cout << "3) subject" << endl;
            cout << "4) other" << endl;
            cout << "5) exit" << endl;
            cout << "Enter an option number:  ";
            cin >> input;
            if(input =="5")
                    return 0;
            cout << "Enter keyphrase:  ";
            cin >> key;
            cout << endl;

            if(input == "1") {
                    matches = cards.cn_search(key);
            }else if(input == "2") {
                    matches = cards.title_search(key);
            }else if(input == "3") {
                    matches = cards.subject_search(key);
            }else if(input == "4") {
                    matches = cards.other_search(key);
            }//if
            
            for(int i=0; i<matches.size(); i++) {
                    Media *mp = matches.at(i);
                    mp->display();
            }//for
            
        }//while

        return 0;
}
