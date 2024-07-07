#pragma once
#include<iostream>
#include"person.h"
#include"Ek.h"
#include<algorithm>
#include<vector>
#include"create.h"

class team 
{
private: 
	std::vector<person*> members; 
	Ek* leader; 
    int anzahl; 

public: 
    team() = default;
	// team() : leader(nullptr), anzahl(0) {};		                            //Was ist wenn ein team member asugetausscht werden soll
   
    
    int get_anzahl() { return anzahl; }
    void addMember(person* member); 
    void setTeamLeader(Ek* newleader); 
    void display() const;
    //std::vector<team> make_teams(int anzahl);
   // std::vector<team> get_teams() { return teams;  }                                                     //Fürs nächste mal immer setters und getters einbauen
    void replace_member(std::vector<team>& teams, int teamindex, int memberindex, person* newMember);
    void replace_leader(std::vector<team>& teams, int teamindex, Ek* newleader);
    void manage_teams(create& creator);
    
};

