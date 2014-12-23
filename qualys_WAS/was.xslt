<?xml version="1.0" encoding="utf-8"?>

<xsl:stylesheet version="1.0"
               xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="xml" version="1.0" encoding="UTF-8" indent="yes"/>
<xsl:template match="/">
<ArcherRecords xmlns="http://www.archer-tech.com/">
<!-- for each host create a new record per vulnerability -->
<xsl:for-each select="WAS_SCAN_REPORT/APPENDIX/WEBAPP">
<xsl:variable name="ID" select="."/>

<ArcherRecord>
<ID>
<xsl:value-of select="ID"/>
</ID>

</xsl:for-each>
</ArcherRecord>
</ArcherRecord>
</xsl:template>