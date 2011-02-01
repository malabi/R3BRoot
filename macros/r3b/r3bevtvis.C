r3bevtvis()
{
   // ----  Load libraries   -------------------------------------------------
  gROOT->LoadMacro("$VMCWORKDIR/gconfig/basiclibs.C");
  basiclibs();
  gSystem->Load("libGeoBase");
  gSystem->Load("libParBase");
  gSystem->Load("libBase");
  gSystem->Load("libMCStack");
  gSystem->Load("libGen");

  // Load FairRoot base Event Display Libs
  gSystem->Load("libEve");
  gSystem->Load("libEventDisplay");

  //----  Load R3B specific libraries ---------------------------------------
  gSystem->Load("libR3Bbase");
  gSystem->Load("libR3BGen");
  gSystem->Load("libR3BPassive");
  gSystem->Load("libR3BData");
  gSystem->Load("libR3BCal");
  gSystem->Load("libR3BCalo");
  gSystem->Load("libR3BDch");
  gSystem->Load("libR3BGfi");
  gSystem->Load("libR3BLand");
  gSystem->Load("libR3BmTof");
  gSystem->Load("libR3BTof");
  gSystem->Load("libR3BTra");

  //----  Load R3B vis. specific libraries --------------------------  
  gSystem->Load("libR3BEvtVis");




                                     
  // -----   Reconstruction run   -------------------------------------------
  FairRunAna *fRun= new FairRunAna();
  TFile* file = new TFile("r3bpar.root");
  file->Get("FairBaseParSet"); 

 // -----   Runtime database   ---------------------------------------------
  FairRuntimeDb* rtdb = fRun->GetRuntimeDb();
  FairParRootFileIo* parIn = new FairParRootFileIo();
  parIn->open("r3bpar.root");
  rtdb->print();

  fRun->SetInputFile("r3bsim.root");
  fRun->SetOutputFile("test.root");
  fRun->LoadGeometry();
  
  R3BEventManager *fMan= new R3BEventManager();
  R3BMCTracks *Track =  new R3BMCTracks ("Monte-Carlo Tracks");

  fMan->AddTask(Track);
  fMan->Init();                     
  
}