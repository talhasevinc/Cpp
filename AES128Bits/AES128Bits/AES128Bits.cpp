/*

  AUTHOR:TALHA SEVİNÇ

*/


#include <cstdio>
#include <iostream>
#include <string>
#include<limits>
#include<ios>
#define numberRound 10

int SBOX[256] =
{
	0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,  //0-15
	0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,  //16-31
	0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,  //32-47
	0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,  //48-63
	0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,  //64-79
	0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,  //80-95
	0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,  //96-111
	0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,  //112-127
	0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,  //128-143
	0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,  //144-159
	0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,  //160-175
	0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,  //176-191
	0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,  //192-207
	0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,  //208-223
	0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,  //224-239
	0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16   //240-255
};

int INV_SBOX[256] =
{
	0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,  //0-15
	0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,  //16-31
	0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,  //32-47
	0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,  //48-63
	0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,  //64-79
	0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,  //80-95
	0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,  //96-111
	0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,  //112-127
	0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,  //128-143
	0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,  //144-159
	0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,  //160-175
	0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,  //176-191
	0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,  //192-207
	0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,  //208-223
	0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,  //224-239
	0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D   //240-255
};

uint8_t GeneralKey[4][44] =
{ 
 { 0x54, 0x41, 0x49, 0x52, 0xd6, 0x97, 0xde, 0x8c, 0xcc, 0x5b, 0x85, 0x9, 0xd, 0x56, 0xd3, 0xda, 0x8e, 0xd8, 0xb, 0xd1, 0x3f, 0xe7, 0xec, 0x3d, 0xd6, 0x31, 0xdd, 0xe0, 0xe2, 0xd3, 0xe, 0xee, 0x4b, 0x98, 0x96, 0x78, 0x2f, 0xb7, 0x21, 0x59, 0xf3, 0x44, 0x65, 0x3c},
 { 0x41, 0x53, 0x4e, 0x41, 0x68, 0x3b, 0x75, 0x34, 0x7d, 0x46, 0x33, 0x7, 0xbc, 0xfa, 0xc9, 0xce, 0xc, 0xf6, 0x3f, 0xf1, 0x2a, 0xdc, 0xe3, 0x12, 0xe7, 0x3b, 0xd8, 0xca, 0x65, 0x5e, 0x86, 0x4c, 0xff, 0xa1, 0x27, 0x6b, 0x56, 0xf7, 0xd0, 0xbb, 0x4c, 0xbb, 0x6b, 0xd0},
 { 0x4c, 0x45, 0x43, 0x4c, 0x65, 0x20, 0x63, 0x2f, 0xb1, 0x91, 0xf2, 0xdd, 0x42, 0xd3, 0x21, 0xfc, 0x2d, 0xfe, 0xdf, 0x23, 0x82, 0x7c, 0xa3, 0x80, 0x4e, 0x32, 0x91, 0x11, 0x85, 0xb7, 0x26, 0x37, 0x11, 0xa6, 0x80, 0xb7, 0xd2, 0x74, 0xf4, 0x43, 0xc6, 0xb2, 0x46, 0x5},
 { 0x48, 0x56, 0x4b, 0x4c, 0x48, 0x1e, 0x55, 0x19, 0x2c, 0x32, 0x67, 0x7e, 0x2d, 0x1f, 0x78, 0x6, 0x7a, 0x65, 0x1d, 0x1b, 0x44, 0x21, 0x3c, 0x27, 0x63, 0x42, 0x7e, 0x59, 0x82, 0xc0, 0xbe, 0xe7, 0xaa, 0x6a, 0xd4, 0x33, 0x16, 0x7c, 0xa8, 0x9b, 0xdd, 0xa1, 0x9, 0x92},
};


