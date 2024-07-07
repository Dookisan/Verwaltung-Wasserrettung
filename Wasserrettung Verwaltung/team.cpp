#include "team.h"

void team::addMember(person* member)
{
	members.push_back(member);
}

void team::setTeamLeader(Ek* newleader)
{
	leader = newleader;
}

void team::display() const
{
    std::cout << "Team Members:" << std::endl;
    for (auto& member : members) {
        member->print();
    }
    if (leader) {
        std::cout << "Team Leader:" << std::endl;
        leader->print();
    }
}

/*std::vector<team> team::make_teams(int anzahl)
{
    
    int ekindex = 0;
    int personindex = 0; 
    int personAdded = 0;

    create creator;
    creator.assign();
   
    std::vector<person>& persons = creator.getPersons();                          //Neue idee es wird ein weiterer vector genutzt, dieser weißt jeden wert ein bool true und false zu, dieser sagt ob eine person schon verwendet wurde 
    std::vector<Ek>& einsatzkraefte = creator.getEinsatzkraefte();
    //std::vector<team> teams; 

    for (int y = 0; y < anzahl; y++) {
        team myTeam;
        personAdded = 0;
        if (!einsatzkraefte.empty()) {
            myTeam.setTeamLeader(&einsatzkraefte[y]);
                                                                //Vector mit mehreren Teams erstellen, dann sollte beides Funktionieren
        }
        while (personindex < persons.size() && personAdded < 3) {
            if (persons[personindex].get_status() != work_state::used) {
                myTeam.addMember(&persons[personindex]);
                persons[personindex].change_state(); 

                personAdded++;
               
            }
            personindex++;
        }
        creator.manageTeams(myTeam);
        //teams.push_back(myTeam); 
    }
    for (int i = 0; i < teams.size(); i++) {
        std::cout << "\nTeam: " << i + 1 << "\n" << std::endl;
        teams[i].display();
    }

    return teams;
}*/

void team::replace_member(std::vector<team>& teams, int teamindex, int memberIndex, person* newMember)
{
    if (teamindex < 0 || teamindex >= teams.size()) {
        std::cout << "Ungültiger Teamindex" << std::endl;
        return;
    }
    if (memberIndex < 0 || memberIndex >= teams[teamindex].members.size()) {
        std::cout << "Ungültiger Memberindex" << std::endl;
        return;
    }


    members[memberIndex] = newMember;  
}

void team::replace_leader(std::vector<team>& teams, int teamindex, Ek* newleader)
{

    leader = newleader; 
}

void team::manage_teams(create & creator)
{
    std::vector<team>& teams = creator.getTeams();
    std::vector<person>& persons = creator.getPersons();
    std::vector<Ek>& einsatzkraefte = creator.getEinsatzkraefte();

    std::string m_replacement;
    char choice; 
    
    std::cout << "Wolles Sie ein Team aendern? (y/n) " << std::endl; 
    std::cin >> choice; 

    while (choice == 'y'|| choice == 'Y') {                                         //Anmerkung: "" const char ; '' normales char; vielleicht nützlich 
        std::cout << "Welches Team wollen Sie aendern? " << std::endl; 

        int teamnum = 0; 
        std::cin >> teamnum;
        teamnum--; 
        std::cout << "Wollen sie eine Einsatzkraft oder ein Member bearbeiten (Ek/m)" << std::endl; 
        
        
        char choicetwo;
        std::cin >> choicetwo;
        switch (choicetwo)
        {
        case 'm':
            person * new_member = NULL;
             

            std::cout << "Welches Member soll geaender werden" << std::endl;
            std::cin >> m_replacement;
            m_replacement.erase(m_replacement.find_last_not_of(" \n\r\t") + 1);
                for (auto& p : teams[teamnum].members) {
                    
                    if (p->get_name() == m_replacement) {
                        new_member = p ;
                        break; 

                    }
                   
                }
                if (new_member) {
                    int memberIndex = 0; 

                    std::cout << "Welches newe Member soll hinzugefuegt werden: Index Eingeben" << std::endl; 
                    std::cin >> memberIndex;
                    memberIndex--; 
                    teams[teamnum].replace_member(teams,teamnum, memberIndex, &creator.getPersons()[memberIndex]);
                    
                }
                else {
                    std::cout << "Memberindex nicht korrekt" << std::endl; 

                }
               
            /*
            case 'Ek':
                int ekindex = 0; 
                Ek* new_ek = NULL;
                std::cout << "Welche Einsatzkraft soll geaendert werden" << std::endl; 
                std::cin >> ekindex; 

                for (const auto& ek : creator.getEinsatzkraefte()) {
                    if (ek.get_id() == ekindex) {
                        new_ek = &ek;
                        break;
                    }
                }
                    if(new_ek){
                        replace_leader(teamnum, new_ek); 
                    }
                    break; 

            default:
                 std::cout << "Ungueltiger Index" << std::endl; 
                 break;
                 */
            
            }
        
        
        }
    for (int i = 0; i < teams.size(); i++) {
        std::cout << "\nTeam: " << i + 1 << "\n" << std::endl;
        teams[i].display();

        std::cout << "Wollen Sie weiter veraendern?" << std::endl;
        std::cin >> choice;
    }
}



