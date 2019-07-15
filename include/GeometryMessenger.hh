//
// Created by user on 7/15/19.
//

#ifndef B_DEVICE_GEOMETRYMESSENGER_HH
#define B_DEVICE_GEOMETRYMESSENGER_HH


#include <G4UIcmdWithADouble.hh>
#include "G4UImanager.hh"
#include "G4UImessenger.hh"
#include "DetGeometry.hh"

class DetGeometry;

class GeometryMessenger : public G4UImessenger{

public:
    GeometryMessenger(DetGeometry *det);

    ~GeometryMessenger();

    void SetNewValue(G4UIcommand *command, G4String newValue);


private:

    DetGeometry *det;
    G4UIdirectory *my_dir3;
    G4UIcmdWithADouble *setC;

};

#endif //B_DEVICE_GEOMETRYMESSENGER_HH
