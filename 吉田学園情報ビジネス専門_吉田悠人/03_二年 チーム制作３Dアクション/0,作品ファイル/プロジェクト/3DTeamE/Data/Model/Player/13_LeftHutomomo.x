xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 151;
 4.72080;-14.00650;-13.13700;,
 0.46290;-15.60820;-13.26330;,
 0.48990;0.50260;-14.80190;,
 3.62860;1.74450;-13.61840;,
 -3.61530;-17.04070;-11.50010;,
 -2.44930;-0.29120;-15.36410;,
 -1.35920;-0.32870;13.29200;,
 -0.65390;-12.68680;14.03150;,
 1.60970;-11.85280;14.35580;,
 0.54010;0.28300;13.08470;,
 -4.16840;-15.93920;10.12250;,
 -4.24730;-0.18150;12.02870;,
 13.26920;-10.22800;0.67560;,
 13.42820;-10.35660;-4.39420;,
 11.59140;3.22340;-4.22450;,
 11.34170;3.31930;0.29880;,
 11.89140;-10.97180;-8.63100;,
 10.19510;3.03850;-8.15660;,
 4.00920;-32.70020;12.40400;,
 0.95960;-33.64740;10.99690;,
 1.41380;-37.94480;11.26850;,
 4.58940;-37.25020;12.57660;,
 -1.39010;-34.13380;8.60730;,
 -0.98700;-38.43140;8.78950;,
 13.38580;-30.64080;-6.30670;,
 14.99970;-30.11900;-2.25950;,
 15.16370;-35.78780;-1.59010;,
 13.55680;-36.25480;-5.54940;,
 15.07590;-29.71020;2.24320;,
 15.33350;-35.37550;2.73810;,
 -1.29670;-33.76990;-6.94800;,
 1.97750;-33.03720;-9.43720;,
 2.47520;-38.12360;-8.50380;,
 -0.66600;-38.58720;-5.97560;,
 6.09920;-32.17040;-10.24510;,
 6.42300;-37.51140;-9.38390;,
 -3.54280;-34.33750;0.99140;,
 -3.12240;-34.23890;-3.20670;,
 -2.49410;-38.82000;-2.44110;,
 -2.98520;-38.80790;1.52140;,
 -1.39010;-34.13380;8.60730;,
 -2.90500;-34.34500;5.11970;,
 -2.41330;-38.68300;5.39550;,
 -0.98700;-38.43140;8.78950;,
 13.80300;-29.73020;6.62900;,
 14.19250;-35.30460;6.91020;,
 11.26760;-30.21710;10.32180;,
 11.76540;-35.63430;10.40610;,
 8.81460;-9.17240;10.91320;,
 11.01800;-8.64360;8.04740;,
 9.33040;2.15780;7.36140;,
 7.21770;1.88070;9.89030;,
 -3.19150;5.15110;8.44890;,
 -1.29750;5.51220;8.59140;,
 -5.04360;4.72900;8.27130;,
 7.11480;7.10460;3.76000;,
 4.58000;6.63040;6.85370;,
 8.94210;7.44370;-0.42350;,
 9.16610;7.47810;-4.26120;,
 8.08260;7.26360;-8.01680;,
 -0.94500;5.53820;-14.32930;,
 2.50380;6.18970;-13.26750;,
 -3.63990;4.98820;-14.92250;,
 1.64100;6.07140;8.24540;,
 3.97220;1.11470;12.17200;,
 5.24530;-10.41840;13.54320;,
 7.73670;-31.21840;12.38860;,
 8.26070;-36.34620;12.44130;,
 10.22130;-31.32370;-9.15660;,
 10.47910;-36.82700;-8.31660;,
 8.71600;-12.32770;-11.60170;,
 7.32020;2.73940;-11.31340;,
 5.59290;6.78360;-10.69790;,
 -6.47390;-0.82080;-15.81710;,
 -6.47390;-15.00710;-11.26570;,
 -6.47390;4.54920;8.24000;,
 -6.47390;-0.94940;11.87290;,
 -4.16840;-15.93920;10.12250;,
 -6.47390;-14.08630;8.92740;,
 -6.47390;-16.67680;4.25200;,
 -5.24050;-18.76930;4.45440;,
 -5.45530;-19.55450;-6.54690;,
 -6.47390;-17.03020;-6.78380;,
 -6.47390;-17.20100;-1.64920;,
 -5.68090;-19.57960;-1.36390;,
 -6.47390;-14.08630;8.92740;,
 -6.47390;4.33200;-14.86760;,
 0.72740;-21.57850;-12.00640;,
 -3.05210;-22.88290;-9.72470;,
 5.28720;-20.05810;-12.48460;,
 -4.81680;-23.72480;-5.68870;,
 -5.10740;-23.95140;-0.62810;,
 -4.48760;-23.42310;4.72600;,
 -2.99680;-22.45550;9.29960;,
 -0.67570;-21.37180;12.02210;,
 2.33410;-20.06650;13.09230;,
 -2.99680;-22.45550;9.29960;,
 5.89110;-18.43430;12.70900;,
 9.40850;-17.05680;10.53550;,
 12.29910;-16.51580;6.23180;,
 14.04790;-16.50740;0.98760;,
 14.14350;-16.74270;-3.98250;,
 12.60520;-17.37360;-8.19040;,
 9.45080;-18.55970;-11.12540;,
 1.21090;4.90810;-4.02340;,
 0.65400;4.62290;-0.26810;,
 3.67020;5.31420;-0.34170;,
 4.37130;5.58350;-4.05720;,
 -1.71660;4.28250;-3.99210;,
 -4.18040;3.79030;-3.96750;,
 -4.35170;3.55890;-0.15450;,
 -1.96510;4.02260;-0.20400;,
 -6.47390;3.40050;-0.15190;,
 -6.47390;3.27770;4.12170;,
 -4.54330;3.30020;4.11790;,
 -2.24330;3.73160;4.04450;,
 0.03000;4.30540;3.94700;,
 2.88340;5.02570;3.82490;,
 2.50380;6.18970;-13.26750;,
 5.59290;6.78360;-10.69790;,
 -0.94500;5.53820;-14.32930;,
 -3.63990;4.98820;-14.92250;,
 -6.47390;4.33200;-14.86760;,
 -6.47390;3.50960;-3.95340;,
 -6.47390;4.54920;8.24000;,
 -5.04360;4.72900;8.27130;,
 -3.19150;5.15110;8.44890;,
 -1.29750;5.51220;8.59140;,
 1.64100;6.07140;8.24540;,
 7.11480;7.10460;3.76000;,
 4.58000;6.63040;6.85370;,
 8.94210;7.44370;-0.42350;,
 9.16610;7.47810;-4.26120;,
 8.08260;7.26360;-8.01680;,
 1.82120;-42.28060;11.74650;,
 5.05610;-41.74490;12.99120;,
 -0.58890;-42.73160;9.24010;,
 16.62270;-41.03950;-1.53430;,
 13.73360;-41.49380;-4.82730;,
 16.87980;-40.52070;3.54140;,
 2.93110;-43.03390;-7.75990;,
 -0.20210;-43.30240;-5.22230;,
 6.81500;-42.58130;-8.62040;,
 -2.02570;-43.37000;-1.78640;,
 -2.54630;-43.25000;2.06490;,
 -2.01430;-43.03180;5.83600;,
 -0.58890;-42.73160;9.24010;,
 15.59320;-40.29060;8.45210;,
 12.11000;-40.66920;10.68970;,
 8.68600;-41.14640;12.74330;,
 10.74270;-42.01920;-7.57100;;
 
 140;
 4;0,1,2,3;,
 4;2,1,4,5;,
 4;6,7,8,9;,
 4;10,7,6,11;,
 4;12,13,14,15;,
 4;14,13,16,17;,
 4;18,19,20,21;,
 4;20,19,22,23;,
 4;24,25,26,27;,
 4;26,25,28,29;,
 4;30,31,32,33;,
 4;32,31,34,35;,
 4;36,37,38,39;,
 4;38,37,30,33;,
 4;40,41,42,43;,
 4;42,41,36,39;,
 4;28,44,45,29;,
 4;45,44,46,47;,
 4;48,49,50,51;,
 4;50,49,12,15;,
 4;52,6,9,53;,
 4;11,6,52,54;,
 4;51,50,55,56;,
 4;55,50,15,57;,
 4;15,14,58,57;,
 4;58,14,17,59;,
 4;3,2,60,61;,
 4;60,2,5,62;,
 4;63,64,51,56;,
 4;9,64,63,53;,
 4;8,65,64,9;,
 4;64,65,48,51;,
 4;46,66,67,47;,
 4;67,66,18,21;,
 4;34,68,69,35;,
 4;69,68,24,27;,
 4;16,70,71,17;,
 4;71,70,0,3;,
 4;17,71,72,59;,
 4;72,71,3,61;,
 4;73,5,4,74;,
 4;54,75,76,11;,
 4;77,78,79,80;,
 4;4,81,82,74;,
 4;83,82,81,84;,
 4;11,76,85,10;,
 4;62,5,73,86;,
 4;1,87,88,4;,
 4;88,87,31,30;,
 4;31,87,89,34;,
 4;89,87,1,0;,
 4;81,90,91,84;,
 4;91,90,37,36;,
 4;37,90,88,30;,
 4;88,90,81,4;,
 4;80,92,93,77;,
 4;93,92,41,40;,
 4;41,92,91,36;,
 4;91,92,80,84;,
 4;7,94,95,8;,
 4;95,94,19,18;,
 4;19,94,96,22;,
 4;96,94,7,10;,
 4;66,97,95,18;,
 4;95,97,65,8;,
 4;65,97,98,48;,
 4;98,97,66,46;,
 4;49,99,100,12;,
 4;100,99,44,28;,
 4;44,99,98,46;,
 4;98,99,49,48;,
 4;13,101,102,16;,
 4;102,101,25,24;,
 4;25,101,100,28;,
 4;100,101,13,12;,
 4;70,103,89,0;,
 4;89,103,68,34;,
 4;68,103,102,24;,
 4;102,103,70,16;,
 4;104,105,106,107;,
 4;108,109,110,111;,
 4;110,112,113,114;,
 4;111,110,114,115;,
 4;106,105,116,117;,
 4;118,104,107,119;,
 4;120,121,109,108;,
 4;122,123,109,121;,
 4;114,113,124,125;,
 4;115,114,125,126;,
 4;117,116,127,128;,
 4;129,117,128,130;,
 4;131,106,117,129;,
 4;107,106,131,132;,
 4;119,107,132,133;,
 4;120,108,104,118;,
 4;108,111,105,104;,
 4;116,105,111,115;,
 4;127,116,115,126;,
 4;83,84,80,79;,
 4;110,109,123,112;,
 4;20,134,135,21;,
 4;23,136,134,20;,
 4;26,137,138,27;,
 4;29,139,137,26;,
 4;32,140,141,33;,
 4;35,142,140,32;,
 4;38,143,144,39;,
 4;33,141,143,38;,
 4;42,145,146,43;,
 4;39,144,145,42;,
 4;45,147,139,29;,
 4;47,148,147,45;,
 4;67,149,148,47;,
 4;21,135,149,67;,
 4;69,150,142,35;,
 4;27,138,150,69;,
 3;76,124,85;,
 3;85,124,79;,
 3;124,113,79;,
 3;79,113,83;,
 3;113,112,83;,
 3;112,123,83;,
 3;83,123,82;,
 3;123,86,82;,
 3;82,86,74;,
 3;86,73,74;,
 3;137,139,138;,
 3;139,147,138;,
 3;138,147,150;,
 3;147,148,150;,
 3;150,148,142;,
 3;148,149,142;,
 3;142,149,140;,
 3;149,135,140;,
 3;140,135,141;,
 3;135,134,141;,
 3;141,134,143;,
 3;134,146,143;,
 3;143,146,144;,
 3;146,145,144;;
 
 MeshMaterialList {
  16;
  140;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.736000;0.544000;0.432000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.400000;0.400000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.056000;0.048000;0.048000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.024000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.008000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.784000;0.800000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.048000;0.048000;0.048000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.736000;0.544000;0.432000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.016000;0.016000;0.016000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.016000;0.016000;0.016000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  162;
  -0.415250;-0.468530;-0.779774;,
  -0.007431;-0.066180;-0.997780;,
  -0.991746;-0.127898;0.009109;,
  -0.976292;-0.194576;-0.094834;,
  0.025000;0.128236;-0.991429;,
  -0.134975;0.988820;0.063380;,
  -0.975720;-0.198114;0.093385;,
  -0.896703;-0.210487;0.389382;,
  -0.235348;0.215269;0.947771;,
  -0.167290;0.567133;0.806458;,
  -0.053523;0.989278;-0.135885;,
  -0.457940;-0.325580;-0.827218;,
  0.830820;0.083639;-0.550220;,
  0.097769;0.129230;-0.986783;,
  0.766997;0.419250;-0.485741;,
  -0.964691;-0.261917;0.027776;,
  0.920860;0.344424;0.182729;,
  0.810491;0.269774;-0.519929;,
  0.023516;-0.037619;-0.999015;,
  -0.068616;0.632699;0.771352;,
  0.050805;-0.022502;0.998455;,
  0.084486;-0.169744;-0.981860;,
  -0.829360;-0.098165;0.550024;,
  0.672427;0.078234;0.736017;,
  0.988223;0.073157;0.134397;,
  -0.052581;-0.155857;-0.986379;,
  -0.201253;0.598277;0.775604;,
  -0.337961;0.254260;0.906164;,
  0.560166;0.423420;0.711990;,
  -0.921075;-0.320377;0.221312;,
  0.882782;0.114214;0.455687;,
  -0.831276;-0.162840;0.531472;,
  0.687170;0.040989;0.725339;,
  0.829600;0.012107;-0.558227;,
  -0.683157;-0.259743;-0.682517;,
  -0.909767;-0.336358;-0.243285;,
  -0.988777;-0.146728;0.028109;,
  0.979626;0.118312;-0.162284;,
  0.978370;0.131978;0.159293;,
  -0.692374;-0.237055;0.681486;,
  0.938042;0.315475;-0.143366;,
  0.143719;0.649251;0.746872;,
  -0.058397;-0.111910;0.992001;,
  0.151577;0.022535;-0.988189;,
  0.259011;-0.056645;-0.964212;,
  0.369370;0.102400;-0.923623;,
  0.150942;-0.140511;-0.978506;,
  -0.721827;-0.240348;-0.648998;,
  -0.340304;-0.223763;-0.913303;,
  -0.990109;-0.138288;0.023674;,
  -0.940958;-0.193621;-0.277687;,
  -0.957668;-0.111418;0.265440;,
  -0.168731;-0.029196;0.985230;,
  -0.552490;-0.073856;0.830241;,
  0.982694;0.104087;0.153225;,
  0.896664;0.095484;0.432292;,
  0.826548;-0.040155;-0.561432;,
  0.980667;0.023994;-0.194206;,
  0.500294;-0.107729;-0.859128;,
  -0.381143;-0.086171;0.920492;,
  0.272528;0.416294;0.867426;,
  0.276764;0.027930;0.960532;,
  0.550808;0.025253;-0.834250;,
  0.590914;0.192876;-0.783339;,
  -0.239368;-0.226440;-0.944155;,
  -0.945359;-0.200261;-0.257278;,
  -0.962177;-0.142397;0.232245;,
  -0.490199;-0.164245;0.855996;,
  0.344319;-0.026591;0.938476;,
  0.892847;0.088387;0.441601;,
  0.981772;0.070977;-0.176311;,
  0.518270;-0.059067;-0.853175;,
  0.404662;0.213583;-0.889174;,
  0.488609;-0.105620;-0.866086;,
  0.961261;0.096808;-0.258080;,
  0.978466;0.178825;0.103079;,
  0.866064;0.185656;0.464183;,
  0.267284;0.066023;0.961353;,
  -0.186280;0.041570;0.981617;,
  -0.563948;0.007473;0.825776;,
  -0.831197;-0.036865;0.554755;,
  -0.959154;-0.075464;0.272632;,
  -0.993665;-0.111406;0.014758;,
  -0.942761;-0.157352;-0.294009;,
  -0.747689;-0.193167;-0.635332;,
  -0.396527;-0.189830;-0.898182;,
  0.047508;-0.154303;-0.986881;,
  0.223998;0.143306;-0.963996;,
  -0.211749;0.570795;0.793319;,
  0.865839;0.484238;-0.125844;,
  0.825968;0.527901;0.197729;,
  0.665023;0.598910;0.446153;,
  0.416805;0.652634;0.632726;,
  0.594745;0.318584;-0.738094;,
  -0.129975;0.990371;0.047656;,
  -0.206459;0.977190;0.049751;,
  -0.206356;0.975523;0.075975;,
  -0.167321;0.983425;0.069842;,
  -0.120485;0.982652;-0.140986;,
  -0.203371;0.968619;-0.142888;,
  -0.315348;0.937508;-0.147085;,
  -0.308368;0.951267;0.001054;,
  -0.290386;0.955196;0.057247;,
  -0.219367;0.972666;0.076148;,
  -0.223971;0.973767;0.040189;,
  -0.226912;0.964226;-0.137040;,
  -0.070350;0.996626;0.042286;,
  0.040732;-0.146834;-0.988322;,
  0.488408;-0.101387;-0.866706;,
  0.580222;0.165714;0.797422;,
  0.273507;0.088197;0.957818;,
  -0.174979;0.070053;0.982077;,
  -0.561580;0.032451;0.826786;,
  -0.834302;-0.018947;0.550981;,
  -0.960919;-0.061643;0.269879;,
  -0.995156;-0.097780;0.010165;,
  -0.943857;-0.139368;-0.299516;,
  -0.754731;-0.172026;-0.633079;,
  -0.410008;-0.175190;-0.895099;,
  0.004469;0.386855;0.922130;,
  0.680849;0.080949;0.727936;,
  0.388772;0.040424;0.920447;,
  0.932308;0.186589;-0.309817;,
  0.950236;0.300081;0.083686;,
  0.818546;0.290795;0.495400;,
  0.626368;0.120374;0.770177;,
  0.769971;0.007378;-0.638036;,
  0.797254;-0.021441;-0.603263;,
  0.790843;0.393049;0.469126;,
  -0.269866;0.333846;0.903172;,
  -0.223198;0.968525;0.110188;,
  -0.285841;0.953016;0.100272;,
  -0.208860;0.972648;0.101656;,
  -0.189291;0.977568;0.092351;,
  -0.171991;0.981428;0.084963;,
  -0.062383;0.948601;-0.310266;,
  -0.121911;0.937873;-0.324857;,
  -0.190012;0.924763;-0.329709;,
  -0.214170;0.926889;-0.308234;,
  -0.302685;0.911271;-0.279226;,
  -0.393451;0.905459;-0.159188;,
  -0.374354;0.889611;-0.261632;,
  -0.389908;0.920310;-0.031658;,
  -0.353903;0.934525;0.037638;,
  -0.335673;0.938271;0.083494;,
  -1.000000;0.000000;0.000000;,
  0.042986;-0.994115;0.099434;,
  0.075478;-0.993334;0.087128;,
  0.085432;-0.992870;0.083126;,
  0.120119;-0.990245;0.070609;,
  0.125701;-0.989804;0.066989;,
  0.146617;-0.987427;0.059090;,
  0.140139;-0.988497;0.056880;,
  0.153747;-0.986827;0.050340;,
  0.139221;-0.989025;0.049476;,
  0.145835;-0.988285;0.045001;,
  0.131291;-0.990308;0.045304;,
  0.138188;-0.989523;0.041808;,
  0.122399;-0.991563;0.042676;,
  0.117937;-0.992146;0.041673;,
  0.104296;-0.993602;0.043334;,
  0.108478;-0.993204;0.042165;;
  140;
  4;44,25,43,45;,
  4;43,25,11,18;,
  4;129,59,20,119;,
  4;39,59,129,27;,
  4;38,37,40,16;,
  4;40,37,12,17;,
  4;52,53,79,78;,
  4;79,53,22,80;,
  4;56,57,74,127;,
  4;74,57,24,75;,
  4;47,48,85,84;,
  4;85,48,21,86;,
  4;49,50,83,82;,
  4;83,50,47,84;,
  4;22,51,81,80;,
  4;81,51,49,82;,
  4;24,55,76,75;,
  4;76,55,23,125;,
  4;120,30,128,28;,
  4;128,30,38,16;,
  4;26,129,119,19;,
  4;27,129,26,88;,
  4;28,128,91,92;,
  4;91,128,16,90;,
  4;16,40,89,90;,
  4;89,40,17,14;,
  4;45,43,87,72;,
  4;87,43,18,13;,
  4;41,60,28,92;,
  4;119,60,41,19;,
  4;20,121,60,119;,
  4;60,121,120,28;,
  4;23,61,77,125;,
  4;77,61,52,78;,
  4;21,58,73,86;,
  4;73,58,56,127;,
  4;12,62,63,17;,
  4;63,62,44,45;,
  4;17,63,93,14;,
  4;93,63,45,72;,
  4;1,18,11,0;,
  4;88,9,8,27;,
  4;39,7,6,29;,
  4;11,35,3,0;,
  4;2,3,35,15;,
  4;27,8,7,39;,
  4;13,18,1,4;,
  4;25,64,34,11;,
  4;34,64,48,47;,
  4;48,64,46,21;,
  4;46,64,25,44;,
  4;35,65,36,15;,
  4;36,65,50,49;,
  4;50,65,34,47;,
  4;34,65,35,11;,
  4;29,66,31,39;,
  4;31,66,51,22;,
  4;51,66,36,49;,
  4;36,66,29,15;,
  4;59,67,42,20;,
  4;42,67,53,52;,
  4;53,67,31,22;,
  4;31,67,59,39;,
  4;61,68,42,52;,
  4;42,68,121,20;,
  4;121,68,32,120;,
  4;32,68,61,23;,
  4;30,69,54,38;,
  4;54,69,55,24;,
  4;55,69,32,23;,
  4;32,69,30,120;,
  4;37,70,33,12;,
  4;33,70,57,56;,
  4;57,70,54,24;,
  4;54,70,37,38;,
  4;62,71,46,44;,
  4;46,71,58,21;,
  4;58,71,33,56;,
  4;33,71,62,12;,
  4;103,104,101,102;,
  4;96,97,94,95;,
  4;94,106,10,98;,
  4;95,94,98,99;,
  4;101,104,105,100;,
  4;130,103,102,131;,
  4;132,133,97,96;,
  4;134,5,97,133;,
  4;98,10,135,136;,
  4;99,98,136,137;,
  4;100,105,138,139;,
  4;140,100,139,141;,
  4;142,101,100,140;,
  4;102,101,142,143;,
  4;131,102,143,144;,
  4;132,96,103,130;,
  4;96,95,104,103;,
  4;105,104,95,99;,
  4;138,105,99,137;,
  4;2,15,29,6;,
  4;94,97,5,106;,
  4;79,112,111,78;,
  4;80,113,112,79;,
  4;74,122,126,127;,
  4;75,123,122,74;,
  4;85,118,117,84;,
  4;86,107,118,85;,
  4;83,116,115,82;,
  4;84,117,116,83;,
  4;81,114,113,80;,
  4;82,115,114,81;,
  4;76,124,123,75;,
  4;125,109,124,76;,
  4;77,110,109,125;,
  4;78,111,110,77;,
  4;73,108,107,86;,
  4;127,126,108,73;,
  3;145,145,7;,
  3;7,145,6;,
  3;145,145,6;,
  3;6,145,2;,
  3;145,145,2;,
  3;145,145,2;,
  3;2,145,3;,
  3;145,145,3;,
  3;3,145,145;,
  3;145,145,145;,
  3;146,147,148;,
  3;147,149,148;,
  3;148,149,150;,
  3;149,151,150;,
  3;150,151,152;,
  3;151,153,152;,
  3;152,153,154;,
  3;153,155,154;,
  3;154,155,156;,
  3;155,157,156;,
  3;156,157,158;,
  3;157,159,158;,
  3;158,159,160;,
  3;159,161,160;;
 }
 MeshTextureCoords {
  151;
  0.245870;0.742290;,
  0.242780;0.770000;,
  0.155820;0.722050;,
  0.159790;0.700930;,
  0.240840;0.799630;,
  0.150800;0.740020;,
  0.253720;0.503820;,
  0.322850;0.520830;,
  0.315110;0.531990;,
  0.248860;0.513630;,
  0.352630;0.497290;,
  0.252880;0.483760;,
  0.273750;0.636210;,
  0.262560;0.663760;,
  0.189810;0.630270;,
  0.200220;0.605720;,
  0.254220;0.688950;,
  0.179360;0.652610;,
  0.439360;0.580860;,
  0.451550;0.561690;,
  0.477190;0.573010;,
  0.466610;0.593020;,
  0.461230;0.542200;,
  0.486500;0.552780;,
  0.366030;0.727640;,
  0.375190;0.702130;,
  0.408740;0.713730;,
  0.399610;0.739600;,
  0.384870;0.675930;,
  0.418230;0.688210;,
  0.346070;0.832240;,
  0.348050;0.805940;,
  0.379400;0.814880;,
  0.376320;0.840190;,
  0.351990;0.779350;,
  0.384050;0.789780;,
  0.344410;0.885170;,
  0.345480;0.858720;,
  0.374220;0.865150;,
  0.372220;0.889990;,
  0.342400;0.934340;,
  0.343690;0.911060;,
  0.370430;0.914120;,
  0.368480;0.936530;,
  0.396320;0.649870;,
  0.429230;0.663120;,
  0.409290;0.624430;,
  0.442090;0.638180;,
  0.289290;0.572730;,
  0.280330;0.590940;,
  0.224200;0.569460;,
  0.230850;0.552700;,
  0.207330;0.486240;,
  0.204580;0.499750;,
  0.210410;0.473200;,
  0.181350;0.566370;,
  0.192160;0.541610;,
  0.169110;0.593940;,
  0.158650;0.617260;,
  0.148570;0.640980;,
  0.120760;0.709690;,
  0.129400;0.687740;,
  0.114840;0.726890;,
  0.199430;0.520000;,
  0.240790;0.532320;,
  0.302400;0.550530;,
  0.423400;0.601370;,
  0.454220;0.614170;,
  0.358030;0.753050;,
  0.390740;0.764240;,
  0.249240;0.715140;,
  0.168090;0.675490;,
  0.138740;0.663180;,
  0.141210;0.762820;,
  0.220990;0.809170;,
  0.212650;0.464150;,
  0.259330;0.469820;,
  0.229680;0.939100;,
  0.213950;0.927660;,
  0.231910;0.900410;,
  0.246650;0.903280;,
  0.253380;0.834850;,
  0.236670;0.833930;,
  0.237300;0.864790;,
  0.252540;0.867170;,
  0.345950;0.480360;,
  0.108220;0.744370;,
  0.277800;0.784440;,
  0.277550;0.813080;,
  0.280370;0.755080;,
  0.279600;0.841020;,
  0.279700;0.872590;,
  0.275830;0.905890;,
  0.270350;0.935530;,
  0.377540;0.531920;,
  0.364030;0.548970;,
  0.391970;0.513090;,
  0.348680;0.568050;,
  0.333890;0.590260;,
  0.320810;0.618910;,
  0.308700;0.649590;,
  0.297930;0.676940;,
  0.289550;0.702110;,
  0.284080;0.727770;,
  0.746950;0.531370;,
  0.762250;0.559580;,
  0.738090;0.567740;,
  0.721750;0.540270;,
  0.770280;0.523140;,
  0.789920;0.516190;,
  0.802330;0.545970;,
  0.783240;0.552500;,
  0.818910;0.539940;,
  0.831710;0.573720;,
  0.816240;0.579340;,
  0.797760;0.585430;,
  0.779430;0.591240;,
  0.756420;0.598550;,
  0.694710;0.463990;,
  0.684720;0.491000;,
  0.728210;0.438980;,
  0.745830;0.422690;,
  0.768500;0.406870;,
  0.807530;0.509890;,
  0.847900;0.616450;,
  0.833020;0.620100;,
  0.817280;0.624940;,
  0.801150;0.629420;,
  0.775260;0.634020;,
  0.713120;0.624130;,
  0.747770;0.634260;,
  0.689750;0.584250;,
  0.680510;0.551830;,
  0.677970;0.517970;,
  0.502770;0.584390;,
  0.493250;0.604440;,
  0.511610;0.564010;,
  0.438640;0.726070;,
  0.428860;0.752230;,
  0.448950;0.698860;,
  0.409280;0.822820;,
  0.405360;0.847440;,
  0.414270;0.798850;,
  0.402320;0.871320;,
  0.399520;0.895140;,
  0.396940;0.918370;,
  0.394330;0.940680;,
  0.460280;0.672190;,
  0.472150;0.646780;,
  0.482740;0.624950;,
  0.420770;0.774960;;
 }
}
