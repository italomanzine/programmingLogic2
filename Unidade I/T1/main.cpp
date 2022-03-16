#include "dictionary.hpp"
#define NDBUG 1 // 1- Dev;   // 0- Res;
using namespace std;
int main()
{
    vector < vector < string > > ListOfDicts;
    vector < string > ListOfDictsName;
    vector< string > wordlist;
    string query;
    size_t contador=0;
    size_t contador1=0;
    size_t contador2=0;
    size_t x=0;
    size_t sub=0;
    size_t pos=0;
    size_t k=0;
    int acabar =0;

    while(acabar!=1)
    {
         if(NDBUG)cout << "DICTIONARY MANIPULATOR HACK" << endl;
         if(NDBUG)cout << "Select an option:" << endl;
         if(NDBUG)cout << "1. Open Dictionary…" << endl;
         if(NDBUG)cout << "2. Search Substrings..." << endl;
         if(NDBUG)cout << "3. Remove Words Containing Substring..." << endl;
         if(NDBUG)cout << "4. Show Statistics" << endl;
         if(NDBUG)cout << "5. Exit" << endl;
         if(NDBUG)cout << "Option: " ;

     char ch;
     cin >> ch;

      if(ch == '1')
       {
           if (NDBUG) cout << "Enter a dictionary file:"  << endl;
           string path;
           cin >> path;


           if(!LoadDictionary(path,wordlist))
           {
               if (NDBUG) cout << "Error, file not found!" << endl;
           }
           else
            {
                ListOfDicts.push_back(wordlist);
                ListOfDictsName.push_back(path);

           }
           continue;
       }

        if(ch == '2')
            {

                cin >> query;
                vector< string > sublist = SearchSubstrings(wordlist,query);
                for(size_t i=0; i<sublist.size(); i++)
                {
                    cout << sublist.at(i) <<  endl;
                }
            continue;
    }

    if(ch == '3')
       {

           cin >> query;

            for(size_t i=0; i< wordlist.size(); i++)
            {
                string word = wordlist.at(i);
                 pos = word.find(query);
                if(pos < word.length())
                    {
                        wordlist.erase (wordlist.begin()+i);
                         x++;
                         if (i<ListOfDictsName.at(0).size()-sub)
                         {
                                contador++;
                                i--;
                                sub++;
                                continue;

                         }

                         else
                        if (i>ListOfDictsName.at(0).size()-sub)
                         {
                                contador1++;
                                i--;
                                sub++;
                                continue;

                         }
                         else
                         {
                             contador2++;
                             i--;
                             sub++;
                             continue;
                         }
                    }
            }
     }


    if(ch == '4')
       {
           cout << "Statistics: " << endl;
           for(size_t i=0; i<ListOfDicts.size(); i++)
           {
               if (i==0)
               {
                    k = ListOfDicts.at(i).size();
                    cout << ListOfDictsName.at(i) << " -> "  <<  ListOfDicts.at(i).size()-contador << " words" << endl;
                    continue;
               }
               if (i==1)
               {
                   k= ListOfDicts.at(i-1).size();
                   cout << ListOfDictsName.at(i) << " -> "  << ListOfDicts.at(i).size()-k-contador1 << " words" << endl;
               }
               if (i==2)
               {
                   k= ListOfDicts.at(i-1).size();
                   cout << ListOfDictsName.at(i) << " -> " << ListOfDicts.at(i).size()-k-contador2 << " words" << endl;
               }
           }

           continue;
        }



        if(ch == '5')
            {
               acabar=1;

            }

}

return 0;
}

