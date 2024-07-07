#include <iostream>
#include"create.h"
#include "team.h"
using namespace std;

int main()
{
    int index = 0; 
    team myteam;
    cout << "Wieviele teams sollen erstellt werden?" << endl; 
    cin >> index; 
    create creator;
    creator.makeTeams(index); 
    creator.printvectors();
    myteam.manage_teams(creator);
    return 0; 
}

   


