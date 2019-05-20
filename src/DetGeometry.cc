#define Tube_With_Mixture
#define Cadmium_Shield


#include "DetGeometry.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4Color.hh"
#include "G4RotationMatrix.hh"
#include "G4Sphere.hh"
#include "G4SubtractionSolid.hh"

DetGeometry::DetGeometry() {

}

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){

    G4NistManager* nist = G4NistManager::Instance();

    G4double size = 5*m;

    G4Material* world_mat = nist->FindOrBuildMaterial("G4_Galactic");

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


//create an SPHERE container

//    G4Material*sc_mat = nist->FindOrBuildMaterial("G4_Fe");
//
//    G4double size_of_sc = 1*cm;
//
//    G4ThreeVector sc_pos = G4ThreeVector(0*cm, 0*cm, 0*cm);
//
//    G4Sphere*spcont = new G4Sphere("SpCont", 100*size_of_sc, 113*size_of_sc, 0.*deg, 360.*deg, 0.*deg, 180.*deg);
//
//    G4RotationMatrix* myRotation = new G4RotationMatrix();
//    myRotation->rotateX(0.*deg);
//    myRotation->rotateY(0.*deg);
//    myRotation->rotateZ(0.*rad);
//
//    G4LogicalVolume*logicSpCont = new G4LogicalVolume(spcont, sc_mat, "SpCont");
//
//    G4VisAttributes*logicSpContcolour = new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));
//
//    logicSpCont->SetVisAttributes(logicSpContcolour);
//
//
//    new G4PVPlacement(myRotation,
//                      sc_pos,
//                      logicSpCont,
//                      "SpCont",
//                      logicWorld,
//                      false,
//                      0);


   // create an complex BOX container

//    G4double box_size = 1*cm;
//
//    G4Material*sub_mat1 = nist->FindOrBuildMaterial("G4_Fe");
//
//    G4ThreeVector sub1_pos = G4ThreeVector(0*cm, 0*cm, 0*cm);
//
//    G4Box*box0 = new G4Box("Box0", 100*box_size, 100*box_size, 100*box_size);
//
//    G4Box*box1 = new G4Box("Box1", 103*box_size, 103*box_size, 103*box_size);
//
//    G4SubtractionSolid*Sub1 = new G4SubtractionSolid ("Sub1", box1, box0);
//    G4LogicalVolume*logicSub1 = new G4LogicalVolume(Sub1, sub_mat1, "Sub1");
//    G4VisAttributes*logicSub1colour = new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));
//    logicSub1->SetVisAttributes(logicSub1colour);
//
//
//    new G4PVPlacement(0,
//                      sub1_pos,
//                      logicSub1,
//                      "Sub1",
//                      logicWorld,
//                      false,
//                      0);
//
//    G4Material*sub_mat2 = nist->FindOrBuildMaterial("G4_CONCRETE");
//
//    G4ThreeVector sub2_pos = G4ThreeVector(0*cm, 0*cm, 0*cm);
//
//    G4Box*box3 = new G4Box("Box3", 104*box_size, 104*box_size, 104*box_size);
//
//    G4Box*box4 = new G4Box("Box4", 109*box_size, 109*box_size, 109*box_size);
//
//    G4SubtractionSolid*Sub2 = new G4SubtractionSolid ("Sub2", box4, box3);
//    G4LogicalVolume*logicSub2 = new G4LogicalVolume(Sub2, sub_mat2, "Sub2");
//    G4VisAttributes*logicSub2colour = new G4VisAttributes(G4Colour(133.0, 133.0, 133.0));
//    logicSub2->SetVisAttributes(logicSub2colour);
//
//
//    new G4PVPlacement(0,
//                      sub2_pos,
//                      logicSub2,
//                      "Sub2",
//                      logicWorld,
//                      false,
//                      0);
//
//    G4Material*sub_mat3 = nist->FindOrBuildMaterial("G4_Fe");
//
//    G4ThreeVector sub3_pos = G4ThreeVector(0*cm, 0*cm, 0*cm);
//
//    G4Box*box5 = new G4Box("Box5", 110*box_size, 110*box_size, 110*box_size);
//
//    G4Box*box6 = new G4Box("Box6", 113*box_size, 113*box_size, 113*box_size);
//
//    G4SubtractionSolid*Sub3 = new G4SubtractionSolid ("Sub3", box6, box5);
//    G4LogicalVolume*logicSub3 = new G4LogicalVolume(Sub3, sub_mat3, "Sub3");
//    G4VisAttributes*logicSub3colour = new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));
//    logicSub3->SetVisAttributes(logicSub3colour);
//
//
//    new G4PVPlacement(0,
//                      sub3_pos,
//                      logicSub3,
//                      "Sub3",
//                      logicWorld,
//                      false,
//                      0);






    // create an SOURSE

    G4Material*InSp_det_mat = nist->FindOrBuildMaterial("G4_Galactic");

    G4double size_of_sourse = 1*cm;

    G4ThreeVector InSp_det_pos = G4ThreeVector(0*cm, 0*cm, 5*cm);

    G4Sphere*InSp_det = new G4Sphere("Source", 0.1*size_of_sourse, 0.2*size_of_sourse, 0*deg, 360*deg, 0*deg, 360*deg);

    G4LogicalVolume*logicInSpDet = new G4LogicalVolume(InSp_det, InSp_det_mat, "Source");

    G4VisAttributes*logicSpDet = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0));

    logicInSpDet->SetVisAttributes(logicSpDet);


    new G4PVPlacement(0,
                      InSp_det_pos,
                      logicInSpDet,
                      "Source",
                      logicWorld,
                      false,
                      0);

    // create an OUTER SPHERE detector

