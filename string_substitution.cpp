#include "Deque.h"
#include "FStream.h"
#include <string.h>
#include <assert.h>
#include <filesystem>
#include <system_error>
using namespace std;
void CASE_1(FStream &fs, char replacechar, char searchchar);
void CASE_2(FStream &fs, char* replacebuf, char searchchar, const int SIZE);
void CASE_3(FStream &fs, char* replacebuf, char* searchbuf, const int R_SIZE, const int S_SIZE);
int CASE_4(FStream &fs, char replacechar, char* searchbuf, const int SIZE);
int CASE_5(FStream &fs, char* replacebuf, char* searchbuf, const int R_SIZE, const int S_SIZE);

int main(int argc, const char* argv[]) 
{
        char searchchar; char* searchbuf;
        char replacechar; char* replacebuf;
        if(strlen(argv[1])==1)//when searchcar is a single character
                searchchar = argv[1][0];
        else
        {
                memcpy(&searchbuf, &argv[1], sizeof(argv[1]));
        }
        
        if(strlen(argv[2])==1)//when replacechar is a single character
                replacechar = argv[2][0];
        else 
        {
                memcpy(&replacebuf, &argv[2], sizeof(argv[2]));
        }

        const string filename = argv[3];
        FStream fs(filename);
        
        if(strlen(argv[1])==1 && strlen(argv[2])==1)
        /* replace a single searchchar to a single replacechar ex) a -> b */
        {
                CASE_1(fs, replacechar, searchchar);
        }//CASE1

        else if(strlen(argv[1])==1 && strlen(argv[2])>1)
        /* replace a single searchchar to a bigger replacechar string ex) a -> AA */
        {
                const int SIZE = strlen(replacebuf);
                CASE_2(fs, replacebuf, searchchar, SIZE);
        }//CASE2
        
        else if(strlen(argv[1])>1 && strlen(argv[1])<strlen(argv[2]))
        /* replace a smaller seachchar string to a bigger replacechar string ex) aa ->ABC */
        {
                const int R_SIZE = strlen(replacebuf);
                const int S_SIZE = strlen(searchbuf);
                CASE_3(fs, replacebuf, searchbuf, R_SIZE, S_SIZE);
        }//CASE3

        else if(strlen(argv[1])>1 && strlen(argv[2])==1)
        /* replace a bigger seachchar string to a single replacechar ex) aaa -> A */
        {
                //resize_file
                const int SIZE = strlen(searchbuf);
                int bytes = CASE_4(fs, replacechar, searchbuf, SIZE);
                auto p = filesystem::path(filename);
                filesystem::resize_file(p,bytes);
        }//CASE4
        else if(strlen(argv[1])>1 && strlen(argv[1])>strlen(argv[2]))
        /* replace a bigger seachchar string to a smaller replacechar string ex) aaa ->AA */
        {
                //resize_file
                const int R_SIZE = strlen(replacebuf);
                const int S_SIZE = strlen(searchbuf);
                int bytes = CASE_5(fs, replacebuf, searchbuf, R_SIZE, S_SIZE);
                auto p = filesystem::path(filename);
                filesystem::resize_file(p,bytes);
        }//CASE5
        else
        /* replace a seachchar string to a replacechar string ex) aaa ->AAA */
        {
                const int R_SIZE = strlen(replacebuf);
                const int S_SIZE = strlen(searchbuf);
                int bytes = CASE_5(fs, replacebuf, searchbuf, R_SIZE, S_SIZE);
        }//CASE6 (reuse CASE5)


        fs.close();
        return 0;
}
void CASE_1(FStream &fs, char replacechar, char searchchar)
{
        char c;
        int count=0;
        while(!fs.eof())
        {
                assert(count < 6000);
                fs.FStream::seekg(count);
                fs.get(c);
                if(c==searchchar)
                {
                        fs.FStream::seekp(count);
                        fs.put(replacechar);
                }//if
         count++;
        }//while

}//CASE_1

