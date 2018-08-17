#ifndef _Stumbled_Stumbled_h
#define _Stumbled_Stumbled_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <Stumbled/Stumbled.lay>
#include <CtrlCore/lay.h>

class Stumbled : public WithStumbledLayout<TopWindow> {
	Vector<String> urls;
	int begin = 0;
	
public:
	typedef Stumbled CLASSNAME;
	Stumbled();
	
	void Stumble();
	
	void Serialize(Stream& s) {s % urls % begin;}
	void LoadThis() {LoadFromFile(*this, ConfigFile("Stumbled.bin"));}
	void StoreThis() {StoreToFile(*this, ConfigFile("Stumbled.bin"));}
};

#endif
