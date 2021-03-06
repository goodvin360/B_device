#ifndef CPROJECT_DETGEOMETRY_HH
#define CPROJECT_DETGEOMETRY_HH

#include "G4SystemOfUnits.hh"

#include <G4PhysicalConstants.hh>
#include "G4SolidStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"

#include "G4NistManager.hh"

#include "G4PVPlacement.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"

#include "G4VUserDetectorConstruction.hh"
#include "GeometryMessenger.hh"


class G4VPhysicalVolume;
class G4LogicalVolume;
class GeometryMessenger;


class DetGeometry : public G4VUserDetectorConstruction
{
private:

    virtual G4VPhysicalVolume*  Construct();
    G4VPhysicalVolume*          physWorld;
    GeometryMessenger *geometryMessenger;





public:
    DetGeometry();
    virtual ~DetGeometry();
    void SetNewC(G4double newValue);
    G4double C = 55;

};


#endif //CPROJECT_DETGEOMETRY_HH
