// main02.cc is a part of the PYTHIA event generator.
// Copyright (C) 2020 Torbjorn Sjostrand.
// PYTHIA is licenced under the GNU GPL v2 or later, see COPYING for details.
// Please respect the MCnet Guidelines, see GUIDELINES for details.

// This is a simple test program. It fits on one slide in a talk.
// It studies the pT_Z spectrum at the Tevatron.


#include "Pythia8/Pythia.h"
#include <TH1F.h>
#include <TFile.h>

using namespace Pythia8;
int main() {
  TFile f("main02.root","RECREATE");
  TH1F h_PTZ("h_pTZ","PT of Z bosons",49,0,300);
  TH1F h_MZ("h_MZ","Mass of Z bosons",200,50,150);


  // Generator. Process selection. Tevatron initialization. Histogram.
  Pythia pythia;
  pythia.readString("Beams:idB = -2212");
  pythia.readString("Beams:eCM = 1960.");
  pythia.readString("WeakSingleBoson:ffbar2gmZ = on");
  pythia.readString("PhaseSpace:mHatMin = 80.");
  pythia.readString("PhaseSpace:mHatMax = 120.");
  pythia.init();

  // Begin event loop. Generate event. Skip if error. List first one.
  for (int iEvent = 0; iEvent < 100000; ++iEvent) {
    if (!pythia.next()) continue;
    // Loop over particles in event. Find last Z0 copy. Fill its pT.
    int iZ = 0;
    for (int i = 0; i < pythia.event.size(); ++i)
      if (pythia.event[i].id() == 23) iZ = i;
    h_PTZ.Fill( pythia.event[iZ].pT() );
    h_MZ.Fill( pythia.event[iZ].m() );

  // End of event loop. Statistics. Histogram. Done.

  }
  pythia.stat();
   h_PTZ.Write();
   h_MZ.Write();
  return 0;
}
