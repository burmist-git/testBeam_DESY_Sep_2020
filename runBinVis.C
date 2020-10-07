{
  gROOT->LoadMacro("visBin.C");
  gROOT->LoadMacro("./wfSimulation/src/waveformSimple.cpp");
  visBin t("../root_data/Run_001_Data_9_22_2020_Binary/Run_001_Data_9_22_2020_Binary.bin.root");
  Int_t evID;
  Int_t chID;
  TString key_lineOn;
  TString key_printInfoTrue;
  TString fileAnaSetups;
  evID = 39;
  chID = 0;
  key_lineOn = "yes";
  key_printInfoTrue = "printInfoTrue";
  //t.DrawOneChannel(evID, chID);
  fileAnaSetups = "anaSetup.dat";
  t.DrawOneChannel_waveformSimple(evID, chID, key_lineOn, key_printInfoTrue,fileAnaSetups);
  //t.Loop();
}