void CASE_2(FStream &fs, char *replacebuf, char searchchar, const int SIZE)
{
        GradingDeque mybuf;
        char c;
        int count=0, i=0;
        bool eof = false;
        while(true)
        {
                assert(count < 6000);
                fs.clear();//clear the EOF flag
                fs.FStream::seekg(count);
                fs.get(c);
                if(fs.eof() || eof==true)
                {
                        if(eof==true && mybuf.GradingDeque::size()<1) break;
                        if(mybuf.GradingDeque::size()>0)
                        {
                                c = mybuf.back();
                                mybuf.pop_back();
                        }
                        eof=true;
                }
                if(c==searchchar && mybuf.GradingDeque::size()<1 && i==0 && eof==false)
                {
                        // first match
                        fs.FStream::seekp(count);
                        fs.put(replacebuf[i]);
                        i++; if(i>SIZE-1){i=0;}
                }else if(c==searchchar && i>0)
                {
                        // Another match found while replacement in process
                        if(eof==true) fs.clear();
                        if(eof==false)
                                mybuf.GradingDeque::push_front(c);
                        fs.FStream::seekp(count);
                        fs.put(replacebuf[i]);
                        i++; if(i>SIZE-1){i=0;}
                }else if(c!=searchchar && i>0)
                {
                        // replacement in process
                        if(eof==false)
                                mybuf.GradingDeque::push_front(c);
                        if(eof==true) fs.clear();
                        fs.FStream::seekp(count);
                        fs.put(replacebuf[i]);
                        i++; if(i>SIZE-1){i=0;}
                 }
                 else 
                 {
                         if(eof==false && mybuf.GradingDeque::size()>0)
                         {
                                mybuf.GradingDeque::push_front(c);
                                if(i==0)
                                {
                                        c = mybuf.back();
                                        mybuf.pop_back();
                                }//if
                         }//if
                         if(c==searchchar)
                         {
                                if(eof==false) 
                                {
                                        fs.clear();
                                        fs.FStream::seekp(count);
                                        fs.put(replacebuf[i]);
                                        i++; if(i>SIZE-1){i=0;}
                                }
                                else
                                {
                                        //iterating through  mybuf
                                        fs.clear();
                                        for(int k=0; k<SIZE; k++)
                                        {
                                                fs.FStream::seekp(count);
                                                fs.put(replacebuf[k]);
                                                count++;
                                        }//for
                                        continue; //prevents extra count++
                                }//if
                         }
                         else 
                         {
                                if(i==0)
                                {
                                        if(eof==true) fs.clear();
                                        fs.FStream::seekp(count);
                                        fs.put(c);
                                }
                                else
                                {
                                        if(eof==true) fs.clear();
                                        fs.FStream::seekp(count);
                                        fs.put(replacebuf[i]);
                                        i++; if(i>SIZE-1){i=0;}
                                }
                         }//if

                 }//if
                  count++;
        }//while
}//CASE_2

