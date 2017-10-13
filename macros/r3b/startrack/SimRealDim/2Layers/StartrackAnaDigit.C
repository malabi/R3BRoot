//  -------------------------------------------------------------------------
//
//   ----- General Macro for R3B STARTRACKER Analysis
//         Author: Nick Ashwood <n.i.ashwood@bham.ac.uk>
//         Last Update: 28/05/14 Marc Labiche
//         Comments: Adapted from califaAna.C
//			Runs the STARTRACKER Hit Finder. Outputs a root file with 
//			a collection (TClonesArray) of R3BTraHits
//
//  -------------------------------------------------------------------------
//
//   Usage: 
//        > root -l startrackerAnaDigit.C
//                         
//
//  -------------------------------------------------------------------------


void StartrackAnaDigit() {
	
	
	// Input and output files
	TString inFile = "../../r3bsim.root";
	TString parFile = "../../r3bpar.root";
	TString outFile = "startrackerAnaDigit.root";
	
	// In general, the following parts need not be touched
	// ========================================================================
		
	// -----   Timer   --------------------------------------------------------
	TStopwatch timer;
	timer.Start();
	// ------------------------------------------------------------------------
		
	
	// -----   Create analysis run   ----------------------------------------
	FairRunAna* fRun = new FairRunAna();
	fRun->SetInputFile(inFile);
	fRun->SetOutputFile(outFile);
      		
	// -----   Runtime database   ---------------------------------------------
	/*
	FairRuntimeDb* rtdb = fRun->GetRuntimeDb();
	FairParRootFileIo* parIn = new FairParRootFileIo();
	parIn->open("r3bpar.root");
	rtdb->print();
	*/
	// -----  Analysis routines for STARTRACKER	
		
	//R3BSTaRTraDigit* startraHF = new R3BSTaRTraDigit();  // obsolete since 2017
	R3BStartrackDigit* startraHF = new R3BStartrackDigit();

	//Selecting the geometry version
	// 0- STARTRACKER 5.0.
	// ...
	//startraHF->SelectGeometryVersion(15);          
	startraHF->SetDetectionThreshold(0.000000);  // 0 KeV
	//startraHF->SetExperimentalResolution(0.00002);  // sigma= 20 keV
	//startraHF->SetExperimentalResolution(0.00001);  // sigma= 10 keV
	//startraHF->SetDetectionThreshold(0.000040);//40 KeV
	startraHF->SetExperimentalResolution(0.00005);  // 50 keV

	fRun->AddTask(startraHF);
	
	// Number of events to process
	Int_t nEvents = 10000;

	fRun->Init();                     
	fRun->Run(0, nEvents);	
        delete fRun;

	// -----   Finish   -------------------------------------------------------
	timer.Stop();
	Double_t rtime = timer.RealTime();
	Double_t ctime = timer.CpuTime();
	cout << endl << endl;
	cout << "Macro finished succesfully." << endl;
	cout << "Real time " << rtime << " s, CPU time " << ctime << " s" << endl;
	cout << endl;
	// ------------------------------------------------------------------------
       	
}
