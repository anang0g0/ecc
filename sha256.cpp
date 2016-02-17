/**
	SHA256を求めるクラス，及びそれを利用したプログラム
	アルゴリズムは
	FIP180-2(http://csrc.nist.gov/publications/fips/fips180-2/fips180-2.pdf)
	を参考にしてください．
	ソースコード中のコメントはFIP180-2内での文章のコピーが大半です^^;

	@date 2005-11-20
	@auther Naoki_I
 */

//#define _DEBUG_SHA256
#define _SHA256_WITH_MAIN

#ifdef _SHA256_WITH_MAIN
#include <cstdio>
#include <cstring>
#endif
#include <NTL/ZZ.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "sha256.h"

NTL_CLIENT

//constant 32-bit words
const u_32 kk[64]=
{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
};

//4.1 Functions

//SHR n(x) = x >> n
//ROTR n(x) = (x >> n) or (x << w - n)
#define SHR(n, x) ((x)>>(n))
#define ROTR(n, x) (SHR(n, x)|((x)<<(32-n)))

//Ch( x, y, z) = ( x and y)xor(~x and z)
//Maj( x, y, z) = ( x and y)xor (x and z)xor(y and z)
#define Ch(x, y, z) ((x&y)^(~x&z))
#define Maj(x, y, z) ((x&y)^(x&z)^(y&z))

//S_0~256(x) = ROTR 2(x) xor ROTR 13(x) xor ROTR 22(x)
//S_1~256(x) = ROTR 6(x) xor ROTR 11(x) xor ROTR 25(x)
#define S256_0(x) (ROTR(2,x) ^ ROTR(13,x) ^ ROTR(22,x))
#define S256_1(x) (ROTR(6,x) ^ ROTR(11,x) ^ ROTR(25,x))

//s_0~256(x) = ROTR 7(x) xor ROTR 18(x) xor SHR3(x)
//s_1~256(x) = ROTR 17(x) xor ROTR 19(x) xor SHR10(x)
#define S_0_256(x) (ROTR(7,(x)) ^ ROTR(18,(x)) ^ SHR(3,(x)))
#define S_1_256(x) (ROTR(17,(x)) ^ ROTR(19,(x)) ^ SHR(10,(x)))

#ifdef _SHA256_WITH_MAIN

#define BUF_SIZE 0x1000
#include<cstdio>
ZZ sha2(int argc, char**argv)
{
	SHA256 sha256;
	unsigned char Hash[32];
	FILE*fp;
//        ZZ salt;
	
	if((argc==3) && (!strcmp(argv[1], "-s")))
	{
		//./sha256 -s hogehoge の形式で実行．
		//テキスト(hogehoge)からハッシュを求める
		sha256.Push((unsigned char*)argv[2], strlen(argv[2]));
	}
	else
	{
		unsigned char Buf[BUF_SIZE];
		/*
		if(argc<2)
		{
			//標準入力からハッシュを求める
			fp=stdin;
			while(fgets((char*)Buf, BUF_SIZE, fp))
				sha256.Push(Buf, strlen((char*)Buf));
		}*/
         fp=fopen(argv[1], "rb");
	        if(fp!=NULL)
		{
			//ファイルからハッシュを求める
			int ret;
			while(ret=fread(Buf, 1, BUF_SIZE, fp))
				sha256.Push(Buf, ret);
		}
		else if(fp==NULL)
		{
			printf("鍵ファイルを指定してください\n");
                  exit(1);
			//コマンドライン引数が不正
		//	fputs("usage: ./a.out [-s] [file]\n", stderr);
//			return 1;
		}
	}
	sha256.Final(Hash);

	ZZ salt;
	
	salt=to_ZZ("0");

	for(int i=0; i<32; i++)
	{
		salt=(salt<<8)+(unsigned int)Hash[i];
		std::printf("%02x", (unsigned int)Hash[i]);
	}
	putc('\n', stdout);
	return salt;
}
#endif

SHA256::SHA256()
{
	H[0]=0x6a09e667;
	H[1]=0xbb67ae85;
	H[2]=0x3c6ef372;
	H[3]=0xa54ff53a;
	H[4]=0x510e527f;
	H[5]=0x9b05688c;
	H[6]=0x1f83d9ab;
	H[7]=0x5be0cd19;

	m_WIndex=0;
	m_MesLen=0;
	memset(W, 0, 256);
}