void CASE_3(FStream &fs, char* replacebuf, char* searchbuf, const int R_SIZE, const int S_SIZE)
{
        GradingDeque mybuf;
        char c;
        bool eof = false, inbuf=false;
        int count=0, p_count=0, i=0, mybuf_size=100;
        while(true)
        {
                fs.clear();//clear the EOF flag
                fs.FStream::seekg(count);
                fs.get(c);
                if(fs.eof())
                {
                        eof = true;
                        if(mybuf.GradingDeque::size() > 0 && i==0)
                        {
                                inbuf=true;
                                c=mybuf.back();
                                mybuf.pop_back();
                                mybuf_size = mybuf.GradingDeque::size();
                        }
                        else if(i<1 && mybuf.GradingDeque::size()<1)
                        {
                                break;
                        }
                }//if
                if(c==searchbuf[0] && i==0 && mybuf.GradingDeque::size()<1)
                {
                        bool flag=false;
                        for(int i=1; i<S_SIZE; i++)
                        {
                                // potential match checking
                                if(eof==true)
                                        fs.clear();//clear the EOF flag
                                count++;
                                fs.FStream::seekg(count);
                                fs.get(c);
                                if(c==!searchbuf[i])
                                {
                                        flag=false;
                                        break;
                                }
                                else
                                {
                                        flag=true;
                                }
                        }//for
                        if(flag==true)
                        {
                                //replacement in process
                                for(i=0; i<S_SIZE; i++)
                                {
                                        if(eof==true)fs.clear();
                                        fs.FStream::seekp(p_count);
                                        fs.put(replacebuf[i]);
                                        p_count++;
                                }//for
                        }//if
                }
                else if(c==searchbuf[0] && i==0 && mybuf.GradingDeque::size()>0)
                {
                        //check a potential match inside of mybuf
                        char tc;
                        if(eof==false) tc = mybuf.back();
                        if(eof==true)  tc = c;
                        if(tc==searchbuf[0])
                        {
                                string match;
                                match+=tc;
                                if(inbuf==true) mybuf.GradingDeque::push_back(tc);
                                const int j=mybuf.GradingDeque::size()-1;
                                if(j>S_SIZE-1)
                                {
                                        for(int p=1;p<S_SIZE; p++)
                                        {
                                                match+=mybuf[j-p];
                                        }//for
                               
                                        string ts(searchbuf);
                                        if(match==ts)//found a match inside of mybuf
                                        {
                                                for(int p=0;p<S_SIZE; p++)
                                                {
                                                        mybuf.pop_back();
                                                }
                                                //replacement starts
                                                if(eof==true)fs.clear();
                                                fs.FStream::seekp(p_count);
                                                fs.put(replacebuf[i]);
                                                i++; if(i==R_SIZE){i=0;}
                                                p_count++;
                                                if(eof==false || inbuf ==false)
                                                        mybuf.GradingDeque::push_front(c);
                                        }
                                        else
                                        {
                                                // match failed
                                                if(eof==false || inbuf ==false)
                                                        mybuf.GradingDeque::push_front(c);
                                                else
                                                {
                                                        fs.clear();
                                                        fs.FStream::seekp(p_count);
                                                        fs.put(tc);
                                                        mybuf.pop_back();
                                                        p_count++;
                                                }
                                        }//inner if
                                }//outer if
                        }
                        else
                        {
                                if(eof==false)
                                        mybuf.GradingDeque::push_front(c);
                                if(eof==true) fs.clear();
                                fs.FStream::seekp(p_count);
                                fs.put(tc);
                                mybuf.pop_back();        
                                p_count++;
                        }//outer if
                }
                else if (c!=searchbuf[0] && i>0)
                {
                        //replacement in process
                        if(eof==false)
                                mybuf.GradingDeque::push_front(c);
                        if(eof==true) fs.clear();
                        fs.FStream::seekp(p_count);
                        fs.put(replacebuf[i]);
                        i++; if(i==R_SIZE){i=0;}
                        p_count++;
                       
                }//if
                else if (c==searchbuf[0] && i>0)
                {
                        //another match found during replacement process
                        //push to my buf
                        if(eof==true) fs.clear();
                        if(eof==false) mybuf.GradingDeque::push_front(c);
                        fs.FStream::seekp(p_count);
                        fs.put(replacebuf[i]);
                        i++; if(i==R_SIZE){i=0;}
                        p_count++;
                }
                else if(c!=searchbuf[0] && i==0 && mybuf.GradingDeque::size()>0)
                {
                        //check a potential match inside of mybuf
                        char tc;
                        if(eof==false) tc = mybuf.back();
                        if(eof==true) tc = c;
                        if(inbuf==true) mybuf.GradingDeque::push_back(tc);
                        if(tc==searchbuf[0])
                        {
                                string match;
                                match+=tc;
                                const int j=mybuf.GradingDeque::size()-1;
                                if(j>S_SIZE-1)
                                {
                                        for(int p=1;p<S_SIZE; p++)
                                        {
                                                match+=mybuf[j-p];
                                        }//for

                                        string ts(searchbuf);
                                        if(match==ts)//found a match inside of mybuf
                                        {
                                                for(int p=0;p<S_SIZE; p++)
                                                {
                                                        mybuf.pop_back();
                                                }//for
                                                //replacement starts
                                                if(eof==true)fs.clear();
                                                fs.FStream::seekp(p_count);
                                                fs.put(replacebuf[i]);
                                                i++; if(i==R_SIZE){i=0;}
                                                p_count++;
                                        
                                                if(eof==false || inbuf ==false)
                                                        mybuf.GradingDeque::push_front(c);
                                        }
                                        else
                                        {
                                                if(eof==false || inbuf ==false)
                                                        mybuf.GradingDeque::push_front(c);
                                                if(eof==true) fs.clear();
                                                fs.FStream::seekp(p_count);
                                                fs.put(tc);
                                                mybuf.pop_back();
                                                p_count++;
                                        }
                                }//inner if
                        }
                        else
                        {
                                if(eof==false)
                                        mybuf.GradingDeque::push_front(c);
                                if(eof==true) fs.clear();
                                fs.FStream::seekp(p_count);
                                fs.put(tc);
                                mybuf.pop_back();
                                p_count++;
                        }//outer if

                }
                else if(c!=searchbuf[0] && i==0) 
                {
                        //copy-paste from mybuf to fs
                        if(mybuf_size==0)
                        {
                                //last character
                                fs.clear();//clear the EOF flag
                                fs.FStream::seekp(p_count);
                                fs.put(c);
                                break;
                        }
                        else
                        {
                                if(eof==false)
                                        mybuf.GradingDeque::push_front(c);
                                if(eof==true) fs.clear();
                                fs.FStream::seekp(p_count);
                                fs.put(mybuf.back());
                                mybuf.pop_back();
                                p_count++;
                        }
                }
                else
                {
                        p_count++;
                }
                count++;
        }//while

}//CASE_3

