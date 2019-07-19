#define Tube_With_Mixture


#include "DetGeometry.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4Color.hh"
#include "G4RotationMatrix.hh"
#include "G4Sphere.hh"
#include "G4SubtractionSolid.hh"
#include "G4MultiUnion.hh"
#include <G4GeometryManager.hh>
#include <G4RunManager.hh>
#include <GeometryMessenger.hh>



DetGeometry::DetGeometry() {

    geometryMessenger = new GeometryMessenger(this);

}

DetGeometry::~DetGeometry() {

    delete geometryMessenger;

}

G4VPhysicalVolume* DetGeometry::Construct(){

    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();

    G4NistManager* nist = G4NistManager::Instance();

    G4double size = 5*m;

    G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

    G4Box* solidWorld =
      new G4Box("World",
         0.5*size, 0.5*size, 0.5*size);

    G4LogicalVolume* logicWorld =
      new G4LogicalVolume(solidWorld,
                          world_mat,
                          "World");

logicWorld->SetVisAttributes(G4VisAttributes::Invisible);

 G4VPhysicalVolume* physWorld =
      new G4PVPlacement(0,
                        G4ThreeVector(),
                        logicWorld,
                        "World",
                        0,
                        false,
                        0);


// Define meterials (Boric Acid, Water, Helium, Am-Be, etc.)
    G4String name,symbol;
    G4double abundance, aH, aO, z, ncomponents,
    H3BO3_density, H3BO3_mass,
    H2O_density, H2O_volume,
    mix_volume, mix_density,
    Am_density, Be_density, AmBe_density, Pu_density, PuBe_density,
    AmBe_temp, AmBe_press, PuBe_temp, PuBe_press,
    temperature, pressure, fractionmass;
    G4int nIsotopes,natoms;
    G4double He3_temp, He3_press, He3_density;

    Am_density = 13.67*g/cm3;
    Be_density = 1.848*g/cm3;
    AmBe_density = 4.2124;
    AmBe_press = 1*atmosphere;
    AmBe_temp = 300*kelvin;

    Pu_density = 19.84*g/cm3;
    PuBe_density = 4.2124;
    PuBe_press = 1*atmosphere;
    PuBe_temp = 300*kelvin;

    He3_temp = 300*kelvin;
    He3_press = 4*atmosphere;
    He3_density = 0.0005*g/cm3;
    temperature = 300.*kelvin;
    pressure = 1.*atmosphere;
    H2O_density = 1*g/cm3;
    mix_volume = 1000*cm3;
    H3BO3_mass = C*g;
    H3BO3_density = 1.435*g/cm3;
    H2O_volume = mix_volume-H3BO3_mass/H3BO3_density;
    mix_density = (H3BO3_mass+H2O_density*H2O_volume)/mix_volume;
//    G4cout << "mix density  is " << mix_density/(g/cm3) << G4endl;

    temperature = AmBe_temp = He3_temp = PuBe_temp = 425.* kelvin;

    //Define common elements
    aH = 1.00784*g/mole;
    G4Element*elH = new G4Element(name="Hydrogen", symbol="H", z = 1., aH);

    aO = 15.999*g/mole;
    G4Element*elO = new G4Element(name="Oxygen", symbol="O", z = 8., aO);

    //Define isotopes of B
    G4Isotope*B10 = new G4Isotope(name="B10", 5, 10, 10.012*g/mole);
    G4Isotope*B11 = new G4Isotope(name="B11", 5, 11, 11.009*g/mole);


    //Define element  Boron from isotopes
    G4Element* elBoron = new G4Element(name="Boron", symbol="B", nIsotopes=2);
    elBoron->AddIsotope(B10,abundance= 18.5*perCent);
    elBoron->AddIsotope(B11,abundance= 81.5*perCent);

    //Define Boric Acid

    G4Material*H3BO3 = new G4Material(name="Boron_Acid", H3BO3_density, ncomponents = 3, kStateSolid, temperature, pressure);
    H3BO3->AddElement(elBoron, natoms = 1);
    H3BO3->AddElement(elH, natoms = 3);
    H3BO3->AddElement(elO, natoms = 3);

    //Define H2O (liquid Water)

    G4Material*H2O = new G4Material(name="Water", H2O_density, ncomponents = 2, kStateLiquid, temperature, pressure);
    H2O->AddElement(elH, natoms = 2);
    H2O->AddElement(elO, natoms = 1);

    //Define Boric Acid mix with Water (material)

    G4Material*Mix_mat = new G4Material(name="Mixture", mix_density, ncomponents = 2, kStateLiquid, temperature, pressure);

    Mix_mat->AddMaterial(H3BO3,fractionmass = (100*(H3BO3_mass/H3BO3_density)/(mix_volume)*perCent));
//    G4cout << "fractionmass of boric acid is " << fractionmass << G4endl;

    Mix_mat->AddMaterial(H2O,fractionmass = (100*(H2O_volume)/(mix_volume))*perCent);
//    G4cout << "fractionmass of H2O  is " << fractionmass << G4endl;


    //Define Helium isotope
    G4Isotope*He3 = new G4Isotope(name="He3", 2, 3, 3.016*g/mole);
    //Define element from Helium isotope
    G4Element* elHe3 = new G4Element(name="He3", symbol="He", nIsotopes=1);
    elHe3->AddIsotope(He3,abundance= 100*perCent);
    //Define Helium material
    G4Material*He3_mat = new G4Material(name="Helium3", He3_density, ncomponents = 1, kStateGas, He3_temp, He3_press);
    He3_mat->AddElement(elHe3, natoms = 1);

    //Define Am241 isotope
    G4Isotope*Am241 = new G4Isotope(name="Am241", 95, 241, 241.057*g/mole);
    //Define element from Am241 isotope
    G4Element* elAm241 = new G4Element(name="Am241", symbol="Am", nIsotopes=1);
    elAm241->AddIsotope(Am241,abundance= 100*perCent);
    //Define Am241 material
    G4Material*Am241_mat = new G4Material(name="Am_mat", Am_density, ncomponents = 1, kStateSolid, AmBe_temp, AmBe_press);
    Am241_mat->AddElement(elAm241, natoms = 1);

    //Define Pu239 isotope
    G4Isotope*Pu239 = new G4Isotope(name="Pu239", 94, 239, 239.052*g/mole);
    //Define element from Am241 isotope
    G4Element* elPu239 = new G4Element(name="Pu239", symbol="Pu", nIsotopes=1);
    elPu239->AddIsotope(Pu239,abundance= 100*perCent);
    //Define Pu239 material
    G4Material*Pu239_mat = new G4Material(name="Pu_mat", Pu_density, ncomponents = 1, kStateSolid, PuBe_temp, PuBe_press);
    Pu239_mat->AddElement(elPu239, natoms = 1);

    //Define Be9 isotope
    G4Isotope*Be9 = new G4Isotope(name="Be9", 4, 9, 241.057*g/mole);
    //Define element from Be9 isotope
    G4Element* elBe9 = new G4Element(name="Be9", symbol="Be", nIsotopes=1);
    elBe9->AddIsotope(Be9,abundance= 100*perCent);
    //Define Be9 material
    G4Material*Be9_mat = new G4Material(name="Be_mat", Be_density, ncomponents = 1, kStateSolid, AmBe_temp, AmBe_press);
    Be9_mat->AddElement(elBe9, natoms = 1);

    //Define AmBe material
    G4Material*AmBe_mat = new G4Material(name="AmBe_mat", AmBe_density, ncomponents = 2, kStateSolid, AmBe_temp, AmBe_press);
    AmBe_mat->AddMaterial(Am241_mat,fractionmass = 20*perCent);
    AmBe_mat->AddMaterial(Be9_mat,fractionmass = 80*perCent);

    //Define PuBe material
    G4Material*PuBe_mat = new G4Material(name="PuBe_mat", PuBe_density, ncomponents = 2, kStateSolid, PuBe_temp, PuBe_press);
    PuBe_mat->AddMaterial(Pu239_mat,fractionmass = 20*perCent);
    PuBe_mat->AddMaterial(Be9_mat,fractionmass = 80*perCent);

    //Define material of Helium counter housing
    G4Material*Counter_mat = nist->FindOrBuildMaterial("G4_Al");

    //Define material of mixture housing
    G4Material*Tube_mat = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");

    //Define material of Cadmium sheild
    G4Material*Cd_mat = nist->FindOrBuildMaterial("G4_Cd");

    //  Create rotation matrix of the objects
    G4RotationMatrix* myRotation = new G4RotationMatrix();
    myRotation->rotateX(0.*deg);
    myRotation->rotateY(90.*deg);
    myRotation->rotateZ(0.*rad);


    // define distances

    G4double Rtube, dtube, Htube, Rcnt, dcnt, Hcnt, dshld, Lsrc,
    Zsrc, Xsrc, Ysrc,
    Ztube, Xtube, Ytube,
    Zcnt1, Xcnt1, Ycnt1,
    Zcnt2, Xcnt2, Ycnt2;

    Rtube=6;
    dtube=0.4;
    Htube=15;
    Rcnt=1.6;
    dcnt=0.1;
    Hcnt=11;
    dshld=0.1;
    Lsrc=4.5;


    Xsrc=0, Ysrc=0, Zsrc=0;
    Xtube=0, Ytube=0, Ztube=Lsrc;
    Xcnt1=0, Ycnt1=0, Zcnt1=Lsrc+3.6;
    Xcnt2=0, Ycnt2=0, Zcnt2=Lsrc-1;



#ifdef Tube_With_Mixture

    //Define Boric Acid mix with Water (place in space)

 /*   G4ThreeVector Mix_pos = G4ThreeVector(Xtube*cm, Ytube*cm, Ztube*cm);

    G4Tubs*Mix = new G4Tubs("Mixture", 0*cm, (Rtube-dtube)*cm, Htube*cm, 0*deg, 360*deg);

    G4LogicalVolume*logicMix = new G4LogicalVolume(Mix, Mix_mat, "Mixture");

    G4VisAttributes*logicVisMix = new G4VisAttributes(G4Colour(5, 0.5, 0.5));

    logicMix->SetVisAttributes(logicVisMix);

    new G4PVPlacement(myRotation,
                      Mix_pos,
                      logicMix,
                      "Mixture",
                      logicWorld,
                      false,
                      0);*/

        G4ThreeVector Cnt1pos = G4ThreeVector(3.6*cm, 0*cm, 0*cm);
        G4ThreeVector Cnt2pos = G4ThreeVector(-1*cm, 0*cm, 0*cm);
        G4ThreeVector Src_pos = G4ThreeVector(-Lsrc*cm, 0*cm, 0*cm);
        G4RotationMatrix* yRot = new G4RotationMatrix;

       G4ThreeVector Mix_pos = G4ThreeVector(Xtube*cm, Ytube*cm, Ztube*cm);

       G4Tubs*Mix0 = new G4Tubs("Mixture1", 0*cm, Rtube*cm, Htube*cm, 0*deg, 360*deg);

       G4Tubs*Cnt1 = new G4Tubs("Cnt1", 0*cm, Rcnt*cm, Hcnt*cm, 0*deg, 360*deg);

        G4Tubs*Cnt2 = new G4Tubs("Cnt2", 0*cm, Rcnt*cm, Hcnt*cm, 0*deg, 360*deg);

        G4Tubs*Src = new G4Tubs("Src", 0*cm, 0.3*cm, 0.3*cm, 0*deg, 360*deg);

       G4SubtractionSolid*Mix1 = new G4SubtractionSolid("Mixture1", Mix0, Cnt1, yRot, Cnt1pos);

        G4SubtractionSolid*Mix2 = new G4SubtractionSolid("Mixture2", Mix1, Cnt2, yRot, Cnt2pos);

        G4SubtractionSolid*Mix = new G4SubtractionSolid("Mixture", Mix2, Src, yRot, Src_pos);

       G4LogicalVolume*logicMix = new G4LogicalVolume(Mix, Mix_mat, "Mixture");

       G4VisAttributes*logicVisMix = new G4VisAttributes(G4Colour(5, 0.5, 0.5));

       logicMix->SetVisAttributes(logicVisMix);

       new G4PVPlacement(myRotation,
                         Mix_pos,
                         logicMix,
                         "Mixture",
                         logicWorld,
                         false,
                         0);


    // create an Tube part (Mixture housing)

    G4ThreeVector Tube_pos = G4ThreeVector(Xtube*cm, Ytube*cm, Ztube*cm);

    G4Tubs*Tube = new G4Tubs("MixTube", Rtube*cm, (Rtube+dtube)*cm, Htube*cm, 0*deg, 360*deg);

    G4LogicalVolume*logicTube = new G4LogicalVolume(Tube, Tube_mat, "MixTube");

    G4VisAttributes*logicVisTube = new G4VisAttributes(G4Colour(0.1, 0.1, 0.8));

    logicTube->SetVisAttributes(logicVisTube);

    new G4PVPlacement(myRotation,
                      Tube_pos,
                      logicTube,
                      "MixTube",
                      logicWorld,
                      false,
                      0);

#endif

    // create an He3 counter #1 housing

    G4ThreeVector Counter1_pos = G4ThreeVector(Xcnt1*cm, Ycnt1*cm, Zcnt1*cm);

    G4Tubs*Counter1_0 = new G4Tubs("Counter1_0", 0*cm, Rcnt*cm, Hcnt*cm, 0*deg, 360*deg);

    G4Tubs*Counter1_1 = new G4Tubs("Counter1_1", 0*cm, (Rcnt-dcnt)*cm, (Hcnt-dcnt)*cm, 0*deg, 360*deg);

    G4SubtractionSolid*Counter1 = new G4SubtractionSolid ("Counter1", Counter1_0, Counter1_1);

    G4LogicalVolume*logicCounter1 = new G4LogicalVolume(Counter1, Counter_mat, "Counter1");

    G4VisAttributes*logicVisCounter1 = new G4VisAttributes(G4Colour(0.7, 0.2, 0.1));

    logicCounter1->SetVisAttributes(logicVisCounter1);

    new G4PVPlacement(myRotation,
                      Counter1_pos,
                      logicCounter1,
                      "Counter1",
                      logicWorld,
                      false,
                      0);

    // filling helium counter #1 with He3 isotope

    G4ThreeVector He3_pos1 = G4ThreeVector(Xcnt1*cm, Ycnt1*cm, Zcnt1*cm);

    G4Tubs*He3_gas1 = new G4Tubs("He3_gas1", 0*cm, (Rcnt-dcnt)*cm, (Hcnt-dcnt)*cm, 0*deg, 360*deg);

    G4LogicalVolume*logicHe3_gas1 = new G4LogicalVolume(He3_gas1, He3_mat, "He3_gas1");

    G4VisAttributes*logicVisHe3_gas1 = new G4VisAttributes(G4Colour(0.1, 0.8, 0.1));

    logicHe3_gas1->SetVisAttributes(logicVisHe3_gas1);

    new G4PVPlacement(myRotation,
                      He3_pos1,
                      logicHe3_gas1,
                      "He3_gas1",
                      logicWorld,
                      true,
                      0);


    // create an He3 counter #2 housing

    G4ThreeVector Counter2_pos = G4ThreeVector(Xcnt2*cm, Ycnt2*cm, Zcnt2*cm);

    G4Tubs*Counter2_0 = new G4Tubs("Counter2_0", 0*cm, Rcnt*cm, Hcnt*cm, 0*deg, 360*deg);

    G4Tubs*Counter2_1 = new G4Tubs("Counter2_1", 0*cm, (Rcnt-dcnt)*cm, (Hcnt-dcnt)*cm, 0*deg, 360*deg);

    G4SubtractionSolid*Counter2 = new G4SubtractionSolid ("Counter2", Counter2_0, Counter2_1);

    G4LogicalVolume*logicCounter2 = new G4LogicalVolume(Counter2, Counter_mat, "Counter2");

    G4VisAttributes*logicVisCounter2 = new G4VisAttributes(G4Colour(0.7, 0.2, 0.1));

    logicCounter2->SetVisAttributes(logicVisCounter2);

    new G4PVPlacement(myRotation,
                      Counter2_pos,
                      logicCounter2,
                      "Counter2",
                      logicWorld,
                      false,
                      0);

    // filling helium counter #2 with He3 isotope

    G4ThreeVector He3_pos2 = G4ThreeVector(Xcnt2*cm, Ycnt2*cm, Zcnt2*cm);

    G4Tubs*He3_gas2 = new G4Tubs("He3_gas2", 0*cm, (Rcnt-dcnt)*cm, (Hcnt-dcnt)*cm, 0*deg, 360*deg);

    G4LogicalVolume*logicHe3_gas2 = new G4LogicalVolume(He3_gas2, He3_mat, "He3_gas2");

    G4VisAttributes*logicVisHe3_gas2 = new G4VisAttributes(G4Colour(0.1, 0.8, 0.1));

    logicHe3_gas2->SetVisAttributes(logicVisHe3_gas2);

    new G4PVPlacement(myRotation,
                      He3_pos2,
                      logicHe3_gas2,
                      "He3_gas2",
                      logicWorld,
                      true,
                      0);


    // create an Cadmium shield for counter #1
/*

    G4ThreeVector Shield_pos = G4ThreeVector(Xcnt1*cm, Ycnt1*cm, Zcnt1*cm);

    G4Tubs*Shield0 = new G4Tubs("Shield0", 0*cm, (Rcnt+dshld)*cm, (Hcnt+dshld)*cm, 0*deg, 360*deg);

    G4Tubs*Shield1 = new G4Tubs("Shield1", 0*cm, Rcnt*cm, Hcnt*cm, 0*deg, 360*deg);

    G4SubtractionSolid*Shield = new G4SubtractionSolid ("Shield", Shield0, Shield1);

    G4LogicalVolume*logicShield = new G4LogicalVolume(Shield, Cd_mat, "Shield");

    G4VisAttributes*logicVisShield = new G4VisAttributes(G4Colour(149, 143, 121));

    logicShield->SetVisAttributes(logicVisShield);

    new G4PVPlacement(myRotation,
                      Shield_pos,
                      logicShield,
                      "Shield",
                      logicWorld,
                      false,
                      0);

*/


    // create an SOURSE

    G4ThreeVector Source_pos = G4ThreeVector(Xsrc*cm, Ysrc*cm, Zsrc*cm);

    G4Tubs*Source = new G4Tubs("Source", 0*cm, 0.3*cm, 0.3*cm, 0*deg, 360*deg);

    G4LogicalVolume*logicSource = new G4LogicalVolume(Source, PuBe_mat, "Source");
//    G4LogicalVolume*logicSource = new G4LogicalVolume(Source, nist->FindOrBuildMaterial("G4_Galactic"), "Source");

    G4VisAttributes*logicVisSource = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0));

    logicSource->SetVisAttributes(logicVisSource);


    new G4PVPlacement(myRotation,
                      Source_pos,
                      logicSource,
                      "Source",
                      logicWorld,
                      false,
                      0);



    return physWorld;

}

void DetGeometry::SetNewC(G4double newValue) {
    C = newValue;
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}

