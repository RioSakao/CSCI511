#include "stampbuf.h"
#include "stamp.h"

static int stamp_col=0;
static int stamp_row=0;

row::row(int r)
        :new_row(r)
{
}


stampbuf::stampbuf(int c, int r)
        :col(c), row(r)
{
        streambuf::setp(buf, buf+1023);
        try{
                stamping_press::insert_plate(col,row);
        }catch(...){
        }
}

stampbuf::~stampbuf()
{
        try{
                int ret = sync();
                stamping_press::eject_plate();
        }catch(...){
        }
}

int stampbuf::overflow(int c)
{
        *pptr()=(char)c;
        pbump(1);
        try{
                int ret = sync();
        }catch(...){
                throw;
        }

        return c;
}

int stampbuf::get_col() const { return col; }
int stampbuf::get_row() const{ return row; }

int stampbuf::sync()
{
        //cerr << "sync() executing..." << endl;
        int COL = get_col();
        int ROW = get_row();
        try{
                for(auto it=streambuf::pbase(); it<streambuf::pptr(); it++){
                        //if (stamp_row == ROW) break;
                        if(stamp_col < COL) {
                                /**if(*it == '\n'){
                                        stamp_col = 0;
                                        stamp_row++;
                                        continue;
                                } else if( *it == ' ') {
                                        stamp_col++;
                                        continue;
                                } else {
                                **/
                                        char c = stamping_press::get_die();
                                        if(c != *it || c == '0')
                                                stamping_press::set_die(*it);
                                        stamping_press::stamp(stamp_col, stamp_row);
                                        stamp_col++;
                                }//if
                        /**} else {

                                if(*it == '\n')
                                        stamp_row++;
                                        stamp_col = 0;
                        }//if**/
                }//for
        }catch(...){
                throw;
        }

        //reset our internal pointers
        streambuf::setp(streambuf::pbase(), streambuf::epptr());
        return 0;
}

/**
void stampbuf::set_newline()
{
        auto it = buf.end();
        *it = '\n';
}
**/
ostream& endrow(ostream& os)
{
        stamp_col = 0;
        //set_newline();
        return os;
}


// gets row number to execute stamp()
ostream& operator<<(ostream& os, const row& r)
{
        stamp_row = r.new_row;

        return os;
}
