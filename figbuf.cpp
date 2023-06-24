#include <iostream>
#include <fstream>
#include <cstdio> 
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

class figbuf : public streambuf 
{
        public:
                int overflow(int c);
                figbuf();
                ~figbuf();
                int sync();
        private:
                char buf[10];
                FILE* figlet_pipe;
};

figbuf::figbuf()
{
        streambuf::setp(buf, buf+9);
        figlet_pipe = popen("figlet -W -w 1000 -f standard", "w");
}

figbuf::~figbuf()
{
        // 1. synchronize the buffer then.
        int ret = sync();
        pclose(figlet_pipe);
}

/**Returns zero, which indicates success.
A value of -1 would indicate failure.**/
int figbuf::sync()
{
        for(auto it=streambuf::pbase(); it<streambuf::pptr(); it++)
            fputc(*it, figlet_pipe);
        //reset our internal pointers
        streambuf::setp(streambuf::pbase(), streambuf::epptr());
        return 0;
}

int figbuf::overflow(int c)
{
        //string the_figlet_string = "figlet a";
        //system(the_figlet_string.c_str());
        
        *pptr()=(char)c;
        pbump(1);
        int ret = sync();

        return c;
}

int main()
{
        //It is fine to create a figbuf object as a local variable.  It ensures the
        //destructor will run when main() ends.
        figbuf fb;
        //Change cout's stream buffer to fb
        //and save the address of cout's normal stream buffer
        streambuf* couts_original_streambuf=cout.rdbuf(&fb);

        cout << "sin(3.14/4)=" << sin(3.141592/4) << ". Irrational!\n";
        cout << "One\nword\nper\nline\nends with endl"<< endl;
        cout << "This line concludes the demonstration.";

        //Restore the original streambuf to cout
        cout.rdbuf(couts_original_streambuf);

        return 0;



        /**
        figbuf fig_ptr;
        streambuf  *backup;
        backup = cout.rdbuf();
        cout.rdbuf(&fig_ptr);

        string input;
        getline(cin,input);
        cout << input << endl;

        //Restore cout’s stream buffer 
        cout.rdbuf(backup);

        return 0;
        **/
}
