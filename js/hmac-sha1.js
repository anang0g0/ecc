/* Implementation of NIST's Secure Hash Algorithm (FIPS 180)
 * Lightly bummed for execution efficiency.
 *
 * Jim Gillogly 3 May 1993
 *
 * 27 Aug 93: imported LITTLE_ENDIAN mods from Peter Gutmann's implementation
 * 5 Jul 94: Modified for NSA fix
 *
 * Compile: cc -O -o sha sha.c
 *
 * To remove the test wrapper and use just the nist_hash() routine,
 *      compile with -DONT_WRAP
 *
 * To reverse byte order for little-endian machines, use -DLITTLE_ENDIAN
 *
 * To get the original SHA definition before the 1994 fix, use -DVERSION_0
 *
 * Usage: sha [-vt] [filename ...]
 *
 *      -v switch: output the filename as well
 *      -t switch: suppress spaces between 32-bit blocks
 *
 *      If no input files are specified, process standard input.
 *
 * Output: 40-hex-digit digest of each file specified (160 bits)
 *
 * Synopsis of the function calls:
 *
 *   sha_file(char *filename, unsigned long *buffer)
 *      Filename is a file to be opened and processed.
 *      buffer is a user-supplied array of 5 or more longs.
 *      The 5-word buffer is filled with 160 bits of non-terminated hash.
 *      Returns 0 if successful, non-zero if bad file.
 *
 *   void sha_stream(FILE *stream, unsigned long *buffer)
 *      Input is from already-opened stream, not file.
 *
 *   void sha_memory(char *mem, long length, unsigned long *buffer)
 *      Input is a memory block "length" bytes long.
 *
 * Caveat:
 *      Not tested for case that requires the high word of the length,
 *      which would be files larger than 1/2 gig or so.
 *
 * Limitation:
 *      sha_memory (the memory block function) will deal with blocks no longer
 *      than 4 gigabytes; for longer samples, the stream version will
 *      probably be most convenient (e.g. perl moby_data.pl | sha).
 *
 * Bugs:
 *      The standard is defined for bit strings; I assume bytes.
 *
 * Copyright 1993, Dr. James J. Gillogly
 * This code may be freely used in any application.
 */

/* 鍵付きハッシュ関数SHA JavaScript 2001.7.25 Copyright(C) by G01dwasser */



/* #define LITTLE_ENDIAN */

/* #define VERSION_0 */  /* Define this to get the original SHA definition */


#define VERBOSE

#define TRUE  1
#define FALSE 0

#define SUCCESS 0
#define FAILURE -1


/* External entries 
int sha_file(char *filename, unsigned long *buffer);
void sha_memory(char *mem, unsigned long length, unsigned long *buffer);
void sha_stream(FILE *stream, unsigned long *buffer);
static void nist_guts(int file_flag, FILE *stream, char *mem, unsigned long length, unsigned long *buf);
*/

#ifndef ONT_WRAP        /* Using just the hash routine itself */

#define HASH_SIZE 5     /* Produces 160-bit digest of the message */




function main(int argc, char **argv) {
    unsigned long hbuf[HASH_SIZE];
    char *s;
    int file_args = FALSE;  /* If no files, take it from stdin */
    int verbose = FALSE;
    int terse = FALSE;

#ifdef MEMTEST
    sha_memory("abc", 3l, hbuf);         /* NIST test value from appendix A */
    if (verbose) printf("Memory:");
    if (terse) 
      documnet.write(hbuf[0], hbuf[1], hbuf[2], hbuf[3], hbuf[4] + "<br>");
    else 
	document.write(hbuf[0], hbuf[1], hbuf[2], hbuf[3], hbuf[4] + "<br>");
#endif

  if (terse) {
    document.write(hbuf[0] + "<br>");
    H = new BigInt("0x" + hbuf[0]);
    TMP= new BigInt("0x" + hbuf[1]);
    H=(H <<< 32);
    H=bigint_add(H,TMP);
    H=(H <<< 32);
    TMP= new BigInt("0x" + hbuf[2]);
    H=bigint_add(H,TMP);
    H=(H << 32);
    TMP= new BigInt("0x" + hbuf[3]);
    H=bigint_add(H,TMP);
    H=(H << 32);
    TMP= new BigInt("0x" + hbuf[4]);
    H=bigint_add(H,TMP);
    document.write(H + "<br>");
  }
  else {
    H= new BigInt("0x" + hbuf[0]);
    H= (H <<< 32);
    TMP = BigInt("0x" + hbuf[1]);
    H=(H <<< 32);
    TMP= BigInt("0x" + hbuf[2]);
    H= (H <<< 32);
    TMP= Bigint("0x" + hbuf[3]);
    H=(H <<< 32);
    TMP= BigInt("0x" + hbuf[4]);
    document.write(H + "<br>");
  }

    if (! file_args)    /* No file specified */
      {
	if (verbose) printf("%s:", *argv);
	sha_stream(stdin, hbuf);

	document.write(hbuf[0] + " " + hbuf[1] + " " + hbuf[2] + " " + hbuf[3] + " " + hbuf[4]) + "<br>";
    }
    return TRUE;
}

