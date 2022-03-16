#include "personPF.hpp"
#include <string>
/*
 bool LoadDatabase(string path,vector < PersonPF > &PFList,vector < PersonPJ > &PJList)
{
     ifstream fileReader;
     string tmp;
     while(getline(fileReader,tmp))
     {
         if(tmp == "1")
         {
             PersonPF p;
             getline(fileReader,p.nome);
             getline(fileReader,p.nomemae);
             getline(fileReader,p.cpf);
             getline(fileReader,p.endereco);
             getline(fileReader,p.telefone);

             PFList.push_back(p);
         }

        else
        {
            PersonPJ p;
            string conversao;
            getline(fileReader,p.razaoSocial);
            getline(fileReader,p.cnpj);
            getline(fileReader,p.endereco);
            getline(fileReader,p.telefone);
            getline(fileReader,conversao);
            size_t valor = stoi(conversao);
            p.capitalSocial = valor;

            PJList.push_back(p);
        }
    }

     return true;
}

 bool SaveDatabase(string path,const vector < PersonPF > &PFList,const vector < PersonPJ > &PJList)
 {
     ofstream fileWriter(path);

     for(size_t i=0; i< PFList.size(); i++)
        {
            fileWriter << "1" << endl;
            PersonPF p;
            fileWriter << p.nome << endl;
            fileWriter << p.nomemae << endl;
            fileWriter << p.cpf << endl;
            fileWriter << p.endereco << endl;
            fileWriter << p.telefone << endl;

            PFList.push_back(p);
        }


    for(size_t i=0; i< PJList.size(); i++)
        {
            fileWriter << "2" << endl;
            PersonPJ p;
            fileWriter << p.razaoSocial << endl;
            fileWriter << p.cnpj << endl;
            fileWriter << p.endereco << endl;
            fileWriter << p.telefone << endl;
            fileWriter << p.capitalSocial << endl;

            PJList.push_back(p);

        }


         return true;
 }
*/

bool LoadDatabase(string path, vector<PersonPF> &PFList, vector<PersonPJ> &PJList)
{
    ifstream fileReader;
    fileReader.open(path);

    if (fileReader.is_open() == false)
    {
        return false;
    }

    string tmp;
    while (getline(fileReader, tmp))
    {
        if (tmp == "1")
        {
            PersonPF p;
            getline(fileReader, p.nome);
            getline(fileReader, p.nomemae);
            getline(fileReader, p.cpf);
            getline(fileReader, p.endereco);
            getline(fileReader, p.telefone);
            PFList.push_back(p);
        }
        else if (tmp == "2")
        {
            PersonPJ p;
            string capital;
            getline(fileReader, p.razaoSocial);
            getline(fileReader, p.cnpj);
            getline(fileReader, p.endereco);
            getline(fileReader, p.telefone);
            getline(fileReader, capital);
            p.capitalSocial = stoi(capital);
            PJList.push_back(p);
        }
    }
    fileReader.close();

    return true;
}

bool SaveDatabase(string path, const vector<PersonPF> &PFList, const vector<PersonPJ> &PJList)
{
    ofstream fileReader;
    fileReader.open(path);

    if (fileReader.is_open() == false)
    {
        return false;
    }

    for (PersonPF p : PFList)
    {
        fileReader << 1 << endl;
        fileReader << p.nome << endl;
        fileReader << p.nomemae << endl;
        fileReader << p.cpf << endl;
        fileReader << p.endereco << endl;
        fileReader << p.telefone << endl;
    }

    for (PersonPJ p : PJList)
    {
        fileReader << 2 << endl;
        fileReader << p.razaoSocial << endl;
        fileReader << p.cnpj << endl;
        fileReader << p.endereco << endl;
        fileReader << p.telefone << endl;
        fileReader << p.capitalSocial << endl;
    }

    fileReader.close();
    return true;
}
