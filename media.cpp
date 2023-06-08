#include "media.h"

Media::Media(const string &cn, const string &t, const string &sub, const string &n)
        :call_number(cn), title(t), subjects(sub), notes(n)
{
}
bool Media::compare_subjects(const string &s) const{
        int found = s.find(subjects);
        if(found != string::npos)
                return true;
        return false;
}
bool Media::compare_title(const string &s) const{
        int found = s.find(title);
        if(found != string::npos)
                return true;
        return false;
}
bool Media::compare_cn(const string &s) const{
        int found = s.find(call_number);
        if(found != string::npos)        
                return true;
        return false;
}
