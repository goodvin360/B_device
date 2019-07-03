

#ifndef CPROJECT_EVENTACT_HH
#define CPROJECT_EVENTACT_HH

#include "G4UserEventAction.hh"
#include "G4RunManager.hh"
#include "RunAct.hh"
#include "Run.hh"

class RunAct;

class EventAct : public G4UserEventAction
{
public:
    EventAct(RunAct* runAct);
   // ~EventAct();
   // virtual void BeginOfEventAction(const G4Event* event);
   // virtual void EndOfEventAction(const G4Event* event);
      void BeginOfEventAction(const G4Event* anEvent);
      void EndOfEventAction(const G4Event* anEvent);
      void AddEnDep1 (G4double en1);
      void AddEnDep2 (G4double en2);
      void AddEnDep3 (G4double en3);
      void AddEnDep4 (G4double en4);
    void AddEnDep4_1(G4double en4_1);
    void AddEnDep4_2(G4double en4_2);
      void AddEnDep5 (G4double en5);
    void AddEnDep5_1(G4double en5_1);
    void AddEnDep5_2(G4double en5_2);



private:
      RunAct *run;
      G4double EnergyDep1;
      G4double EnergyDep2;
      G4double EnergyDep3;
      G4double EnergyDep4;
    G4double EnergyDep4_1;
    G4double EnergyDep4_2;
      G4double EnergyDep5;
    G4double EnergyDep5_1;
    G4double EnergyDep5_2;


};

#endif //CPROJECT_EVENTACT_HH