int mixArray[4][4] = { {0x02, 0x03, 0x01, 0x01},{0x01,0x02,0x03,0x01},{0x01,0x01,0x02,0x03}, {0x03, 0x01, 0x01, 0x02}};
uint8_t Key[4][4] = {{  0x54,0x41,0x49,0x52  },{  0x41,0x53,0x4E,0x41  },{ 0x4C,0x45,0x43,0x4C }, { 0x48,0x56,0x4B,0x4C  }};
//uint8_t Key[4][4] = { { 0x54, 0x73, 0x20, 0x67  },{  0x68, 0x20, 0x4B, 0x20  },{ 0x61, 0x6D, 0x75, 0x46 }, {0x74, 0x79, 0x6E, 0x75 } };
const uint8_t Rcon[11] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 }; 
uint8_t GeneralKeyAll[4][44];
int printCount = 1;
int KeyCounter = 0;
int tempArray[4];
int trBuf[16] = { 0x54, 0x77, 0x6F , 0x20 , 0x4F , 0x6E , 0x65 , 0x20 , 0x4E , 0x69 , 0x6E , 0x65 , 0x20 , 0x54 , 0x77 , 0x6F };
int message[16]    ;//= { 0x74, 0x17, 0x3F , 0x26 , 0x1F , 0x1E , 0x35 , 0x25 , 0xAE , 0x6E , 0xBA , 0x61 , 0x20 , 0x12 , 0x32 , 0x5F  }
int rawData[16];
int CryptedData[16];
int stateMatrix[4][4];
uint8_t AESEncrypte[16];
int reverseStateMatrix[4][4];
int DecryptedData[16];

void convertDataToState();
void AESEncrypt(int *arrayS,int arraySize);
void Subbytes(void);
void ShiftRows(void);
void MixColumns(void);
void mixSubCol(int section);
void AddRoundKey(int selection);
void KeyExtension(void);
void GFunction(int *lastWord,int selection);
void convertStateToData();
void printArray(int selection);
void printKeySchedule(int select);

void ConvReverseToData();
void miniReverseMix(int section);
void ReverseShift();
void ReverseSubBytes();
void ReverseMixColumns();
void AESDecrypte(int *cryptedDatas);

int mul14(int a);
int mul13(int a);
int mul11(int a);
int mult9(int a);
int mul2 (int a);
int mul3 (int a);

void UserInterface();
void decodeDecryptedData();
int inquire();
void clear();

int main()
{

	
	//KeyExtension();
	//printKeySchedule(44);

	
	int select = 1;
	char userChar[21];
	
	while (select)
	{
		system("cls"); clear(); printf("\n");		
		UserInterface();		
		select=inquire();

	}
	

}

