void eventDisplay()
{
  FairRunAna *fRun= new FairRunAna();
  
  FairRuntimeDb* rtdb = fRun->GetRuntimeDb();
  FairParRootFileIo*  parIo1 = new FairParRootFileIo();
<<<<<<< HEAD
  parIo1->open("r3bpar.root");
//  parIo1->open("par.root");
  rtdb->setFirstInput(parIo1);
  rtdb->print();
  
  fRun->SetInputFile("r3bsim.root");
//  fRun->SetInputFile("sim.root");
=======
//  parIo1->open("r3bpar.root");
  parIo1->open("par.root");
  rtdb->setFirstInput(parIo1);
  rtdb->print();
  
//  fRun->SetInputFile("r3bsim.root");
  fRun->SetInputFile("sim.root");
>>>>>>> b351b5200607b39d0f67b8cb57b4d8dc33bd5aff
  fRun->SetOutputFile("test.root");
  
  FairEventManager *fMan= new FairEventManager();
  FairMCTracks *Track =  new FairMCTracks ("Monte-Carlo Tracks");
  FairMCPointDraw *LandPoints =   new FairMCPointDraw ("LandPoint",kOrange,  kFullSquare);
  
  fMan->AddTask(Track);
  
  fMan->AddTask(LandPoints);
  
  fMan->Init();
}