//    G4Material*OuSp_det_mat = nist->FindOrBuildMaterial("G4_BGO");
//
//    G4double OuSp_size_of_det = 1*cm;
//
//    G4ThreeVector OuSp_det_pos = G4ThreeVector(0*cm, 0*cm, 0*cm);
//
//    G4Sphere*OuSp_det = new G4Sphere("OuSpDetector", 15*OuSp_size_of_det, 16*OuSp_size_of_det, 0.*deg, 360.*deg, 0.*deg, 90.*deg);
//
//    G4LogicalVolume*logicOuSpDet = new G4LogicalVolume(OuSp_det, OuSp_det_mat, "OuSpDetector");
//
//    G4VisAttributes*logicOutSpDet = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0));
//
//    logicOuSpDet->SetVisAttributes(logicOutSpDet);
//
//
//    new G4PVPlacement(0,
//                      OuSp_det_pos,
//                      logicOuSpDet,
//                      "OuSpDetector",
//                      logicWorld,
//                      false,
//                      0);


//    create an CYLLINDER detector

//        G4String name, symbol;
//    G4double a, z, det_density;
//    G4int ncomponents;
//    G4int natoms;
//    a = 80.9058*g/mole;
//    G4Element*elY = new G4Element(name="Yttrium", symbol="Y", z = 39., a);
//    a = 26.9816*g/mole;
//    G4Element*elAl = new G4Element(name="Aluminium", symbol="Al", z = 13., a);
//    a = 16*g/mole;
//    G4Element*elO = new G4Element(name="Oxygen", symbol="O", z = 8., a);
//    a = 1*g/mole;
//    G4Element*elH = new G4Element(name="Hydrogen", symbol="H", z = 1., a);
//    det_density = 5.37*g/cm3;
//    G4Material*det_mat2 = new G4Material(name="Detector_material", det_density, ncomponents = 3);
//    det_mat2->AddElement(elY, natoms = 1);
//    det_mat2->AddElement(elAl, natoms = 1);
//    det_mat2->AddElement(elO, natoms = 3);

