#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;

bool mysorterfunction(const pair< size_t, size_t > &p1, const pair< size_t, size_t > &p2)
{
    return (p1.second > p2.second);
}

int main()
{
    vector<size_t> alfabeto = {65, 130, 134, 144, 138, 148, 147, 143, 149, 142, 133, 132, 141, 150, 136, 145, 77, 135, 137, 151, 79, 140, 146, 100, 155, 76, 98, 131, 66, 110};
    cout << "enter with an alphabet to read: ";
    string pathAlpha;
    cin >> pathAlpha;

    //reading an alphabet file
    ifstream frAlpha(pathAlpha);
    vector< char > alphabetList;
    if(!frAlpha.is_open())
    {
        cout << "Error, alphabet file not found" << endl;
        return 1;
    }
    else
    {
        string tmp;
        while(getline(frAlpha, tmp))
        {
            alphabetList.push_back(tmp.at(0));
        }
    }

    //reading a manuscript file
    cout << "enter with a manuscript to encode: ";
    string pathManusc;
    cin >> pathManusc;

    ifstream frManusc(pathManusc);
    stringstream manuscriptStr;
    if(!frManusc.is_open())
    {
        cout << "Error, manuscript file not found" << endl;
        return 2;
    }
    else
    {
        char ch;
        while(frManusc.get(ch))
        {
            manuscriptStr << ch;
        }
    }
    cout << manuscriptStr.str() << endl;

    //computing the characters frequency of the manuscript
    //initialize
    vector < pair< size_t, size_t > > frequencyList;
    for(size_t i=0; i<256; i++)
    {
        pair< size_t, size_t > p;
        p.first = i;
        p.second = 0;
        frequencyList.push_back(p);
    }
    for(size_t i=0; i<manuscriptStr.str().size(); i++)
    {
        char ch = manuscriptStr.str().at(i);
        frequencyList.at(ch).second++;
    }

    //sort and remove elements with zero frequency
    stable_sort(frequencyList.begin(), frequencyList.end(), mysorterfunction);
    for(size_t i=0; i<frequencyList.size(); i++)
    {
        if(frequencyList.at(i).second == 0)
        {
            frequencyList.erase(frequencyList.begin()+i, frequencyList.end());
        }
    }

    if(alphabetList.size() < frequencyList.size())
    {
        cout << "Error, alphabet with insufficient characters to encode  the manuscript" << endl;
        return 3;
    }

    //connecting alphabet and frequency list
    for(size_t i=0; i<frequencyList.size(); i++)
    {
        frequencyList.at(i).second = alphabetList.at(i);
    }

    for(size_t i=0; i<alfabeto.size(); i++)
    {
        cout << alfabeto.at(i) << endl;
        frequencyList.at(i).second = alfabeto.at(i)-33;
    }

    for(size_t i=0; i<frequencyList.size(); i++)
    {
        cout << frequencyList.at(i).first << " " << (char) frequencyList.at(i).second << endl;
    }

    //convert manuscript to codes
    for(size_t i=0; i<manuscriptStr.str().size(); i++)
    {
        char ch = manuscriptStr.str().at(i);
        for(size_t j=0; j<frequencyList.size(); j++)
        {
            if(ch == frequencyList.at(j).first)
            {
                cout << (char) frequencyList.at(j).second;
                break;
            }
        }
    }

    cout << endl;


    return 0;
}
