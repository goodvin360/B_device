//
// Created by user on 7/15/19.
//

#include "GeometryMessenger.hh"
#include "DetGeometry.hh"

GeometryMessenger::GeometryMessenger(DetGeometry *Det) {

    det = Det;

    my_dir3 = new G4UIdirectory("/my_dir3/");
    my_dir3->SetGuidance("UI commands specific to this sample");

    setC = new G4UIcmdWithADouble("/my_dir3/SetAcidMass", this);
    setC->SetGuidance("Change mass of the Acid");
    setC->SetParameterName("mass", false);

}

GeometryMessenger::~GeometryMessenger() {

}


void GeometryMessenger::SetNewValue(G4UIcommand *command, G4String newValue) {

    if(command == setC)
    {
        det->SetNewC(setC->GetNewDoubleValue(newValue));
    }

}