//    G4Material*det_mat = nist->FindOrBuildMaterial("G4_Ge");
//
//    G4ThreeVector det_pos = G4ThreeVector(0*cm, 0*cm, -9.8*cm);
//
//    G4Tubs*det = new G4Tubs("Detector", 0.0*cm, 2.4*cm, 1.5*cm,  0*deg, 360*deg);
//
//    G4LogicalVolume*logicDet = new G4LogicalVolume(det, det_mat, "Detector");
//
//    G4VisAttributes*logicVisDet = new G4VisAttributes(G4Colour(0.0, 0.0, 1.0));
//
//    logicDet->SetVisAttributes(logicVisDet);
//
//    G4RotationMatrix* myRotation = new G4RotationMatrix();
//    myRotation->rotateX(90.*deg);
//    myRotation->rotateY(0.*deg);
//    myRotation->rotateZ(0.*rad);
//
//    new G4PVPlacement(0,
//                      det_pos,
//                      logicDet,
//                      "Detector",
//                      logicWorld,
//                      false,
//                      0);
//
//
//
//    //    create an CYLLINDER conteiner of Al
//
//
//    G4Material*sub_mat1 = nist->FindOrBuildMaterial("G4_Al");
//
//    G4ThreeVector sub1_pos = G4ThreeVector(0*cm, 0*cm, -20*cm);
//
//    G4Tubs*tub0 = new G4Tubs("Tub0", 0*cm, 2.8*cm, 12*cm, 0*deg, 360*deg);
//
//    G4Tubs*tub1 = new G4Tubs("Tub1", 0*cm, 2.677*cm, 11.877*cm, 0*deg, 360*deg);
//
//    G4SubtractionSolid*Sub1 = new G4SubtractionSolid ("Sub1", tub0, tub1);
//    G4LogicalVolume*logicSub1 = new G4LogicalVolume(Sub1, sub_mat1, "Sub1");
//    G4VisAttributes*logicSub1colour = new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));
//    logicSub1->SetVisAttributes(logicSub1colour);
//
//
//    new G4PVPlacement(0,
//                      sub1_pos,
//                      logicSub1,
//                      "Sub1",
//                      logicWorld,
//                      false,
//                      0);
//
//   //    create an CYLLINDER conteiner of Pb
//
//
//   G4Material*tub_mat2 = nist->FindOrBuildMaterial("G4_Pb");
//
//   G4ThreeVector tub2_pos = G4ThreeVector(0*cm, 0*cm, -10*cm);
//
//   G4Tubs*Tub2 = new G4Tubs("Tub2", 4*cm, 8*cm, 10*cm, 0*deg, 360*deg);
//
//   G4LogicalVolume*logicTub2 = new G4LogicalVolume(Tub2, tub_mat2, "Tub2");
//   G4VisAttributes*logicTub2colour = new G4VisAttributes(G4Colour(0.0, 1.0, 0.0));
//   logicTub2->SetVisAttributes(logicTub2colour);
//
//
//   new G4PVPlacement(0,
//                     tub2_pos,
//                     logicTub2,
//                     "Tub2",
//                     logicWorld,
//                     false,
//                     0);
//
//    G4ThreeVector tub3_pos = G4ThreeVector(0*cm, 0*cm, 2*cm);
//
//    G4Tubs*Tub3 = new G4Tubs("Tub3", 2.7*cm, 8*cm, 2*cm, 0*deg, 360*deg);
//
//    G4LogicalVolume*logicTub3 = new G4LogicalVolume(Tub3, tub_mat2, "Tub3");
//    G4VisAttributes*logicTub3colour = new G4VisAttributes(G4Colour(0.0, 1.0, 0.0));
//    logicTub3->SetVisAttributes(logicTub3colour);
//
//
//    new G4PVPlacement(0,
//                      tub3_pos,
//                      logicTub3,
//                      "Tub3",
//                      logicWorld,
//                      false,
//                      0);
//
//    G4ThreeVector tub4_pos = G4ThreeVector(0*cm, 0*cm, -10*cm);
//
//    G4Tubs*Tub4 = new G4Tubs("Tub4", 3.9*cm, 4*cm, 10*cm, 0*deg, 360*deg);
//
//    G4LogicalVolume*logicTub4 = new G4LogicalVolume(Tub4, sub_mat1, "Tub4");
//    G4VisAttributes*logicTub4colour = new G4VisAttributes(G4Colour(0.5, 0.5, 5.0));
//    logicTub4->SetVisAttributes(logicTub4colour);
//
//
//    new G4PVPlacement(0,
//                      tub4_pos,
//                      logicTub4,
//                      "Tub4",
//                      logicWorld,
//                      false,
//                      0);


