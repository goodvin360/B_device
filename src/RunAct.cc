
#include "RunAct.hh"
#include "EventAct.hh"
#include "StepAct.hh"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

RunAct::RunAct()
{
    result1 = new std::map<G4double, G4int>;

    result2 = new std::map<G4double, G4int>;

    result3 = new std::map<G4double, G4int>;

    result4 = new std::map<G4double, G4int>;

    result4_1 = new std::map<G4double, G4int>;

    result4_2 = new std::map<G4double, G4int>;

    result5 = new std::map<G4double, G4int>;

    result5_1 = new std::map<G4double, G4int>;

    result5_2 = new std::map<G4double, G4int>;

    runactMessenger = new RunActMessenger(this);




}

RunAct::~RunAct()
{
    delete result1;

    delete result2;

    delete result3;

    delete result4;

    delete result4_1;

    delete result4_2;

    delete result5;

    delete result5_1;

    delete result5_2;

    delete runactMessenger;



}

void RunAct::BeginOfRunAction(const G4Run *aRun)
{


    result1->clear();
    for (int i=0; i <nStep; i++)
        result1->insert(std::pair<G4double, G4int> (i *Emax / nStep, 0));

    result2->clear();
    for (int i=0; i <nStep; i++)
        result2->insert(std::pair<G4double, G4int> (i *Emax / nStep, 0));

    result3->clear();
    for (int i=0; i <nStep; i++)
        result3->insert(std::pair<G4double, G4int> (i *Emax / nStep, 0));

    result4->clear();
    for (int i=0; i <nStep; i++)
        result4->insert(std::pair<G4double, G4int> ( (Emax2+ (i *Emax / nStep)), 0));

    result4_1->clear();
    for (int i=0; i <nStep; i++)
        result4_1->insert(std::pair<G4double, G4int> ((Emax1+ (i *Emax2 / nStep)), 0));

    result4_2->clear();
    for (int i=0; i <nStep; i++)
        result4_2->insert(std::pair<G4double, G4int> (i *Emax1 / nStep, 0));

    result5->clear();
    for (int i=0; i <nStep; i++)
        result5->insert(std::pair<G4double, G4int> ((Emax2+ (i *Emax / nStep)), 0));

    result5_1->clear();
    for (int i=0; i <nStep; i++)
        result5_1->insert(std::pair<G4double, G4int> ((Emax1+ (i *Emax2 / nStep)), 0));

    result5_2->clear();
    for (int i=0; i <nStep; i++)
        result5_2->insert(std::pair<G4double, G4int> (i *Emax1 / nStep, 0));

}


