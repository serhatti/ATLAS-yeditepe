#include <iostream>
#include <TH1F.h>
#include <TFile.h>
#include <TRandom3.h>

//Example histogram fillings we have done during our meetings
//Two histogrms are filled and written into a root file
int main(){

    //number of entries for histograms
    int N=500000;
    TFile f("hist_randfill.root","RECREATE");
    TH1F h1("h1","gaussian",100,-50,50);
    TH1F h2("h2","uniform",50,0,50);

    //declare a random number generator
    TRandom3 rnd;

    for(int i=0;i<N;i++){
        h1.Fill(rnd.Gaus(11,7));
        h2.Fill(rnd.Uniform(-50,50));
    }
    h1.Write();
    h2.Write();
    std::cout<<"Done"<<std::endl;
    return 0;
}