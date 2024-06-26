#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>

int skip(const std::string& s1)
{
    if (s1.length()==0) return 1;
#ifdef IGNORE_DEFAULT_WEIGHT
    if (s1=="W Default") return 1;
#endif
    if (s1.find("HepMC::Version")!=std::string::npos) return 1;
    return 0;
}
int COMPARE_ASCII_FILES(const std::string& f1,const std::string& f2)
{
    std::fstream file1(f1.c_str()), file2(f2.c_str());
    std::string string1, string2;
    int j1,j2;
    j1 = 0;
    j2 = 0;
    std::cout << "Run comparison" << "\n";
    while((!file1.eof()) && (!file2.eof()))
    {
        for (;;) {
            j1++;
            if (!std::getline(file1,string1)) break;
            if (skip(string1)==0) break;
        }
        for (;;) {
            j2++;
            if (!std::getline(file2,string2)) break;
            if (skip(string2)==0) break;
        }

        if(string1.compare(string2) != 0)
        {
            std::cout << j1 << "/" << j2 << "-th strings are not equal " << f1 << " " << f2 << "\n";
            std::cout << "   ->" << string1 << "<-\n";
            std::cout << "   ->" << string2 << "<-\n";
            return 1;
        }
    }
    return 0;
}

int COMPARE_ASCII_STREAMS(std::stringstream& file1,std::stringstream& file2)
{
    std::string string1, string2;
    int j1,j2;
    j1 = 0;
    j2 = 0;
    std::cout << "Run comparison" << "\n";
    while( file1.rdbuf()->in_avail() != 0 || file2.rdbuf()->in_avail() != 0)
    {
        for (;;) {
            j1++;
            if (!std::getline(file1,string1)) break;
            if (skip(string1)==0) break;
        }
        for (;;) {
            j2++;
            if (!std::getline(file2,string2)) break;
            if (skip(string2)==0) break;
        }

        if(string1.compare(string2) != 0)
        {
            std::cout << j1 << "/" << j2 << "-th strings are not equal \n";
            std::cout << "   ->" << string1 << "<-\n";
            std::cout << "   ->" << string2 << "<-\n";
            return 1;
        }
    }
    return 0;
}

