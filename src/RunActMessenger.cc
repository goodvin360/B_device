//
// Created by user on 7/15/19.
//


#include "RunActMessenger.hh"
#include "RunAct.hh"

RunActMessenger::RunActMessenger(RunAct *run2) {

    run1 = run2;
    my_dir4 = new G4UIdirectory("/my_dir4/");
    my_dir4->SetGuidance("UI command for changing result file path");

    setPath = new G4UIcmdWithAString("/my_dir4/SetNewPath", this);
    setPath->SetGuidance("Write new path");
    setPath->SetParameterName("path", false);


}


RunActMessenger::~RunActMessenger() {

}


void RunActMessenger::SetNewValue(G4UIcommand *command, G4String newValue) {
    if(command == setPath)
    {
        run1->SetNewPath(newValue);
    }
}