void printArray(int selection)
{
	printf("****************************************\n");
	if (selection == 0)
	{
		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)  printf("%x\t ", stateMatrix[i][j]);
			printf("\n");
			
			
		}

		printf("  %d x %d =%d   ", printCount, 16, printCount * 16);
		printCount++;
		printf("\n");
	}

	else if (selection == 1)
	{
		printf("Raw Data:");
		for (int i = 0; i < 16; i++)
			printf(" %x ", rawData[i]);
				

	}

	else if (selection == 2)
	{
		printf("Crypted Data(HEX Format):");
		for (int i = 0; i < 16; i++)
			printf(" %x ", CryptedData[i]);
		printf("\n\n");
		

		printf("Crypted Data(String Format):");
		for (int i = 0; i < 16; i++)
			printf(" %c ", (char)CryptedData[i]);
		printf("\n");
		
	}

	else if (selection == 3)
	{
		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) printf("%x\t", reverseStateMatrix[i][j]);
			printf("\n");
		}
	}
	else if (selection == 4)
	{
		printf("\nDecrypted Data(HEX Format):");
		for (int i = 0; i < 16; i++)
			printf(" %x ", DecryptedData[i]);
	}
	else if (selection == 5)
	{
		printf("Original Data:");
		for (int i = 0; i < 16; i++)
			printf(" %x ", trBuf[i]);
	}
	else if (selection == 6)
	{
		printf("Original Datas(HEX Format):{ "); 
		for (int i = 0; i < 16; i++) 
		{ 
			if (message[i] != 0 || 1) 
			{ 
				printf(" %x, ", message[i]); 
			}
		}
		printf("} \n\n");
	}
	else if (selection == 7)
	{
		for (int i = 0; i < 4; i++) 
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%x\t", reverseStateMatrix[i][j]);
			}
			printf("\n");
		}
	}
	
}
void printKeySchedule(int select)
{
	printf("Extended Key:\n");
	for (int i = 0; i < 4; i++)
	{
		printf("{");
		for (int j = 0; j < select; j++)  printf(" 0x%x,", GeneralKey[i][j]);

		printf("},\n");
	}
}
void UserInterface()
{
	int selection = 0;
	printf("What process do you want do?\n1-)Encrypte 2-)Decrypte 3-)Both 4-)Only one(message array) :");
	std::cin>>selection;
	if(selection==1)
	{
		
		system("cls");
		char userChar[20];
		printf("\nPlease enter string you want encrypt:");
		std::cin.ignore(256, '\n');
		std::cin.getline(userChar, 20);
		printf("\n");

		printf("Original Data(String):");
		for (int i = 0; i < strlen(userChar); i++)
		{
			if (i < 16) { message[i] = (uint8_t)userChar[i]; printf("%c", userChar[i]); }

		}
		printf("\n\n");
		AESEncrypt(message, 16);
	
	}

	else if (selection == 2)

	{
		system("cls");
		printf("Enter Crypted Data as Array:");
		for (int i = 0; i < 16; i++)
		{
			std::cin.unsetf(std::ios::dec);
			std::cin>>std::dec>>CryptedData[i];
			std::cin.ignore(256, '\n');

		}
		AESDecrypte(CryptedData);

	}

	else if (selection == 3)
	{
		system("cls");
		char userChar[20];
		printf("\nPlease enter string you want encrypt:");
		std::cin.ignore(256, '\n');
		std::cin.getline(userChar, 20);
		printf("\n");

		printf("Original Data(String):");
		for (int i = 0; i < strlen(userChar); i++)
		{
			if (i < 16) { message[i] = (uint8_t)userChar[i]; printf("%c", userChar[i]); }

		}
		printf("\n\n");
		AESEncrypt(message, 16);
		AESDecrypte(CryptedData);


	}
	else if (selection == 4)
	{  
		printf("\n");
		
		message[0] = 0x74;   message[4] = 0x61;  message[8] = 0x69;    message[12] = 0x72;
		message[1] = 0x61;   message[5] = 0x73;  message[9] = 0x6e;    message[13] = 0x61;
		message[2] = 0x6c;   message[6] = 0x65;  message[10] = 0x63;   message[14] = 0x6c;
		message[3] = 0x68;   message[7] = 0x76;  message[11] = 0x6b;   message[15] = 0x6c;
		AESEncrypt(message, 16);
		AESDecrypte(CryptedData);

	}
	else
	{
		exit(0);

	}



}

void clear()
{
	for (int i = 0; i < 16; i++) message[i] = 0;
	for (int i = 0; i < 16; i++) rawData[i] = 0;	

}

void decodeDecryptedData()
{
	char decrypteString[16];
	for (int i = 0; i < 16; i++) decrypteString[i] = (char)DecryptedData[i];
	printf("\n\nDecrypted Data(String):");
	for (int i = 0; i < 16; i++) printf("%c", decrypteString[i]);
	printf("\n\n");
         
}

int inquire()
{
	char selection;
	printf("\n\n Quit(To continue press any except for Q): ");
	
	std::cin>>selection;
	printf("\n\n");
	if (selection == 'Q' || selection == 'q')
		return 0;
	else 
		return 1;
	return 1;
}


