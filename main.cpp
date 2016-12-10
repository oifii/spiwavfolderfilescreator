#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

#include <assert.h>

//utility program for spimidisampler
//program uses files "navfolders_*.txt" to create files "navfolder_*.txt"
//created "navfolder_*.txt" files can then be copied to spimidisampler application folders
int main(int argc, char **argv)
{
	//take no arguments for now
	if(argc>1)
	{
		assert(false); //todo
		return 1;
	}

	///////////////////////////////////////////////////////////
	//1) execute cmd line to get all specified folder's folders
	///////////////////////////////////////////////////////////
	string quote = "\"";
	string pathfilter;
	//string path="C:\\Program Files (x86)\\Native Instruments\\Sample Libraries\\Kontakt 3 Library\\Urban Beats\\Z - Samples";
	//string path="C:\\Program Files (x86)\\Native Instruments\\Sample Libraries\\Kontakt 3 Library\\Synth\\Z - Samples\\Bass Samples";
	//string path="C:\\Program Files (x86)\\Native Instruments\\Sample Libraries\\Kontakt 3 Library\\Synth\\Z - Samples\\Choir Samples";
	//string path="C:\\Program Files (x86)\\Native Instruments\\Sample Libraries\\Kontakt 3 Library\\Synth\\Z - Samples\\Classic Waveform Samples";
	//string path= "C:\\Program Files (x86)\\Native Instruments\\Sample Libraries\\Kontakt 3 Library\\Synth\\Z - Samples\\Lead Samples";
	//string path = "C:\\Program Files (x86)\\Native Instruments\\Sample Libraries\\Kontakt 3 Library\\Synth\\Z - Samples\\Mallet Samples";
	//string path = "C:\\Program Files (x86)\\Native Instruments\\Sample Libraries\\Kontakt 3 Library\\Synth\\Z - Samples\\Pad Samples";
	//string path = "C:\\Program Files (x86)\\Native Instruments\\Sample Libraries\\Kontakt 3 Library\\Synth\\Z - Samples\\Sequencer Samples";
	string path = "C:\\Program Files (x86)\\Native Instruments\\Sample Libraries\\Kontakt 3 Library\\Synth\\Z - Samples\\Synth Drums Samples";

	pathfilter = path + "\\*.";
	string systemcommand;
	systemcommand = "DIR " + quote + pathfilter + quote + "/B /O:N > wffc_foldernames.txt"; //wsip tag standing for wav set (library) instrumentset (class) populate (function)
#ifdef _DEBUG
	cout << systemcommand << endl;
#endif //_DEBUG
	system(systemcommand.c_str());

	////////////////////////
	//2) load in all folders
	////////////////////////
	vector<string> foldervector;
	ifstream ifs("wffc_foldernames.txt");
	string temp;
	while(getline(ifs,temp))
	{
		//foldervector.push_back(path + "\\" + temp);
		foldervector.push_back(temp);
	}

	//////////////////////////////////////
	//3) for each one of these folders ...
	//////////////////////////////////////
	vector<string>::iterator it;
	for(it=foldervector.begin(); it<foldervector.end(); it++)
	{
		string quote = "\"";
		string pathfilter;
		pathfilter = path + "\\" + *it + "\\*.WAV";
		string outputfilename = "wavfolder_synth-synthdrums-" + (*it) + ".txt";
		string systemcommand;
		//systemcommand = "DIR " + quote + pathfilter + quote + "/S /B /O:N > wffc_wavfilenames.txt"; 
		systemcommand = "DIR " + quote + pathfilter + quote + "/S /B /O:N > " + quote + outputfilename + quote; 
	#ifdef _DEBUG
		cout << systemcommand << endl;
	#endif //_DEBUG
		system(systemcommand.c_str());
	}
	return 0;
}