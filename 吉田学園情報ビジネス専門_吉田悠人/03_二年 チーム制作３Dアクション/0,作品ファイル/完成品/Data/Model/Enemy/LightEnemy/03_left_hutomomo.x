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
 110;
 0.63147;-3.38260;-11.71512;,
 1.31137;-3.38805;-11.70467;,
 1.72485;-5.34733;-11.67410;,
 0.60976;-5.34187;-11.68456;,
 1.25931;-7.02514;-10.57418;,
 0.57941;-7.01969;-10.58462;,
 1.31137;-3.38805;-11.70467;,
 1.15511;1.68555;0.75798;,
 1.55407;0.19760;2.33766;,
 1.72485;-5.34733;-11.67410;,
 1.10631;-2.05727;1.97939;,
 1.25931;-7.02514;-10.57418;,
 1.15511;1.68555;0.75798;,
 0.47521;1.69101;0.74753;,
 0.43900;0.20305;2.32722;,
 1.55407;0.19760;2.33766;,
 0.42642;-2.05181;1.96894;,
 1.10631;-2.05727;1.97939;,
 0.47521;1.69101;0.74753;,
 0.63147;-3.38260;-11.71512;,
 0.60976;-5.34187;-11.68456;,
 0.43900;0.20305;2.32722;,
 0.57941;-7.01969;-10.58462;,
 0.42642;-2.05181;1.96894;,
 1.31137;-3.38805;-11.70467;,
 0.63147;-3.38260;-11.71512;,
 0.57941;-7.01969;-10.58462;,
 1.25931;-7.02514;-10.57418;,
 -0.22638;-2.78663;-9.69272;,
 1.02343;-2.78681;-9.67078;,
 1.01337;-4.16698;-9.10941;,
 -0.23644;-4.16679;-9.13136;,
 1.00331;-5.54715;-8.54806;,
 -0.24649;-5.54697;-8.56999;,
 0.84177;1.43661;0.70963;,
 -0.40803;1.43680;0.68770;,
 -0.42266;0.16282;1.51006;,
 0.82715;0.16264;1.53201;,
 -0.41902;-1.53583;1.28868;,
 0.83079;-1.53601;1.31062;,
 -0.40803;1.43680;0.68770;,
 -0.35053;0.09978;-2.59846;,
 -0.36058;-1.28039;-2.03709;,
 -0.42266;0.16282;1.51006;,
 -0.28845;-1.34343;-6.14559;,
 -0.22638;-2.78663;-9.69272;,
 -0.23644;-4.16679;-9.13136;,
 -0.29851;-2.72360;-5.58422;,
 -0.37064;-2.66056;-1.47572;,
 -0.41902;-1.53583;1.28868;,
 -0.24649;-5.54697;-8.56999;,
 -0.30857;-4.10377;-5.02286;,
 0.84177;1.43661;0.70963;,
 0.89928;0.09960;-2.57651;,
 -0.35053;0.09978;-2.59846;,
 -0.28845;-1.34343;-6.14559;,
 0.96135;-1.34360;-6.12364;,
 1.02343;-2.78681;-9.67078;,
 -0.22638;-2.78663;-9.69272;,
 -0.37064;-2.66056;-1.47572;,
 0.87917;-2.66075;-1.45377;,
 0.83079;-1.53601;1.31062;,
 -0.24649;-5.54697;-8.56999;,
 1.00331;-5.54715;-8.54806;,
 0.94124;-4.10395;-5.00091;,
 -0.30857;-4.10377;-5.02286;,
 0.90005;0.20479;-2.61930;,
 -0.34976;0.20497;-2.64124;,
 0.96212;-1.23841;-6.16643;,
 -0.28769;-1.23823;-6.18837;,
 -0.43297;-1.34340;-6.14812;,
 -0.49504;0.09980;-2.60099;,
 -0.44303;-2.72358;-5.58676;,
 -0.50510;-1.28037;-2.03963;,
 -0.45308;-4.10374;-5.02539;,
 -0.51515;-2.66054;-1.47825;,
 0.94117;-4.11351;-4.99702;,
 -0.30864;-4.11333;-5.01896;,
 0.87910;-2.67030;-1.44988;,
 -0.37071;-2.67013;-1.47183;,
 0.94027;-4.23783;-4.94646;,
 -0.30954;-4.23765;-4.96840;,
 0.87819;-2.79462;-1.39932;,
 -0.37162;-2.79445;-1.42127;,
 0.71273;-5.22019;-11.15604;,
 0.72013;-6.48062;-10.41924;,
 -1.12984;-6.48722;-10.41196;,
 -1.13724;-5.22679;-11.14876;,
 0.72585;-6.47273;-8.95928;,
 -1.12412;-6.47934;-8.95199;,
 0.72417;-5.20442;-8.23610;,
 -1.12581;-5.21102;-8.22882;,
 0.71676;-3.94399;-8.97290;,
 -1.13321;-3.95060;-8.96562;,
 0.71105;-3.95187;-10.43286;,
 -1.13893;-3.95848;-10.42558;,
 0.71273;-5.22019;-11.15604;,
 -1.13724;-5.22679;-11.14876;,
 0.71845;-5.21230;-9.69606;,
 0.71845;-5.21230;-9.69606;,
 0.71845;-5.21230;-9.69606;,
 0.71845;-5.21230;-9.69606;,
 0.71845;-5.21230;-9.69606;,
 0.71845;-5.21230;-9.69606;,
 -1.13152;-5.21891;-9.68878;,
 -1.13152;-5.21891;-9.68878;,
 -1.13152;-5.21891;-9.68878;,
 -1.13152;-5.21891;-9.68878;,
 -1.13152;-5.21891;-9.68878;,
 -1.13152;-5.21891;-9.68878;;
 
 62;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;6,7,8,9;,
 4;9,8,10,11;,
 4;12,13,14,15;,
 4;15,14,16,17;,
 4;18,19,20,21;,
 4;21,20,22,23;,
 4;18,7,24,25;,
 4;26,27,10,23;,
 4;28,29,30,31;,
 4;31,30,32,33;,
 4;34,35,36,37;,
 4;37,36,38,39;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;43,42,48,49;,
 4;47,46,50,51;,
 4;40,52,53,54;,
 4;55,56,57,58;,
 4;59,60,61,49;,
 4;62,63,64,65;,
 4;66,67,54,53;,
 4;68,66,53,56;,
 4;69,68,56,55;,
 4;67,69,55,54;,
 4;67,66,68,69;,
 4;70,71,41,44;,
 4;72,70,44,47;,
 4;71,73,42,41;,
 4;71,70,72,73;,
 4;74,72,47,51;,
 4;75,74,51,48;,
 4;73,75,48,42;,
 4;73,72,74,75;,
 4;76,77,65,64;,
 4;78,76,64,60;,
 4;79,78,60,59;,
 4;77,79,59,65;,
 4;80,81,77,76;,
 4;82,80,76,78;,
 4;83,82,78,79;,
 4;81,83,79,77;,
 4;81,80,82,83;,
 4;84,85,86,87;,
 4;85,88,89,86;,
 4;88,90,91,89;,
 4;90,92,93,91;,
 4;92,94,95,93;,
 4;94,96,97,95;,
 3;98,85,84;,
 3;99,88,85;,
 3;100,90,88;,
 3;101,92,90;,
 3;102,94,92;,
 3;103,96,94;,
 3;104,87,86;,
 3;105,86,89;,
 3;106,89,91;,
 3;107,91,93;,
 3;108,93,95;,
 3;109,95,97;;
 
 MeshMaterialList {
  4;
  62;
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
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  1,
  1,
  1,
  2,
  1,
  1,
  1,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.138400;0.138400;0.138400;1.000000;;
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
   0.627200;0.661600;0.533600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.542400;0.222400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  90;
  0.012273;-0.014702;-0.999817;,
  0.009928;-0.293432;-0.955928;,
  0.006793;-0.548799;-0.835927;,
  0.977574;0.199327;-0.067959;,
  0.999898;-0.004598;0.013497;,
  0.973509;-0.208299;0.094296;,
  -0.003784;0.727768;0.685813;,
  -0.009615;0.323349;0.946231;,
  -0.015160;-0.625086;0.780408;,
  -0.999825;0.009419;-0.016149;,
  -0.999838;0.008719;-0.015754;,
  -0.999850;0.008018;-0.015358;,
  0.013225;0.926167;-0.376881;,
  -0.013110;-0.929813;0.367799;,
  0.016206;-0.376817;-0.926146;,
  0.016204;-0.376814;-0.926147;,
  0.016202;-0.376811;-0.926148;,
  0.006745;0.926288;-0.376756;,
  0.006752;0.926288;-0.376755;,
  -0.006747;-0.926289;0.376754;,
  -0.006754;-0.926288;0.376756;,
  -0.014669;0.542395;0.839995;,
  -0.017095;0.220021;0.975345;,
  -0.017431;-0.129251;0.991459;,
  -0.999846;0.000140;-0.017554;,
  -0.999846;0.000141;-0.017554;,
  -0.999846;0.000145;-0.017557;,
  -0.999846;0.000145;-0.017556;,
  -0.999846;0.000147;-0.017557;,
  -0.999846;0.000146;-0.017556;,
  0.999846;-0.000172;0.017566;,
  -0.016208;0.376820;0.926145;,
  0.016209;-0.376800;-0.926153;,
  0.006757;0.926288;-0.376756;,
  -0.016193;0.376818;0.926146;,
  0.016179;-0.376815;-0.926147;,
  -0.006757;-0.926288;0.376755;,
  0.016179;-0.376817;-0.926147;,
  0.016204;-0.377066;-0.926045;,
  0.999846;-0.000164;0.017564;,
  -0.016212;0.376852;0.926132;,
  0.016204;-0.376781;-0.926160;,
  0.999846;-0.000138;0.017554;,
  -0.016214;0.376780;0.926161;,
  -0.999846;0.000144;-0.017556;,
  -0.999846;0.000147;-0.017556;,
  -0.999846;0.000146;-0.017558;,
  -0.999846;0.000144;-0.017556;,
  0.006755;0.926288;-0.376756;,
  0.006751;0.926288;-0.376756;,
  -0.006756;-0.926288;0.376756;,
  -0.006752;-0.926288;0.376755;,
  -0.016201;0.376818;0.926146;,
  0.016194;-0.376807;-0.926150;,
  -0.999846;0.000135;-0.017552;,
  0.006747;0.926288;-0.376755;,
  0.016179;-0.376814;-0.926148;,
  -0.016193;0.376815;0.926147;,
  -0.999846;0.000147;-0.017556;,
  -0.999846;0.000144;-0.017555;,
  0.016192;-0.377084;-0.926038;,
  -0.016193;0.376821;0.926144;,
  -0.016202;0.376872;0.926124;,
  -0.999846;0.000141;-0.017553;,
  0.016204;-0.377351;-0.925929;,
  0.999846;-0.000191;0.017574;,
  -0.016210;0.376923;0.926103;,
  -0.999846;0.000145;-0.017555;,
  -0.999846;0.000141;-0.017555;,
  -0.006745;-0.926288;0.376756;,
  0.999986;0.003571;-0.003936;,
  -0.001599;-0.504671;-0.863310;,
  0.003592;-0.999979;0.005387;,
  0.005189;-0.495313;0.868699;,
  0.001595;0.504670;0.863311;,
  -0.003594;0.999979;-0.005383;,
  -0.999986;-0.003573;0.003935;,
  -0.005191;0.495315;-0.868698;,
  0.999986;0.003569;-0.003937;,
  0.999986;0.003569;-0.003937;,
  0.999986;0.003570;-0.003937;,
  0.999986;0.003573;-0.003937;,
  0.999986;0.003575;-0.003934;,
  0.999986;0.003571;-0.003934;,
  -0.999986;-0.003573;0.003937;,
  -0.999986;-0.003569;0.003937;,
  -0.999986;-0.003572;0.003934;,
  -0.999986;-0.003573;0.003930;,
  -0.999986;-0.003575;0.003934;,
  -0.999986;-0.003577;0.003937;;
  62;
  4;0,0,1,1;,
  4;1,1,2,2;,
  4;3,3,4,4;,
  4;4,4,5,5;,
  4;6,6,7,7;,
  4;7,7,8,8;,
  4;9,9,10,10;,
  4;10,10,11,11;,
  4;12,12,12,12;,
  4;13,13,8,8;,
  4;14,14,15,15;,
  4;15,15,16,16;,
  4;21,21,22,22;,
  4;22,22,23,23;,
  4;44,24,26,26;,
  4;25,45,27,27;,
  4;26,26,28,46;,
  4;27,27,47,29;,
  4;18,18,18,48;,
  4;49,17,17,17;,
  4;50,20,20,20;,
  4;19,19,19,51;,
  4;31,31,52,31;,
  4;30,30,30,30;,
  4;32,32,32,53;,
  4;54,54,25,24;,
  4;55,55,55,55;,
  4;33,33,48,49;,
  4;35,56,53,35;,
  4;57,34,34,52;,
  4;58,58,59,59;,
  4;37,35,35,60;,
  4;36,36,51,50;,
  4;34,61,62,34;,
  4;59,59,63,63;,
  4;38,38,60,64;,
  4;39,39,65,65;,
  4;40,40,66,62;,
  4;67,67,28,29;,
  4;41,41,38,38;,
  4;42,42,39,39;,
  4;43,43,40,40;,
  4;68,68,67,67;,
  4;69,69,69,69;,
  4;71,71,71,71;,
  4;72,72,72,72;,
  4;73,73,73,73;,
  4;74,74,74,74;,
  4;75,75,75,75;,
  4;77,77,77,77;,
  3;70,78,79;,
  3;70,80,78;,
  3;70,81,80;,
  3;70,82,81;,
  3;70,83,82;,
  3;70,79,83;,
  3;76,84,85;,
  3;76,85,86;,
  3;76,86,87;,
  3;76,87,88;,
  3;76,88,89;,
  3;76,89,84;;
 }
 MeshTextureCoords {
  110;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;0.500000;,
  0.000000;0.500000;,
  0.666670;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.666670;0.500000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.000000;0.333330;,
  0.000000;0.666670;,
  1.000000;0.666670;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.666670;,
  1.000000;0.666670;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.000000;0.333330;,
  1.000000;0.333330;,
  0.000000;0.333330;,
  1.000000;0.666670;,
  0.000000;0.666670;,
  0.666670;0.000000;,
  0.333330;0.000000;,
  0.666670;0.500000;,
  0.333330;0.500000;,
  0.666670;1.000000;,
  0.333330;1.000000;,
  1.000000;0.333330;,
  0.000000;0.333330;,
  1.000000;0.666670;,
  0.000000;0.666670;,
  1.000000;0.333330;,
  0.000000;0.333330;,
  1.000000;0.666670;,
  0.000000;0.666670;,
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.833330;0.000000;,
  0.833330;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083330;0.000000;,
  0.250000;0.000000;,
  0.416670;0.000000;,
  0.583330;0.000000;,
  0.750000;0.000000;,
  0.916670;0.000000;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;;
 }
}
