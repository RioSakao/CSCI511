#include "stampstream.h"
#include "stampbuf.h"

stampstream::stampstream(int c, int r)
        :std::ostream(new stampbuf(c, r))
{
}

stampstream::~stampstream()
{
        /** think it as book : public Media **/

        streambuf* sbp;
        //I can call streambuf's rdbuf() function because stampbuf *is* a streambuf
        sbp=rdbuf();
        //now sbp holds the address of the stampbuf so we can release it
        delete sbp;
}

