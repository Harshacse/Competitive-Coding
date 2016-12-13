import math
def checkprime(t):
	for i in range(2,t):
		if t%i==0:
			return False
	return True

def main():
	t = 2
	l = []
	while math.sqrt(10000000)>t:
		if checkprime(t):
			l.append(t)
		t+=1
	print l

main()
