#include <iostream>
#include <vector>

using namespace std;

class Scheduler
{
public:
    virtual void deletar(vector<size_t> &jobsID){}
};

class Policy1 : public Scheduler // Fila
{
public:
    void deletar(vector<size_t> &jobsID){jobsID.erase(jobsID.begin()+0);}
};

class Policy2 : public Scheduler // Pilha
{
public:
    void deletar(vector<size_t> &jobsID){size_t i; i=jobsID.size()-1;jobsID.erase(jobsID.begin()+i);}
};