void AESEncrypt(int *arrayS, int arraySize)
{
	
	printArray(6);
	int division = arraySize / 16;
	int remining = arraySize % 16;
	for (int i = 0; i <= division; i++)
	{
		if ((i == division && remining == 0)) break;

		if (i != division || (i==division && remining==0))
		{
			for (int j = 0; j < 16; j++)         rawData[j] = arrayS[i*16+j];
		}

		else if(remining!=0)
		{
			for (int j = 0; j < remining; j++)   rawData[j] = arrayS[i * 16 + j];
			for (int j = (remining + 1); j < 16; j++)     rawData[j] = 0;
		}
		
		
		convertDataToState();
		printArray(0);
		AddRoundKey(0);
		printArray(0);
		for (int i = 0; i < numberRound-1; i++)   //for (int i = 0; i < 9; i++)
		{

			Subbytes();
			printArray(0);
			ShiftRows();
			printArray(0);
			MixColumns();
			printArray(0);
			AddRoundKey(i + 1);
			printArray(0);
		}


		Subbytes(); printArray(0);
		ShiftRows(); printArray(0);
		AddRoundKey(numberRound); printArray(0);
		convertStateToData();
		printArray(2);

		
	}
}



void convertDataToState()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			stateMatrix[i][j] = rawData[4 * j + i];
}

void convertStateToData()
{
	int count = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			CryptedData[count] = stateMatrix[j][i];
			count++;
		}
}

void Subbytes(void)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{			

			//stateMatrix[i][j] = SBOX[ stateMatrix[i][j] ];
			int level = stateMatrix[i][j];
			stateMatrix[i][j]= *(SBOX + level);
		}
	}
}
void ShiftRows()
{
	int temp  = 0;
	int temp2 = 0;

	temp = stateMatrix[1][0];
	stateMatrix[1][0]= stateMatrix[1][1];
	stateMatrix[1][1] = stateMatrix[1][2];
	stateMatrix[1][2] = stateMatrix[1][3];
	stateMatrix[1][3] = temp;
	
	temp = stateMatrix[2][0];
	temp2 = stateMatrix[2][1];
	stateMatrix[2][0] = stateMatrix[2][2];
	stateMatrix[2][1] = stateMatrix[2][3];
	stateMatrix[2][2] = temp;
	stateMatrix[2][3] = temp2;

	temp = stateMatrix[3][3];
	stateMatrix[3][3] = stateMatrix[3][2];
	stateMatrix[3][2] = stateMatrix[3][1];
	stateMatrix[3][1] = stateMatrix[3][0];
	stateMatrix[3][0] = temp;
}


void MixColumns()
{
	for (int i = 1; i < 5;i++) mixSubCol(i);
}

void mixSubCol(int section)
{
	
	bool mul2control = 0;
	bool mul3control = 0;
	int temp0, temp1, temp2, temp3;
	int trans0, trans1, trans2, trans3;
	int tempArray[4];

	for (int i = 0; i < 4;i++) tempArray[i] = stateMatrix[i][section - 1];
	
	/*First loop.*/
	
	mul2control = (tempArray[0] >> 7);
	mul3control = (tempArray[1] >> 7);
	trans0=tempArray[0] << 1;	
	if (mul2control) trans0 ^= 0x1B;
	trans0 &= 0x0FF;
	trans1 = tempArray[1] << 1;
	if (mul3control) trans1 ^= 0x1B;
	trans1 ^= tempArray[1];
	trans1 &= 0x0FF;

	temp0 = trans0 ^ trans1^tempArray[2] ^ tempArray[3];
	
	/*Second loop.*/

	mul2control = (tempArray[1] >> 7);
	mul3control = (tempArray[2] >> 7);
	trans0 = tempArray[1] << 1;
	if (mul2control) trans0 ^= 0x1B;
	trans0 &= 0x0FF;
	trans1 = tempArray[2] << 1;
	if (mul3control) trans1 ^= 0x1B;
	trans1 ^= tempArray[2];
	trans1 &= 0x0FF;

	temp1 = trans0 ^ trans1 ^ tempArray[0] ^ tempArray[3];

	/*Third loop.*/

	mul2control = (tempArray[2] >> 7);
	mul3control = (tempArray[3] >> 7);
	trans0 = tempArray[2] << 1;
	if (mul2control) trans0 ^= 0x1B;
	trans0 &= 0x0FF;
	trans1 = tempArray[3] << 1;
	if (mul3control) trans1 ^= 0x1B;
	trans1 ^= tempArray[3];
	trans1 &= 0x0FF;
	temp2 = trans0 ^ trans1^tempArray[0] ^ tempArray[1];

	/*Fourth loop.*/

	mul2control = (tempArray[3] >> 7);
	mul3control = (tempArray[0] >> 7);
	trans0 = tempArray[3] << 1;
	if (mul2control) trans0 ^= 0x1B;
	trans0 &=0x0FF;
	trans1 = tempArray[0] << 1;
	if (mul3control) trans1 ^= 0x1B;
	trans1 ^= tempArray[0];
	trans1 &= 0x0FF;
	temp3 = trans0 ^ trans1^tempArray[1] ^ tempArray[2];

	stateMatrix[0][section - 1] = temp0;
	stateMatrix[1][section - 1] = temp1;
	stateMatrix[2][section - 1] = temp2;
	stateMatrix[3][section - 1] = temp3;


}

