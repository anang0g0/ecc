function det()
{
        var N=32;

	sig=new Array();
	ss=new Array();
	ps=new Array();
	sn=new Array();
	gf=new Array();
	fg=new Array();

ps=[165,29,233,153,201,180,79,122,25,83,203,204,211,102,149,123];
sig = [50, 33 ,101 ,22 ,24 ,209 ,208 ,231 ,161 ,3 ,118 ,18 ,169 ,174 ,123 ,5 ,224 ,65 ,153 ,219 ,5 ,174 ,171 ,217 ,195 ,79 ,207 ,220 ,233 ,226 ,96 ,60];
gf={0,1,2,4,8,16,32,64,128,29,58,116,232,205,135,19,38,76,152,45,90,180,117,234,201,143,3,6,12,24,48,96,192,157,39,78,156,37,74,148,53,106,212,181,119,238,193,159,35,70,140,5,10,20,40,80,160,93,186,105,210,185,111,222,161,95,190,97,194,153,47,94,188,101,202,137,15,30,60,120,240,253,231,211,187,107,214,177,127,254,225,223,163,91,182,113,226,217,175,67,134,17,34,68,136,13,26,52,104,208,189,103,206,129,31,62,124,248,237,199,147,59,118,236,197,151,51,102,204,133,23,46,92,184,109,218,169,79,158,33,66,132,21,42,84,168,77,154,41,82,164,85,170,73,146,57,114,228,213,183,115,230,209,191,99,198,145,63,126,252,229,215,179,123,246,241,255,227,219,171,75,150,49,98,196,149,55,110,220,165,87,174,65,130,25,50,100,200,141,7,14,28,56,112,224,221,167,83,166,81,162,89,178,121,242,249,239,195,155,43,86,172,69,138,9,18,36,72,144,61,122,244,245,247,243,251,235,203,139,11,22,44,88,176,125,250,233,207,131,27,54,108,216,173,71,142};
fg={0,1,2,26,3,51,27,199,4,224,52,239,28,105,200,76,5,101,225,15,53,142,240,130,29,194,106,249,201,9,77,114,6,139,102,48,226,37,16,34,54,148,143,219,241,19,131,70,30,182,195,126,107,40,250,186,202,155,10,121,78,229,115,167,7,192,140,99,103,222,49,254,227,153,38,180,17,146,35,137,55,209,149,207,144,151,220,190,242,211,20,93,132,57,71,65,31,67,183,164,196,73,127,111,108,59,41,85,251,134,187,62,203,95,156,160,11,22,122,44,79,213,230,173,116,244,168,88,8,113,193,248,141,129,100,14,104,75,223,238,50,198,255,25,228,166,154,120,39,185,181,125,18,69,147,218,36,33,138,47,56,64,210,92,150,189,208,206,145,136,152,179,221,253,191,98,243,87,212,172,21,43,96,64,210,92,150,189,208,206,145,136,152,179,221,253,191,98,243,87,212,172,21,43,92,158,86,171,252,97,135,178,188,205,63,91,204,90,96,177,157,170,161,82,12,246,23,236,123,118,45,216,80,175,214,234,231,232,174,233,117,215,245,235,169,81,89,176};

        for(var i=0;i<N;i++)
        {
                H[i]=new Array();
        }
H[0]=[116,56,128,81,97,101,91,182,162,19,32,76,34,93,188,186,140,50,148,63,70,13,79,210,205,92,113,100,144,57,9,92,53,235,167,130,40,156,209,12,49,39,14,211,183,85,65,105,4,56,123,196,193,136,9,47,44,120,133,235,78,85,139,96,23,89,79,182,115,12,8,48,28,73,48,164,58,168,225,144,148,133,252,54,157,167,215,45,254,141,252,65,175,114,151,119,149,237,171,104,250,205,212,234,7,248,71,11,132,75,138,106,7,138,55,201,213,56,159,109,234,210,100,47,210,33,183,16,168,72,130,186,40,198,186,17,180,43,99,158,191,103,116,178,5,50,48,107,190,228,221,80,240,235,197,243,42,252,185,202,189,106,22,22,240,122,226,115,101,99,148,65,162,193,11,58,69,199,143,175,113,72,79,51,39,58,22,208,70,34,189,117,144,156,70,161,18,73,103,66,26,32,48,115,244,122,70,121,28,99,134,72,115,42,48,121,225,201,198,97,183,27,3,26,236,212,137,224,221,150,37,242,221,72,66,150,184,110,97,32,68,111,163,131,33,193,133,193,255,210,243,171,209,49,126,84];
H[1]=[115,49,125,242,70,68,67,76,130,155,37,251,208,132,108,129,39,90,176,230,253,36,17,252,180,140,75,252,73,42,143,18,143,67,192,86,8,10,228,106,249,230,97,3,197,82,159,104,232,104,163,39,92,236,141,251,63,121,237,253,163,136,30,227,124,102,1,179,88,61,192,128,170,48,159,40,32,19,136,254,101,111,212,150,114,253,62,220,80,184,126,29,81,65,241,127,50,99,214,108,198,95,41,129,96,57,45,35,124,74,109,231,51,212,190,191,41,112,41,228,253,216,164,69,57,52,5,188,92,161,189,48,246,152,79,182,136,152,103,134,65,157,250,239,4,107,191,196,187,190,189,183,30,24,54,255,213,150,219,134,168,187,246,160,81,42,12,225,200,201,229,113,57,234,146,177,165,149,239,27,113,27,162,29,77,140,117,179,134,174,57,99,11,185,226,16,184,1,142,139,6,29,211,59,211,69,66,196,39,140,33,39,150,143,113,104,190,134,201,9,94,219,194,255,5,103,164,13,214,137,227,90,100,200,21,132,251,24,223,28,209,239,48,167,182,2,6,4,76,71,112,158,80,88,235,119];
H[2]=[138,52,229,99,244,60,140,66,59,103,205,42,185,229,147,129,155,238,79,134,186,37,58,138,61,126,162,177,234,15,3,128,162,209,186,65,146,205,217,71,130,247,109,252,39,163,34,34,172,242,89,187,191,177,248,225,74,37,10,51,182,2,124,205,159,176,95,50,135,147,16,55,35,52,29,213,56,107,222,164,10,50,62,93,9,114,8,159,172,205,206,3,58,123,229,30,164,57,130,187,48,111,7,41,222,158,11,93,156,226,250,194,173,185,77,207,211,82,25,151,187,109,70,161,50,90,42,187,161,17,72,56,11,94,230,192,92,76,4,64,145,57,252,198,57,241,44,144,159,241,249,166,45,117,190,222,237,158,22,94,151,188,20,188,12,1,115,86,116,187,233,141,238,14,135,208,17,100,217,225,53,239,144,163,112,78,8,75,226,18,168,108,50,96,127,77,44,70,254,3,41,178,253,6,218,183,255,134,97,169,236,106,154,52,13,112,88,59,211,94,98,10,80,174,171,151,229,167,63,252,64,3,92,206,254,193,6,94,210,214,145,210,126,208,27,213,151,115,186,158,248,212,41,207,27,84];
H[3]=[135,228,172,11,12,219,51,184,246,133,31,255,158,153,31,139,76,50,114,99,115,144,119,154,10,114,189,23,152,109,170,215,58,113,81,39,246,67,209,231,106,241,94,49,153,115,6,172,238,87,14,8,161,255,230,47,39,44,103,106,172,143,143,61,68,61,71,127,145,169,68,243,153,40,226,92,205,143,154,253,114,141,186,186,209,17,152,96,2,152,150,126,174,201,78,174,122,38,229,212,90,196,147,20,86,233,202,174,253,201,36,171,54,221,226,28,42,86,189,155,178,132,101,96,13,186,13,172,59,128,242,125,246,27,80,113,48,132,90,148,58,154,155,11,227,218,165,21,218,146,87,102,214,66,64,137,112,86,179,63,122,149,93,121,72,11,209,86,221,135,65,215,210,207,71,1,158,30,68,160,189,20,124,238,23,168,103,186,195,133,16,166,180,51,221,228,43,69,35,25,33,48,224,186,93,172,231,132,18,163,245,123,139,105,22,126,157,232,232,181,198,5,63,15,227,29,210,227,237,184,195,228,130,170,230,15,7,139,146,226,53,24,255,79,45,196,91,110,9,154,114,94,103,118,92,31];
H[4]=[189,164,249,2,234,172,168,153,229,225,213,170,213,145,5,5,135,157,237,215,221,52,180,135,101,177,166,124,89,218,172,117,128,36,35,202,79,204,229,104,177,210,167,158,159,215,164,12,97,208,92,118,191,166,41,131,144,184,129,146,156,233,92,184,34,213,46,171,32,113,84,18,157,7,51,70,117,191,246,162,112,84,7,2,181,125,122,121,235,172,130,173,210,101,175,131,173,137,225,141,166,27,11,114,95,212,52,205,153,164,164,247,87,37,125,175,77,243,9,71,12,223,53,100,121,148,58,193,59,129,84,61,10,62,154,17,51,166,251,135,10,231,162,1,21,74,240,71,145,15,104,125,226,28,77,48,244,250,159,167,234,44,8,212,31,198,52,191,177,21,253,177,152,203,49,223,237,114,10,86,236,127,56,100,142,141,230,109,3,244,222,104,238,99,58,103,66,211,221,140,101,193,19,192,227,36,55,151,94,233,24,131,76,81,222,15,117,17,33,121,225,131,69,183,237,223,41,223,232,53,62,244,200,218,255,70,105,91,174,70,206,100,102,104,88,73,8,228,60,67,158,181,76,50,121,6];
H[5]=[115,7,58,15,202,95,86,185,69,52,4,196,243,161,119,241,97,49,169,243,5,212,40,65,164,202,52,213,221,65,223,196,111,213,141,229,114,121,243,87,165,1,21,164,253,139,202,77,168,187,147,106,222,106,174,72,138,253,215,194,209,205,53,91,228,42,161,94,228,189,44,76,20,168,178,117,177,34,2,66,5,77,132,2,251,220,176,100,38,18,32,33,22,219,195,26,30,87,190,57,200,62,183,210,172,82,100,77,129,30,23,127,55,75,130,5,221,70,33,223,57,217,222,209,118,15,36,49,227,45,23,19,44,37,53,191,234,15,108,238,164,101,4,202,191,216,6,63,173,40,231,209,209,222,214,106,210,94,247,193,102,175,64,49,93,154,104,209,143,94,3,105,192,12,145,203,146,156,93,149,65,171,254,41,150,10,232,116,77,109,227,161,151,4,51,59,248,142,191,195,222,237,79,111,175,192,223,198,144,28,79,197,52,115,200,53,97,233,97,196,94,233,60,181,62,61,37,185,195,4,153,26,2,246,207,60,122,8,24,186,22,99,109,218,116,219,36,98,176,52,255,94,243,153,113,108];
H[6]=[17,239,12,237,91,92,128,180,88,163,94,196,234,149,16,232,127,119,118,58,147,14,80,211,50,24,61,126,63,195,196,105,187,186,185,243,42,116,116,22,8,198,193,23,211,152,172,245,174,6,15,98,55,217,56,246,55,216,200,221,1,4,215,180,75,226,86,55,180,91,5,192,106,105,116,155,147,29,20,74,118,124,5,18,66,134,9,154,45,200,212,131,184,108,70,110,197,152,58,240,146,224,159,110,225,9,173,207,151,72,60,145,164,156,189,72,245,177,117,85,54,94,40,226,71,253,57,96,28,41,187,201,42,49,114,130,42,63,251,119,239,192,45,62,170,171,200,35,20,142,201,35,100,41,27,90,206,147,92,208,7,219,247,78,138,217,30,133,55,138,25,71,135,212,237,226,213,33,48,237,61,139,7,194,137,133,214,103,243,16,8,176,123,95,162,67,111,66,254,217,180,213,72,210,88,185,43,123,175,197,121,138,198,120,119,72,240,136,155,236,90,178,228,164,240,240,82,71,218,165,233,224,48,150,96,137,31,158,225,78,253,134,208,23,4,215,230,227,59,211,49,97,99,145,14,220];
H[7]=[57,6,113,81,230,131,134,48,160,51,220,247,124,134,19,73,213,162,228,225,139,170,13,234,39,157,168,72,219,156,94,139,57,64,144,163,171,129,163,187,236,236,71,183,109,34,209,206,96,45,253,199,68,56,64,229,141,195,76,169,84,212,226,173,216,175,229,113,165,151,198,226,60,117,31,166,56,86,73,22,88,218,58,88,182,185,71,154,94,155,102,85,137,237,149,111,86,164,4,40,115,177,11,104,128,91,136,21,55,215,137,74,191,100,15,200,20,246,81,16,33,182,182,120,75,218,184,196,45,94,177,231,182,59,190,76,93,10,205,163,15,53,187,221,87,57,230,247,228,54,19,139,201,6,167,35,121,155,240,172,95,10,173,65,98,226,113,168,132,252,114,176,238,13,199,8,89,156,10,134,210,223,68,37,152,142,81,16,124,75,218,239,19,255,127,51,160,202,161,3,12,207,103,52,75,33,132,122,76,226,211,124,76,159,50,166,21,116,191,103,152,72,48,5,182,251,80,44,34,252,195,226,52,203,199,59,159,190,14,185,36,107,184,246,119,121,168,86,35,104,203,206,42,93,67,246];
H[8]=[248,195,96,252,175,247,185,191,27,24,246,85,60,33,82,191,217,250,185,148,18,144,201,177,216,230,149,57,186,243,231,96,113,240,29,202,187,187,212,10,103,221,15,93,40,80,72,124,54,218,162,171,84,255,174,78,120,5,239,174,114,221,168,67,130,9,125,204,36,3,41,24,11,208,214,97,73,238,118,160,244,234,91,204,179,77,73,38,207,104,253,219,132,208,87,185,149,85,147,170,78,182,238,73,140,214,120,230,124,11,100,39,238,18,145,156,173,23,58,139,170,44,4,55,122,186,251,167,239,237,242,29,252,196,134,86,113,185,229,29,210,179,152,99,217,142,27,192,23,31,23,212,244,48,192,14,98,149,170,56,80,140,21,155,232,43,203,48,86,11,88,17,14,37,125,156,184,93,141,167,19,194,46,23,107,54,28,234,118,9,218,186,235,114,225,117,246,92,191,120,183,221,199,234,88,214,110,114,210,65,30,184,131,33,249,186,101,212,245,138,66,103,6,15,245,8,107,217,130,152,93,206,20,209,15,156,136,237,171,89,22,25,3,177,81,197,173,92,67,2,230,3,233,188,118,24];
H[9]=[17,213,144,218,106,9,12,159,130,130,145,137,193,196,39,171,212,96,36,27,155,80,224,228,172,53,244,254,7,98,67,107,106,183,5,111,54,185,173,3,13,74,183,239,251,135,181,51,86,2,225,250,174,114,51,230,172,77,145,216,246,199,14,167,66,17,153,63,135,220,79,138,85,56,161,110,189,46,217,184,36,179,49,90,1,203,186,77,246,8,106,89,121,26,28,190,114,213,176,1,215,52,206,224,175,107,210,55,10,186,194,156,220,16,64,169,224,163,188,69,215,33,123,119,96,88,127,243,99,215,163,200,54,173,66,246,33,15,60,110,140,80,121,133,58,26,127,163,208,11,108,52,165,148,199,68,183,213,122,165,5,40,37,54,34,91,23,255,140,210,120,86,26,122,147,202,185,187,113,222,244,5,198,61,213,108,7,159,109,45,132,230,166,21,175,171,181,100,205,158,106,252,184,14,80,148,11,127,208,148,30,114,122,203,44,252,58,120,10,214,205,1,48,52,59,39,59,242,78,204,213,109,16,91,148,178,63,255,99,206,16,40,75,32,151,106,206,140,114,228,223,28,134,91,85,168];
H[10]=[141,174,64,130,15,10,177,234,61,25,54,223,26,190,116,192,120,99,144,106,35,61,172,161,6,116,31,62,227,9,166,244,120,137,149,21,173,23,193,163,174,155,120,178,173,95,167,144,6,239,111,41,137,144,73,197,14,60,166,164,24,151,163,164,171,47,44,181,82,110,155,71,57,92,109,84,183,40,99,159,186,213,104,8,227,198,80,129,130,207,91,253,118,50,70,191,43,2,112,200,84,178,38,163,139,255,184,35,240,9,192,23,126,92,50,101,207,77,36,181,6,133,75,27,171,128,157,67,224,185,111,69,126,183,76,86,90,98,60,56,92,48,250,55,19,70,45,125,75,28,81,29,11,66,181,175,72,138,168,205,33,164,201,199,24,105,62,183,72,144,128,255,136,16,127,224,253,112,187,232,24,51,156,198,194,254,39,191,139,230,11,17,76,86,141,123,8,217,162,39,19,18,11,242,249,187,204,206,54,247,252,38,70,179,136,248,148,166,43,106,247,139,151,122,34,114,27,126,9,137,226,131,70,124,182,18,97,94,44,13,248,32,215,76,184,140,222,210,140,82,129,121,193,167,76,175];
H[11]=[208,210,92,177,56,36,203,225,17,96,229,141,2,148,120,244,83,184,190,171,9,11,202,111,171,101,127,245,233,17,73,121,166,231,57,186,163,78,149,27,129,243,225,119,52,83,221,145,75,116,151,21,140,169,38,219,19,17,214,33,122,69,137,149,40,23,27,58,147,117,218,59,54,73,53,65,119,194,97,10,235,251,151,120,165,196,42,215,35,94,235,212,118,147,176,226,237,65,71,61,166,73,116,94,242,68,212,1,7,36,177,210,11,113,43,17,51,156,239,162,61,162,234,78,191,147,153,80,240,212,236,211,227,114,22,34,207,51,252,20,140,226,129,120,103,211,106,245,177,71,4,2,151,30,186,196,46,197,85,98,222,231,34,120,159,124,174,247,22,245,12,138,130,51,154,229,65,213,99,10,123,37,173,65,153,152,249,62,219,33,123,92,179,109,109,4,160,254,176,180,240,248,150,161,89,86,104,72,72,128,217,69,242,141,186,114,183,123,69,177,39,160,160,165,246,31,121,121,27,129,151,141,196,122,22,202,186,93,146,165,95,70,173,199,245,164,13,230,78,245,36,185,211,57,61,21];
H[12]=[9,248,87,252,32,60,95,225,230,160,234,139,214,14,240,104,205,78,163,54,60,49,62,131,29,194,54,6,131,145,96,204,19,117,186,209,199,204,2,187,138,98,39,161,82,6,79,37,116,27,59,153,121,245,97,198,152,93,170,185,208,216,233,73,248,236,87,198,201,238,22,255,234,52,109,123,248,19,213,250,163,250,137,177,109,169,99,209,223,211,93,174,80,247,62,195,221,210,139,25,221,6,25,139,236,155,33,21,108,230,137,219,176,233,255,111,130,31,33,80,208,9,40,29,240,198,74,7,84,89,248,92,199,214,132,179,170,2,130,163,114,113,252,115,66,140,108,73,49,22,22,98,7,56,32,112,138,121,225,96,241,56,129,72,173,26,14,22,55,252,235,112,249,75,33,153,235,193,227,143,54,169,41,170,4,218,202,142,5,140,53,226,16,235,4,180,106,135,81,100,60,200,160,34,66,39,180,90,79,36,121,26,93,228,14,204,178,94,213,190,234,111,241,253,171,16,189,174,83,187,177,253,216,117,161,103,203,244,142,167,28,143,205,146,29,98,240,50,166,131,76,217,20,37,199,199];
H[13]=[226,191,203,22,40,246,79,120,162,47,147,232,183,113,47,61,222,150,52,80,255,31,168,126,211,10,77,190,11,86,73,192,190,167,221,142,218,162,222,191,97,59,69,101,75,223,186,170,214,172,26,22,189,111,52,132,58,2,83,72,245,38,85,189,252,13,147,40,179,93,120,86,53,140,195,42,171,167,139,179,65,125,135,187,194,30,246,21,236,187,118,202,245,240,244,188,3,179,89,41,174,168,103,33,180,97,18,76,37,107,10,48,235,46,118,232,27,150,5,84,247,72,202,72,44,7,108,30,200,31,134,229,140,16,96,244,193,118,167,147,108,211,242,122,213,32,50,222,116,249,89,175,64,185,141,89,70,156,152,236,180,160,129,208,130,107,141,235,59,113,219,179,36,138,147,178,135,219,171,88,185,9,192,17,150,44,227,133,126,221,85,70,231,188,124,12,19,98,99,13,95,116,241,133,186,163,219,93,156,219,222,243,84,13,15,254,71,121,211,39,1,93,12,195,123,66,108,213,146,119,74,166,40,186,92,79,164,33,225,178,94,250,76,219,48,221,119,155,62,173,10,118,232,191,173,107];
H[14]=[134,49,2,24,137,176,49,106,245,93,87,135,221,155,157,194,214,238,113,127,207,45,41,185,23,29,19,60,112,207,131,99,225,104,47,190,197,58,217,249,33,192,204,80,196,204,83,22,109,145,161,133,251,147,147,225,122,241,251,103,101,128,24,53,25,210,234,215,74,212,77,203,48,172,152,214,242,62,156,188,58,239,150,40,122,233,228,113,204,186,115,149,102,57,95,57,137,2,228,137,164,235,1,205,154,84,24,147,5,203,2,189,56,125,106,87,234,172,174,167,137,112,97,191,147,167,49,98,138,250,160,150,81,170,82,128,126,249,65,59,161,119,245,152,82,87,206,28,194,191,57,44,181,41,104,65,68,177,246,220,113,158,214,43,26,37,252,221,24,27,91,31,162,11,202,101,90,12,146,227,134,48,84,234,30,95,173,244,4,60,251,122,92,169,56,128,195,47,163,88,143,20,232,133,224,236,20,97,191,68,132,240,224,3,75,234,135,101,235,122,83,143,208,94,66,131,189,175,202,245,195,20,187,97,123,169,156,90,73,174,252,98,27,241,201,14,235,242,54,244,210,147,7,64,13,201];
H[15]=[229,89,192,211,26,97,203,205,29,40,19,3,32,226,32,179,199,246,91,46,101,165,230,43,110,244,82,134,227,24,175,5,197,90,14,21,236,137,132,117,172,166,119,159,141,241,103,211,65,59,192,12,62,220,42,70,221,68,152,16,171,58,179,251,61,143,174,181,252,37,138,29,48,154,187,148,8,39,67,203,91,141,68,39,154,229,164,186,42,212,166,5,192,22,99,131,109,217,129,232,199,231,114,170,12,244,175,247,137,84,195,14,219,206,18,236,111,38,214,234,49,165,47,208,29,138,236,119,8,46,117,56,236,40,117,140,238,222,220,92,21,19,16,94,164,133,148,182,218,59,208,33,254,250,12,98,63,41,107,128,171,122,153,187,24,71,164,196,56,213,152,190,224,58,74,7,156,42,33,118,82,17,116,162,139,146,187,127,68,239,202,145,65,162,181,173,246,69,48,109,54,13,31,33,13,99,130,177,238,74,61,174,45,178,148,69,148,141,84,150,126,4,14,87,248,103,243,35,8,241,85,191,197,214,9,168,110,145,36,75,117,46,235,49,12,221,98,86,66,43,60,204,132,124,69,144];
H[16]=[157,23,83,6,6,156,49,23,55,100,22,98,83,199,197,145,212,130,235,161,119,27,161,232,109,127,123,232,106,89,91,211,35,30,86,104,232,48,137,61,130,45,13,196,34,206,115,94,66,172,168,188,66,77,160,73,47,255,28,119,241,228,221,95,146,218,27,210,87,227,87,150,241,155,53,79,25,175,10,37,190,47,229,183,81,11,157,145,35,215,77,111,231,249,73,244,211,231,242,182,247,101,28,150,40,166,93,235,125,100,97,75,119,151,119,28,233,89,51,22,171,95,155,14,181,23,81,140,149,209,184,129,49,17,53,203,97,160,202,157,189,46,219,135,106,121,103,92,163,9,166,49,143,245,91,161,59,67,132,144,73,178,200,182,217,26,180,20,58,178,127,191,127,150,154,249,200,41,135,178,127,111,234,192,39,184,210,225,91,125,186,207,21,246,24,184,180,29,129,215,189,159,26,148,85,113,138,216,188,237,83,65,243,157,181,160,81,121,200,117,45,51,150,7,11,199,131,42,120,128,122,191,40,54,198,119,144,56,165,105,90,9,129,120,227,134,90,124,241,217,44,3,144,62,61,97];
H[17]=[82,7,117,59,175,57,117,21,4,247,13,251,35,37,79,80,62,52,45,154,198,224,248,162,244,113,163,202,80,157,139,58,118,24,218,9,5,218,183,15,210,251,185,239,114,7,136,81,139,239,73,116,210,71,199,170,107,84,201,247,190,7,184,238,61,66,56,72,26,178,10,131,249,196,77,23,201,93,57,88,165,163,92,171,145,112,190,252,68,50,243,138,6,107,37,208,49,195,162,94,88,242,132,13,122,240,145,109,20,42,97,80,210,157,205,246,47,193,185,217,94,223,32,55,72,110,87,167,32,127,33,246,169,181,166,161,11,7,189,187,144,21,233,52,231,65,60,95,7,69,56,147,103,31,20,113,18,14,163,127,117,254,86,71,210,104,212,188,138,230,20,57,118,207,85,51,173,35,148,200,227,123,149,8,251,64,55,88,247,63,65,138,88,157,198,191,152,28,223,68,147,33,131,254,163,255,41,93,27,91,240,127,254,8,200,53,45,236,168,205,90,84,93,68,1,117,228,184,70,233,224,186,109,40,1,91,99,184,159,127,126,178,66,51,172,168,64,209,13,151,119,202,162,29,46,160];
H[18]=[71,168,9,163,193,85,27,96,83,154,34,99,180,177,6,15,95,73,165,52,191,156,159,48,221,243,42,205,28,88,16,153,101,129,49,195,69,248,147,80,105,101,82,151,177,191,75,9,121,127,74,231,206,11,105,12,245,125,243,119,254,237,130,228,150,117,192,38,146,197,193,65,92,6,133,142,44,41,218,153,165,233,36,15,142,119,244,70,78,226,7,32,136,177,20,199,213,61,211,75,204,245,121,230,12,187,170,99,27,69,7,111,166,101,31,201,3,205,204,214,113,27,150,70,157,59,35,11,242,77,117,206,69,248,173,234,157,43,234,232,138,48,174,30,142,35,227,23,98,217,101,87,202,204,168,4,167,219,241,240,234,175,147,156,57,88,50,138,186,88,164,201,157,87,192,252,55,240,100,105,42,230,9,104,186,205,165,38,54,69,112,15,43,201,219,47,154,19,28,63,64,104,232,38,198,109,221,27,35,14,107,124,15,52,144,114,239,198,18,169,73,148,95,33,164,93,141,142,85,26,80,107,223,250,9,45,245,100,37,27,130,30,119,140,21,97,51,107,63,48,243,71,153,78,198,227];
H[19]=[230,124,100,127,45,179,233,14,150,214,197,237,45,209,200,118,53,9,133,163,55,41,2,23,224,42,43,245,248,172,10,73,70,69,71,251,191,197,26,105,211,174,64,105,181,170,3,29,121,22,112,219,165,27,201,196,82,31,242,218,79,111,234,148,213,196,21,107,72,185,95,230,202,164,79,164,144,29,66,255,242,229,225,173,31,198,145,81,207,117,165,153,167,31,182,146,183,116,235,105,148,90,80,88,26,129,191,43,249,94,17,182,51,158,22,146,64,16,86,134,84,227,51,65,199,240,55,212,65,61,149,137,60,239,194,64,52,29,239,86,176,141,230,188,141,196,193,86,65,216,9,48,111,63,64,174,178,150,12,217,70,92,238,175,90,77,237,84,123,91,76,123,9,213,130,203,84,79,236,28,109,246,157,203,230,119,195,47,37,159,11,81,172,53,239,2,193,208,253,1,246,34,160,138,128,248,192,89,102,30,62,252,127,251,24,212,98,245,137,24,160,242,175,14,153,248,29,154,234,233,55,79,101,167,195,18,47,24,10,75,176,69,144,71,127,135,19,157,71,249,25,224,166,214,9,194];
H[20]=[218,72,20,9,92,60,204,71,53,198,96,178,228,118,216,20,57,75,81,195,182,168,217,62,127,65,75,253,123,107,11,118,198,239,89,158,125,38,245,112,207,25,16,184,33,3,232,165,175,117,173,183,85,84,133,18,167,197,120,103,47,77,131,185,90,244,79,148,149,158,9,19,114,213,48,149,134,58,48,126,197,243,182,210,129,215,44,71,254,127,161,76,130,3,90,202,238,220,45,60,225,112,37,166,153,6,105,183,190,210,42,116,196,127,108,252,204,79,200,71,60,250,89,86,225,171,81,22,80,200,247,219,202,14,234,46,190,25,148,186,41,108,38,83,3,221,80,50,214,37,16,58,87,223,29,29,68,153,180,71,249,5,189,238,143,87,150,221,123,187,201,83,238,116,11,87,88,120,87,144,58,188,203,108,82,249,23,29,43,232,115,72,104,100,33,202,107,127,17,122,36,235,22,210,233,22,71,186,223,182,48,52,22,131,18,194,78,196,95,111,67,45,38,77,204,111,249,171,78,38,56,202,50,10,113,185,35,2,83,108,219,216,212,127,246,17,119,59,36,48,148,148,245,117,126,67];
H[21]=[254,31,100,169,180,19,106,187,149,90,9,231,94,129,211,19,193,63,95,237,157,123,138,46,4,76,179,239,16,251,56,118,93,44,7,188,17,25,109,236,110,144,39,139,116,55,24,168,135,225,120,215,84,47,58,212,148,198,122,237,39,32,27,31,126,40,191,201,246,233,183,57,135,200,81,108,4,212,167,174,95,202,133,73,42,166,163,137,195,149,18,108,89,9,245,143,195,132,127,204,179,209,140,221,222,72,44,23,112,240,239,242,152,153,74,249,143,238,221,196,181,254,188,201,163,40,128,242,224,100,93,93,17,249,29,96,160,57,41,49,187,240,228,237,66,2,113,28,116,104,188,180,182,193,212,129,143,176,238,110,228,1,167,234,185,58,90,212,224,26,111,76,170,164,185,246,124,10,157,96,179,1,195,106,126,209,202,243,227,128,206,180,3,204,91,227,57,175,170,251,40,77,14,98,16,33,216,174,214,21,244,15,126,37,200,151,123,63,214,51,123,189,86,236,155,74,200,88,60,188,27,212,91,196,8,98,93,32,158,175,84,186,21,166,156,43,136,22,61,46,229,115,192,125,42,230];
H[22]=[39,62,141,209,201,190,194,12,165,125,180,190,67,155,12,223,5,205,78,184,214,210,166,32,192,89,234,162,167,125,201,235,222,151,193,147,188,244,164,228,44,59,227,56,216,221,115,249,119,76,45,212,108,189,16,144,44,95,22,11,206,251,208,3,241,233,35,236,117,121,166,146,44,113,207,255,90,220,44,101,147,12,234,13,192,136,93,58,224,132,250,254,127,3,35,225,131,166,38,37,129,251,227,185,215,96,6,249,7,242,41,180,172,99,25,147,156,97,188,144,118,159,159,200,166,181,255,159,178,40,54,140,88,254,208,238,115,122,124,198,109,234,228,42,129,126,27,190,140,74,173,77,206,62,165,15,185,180,98,243,121,95,230,62,89,7,144,131,182,88,242,100,237,41,216,76,136,33,250,112,130,119,160,14,193,138,92,222,27,237,219,196,186,246,230,33,187,69,111,67,108,229,45,198,184,170,208,98,50,70,156,183,162,50,12,106,229,29,172,70,26,210,12,242,63,204,74,99,251,88,57,197,13,241,6,99,75,197,98,105,9,247,17,110,232,100,234,155,223,223,115,66,28,47,245,231];
H[23]=[104,51,162,141,37,102,13,203,112,138,211,210,79,60,139,227,190,197,19,213,82,178,112,77,94,115,33,242,209,128,103,13,120,45,213,219,20,234,255,28,140,201,137,255,131,243,193,53,187,81,9,219,129,115,58,252,141,122,16,62,14,43,243,112,65,130,141,245,218,87,232,191,138,4,53,103,159,254,96,86,149,207,49,97,55,58,192,162,28,52,90,65,122,91,133,198,39,48,81,89,161,222,105,49,39,134,60,80,221,68,225,91,171,135,13,78,93,67,224,6,89,19,192,151,120,212,67,168,122,227,141,20,158,144,43,153,45,210,182,213,25,244,63,219,226,254,213,100,67,247,165,3,66,25,223,70,52,161,15,156,201,33,51,195,124,42,174,81,27,184,59,23,182,114,141,151,34,235,178,23,9,217,115,31,165,148,14,228,15,139,71,34,134,122,11,103,234,17,203,144,112,224,68,228,38,241,244,149,105,172,26,216,64,104,197,69,227,124,103,203,70,90,17,210,51,144,84,226,154,63,94,239,102,255,210,57,186,216,139,48,105,191,47,255,173,98,83,167,155,185,115,23,151,230,15,205];
H[24]=[10,79,69,243,140,220,21,174,195,56,168,40,241,130,130,128,253,251,54,98,178,208,141,96,189,208,142,155,237,6,141,61,113,126,19,235,39,47,56,250,31,49,144,164,125,128,110,147,197,77,246,105,122,162,19,189,57,66,143,233,157,112,136,151,81,66,91,214,131,63,94,179,221,145,127,193,202,250,15,206,54,89,214,24,107,215,64,57,141,101,140,53,248,115,162,22,137,52,154,23,19,77,100,35,170,252,133,164,89,207,192,198,79,199,38,221,60,46,253,253,238,139,76,20,221,106,117,176,131,238,77,160,39,206,202,91,184,168,188,85,71,196,227,121,120,58,97,94,41,123,151,230,126,152,131,117,73,52,9,91,225,121,223,161,180,177,146,229,82,201,12,161,47,99,84,247,134,60,171,93,142,164,29,12,30,189,205,108,213,68,137,90,21,96,111,211,195,251,228,34,57,139,110,82,146,141,175,110,219,158,255,225,105,180,86,41,196,138,1,229,207,251,246,230,107,101,54,12,105,163,88,20,82,227,91,77,174,151,74,1,82,91,148,198,11,229,169,25,225,96,115,147,70,216,241,7];
H[25]=[107,41,243,19,222,27,171,168,244,150,83,35,121,20,41,182,226,223,122,166,90,32,130,215,82,186,124,69,202,193,48,175,103,111,102,148,19,248,144,39,219,107,51,197,22,37,101,14,99,211,197,50,163,16,90,5,206,140,238,118,59,110,61,159,36,177,176,50,26,84,23,150,110,202,169,235,17,77,59,8,210,241,250,233,11,30,203,134,50,148,240,42,8,72,156,210,124,196,107,70,172,61,60,252,19,139,75,250,195,169,61,203,113,9,49,147,67,191,121,218,109,167,2,235,15,53,14,214,116,126,182,105,149,108,196,248,207,122,140,84,105,79,110,131,111,55,244,28,200,129,185,106,100,217,164,54,7,164,248,164,114,192,160,145,150,96,248,46,70,229,87,173,193,179,225,214,175,241,77,11,96,112,129,200,86,150,253,225,22,138,85,130,196,177,66,80,114,31,30,244,52,76,38,132,37,172,86,165,212,80,233,98,103,165,185,202,174,137,77,68,87,50,207,64,119,123,17,249,36,76,213,168,215,219,51,79,153,173,91,72,11,234,128,146,18,228,95,49,195,1,115,189,144,127,45,23];
H[26]=[79,183,233,5,15,80,239,67,250,115,135,212,108,126,68,75,103,56,162,247,211,213,220,160,220,64,245,36,48,95,248,69,102,89,11,217,108,99,71,60,88,176,201,175,235,190,242,143,224,90,202,15,81,80,143,207,153,249,95,173,81,215,67,9,176,39,158,70,43,59,165,87,252,203,196,215,204,159,145,85,151,33,82,166,158,139,178,238,65,16,189,233,77,148,248,218,228,32,234,138,179,93,249,78,184,10,244,107,138,143,215,40,20,202,91,78,147,50,225,165,138,246,88,99,56,148,236,196,24,156,212,111,253,218,148,132,26,210,12,79,199,225,200,12,238,52,66,15,233,20,216,255,9,255,10,138,250,130,58,83,69,26,180,205,214,122,240,163,224,185,217,110,117,75,156,25,226,76,129,145,111,1,195,103,104,216,82,196,97,127,72,103,36,42,155,6,113,131,216,13,105,5,134,184,241,125,177,174,230,72,185,180,191,34,228,142,141,49,156,156,184,57,95,104,4,152,83,154,158,200,202,203,130,171,183,204,56,51,41,141,202,166,245,42,89,84,27,229,254,36,115,134,170,171,237,185];
H[27]=[18,229,4,177,254,124,173,20,8,33,15,156,39,12,186,116,51,186,87,4,77,80,98,100,72,89,91,122,44,187,224,223,42,13,226,57,245,89,143,118,5,77,227,188,245,113,134,13,125,178,201,178,94,13,48,220,3,151,107,133,212,57,9,77,16,235,157,213,30,175,131,7,85,168,245,26,57,112,89,181,87,68,20,229,37,84,110,250,165,36,66,182,157,26,141,162,141,211,239,21,236,66,217,114,108,59,6,75,61,252,129,51,116,171,8,221,132,72,69,176,93,21,72,163,101,74,193,6,159,183,250,95,245,45,82,198,86,168,32,23,171,181,83,222,12,12,70,167,53,131,220,160,216,142,81,100,156,235,213,29,157,75,44,62,233,246,181,20,136,83,8,59,173,220,203,159,182,31,240,91,91,40,190,143,108,194,195,234,82,166,35,24,205,7,106,71,39,102,179,243,116,107,196,151,186,232,81,130,143,84,46,31,249,19,173,150,221,39,150,9,15,62,158,81,195,237,186,120,140,118,250,202,249,75,65,199,240,71,112,252,99,158,28,92,200,46,219,213,239,100,115,225,15,19,195,207];
H[28]=[197,150,19,236,34,227,78,64,152,237,158,48,188,42,205,217,132,252,229,12,81,83,219,253,116,115,81,243,200,68,156,249,183,71,166,121,121,4,5,145,62,70,137,193,144,197,44,149,24,82,61,91,220,57,78,133,139,78,13,16,23,33,182,194,117,98,98,232,87,137,10,166,184,20,143,106,49,136,1,87,142,97,178,92,174,140,209,87,55,65,229,200,241,123,201,48,11,115,146,185,202,138,243,117,31,87,60,90,251,186,80,141,9,24,229,147,209,8,67,212,77,189,178,90,7,37,9,151,95,6,130,194,204,213,8,165,120,122,11,236,11,108,195,175,116,224,121,253,254,220,197,174,143,120,103,252,231,201,5,190,67,71,167,195,85,237,32,135,8,175,145,80,61,100,98,57,163,89,159,90,197,52,229,25,33,33,48,248,244,101,197,56,80,142,199,36,144,32,163,104,155,199,205,248,100,78,15,50,84,185,28,83,232,98,182,52,178,132,94,228,45,137,89,80,255,155,99,116,195,159,230,145,203,150,18,189,121,102,4,66,71,194,229,59,98,237,52,77,127,145,115,240,142,26,185,219];
H[29]=[247,65,6,183,62,139,188,239,192,217,14,201,189,4,138,98,114,143,164,20,76,136,123,172,140,208,47,139,73,118,236,187,241,41,95,38,25,140,30,162,171,83,144,90,9,73,102,58,153,214,171,61,140,221,53,47,50,14,151,169,155,236,43,250,148,23,60,59,35,10,103,195,62,239,101,244,81,16,193,231,95,96,124,182,225,89,79,218,98,213,14,238,111,22,13,13,143,203,163,251,143,5,124,42,245,8,133,62,44,56,216,19,49,109,253,78,98,156,244,226,251,60,200,112,47,156,154,138,211,164,132,94,201,212,31,121,130,210,195,124,119,224,72,184,27,151,118,89,158,204,210,94,20,213,205,21,204,97,7,236,198,101,215,161,160,111,9,122,183,125,101,125,221,224,133,128,225,20,135,56,57,115,45,104,6,162,175,89,186,130,14,147,217,160,200,141,63,66,232,203,229,73,217,208,120,186,141,200,128,247,38,238,161,226,87,157,43,131,239,225,195,78,24,114,218,222,19,141,133,72,30,4,8,49,4,17,223,142,186,103,254,173,33,189,252,13,156,109,249,169,115,47,171,200,115,208];
H[30]=[62,169,72,204,185,245,212,68,243,29,50,167,253,5,103,56,136,153,222,116,205,165,17,148,117,233,199,241,212,202,42,132,197,122,189,64,104,48,156,110,255,181,105,49,73,62,28,234,212,89,111,181,134,220,247,7,107,181,60,14,11,53,117,134,125,58,230,191,182,195,68,183,48,93,40,67,252,182,201,209,222,98,166,125,227,140,238,205,129,93,191,253,79,22,199,129,71,207,155,177,99,97,55,200,12,32,129,42,75,201,102,90,101,179,75,158,79,1,106,211,2,243,62,161,133,138,4,71,39,167,117,64,104,31,228,229,22,60,204,212,37,225,229,17,198,243,43,45,147,1,196,33,135,229,68,35,52,181,143,129,99,240,153,67,82,25,147,197,207,194,126,103,31,168,128,70,180,211,252,111,199,77,160,162,68,242,67,139,101,233,81,36,188,238,166,68,148,83,147,119,80,147,31,39,164,135,173,92,210,211,45,94,70,200,43,154,183,157,148,89,91,98,78,87,6,226,40,222,61,107,150,12,242,124,9,143,228,185,193,19,206,124,106,192,127,143,73,80,90,148,91,131,156,172,65,144];
H[31]=[238,199,89,169,193,58,5,24,86,249,61,179,223,158,74,16,223,170,19,128,35,186,194,85,157,63,83,85,18,95,56,203,206,226,25,37,185,70,39,112,178,123,196,204,59,124,105,137,40,147,11,85,165,162,162,206,135,75,47,35,119,108,199,27,247,196,12,125,171,145,109,66,11,65,202,32,126,69,106,3,134,199,187,219,35,98,207,149,231,54,198,114,108,201,179,115,232,106,204,247,177,118,53,78,237,159,169,162,213,66,106,161,4,27,222,143,23,16,168,208,222,246,188,43,72,25,73,153,201,193,200,203,244,18,11,145,94,218,60,64,153,19,170,104,147,102,134,59,132,126,163,233,135,172,245,131,151,186,168,21,56,51,32,123,3,189,80,93,199,55,159,76,111,151,150,133,233,170,104,239,118,215,92,226,155,2,33,70,102,211,2,124,214,101,4,159,221,186,232,168,243,51,229,173,16,29,163,26,85,72,185,169,101,231,192,238,158,206,114,124,128,62,240,128,121,126,92,69,129,203,153,163,166,254,61,176,64,230,101,121,246,152,203,131,193,11,40,19,199,235,95,162,110,24,128,46];

pass=document.oreore.password.value;
for(var i=0;i<16;i++)
{
ss[i] = pass.charCodeAt(i);
}

        for(var i=0;i<N;i++) 
        {
                for(var j=0;j<16;j++) 
                {
      		sn[i]^=gf[mlt(fg[H[i][ps[j]]],fg[ss[j]])];
                }
	if(sn[i]!=sig[i])
	var f=1;
        }
}

sub mlt(var x, var y){

    if(x==0||y==0)

       return 0;

 return ((x+y-2)%255)+1;

}

</script>