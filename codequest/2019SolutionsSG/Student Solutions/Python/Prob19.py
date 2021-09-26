import sys, math, string

def charr(b):
	while len(b) < 8:
		b = "0" + b
	return b
def toDec(num):
	dec = 0
	if num[7] == "1":
		dec += 1
	if num[6] == "1":
		dec += 2
	if num[5] == "1":
		dec += 4
	if num[4] == "1":
		dec += 8
	if num[3] == "1":
		dec += 16
	if num[2] == "1":
		dec += 32
	if num[1] == "1":
		dec += 64
	if num[0] == "1":
		dec += 128
	return str(dec)
'''
2
2
192.168.0.0
192.168.255.255
4
32.73.94.16
32.73.89.172
32.73.95.210
32.73.92.82
'''


cases = int(sys.stdin.readline().rstrip())
for caseNum in range(cases):
	ccnum = int(sys.stdin.readline().rstrip())
	address = []
	for las in range(ccnum):
		address.append("")
	for i in range(ccnum):
		a1, a2, a3, a4 = map(str, sys.stdin.readline().rstrip().split("."))
		
		address[i] = charr(str(bin(int(a1)))[2:]) + charr(str(bin(int(a2)))[2:]) + charr(str(bin(int(a3)))[2:]) + charr(str(bin(int(a4)))[2:])
	match = 32
	for ii in range(ccnum-1):
		current = 0
		for j in range(32):
			if address[ii][j] == address[ii+1][j]:
				current = j+1
			else:
				break
		if current < match:
			match = current
	smallest = [0]*32
	for k in range(match):
		smallest[k] = address[0][k]
	sss = ""
	for st in smallest:
		sss += str(st)
	smallest = sss

	print(toDec(smallest[:8]) + "." + toDec(smallest[8:16]) + "." +toDec(smallest[16:24]) + "." +toDec(smallest[24:]) + "/" + str(match) )