void AddRoundKey(int selection)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			stateMatrix[i][j] = stateMatrix[i][j] ^ GeneralKey[i][4 * selection + j];
		}
	}

}


void ConvertDataToReverseArray(int *arrayNew)
{
	 int count = 0;
	 for(int i=0;i<4;i++)
	     for (int j = 0; j < 4; j++)
		  {
			 reverseStateMatrix[i][j] = arrayNew[4*j+i];			 

		  }
     
}

void ConvReverseToData()
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{ 
			DecryptedData[count] = reverseStateMatrix[j][i]; 
			count++; 
		}
	}

}


void InvAddRoundKey(int selection)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			reverseStateMatrix[i][j] = reverseStateMatrix[i][j] ^ GeneralKey[i][4 * selection + j];
		}
	}
}


void ReverseShift()
{
	int temp,temp2;

	temp = reverseStateMatrix[1][3];
	reverseStateMatrix[1][3] = reverseStateMatrix[1][2];
	reverseStateMatrix[1][2] = reverseStateMatrix[1][1];
	reverseStateMatrix[1][1] = reverseStateMatrix[1][0];
	reverseStateMatrix[1][0] = temp;

	temp  = reverseStateMatrix[2][2];
	temp2 = reverseStateMatrix[2][3];
	reverseStateMatrix[2][3] = reverseStateMatrix[2][1];
	reverseStateMatrix[2][2] = reverseStateMatrix[2][0];
	reverseStateMatrix[2][1] = temp2;
	reverseStateMatrix[2][0] = temp;

	temp = reverseStateMatrix[3][0];
	reverseStateMatrix[3][0] = reverseStateMatrix[3][1];
	reverseStateMatrix[3][1] = reverseStateMatrix[3][2];
	reverseStateMatrix[3][2] = reverseStateMatrix[3][3];
	reverseStateMatrix[3][3] = temp;	 

}

void ReverseSubBytes()
{
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			reverseStateMatrix[i][j] = INV_SBOX[reverseStateMatrix[i][j]];
		}
	}

}

void ReverseMixColumns()
{
	for (int i = 0; i < 4; i++) 
	{ miniReverseMix(i + 1); }
}

