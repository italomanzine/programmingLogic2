#include "dictionary.hpp"

bool LoadDictionary(string path, vector< string > &wordlist)
{
    ifstream filereader;
    filereader.open(path);

    //checking if file is valid
    if(filereader.is_open() == false)
        return false;
    vector < string > tmpvector;

    //reading file and filling a vector
    string tmp;
    while(getline(filereader, tmp))
    {
        tmpvector.push_back(tmp);
    }

    //remove first element
    tmpvector.erase (tmpvector.begin()+0);
    for(size_t i=0; i<tmpvector.size();i++)
    {
        wordlist.push_back(tmpvector.at(i));
    }

    return true;
}

bool SearchWord(const vector< string > &wordlist, string query)
{
    for(size_t i=0; i< wordlist.size(); i++)
    {
        if(wordlist.at(i) == query)
            return true;
    }
    return false;
}

vector< string > SearchSubstrings(const vector< string > &wordlist, string query)
{
    vector< string > newsublist;

    for(size_t i=0; i< wordlist.size(); i++)
    {
        string word = wordlist.at(i);
        size_t pos = word.find(query);
        if(pos < word.length())
        {
            newsublist.push_back(word);
        }
    }
    return newsublist;
}

