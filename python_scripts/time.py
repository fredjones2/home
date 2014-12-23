import time
import base64
timestamp = int(time.time())
pad= raw_input ("enter pad:")
userid= raw_input ("enter userid:")
spacer= raw_input ("enter spacer:")
print (userid)
print (spacer)
print (timestamp)
print (pad)
out = (userid+spacer+str(timestamp))
print base64.b64encode(bytes(out)+pad)