// Define meterials (Boric Acid, Water, Helium etc.)

    G4String name,symbol;
    G4double abundance, aH, aO, z, ncomponents,
    H3BO3_density, H3BO3_mass,
    H2O_density, H2O_volume,
    mix_volume, mix_density,
    temperature, pressure, fractionmass;
    G4int nIsotopes,natoms;
    G4double He3_temp, He3_press, He3_density;

    He3_temp = 300*kelvin;
    He3_press = 0.1*atmosphere;
    He3_density = 0.001*g/cm3;
    temperature = 300.*kelvin;
    pressure = 1.*atmosphere;
    H2O_density = 1*g/cm3;
    mix_volume = 1000*cm3;
    H3BO3_mass = 55*g;
    H3BO3_density = 1.435*g/cm3;
    H2O_volume = mix_volume-H3BO3_mass/H3BO3_density;
    mix_density = (H3BO3_mass+H2O_density*H2O_volume)/mix_volume;
//    G4cout << "mix density  is " << mix_density/(g/cm3) << G4endl;

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

    //Define material of Helium counter housing
    G4Material*Counter_mat = nist->FindOrBuildMaterial("G4_Al");

    //Define material of mixture housing
    G4Material*Tube_mat = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");

    //Define material of Cadmium sheild
    G4Material*Cd_mat = nist->FindOrBuildMaterial("G4_Cd");


//  Create rotation of the objects
    G4RotationMatrix* myRotation = new G4RotationMatrix();
    myRotation->rotateX(0.*deg);
    myRotation->rotateY(90.*deg);
    myRotation->rotateZ(0.*rad);


#ifdef Tube_With_Mixture

    //Define Boric Acid mix with Water (place in space)

    G4ThreeVector Mix_pos = G4ThreeVector(0*cm, 0*cm, -15*cm);

    G4Tubs*Mix = new G4Tubs("Mixture", 0*cm, 5*cm, 5*cm, 0*deg, 360*deg);

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

    G4ThreeVector Tube_pos = G4ThreeVector(0*cm, 0*cm, -15*cm);

    G4Tubs*Tube = new G4Tubs("MixTube", 5*cm, 6*cm, 5*cm, 0*deg, 360*deg);

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

    // create an He3 counter housing

    G4ThreeVector Counter_pos = G4ThreeVector(0*cm, 0*cm, -30*cm);

    G4Tubs*Counter0 = new G4Tubs("Counter0", 0*cm, 1*cm, 2.1*cm, 0*deg, 360*deg);

    G4Tubs*Counter1 = new G4Tubs("Counter1", 0*cm, 0.9*cm, 2*cm, 0*deg, 360*deg);

    G4SubtractionSolid*Counter = new G4SubtractionSolid ("Counter", Counter0, Counter1);

    G4LogicalVolume*logicCounter = new G4LogicalVolume(Counter, Counter_mat, "Counter");

    G4VisAttributes*logicVisCounter = new G4VisAttributes(G4Colour(0.7, 0.2, 0.1));

    logicCounter->SetVisAttributes(logicVisCounter);

    new G4PVPlacement(myRotation,
                      Counter_pos,
                      logicCounter,
                      "Counter",
                      logicWorld,
                      false,
                      0);

    // filling helium counter with He3 isotope

    G4ThreeVector He3_pos = G4ThreeVector(0*cm, 0*cm, -30*cm);

    G4Tubs*He3_gas = new G4Tubs("He3_gas", 0*cm, 0.9*cm, 2*cm, 0*deg, 360*deg);

    G4LogicalVolume*logicHe3_gas = new G4LogicalVolume(He3_gas, He3_mat, "He3_gas");

    G4VisAttributes*logicVisHe3_gas = new G4VisAttributes(G4Colour(0.1, 0.8, 0.1));

    logicHe3_gas->SetVisAttributes(logicVisHe3_gas);

    new G4PVPlacement(myRotation,
                      He3_pos,
                      logicHe3_gas,
                      "He3_gas",
                      logicWorld,
                      true,
                      0);

#ifdef Cadmium_Shield
    // create an Cadmium shield

    G4ThreeVector Shield_pos = G4ThreeVector(0*cm, 0*cm, -30*cm);

    G4Tubs*Shield0 = new G4Tubs("Shield0", 0*cm, 1.1*cm, 2.2*cm, 0*deg, 360*deg);

    G4Tubs*Shield1 = new G4Tubs("Shield1", 0*cm, 1*cm, 2.1*cm, 0*deg, 360*deg);

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
#endif


    return physWorld;
}
