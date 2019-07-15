

#ifndef CPROJECT_RUNACT_HH
#define CPROJECT_RUNACT_HH

#include <G4UserRunAction.hh>
#include <G4SystemOfUnits.hh>
#include "Run.hh"
#include "EventAct.hh"
#include <map>
#include "RunActMessenger.hh"

using namespace std;

class G4Run;
class RunActMessenger;



class RunAct : public G4UserRunAction {
public:

    RunAct();
    ~RunAct();
    void BeginOfRunAction(const G4Run *aRun);
    void EndOfRunAction(const G4Run *aRun);

    void AddEvent1(G4double energy1);

    void AddEvent2(G4double energy2);

    void AddEvent3(G4double energy3);

    void AddEvent4(G4double energy4);

    void AddEvent4_1(G4double energy4_1);

    void AddEvent4_2(G4double energy4_2);

    void AddEvent5(G4double energy5);

    void AddEvent5_1(G4double energy5_1);

    void AddEvent5_2(G4double energy5_2);

    void SetNewPath(G4String newPath);

    G4String foldername = "/mnt/hgfs/VMplayer/B_device/Summ.txt";

    int nStep = 10000;
    G4double Emax = 10.0*MeV;
    G4double Emax1 = 0.0000004*MeV;
    G4double Emax2 = 0.01*MeV;
//    double a = 0.00001;
//    double b = 0.000002;

    double w = 13.1;
    double F = 220;


private:

    std::map <G4double, G4int> *result1;

    std::map <G4double, G4int> *result2;

    std::map <G4double, G4int> *result3;

    std::map <G4double, G4int> *result4;

    std::map <G4double, G4int> *result4_1;

    std::map <G4double, G4int> *result4_2;

    std::map <G4double, G4int> *result5;

    std::map <G4double, G4int> *result5_1;

    std::map <G4double, G4int> *result5_2;

    RunActMessenger *runactMessenger;

};

#endif //CPROJECT_RUNACT_HH
