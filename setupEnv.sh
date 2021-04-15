
#bu dosyayi ben kendi pcme gore hazirladim

# bu bize fizikle alakali programlarin environment setuplarini  yapiyor ...

# asagidaki pathleri kendi sisteminize gore degistirmelisiniz

#PYTHIA8


#asagida sag taraftaki pathi kendinize gore degistririn
export PYTHIA8=/storage/ATLAS/builds/pythia8245/


export PYTHIA8DATA=${PYTHIA8}/share/Pythia8/xmldoc/

#setup ROOT

#root ayari icin asagida sg taraftaki pathi kendinize gore ayarlayin
source /storage/ATLAS/builds/root-v6-23-01/bin/thisroot.sh
#source /storage/ATLAS/builds/root-v6-22-00/bin/thisroot.sh

#setup Delphes
export DELPHES=/storage/ATLAS/builds/delphes
export PATH=$PATH:${DELPHES}


export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${DELPHES}
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${PYTHIA8}/lib
