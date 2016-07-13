#ifndef DATAPROCESSOR_H_
#define DATAPROCESSOR_H_

#include "TH1D.h"
#include <omp.h>
#include <iostream>
#include <sstream>
#include "DataSet.h"
#include "EventSizeException.h"
#include "TFile.h"
#include "TTree.h"



/**
 * A class, that processes raw data measured by an FADC, that comes as
 * *.root files. It offers functions to integrate histograms, calculate
 * time-dependant currents and deposited charge in a drifttube detector.
 * Makes use of ROOT libraries by CERN.
 * 
 * @author Stefan
 * @date May 30, 2016
 * @version 0.1 
 */
class DataProcessor
{
public:
	DataProcessor();
	virtual ~DataProcessor();
	
	Double_t computeIntegral(TH1D& data);
	TH1D* integrate(TH1D* data);
	DataSet* integrateAll(DataSet* data);
	double findMinimum(TH1D* data);
	int findSignalStart(TH1D* data, int threshold);
	TH1D* calculateDriftTimeSpectrum(DataSet* data);

	void calibrate(TString triggerDataFile);
};

#endif //DATAPROCESSOR_H_