void miniReverseMix(int section)
{

	bool mul2control = 0;
	bool mul3control = 0;
	int temp0, temp1, temp2, temp3;
	int trans0, trans1, trans2, trans3;
	int temp[4];

	for (int i = 0; i < 4; i++) temp[i] = reverseStateMatrix[i][section - 1];

	trans0 = mul14(temp[0]) ^ mul11(temp[1]) ^ mul13(temp[2]) ^ mult9(temp[3]);
	trans1 = mult9(temp[0]) ^ mul14(temp[1]) ^ mul11(temp[2]) ^ mul13(temp[3]);
	trans2 = mul13(temp[0]) ^ mult9(temp[1]) ^ mul14(temp[2]) ^ mul11(temp[3]);
	trans3 = mul11(temp[0]) ^ mul13(temp[1]) ^ mult9(temp[2]) ^ mul14(temp[3]);

	reverseStateMatrix[0][section - 1] = trans0;
	reverseStateMatrix[1][section - 1] = trans1;
	reverseStateMatrix[2][section - 1] = trans2;
	reverseStateMatrix[3][section - 1] = trans3;

}


void AESDecrypte(int *cryptedDatas)
{

	ConvertDataToReverseArray(cryptedDatas);
	InvAddRoundKey(numberRound);

	for (int i = (numberRound-1); i > 0; i--)
	{
		ReverseShift();	
		ReverseSubBytes();
		InvAddRoundKey(i);
		ReverseMixColumns();

	}

	ReverseShift();
	ReverseSubBytes();
	InvAddRoundKey(0);
	ConvReverseToData();
	printArray(4);
	decodeDecryptedData();
}



void KeyExtension()
{

	int tempArray2[4];
	int tempArray3[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			GeneralKey[i][j] = Key[i][j];

	int select = 3;
	for (int i = 4; i < 4 * numberRound + 4; i++)
	{
		if (i % 4 == 0)
		{
			for (int a = 0; a < 4; a++) tempArray2[a] = GeneralKey[a][select];
			for (int a = 0; a < 4; a++) tempArray3[a] = GeneralKey[a][select - 3];
			GFunction(tempArray2, KeyCounter);
			for (int a = 0; a < 4; a++) GeneralKey[a][select + 1] = tempArray[a] ^ tempArray3[a];
			select += 4;
			KeyCounter++;
		}

		else
		{
			for (int a = 0; a < 4; a++) GeneralKey[a][i] = GeneralKey[a][i - 1] ^ GeneralKey[a][i - 4];

		}
	}

}

void GFunction(int *lastWord, int selection)
{
	int temp = lastWord[0];
	tempArray[0] = lastWord[1];
	tempArray[1] = lastWord[2];
	tempArray[2] = lastWord[3];
	tempArray[3] = temp;

	tempArray[0] = SBOX[tempArray[0]];
	tempArray[1] = SBOX[tempArray[1]];
	tempArray[2] = SBOX[tempArray[2]];
	tempArray[3] = SBOX[tempArray[3]];

	tempArray[0] = tempArray[0] ^ Rcon[selection];
	tempArray[1] ^= 0x00;
	tempArray[2] ^= 0x00;
	tempArray[3] ^= 0x00;
}


int mul14(int a)
{
	int temp = a;
	temp = mul2(temp);
	temp ^= a;
	temp = mul2(temp);
	temp ^= a;
	temp = mul2(temp);
	return temp;

}

int mul13(int a)
{
	int temp = a;
	temp = mul2(temp);
	temp ^= a;
	for (int i = 0; i < 2; i++) temp = mul2(temp);
	temp ^= a;
	return temp;

}


int mul11(int a)
{
	int temp = a;
	for (int i = 0; i < 2; i++) temp = mul2(temp);
	temp ^= a;
	temp = mul2(temp);
	temp ^= a;
	return temp;


}

int mult9(int a)
{
	int temp = a;
	for (int i = 0; i < 3; i++)	temp = mul2(temp);
	temp = a ^ temp;
	return temp;
	

}

int mul2(int a)
{
	if (a > 255) a = a & 0x0FF;
	bool control = a >> 7;
	a = a << 1;
	a = a & 0x0FF;
	if (control)  a = a ^ 0x1B;
	return a;

}

int mul3(int a)
{
	return mul2(a) ^ a;
}




