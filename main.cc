//#ifdef G4MULTITHREADED
//#include "G4MTRunManager.hh"
//#else
#include "G4RunManager.hh"
//#endif
#include "G4UImanager.hh"

#include "DetGeometry.hh"
#include "ActionInit.hh"
#include "PrimaryGen.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include <iostream>
#include <G4MTRunManager.hh>

#include "QGSP_BERT_HP.hh"
#include "QBBC.hh"
#include "Shielding.hh"

using namespace std;

int main(int argc, char** argv) {

    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    CLHEP::HepRandom::setTheSeed(time(NULL));

    //#ifdef G4MULTITHREADED
//    G4MTRunManager* runManager;
//#else
    G4RunManager* runManager;
//#endif
    DetGeometry *detGeom;

//#ifdef G4MULTITHREADED
//    runManager = new G4MTRunManager;
//    G4int nThreads = G4Threading::G4GetNumberOfCores();
//    if (argc==3) nThreads = G4UIcommand::ConvertToInt(argv[2]);
//    runManager->SetNumberOfThreads(nThreads);
//#else
    runManager = new G4RunManager;
//#endif

//Set mandatory initialization classes
    detGeom = new DetGeometry();
    runManager->SetUserInitialization(detGeom);
    auto Phys = new QGSP_BERT_HP;
    runManager->SetUserInitialization(Phys);
    runManager->SetUserInitialization(new ActionInit());
    runManager->Initialize();

    // Initialize visualization
    G4VisManager*visManager = new G4VisExecutive;
    visManager->Initialize();

    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    G4UIExecutive* ui = 0;
    if ( argc == 1 ) {
        ui = new G4UIExecutive(argc, argv);
    }

    if (! ui) {
        // batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }
    else {
        // interactive mode : define UI session
        UImanager->ApplyCommand("/control/execute init_vis.mac");
        ui->SessionStart();
    }

    delete ui;
    delete visManager;
    delete runManager;

    return 0;
}