void RunAct::EndOfRunAction(const G4Run *aRun)
{

    auto sum = new double *[nStep];
    for (int i = 0; i < nStep; i++) {
        sum[i] = new double[16];
    }


    fstream fout1("/mnt/hgfs/VMplayer/B_device/Source.txt", ios::out);
    for (auto it1: *result1)
        fout1 << it1.first << " " << it1.second << '\n';
    fout1.close();

    fstream fout2("/mnt/hgfs/VMplayer/B_device/Detector_No_1.txt", ios::out);
    for (auto it2: *result2)
        fout2 << it2.first << " " << it2.second << '\n';
    fout2.close();

    fstream fout3("/mnt/hgfs/VMplayer/B_device/Detector_No_2.txt", ios::out);
    for (auto it3: *result3)
        fout3 << it3.first << " " << it3.second << '\n';
    fout3.close();

    fstream fout4("/mnt/hgfs/VMplayer/B_device/Det_No_1_ 10keV - 10 MeV.txt", ios::out);
    for (auto it4: *result4)
        fout4 << it4.first << " " << it4.second << '\n';
    fout4.close();

    fstream fout4_1("/mnt/hgfs/VMplayer/B_device/Det_No_1_ 0.4eV - 10 keV.txt", ios::out);
    for (auto it4_1: *result4_1)
        fout4_1 << it4_1.first << " " << it4_1.second << '\n';
    fout4_1.close();

    fstream fout4_2("/mnt/hgfs/VMplayer/B_device/Det_No_1_ 0 - 0.4eV.txt", ios::out);
    for (auto it4_2: *result4_2)
        fout4_2 << it4_2.first << " " << it4_2.second << '\n';
    fout4_2.close();


    fstream fout5("/mnt/hgfs/VMplayer/B_device/Det_No_2_ 10keV - 10 MeV.txt", ios::out);
    for (auto it5: *result5)
        fout5 << it5.first << " " << it5.second << '\n';
    fout5.close();

    fstream fout5_1("/mnt/hgfs/VMplayer/B_device/Det_No_2_ 0.4eV - 10 keV.txt", ios::out);
    for (auto it5_1: *result5_1)
        fout5_1 << it5_1.first << " " << it5_1.second << '\n';
    fout5_1.close();

    fstream fout5_2("/mnt/hgfs/VMplayer/B_device/Det_No_2_ 0 - 0.4eV.txt", ios::out);
    for (auto it5_2: *result5_2)
        fout5_2 << it5_2.first << " " << it5_2.second << '\n';
    fout5_2.close();


    double E, Cnt;

    ifstream infile1;
    infile1.open("/mnt/hgfs/VMplayer/B_device/Detector_No_1.txt");
    for (int i = 0; i < nStep; i++) {
        infile1 >> E >> Cnt;
        sum[i][0] = E;
        sum[i][1]=Cnt;
    }
    sum[0][1]=0;
    infile1.close();

    ifstream infile2;
    infile2.open("/mnt/hgfs/VMplayer/B_device/Detector_No_2.txt");
    for (int i = 0; i < nStep; i++) {
        infile2 >> E >> Cnt;
        sum[i][2] = E;
        sum[i][3]=Cnt;
    }
    sum[0][3]=0;
    infile2.close();

    ifstream infile3;
    infile3.open("/mnt/hgfs/VMplayer/B_device/Det_No_1_ 10keV - 10 MeV.txt");
    for (int i = 0; i < nStep; i++) {
        infile3 >> E >> Cnt;
        sum[i][4] = E;
        sum[i][5]=Cnt;
    }
    infile3.close();

    ifstream infile4;
    infile4.open("/mnt/hgfs/VMplayer/B_device/Det_No_1_ 0.4eV - 10 keV.txt");
    for (int i = 0; i < nStep; i++) {
        infile4 >> E >> Cnt;
        sum[i][6] = E;
        sum[i][7]=Cnt;
    }
    infile4.close();

    ifstream infile5;
    infile5.open("/mnt/hgfs/VMplayer/B_device/Det_No_1_ 0 - 0.4eV.txt");
    for (int i = 0; i < nStep; i++) {
        infile5 >> E >> Cnt;
        sum[i][8] = E;
        sum[i][9]=Cnt;
    }
    infile5.close();

    ifstream infile6;
    infile6.open("/mnt/hgfs/VMplayer/B_device/Det_No_2_ 10keV - 10 MeV.txt");
    for (int i = 0; i < nStep; i++) {
        infile6 >> E >> Cnt;
        sum[i][10] = E;
        sum[i][11]=Cnt;
    }
    infile6.close();

    ifstream infile7;
    infile7.open("/mnt/hgfs/VMplayer/B_device/Det_No_2_ 0.4eV - 10 keV.txt");
    for (int i = 0; i < nStep; i++) {
        infile7 >> E >> Cnt;
        sum[i][12] = E;
        sum[i][13]=Cnt;
    }
    infile7.close();

    ifstream infile8;
    infile8.open("/mnt/hgfs/VMplayer/B_device/Det_No_2_ 0 - 0.4eV.txt");
    for (int i = 0; i < nStep; i++) {
        infile8 >> E >> Cnt;
        sum[i][14] = E;
        sum[i][15]=Cnt;
    }
    infile8.close();



    sum[0][9] = 0;

    double one = 0;
    double two = 0;

    for (int i=0; i<nStep; i++)
    {
        two+=sum[i][9];
    }

    sum[0][7] = two;

    for (int i=0; i<nStep; i++)
    {
        one+=sum[i][7];
    }

    sum[0][5] = one;


    one = 0;
    two = 0;

    sum[0][15] = 0;

    double three = 0;
    double four = 0;

    for (int i=0; i<nStep; i++)
    {
        three+=sum[i][15];
    }

    sum[0][13] = three;

    for (int i=0; i<nStep; i++)
    {
        four+=sum[i][13];
    }

    sum[0][11] = four;

    three = 0;
    four = 0;



    fstream fout6(foldername, ios::out);
    for (int i =0; i <nStep; i++)
    {
        for(int j=0; j<16; j++)
        {
            fout6 << sum[i][j] << '\t';
        }

        fout6 << '\n';
    }

    fout6.close();

    for (int i = 0; i < nStep; i++) { delete[] sum[i]; }



    /////////////////////// N O R M A L I S A T I O N      P R O C E S S  //////////////////////////////////////////////

   /* auto P1 = new double *[nStep];
    for (int i = 0; i < nStep; i++) {
        P1[i] = new double[nStep];
    }

    auto Sigma = new double[nStep];
    auto Energy = new double[nStep];
    auto Counts = new double[nStep];
    auto NormCounts = new double[nStep];
    auto NormCounts_1 = new double[nStep];

    double E, Cnt;

    double PI = 3.1415;

    ifstream infile1;

    infile1.open("/mnt/hgfs/VMplayer/B_device/Detector_No_1.txt");

    for (int i = 0; i < nStep; i++) {
        infile1 >> E >> Cnt;
        Energy[i] = E;
        Counts[i] = Cnt;
        Counts[0] = Counts[1];
        Energy[0] = 0.001;

    }

    infile1.close();

    double delta = Energy[10]-Energy[9];

    for (int i=0; i<nStep; i++)
    {
//        Sigma[i] = a+b/sqrt(Energy[i]);
//        Sigma[i] = 0.0001;
        Sigma[i] = 2.55*(sqrt(1000000*Energy[i]*w*F))/1000000;
    }

    for (int i = 0; i < nStep; i++)
    {
        for (int j = 0; j < nStep; j++)
        {

            P1[i][j] = (delta*Counts[j] / (sqrt(2 * PI * Sigma[i]))) *
                       exp(-1*(((Energy[i] - Energy[j]) * (Energy[i] - Energy[j])) /
                               (2 * Sigma[i])));

        }

    }

    double sum1 = 0;

    for (int i = 0; i < nStep; i++)
    {
        for (int j = 0; j < nStep; j++)
        {
            sum1 += P1[i][j];
        }

        NormCounts_1[i] = sum1;
        sum1 = 0;

    }

    double sum2 =0;

    for (int i=0; i<nStep; i++)
    {
        sum2+=delta*Counts[i];
    }

    double sum3 =0;

    for (int i=0; i<nStep; i++)
    {
        sum3+=delta*NormCounts_1[i];
    }

    for (int i=0; i<nStep; i++)
    {
        NormCounts[i]=(sum2/sum3)*NormCounts_1[i];
    }



        fstream fout4 ("/mnt/hgfs/VMplayer/B_device/Detector_1_Norm.txt", ios::out);


        for (int i = 0; i < nStep; i++) {

        fout4 << Energy[i] << '\t'<< NormCounts[i] << '\n';

        }
        fout4.close();


    ifstream infile2;

    infile2.open("/mnt/hgfs/VMplayer/B_device/Detector_No_2.txt");

    for (int i = 0; i < nStep; i++) {
        infile2 >> E >> Cnt;
        Energy[i] = E;
        Counts[i] = Cnt;
        Counts[0] = Counts[1];
        Energy[0] = 0.001;

    }

    infile1.close();

    for (int i = 0; i < nStep; i++)
    {
        for (int j = 0; j < nStep; j++)
        {

            P1[i][j] = (delta*Counts[j] / (sqrt(2 * PI * Sigma[i]))) *
                       exp(-1*(((Energy[i] - Energy[j]) * (Energy[i] - Energy[j])) /
                               (2 * Sigma[i])));

        }

    }

    double sum4 = 0;

    for (int i = 0; i < nStep; i++)
    {
        for (int j = 0; j < nStep; j++)
        {
            sum4 += P1[i][j];
        }

        NormCounts_1[i] = sum4;
        sum4 = 0;

    }

    double sum5 =0;

    for (int i=0; i<nStep; i++)
    {
        sum5+=delta*Counts[i];
    }

    double sum6 =0;

    for (int i=0; i<nStep; i++)
    {
        sum6+=delta*NormCounts_1[i];
    }

    for (int i=0; i<nStep; i++)
    {
        NormCounts[i]=(sum5/sum6)*NormCounts_1[i];
    }



    fstream fout5 ("/mnt/hgfs/VMplayer/B_device/Detector_2_Norm.txt", ios::out);


    for (int i = 0; i < nStep; i++) {

        fout5 << Energy[i] << '\t'<< NormCounts[i] << '\n';

    }
    fout5.close();


    for (int i = 0; i < nStep; i++) { delete[] P1[i]; }

    delete [] Energy;
    delete [] Counts;
    delete [] NormCounts;
    delete [] NormCounts_1;
    delete [] Sigma;
*/

}

