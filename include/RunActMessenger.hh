//
// Created by user on 7/15/19.
//

#ifndef B_DEVICE_RUNACTMESSENGER_HH
#define B_DEVICE_RUNACTMESSENGER_HH

#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithAString.hh>
#include "G4UImanager.hh"
#include "G4UImessenger.hh"
#include "RunAct.hh"

class RunAct;

class RunActMessenger : public G4UImessenger{

public:
    RunActMessenger(RunAct *run1);

    ~RunActMessenger();

    void SetNewValue(G4UIcommand *command, G4String newValue);


private:

    RunAct *run1;
    G4UIdirectory *my_dir4;
    G4UIcmdWithAString *setPath;


};


#endif //B_DEVICE_RUNACTMESSENGER_HH
