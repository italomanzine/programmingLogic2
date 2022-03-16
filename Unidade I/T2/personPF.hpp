#ifndef PERSON_HPP
#define PERSON_HPP


#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>


using namespace std;

struct PersonPF
{
    string nome;
    string nomemae;
    string cpf;
    string endereco;
    string telefone;
};

struct PersonPJ
{
    string razaoSocial;
    string cnpj;
    string endereco;
    string telefone;
    size_t capitalSocial;
};



bool LoadDatabase(string path,vector < PersonPF >& PFList,vector < PersonPJ >& PJList);

bool SaveDatabase(string path, const vector < PersonPF >& PFList, const vector < PersonPJ >& PJList);


#endif
