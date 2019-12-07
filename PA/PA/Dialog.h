#pragma once
#include "TxtLayout.h"
#include "SoundManager.h"
class Dialog : public TxtLayout
{

	SoundManager c;

	string openTxt[17] = { "lake.txt","lake2.txt" ,"lake3.txt" ,"lake4.txt" ,"lake5.txt" ,"lake6.txt"
	"lake7.txt" ,"lake8.txt" ,"lake9.txt" ,"lake10.txt" ,"lake11.txt" ,"lake12.txt"
	"lake13.txt" ,"lake14.txt" ,"lake15.txt" ,"lake16.txt" ,"lake17.txt" };


	string oroTxt[8] = { "oro1.txt","oro2.txt" ,"oro3.txt","oro4.txt" ,"oro5.txt",
	"oro6.txt","oro7.txt" ,"oro8.txt" };
	string oroClear[4] = { "oroC1.txt","oroC2.txt","oroC3.txt","oroC4.txt" };
	string oroFail[4] = { "oroF1.txt","oroF2.txt","oroF3.txt","oroF4.txt" };


	string DrTxt[6] = { "dr1.txt","dr2.txt" ,"dr3.txt" ,"dr4.txt" ,"dr5.txt","dr6.txt" };
	string DrClear[5] = { "drC1.txt","drC2.txt" ,"drC3.txt" ,"drC4.txt","drC5.txt" };
	string DrFail[4] = { "drF1.txt","drF2.txt" ,"drF3.txt" ,"drF4.txt" };


	string DcTxt[6] = { "dc1.txt","dc2.txt","dc3.txt","dc4.txt","dc5.txt","dc6.txt" };
	string DcClear[4] = { "dcC1.txt","dcC2.txt","dcC3.txt","dcC4.txt" };
	string DcFail[4] = { "dcF1.txt","dcF2.txt","dcF3.txt","dcF4.txt" };

	string JsTxt[3] = { "js1.txt","js2.txt","js3.txt" };
	string JsClear[4] = { "jsC1.txt","jsC2.txt","jsC3.txt","jsC4.txt" };
	string JsFail[4] = { "jsF1.txt","jsF2.txt","jsF3.txt","jsF4.txt" };

	string SdTxt[6] = { "sd1.txt","sd2.txt","sd3.txt","sd4.txt","sd5.txt","sd6.txt" };
	string SdClear[4] = { "sdC1.txt","sdC2.txt","sdC3.txt","sdC4.txt" };
	string SdFail[4] = { "sdF1.txt","sdF2.txt","sdF3.txt","sdF4.txt" };

	string JmTxt[6] = { "jm1.txt","jm2.txt","jm3.txt","jm4.txt","jm5.txt","jm6.txt" };
	string JmClear[4] = { "jmC1.txt","jmC2.txt","jmC3.txt","jmC4" };
	string JmFail[4] = { "jmF1.txt","jmF2.txt","jmF3.txt","jmF4.txt" };

	string JjTxt[6] = { "jj1.txt","jj2.txt","jj3.txt","jj4.txt","jj5.txt","jj6.txt" };
	string JjClear[4] = { "jjC1.txt","jjC2.txt","jjC3.txt","jjC4.txt" };
	string JjFail[4] = { "jjF1.txt","jjF2.txt","jjF3.txt","jjF4.txt" };

	string MjTxt[6] = { "mj1.txt","mj2.txt","mj3.txt","mj4.txt","mj5.txt","mj6.txt" };
	string MjClear[4] = { "mjC1.txt","mjC2.txt","mjC3.txt","mjC4.txt" };
	string MjFail[4] = { "mjF1.txt","mjF2.txt","mjF3.txt","mjF4.txt" };

public:
	void openPrint();

	void OroPrint();
	void OroClear();
	void OroFail();

	void drPrint();
	void drClear();
	void drFail();

	void dcPrint();
	void dcClear();
	void dcFail();

	void jsPrint();
	void jsClear();
	void jsFail();

	void sdPrint();
	void sdClear();
	void sdFail();

	void jmPrint();
	void jmClear();
	void jmFail();

	void jjPrint();
	void jjClear();
	void jjFail();

	void mjPrint();
	void mjClear();
	void mjFail();

	void ending();
};
