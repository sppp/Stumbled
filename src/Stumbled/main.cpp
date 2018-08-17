#include "Stumbled.h"

Stumbled::Stumbled()
{
	CtrlLayout(*this, "Stumbled");
	
	
	LoadThis();
	
	if (urls.IsEmpty()) {
		for(int i = 1; i < 14; i++) {
			String path = GetDataFile(IntStr(i) + ".json");
			String s = LoadFile(path);
			ValueMap js = ParseJSON(s);
			ValueMap likes = js.GetAdd("likes");
			ValueMap values = likes.GetAdd("values");
			for(int j = 0; j < values.GetCount(); j++) {
				ValueMap like = values[j];
				Value url = like.GetAdd("url");
				urls.Add(url);
			}
		}
	}
	
	
	start.SetData(begin);
	
	stumble <<= THISBACK(Stumble);
	
}

void Stumbled::Stumble() {
	int count = 4;
	
	begin = start.GetData();
	
	String cmd = "C:\\Program Files\\Mozilla Firefox\\firefox.exe ";
	for(int i = 0; i < count; i++) {
		int j = begin + i;
		if (j < urls.GetCount())
			cmd += "\"" + urls[j] + "\" ";
	}
	LOG(cmd);
	String out;
	Sys(cmd, out);
	
	begin += count;
	start.SetData(begin);
	StoreThis();
}

GUI_APP_MAIN
{
	Stumbled().Run();
}
