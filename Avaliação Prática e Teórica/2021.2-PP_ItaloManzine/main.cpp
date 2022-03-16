#include <iostream>
#include <vector>
#include "classes.hpp"
#include <algorithm>

using namespace std;

int main()
{
    Policy1 p1;
    Policy2 p2;
    vector<size_t>jobsIDs;
    size_t fim =0;

    while(fim!=1)
    {
      cout <<"TASK SCHEDULER SYSTEM - UFxC TSS" << endl;
      cout <<"Select an option below: "<< endl;
      cout <<"1. Schedule a task to process "<< endl;
      cout <<"2. Pick up a task to process using Policy 1 "<< endl;
      cout <<"3. Pick up a task to process using Policy 2 "<< endl;
      cout <<"4. Print pending tasks "<< endl;
      cout <<"5. Exit "<< endl;

      cout <<" "<< endl;

      char option;
      cin  >> option;
      cin.ignore();

      switch (option)
      {
        case '1':
          size_t tempjob;
          cin >> tempjob;
          if (find(jobsIDs.begin(), jobsIDs.end(), tempjob) != jobsIDs.end() )
            cout << "Esse ID ja existe" << endl;
          else
          {
            jobsIDs.push_back(tempjob);
          }
        break;

        case '2':
          p1.deletar(jobsIDs);
        break;

        case '3':
          p2.deletar(jobsIDs);
        break;

        case '4':
          for (size_t i=0; i<jobsIDs.size(); i++)
          {
              cout << "Vector Position " << i << " - " "Job " << jobsIDs[i] << endl;
          }
        break;

        case '5':
        fim=1;
        default:
        break;
      }

      cout <<" "<< endl;
      cout <<"------------------------------------------------------------------ "<< endl;
    }

return 0;
}