int CASE_4(FStream &fs, char replacechar, char* searchbuf, const int SIZE)
{
        int count=0, p_count=0, file_size;
        char c;
        while(true)
        {
                assert(count < 6000 && p_count < 6000);
                fs.FStream::seekg(count);
                fs.get(c);
                if(fs.eof())
                {
                        file_size = p_count;
                        break;
                }

                if(c==searchbuf[0])
                {
                        bool flag=false;
                        for(int peek_i=1; peek_i < SIZE; peek_i++)
                        {
                                // potential match checking
                                count++;
                                fs.FStream::seekg(count);
                                fs.get(c);
                                if(c != searchbuf[peek_i])
                                {
                                        flag=false;
                                        break;
                                }
                                else
                                {
                                        flag=true;
                                }
                         }//for
                         count++;
                         if(flag==true)
                         {
                                 //replacement in process
                                 fs.FStream::seekp(p_count);
                                 fs.put(replacechar);
                                 p_count++;
                         }//if
                }
                else
                {
                        if(p_count!=count)
                        {
                                fs.FStream::seekp(p_count);
                                fs.put(c);
                        }
                        count++;
                        p_count++;
                }//if
        }//while
        return file_size;
}//CASE_4

int CASE_5(FStream &fs, char* replacebuf, char* searchbuf, const int R_SIZE, const int S_SIZE)
{
        int count=0;
        char c;
        if(R_SIZE==S_SIZE)
        {
                assert(count < 6000);
                while(!fs.eof())
                {
                        fs.FStream::seekg(count);
                        fs.get(c);
                        if(c==searchbuf[0])
                        {
                                bool flag=false;
                                int p_count = count;
                                for(int peek_i=1; peek_i < S_SIZE; peek_i++)
                                {
                                        // potential match checking
                                        count++;
                                        fs.FStream::seekg(count);
                                        fs.get(c);
                                        if(c != searchbuf[peek_i])
                                        {
                                                flag=false;
                                                break;
                                        }
                                        else 
                                        {
                                                flag=true;
                                        }
                                }//for
                                if(flag==true)
                                {
                                        // replacement in process
                                        int j=0;
                                        while(p_count<=count)
                                        {
                                                fs.FStream::seekp(p_count);
                                                fs.put(replacebuf[j]);
                                                j++;
                                                p_count++;
                                        }//while
                                }//if
                        }//if
                        count++;
                }
                return count;
        }
        else //CASE aaa ->AA
        {
                int count=0, p_count=0, file_size;
                char c;
                while(true)
                {
                        assert(count < 6000 && p_count < 6000);
                        fs.FStream::seekg(count);
                        fs.get(c);
                        if(fs.eof())
                        {
                                file_size = p_count;
                                break;
                        }//if
                        if(c==searchbuf[0])
                        {
                                int t_count=count;
                                bool flag=false;
                                char tc;
                                for(int peek_i=1; peek_i < S_SIZE; peek_i++)
                                {
                                        // potential match checking
                                        t_count++;
                                        fs.get(tc);
                                        if(tc != searchbuf[peek_i])
                                        {
                                                flag=false;
                                                break;
                                        }
                                        else
                                        {
                                                flag=true;
                                        }
                                }//for
                                count++;
                                if(flag==true)
                                {
                                        //replacement in process
                                        for(int i=0; i<R_SIZE; i++)
                                        {
                                                fs.FStream::seekp(p_count);
                                                fs.put(replacebuf[i]);
                                                p_count++;
                                        }//for
                                        count = t_count+1;
                                }
                                else 
                                {
                                        fs.FStream::seekp(p_count);
                                        fs.put(c);
                                        p_count++;
                                }
                        }
                        else
                        {
                                fs.FStream::seekp(p_count);
                                fs.put(c);
                                p_count++;
                                count++;
                        }//if

                }//while
                return file_size;
        }//if

}//CASE_5