#endif ONT_WRAP

#ifdef LITTLE_ENDIAN    /* Imported from Peter Gutmann's implementation */

/* When run on a little-endian CPU we need to perform byte reversal on an
   array of longwords.  It is possible to make the code endianness-
   independant by fiddling around with data at the byte level, but this
   makes for very slow code, so we rely on the user to sort out endianness
   at compile time */

byteReverse( buffer, byteCount )
    {
    var value;
    var count;

    byteCount /= 32;
    for( count = 0; count < byteCount; count++ )
	{
	value = ( buffer[ count ] << 16 ) | ( buffer[ count ] >> 16 );
	buffer[ count ] = ( ( value & 0xFF00FF00L ) >> 8 ) | ( ( value & 0x00FF00FFL ) << 8 );
	}
    }
#endif /* LITTLE_ENDIAN */



union longbyte
{
     W = new Array(80);        /* Process 16 32-bit words at a time */
     B = new Array(320);                /* But read them as bytes for counting */
};

function sha_text( buffer )      /* Hash a file */
{
    var infile;

  while(buffer != EOF){
	var i; //int

	for (i = 0; i < 5; i++)
	    buffer[i] = 0xdeadbeef;
	return FAILURE;
  }
    sha_stream(infile, buffer);
    return SUCCESS;
}

/* Hash a memory block */
sha_memory( mem, length, buffer)
{
    nist_guts(FALSE, (FILE *) NULL, mem, length, buffer);
}

sha_stream(FILE *stream, unsigned long *buffer)
{
    nist_guts(TRUE, stream, (char *) NULL, 0l, buffer);
}

function f0(x,y,z)
{
  return (z ^ (x & (y ^ z)));
} /* Magic functions */
function f1(x,y,z)
{
  return (x ^ y ^ z);
}
function f2(x,y,z) {
return ((x & y) | (z & (x | y)));
}
function f3(x,y,z) {
  return (x ^ y ^ z);
}

/* Magic constants */
 K = new Array(0x5a827999, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6);

function S(n, X) {
  return ((X << n) | (X >> (32 - n)));    /* Barrel roll */
}

function r0(f, K) {
  temp = S(5, A) + f(B, C, D) + E + *p0++ + K; 
  E = D;  
  D = C;  
  C = S(30, B); 
  B = A;  
  A = temp;

  return A;
}

#ifdef VERSION_0
function r1(f, K) {
    temp = S(5, A) + f(B, C, D) + E + (*p0++ = *p1++ ^ *p2++ ^ *p3++ ^ *p4++) + K;
    E = D;
    D = C;
    C = S(30, B);
    B = A;
    A = temp;

  return A;
}
#else                   /* Version 1: Summer '94 update */
function r1(f, K) {
    temp = *p1++ ^ *p2++ ^ *p3++ ^ *p4++; 
    temp = S(5, A) + f(B, C, D) + E + (*p0++ = S(1,temp)) + K; 
    E = D;  
    D = C;  
    C = S(30, B); 
    B = A;  
    A = temp;
return A;
}
#endif



