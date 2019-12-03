#pragma once
class Block
{
public:
	char block[7][4][4][4] = {
		//막대모양
		1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0, 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0, 1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0, 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,

		//네모모양
		1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0, 1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0, 1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0, 1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,

		//'ㅓ' 모양
		0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0, 1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0, 1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0, 0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,

		//'ㄱ'모양
		1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0, 1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0, 1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0, 0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,

		//'ㄴ' 모양
		1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0, 1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0, 0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0, 1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,

		//'Z' 모양
		1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0, 0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0, 1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0, 0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,

		//'S' 모양
		0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0, 1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0, 0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0, 1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0

	};
public:
	Block();
	~Block();
};

