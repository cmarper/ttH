#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <utility>

using namespace std;

TString getInputFile(const TString _samplename){

        TString _inputFile;

    	if (_samplename == "DYJets_M10to50") _inputFile = "PU_weights_2017/DYJets_M10to50.txt";
	else if (_samplename == "DYJets_M50") _inputFile = "PU_weights_2017/DYJets_M50.txt";
	else if (_samplename == "DYJets_M50_ext") _inputFile = "PU_weights_2017/DYJets_M50_ext.txt";
	else if (_samplename == "ggHZZ4l") _inputFile = "PU_weights_2017/ggHZZ4l.txt";
	else if (_samplename == "ST_sLep") _inputFile = "PU_weights_2017/ST_sLep.txt";
	else if (_samplename == "ST_sLep_psw") _inputFile = "PU_weights_2017/ST_sLep_psw.txt";
	else if (_samplename == "ST_tT") _inputFile = "PU_weights_2017/ST_tT.txt";
	else if (_samplename == "ST_tTbar") _inputFile = "PU_weights_2017/ST_tTbar.txt";
	else if (_samplename == "ST_tWT") _inputFile = "PU_weights_2017/ST_tWT.txt";
	else if (_samplename == "ST_tWTbar") _inputFile = "PU_weights_2017/ST_tWTbar.txt";
	else if (_samplename == "TTGJets") _inputFile = "PU_weights_2017/TTGJets.txt";
	else if (_samplename == "ttHJetTobb") _inputFile = "PU_weights_2017/ttHJetTobb.txt";
	else if (_samplename == "ttHJetToNonbb") _inputFile = "PU_weights_2017/ttHJetToNonbb.txt";
	else if (_samplename == "ttHToNonbb") _inputFile = "PU_weights_2017/ttHToNonbb.txt";
	else if (_samplename == "TTToDiLep") _inputFile = "PU_weights_2017/TTToDiLep.txt";
	else if (_samplename == "TTToDiLep_psw") _inputFile = "PU_weights_2017/TTToDiLep_psw.txt";
	else if (_samplename == "TTToHad") _inputFile = "PU_weights_2017/TTToHad.txt";
	else if (_samplename == "TTToHad_psw") _inputFile = "PU_weights_2017/TTToHad_psw.txt";
	else if (_samplename == "TTToSemiLep") _inputFile = "PU_weights_2017/TTToSemiLep.txt";
	else if (_samplename == "TTToSemiLep_psw") _inputFile = "PU_weights_2017/TTToSemiLep_psw.txt";
	else if (_samplename == "TTTT") _inputFile = "PU_weights_2017/TTTT.txt";
	else if (_samplename == "TTW") _inputFile = "PU_weights_2017/TTW.txt";
	else if (_samplename == "TTW_psw") _inputFile = "PU_weights_2017/TTW_psw.txt";
	else if (_samplename == "TTWW") _inputFile = "PU_weights_2017/TTWW.txt";
	else if (_samplename == "TTZ") _inputFile = "PU_weights_2017/TTZ.txt";
	else if (_samplename == "TTZ_M1to10") _inputFile = "PU_weights_2017/TTZ_M1to10.txt";
	else if (_samplename == "tZq") _inputFile = "PU_weights_2017/tZq.txt";
	else if (_samplename == "WJets") _inputFile = "PU_weights_2017/WJets.txt";
	else if (_samplename == "WW") _inputFile = "PU_weights_2017/WW.txt";
	else if (_samplename == "WWd") _inputFile = "PU_weights_2017/WWds.txt";
	else if (_samplename == "WWTo2L2Nuds") _inputFile = "PU_weights_2017/WWTo2L2Nuds.txt";
	else if (_samplename == "WWW") _inputFile = "PU_weights_2017/WWW.txt";
	else if (_samplename == "WWZ") _inputFile = "PU_weights_2017/WWZ.txt";
	else if (_samplename == "WZ") _inputFile = "PU_weights_2017/WZ.txt";
	else if (_samplename == "WZTo3LNu") _inputFile = "PU_weights_2017/WZTo3LNu.txt";
	else if (_samplename == "WZZ") _inputFile = "PU_weights_2017/WZZ.txt";
	else if (_samplename == "ZZ") _inputFile = "PU_weights_2017/ZZ.txt";
	else if (_samplename == "ZZ_ext") _inputFile = "PU_weights_2017/ZZ_ext.txt";
	else if (_samplename == "ZZZ") _inputFile = "PU_weights_2017/ZZZ.txt";

        return _inputFile;

}

float getPUweight(int nPU, bool isMC, const TString samplename)
{
    int nInt_file;
    float PUweight_file;
    float PU_weight = 0;
   
    ifstream inputFile(getInputFile(samplename));
   
    while (inputFile >> nInt_file >> PUweight_file)
    {
        if( nPU == nInt_file ) PU_weight = PUweight_file;
    }
    return PU_weight;
}