/* Input from memory, or from stream? */
nist_guts( file_flag, mem, length, buf)
{
    var i, nread, nbits; //int
    union longbyte d;
    var hi_length, lo_length; // unsigned long
    var padded; // int
    var s; // char *

    var p0, p1, p2, p3, p4; // register unsignred long *
    var A, B, C, D, E, temp; // unsigned long

    h = new Array(
      0x67452301,/* Accumulators */ ,0xefcdab89,
      0x98badcfe, 0x10325476, 0xc3d2e1f0);

  padded = FALSE;
  s = mem;
    for (hi_length = lo_length = 0; ;)  /* Process 16 longs at a time */
    {
          /* Read as 64 bytes */
      
      if (length < 64) nread = length;
      else             nread = 64;
      length -= nread;
      memcpy(d.B, s, nread);
      s += nread;
    }
  if (nread < 64)   /* Partial block? */
    {
		nbits = nread << 3;               /* Length: bits */
		if ((lo_length += nbits) < nbits)
			hi_length++;              /* 64-bit integer */

		if (nread < 64 && ! padded)  /* Append a single bit */
		{
			d.B[nread++] = 0x80; /* Using up next byte */
			padded = TRUE;       /* Single bit once */
		}
		for (i = nread; i < 64; i++) /* Pad with nulls */
			d.B[i] = 0;
		if (nread <= 56)   /* Room for length in this block */
		{
			d.W[14] = hi_length;
			d.W[15] = lo_length;
#ifdef LITTLE_ENDIAN
	      byteReverse(d.W, 56 );
#endif /* LITTLE_ENDIAN */
		}
#ifdef LITTLE_ENDIAN
	   else byteReverse(d.W, 64 );
#endif /* LITTLE_ENDIAN */
	}
	else    /* Full block -- get efficient */
	{
		if ((lo_length += 512) < 512)
			hi_length++;    /* 64-bit integer */
#ifdef LITTLE_ENDIAN
	   byteReverse(d.W, 64 );
#endif /* LITTLE_ENDIAN */
	}

	p0 = d.W;
	A = h0; B = h1; C = h2; D = h3; E = h4;

	r0(f0,K0); r0(f0,K0); r0(f0,K0); r0(f0,K0); r0(f0,K0);
	r0(f0,K0); r0(f0,K0); r0(f0,K0); r0(f0,K0); r0(f0,K0);
	r0(f0,K0); r0(f0,K0); r0(f0,K0); r0(f0,K0); r0(f0,K0);
	r0(f0,K0);

	p1 = &d.W[13]; p2 = &d.W[8]; p3 = &d.W[2]; p4 = &d.W[0];

		   r1(f0,K0); r1(f0,K0); r1(f0,K0); r1(f0,K0);
	r1(f1,K1); r1(f1,K1); r1(f1,K1); r1(f1,K1); r1(f1,K1);
	r1(f1,K1); r1(f1,K1); r1(f1,K1); r1(f1,K1); r1(f1,K1);
	r1(f1,K1); r1(f1,K1); r1(f1,K1); r1(f1,K1); r1(f1,K1);
	r1(f1,K1); r1(f1,K1); r1(f1,K1); r1(f1,K1); r1(f1,K1);
	r1(f2,K2); r1(f2,K2); r1(f2,K2); r1(f2,K2); r1(f2,K2);
	r1(f2,K2); r1(f2,K2); r1(f2,K2); r1(f2,K2); r1(f2,K2);
	r1(f2,K2); r1(f2,K2); r1(f2,K2); r1(f2,K2); r1(f2,K2);
	r1(f2,K2); r1(f2,K2); r1(f2,K2); r1(f2,K2); r1(f2,K2);
	r1(f3,K3); r1(f3,K3); r1(f3,K3); r1(f3,K3); r1(f3,K3);
	r1(f3,K3); r1(f3,K3); r1(f3,K3); r1(f3,K3); r1(f3,K3);
	r1(f3,K3); r1(f3,K3); r1(f3,K3); r1(f3,K3); r1(f3,K3);
	r1(f3,K3); r1(f3,K3); r1(f3,K3); r1(f3,K3); r1(f3,K3);

	h0 += A; h1 += B; h2 += C; h3 += D; h4 += E;

	if (nread <= 56) break; /* If it's greater, length in next block */
    }
    buf[0] = h0; buf[1] = h1; buf[2] = h2; buf[3] = h3; buf[4] = h4;
}
