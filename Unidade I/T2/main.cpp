#include "personPF.hpp"
#include <iostream>
#include <vector>

#define fdebug 0


int main()
{
    vector < PersonPF > PFList;
    vector < PersonPJ > PJList;
    string query;



    if(LoadDatabase("database.dat",PFList,PJList) == false)
    {
        if(fdebug)cout << "Database file not found.Creating a new one" << endl;
    }


    for(;;)
    {
        SaveDatabase("database.dat",PFList,PJList);

        if(fdebug) cout << "MY PAPA'S COMPANY - SIG" << endl;
        if(fdebug) cout << "1. Add PF..." << endl;
        if(fdebug) cout << "2. Add PJ..." << endl;
        if(fdebug) cout << "3. Remove PF Index..." << endl;
        if(fdebug) cout << "4. Remove PJ Index..." << endl;
        if(fdebug) cout << "5. Print Names in Ascending Order" << endl;
        if(fdebug) cout << "6. Exit" << endl;
        if(fdebug) cout << "Enter an option: " << endl;

        char ch;
        cin >> ch;

        //clear input buffer
        cin.ignore();  //fflush();

        if(ch == '1')
        {
            PersonPF p;
            if(fdebug)cout << "Digite todos os dados da pessoa: Nome, nomeMae,CPF,Endereco e Telefone" << endl;
            getline(cin,p.nome);
            getline(cin,p.nomemae);
            getline(cin,p.cpf);
            getline(cin,p.endereco);
            getline(cin,p.telefone);
            PFList.push_back(p);

            continue;
        }
        if(ch == '2')
        {
            PersonPJ p;
            if(fdebug)cout << "Digite todos os dados da pessoa: razaoSocial, CNPJ,Endereco,Telefone e capitalSocial" << endl;
            getline(cin,p.razaoSocial);
            getline(cin,p.cnpj);
            getline(cin,p.endereco);
            getline(cin,p.telefone);
            cin >> p.capitalSocial;
            PJList.push_back(p);

            continue;
        }

        if(ch == '3')
        {

           if(fdebug)cout << "Digite a PF que deseja remover";
           size_t remover;
           cin >> remover;

           PFList.erase(PFList.begin()+ remover);

           continue;
        }



        if(ch == '4')
        {
            if(fdebug)cout << "Digite a PF que deseja remover";
            size_t remover;
            cin >> remover;

            PJList.erase(PJList.begin()+ remover);

            continue;
        }

        if(ch == '5')
        {
           cout << "Names in Ascending Order:" << endl;
            //concatenar em um unico vector<string> tmp
            vector <string> tmp;
            string tmpstring;
            for (size_t i=0; i<PFList.size(); i++)
            {
                tmpstring = PFList[i].nome;
                tmp.push_back(tmpstring);
            }
            for (size_t i=0; i<PJList.size(); i++)
            {
                tmpstring = PJList[i].razaoSocial;
                tmp.push_back(tmpstring);
            }

            sort(tmp.begin(), tmp.end());
            for (size_t i=0; i<tmp.size(); i++)
            {
                cout << tmp.at(i) << endl;
            }



            // concatenar em um único vector<string>tmp;
            //std:: sort
            // std:: stable_sort()
            //for(size_t i=0; i<PFList.size(); i++)
            //{
               // cout << " Name : " << PFList.at(i).nome << " -> " << " Mae : " << PFList.at(i).nomemae << endl;
            //}
        }
        if(ch == '6')
        {
            break;
        }
    }

    return 0;
}