void SHA256::CalcIntermediateHash(){
    u_32 x[8];

    memcpy(x, H, 32);
    int T1, T2;
    int t;
#define ROUND(n,a,b,c,d,e,f,g,h) \
    T1=x[h]+S256_1(x[e])+Ch(x[e],x[f],x[g])+kk[t+n]+W[t+n]; \
    T2=S256_0(x[a])+Maj(x[a],x[b],x[c]); \
    x[d]=x[d]+T1; \
    x[h]=T1+T2
    
    for(t=0; t<64; t+=8){
        ROUND(0,0,1,2,3,4,5,6,7);
        ROUND(1,7,0,1,2,3,4,5,6);
        ROUND(2,6,7,0,1,2,3,4,5);
        ROUND(3,5,6,7,0,1,2,3,4);
        ROUND(4,4,5,6,7,0,1,2,3);
        ROUND(5,3,4,5,6,7,0,1,2);
        ROUND(6,2,3,4,5,6,7,0,1);
        ROUND(7,1,2,3,4,5,6,7,0);
    }
    H[0]+=x[0];
    H[1]+=x[1];
    H[2]+=x[2];
    H[3]+=x[3];
    H[4]+=x[4];
    H[5]+=x[5];
    H[6]+=x[6];
    H[7]+=x[7];
}

void SHA256::Push(unsigned char*pMes, u_32 Len)
{
push_top:
	u_32 MesIndex=0;
	u_32 t_4;

	for(t_4=m_WIndex; (m_WIndex%4) && (MesIndex<Len); t_4++)
	{
		W[t_4/4]|=pMes[MesIndex++]<<(24-(t_4%4)*8);
	}
    
	m_WIndex=t_4;
	u_32 t;
	for(t=m_WIndex/4; (t<16) && (MesIndex+3<Len); t++)
	{
		W[t]|=pMes[MesIndex]<<24
			|pMes[MesIndex+1]<<16
			|pMes[MesIndex+2]<<8
			|pMes[MesIndex+3];
		MesIndex+=4;
	}

	for(t_4=t*4; (t_4<64) && (MesIndex<Len); t_4++)
	{
		W[t_4/4]|=pMes[MesIndex++]<<(24-(t_4%4)*8);
	}
	m_WIndex=t_4;


	//t_4==64の時，すでに1ブロック分のメッセージがコピーされているので
	//一時的なハッシュを求める
	if(t_4==64)
	{
		for(int t=16;t<64; t++)
		{
			W[t]=S_1_256(W[t-2])+W[t-7]+S_0_256(W[t-15])+W[t-16];
		}
		CalcIntermediateHash();

		m_WIndex=0;
		memset(W, 0, 256);
		m_MesLen+=MesIndex*8;
		if(MesIndex<Len)
		{
			pMes+=MesIndex;
			Len-=MesIndex;
			///////こんな所にgotoが/////////
			//再帰呼び出しの意味は無いのでジャンプします．
			//ループはネストが深くなるので嫌です
			goto push_top;
		}
	}
	else
		m_MesLen+=Len*8;
}

void SHA256::Final(unsigned char* pHash)
{
	//メッセージの終わりのビットを立てる
	W[m_WIndex++/4]|=0x80000000>>((m_WIndex%4)*8);
	while(m_WIndex%4)
        m_WIndex++;

	if(m_WIndex>56)
	{
		//メッセージの長さをコピーする余裕が無いので
		//次のブロックを作る
        int t;        
		for(t=16;t<64; t++)
			W[t]=S_1_256(W[t-2])+W[t-7]+S_0_256(W[t-15])+W[t-16];
		CalcIntermediateHash();
		m_WIndex=0;
	}
	//残りのブロックを0で埋める
	int t;
	for(t=m_WIndex/4;t<14; t++)
			W[t]=0;
	//メッセージのサイズ
	W[14]=U64_HIGH(m_MesLen);
	W[15]=U64_LOW(m_MesLen);	
	for(t=16;t<64; t++)
			W[t]=S_1_256(W[t-2])+W[t-7]+S_0_256(W[t-15])+W[t-16];
	CalcIntermediateHash();

	for(t=0; t<32; t++)
	{
		pHash[t]=H[t/4]>>((3-t%4)*8);
	}
}