void RunAct::AddEvent1(G4double energy1)
{
    auto it1 = result1->lower_bound(energy1);
    it1->second++;
}

void RunAct::AddEvent2(G4double energy2)
{
    auto it2 = result2->lower_bound(energy2);
    it2->second++;

}


void RunAct::AddEvent3(G4double energy3)
{
    auto it3 = result3->lower_bound(energy3);
    it3->second++;

}

void RunAct::AddEvent4(G4double energy4)
{
    auto it4 = result4->lower_bound(energy4);
    it4->second++;

}

void RunAct::AddEvent4_1(G4double energy4_1)
{
    auto it4_1 = result4_1->lower_bound(energy4_1);
    it4_1->second++;

}

void RunAct::AddEvent4_2(G4double energy4_2)
{
    auto it4_2 = result4_2->lower_bound(energy4_2);
    it4_2->second++;

}

void RunAct::AddEvent5(G4double energy5)
{
    auto it5 = result5->lower_bound(energy5);
    it5->second++;

}

void RunAct::AddEvent5_1(G4double energy5_1)
{
    auto it5_1 = result5_1->lower_bound(energy5_1);
    it5_1->second++;

}

void RunAct::AddEvent5_2(G4double energy5_2)
{
    auto it5_2 = result5_2->lower_bound(energy5_2);
    it5_2->second++;

}


void RunAct::SetNewPath(G4String newPath) {
    foldername = newPath;

}
